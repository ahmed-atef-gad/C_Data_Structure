#include "singleLinkedList.h"

ListStatus_t InsertNodeAtBeginning(struct node **List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = NULL;

    tempNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == tempNode)
    {
        ret_status = R_NULL_POINTER;
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &tempNode->data);
        if(NULL == *List)
        {
            tempNode->link = NULL;
            *List = tempNode;
        }
        else
        {
            tempNode->link = *List;
            *List = tempNode;
        }
        ret_status = R_OK;
    }
    return ret_status;
}

ListStatus_t InsertNodeAtEnd(struct node **List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = NULL;
    struct node *lastNode = NULL;

    tempNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == tempNode)
    {
        ret_status = R_NULL_POINTER;
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &tempNode->data);
        tempNode->link = NULL;
        if(NULL == *List)
        {
            *List = tempNode;
        }
        else
        {
            lastNode = *List;
            while(lastNode->link != NULL)
            {
                lastNode = lastNode->link;
            }
            lastNode->link = tempNode;
        }
        ret_status = R_OK;
    }
    return ret_status;
}

ListStatus_t InsertNodeAfter(struct node *List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = NULL;
    struct node *chosenNode = List;
    unsigned int nodePosition = 0,listLength = 0, nodeCounter = 1;

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &nodePosition);
    listLength = GetLength(List);
    if((nodePosition > listLength) || (nodePosition < 1))
    {
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", listLength);
    }
    else
    {
        tempNode = (struct node *)malloc(sizeof(struct node));
        if(NULL == tempNode)
        {
            ret_status = R_NULL_POINTER;
        }
        else
        {
            printf("Enter Node Data : ");
            scanf("%i", &tempNode->data);

            while(nodeCounter < nodePosition)
            {
                chosenNode = chosenNode->link;
                nodeCounter++;
            }
            tempNode->link = chosenNode->link;
            chosenNode->link = tempNode;
            ret_status = R_OK;
        }
    }
    return ret_status;
}

ListStatus_t DeleteNodeAtBeginning(struct node **List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = *List;
    unsigned int listLength = 0;

    listLength = GetLength(*List);
    if(listLength == 0)
    {
        printf("List is Empty , nothing to be deleted !! \n");
        ret_status = R_EMPTY;
    }
    else
    {
        *List = tempNode->link;
        tempNode->link = NULL;
        free(tempNode);
        ret_status = R_OK;
    }

    return ret_status;
}

ListStatus_t DeletetNode(struct node *List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = List;
    struct node *chosenNode = List;
    unsigned int nodePosition = 0,listLength = 0, nodeCounter = 1;

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &nodePosition);
    listLength = GetLength(List);
    if((nodePosition > listLength) || (nodePosition <= 1))
    {
        if(nodePosition == 1)
        {
            printf("Please use the Delete_Node_At_Beginning !! \n");
        }
        else
        {
            printf("Invalid Node Position -> List has ( %i ) Nodes \n", listLength);
        }
    }
    else
    {
        while(nodeCounter < nodePosition-1)
        {
            tempNode = tempNode->link;
            nodeCounter++;
        }
        chosenNode = tempNode->link;
        tempNode->link = chosenNode->link;
        chosenNode->link = NULL;
        free(chosenNode);
        ret_status = R_OK;
    }

    return ret_status;
}

ListStatus_t DisplayList(struct node *List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = List;

    if(!List)
    {
        printf("List is Empty , nothing to display !! \n");
        ret_status = R_EMPTY;
    }
    else
    {
        while(tempNode != NULL)
        {
            printf("%i -> ", tempNode->data);
            tempNode = tempNode->link;
        }
        if(NULL == tempNode)
        {
            printf("NULL \n");
        }
        ret_status = R_OK;
    }
    return ret_status;
}

unsigned int GetLength(struct node *List)
{
    struct node *tempNode = List;
    unsigned int counter = 0;
    if(!List)
    {
        printf("ERROOOOR\n");
    }
    else
    {
        while(tempNode!= NULL)
        {
            counter++;
            tempNode = tempNode->link;
        }
    }
    return counter;
}

ListStatus_t ReverseList(struct node *List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *node1 = List;
    struct node *node2 = List;
    unsigned int listLength = 0, temp = 0, tmplength = 0;
    listLength = GetLength(List);

    if (NULL == List)
    {
        ret_status = R_NULL_POINTER;
    }
    else
    {
        while (listLength--)
        {
            tmplength = listLength;
            node1 = List;
            while (tmplength--)
            {
                node2 = node1->link;
                temp = node1->data;
                node1->data = node2->data;
                node2->data = temp;

                node1 = node1->link;
            }
        }

        ret_status = R_OK;
    }
    return ret_status;
}

ListStatus_t Swap2Nodes(struct node *List, unsigned int pos1, unsigned int pos2)
{
    ListStatus_t ret_status = R_NOK;
    struct node *node1 = List;
    struct node *node2 = List;
    unsigned int listLength = 0, temp=0;
    listLength = GetLength(List);

    if ((NULL == List) || (pos1 < 1) || (pos2 < 1) || (pos1 > listLength) || (pos2 > listLength))
    {
        ret_status = R_NULL_POINTER;
    }
    else
    {
        while (--pos1)
        {
            node1 = node1->link;
        }
        while (--pos2)
        {
            node2 = node2->link;
        }
        temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;

        ret_status = R_OK;
    }
    return ret_status;
}

ListStatus_t SortList(struct node *List)
{
    ListStatus_t ret_status = R_NOK;
    unsigned int listLength = 0, temp=0, tmplength = 0;
    struct node *node1 = List;
    struct node *node2 = List;
    listLength = GetLength(List);

    if ((NULL == List))
    {
        ret_status = R_NULL_POINTER;
    }
    else
    {
        while(listLength--)
        {
            tmplength = listLength;
            node1 = List;
            while(tmplength--)
            {
                node2 = node1->link;
                if(node2->data < node1->data)
                {
                    temp = node1->data;
                    node1->data = node2->data;
                    node2->data = temp;
                }
                node1 = node1->link;
            }
        }
        ret_status = R_OK;
    }
    return ret_status;
}

ListStatus_t DestroyList(struct node **List)
{
    ListStatus_t ret_status = R_NOK;
    struct node *tempNode = *List;

    if(!(*List))
    {
        ret_status = R_NULL_POINTER;
    }
    else
    {
        while ((*List)->link)
        {
            tempNode = (*List)->link;
            (*List)->link = NULL;
            free(*List);
            (*List) = tempNode;
        }
        free(*List);
        (*List) = NULL;
        ret_status = R_DESTROYED;
    }
    return ret_status;
}
