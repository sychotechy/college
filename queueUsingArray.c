/*
Queue using array
Name :- Sreejith O
Class :- CS3B
Roll no :- 71
*/
#include<stdio.h>
int queue[50],front=-1,rear=-1;
void enQueue(int element,int maxSize){
    if(rear==maxSize-1){
        printf("Queue is full\n");
    }
    else if(front==-1){
        front=rear=0;
        queue[rear]=element;
    }
    else{
        queue[++rear]=element;
    }
}
void deQueue(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted element : %d",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=front+1;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements : \n");
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
int main(){
    int element,choice,maxSize,flag=1;
    printf("Enter size of queue : ");
    scanf("%d",&maxSize);
    do{
        printf("\n** Menu **\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter you option : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert : ");
                scanf("%d",&element);
                enQueue(element,maxSize);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                flag=0;
                break;

            default:
                printf("Invalid option\n");
        }
    }while(flag);
}