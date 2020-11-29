
How to run the program?

Option 1:
To run the program successfuly you should use Developer Command Prompt.

You can download it from here:
https://docs.microsoft.com/en-us/dotnet/framework/tools/developer-command-prompt-for-vs

After successful installation, open Developer Command Prompt. You shoud navigate to the source code directory 
with "cd" command:
cd.. - go back one folder
cd folderName - go into the folder (folderName should not contain any whitespace)
After you are at the directory you should type:
cl find.c
Then the compiler would compile the program. You will notice two new files in the program directory.
Now you are able to run the program. To do that you should input the correct arguments:

find oldword -i WordsInput.txt -r newword  -c
 0       1    2        3        4    5     6

Only program name and old word have to be at the correct order.
The program will work, even if you do not put all the arguments in the correct positions and it will
return errors if the arguments are not written properly.

Arguments explanation:
program name (0)
word you want to replace (1) 
-i to indicate that the next argument is the inputfile (2)
input file (3)
-r to indicate that the next argument is the replacement word (4)
- replacement word (5)
-c to indicate that you should ignore upper and lower case letters (not working fully) (6)


Option 2:
There is a makefile in the directory. Its made by Microsoft Nmake Compiler. To run it properly you have to
navigate to the program directory (explanation in Option 1), then type:
nmake find
Click enter, then the compiler will compile the files needed for the correct execution.
After that you can run the program by inputing the correct arguments, starting with program name.

When you are finished, you can clean the directory with one easy command:
nmake clean

When executed successfuly in the program directory the files left should be only:
input.txt, inputWords.txt, find.c, output.txt;

 
Known bugs:
- "-c" argument not working correctly - the program is only recognising -c argument.
- if user do not pass argument after -r, the program will be stuck in a loop.

If you are having trouble running the program or you found a bug feel free to contact me:
kisimovvalentin@gmail.com
