#include "monty.h"

glob_var va = {0, NULL, NULL};
/**
 * main - prints multiplies two numbers.
 *@argc: The number of arguments.
 *@argv: an array of pointers to the arguments.
 *Return: Always to 0.
 */
int main(int argc, char *argv[])
{
	int i = 0, line_count = 0;
	char line[1024], *token;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	va.file_fb = fopen(argv[1], "r");
	if (va.file_fb == NULL)
	{
		fprintf(stderr, "Error: Can't open file \n");
		exit(EXIT_FAILURE); }
	while (fgets(line, sizeof(line), va.file_fb) != NULL)
	{
		line_count++;
		va.args = malloc(sizeof(char *) * 3);
		token = strtok(line, "  \n\t");
		for (i = 0; token && i < 2; i++, token = strtok(NULL, "  \n\t"))
			va.args[i] = token;
		va.args[i] = NULL;
		if (va.args[0] == NULL || strcmp(va.args[0], "nop") == 0
			|| va.args[0][0] == '#')
		{
			free(va.args);
			continue; }
		if (strcmp(va.args[0], "push") == 0)
		{
			if (!va.args[1])
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				free(va.args), fclose(va.file_fb), free_stack(&stack);
				exit(EXIT_FAILURE); }
			va.number = __atoi(va.args[1], stack, line_count); }
		execute(&stack, va.args[0], line_count);
		free(va.args);
	}

	fclose(va.file_fb), free_stack(&stack);
	return (0);
}
