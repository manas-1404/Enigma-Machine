#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "rotorMachine.h"

//encryptFile function
void encryptFile(FILE *infile, FILE *outfile, int rotor1[28], int rotor2[28]){

    //storing the value of the initial settings of the rotor before they can be built
    int r1 = rotor1[0];
    int r2 = rotor2[0];

    //building the rotors first according to the PDF
    buildRotors(rotor1, rotor2);

    //setting the rotors based on the input of r1 and r2
    setRotor1(rotor1, r1);
    setRotor2(rotor2, r2);

    //checking if the infile is not null
    if(infile == NULL){
        printf("File does not exist. File not found.");
    }

    //infile is not null, so we will proceed with the encryption
    else{

        char lineBuffer[256];           //defining lineBuffer which will read each line line-by-line
        //while loop which will read every line from  the infile, till the a newline character of the max 255 characters
        while (fgets(lineBuffer, sizeof(lineBuffer), infile) != NULL)
        {
            //defining some variables which will be used in encryption process
            int i = 0;                  //varible which will traverse each character in a line
            char character;             //each character in a line
            int characterIndex;         //index of the character
            int valueRotor1;            //value of the index of the character in rotor1
            int indexRotor2;            //the corresponding index in rotor 2

            char valueRotor2;           //it contains the encrypted value of the character from rotor2

            //accessing each and every character in the line
            while (i < (int)strlen(lineBuffer)){
                character = lineBuffer[i];              //just storing the value of the character to a new variable
                if(character == '\n'){                  //if the character is newline character then we need to skip that character and go for the next one. 
                    break;
                }

                characterIndex = charToIndex(character);    //calling the charToIndex function which will give us the index of the character 

                valueRotor1 = rotor1[characterIndex];       //finding the value of the character using the characterIndex

                //variable which will traverse through rotor2 
                int j = 0;
                //for loop which is used to search for the valueRotor1 in rotor2
                for(j = 0; j < 28; j++){
                    //if the valueRotor1 is equal to some value in rotor2
                    if( valueRotor1 == rotor2[j] ){
                        indexRotor2 = j;                    //storing the value of the index to indexRotor2
                        break;                              //stoping the for loop since the value is found
                    }
                }

                //calling indexToChar function which will give us the character value of the indexRotor2, basically the encrypted text
                valueRotor2 = indexToChar(indexRotor2);

                //writing the encrypted character in the outfile
                fprintf(outfile, "%c", valueRotor2);  

                //rotating the rotors according to the PDF
                setRotor1(rotor1, 1);
                setRotor2(rotor2, 1); 

                //increasing the value of i so that it reads the next line
                i++;            
            }

            //checking if the length of the line is smaller than 255, then we need to manually add a line, or else we should not add a newline manually because it will automatically go to the next line
            if((int)strlen(lineBuffer) < 255){
                //adding a newline character after each and every character from a line is read and written completely
                fprintf(outfile, "\n");
            }
            
        }
    }
}

//DecryptFile function
void decryptFile(FILE *infile, FILE *outfile, int rotor1[28], int rotor2[28]){
    
    //storing the value of the initial settings of the rotor before they can be built
    int r1 = rotor1[0];
    int r2 = rotor2[0];

    //building the rotors first according to the PDF
    buildRotors(rotor1, rotor2);

    //setting the rotors based on the input of r1 and r2
    setRotor1(rotor1, r1);
    setRotor2(rotor2, r2);

    //checking if the infile is not null
    if(infile == NULL){
        printf("File does not exist. File not found.");
    }
    
    //infile is not null, so we will proceed with the Decryption
    else{

        char lineBuffer[256];           //defining lineBuffer which will read each line line-by-line
        //while loop which will read every line from  the infile, till the a newline character of the max 255 characters
        while (fgets(lineBuffer, sizeof(lineBuffer), infile) != NULL)
        {
            //defining some variables which will be used in Decryption process
            int i = 0;                                          //varible which will traverse each character in a line        
            char character;                                     //each character in a line
            int characterIndex;                                 //index of the character
            int valueRotor2;                                    //value of the index of the character in rotor2
            int indexRotor1;                                    //the corresponding index in rotor 1

            char valueRotor1;                                   //it contains the encrypted value of the character from rotor 1
            
            //accessing each and every character in the line
            while (i < (int)strlen(lineBuffer)){
                character = lineBuffer[i];                      //just storing the value of the character to a new variable
                if(character == '\n'){                          //if the character is newline character then we need to skip that character and go for the next one. 
                    break;
                }
                characterIndex = charToIndex(character);        //calling the charToIndex function which will give us the index of the character 

                valueRotor2 = rotor2[characterIndex];           //finding the value of the character using the characterIndex

                //variable which will traverse through rotor1
                int j = 0;
                //for loop which is used to search for the valueRotor2 in rotor1
                for(j = 0; j < 28; j++){
                    //if the valueRotor2 is equal to some value in rotor1
                    if( valueRotor2 == rotor1[j] ){
                        indexRotor1 = j;                        //storing the value of the index to indexRotor2
                        break;                                  //stoping the for loop since the value is found
                    }
                }

                //calling indexToChar function which will give us the character value of the indexRotor2, basically the decrypted text
                valueRotor1 = indexToChar(indexRotor1);

                //writing the encrypted character in the outfile
                fprintf(outfile, "%c", valueRotor1);  

                //rotating the rotors according to the PDF
                setRotor1(rotor1, 1);
                setRotor2(rotor2, 1); 

                //increasing the value of i so that it reads the next line
                i++;            
            }

            //checking if the length of the line is smaller than 255, then we need to manually add a line, or else we should not add a newline manually because it will automatically go to the next line
            if((int)strlen(lineBuffer) < 255){
                //adding a newline character after each and every character from a line is read and written completely
                fprintf(outfile, "\n");
            }

        }
    }
}

//function which will convert the index to character
char indexToChar(int convert){
    char alphabet;                              //declaring the aplhabet
    //if the index is 26, then return space ' '
    if(convert == 26){                          
        return ' ';
    }
    //if the index is 27, then return period '.'
    else if(convert == 27){                    
        return '.';
    }
    //for any other index return a character based on the conversion
    else{
        alphabet = (char)(convert + 65);            //type casting it to character based on ASCII value
        return alphabet;
    }
}

//function which will convert the character to index 
int charToIndex(char convert){
    int index = 0;                              //declaring the index
    //checking if the character is a space ' ', then return 26
    if(convert == ' '){
        index = 26;
    }
    //checking if the character is a period '.', then return 27
    else if(convert == '.'){
        index = 27;
    }
    //anything other than that will be a alphabet
    else{
        convert = toupper(convert);             //convert it to uppercase first
        index = convert - 65;                   //return the ASCII value of the character
    }

    return index;                               //returning the index back to the calling function
}

//function whcih will set the rotor1 (right) to the initial settings
void setRotor1(int rotor[28], int rotations){
    int i;                                      //declaring the index which will count the number of rotations
    //loop which will call the rotateRotorRight function rotation number of times
    for (i = 0; i < rotations; i++){
        rotateRotorRight(rotor);                //calling the rotateRotorRight with the array inside
    }
}

//function whcih will set the rotor2 (left) to the initial settings
void setRotor2(int rotor[28], int rotations){
    int i;                                      //declaring the index which will count the number of rotations
    //loop which will call the rotateRotorLeft function rotation number of times
    for (i = 0; i < rotations; i++){
        rotateRotorLeft(rotor);                 //calling the rotateRotorRight with the array inside
    }
}

//function which will Rotate Right will move every value down 1 index to the right and move the last index into the first index
void rotateRotorRight(int rotor[28]){
    int temp[28];                               //declaring an empty array having 28 length
    int i = 0;                                  //declaring the variable whcih will traverse the arrays

    temp[0] = rotor[27];                        //storing the value of the last element of rotor as the first element of temp

    //looping through the values where the remaining values of rotor from index = 1 to index = 26 is stored in temp
    for(i = 1; i < 28 ; i++){
        temp[i] = rotor[i - 1];
    }

    //traversing through temp and storing it's values in rotor
    for(i=0; i<28; i++){
        rotor[i] = temp[i];
    }
}

//Rotate Left will move every value down 1 index to the left and move the first index into the last index
void rotateRotorLeft(int rotor[28]){
    int temp[28];                               //declaring an empty array having 28 length
    int i=0;                                    //declaring the variable whcih will traverse the arrays

    //looping through the values where the values of rotor from index = 1 to index = 27 is stored in temp, basically everything except the first value
    for(i = 0; i<27; i++){
        temp[i] = rotor[i+1];                   
    }

    //storing the first value of rotor as the last element of the temp, thus rotating the entire rotor
    temp[27] = rotor[0];

    //traversing through temp and storing it's values in rotor
    for(i=0; i<28; i++){
        rotor[i] = temp[i];
    }
}

//function which will build the rotors
void buildRotors(int rotor1[28], int rotor2[28]){
    FILE *fileRotors;                           //declaring the filename

    //opening the rotors.ini so that we can read it and make the rotors
    fileRotors = fopen("rotors.ini", "r");

    //if the file is not proper, then give an error
    if(fileRotors == NULL){
        printf("File rotors.ini cannot be read.");
    }
    //file is proper
    else{
        int value;                              //encrypting and decrypting key
        int index = 0;                          //declaring the variable which will serve as the index for the arrays
        while (fscanf(fileRotors, "%d", &value) == 1){      //reading the values from the file
            value = value ^ 42;                 //encrpyting or decrypting it with XOR
            if(index < 28){                     //if the index is smaller than 28, then it will be stored in rotor 1
                rotor1[index] = value;
            }else{
                rotor2[index - 28] = value;     //else the index is greater than 28, then it will be stored in rotor 1
            }

            index++;                            //increase the index by manually at the end of the while loop, so that the loop works
        }
    }
    //close the opened file
    fclose(fileRotors);
}   

//function whhich will build the rotors.ini file
void buildIni(char *filename){
    FILE *fileConfig;                           //declaring the filename

    //opening the config.rtr so that we can read it and make the rotors.ini
    fileConfig = fopen(filename, "r");

    //if the file is not proper, then give an error
    if(fileConfig == NULL){
        printf("File Configration cannot be read.\n");
    }
    //file is proper
    else{
        FILE *rotors;                           //declaring the filename  
        rotors = fopen("rotors.ini", "w");     //opening the rotors.ini so that we can write it

        //if the file is not proper, then give an error
        if(rotors == NULL){
            printf("Can't open rotors.ini file");
        }
        //file is proper, we can write in it
        else{
            int value;                          //declaring the initial value
            while(fscanf(fileConfig, "%d", &value) == 1){           //reading the values from the file
                value = value ^ 42;                                 //encrpyting or decrypting it with XOR
                fprintf(rotors, "%d\n", value);                     //writing them down in rotors file
            }

            fclose(fileConfig);                 //closing the config file
            fclose(rotors);                     //closing the rotors.ini file

        }
    }
}
