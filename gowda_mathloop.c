#include <stdio.h>

int main() {
    char ch;
    int f, a = 10, b = 20;

    int i=0;

    for(i = 1; i<=5; i++){
        printf("Enter the character : ");
        scanf("%c", &ch);
        printf("ch = %c\n", ch);

        switch (ch) {
        case '+':
            f = a + b;
            printf("f = %d\n", f);
            break;
        case '-':
            f = a - b;
            printf("f = %d\n", f);
            break;
        case '*':
            f = a * b;
            printf("f = %d\n", f);
            break;
        case '/':
            f = a / b;
            printf("f = %d\n", f);
            break;
        case '%':
            f = a % b;
            printf("f = %d\n", f);
            break;
        default:
            printf("invalid operator\n");
            break;
        }
    }
}