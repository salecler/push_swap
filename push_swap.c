#include "push_swap.h"

// TODO mover todas mis funciones para configuración de mis stacks en otro archivo

// Iniciación de mi stack
void initStack(Stack *stackA)
{
    stackA->head = NULL;
}

// Push de un numero pasado como argumento en mi stack
void push(Stack *stackA, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error al asignar memoria al nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    if (stackA->head == NULL)
    {
        stackA->head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = stackA->head;
        stackA->head = newNode;
    }
}

// Enlaza el ultimo nodo con el primero
void connectStack(Stack *stackA)
{
    Node *current = stackA->head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = stackA->head;
}

// Printea el contenido de mi lista
void printList(Stack *stackA)
{
    Node *current = stackA->head;
    while(current->next != stackA->head)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("%d\n", current->value);
}

int main(int ac, char **av)
{
    // TODO Capear si se pasa 0 argumentos o si lo que se pasa no son numeros
    // TODO Capear si es solamente un numero
    if (ac <= 2)
    {
        printf("%s",av[1]);
        return (0);
    }
    Stack stackA;
    Stack stackB;

    initStack(&stackA);
    initStack(&stackB);
    push(&stackA, 3);
    push(&stackA, 53);
    push(&stackA, 5);
    connectStack(&stackA);
    printList(&stackA);
    return(0);
}