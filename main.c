////////////// headerfiles///////////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "Assignmentshell.c"
////////////// headerfiles///////////////


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
        /////////////////////////////if else block to check whether whether the assignment name is given or not/////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if ((!argument) && t) //this is find wheather there is an argument or not(if argument=NULL then if(!argument)is true)
        {                     // based on the command we call the relevent function
            //t says wheather the we ues if t=0 then the use is not used previously atleast once
            if (strcmp(string, "create\n") == 0)// when argument =null and t=1 and the command is create  the it calls the create function
                CreateAssignment(assignment);//the argument is the assignment (the argument in the previous use assignment)

            else if (strcmp(string, "update\n") == 0)// when argument =null and t=1 and the command is upadet the it calls the UpdateAssignment function
                UpdateAssignment(assignment);//the argument is the assignment (the argument in the previous use assignment)

            else if (strcmp(string, "test\n") == 0)// when argument =null and t=1 and the command is test  the it calls the TestAssignment function
               TestAssignment(assignment);//the argument is the assignment (the argument in the previous use assignment)

            else if (strcmp(string, "submit\n") == 0)// when argument =null and t=1 and the command is submit  the it calls the SubmitAssignment function
               SubmitAssignment(assignment);//the argument is the assignment (the argument in the previous use assignment)

            else if (strcmp(string, "compare\n") == 0)// when argument =null and t=1 and the command is compare  the it calls the CompareAssignment function
               CompareAssignment(assignment);//the argument is the assignment (the argument in the previous use assignment)
        }
        else
        {
            if (strcmp(command, "switch") == 0)//when there is an argument is not null and the command is switch  
              Switch(pathtofolder, argument);//the argumnets are pathtofolder and the argument 

            else if (strcmp(command, "create") == 0)//when there is an argument is not null and the command is create
                CreateAssignment(argument);

            else if (strcmp(command, "update") == 0)//when there is an argument is not null and the command is update
               UpdateAssignment(argument);

            else if (strcmp(command, "test") == 0)//when there is an argument is not null and the command is test
                 TestAssignment(argument);

            else if (strcmp(command, "submit") == 0)//when there is an argument is not null and the command is submit
             SubmitAssignment(argument);

            else if (strcmp(command, "compare") == 0)//when there is an argument is not null and the command is compare
                 CompareAssignment(argument);

            else if (strcmp(command, "use") == 0)//when there is an argument is not null and the command is use
            {
                memset(assignment, '\0', sizeof(assignment));// first removing the previous assignment name (making the string null)
                strcpy(assignment, argument);//then storing the name of assignment given with use command into the assignment string
                t = 1;//makes the value of t as 1 so that we can know that use command is given atleast once
            }

            else
                printf("ERROR!");// gives error when none of the above commands is given
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////if else block for wheather the assignment name is given or not//////////////////////////////////////////////////////////////
    return 0;
}
