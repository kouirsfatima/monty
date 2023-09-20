#include "monty.h"
/**
 * main - prints multiplies two numbers.
 *@argc: The number of arguments.
 *@argv: an array of pointers to the arguments.
 *Return: Always to 0.
 */
int main(int argc, char *argv[])
{
    FILE *file_fb;
    int i = 0;
    char line_number[1024];
    char *token;
    int j = 0; 

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file_fb = fopen(argv[1], "r");

    if (file_fb == NULL)
    {
        fprintf(stderr, "Error: Can't open file \n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line_number, sizeof(line_number), file_fb) != NULL)
    {
        i++;
        /**printf("%d%s", i, line_number);*/
        token = strtok(line_number, "  \n");
        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, "  \n");
            j++; 
        }
    }
    fclose(file_fb);
    return 0;
}
