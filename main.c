#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "Assignmentshell.h"



int main()
{
    char string[100];
    char path[100];
    char *argument;
    char *command;
    int i = 0;
    char assignment[100];
    char pathtofolder[200];
    memset(pathtofolder, '\0', sizeof(pathtofolder));//making the path of the folder to the null
    getcwd(pathtofolder, 200);//to store the path of the directory in which the code is present
    int t=0 ;
    while (1)
    {
        printf("\nteam53");
        printf("%s >", getcwd(path, 100));
        memset(string, '\0', sizeof(string));
        fgets(string, 200, stdin);
        command = strtok(string, " "); //spliting the input into command
        argument = strtok(NULL, " ");  //splitting the input into argument
        if(argument!=NULL)
        argument[strlen(argument)-1]='\0';
        if (strcmp(command, "exit\n") == 0)
            break;
        if ((!argument) && t) //this is find wheather there is an argument or not(if argument=NULL then if(!argument)is true)
        {                     // based on the command we call the relevent function
            //t says wheather the we ues if t=0 then the use is not used previously atleast once
            if (strcmp(string, "create\n") == 0)
                CreateAssignment(assignment);

            else if (strcmp(string, "update\n") == 0)
                UpdateAssignment(assignment);

            else if (strcmp(string, "test\n") == 0)
               TestAssignment(assignment);

            else if (strcmp(string, "submit\n") == 0)
               SubmitAssignment(assignment);

            else if (strcmp(string, "compare\n") == 0)
               CompareAssignment(assignment);
        }
        else
        {
            if (strcmp(command, "switch") == 0)
              Switch(pathtofolder, argument);

            else if (strcmp(command, "create") == 0)
                CreateAssignment(argument);

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
                memset(assignment, '\0', sizeof(assignment));
                strcpy(assignment, argument);
                t = 1;
            }

            else
                printf("ERROR!");
        }
    }
    return 0;
}
