#include <stdio.h>

void main(){
    int queue[100];
    int rear = -1, front = -1;
    int ch, re = 1;
    while(re == 1){
        printf("Enter choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            int val;
            printf("Enter value to be enqueued: ");
            scanf("%d", &val);
            if(rear == 99){
                printf("Queue is full!\n");
            } else if (rear == -1 && front == -1)
            {
                rear = front = 0;
                queue[rear] = val;
            } else {
                rear+=1;
                queue[rear] = val;
            }
            break;
            case 2:
            if(front>rear || front == -1){
                printf("Queue is empty!\n");
            }else{
                printf("Popped element: %d\n", queue[front]);
                front+=1;
                if(front>rear){
                    front = rear = -1;
                }
            }
            break;
            case 3:
            if(front == -1){
                printf("Queue is empty!\n");
            }else{
                printf("Queue elements: \n");
                for(int j=front; j<=rear;j++){
                    printf("| %d ", queue[j]);
                }
                printf("|\n");
            }
            break;
            case 4:
            printf("Exiting.....\n");
            return;
            break;
            default:
            printf("Invalid Operation!");
            break;
        }
        printf("Do you want to continue(1.Yes/2.No)");
        scanf("%d", &re);
    }
}