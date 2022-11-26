#include<stdio.h>
#include<stdlib.h>
 
typedef struct node{
    int data;
    struct node *next;
} node;
 
node * insert_node(node *prevNode, int data){
  //  if(prevNode == NULL){
    //    printf("The given previous node cannot be null\n");
      //  return;
    //}
    node *newNode = (node *)malloc(sizeof(node));
 
    //Allocating data in new node
    newNode->data = data;
    //newNode's next points to what prevNode's next was pointing to
    newNode->next = NULL;
    //prevNode's next points to newNode
    prevNode->next = newNode;

    return prevNode;
}
 
int ll_count(node *ptr){
    
    int count=0;
    while(ptr->next != NULL){
        count++;
        ptr = ptr->next;
    }
 
    return count;
}
 
void display(node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
int main(){
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL; 
    int size = 0, element, choice;
    while(1){
	    size = ll_count(head);
            printf("Enter your choice:\n");
            printf("1->Insert element\n2->Display list\n3->Exit\n");
            scanf("%d", &choice);
            switch(choice){
            
            case 1:if(size == 0){ 
            printf("Enter the element to be added: ");
            scanf("%d", &element);
            head = insert_node(head, element);}

            break;
 
            case 2:
            display(head);
            break;
 
            case 3:printf("Quit\n");
            return 0;
 
            default:
            printf("Incorrect choice");
            }
    }
}
