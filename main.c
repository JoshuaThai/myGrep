/************************************************
* Author: Joshua Thaisananikone
* Created October 13, 2024
* Description: 
* This C program implements modified versions of the 'grep' command commonly found in Unix-like operating systems. 
* The 'grep' command is used to search for specific patterns within text files.

* The user will input a command line with the following format: ./mygrep <pattern> <filename> with optional [-i] for case 
* insensitive search, [-n] for line number. Regardless of user input, the program will be searching for a pattern (word) inside every
* line in a specified file if it exists.
* Resources used:
* https://www.geeksforgeeks.org/strstr-in-ccpp/
* https://cplusplus.com/reference/cstring/strcspn/

* Usage:
* Compile it using a C compiler and run the executable from the command line with appropriate arguments.
*    - ./main <pattern> <file> [-i] [-n]
*    - optional arguments are specified in [ ]
*******************************************************************/


#include "text.h"


int main(int argc, char *argv[]) {
    
    grepLite(argc, argv);
 
    return 0;
}