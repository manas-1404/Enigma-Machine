#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cstdlib>
#include "rotorMachine.h"

//function declarations used in the main function
void encryptFile(FILE *infile, FILE *outfile, int rotor1[28], int rotor2[28]);
void decryptFile(FILE *infile, FILE *outfile, int rotor1[28], int rotor2[28]);
char indexToChar(int convert);
int charToIndex(char convert);
void setRotor1(int rotor[28], int rotations);
void setRotor2(int rotor[28], int rotations);
void rotateRotorRight(int rotor[28]);
void rotateRotorLeft(int rotor[28]);
void buildRotors(int rotor1[28], int rotor2[28]);
void buildIni(char *filename);


//main function which takes in command line arguments
int main(int argc, char *argv[]){

    //initializing rotor arrays based on the PDF
    int rotor1[28];
    int rotor2[28];

    //if there are no arguments passed, then print Usage Error
    if(argc == 0){
        printf("Usage Error");
        return 1;
    }
    //checking for ./exe -i <file> argument and calling the buildIni file
    else if (argc == 3 && strcmp(argv[1], "-i") == 0){
        buildIni(argv[2]);
    }
    //checking for ./exe -e <file1> <file2> -r <r1> <r2> argument and calling the encryptFile function
    else if (argc == 7 && strcmp(argv[1], "-e") == 0){
        rotor1[0] = atoi(argv[5]);
        rotor2[0] = atoi(argv[6]);

        FILE *CleanFile = fopen(argv[2], "r");
        FILE *EncryptedFile = fopen(argv[3], "w");

        encryptFile(CleanFile, EncryptedFile, rotor1, rotor2);

        fclose(CleanFile);
        fclose(EncryptedFile);
    }
    //checking for ./exe -d <file1> <file2> -r <r1> <r2> argument and calling decryptFile function
    else if (argc == 7 && strcmp(argv[1], "-d") == 0){
        rotor1[0] = atoi(argv[5]);
        rotor2[0] = atoi(argv[6]);

        FILE *InputEncryptedFile = fopen(argv[2], "r");
        FILE *DecryptedFile = fopen(argv[3], "w");

        decryptFile(InputEncryptedFile, DecryptedFile, rotor1, rotor2);

        fclose(InputEncryptedFile);
        fclose(DecryptedFile);
    }
    //checking for ./exe -e <file1> <file2> -r <r1> <r2> -i <file> argument in command line and calling encryptFile & buildIni function
    else if (argc == 9 && strcmp(argv[1], "-e") == 0){
        buildIni(argv[8]);

        rotor1[0] = atoi(argv[5]);
        rotor2[0] = atoi(argv[6]);

        FILE *CleanFile2 = fopen(argv[2], "r");
        FILE *EncryptedFile2 = fopen(argv[3], "w");

        encryptFile(CleanFile2, EncryptedFile2, rotor1, rotor2);

        fclose(CleanFile2);
        fclose(EncryptedFile2);

    }
    //checking for ./exe -d <file1> <file2> -r <r1> <r2> -i <file> argument in command line and calling decryptFile & buildIni function
    else if (argc == 9 && strcmp(argv[1], "-d") == 0){
        buildIni(argv[8]);

        rotor1[0] = atoi(argv[5]);
        rotor2[0] = atoi(argv[6]);

        FILE *InputEncryptedFile2 = fopen(argv[2], "r");
        FILE *DecryptedFile2 = fopen(argv[3], "w");

        decryptFile(InputEncryptedFile2, DecryptedFile2, rotor1, rotor2);

        fclose(InputEncryptedFile2);
        fclose(DecryptedFile2);
    }
    //any other command line arguments will prompt Usage Error. 
    else{
        printf("Unknown Command: Usage Error");
        return 1;
    }
    
    return 0;
}