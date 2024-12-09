#include<stdio.h>
#include<stdlib.h>

typedef struct myLL{
    int data;
    struct myLL* next;
}Node;


Node* create(int x){
    Node* newnode=(Node*) malloc(sizeof(Node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}



Node* insert(Node* head,int x,int position){
    Node* newnode= create(x);

    if(position==1){
        newnode->next=head;
        return newnode;
    }
    Node* temp=head;
    int mover=1;
    while(mover<position-1 && temp!=NULL){
        mover++;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Error...the position is out of bound\n");
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}


Node* deletion(Node* head,int position){
    Node* temp;
    if(position==1){
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    int mover=1;
    temp=head;
    while(mover<position-1 && temp!=NULL){
        mover++;
        temp=temp->next;
    }

    if(!temp || !temp->next){
        printf("The position is out of bound\n");
        return head;
    }
    Node* dlt=temp->next;
    temp->next=dlt->next;
    free(dlt);
    return head;
}


void display(Node* head){
    Node* temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main(){
    Node* head=NULL;
    int flag=1;
    int choice,el,position;

    while(flag){

    printf("Enter 1 to insert :\n");
    printf("Enter 2 to delete :\n");
    printf("Enter 3 to exit :\n");
    scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the position\n");
                scanf("%d",&position);
                printf("Enter the data :\n");
                scanf("%d",&el);
                head=insert(head,el,position);
                display(head);
                break;
            
            case 2:
                printf("Enter the position to be deleted\n");
                scanf("%d",&position);
                head=deletion(head,position);
                display(head);
                break;

            case 3:
                flag=0;
                break;
            
            default:
                printf("Enter a valid choice\n");

        }

    }
    return 0;
}