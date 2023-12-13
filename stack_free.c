#include "monty.h"
/**
 * stack_free - my code Function
 * @nodepointer: nodepointer
 */
void stack_free(stack_t *nodepointer)
{
stack_t *reserved;

reserved = nodepointer;
while (nodepointer)
{
reserved = nodepointer->next;
free(nodepointer);
nodepointer = reserved;
}
}
