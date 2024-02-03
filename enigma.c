#include <stdio.h>
#include <string.h>
#include <ctype.h>

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


// verification methods
void printArray(int arr[28]);

int main(int argc, char *argv[]){

    // if(argc == 0){
    //     printf("Usage Error")
    // }else if (argc == 3 && strcmp(argv[1], "-i") == 0)
    // {
    //     buildIni(argv[2]);
    // }else if (argc == 7 && strcpm(argv[1], "-e") == 0){
    //     encryptFile(argv[2], argv[3], argv[5], argv[6]);
    // }else if (argc == 7 && strcmp(argv[1], "-d") == 0){
    //     decryptFile(argv[2], argv[3], argv[5], argv[6]);
    // }else if (argc == 9 && strcmp(argv[1], "-e") == 0){
    //     encryptFile(argv[2], argv[3], argv[5], argv[6]);
    //     buildIni(argv[8]);
    // }else if (argc == 9 && strcmp(argv[1], "-d") == 0){
    //     decryptFile(argv[2], argv[3], argv[5], argv[6]);
    //     buildIni(argv[8]);
    // }else{
    //     printf("Unknown Command: Usage Error");
    // }
    

    int rotor1[28];
    int rotor2[28];

    printf("Before Encrypt function call\n");

    buildIni("C://Users//manas//CSE 240//Assignment3//config.rtr");

    rotor1[0] = 5;
    rotor2[0] = 5;

    FILE *infile = fopen("C://Users//manas//CSE 240//Assignment3//test.txt", "r");
    FILE *outfile = fopen("C://Users//manas//CSE 240//Assignment3//output.txt", "w");
    

    encryptFile(infile, outfile, rotor1, rotor2);
    printf("\nAfter Encrypt function call\n.");

    fclose(infile);
    fclose(outfile);

    printf("\n-------------------------------------------------------------------------------------------------\n");

    // printf("\nBefore Decrypt function call\n");

    // FILE *cleanfile = fopen("C://Users//manas//CSE 240//Assignment3//cleanfile.txt","w");
    // FILE *encryptedFile = fopen("C://Users//manas//CSE 240//Assignment3//output.txt", "r");

    // decryptFile(encryptedFile, cleanfile, rotor1, rotor2);

    // fclose(cleanfile);
    // fclose(encryptedFile);

    // printf("\nAfter Decrypt function call\n");

    return 1;
}

void encryptFile(FILE *CleanData, FILE *EncryptData, int rotor1[28], int rotor2[28]){
    int r1 = rotor1[0];
    int r2 = rotor2[0];

    printf("\nSet Rotation 1: %d\n", r1);
    printf("\nSet Rotation 2: %d\n", r2);

    buildRotors(rotor1, rotor2);

    setRotor1(rotor1, r1);
    setRotor2(rotor2, r2);

    if(CleanData == NULL){
        printf("File does not exist. File not found.");
    }else{

        char lineBuffer[256];
        while (fgets(lineBuffer, sizeof(lineBuffer), CleanData) != NULL)
        {
            int i = 0;
            char character;
            int characterIndex;
            int valueRotor1;
            int indexRotor2;

            char valueRotor2;       //it contains the encrypted value of the character 

            printf("\nSize of line: %d\n", sizeof(lineBuffer));
            printf("\nString of line: %d\n", strlen(lineBuffer));
            
            while (i < (int)strlen(lineBuffer)){
                character = lineBuffer[i];
                if(character == '\n'){
                    printf("Found new line character at: %d", i);
                    break;
                }
                printf("Character: %c\n", character);
                characterIndex = charToIndex(character);

                valueRotor1 = rotor1[characterIndex];

                int j = 0;
                for(j = 0; j < 28; j++){
                    if( valueRotor1 == rotor2[j] ){
                        indexRotor2 = j;
                        break;
                    }
                }

                valueRotor2 = indexToChar(indexRotor2);

                printf("The value of valueRotor2 : %c\n", valueRotor2);

                fprintf(EncryptData, "%c", valueRotor2);  

                rotateRotorRight(rotor1);
                rotateRotorLeft(rotor2); 

                i++;            
            }

            //adding a newline character after each and every character from a line is read and written completely
            fprintf(EncryptData, "\n");

        }
    }
}

void decryptFile(FILE *EncryptData, FILE *CleanData, int rotor1[28], int rotor2[28]){
    buildRotors(rotor1, rotor2);

    if(EncryptData == NULL){
        printf("File does not exist. File not found.");
    }else{

        char lineBuffer[256];
        while (fgets(lineBuffer, sizeof(lineBuffer), EncryptData) != NULL)
        {
            int i = 0;
            char character;
            int characterIndex;
            int valueRotor2;
            int indexRotor1;

            char valueRotor1;       //it contains the encrypted value of the character 

            printf("\nSize of line: %d\n", sizeof(lineBuffer));
            printf("\nString of line: %d\n", strlen(lineBuffer));
            
            while (i < (int)strlen(lineBuffer)){
                character = lineBuffer[i];
                if(character == '\n'){
                    printf("Found new line character at: %d", i);
                    break;
                }
                printf("Character: %c\n", character);
                characterIndex = charToIndex(character);

                valueRotor2 = rotor2[characterIndex];

                int j = 0;
                for(j = 0; j < 28; j++){
                    if( valueRotor2 == rotor1[j] ){
                        indexRotor1 = j;
                        break;
                    }
                }

                valueRotor1 = indexToChar(indexRotor1);

                printf("The value of valueRotor1 : %c\n", valueRotor1);

                fprintf(CleanData, "%c", valueRotor1);  

                setRotor1(rotor1, 1);
                setRotor2(rotor2, 1); 

                i++;            
            }

            //adding a newline character after each and every character from a line is read and written completely
            fprintf(CleanData, "\n");

        }
    }
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

int charToIndex(char convert){
    int index = 0;
    if(convert == ' '){
        index = 26;
    }else if(convert == '.'){
        index = 27;
    }else{
        convert = toupper(convert);
        index = convert - 65;
    }

    return index;
}

void setRotor1(int rotor[28], int rotations){
    int i;
    for (i = 0; i < rotations; i++){
        rotateRotorRight(rotor);
    }

}

void setRotor2(int rotor[28], int rotations){
    int i;
    for (i = 0; i < rotations; i++){
        rotateRotorLeft(rotor);
    }

}


void rotateRotorRight(int rotor[28]){
    int temp[28];
    int i = 0;

    temp[0] = rotor[27];

    for(i = 1; i < 28 ; i++){
        temp[i] = rotor[i - 1];
    }

    for(i=0; i<28; i++){
        rotor[i] = temp[i];
    }
}

void rotateRotorLeft(int rotor[28]){
    int temp[28];
    int i=0;

    for(i = 0; i<27; i++){
        temp[i] = rotor[i+1];
    }

    temp[27] = rotor[0];

    for(i=0; i<28; i++){
        rotor[i] = temp[i];
    }
}



void buildRotors(int rotor1[28], int rotor2[28]){
    FILE *fileRotors;

    fileRotors = fopen("C:\\Users\\manas\\CSE 240\\Assignment3\\rotors.ini", "r");

    if(fileRotors == NULL){
        printf("File rotors.ini cannot be read.");
    }else{
        int value;
        int index = 0;
        while (fscanf(fileRotors, "%d", &value) == 1){
            value = value ^ 42;
            if(index < 28){
                rotor1[index] = value;
            }else{
                rotor2[index - 28] = value;
            }

            index++;
        }
    }

    fclose(fileRotors);
}

void buildIni(char *filename){
    FILE *fileConfig;

    fileConfig = fopen(filename, "r");

    if(fileConfig == NULL){
        printf("File Configration cannot be read.\n");
    }else{
        FILE *rotors;
        rotors = fopen("C:\\Users\\manas\\CSE 240\\Assignment3\\rotors.ini", "w");

        if(rotors == NULL){
            printf("Can't open rotors.ini file");
        }else{

            printf("The contents of configration are :\n");

            int value;
            while(fscanf(fileConfig, "%d", &value) == 1){
                printf("%d\n", value);
                value = value ^ 42;
                printf("The value after encryption: %d\n", value);
                printf("--------------------------------\n");
                fprintf(rotors, "%d\n", value);
            }

            fclose(fileConfig);
            fclose(rotors);

        }
    }
}

// verification method 1
void printArray(int arr[28]){
    int i = 0;
    for(i = 0; i < 28; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}