#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    int n;

    if (!arg || sscanf(arg, "%d", &n) != 1)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; // Unused parameter

    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
