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

DIRECTORYNODE createDirectory(const char* name) {
    DIRECTORYNODE newDir = (DIRECTORYNODE)malloc(sizeof(struct DirectoryNode));
    strcpy(newDir->name, name);
    newDir->files = NULL;
    newDir->subDirs = NULL;
    newDir->next = NULL;
    return newDir;
}

FILENODE createFile(const char* name, int size) {
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

void listContents(DIRECTORYNODE dir) {
    printf("Contents of directory '%s':\n", dir->name);
    FILENODE file = dir->files;
    while (file) {
        printf("File: %s (Size: %d)\n", file->name, file->size);
        file = file->next;
    }
    DIRECTORYNODE subDir = dir->subDirs;
    while (subDir) {
        printf("Directory: %s\n", subDir->name);
        subDir = subDir->next;
    }
}

DIRECTORYNODE findDirectory(DIRECTORYNODE dir, const char* name) {
    if (strcmp(dir->name, name) == 0) return dir;
    DIRECTORYNODE subDir = dir->subDirs;
    while (subDir) {
        DIRECTORYNODE found = findDirectory(subDir, name);
        if (found) return found;
        subDir = subDir->next;
    }
    return NULL;
}

FILENODE findFile(DIRECTORYNODE dir, const char* name) {
    FILENODE file = dir->files;
    while (file) {
        if (strcmp(file->name, name) == 0) return file;
        file = file->next;
    }
    DIRECTORYNODE subDir = dir->subDirs;
    while (subDir) {
        FILENODE found = findFile(subDir, name);
        if (found) return found;
        subDir = subDir->next;
    }
    return NULL;
}

int calculateSize(DIRECTORYNODE dir) {
    int totalSize = 0;
    FILENODE file = dir->files;
    while (file) {
        totalSize += file->size;
        file = file->next;
    }
    DIRECTORYNODE subDir = dir->subDirs;
    while (subDir) {
        totalSize += calculateSize(subDir);
        subDir = subDir->next;
    }
    return totalSize;
}

int main() {
    DIRECTORYNODE root = createDirectory("root");
    int choice, size;
    char dirName[100], fileName[100];
    DIRECTORYNODE currentDir = root, newDir;
    FILENODE newFile;

    while (1) {
        printf("\nMenu:\n1. Create Directory\n2. Create File\n3. List Contents\n4. Find Directory\n5. Find File\n6. Calculate Size\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                newDir = createDirectory(dirName);
                addDirectoryToDirectory(currentDir, newDir);
                printf("Directory created.\n");
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", fileName);
                printf("Enter file size: ");
                scanf("%d", &size);
                newFile = createFile(fileName, size);
                addFileToDirectory(currentDir, newFile);
                printf("File added to current directory.\n");
                break;

            case 3:
                listContents(currentDir);
                break;

            case 4:
                printf("Enter directory name to find: ");
                scanf("%s", dirName);
                newDir = findDirectory(root, dirName);
                if (newDir) printf("Directory '%s' found.\n", dirName);
                else printf("Directory not found.\n");
                break;

            case 5:
                printf("Enter file name to find: ");
                scanf("%s", fileName);
                newFile = findFile(root, fileName);
                if (newFile) printf("File '%s' found.\n", fileName);
                else printf("File not found.\n");
                break;

            case 6:
                printf("Total size of current directory: %d\n", calculateSize(currentDir));
                break;

            case 7:
                deleteDirectory(root);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}

