#include<stdio.h>

#define size 10

typedef struct myQueue{
    int arr[size];
    int front;
    int rear;
    int cntsize;
}myqueue;

void initialize(myqueue* q){
    q->front=-1;
    q->rear=-1;
    q->cntsize=0;
    return;
}


void enqueue(myqueue* q,int x){
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->rear++;
        q->arr[q->rear]=x;
        q->cntsize++;
        return;
    }
    else if(q->cntsize==size){
        printf("The queue is full\n");
        return;
    }
    q->rear=(q->rear+1)%size;
    q->arr[q->rear]=x;
    q->cntsize++;
}

int dequeue(myqueue* q){
    int el;
    if(q->cntsize==0){
        return -1;
    }
    else if(q->cntsize==1){
        el=q->arr[q->front];
        q->front=-1;
        q->rear=-1;
        q->cntsize--;
        return el;
    }
    el=q->arr[q->front];
    q->front=(q->front+1)%size;
    q->cntsize--;
    return el;
}

void display(myqueue* q){
    if(q->cntsize==0){
        printf("The queue is empty \n");
        return;
    }
    int n=q->cntsize;
    int start=q->front;
    for(int i=0;i<n;i++){
        printf("%d ",q->arr[start]);
        start=(start+1)%size;
    }
    printf("\n");
}

int main(){
    myqueue q;
    initialize(&q);
    int choice,el;
    int flag=1;
    while(flag){
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to Exit\n");
        printf("Enter choice\n");
        scanf("%d",&choice);

       switch(choice){
        case 1:
            printf("Enter the number :\n");
            scanf("%d",&el);
            enqueue(&q,el);
            break;

       case 2:

            el=dequeue(&q);
            if(el!=-1){
                printf("The top element in the queue is %d \n",el);
            }
            else printf("The queue is empty\n");
            break;

        case 3:
            display(&q);
            break;

        case 4:
            flag=0;
            break;
        default:
            printf("Enter a valid option\n");
        }
    }
    return 0;
}