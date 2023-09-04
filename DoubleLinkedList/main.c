#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int main()
{
    struct node *ListHead = NULL;
    unsigned int UserChoice = 0, pos1=0, pos2=0;
    unsigned int ListLength = 0;

    printf("-> Hello to Dpuble Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Insert_Node_Before \n");
        printf("-> 5) Delete_Node_At_Beginning \n");
        printf("-> 6) Delete_Node_At_End \n");
        printf("-> 7) Delete_Node \n");
        printf("-> 8) Display_All_Nodes_Forward \n");
        printf("-> 9) Display_All_Nodes_Reverse \n");
        printf("-> 10) Get_Length \n");
        printf("-> 11) ReverseList \n");
        printf("-> 12) Swap2Nodes \n");
        printf("-> 13) SortList \n");
        printf("-> 14) DestroyList \n");
        printf("-> 15) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                InsertNodeAtBeginning(&ListHead);
            break;
            case 2:
                InsertNodeAtEnd(&ListHead);
            break;
            case 3:
                InsertNodeAfter(ListHead);
            break;
            case 4:
                InsertNodeBefore(&ListHead);
            break;
            case 5:
                DeleteNodeAtBeginning(&ListHead);
            break;
            case 6:
                DeleteNodeAtEnd(&ListHead);
            break;
            case 7:
                DeletetNode(ListHead);
            break;
            case 8:
                DisplayListForward(ListHead);
            break;
            case 9:
                DisplayListReverse(ListHead);
            break;
            case 10:
                ListLength = GetLength(ListHead);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
            case 11:
                ReverseList(ListHead);
            break;
            case 12:
                printf("pos1 : ");scanf("%i", &pos1);
                printf("pos2 : ");scanf("%i", &pos2);
                Swap2Nodes(ListHead, pos1, pos2);
            break;
            case 13:
                SortList(ListHead);
            break;
            case 14:
                DestroyList(&ListHead);
            break;
            case 15:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}

