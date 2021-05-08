
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
    char* pointer,pointer1;
    pointer = getcwd(pointer, 500);
    pointer = strcat(pointer, "/");
    pointer = strcat(pointer, assignment);
    strcpy(pointer1,pointer);
    pointer = strcat(pointer, "/");
    pointer = strcat(pointer, "dist");
    rmdir(pointer);           //removing the dir created
    CopyFileFunction(pointer1); //after deleting dir the call the copyfile function function to install the new contents
}

void submit(void)// This function will zip the files in the current working directory and copys that zip file to the home directory
{
    char buff1[1000] ;
    chdir("/home/welcome/DSA_MINI_PROJECT/CPRO") ;
    getcwd(buff1,100) ;
    char buff2[1000]="\0" ;
    strcat(buff2,"zip -r submit.zip ") ;
    strcat(buff2,buff1) ;
    system(buff2) ;
    char buff3[1000]="\0" ;
    strcat(buff3,buff1) ;
    strcat(buff3,"/submit.zip ") ;
    char buff4[1000]="/home/welcome/DSA_MINI_PROJECT" ;
    char buff5[1000]="cp -r " ;
    strcat(buff5,buff3) ;
    strcat(buff5,buff4) ;
    system(buff5) ;
    printf("ZIP FILE IS CREATED AND IT IS PRESENT IN HOME DIRECTORY\n") ;
    strcat(buff1,"/submit.zip") ;
    char string[100]="rm " ;
    strcat(string,buff1) ;
    system(string) ;
}
