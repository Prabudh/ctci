#include<stdio.h>
typedef struct llNode {
   struct llNode * next;
   int data;
} llNode;

llNode *lList = NULL;

void append(int data)
{
 llNode *temp = (llNode*) (malloc(sizeof(llNode)));
 temp->data = data;
 temp->next = lList;
 lList = temp;
}

void delete(int data)
{
llNode *temp = lList;
llNode *x;
if(temp->data == data)
{
   lList = temp->next;
   free(temp);
   return;
}
while(temp!=NULL && temp->next != NULL)
{
    if(temp->next->data == data)
    {
         x = temp->next;
         temp->next=temp->next->next;
         
         free(x); 
    }
    temp = temp->next;
}

}
void deleteInList(int data, llNode **root)
{
if(*root == NULL)
return;
llNode *x;
llNode *temp = *root;
if(temp->data == data)
{
   *root = temp->next;
   free(temp);
   return;
}
while(temp!=NULL && temp->next != NULL)
{
    if(temp->next->data == data)
    {
         x = temp->next;
         temp->next=temp->next->next;
         free(x);
    }
    temp = temp->next;
}

}
appendToList(llNode **root, int data)
{
    llNode *temp = NULL;
    
    temp = (llNode*) malloc(sizeof(llNode));
    temp->data = data;
    temp->next = *root;
    *root = temp;
}
void display()
{
    llNode * temp = lList;
    while(temp!=NULL)
    {
      printf("%d,", temp->data);
      temp= temp->next;
    }
printf("\n");
}
void createALoopAt(int data)
{
   llNode *temp = lList;
   while(temp->next != NULL)
   {
       temp = temp->next;
   }
   llNode *x = lList;
   while(x->next->data != data)
   {
      x= x->next;
   }
   //create loop
   temp->next = x->next;
}

void findTheLoopStart()
{
   llNode *slow = lList;
   llNode *fast = lList;
   while(slow!=NULL && fast != NULL && fast->next!=NULL)
   {
       slow = slow->next;
       fast = fast->next->next;
       if(fast == slow)
       {
           break;
       }
   }
   llNode *temp = lList;
   while(temp!= NULL)
   {
      temp = temp->next;
      fast = fast->next;
      if(temp == fast)
      {
          printf("start of loop is at %d\n",temp->data);
      }
   }
}

int main()
{
//create linked list
append(1);
append(2);
append(3);
append(4);
append(5);
append(6);
append(7);
append(8);
append(9);
append(10);
append(11);
display();
int pivot = 5;
llNode *l1 = NULL;
llNode *l2 = NULL;
llNode *l3 = NULL;
while(lList!=NULL)
{
   if(lList->data< pivot)
   {
      appendToList(&l1,lList->data);
      delete(lList->data);
   }
   else if(lList->data > pivot)
   {
      appendToList(&l2,lList->data);
      delete(lList->data);
   } 
   else
   {
      appendToList(&l3, lList->data);
      delete(lList->data);
   }
}
//
while(l2 != NULL)
{
    append(l2->data);
    deleteInList(l2->data, &l2);
}

while(l3!=NULL)
{
    append(l3->data);
    deleteInList(l3->data, &l3);
}

while(l1!=NULL)
{
    append(l1->data);
    deleteInList(l1->data, &l1);
}
display();
createALoopAt(4);
findTheLoopStart();
return 0;
}
