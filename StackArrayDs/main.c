#include <stdio.h>
#include <stdlib.h>
#include "StackArrayDs.h"

unsigned int Stack1_Count = 0;
Stack_t *Stack1 = NULL;
int StackRetVal;

int main()
{
    StackStatus_t stack1_status = STACK_NOK;
    Stack1 = CreateStack(&stack1_status);

    for(int i=0; i<Stack1->StackMaxSize; i++){
        stack1_status = PushStack(Stack1, 11*(i+1)); printf("=> %i \n", stack1_status);
    }
    stack1_status = PushStack(Stack1, 66); printf("=> %i \n", stack1_status);

    stack1_status = StackCount(Stack1, &Stack1_Count); printf("=> %i \n", stack1_status);
    printf("Stack1_Count = %i \n", Stack1_Count);

    for(int i=0; i<Stack1->StackMaxSize; i++){
        StackRetVal = StackTop(Stack1, &stack1_status); printf("=> %i \n", stack1_status);
        printf("StackTop = %i \n", StackRetVal);

        StackRetVal = PopStack(Stack1, &stack1_status); printf("=> %i \n", stack1_status);
        printf("value = %i \n", StackRetVal);
    }
    StackRetVal = PopStack(Stack1, &stack1_status); printf("=> %i \n", stack1_status);
    printf("value = %i \n", StackRetVal);

    stack1_status = StackCount(Stack1, &Stack1_Count); printf("=> %i \n", stack1_status);
    printf("Stack1_Count = %i \n", Stack1_Count);


    stack1_status = DestroyStack(&Stack1); printf("=> %i \n", stack1_status);

    if(!Stack1){
        printf("stack destroyed\n");
    }

    return 0;
}
