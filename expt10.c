#include<stdio.h>
#include<stdlib.h>

int top=-1;
char stack[100];

void push(int x){
    top=top+1;
    stack[top]=x;
}

void pop(){
    while(top!=-1){
        printf("%d",stack[top]);
        top=top-1;
    }
}

int main(){
    int dec,rem;
    printf("Enter Decimal Number:\n");
    scanf("%d",&dec);
    int num=dec;
    while(dec!=0){
        rem=dec%2;
        push(rem);
        dec=dec/2;
    }
    printf("Binary Conversion of %d is:\n",num);
    pop();
    return 0;
}