#include <stdio.h>
# include <string.h>
int main()
{
    char command[] = "gcc shell.c -o customshell";
    char *line = command; //pointer 'line' stores where the command starts
    char **token_positions = malloc(sizeof(char *) * 64);
    char *token = strtok(command, " ");
    int index = 0;

    token_positions[index] = token;
    index++;
    for (int i=0;i<5;i++)
    while (token != 0)
    {
        // Tokenize the rest of the command
        token = strtok(NULL, " ");      //continue finding the next token
        printf("Debug here %d %x\n", index, token);
        token_positions[index] = token; //store the position
        index++;
    }
    printf("after loop");
    token_positions[index] = NULL; //dont forget to NULL terminate.
    printf("First token is : %s, it is at address %0x \n", token_positions[0], token_positions[0]);
    printf("Second token is : %s, it is at address %0x \n", token_positions[1], token_positions[1]);
    printf("Third token is : %s, it is at address %0x \n", token_positions[2], token_positions[2]);
    printf("Fourth token is : %s, it is at address %0x \n", token_positions[3], token_positions[3]);
}
