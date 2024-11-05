#include<stdio.h>
#include<stdlib.h>

int top=-1;
int max=4;
int arr[4];

void push(){
    int x;
    if(top==max-1){
        printf("Overflow condition\n");
    }
    else{
        printf("Enter elements\n");
        scanf("%d",&x);
        top++;
        arr[top]=x;
    }
}

void pop(){
    int temp;
    if(top==-1){
        printf("Underflow condition\n");
    }
    else{
        temp=arr[top];
        top--;
        printf("Popped element is %d\n",temp);
    }
    
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Elements in the stack are:\n");
        for(int i=top;i>=0;i--){
        printf("%d\n",arr[i]);
    }
        }
}

int main(){
    int b=1;
    while(b==1){
        int a;
        printf("Enter the operation you want to perform\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        scanf("%d",&a);
        switch(a){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            b=0;
            break;
            default:
            printf("Invalid Input\n");
        }
    }
    return 0;
    
}
