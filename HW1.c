/*Write a menu driven program to implement a singly linked list in C. 
Include the following operations: Add at beginning, search , Display, exit*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
   
   while(head != NULL)
   {
      printf("%d", head->data);
      head = head->next;
   }
   printf("\n");
}

bool search(struct Node* head, int x) 
{  
    while (head != NULL) 
    { 
        if (head->data == x) 
            return true; 
       head = head->next; 
    } 
    return false; 
} 

int main()
{
   int n;
   struct Node *head = NULL;
   while(1)
   {
      int new_data, s_data;
      printf("Enter your Selection: \n\t1. Add at beginning\n\t2. Search\n\t3. Display\n\t4. Exit\n>>> ");
      scanf("%d", &n);
      switch(n)
      {
         case 1:
            printf("Enter your data: ");
            scanf("%d", &new_data);
            push(&head, new_data);
            break;
         
         case 2:
            printf("Enter your search: ");
            scanf("%d", &s_data);
            search(head, s_data)? printf("Yes \n") : printf("No \n");
            break;

         case 3:
            print_ll(head);
         
            break;
         case 4:
            return 0;
            break;
      }
   }
   return 0;
}