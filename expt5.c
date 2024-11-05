#include<stdio.h>
# define MAX 5
int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x){
    
if((front == 0 && rear == MAX-1) || (front == rear+1)){
printf("Queue Overflow \n");
return;
}

if(front == -1){
front = 0;
rear = 0;
}
else{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue[rear] = x ;
}


void dequeue(){
    
if(front == -1){
printf("Queue Underflow\n");
return ;
}
printf("Element deleted from queue is : %d\n",cqueue[front]);

if(front == rear){
front = -1;
rear=-1;
}
else{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}


void display(){

int front_pos = front, rear_pos = rear;

if(front == -1){
printf("Queue is empty\n");
return;
}

printf("Queue elements :\n");

if( front_pos <= rear_pos )
while(front_pos <= rear_pos){
printf("%d ",cqueue[front_pos]);
front_pos++;
}
else{
    
while(front_pos <= MAX-1){
printf("%d ",cqueue[front_pos]);
front_pos++;
}

front_pos = 0;

while(front_pos <= rear_pos){
printf("%d ",cqueue[front_pos]);
front_pos++;
}
}
printf("\n");
}



int main(){
int b=1;
int choice,x;
while(b==1){
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Quit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice){
case 1 :
printf("Input the element for insertion in queue :\n ");
scanf("%d", &x);
enqueue(x);
break;
case 2 :
dequeue();
break;
case 3:
display();
break;
case 4:
b=0;
break;
default:
printf("Wrong choice\n");
}
}
return 0;
}