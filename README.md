# DSA_MINI_PROJECT



description of submit assignment function:
1. In this function first we will zip all the files in current directory.
2. To zip the file we use system function which is present in stdlib.h header file.
3. Then we will copy the zip file to the local directory using system function.

description of test assignment function:
1. In this function we will run submitter.py on our files to check if there are any compilation errors or incorrect folder structure.
2. In this function we will compile the python file using system function and run that file.
3. After running submitter.py the output is redirected to another file debug.txt Now we can send this file for debugging.

description of Create Assignment function:
1. In this function, the user will give the name of the assignment which has to be created.
2. It's assumed that a dist folder has been provided for Cut&Paste to the assignment.
3. Here, the whole dist folder is been moved to the assignment folder instead of its contents(only).

description of Compare Assignment function:
1. This function will unzip the present zip file with a name called "test" folder.
2. md5sum function will be applied to both of them and 2 checklist.txt files will be created containing all the hashvalues of the folders.
3. Diff function will be called on these two files and the differnce will be routed to a "DiffFiles.txt" file in aassignment folder.
4. The test folder will be deleted.
