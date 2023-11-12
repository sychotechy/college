#include<stdio.h>
int queue[50],front=-1,rear=-1;
void enQueue(int element, int maxSize){
    if((rear+1)%maxSize==front){
        printf("Queue is full");
    }
    else if(front==-1){
        front=rear=0;
        queue[rear]=element;
    }
    else{
        rear=(rear+1)%maxSize;
        queue[rear]=element;
    }
}
void deQueue(int maxSize){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        printf("Deleted element : %d",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%maxSize;
        }
    }
}
void display(int maxSize){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements : ");
        int i=front;
		while(i!=rear)
			{
			printf("%d\t",queue[i]);
			i=(i+1)%maxSize;
			}
		printf("%d\n",queue[rear]);
    }
}
int main(){
    int element,choice,maxSize,flag=1;
    printf("Enter size of circular queue : ");
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
                deQueue(maxSize);
                break;

            case 3:
                display(maxSize);
                break;

            case 4:
                flag=0;
                break;

            default:
                printf("Invalid option\n");
        }
    }while(flag);
}