#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}


Node* insertAtBeginning(Node* head,int data) {
    Node* newNode=createNode(data);
    if(head!= NULL) {
        head->prev= newNode;
    }
    newNode->next= head;
    return newNode;  
}


Node* insertAtEnd(Node* head, int data) {
    Node* newNode=createNode(data);
    if(head==NULL) {
        return newNode; 
    }
    
    Node* temp= head;
    while(temp->next!= NULL) {
        temp= temp->next;
    }

    temp->next= newNode;
    newNode->prev= temp;
    return head;
}


Node* insertAtPosition(Node* head, int data, int position) {
    if(position== 1) {
        return insertAtBeginning(head,data);
    }

    Node* newNode= createNode(data);
    Node* temp= head;
    int count= 1;

    while(temp!= NULL && count < position - 1) {
        temp= temp->next;
        count++;
    }

    if(temp== NULL) {
        printf("The position is out of range.\n");
        return head;
    }

    newNode->next= temp->next;
    if(temp->next!= NULL) {
        temp->next->prev = newNode;
    }
    temp->next= newNode;
    newNode->prev= temp;
    return head;
}


Node* deleteAtPosition(Node* head,int position) {
    if(head== NULL) {
        printf("List is empty\n");
        return NULL;
    }

    Node* temp= head;
    int count= 1;

   
    if(position == 1) {
        head = head->next;
        if(head!= NULL) {
            head->prev= NULL;
        }
        free(temp);
        return head;
    }

    while(temp!= NULL && count < position) {
        temp= temp->next;
        count++;
    }

    if(temp== NULL) {
        printf("The position is out of range.\n");
        return head;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}


void displayForward(Node* head) {
    if(head== NULL) {
        printf("The list is empty\n");
        return;
    }
    
    Node* temp= head;
    printf("List Forward ");
    while(temp!= NULL) {
        printf("%d ",temp->data);
        temp= temp->next;
    }
    printf("\n");
}


void displayBackward(Node* head) {
    if(head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp= head;
    while(temp->next != NULL) {
        temp= temp->next;  
    }

    printf("List Backward ");
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp= temp->prev;
    }
    printf("\n");
}

int main() {
    Node* head= NULL;
    int choice,data,position;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;

            case 5:
                displayForward(head);
                break;

            case 6:
                displayBackward(head);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice...Please try again.\n");
        }
    }

    return 0;
}
