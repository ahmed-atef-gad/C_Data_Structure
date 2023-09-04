#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct node
{
    unsigned int data;
    struct node *LeftLink;
    struct node *RightLink;
};

typedef enum
{
    R_NOK,
    R_OK,
    R_EMPTY,
    R_NULL_POINTER,
    R_DESTROYED
} ListStatus_t;

ListStatus_t InsertNodeAtBeginning(struct node **List);
ListStatus_t InsertNodeAtEnd(struct node **List);
ListStatus_t InsertNodeAfter(struct node *List);
ListStatus_t InsertNodeBefore(struct node **List);
ListStatus_t DeleteNodeAtBeginning(struct node **List);
ListStatus_t DeleteNodeAtEnd(struct node **List);
ListStatus_t DeletetNode(struct node *List);
ListStatus_t DisplayListForward(struct node *List);
ListStatus_t DisplayListReverse(struct node *List);
unsigned int GetLength(struct node *List);
ListStatus_t ReverseList(struct node *List);
ListStatus_t Swap2Nodes(struct node *List, unsigned int pos1, unsigned int pos2);
ListStatus_t SortList(struct node *List);
ListStatus_t DestroyList(struct node **List);

#endif // DOUBLELINKEDLIST_H_INCLUDED
