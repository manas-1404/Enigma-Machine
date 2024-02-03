#ifndef ROTOR_ENCRYPTION_H
#define ROTOR_ENCRYPTION_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declaring the list of prototype functions
void buildIni(char *filename);
void buildRotors(int rotor1[28], int rotor2[28]);
void rotateRotorRight(int rotor[28]);
void rotateRotorLeft(int rotor[28]);
void setRotor1(int rotor[28], int rotations);
void setRotor2(int rotor[28], int rotations);
int charToIndex(char convert);
char indexToChar(int convert);
void encryptFile(FILE* infile, FILE* outfile, int rotor1[28], int rotor2[28]);
void decryptFile(FILE* infile, FILE* outfile, int rotor1[28], int rotor2[28]);

#endif
