/*Write a menu driven program to implement a singly linked list in C. 
Include the following operations: Add at beginning, search , Display, exit*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
   struct Node *new_node = (struct Node*) malloc (sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = *head_ref;
   *head_ref = new_node;
}

void print_ll(struct Node *head)
{
   
   while(head->next != NULL)
   {
      printf("%d", head->data);
      head = head->next;
      if(head->next == NULL)
      {
         printf("%d", head->data);
      }
   }
}

void find_in_ll(struct Node *head,int s_data)
{
   int n = 1;
   while(head->data != s_data)
   {
      if(head->data == s_data)
      {
         printf("Exists at node %d", n);
      }
            if(head->data != s_data)
      {
         printf("Doesn't Exist");
      }
      head = head->next;
      n++;
   }
}

int main()
{
   int n;
   struct Node *head = NULL;
   while(1)
   {
      int new_data, s_data;
      printf("Enter your Selection: \n\t1. Add at beginning\n\t2. Search\n\t3. Display\n>>> ");
      scanf("%d", &n);
      switch(n)
      {
         case 1:
            printf("Enter your data: ");
            scanf("%d", &new_data);
            push(&head, new_data);
            break;
         
         case 2:
            scanf("%d", &s_data);
            find_in_ll(head, s_data);
            break;

         case 3:
            print_ll(head);
         
            break;
      }
   }
   return 0;
}