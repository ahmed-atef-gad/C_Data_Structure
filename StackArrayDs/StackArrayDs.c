#include "StackArrayDs.h"


static char StackIsFull(Stack_t *stack_obj)
{
    return (stack_obj->ElementCount == stack_obj->StackMaxSize);
}

static char StackIsEmpty(Stack_t *stack_obj)
{
    return (stack_obj->ElementCount == 0);
}

Stack_t* CreateStack(StackStatus_t* ret_status)
{
    Stack_t *my_stack = NULL;
    if(NULL == ret_status)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        my_stack = (Stack_t *)malloc(sizeof(Stack_t));
        if(!my_stack)
        {
            *ret_status = STACK_NOK;
            my_stack = NULL;
        }
        else
        {
            printf("Enter number of stack elements : ");
            scanf("%i", &(my_stack->StackMaxSize));
            my_stack->ElementCount = 0;
            my_stack->StackTop = -1;
            my_stack->data = (int *)calloc(my_stack->StackMaxSize, sizeof(int));
            if(!my_stack->data)
            {
                free(my_stack);
                my_stack = NULL;
                *ret_status = STACK_NOK;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }
    return my_stack;
}

StackStatus_t DestroyStack(Stack_t **stack_obj)
{
    StackStatus_t ret_status = STACK_NOK;
    if(*stack_obj == NULL)
    {
        ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free((*stack_obj)->data);
        free((*stack_obj));
        *stack_obj = NULL;
        ret_status = STACK_DESTROYED;
    }
    return ret_status;
}

StackStatus_t PushStack(Stack_t *stack_obj, int item)
{
    StackStatus_t ret_status = STACK_NOK;
    if(stack_obj == NULL)
    {
        ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if(StackIsFull(stack_obj))
        {
            ret_status = STACK_FULL;
        }
        else
        {
            (stack_obj->StackTop)++;
            stack_obj->data[stack_obj->StackTop] = item;
            (stack_obj->ElementCount)++;
            ret_status = STACK_OK;
        }
    }
    return ret_status;
}

int PopStack(Stack_t *stack_obj, StackStatus_t* ret_status)
{
    int element = -1;
    if(NULL == stack_obj || ret_status == NULL)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
        }
        else
        {
            element = stack_obj->data[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementCount)--;
            *ret_status = STACK_OK;
        }
    }
    return element;
}

int StackTop(Stack_t *stack_obj, StackStatus_t* ret_status)
{
    int element = -1;
    if(NULL == stack_obj || ret_status == NULL)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
        }
        else
        {
            element = stack_obj->data[stack_obj->StackTop];
            *ret_status = STACK_OK;
        }
    }
    return element;
}

StackStatus_t StackCount(Stack_t *stack_obj, unsigned int *Stack_Count)
{
    StackStatus_t ret_status = STACK_NOK;
    if(NULL == stack_obj || Stack_Count == NULL)
    {
        ret_status = STACK_NULL_POINTER;
    }
    else
    {
        *Stack_Count = stack_obj->ElementCount;
        ret_status = STACK_OK;
    }
    return ret_status;
}
