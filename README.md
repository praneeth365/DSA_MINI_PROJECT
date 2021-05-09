# DSA_MINI_PROJECT
                                                                   TEAM 53
                                                            Assignment Shell Project
Instructions to be followed during the running of code:
1. The code for the project must be present in the same directory where subjects are present.
2. Note that before executing any command the first command for the programme should be switch because then only the current working directory of programme will be a subject and now we can use other commands.
3. Before entering the command create or update we need to ensure that there is a dist folder present in the Downloads because these two functions need a dist folder.
4. Note that in compare assignment command the command should be either (compare or compare <name of assignment>) i.e we should not mention the name of the zip file in the command(the name of the zip file is default taken as assignment.zip) and before entering compare command we need to ensure that there is a zip file present in the downloads named assignment.zip.
5. after entering the test command we need to enter 2020101040. Now the compilation errors are sent into a file named debug.txt
6. Note that the zip file used for compare assignment should have a folder with name of assignment and that folder should contain a dist folder.

commands must be given in the below format:
1. switch <name of assignment> or switch (if use command is entered previously)
2. create <name of assignment> or create (if use command is entered previously)
3. update <name of assignment> or update (if use command is entered previously)
4. test <name of assignment> or test (if use command is entered previously)
5. submit <name of assignment> or submit (if use command is entered previously)
6. compare <name of assignment> or compare (if use command is entered previously) Note that here we are not giving the name of zip file in the command The name of the zip file is default taken as assignment.zip
7. use <name of assignment> 


Description of submit assignment Function:
1. In this function first we will zip all the files in current directory.
2. To zip the file we use system function which is present in stdlib.h header file.
3. Then we will copy the zip file to the local directory using system function.

Description of test assignment Function:
1. In this function we will run submitter.py on our files to check if there are any compilation errors or incorrect folder structure.
2. In this function we will compile the python file using system function and run that file.
3. After running submitter.py the output is redirected to another file debug.txt Now we can send this file for debugging.

Description of Create Assignment Function:
1. In this function, the user will give the name of the assignment which has to be created.
2. It's assumed that a dist folder has been provided for Cut&Paste to the assignment.
3. Here, the whole dist folder is been moved to the assignment folder instead of its contents(only).

Description of Compare Assignment Function:
1. This function will unzip the present zip file with a name called "test" folder.
2. md5sum function will be applied to both of them and 2 checklist.txt files will be created containing all the hashvalues of the folders.
3. Diff function will be called on these two files and the differnce will be routed to a "DiffFiles.txt" file in aassignment folder.
4. The test folder will be deleted.

Description of Delete Assignment Function:
1. The input for this function will be the name of the assignment which the user wishes to remove from the memory.
2. This function will then free the memory containing data of the assignment specified by the user.

Description of Switch Assignment Function:
1. The input of this function is the name of the subject (subject folder).
2. This function will change the current working directory to specified destination subject folder.
