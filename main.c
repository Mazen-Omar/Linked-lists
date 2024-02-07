#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* list_Head = NULL;
struct node* list_Head1 = NULL;

int get_length(struct node* list);
void insert_node_at_beginning(struct node** head);
void insert_node_at_end(struct node** list);
void insert_node_after(struct node *list);
void delete_node_at_beginning(struct node** list);
void delete_node(struct node* head);
void display_all_nodes(struct node* list);
int get_Nth_node(struct node* list, int position);
void delete_linked_list(struct node** list);
int find_middle_linkedlist(struct node* list);
int get_Nth_node_end(struct node* list);
void delete_middle(struct node** list);
void Reverse_LinkedList(struct node** head);
void Sort_LinkedList(struct node** head);
void Sort_LinkedList1(struct node** head);
struct node* merge_two_sorted_LinkedList(struct node** head1, struct node** head2);



int main()
{
    int user_choice = 0;
    int ListLength = 0;
    int data_wanted = 0;
    printf("-> Hello to Single Linked List \n");
    while(1)
    {
        printf("\n");
        printf("===============================\n");
        printf("-> 1)  Insert_Node_At_Beginning \n");
        printf("-> 2)  Insert_Node_At_End \n");
        printf("-> 3)  Insert_Node_After \n");
        printf("-> 4)  Delete_Node_At_Beginning \n");
        printf("-> 5)  Delete_Node \n");
        printf("-> 6)  Display_All_Nodes \n");
        printf("-> 7)  Get_Length \n");
        printf("-> 8)  get_Nth_node \n");
        printf("-> 9)  delete_linkedlist \n");
        printf("-> 10) find_middle_linkedlist \n");
        printf("-> 11  delete_middle \n");
        printf("-> 12) get_Nth_node_end\n");
        printf("-> 13) Reverse LinkedList \n");
        printf("-> 14) Sort LinkedList \n");
        printf("-> 15) merge_two_sorted_LinkedList \n");
        printf("-> 16) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("user_choice : ");
        if(scanf("%i", &user_choice) != 1)
        {
            printf("Invalid input, Please try agian.\n");
            getchar();
        }
        else
        {
            switch(user_choice)
            {
            case 1:
                insert_node_at_beginning(&list_Head);
                insert_node_at_beginning(&list_Head1);
                break;
            case 2:
                insert_node_at_end(&list_Head);
                break;
            case 3:
                insert_node_after(list_Head);
                break;
here:
            case 4:
                delete_node_at_beginning(&list_Head);
                break;
            case 5:
                delete_node(list_Head);
                break;
            case 6:
                display_all_nodes(list_Head);
                break;
            case 7:
                ListLength = get_length(list_Head);
                printf("List Length : << %i >> Nodes\n", ListLength);
                break;
            case 8:
                int node_position = 0;
                printf("Enter node you want to get its data : ");
                scanf("%d",&node_position);
                data_wanted = get_Nth_node(list_Head,node_position);
                break;
            case 9:
                delete_linked_list(&list_Head);
                break;
            case 10:
                find_middle_linkedlist(list_Head);
                break;
            case 11:
                delete_middle(&list_Head);
                break;
            case 12:
                get_Nth_node_end(list_Head);
                break;
            case 13:
                Reverse_LinkedList(&list_Head);
                break;
            case 14:
                Sort_LinkedList1(&list_Head);
                break;
            case 15:
                merge_two_sorted_LinkedList(&list_Head,&list_Head1);
                break;
            case 16:
                printf("Quit from application \n");
                exit(1);
                break;
            default:
                printf("User Choice out of range !!\n");
                break;
            }
        }

    }
    return 0;
}

void insert_node_at_beginning(struct node** head)
{
    struct node* temp_node = NULL;
    temp_node = (struct node*)malloc(sizeof(struct node));
    if(temp_node == NULL)
    {
        /** nothing */
    }
    else
    {
        printf("Enter node data : ");
        scanf("%d",&(temp_node->data));
        if(*head == NULL)
        {
            temp_node->link = NULL;
            *head = temp_node;
        }
        else
        {
            temp_node->link = *head;
            *head = temp_node;
        }
    }
}

void insert_node_at_end(struct node** list)
{
    struct node* temp_node = NULL;
    struct node* last_node = NULL;

    if(list == NULL)
    {
        printf("problem\n");
    }
    else
    {
        temp_node = (struct node*)malloc(sizeof(struct node));
        if(temp_node == NULL)
        {
            /** nothing */
        }
        else
        {
            printf("Enter node data : ");
            scanf("%d",&temp_node->data);
            temp_node->link = NULL;

            if(*list == NULL)   /** if the list is empty */
            {
                *list = temp_node;
            }
            /** if the list is not empty */
            else
            {
                /** we need to find the last node */
                last_node = *list;  // assign last node to head

                /** Traversing the list to find the last node */
                while(last_node->link != NULL)
                {
                    last_node = last_node->link;
                }

                last_node->link = temp_node;
            }

        }

    }
}



void insert_node_after(struct node *List)
{
    struct node *TempNode = NULL;
    struct node *NodeListCounter = NULL;
    int NodePosition = 0;    /*  */
    int ListLength = 0;      /*  */
    int NodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &NodePosition);

    ListLength = get_length(List);
    if(NodePosition > ListLength)
    {
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", ListLength);
    }
    else
    {
        NodeListCounter = List;
        while(NodeCounter < NodePosition)
        {
            NodeCounter++;
            NodeListCounter = NodeListCounter->link;
        } /* TempNode points to the node where we have to insert after it */
        TempNode = (struct node *)malloc(sizeof(struct node));
        if(NULL != TempNode)
        {
            printf("Enter Node Data : ");
            scanf("%i", &TempNode->data);
            /* Connect the right side connection */
            TempNode->link = NodeListCounter->link;
            /* Connect the Left side connection */
            NodeListCounter->link = TempNode;
        }
        else
        {
            /* Nothing */
        }
    }
}


int get_length(struct node* list)
{
    struct node* traverser = list;
    unsigned int counter = 0;
    while(traverser != NULL)
    {
        traverser = traverser->link;
        counter++;
    }
    return counter;
}


void delete_node_at_beginning(struct node** list)
{
    if(NULL == list)
    {
        /** nothing */
    }
    else
    {
        if(*list == NULL)
        {
            printf("The list is empty! \n");
        }
        else
        {
            struct node* temp_node = *list;
            *list = temp_node->link;
            temp_node->link = NULL;
            free(temp_node);
        }

    }
}

void delete_node(struct node* head)
{
    struct node* traverser = head;
    struct node* next_node = head;
    unsigned int node_position = 0, list_length = 0;
    printf("Enter node position : ");
    scanf("%d",&node_position);
    list_length = get_length(head);

    if(list_length == 1)
    {
        printf("You should use delete_node_at_beginning function \n");
    }
    else if(node_position > list_length)
    {
        printf("node position is greater than list length !! \n");
    }
    else
    {
        if(head == NULL)
        {
            printf("The list is empty! \n");
        }
        else
        {
            if(node_position == 1) // Deleting the first node
            {
                printf("please use function delete_node_at_beginning \n");
            }
            else
            {
                unsigned int node_counter = 1;
                while(node_counter < (node_position - 1))
                {
                    traverser = traverser->link;
                    node_counter++;
                }
                next_node = traverser->link; // now next_node points to the node that will be deleted.
                traverser->link = next_node->link;
                next_node->link = NULL;
                free(next_node); //because this node is deleted now.
            }
        }
    }
}


void display_all_nodes(struct node *list)
{
    struct node *temp_node = list;
    unsigned int counter = 1;

    if (NULL == temp_node)
    {
        printf("List is empty !! \n");
    }
    else
    {
        while (temp_node != NULL)
        {
            printf("Node <<%i>> = %d \n",counter,temp_node->data);
            temp_node = temp_node->link;
            counter++;
        }
    }
}


int get_Nth_node(struct node* list, int position)
{
    struct node* temp_node = NULL;
    unsigned int list_length, node_counter = 1;

    if(list == NULL)
    {
        /** nothing */
        printf("List is empty !! \n");
    }
    else
    {
        list_length = get_length(list);
        if(position > list_length)
        {
            printf("Invalid position\n");
        }
        else
        {
            temp_node = list;
            while(node_counter < position)
            {
                node_counter++;
                temp_node = temp_node->link;
            }
            printf("Node <<%i>> = %d \n",node_counter,temp_node->data);
        }
    }
}

/*void sort_list(struct node** list)
{
    struct node* temp_node = NULL;
    int max = *list->data;
    if(NULL == list)
    {

    }
    else
    {
        if(*list == NULL)
        {
            printf("The list is empty !! \n");
        }
        else
        {
            temp_node = *list;
            while(temp_node->link != NULL)
            {
                if()
                temp_node = temp_node->link;
            }

        }
    }
}*/

void delete_linked_list(struct node** list)
{
    /*
    unsigned int list_length = 0;
    list_length = get_length(*list);

    while(list_length--)
    {
        delete_node_at_beginning(list);
    }*/
    struct node* temp_node = NULL;
    struct node* next_node = *list;

    if(list == NULL)
    {

    }
    else
    {
        if(*list == NULL)
        {
            free(*list);
            free(list);
        }
        else
        {
            temp_node = *list;
            while(temp_node != NULL)
            {
                temp_node = temp_node->link;
                next_node->link = NULL;
                free(next_node);
                next_node = temp_node;
            }
            *list = NULL;
        }
    }
    printf("The list has been deleted successfully \n");
}

int find_middle_linkedlist(struct node* list)
{
    struct node* temp_node = NULL;
    unsigned int list_length = get_length(list), counter = 0;
    unsigned middle = list_length / 2;

    if(list == NULL)
    {
        printf("The list is empty !! \n");
    }
    else
    {
        temp_node = list;
        if(list_length % 2 == 0)
        {
            while(counter < middle + 1)
            {
                temp_node = temp_node->link;
                counter++;
            }
            printf("Middle node data = %d \n",temp_node->data);
        }
        else
        {
            while(counter < middle)
            {
                temp_node = temp_node->link;
                counter++;
            }
            printf("Middle node data = %d \n",temp_node->data);
        }
    }
    return temp_node->data;
}

int get_Nth_node_end(struct node* list)
{
    struct node* last_node = NULL;
    if(list == NULL)
    {
        printf("The list is empty !! \n");
    }
    else
    {
        unsigned int position_end = 0,
                     list_length = get_length(list),
                     counter = list_length;

        printf("Enter position of node data you want from the end : ");
        scanf("%d",&position_end);
        last_node = list;
        while(counter > position_end)
        {
            last_node = last_node->link;
            counter--;
        }
        printf("Node data = %d \n",last_node->data);

    }
    return last_node->data;
}

void delete_middle(struct node** list)
{
    if(*list == NULL)
    {
        printf("The list is empty !! \n");
    }
    else
    {
        int length = get_length(*list);
        int counter = 1;
        if(length == 1)
        {
            (*list)->link = NULL;
            *list = NULL;
        }
        else if(length % 2 == 0)
        {
            /** EVEN */
            struct node* temp_node = NULL;
            int middle1 = length / 2;
            struct node* traverser = *list;
            struct node* next_node = NULL;
            while(counter < middle1)
            {
                traverser = traverser->link;
                counter++;
            }
            temp_node = traverser->link;
            next_node = temp_node->link;
            traverser->link = next_node;
            temp_node->link = NULL;
            free(temp_node);
            temp_node = NULL;


        }
        else
        {
            /** ODD */
            struct node* temp_node = NULL;
            struct node* next_node = NULL;
            int middle2 = (length / 2);
            struct node* traverser = *list;
            while(counter < middle2)
            {
                traverser = traverser->link;
                counter++;
            }
            temp_node = traverser->link;
            next_node = temp_node->link;
            traverser->link = next_node;
            temp_node->link = NULL;
            free(temp_node);
            temp_node = NULL;

        }

    }
}


void Reverse_LinkedList(struct node** head)
{
    if(head == NULL)
    {
        printf("problem\n");
    }
    else
    {
        if((*head) == NULL)
        {
            printf("The list is empty !! \n");
        }
        else
        {
            struct node* current = *head;
            struct node* next = NULL;
            struct node* prev = NULL;

            while(current != NULL)
            {
                next = current->link;
                current->link = prev;
                prev = current;
                current = next;
            }
            *head = prev;
        }

    }

}
/*
void Sort_LinkedList(struct node** head)
{
    if(head == NULL)
    {
        printf("problem\n");
    }
    else
    {
        if(*head == NULL)
        {
            printf("The list is empty !! \n");
        }
        else
        {
            int i = 0 ,j ,k = 0;
            int key = 0;
            int len = (get_length(*head));
            struct node* traverser = (*head);
            struct node* temp = NULL;
            int* arr;
            arr = (int *)malloc(sizeof(int) *len);
            while(traverser != NULL)
            {
                arr[i] = traverser->data;
                traverser = traverser->link;
                i++;
            }

            for(j = 1; j < len; j++)
            {
                k = j - 1;
                key = arr[j];

                while((key < arr[k]) && (k >= 0))
                {
                    arr[k+1] = arr[k];
                    k--;
                }
                arr[k+1] = key;
            }

            i = 0;
            traverser = (*head);
            while(traverser != NULL)
            {
                traverser->data = arr[i];
                traverser = traverser->link;
                i++;
            }
        }

    }

}
*/

void Sort_LinkedList1(struct node** head)
{
    if(head == NULL)
    {
        printf("problem\n");
    }
    else
    {
        if(*head == NULL)
        {
            printf("The list is empty !! \n");
        }
        else
        {
            int temp;
            struct node * i = NULL;
            struct node * j = NULL;

            for(i = (*head); i->link != NULL; i = i->link)
            {
                for(j = i->link; j != NULL; j = j->link)
                {
                    if(i->data > j->data)
                    {
                        /** swapping */
                        temp = j->data;
                        j->data = i->data;
                        i->data = temp;
                    }
                }
            }
        }

    }

}

/*struct node* merge_two_sorted_LinkedList(struct node** head1, struct node** head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        printf("problem\n");
    }
    else
    {
        if(*head1 == NULL || *head2 == NULL)
        {
            printf("One of the LinkedLists is empty !! \n");
        }
        else
        {
            struct node* new_head = NULL;
            new_head = (struct node*)malloc(sizeof(struct node));
            if(new_head == NULL)
            {
                printf("Failed to malloc the new_head \n");
            }
            else
            {
                if((*head1)->data >= (*head2)->data)
                {
                    new_head = (*head1);
                }
                else
                {
                    new_head = (*head2);
                }

                struct node* traveser1 = (*head1);
                struct node* traveser2 = (*head2);
                struct node* temp1 = NULL;

                while(traveser1->link != NULL)
                {
                    traveser1 = traveser1->link;
                }
                traveser1->link = (*head2);
                Sort_LinkedList1(&new_head);

                return new_head;
            }
        }
    }



}*/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
   if(list1 == NULL)
   {
       return list2;
   }
   else if(list2 == NULL)
   {
       return list1;
   }
    else
    {
        struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(list1->val > list2->val)
        {
            head = list2;
        }
        else
        {
            head = list1;
        }

        struct ListNode* temp = head;

       while(list1 != NULL && list2 != NULl)
       {
           if(list1->val <= list2->val)
           {
               temp = list1;
               temp->next = list2;
               list1 = list1->next;
           }
           else
           {
               temp = list2;
               temp->next = list1;
               list2 = list2->next;
           }
       }

    }
}

