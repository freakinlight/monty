#include "monty.h"
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \n");

        if (!opcode || opcode[0] == '#')
            continue;

        instruction_t *instruction = get_instruction(opcode);
        if (!instruction)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        instruction->f(&stack, line_number);
    }

    free(line);
    fclose(file);

    return 0;
}
