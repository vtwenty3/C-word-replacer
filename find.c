/* Find and Replace program made by Valentin Kisimov (40439132), last modification 14:23, 03/01/2020;
Purpouse: Read a .txt file from directory of the program, then replace a given word with another
and output an output.txt file containing the changed text.
It is working with arguments. Syntax:
find  oldword  -i WordsInput.txt  -r  newword  -c
 0       1      2        3        4    5       6     */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //512 seems to work better than 256.
#define MAX 512
int main(int argc, char * argv[]) {
  //45 letters is the longest word in English
  char oldWord[46];
  char neWord[46];
  char printAfter[MAX];
  char printBefore[MAX];
  char mainString[MAX];
  char name[10] = "find";
  char dir[23];
  char argInp[3];
  char replace[3];
  int argCount = argc;
  int caseSense = 0;
  FILE * inpFile, * outFile, * inpFileCons, * outFileCons;
  char * token;
  char * token2;
  char * ptr1;
  char * ptr2;
  char * ptr3;
  char * ptr4;
  printf("\n************************************************************************\n\n");
  printf("Program name is: %s\n", argv[0]);
  printf("You entered %d arguments.\n", argc);
  //Assuming that everytime argv[1] is oldWord
  strcpy(oldWord, argv[1]);
  printf("Scanning file for:%s\n\n", oldWord);

  //accepting mixed arguments:
  if (argc >= 4 || argc <= 7) {
    //loop with pos to determine the argument's position
    for (int pos = 0; pos < argc; pos++) {
      if (strcmp(argv[pos], "-i") == 0) {
        //when -i is found save it to argInp
        strcpy(argInp, argv[pos]);
        // Copy next argument to inputFile variable
        strcpy(dir, argv[pos + 1]);
      }
        if (strcmp(argv[pos], "-r") == 0) {
          strcpy(replace, "-r");
            if (strcmp(argv[pos], "") != 0) {
              strcpy(neWord, argv[pos + 1]);
            }
        } else if (strcmp(argv[pos], "-c") == 0) {
        caseSense = 1;
        printf("***-c found in argument:%d, but strcasestr is not working.***\n", pos);
        }
    }
  } else {
    printf("***Arguments Error***");
    return 1;
    }

  //load input.txt to 2 file pointers
  if ((strcmp(argInp, "-i")) == 0) {
    inpFile = fopen(dir, "r");
    inpFileCons = fopen(dir, "r");
  } else { printf("\n***Arguments Error! Check -i***\n");
    return 1;
    }

  outFile = fopen("output.txt", "w");

  if (!inpFile) {
    printf("***Input file error***\n Check if the file is in directory\n");
    return 0;
  }

  if (!outFile) {
    printf("***Creating output file error!***\n");
    return 0;
  }

  printf("Occurrence found in these words:\n");

  //print to the console whole words, before the replacing:
  while (!feof(inpFileCons)) {
    fgets(printBefore, MAX, inpFileCons);
    token = strtok(printBefore, " ");
    ptr3 = token;
      while (token != NULL) {
        if (strstr(token, oldWord)) {
          printf("%s\n", token);
        }
      token = strtok(NULL, " ");
      }
  }

  //Replacing the words:
  if ((strcmp(replace, "-r")) == 0) {
    while (!feof(inpFile)) {
      strcpy(mainString, "\0");
      //getting data from inputfile, loding it to mainString
      fgets(mainString, MAX, inpFile);
      //check if oldWord is present in current line in MainString
        if (strstr(mainString, oldWord)) {
          ptr2 = mainString;
            while (ptr1 = strstr(ptr2, oldWord)) {
              //replacing:
              while (ptr2 != ptr1) {
                fputc( * ptr2, outFile);
                ptr2++;
              }
              ptr1 = ptr1 + strlen(oldWord);
              fprintf(outFile, "%s", neWord);
              ptr2 = ptr1;
            } //write to output file:
            while ( * ptr2 != '\0') {
              fputc( * ptr2, outFile);
              ptr2++;
            }
        } else {
        //if current line dont have oldword just copy it to mainstring
        fputs(mainString, outFile);
      }
    }
  printf("\nEverything is successfuly replaced!\n");
  } else {
    printf("\n***I did not replace anything!***\nIf you want me to do it, type *-r* in argument menu.\n");
    return 1;
    }
  //file needed for printing the words after the change:
  outFileCons = fopen("output.txt", "r");
  printf("\nChanged words:\n");
  // same algoritm for printing the replaced words:
  while (!feof(outFileCons)) {
    fgets(printAfter, MAX, outFileCons);
    token2 = strtok(printAfter, " ");
    ptr4 = token2;

      while (token2 != NULL) {
        if (strstr(token2, neWord)) {
          printf("%s\n", token2);
        }
      token2 = strtok(NULL, " ");
      }
  }
  //close all used files
  fclose(inpFile);
  fclose(outFile);
  fclose(inpFileCons);
  fclose(outFileCons);
  printf("Program execution successfuly! Exiting...");
  printf("\n\n************************************************************************\n");
  return 0;
}
