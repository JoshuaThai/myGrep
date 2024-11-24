# myGrep
## Description
This C program implements modified versions of the 'grep' command commonly found in Unix-like operating systems. The 'grep' command is used to search for specific patterns within text files
## Usage:
Compile it using a C compiler and run the executable from the command line with appropriate arguments.
```
./main <pattern> <file> [-i] [-n]
optional arguments are specified in [ ]

EXAMPLE TEST CASES (to input into command lines):
// For Basic Search
./mygrep hello sample.txt

// For Case-Insensitive Search
./mygrep hello sample.txt -i

// For Search with Line Numbers
./mygrep world sample.txt -n

// For Case-Insensitive Search with Line Numbers
./mygrep test sample.txt -i -n
OR:
./mygrep test sample.txt -n -i
```
