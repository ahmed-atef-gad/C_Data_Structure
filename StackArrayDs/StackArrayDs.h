#ifndef STACKARRAYDS_H_INCLUDED
#define STACKARRAYDS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *data;
    int ElementCount;
    unsigned int StackMaxSize;
    int StackTop;
}Stack_t;

typedef enum{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER,
    STACK_DESTROYED
}StackStatus_t;


Stack_t* CreateStack(StackStatus_t* ret_status);
StackStatus_t DestroyStack(Stack_t **stack_obj);
StackStatus_t PushStack(Stack_t *stack_obj, int item);
int PopStack(Stack_t *stack_obj, StackStatus_t* ret_status);
int StackTop(Stack_t *stack_obj, StackStatus_t* ret_status);
StackStatus_t StackCount(Stack_t *stack_obj, unsigned int *Stack_Count);

#endif // STACKARRAYDS_H_INCLUDED
