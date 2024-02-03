#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char sourceString[] = "Lorem ipsum dolor sit amet consectetur adipiscing elit Integer tempor posuere nibh quis tempor Sed eu turpis nulla Suspendisse vestibulum blandit enim vitae feugiat Nulla malesuada orci ut nisi blandit congue Maecenas vulputate magna in tellus eros ";
    char *token;
    printf("Splitting string...");
    token = strtok(sourceString, " "); // first read
    while (token != NULL)
    {
        printf("%s\n", token);
        printf("-------------\n");
        token = strtok(NULL, " "); // keep tokenizing notice NULL
    }
    return 0;
}
