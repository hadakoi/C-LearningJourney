#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileNode {
    char name[100];
    int size;
    struct FileNode* next;
} *FILENODE;

typedef struct DirectoryNode {
    char name[100];
    FILENODE files;
    struct DirectoryNode* subDirs;
    struct DirectoryNode* next;
} *DIRECTORYNODE;

DIRECTORYNODE createDirectory(char* name) {
    DIRECTORYNODE newDir = (DIRECTORYNODE)malloc(sizeof(struct DirectoryNode));
    strcpy(newDir->name, name);
    newDir->files = NULL;
    newDir->subDirs = NULL;
    newDir->next = NULL;
    return newDir;
}

FILENODE createFile(char* name, int size) {
    FILENODE newFile = (FILENODE)malloc(sizeof(struct FileNode));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;
    return newFile;
}

void addFileToDirectory(DIRECTORYNODE dir, FILENODE file) {
    file->next = dir->files;
    dir->files = file;
}

void addDirectoryToDirectory(DIRECTORYNODE parent, DIRECTORYNODE subDir) {
    subDir->next = parent->subDirs;
    parent->subDirs = subDir;
}

void deleteFiles(FILENODE file) {
    while (file) {
        FILENODE temp = file;
        file = file->next;
        free(temp);
    }
}

void deleteDirectory(DIRECTORYNODE dir) {
    while (dir) {
        deleteFiles(dir->files);
        deleteDirectory(dir->subDirs);
        DIRECTORYNODE temp = dir;
        dir = dir->next;
        free(temp);
    }
}

DIRECTORYNODE findAndRemoveSubDirectory(DIRECTORYNODE parent, char* name) {
    DIRECTORYNODE* subDirPtr = &parent->subDirs;
    while (*subDirPtr) {
        if (strcmp((*subDirPtr)->name, name) == 0) {
            DIRECTORYNODE toMove = *subDirPtr;
            *subDirPtr = toMove->next;
            toMove->next = NULL;
            return toMove;
        }
        subDirPtr = &(*subDirPtr)->next;
    }
    return NULL;
}

FILENODE findAndRemoveFile(DIRECTORYNODE parent, char* name) {
    FILENODE* filePtr = &parent->files;
    while (*filePtr) {
        if (strcmp((*filePtr)->name, name) == 0) {
            FILENODE toMove = *filePtr;
            *filePtr = toMove->next;
            toMove->next = NULL;
            return toMove;
        }
        filePtr = &(*filePtr)->next;
    }
    return NULL;
}

void moveNode(DIRECTORYNODE srcParent, DIRECTORYNODE destParent, char* name) {
    DIRECTORYNODE subDir = findAndRemoveSubDirectory(srcParent, name);
    if (subDir) {
        addDirectoryToDirectory(destParent, subDir);
        printf("Directory '%s' moved successfully.\n", name);
        return;
    }

    FILENODE file = findAndRemoveFile(srcParent, name);
    if (file) {
        addFileToDirectory(destParent, file);
        printf("File '%s' moved successfully.\n", name);
    } else {
        printf("No file or directory found with the name '%s'.\n", name);
    }
}

void listContents(DIRECTORYNODE dir) {
    printf("Directory '%s' contents:\n", dir->name);
    FILENODE f = dir->files;
    while (f) {
        printf("File: %s (Size: %d)\n", f->name, f->size);
        f = f->next;
    }
    DIRECTORYNODE d = dir->subDirs;
    while (d) {
        printf("Directory: %s\n", d->name);
        d = d->next;
    }
}

int calculateTotalSize(DIRECTORYNODE dir) {
    int totalSize = 0;
    FILENODE f = dir->files;
    while (f) {
        totalSize += f->size;
        f = f->next;
    }
    DIRECTORYNODE d = dir->subDirs;
    while (d) {
        totalSize += calculateTotalSize(d);
        d = d->next;
    }
    return totalSize;
}

DIRECTORYNODE findNodeRecursive(DIRECTORYNODE dir, char* name) {
    if (strcmp(dir->name, name) == 0) return dir;
    DIRECTORYNODE subDir = dir->subDirs;
    while (subDir) {
        DIRECTORYNODE result = findNodeRecursive(subDir, name);
        if (result) return result;
        subDir = subDir->next;
    }
    return NULL;
}

void menu(DIRECTORYNODE root) {
    int choice;
    char name[100], src[100], dest[100];
    int size;

    while (1) {
        printf("\n1. Create File\n2. Create Directory\n3. Delete Directory\n4. List Contents\n5. Move File/Directory\n6. Find Directory\n7. Calculate Directory Size\n8. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                addFileToDirectory(root, createFile(name, size));
                printf("File '%s' created.\n", name);
                break;
            case 2:
                printf("Enter directory name: ");
                scanf("%s", name);
                addDirectoryToDirectory(root, createDirectory(name));
                printf("Directory '%s' created.\n", name);
                break;
            case 3:
                printf("Enter directory name to delete: ");
                scanf("%s", name);
                DIRECTORYNODE toDelete = findAndRemoveSubDirectory(root, name);
                if (toDelete) {
                    deleteDirectory(toDelete);
                    printf("Directory '%s' deleted.\n", name);
                } else {
                    printf("Directory not found.\n");
                }
                break;
            case 4:
                listContents(root);
                break;
            case 5:
                printf("Enter name to move: ");
                scanf("%s", name);
                printf("Enter destination directory name: ");
                scanf("%s", dest);
                DIRECTORYNODE destDir = findNodeRecursive(root, dest);
                if (destDir) {
                    moveNode(root, destDir, name);
                } else {
                    printf("Destination directory not found.\n");
                }
                break;
            case 6:
                printf("Enter directory name to find: ");
                scanf("%s", name);
                DIRECTORYNODE foundDir = findNodeRecursive(root, name);
                if (foundDir) {
                    printf("Directory '%s' found.\n", foundDir->name);
                } else {
                    printf("Directory not found.\n");
                }
                break;
            case 7:
                printf("Total size: %d\n", calculateTotalSize(root));
                break;
            case 8:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    DIRECTORYNODE root = createDirectory("root");
    menu(root);
    deleteDirectory(root);
    return 0;
}

