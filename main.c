#include"monty.h"
/**
 * main - Entry points
 * Description: create an interpreter for Monty ByteCodes files.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
*/
int main(int argc, char *argv[])
{
    FILE *file_fb;
    int i = 0;
    char line_number[1024];

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
        {
            printf("%d%s\n", i, line_number);
        }
    }
    fclose(file_fb);
    return 0;
}
