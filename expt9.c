#include<stdio.h>
#include<string.h>

#define max 100

int top,stack[max];

void push(char x){
    if(top==max-1){
        printf("Stack overflow\n");
    }
    else{
        stack[++top]=x;
    }
}

void pop(){
    printf("%c",stack[top--]);
}

int main(){
    char str[100];
    printf("Enter String to be Reversed:\n");
    scanf("%s",str);
    int len=strlen(str);
    int i;
    for(i=0;i<len;i++){
        push(str[i]);
    }
    for(i=0;i<len;i++){
        pop();
    }
    return 0;
}