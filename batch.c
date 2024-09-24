#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// default directory
char jobsDirectory[256] = "./jobs";

void listJobs() {
    DIR *d;
    struct dirent *dir;
    d = opendir(jobsDirectory);
    if (d == NULL) {
        printf("Could not open current directory.");
    }
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char *file = dir->d_name;
            if (strstr(file, ".C") != NULL) {
                printf("%s\n", file);
            }
        }
        closedir(d);
    }
}

 // Compile one file
void compileAndRunFile(char *jobName) {
    char compileCommand[512];
    char runCommand[512];
    snprintf(compileCommand, sizeof(compileCommand), "gcc %s/%s -o %s/job.out", jobsDirectory, jobName, jobsDirectory);

    printf("Compiling %s...\n", jobName);
    if (system(compileCommand) == 0) {
        // If compilation succeeds, execute the program
        snprintf(runCommand, sizeof(runCommand), "%s/job.out", jobsDirectory);
        printf("Running %s...\n", jobName);
        system(runCommand);
    } else {
        printf("Compilation failed for program: %s\n", jobName);
    }
}

// compile all the files
void compileAndRunAllFiles() {
    struct dirent *entry;
    DIR *directory = opendir(jobsDirectory);

    if (directory == NULL) {
        printf("Error: Unable to open the  directory.\n");
        return;
    }

    printf("Compiling and running all files in '%s':\n", jobsDirectory);
    while ((entry = readdir(directory)) != NULL) {
        if (strstr(entry->d_name, ".C") != NULL) {
            compileAndRunFile(entry->d_name);
        }
    }

    closedir(directory);
}

// set new directory
void setNewDirectory() {
    printf("Enter the new directory path: ");
    scanf("%s", jobsDirectory);
    printf(" New directory set to: %s\n", jobsDirectory);
}

void displayMenu() {
    printf("\n======== Batch Operating System ========\n");
    printf("1. List available jobs\n");
    printf("2. Set new directory\n");
    printf("3. Compile and run a specific file\n");
    printf("4. Compile and run all file\n");
    printf("5. Shutdown\n");
    printf("6. Help\n");
    printf("=====================================\n");
}

// Simulator function
int main() {
    int userChoice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                listJobs();
                break;
            case 2:
                setNewDirectory();
                break;
            case 3: {
                char jobName[256];
                printf("Enter the job name to compile and run (e.g., dots.C, factorial.C): ");
                scanf("%s", jobName);
                compileAndRunFile(jobName);
                break;
            }
            case 4:
                compileAndRunAllFiles();
                break;
            case 5:
                printf("Shutting down............ See you Again.....\n");
                exit(0);
            case 6:
                printf("This program allows you to run the batch Operating System.\n"
                       "Click on the 1 to see the options 2 to change the directory from default and option 3 and 4 to run the program.\n"
                       "5 to leave the system");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
