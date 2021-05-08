
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "Assignmentshell.h"

void CopyFileFunction(char constdir[10000]);
char* CurrentDir(char cwd[10000]);
int md5comp();
int DiffernceFile();

void TestAssignment(char assignment[100])
{
    char buff1[200]="\0" ;
    getcwd(buff1,200) ;
    strcat(buff1,"/") ;
    strcat(buff1,assignment) ;
    strcat(buff1,"/dist/submitter.py > debug.txt") ;
    char buff2[200]="python3 " ;
    strcat(buff2,buff1) ;
    system(buff2) ;
}
void Switch(char *path, char *subject)
{
    char path1[100]="\0";
    strcpy(path1, path);
    strcat(path1, "/");
    strcat(path1, subject);
    int x=chdir(path1);
    if(x!=0)
    {
        char buff2[100]="\0" ;
        strcat(buff2,path) ;
        strcat(buff2,"/") ;
        strcat(buff2,subject) ;
        mkdir(buff2,0777) ;
        chdir(buff2) ;
    }   
}


////////////////////////////////CREATE ASSIGNMENT///////////////////////////////////////////
int CreateAssignment(char assignment[10000])
{
    char yn[2];
    char constdir[10000]; 

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
    char src[10000] = "/home/welcome/Downloads/dist/ ";

    strcat(src, constdir);
    strcat(movFunction, src);

    int r = system(movFunction);
    return;
}

char* CurrentDir(char cwd[10000])
{

    if (getcwd(cwd, 10000) == NULL)
        perror(">>> getcwd() error");
    else

    return cwd;
}
////////////////////////////////CREATE ASSIGNMENT///////////////////////////////////////////

////////////////////////////////UPDATE ASSIGNMENT///////////////////////////////////////////
void UpdateAssignment(char assignment[])
{
    char pointer[300], pointer1[300];
    memset(pointer, '\0', sizeof(pointer));   //initializing the all char in the pointer to null
    memset(pointer1, '\0', sizeof(pointer1)); //intializing the all char in the pointer1 to null
    char pointer2[400] = "rm -r ";
    getcwd(pointer, 300); //let the path of current dir be path(a string indicating path)
    strcat(pointer, "/");
    strcat(pointer, assignment);         //at this step the path is pointing to the assignment in the subject
    strcpy(pointer1, pointer);           //copying the path to assignment to give it as argument
    strcat(pointer, "/dist");   //pointer shows path for dist folder
    strcat(pointer2, pointer);  // making pointer 2 as mv -v path to the dist folder in assignment
    system(pointer2);           //this step is to remove the dist folder in the assignment
    CopyFileFunction(pointer1); // after deleting dist the call the copyfile function function to install the new contents of the dist
     printf(">>>the dist in the %s is updated\n",assignment);
}

////////////////////////////////UPDATE ASSIGNMENT///////////////////////////////////////////


////////////////////////////////SUBMIT ASSIGNMENT///////////////////////////////////////////
void SubmitAssignment(char arg[100])// This function will zip the files in the current working directory and copys that zip file to the home directory
{
    char buff1[1000]="\0" ;
    strcat(buff1,arg) ;
    char buff2[1000]="\0" ;
    strcat(buff2,"zip -r assignment.zip ") ;
    strcat(buff2,buff1) ;
    system(buff2) ;
    char buff3[100]="\0" ;
    getcwd(buff3,100) ;
    strcat(buff3,"/assignment.zip") ;
    char buff4[100]="\0" ;
    strcat(buff4,"mv -v ") ;
    strcat(buff4,buff3) ;
    char buff5[100]="\0" ;
    getcwd(buff5,100) ;
    strcat(buff5,"/") ;
    strcat(buff5,arg) ;
    strcat(buff4," ") ;
    strcat(buff4,buff5) ;
    system(buff4) ; 
    printf("ZIP FILE IS CREATED\n") ;
}

////////////////////////////////SUBMIT ASSIGNMENT///////////////////////////////////////////
////////////////////////////////COMPARE ASSIGNMENT///////////////////////////////////////////
int CompareAssignment(char currentdist[100])
{
    char dest[10000];
    CurrentDir(dest);
    strcat(dest, "/");
    strcat(dest, currentdist);
    strcat(dest, "/");
    strcat(dest,"test/ ") ;
    char file[10000]="\0" ;

    CurrentDir(file);
    strcat(file, "/");
    strcat(file,currentdist) ;
    strcat(file, "/assignment.zip");
    char unzip[10000] = "unzip ";

    strcat(unzip, file);
    strcat(unzip, " -d ");
    strcat(unzip, dest);

    int zippy = system(unzip);
    printf("%s\n",unzip);
    printf(">>> File Extracted...\n");
    md5comp(currentdist);

    return 0;
}

int md5comp(char currentdist[100])
{
    strcat(currentdist, "/");

    char file1[1000];
    CurrentDir(file1);
    strcat(file1,"/");
    strcat(file1, currentdist);
    strcat(file1, "dist  > ");

    char file2[1000];
    CurrentDir(file2);
    strcat(file2,"/");
    strcat(file2, currentdist);
    strcat(file2, "test/");
    strcat(file2, currentdist);
    strcat(file2, "dist > ");

    char command1[1000] = "md5deep -r ";
    char command2[1000] = "md5deep -r ";

    char checklist1[1000];
    CurrentDir(checklist1);
    strcat(checklist1, "/");
    strcat(checklist1, currentdist);
    strcat(checklist1, "checklist1.txt");

    char checklist2[1000];
    CurrentDir(checklist2);
    strcat(checklist2, "/");
    strcat(checklist2, currentdist);
    strcat(checklist2, "checklist2.txt");
    strcat(command1, file1);
    strcat(command1, checklist1);
    int sys1 = system(file1);
    printf("%s\n", command1);

    strcat(command2, file2);
    strcat(command2, checklist2);
    int sys2 = system(file2);
    printf("%s\n", command2);

    DiffernceFile(checklist1, checklist2);

    
    return 0;
}

int DiffernceFile(char checklist1[1000], char checklist2[1000])
{
    char difflist[1000];
    char arrow[10000] = " > ";
    CurrentDir(difflist);
    strcat(arrow, difflist);
    strcat(arrow, "/DiffFiles.txt ");
    char diff[10000] = "diff ";
    
    strcat(diff, checklist1);
    strcat(diff, " ");
    strcat(diff, checklist2);
    strcat(diff, arrow);

    int sys3 = system(diff);
    printf("%s\n",diff);
    printf(">>> A 'DiffFiles.txt' has been created inside current Assignment\n\n");
    return 0;
    
}
////////////////////////////////COMPARE ASSIGNMENT///////////////////////////////////////////
