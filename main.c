#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
 
int main(void)
{
    char string[100];
    char path[100];
    //char command[100];
    char argument[100];
    int i = 0;
    while (1)
    {
        printf("TEAM53:");
        printf("%s>>>", getcwd(path, 100));
 
        fgets(string,100, stdin);
        char * command = strtok(string, " ");
        char * argument = strtok(NULL, " ");
        char* defaultargument[100]="\0" ;

        if(strcmp(command,"use\n")==0&&argument!=NULL)
            strcpy(defaultargument,argument) ;

        if(argument==NULL)
            command[strlen(command)-1]="\0" ;

 
        if (strcmp(command, "exit") == 0)
            break;
 
        if (strcmp(command, "switch") == 0)
            Switch(argument);
 
        else if (strcmp(command, "create") == 0)
            CreateAssignment(argument\n);
 
        else if (strcmp(command, "update") == 0)
            UpdateAssignment(argument);
 
        else if (strcmp(command, "test") == 0)
            TestAssignment(argument);
 
        else if (strcmp(command, "submit") == 0)
            SubmitAssignment(argument);
 
        else if (strcmp(command, "compare") == 0)
            CompareAssignment(argument);
 
        else if (strcmp(command, "use") == 0)
        {
            UseAssignment(defaultargument);
        }
 
        else
            printf("ERROR!\n");
    }
}
