
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void CopyFileFunction(char constdir[10000]);
char* CurrentDir(char cwd[10000]);

void TestAssignment(char assignment[100])
{
	system("python3 /home/welcome/submitter.py") ;
	system("./a.out > /home/welcome/debug.txt") ;
}

int createAssignment(char assignment[10000])
{
    char yn[2];
    char constdir[10000]; //char currentdir[10000] = "geeksforgeeks2";

    CurrentDir(constdir);
    strcat(constdir,"/");
    
    // Creating a directory
    printf("\n");
    strcat(constdir, assignment);
    if (mkdir(constdir, 0777) == -1)
    {
        printf(">>> Error --> Folder Already Exists!!\n");
        printf(">>> Do you want to copy file to the existing folder? (y/n)\n");
        printf(">>> ");
        scanf("%s", yn);
        if (strcmp(yn, "y") == 0)
        {
            CopyFileFunction(constdir);
        }
        else if (strcmp(yn, "n") == 0)
        {
            printf(">>> Function Exited...\n\n");
        }
        else
        {
            printf(">>> Invalid Input\n");
            printf(">>> Function Exited...\n\n");
        }
    }

    else
    {
        printf(">>> New Directory created\n");
        CopyFileFunction(constdir);
    }

    return 0;
}

void CopyFileFunction(char constdir[10000])
{
    char movFunction[10000] = "mv -v ";
    char src[10000] = "/home/aditya/Documents/Function/dist/ ";

    strcat(src, constdir);
    strcat(movFunction, src);

    int r = system(movFunction);
    return;
}

char* CurrentDir(char cwd[10000])
{

    if (getcwd(cwd, 10000) == NULL)
        perror("getcwd() error");
    else

    return cwd;
}
void update(char assignment[])
{
    char *pointer;
    pointer = getcwd(pointer, 500);
    pointer = strcat(pointer, "/");
    pointer = strcat(pointer, assignment);
    pointer = strcat(pointer, "/");
    pointer = strcat(pointer, "dist");
    rmdir(pointer);               //removing the dir created
    CopyFileFunction(assignment); //after deleting dir the call the create assignment function
}
