/************************************************
* Author: Joshua Thaisananikone
* Created October 13, 2024
* This program will be implementing a modified version of the grep command-line utility. The user will input a command line 
* with the following format: ./mygrep <pattern> <filename> with optional [-i] for case insensitive search, [-n] for line number.
* Regardless of user input, the program will be searching for a pattern (word) inside every line in a specified file if it exists.
* Resources used:
* https://www.geeksforgeeks.org/strstr-in-ccpp/
* https://cplusplus.com/reference/cstring/strcspn/
*************************************************/

#include "text.h"
#define MAX_LINE_LENGTH 1024  // Maximum number of characters in a line
#define MAX_PATTERN_LENGTH 10  // Maximum length of the search pattern

/*
* This is a helper function to assist us in searching for a pattern from a specified file name.
* Input - There is a char pointer entitled word that stores the pattern we are searching for. There is a integer variable entitled
* ignoredCase that can hold "0" or "1". If it is 1, then we will be case-sensitive in our pattern search. There is a also a integer 
* variable named giveLine that can can hold "0" or "1". If it is 1, then we will add prefix to the lines that are printed when the 
* pattern is found. We also have a char pointer called filename that points to file that we will be searching for the pattern in.
* Output - No output.
*
*/
void readFile(char *word, int ignoreCase, int giveLine, char *filename){
    // Open file and set to read.
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: Failed to open %s\n", filename);
        return;
    }
     
    char line[MAX_LINE_LENGTH];
    int line_number = 0;  // Keep track of the current line number
    int found = 0;  // A flag to track if we found the pattern in any line

    while(fgets(line, sizeof(line), fp)){
        line_number++;
        // Find the position of the newline character
        int newlinePos = strcspn(line, "\n");

        // Replace the newline with a null terminator for clean comparision
        line[newlinePos] = '\0';

        char *findPattern = NULL;  // This will store the position of the pattern if found

        if(ignoreCase == 1){
            char lowerLine[MAX_LINE_LENGTH];
            char lower_pattern[MAX_PATTERN_LENGTH + 1]; // +1 to accomodate null terminator.

             // Convert the line to lowercase
            for (int i = 0; line[i]; i++) {
                lowerLine[i] = tolower(line[i]);
            }

            lowerLine[strlen(line)] = '\0';  // End the lowercase string properly

            // Convert the pattern to lowercase
            for (int i = 0; word[i]; i++) {
                lower_pattern[i] = tolower(word[i]);
            }

            lower_pattern[strlen(word)] = '\0';  // End the lowercase pattern string properly

            // Now, search for the lowercase pattern in the lowercase line
            findPattern = strstr(lowerLine, lower_pattern);
        } else{
            // If case-sensitive, just look for the pattern in the line
            findPattern = strstr(line, word);
        }

        // If the pattern is found in the line, print the line
        if (findPattern != NULL) {
            found = 1;  // We found at least one match

            // If -n is used, print the line number first
            if (giveLine == 1) {
                printf("%d ", line_number);
            }

            // Print the matching line
            printf("%s\n", line);
            }
        }

        // If no match was found, print a message
        if (found == 0) {
            printf("Pattern not found in the file.\n");
        }

    fclose(fp); // Close file
}

/*
* This function will perform a modified version of 'man grep'. It will retrieve up to 4 arguments (no less than two) 
* from the command line. These arguments will be used to determine the pattern to look for, how to search for a pattern / '-i' (case-sensitive)
* / '-n' (line index), and determine what file to look at. We will be using a helper method to assist us in searching for a pattern.
* Input - a int value entitled argc that keeps count of the argument inputted in the command line. An array of char pointers
* that contains the arguments used.
* Output - None
*/
void grepLite(int argc, char *argv[]) {
    // First check if the correct number of arguments is provided
    if (argc > 5) {
       printf("Fifth argument: %s\n", argv[4]);
       return;
   }

    if (argc < 3) { // At least two argument plus the program name is required
        printf("Usage: grep <pattern> <filename> with optional [-i] for case insensitive search, [-n] for line number\n");
        return;
    }
    
    char* word = argv[1];
    if(strlen(word) > 10){
        printf("ERROR: The pattern is above 10 characters.\n");
        return;
    }
    // The pattern is stored in word.
    
    char* filename = argv[2];

    int ignoreCase = 0; // if 1 then true.
    int giveLine = 0; // if 1 then true.
    int Error_Found = 0;
    
    // ERROR check for empty hypens
    for (int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-") == 0){
            printf("Usage: grep <pattern> <filename> with optional [-i] for case insensitive search,  [-n] for line number\n");
            Error_Found = 1;
            break;
        }
    }
    
    if(Error_Found == 1) return;

    // Check if we should ignore cases when checking for pattern.
    if((argc > 3 && strcmp(argv[3], "-i") == 0 ) || (argc > 4 && strcmp(argv[4], "-i") == 0)){
        ignoreCase = 1;
    }
    // Check if we need to prefix the output with the line number
    if((argc > 4 && strcmp(argv[4], "-n") == 0) || (argc > 3 && strcmp(argv[3], "-n") == 0)){
        giveLine = 1;
    }
    readFile(word, ignoreCase, giveLine, filename);// will handle file reading for us.
    

}
