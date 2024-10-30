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
    DIRECTORYNODE subDir1 = createDirectory("subDir1");
    addDirectoryToDirectory(root, subDir1);

    FILENODE file1 = createFile("file1.txt", 500);
    addFileToDirectory(root, file1);

    FILENODE file2 = createFile("file2.txt", 300);
    addFileToDirectory(subDir1, file2);

    listContents(root);

    FILENODE foundFile = findFile(root, "file2.txt");
    if (foundFile) printf("Found file: %s\n", foundFile->name);

    int totalSize = calculateSize(root);
    printf("Total size of root directory: %d\n", totalSize);

    deleteDirectory(root);
    return 0;
}
