#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* createNewNode(int data){
    node* newNode = (node*) malloc(sizeof(node));
    if(!newNode){
        printf("Memory error!");
        return NULL;
    } 
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void inserAtBeg(node** head, int data){
    node* newNode = createNewNode(data);
    if(*head==NULL){
        *head = newNode;
    }else{
        newNode->next=*head;
        *head = newNode;
    }
}

void insertAtEnd(node** head, int data){
    node* newNode = createNewNode(data);
    if(*head==NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==data){
            if(prev!=NULL){
                prev->next=temp->next;
            }else{
                *head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void display(node* head){
    while(head!=NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    node* head = NULL;
    int ch, re=1, val;
    while(re==1){
        printf("Enter a choice:\n1.Insert At Beginning\n2.Insert At End\n3.Delete A Node\n4.Display List\n5.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &val);
            inserAtBeg(&head, val);
            break;
            case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &val);
            insertAtEnd(&head, val);
            break;
            case 3:
            printf("Enter the data to be deleted: ");
            scanf("%d", &val);
            deleteNode(&head, val);
            break;
            case 4:
            display(head);
            break;
            case 5:
            printf("Exiting.....");
            return 0;
            break;
            default:
            printf("Invalid Choice!");
            break;
        }
        printf("Do you want to Continue?(1.Yes/2.No)");
        scanf("%d", &re);
    }
    return 0;
}