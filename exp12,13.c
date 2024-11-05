#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* createNewNode(int data){
    node* newNode = (node*) malloc (sizeof(node));
    if(!newNode){
        printf("Memory error!");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(node** head, int data){
    node* newNode = createNewNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        node *temp = *head;
        temp->prev = newNode;
        newNode->next = temp;
        *head = newNode;
    }
}

void insertAtEnd(node** head, int data){
    node* newNode = createNewNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(node* head){
    while(head!=NULL){
        printf(" %d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    node* head = NULL;
    int ch, re=1, val;
    while(re==1){
        printf("Enter a choice:\n1.Insert At Beginning\n2.Insert At End\n3.Display List\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &val);
            insertAtBeg(&head, val);
            break;
            case 2:
            printf("Enter data to be inserted: ");
            scanf("%d", &val);
            insertAtEnd(&head, val);
            break;
            case 3:
            displayList(head);
            break;
            case 4:
            printf("Exiting....\n");
            return 0;
        }
    }
    return 0;
}