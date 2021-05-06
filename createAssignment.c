//2020112013 aditya

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void CopyFileFunction();

int main()
{
    char yn[2];
    // Creating a directory
    printf("\n");
    if (mkdir("/home/aditya/Documents/Function/DSA/geeksforgeeks3", 0777) == -1)
    {
        printf(">>> Error --> Folder Already Exists!!\n");
        printf(">>> Do you want to copy file to the existing folder? (y/n)\n");
        printf(">>> ");
        scanf("%s",yn);
        if (strcmp(yn, "y") == 0)
        {
            CopyFileFunction();
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
        CopyFileFunction();
    }

    return 0;
}

void CopyFileFunction()
{
    if (rename("/home/aditya/Documents/Function/dist/food.pdf", "/home/aditya/Documents/Function/DSA/geeksforgeeks3/food.pdf") == 0)
    {
        printf(">>> Files Copied from dist folder...\n");
    }
    else
    {
        perror(">>> Error");
    }
    printf(">>> Function Exited...\n\n");
}
