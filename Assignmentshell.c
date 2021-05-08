
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void CopyFileFunction(char constdir[10000]);
char* CurrentDir(char cwd[10000]);
int md5comp();
int DiffernceFile();

void TestAssignment(char assignment[100])
{
	system("python3 /home/welcome/submitter.py") ;
	system("./a.out > /home/welcome/debug.txt") ;
}


////////////////////////////////CREATE ASSIGNMENT///////////////////////////////////////////
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
    char src[10000] = "/home/welcome/DSA_MINI_PROJECT/dist/ ";

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
    printf(">>> ZIP FILE IS CREATED AND IT IS PRESENT IN HOME DIRECTORY\n") ;
    strcat(buff1,"/submit.zip") ;
    char string[100]="rm " ;
    strcat(string,buff1) ;
    system(string) ;
}

////////////////////////////////SUBMIT ASSIGNMENT///////////////////////////////////////////

////////////////////////////////COMPARE ASSIGNMENT///////////////////////////////////////////
int CompareAssignment(char currentdist[100])
{
    char currentdist[100] = "assignment1";
    char dest[10000];
    CurrentDir(dest);
    strcat(dest, "/");
    strcat(dest, currentdist);
    strcat(dest, "/");

    char file[10000] = "assignment.zip";
    char unzip[10000] = "unzip ";

    strcat(unzip, file);
    strcat(unzip, " -d ");
    strcat(unzip, dest);

    int zippy = system(unzip);
    //printf("%s\n",unzip);
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
    strcat(file1, "dist/*  > "); //////////////// DO CHECKOUT FOR DIR. NAME WITH PRANEET///////////////////

    char file2[1000];
    CurrentDir(file2);
    strcat(file2,"/");
    strcat(file2, currentdist);
    strcat(file2, "test/*  > "); //////////////// DO CHECKOUT FOR DIR. NAME WITH PRANEET///////////////////

    char command1[1000] = "md5sum ";
    char command2[1000] = "md5sum ";

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
    //printf("%s\n", command1);

    strcat(command2, file2);
    strcat(command2, checklist2);
    int sys2 = system(file2);
    //printf("%s\n", command2);

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
    //printf("%s\n",diff);
    printf(">>> A 'DiffFiles.txt' has been created inside current Assignment\n\n");
    return 0;
    
}
////////////////////////////////COMPARE ASSIGNMENT///////////////////////////////////////////
