#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file
typedef struct {
    char name[100];
    char content[1000];
} File;

// Function to create a file
void createFile(File* files, int* fileCount, const char* name, const char* content) {
    if (*fileCount < 100) {
        File newFile;
        strcpy(newFile.name, name);
        strcpy(newFile.content, content);
        files[(*fileCount)++] = newFile;
        printf("File created: %s\n", name);
    } else {
        printf("File limit reached. Cannot create more files.\n");
    }
}

// Function to list all files in the directory
void listFiles(const File* files, int fileCount) {
    printf("Files in the directory:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%s\n", files[i].name);
    }
}

// Function to delete a file by name
void deleteFile(File* files, int* fileCount, const char* name) {
    int indexToDelete = -1;
    for (int i = 0; i < *fileCount; i++) {
        if (strcmp(files[i].name, name) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        for (int i = indexToDelete; i < *fileCount - 1; i++) {
            files[i] = files[i + 1];
        }
        (*fileCount)--;
        printf("File deleted: %s\n", name);
    } else {
        printf("File not found: %s\n", name);
    }
}

// Function to access and read the content of a file
void accessFile(const File* files, int fileCount, const char* fileName) {
    int found = 0;
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].name, fileName) == 0) {
            printf("File content of %s:\n%s\n", fileName, files[i].content);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("File not found: %s\n", fileName);
    }
}

int main() {
    File files[100];
    int fileCount = 0;

    while (1) {
        printf("1. Create file\n2. List files\n3. Delete file\n4. Access and read file\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[100], content[1000];
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            getchar(); // Consume the newline character left in the input buffer
            fgets(content, sizeof(content), stdin);
            createFile(files, &fileCount, name, content);
        } else if (choice == 2) {
            listFiles(files, fileCount);
        } else if (choice == 3) {
            char name[100];
            printf("Enter the name of the file to delete: ");
            scanf("%s", name);
            deleteFile(files, &fileCount, name);
        } else if (choice == 4) {
            char name[100];
            printf("Enter the name of the file you want to access: ");
            scanf("%s", name);
            accessFile(files, fileCount, name);
        } else if (choice == 5) {
            break;
        }
    }

    return 0;
}

