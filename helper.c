#include <stdio.h>
#include <string.h>
#include <ctype.h>

char indexToChar(int convert);

int main() {
    // FILE *file = fopen("C://Users//manas//CSE 240//Assignment3//sample.txt", "w");  // Open a file for writing (create if it doesn't exist)

    // if (file == NULL) {
    //     perror("Failed to open the file");
    //     return 1;
    // }

    // // Write lines of text to the file using fprintf
    // fprintf(file, "T");
    // fprintf(file, "h");
    // fprintf(file, "i");
    // fprintf(file, "s");
    // fprintf(file, "\n");
    // fprintf(file, "And this is the third line.\n");

    // // Close the file
    // fclose(file);

    printf("Character of this index = %c", indexToChar(19));

    return 0;
}

char indexToChar(int convert){
    char alphabet;
    if(convert == 26){
        return ' ';
    }else if(convert == 27){
        return '.';
    }else{
        alphabet = (char)(convert + 65);
        return alphabet;
    }
}




// #include <stdio.h>
// #include <stdlib.h>

// void readAndPrintFileLineByLine(const char *filename) {
//     FILE *file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Failed to open the file: %s\n", filename);
//         return;
//     }

//     char line[256];  // Adjust the buffer size as needed
//     while (fgets(line, sizeof(line), file) != NULL) {
//         printf("%s this is line 1\n", line);
//     }

//     fclose(file);
// }

// int main() {
//     const char *filename = "C://Users//manas//CSE 240//Assignment3//sample.txt";  // Replace with your file's path
//     readAndPrintFileLineByLine(filename);
//     return 0;
// }
















// #include <stdio.h>
// #include <stdlib.h>

// // Function prototypes
// void functionA();
// void functionB();

// int main(int argc, char *argv[]) {
//     if (argc != 3) {
//         printf("Usage: %s <function_name>\n", argv[0]);
//         return 1; // Exit with an error code
//     }

//     char *functionName = argv[2];

//     if (argc == 3 && strcmp(functionName, "functionA") == 0) {
//         functionA();
//     } else if (strcmp(functionName, "functionB") == 0) {
//         functionB();
//     } else {
//         printf("Unknown function: %s\n", functionName);
//         return 1; // Exit with an error code
//     }

//     return 0;
// }

// void functionA() {
//     printf("Function A is running.\n");
// }

// void functionB() {
//     printf("Function B is running.\n");
// }















// #include <stdio.h>

// int main() {
//     FILE *file;
//     int num;

//     // Open the file for reading
//     file = fopen("C:\\Users\\manas\\CSE 240\\Assignment3\\config.rtr", "r");
//     if (file == NULL) {
//         printf("Failed to open the file.\n");
//         return 1;
//     }

//     printf("Integers in the file:\n");

//     // Read integers from the file and print them
//     while (fscanf(file, "%d", &num) == 1) {
//         printf("%d\n", num);
//     }

//     // Close the file
//     fclose(file);

//     return 0;
// }


// C program to print 
// ASCII Value of Character 
// #include <stdio.h> 

// Driver code 
// int main() 
// { 
// 	char c = 'A'; 

// 	// %d displays the integer value of 
// 	// a character 
// 	// %c displays the actual character 
// 	// printf("The ASCII value of %c is %d", c, c); 
//     printf("The ASCII value of %c is %d\n", c, ascii(c));

// 	return 0; 
// }


// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char character = 'a';  // Character 'A'
//     printf("%c", character);
//     character = toupper(character);
//     int asciiValue = character;  // ASCII value of 'A'

//     // Perform arithmetic operations
//     int resultAdd = asciiValue + 1;  // Add 1 to the ASCII value
//     int resultSubtract = asciiValue - 1;  // Subtract 1 from the ASCII value
//     int resultMultiply = asciiValue * 2;  // Multiply the ASCII value by 2
//     int resultDivide = asciiValue / 2;  // Divide the ASCII value by 2

//     // Display results
//     printf("Character: %c\n", character);
//     printf("ASCII Value: %d\n", asciiValue);
//     printf("ASCII Value + 1: %d\n", resultAdd);
//     printf("ASCII Value - 1: %d\n", resultSubtract);
//     printf("ASCII Value * 2: %d\n", resultMultiply);
//     printf("ASCII Value / 2: %d\n", resultDivide);

//     return 0;
// }

// #include <stdio.h>

// // Function to compare a character to a space character
// int compareCharToSpace(char charToCompare) {
//     if (charToCompare == ' ') {
//         return 1;  // Return 1 if the characters are equal
//     } else if (charToCompare == '.')
//     {
//         printf(". is equal");
//         return 0;
//     }
//     else {
//         return 0;  // Return 0 if the characters are not equal
//     }
// }

// int main() {
//     char character1 = 'A';
//     char character2 = '.';

//     int result1 = compareCharToSpace(character1);
//     int result2 = compareCharToSpace(character2);

//     if (result1 == 1) {
//         printf("character1 is equal to a space character.\n");
//     } else {
//         printf("character1 is not equal to a space character.\n");
//     }

//     if (result2 == 1) {
//         printf("character2 is equal to a space character.\n");
//     } else {
//         printf("character2 is not equal to a space character.\n");
//     }

//     return 0;
// }


// #include <stdio.h>

// char indexToChar(int index) {
//     if (index >= 0 && index < 26) {
//         return 'A' + index; // Convert index to a character
//     } else {
//         return '\0'; // Return null character for out-of-range indices
//     }
// }

// int main() {
//     int index1 = 2;  // Example index
//     int index2 = 20; // Out-of-range index
//     char result1, result2;

//     result1 = indexToChar(index1);
//     result2 = indexToChar(index2);

//     if (result1 != '\0') {
//         printf("Character for index1: %c\n", result1);
//     } else {
//         printf("Index1 is out of range.\n");
//     }

//     if (result2 != '\0') {
//         printf("Character for index2: %c\n", result2);
//     } else {
//         printf("Index2 is out of range.\n");
//     }

//     return 0;
// }


// #include <stdio.h>

// int main(int argc, char *argv[]) {
//     // Check if any command-line arguments were provided
//     if (argc > 1) {
//         printf("Command-line arguments:\n");

//         // Iterate through the arguments and print them
//         for (int i = 1; i < argc; i++) {
//             printf("Argument %d: %s\n", i, argv[i]);
//         }
//     } else {
//         printf("No command-line arguments provided.\n");
//     }

//     return 0;
// }
