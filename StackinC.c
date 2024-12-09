#include<stdio.h>
#include<stdbool.h>

#define max 5

typedef struct mystack{
    int arr[max];
    int top;
}Stack;

void initialize(Stack* s){
    s->top=-1;
}

bool isEmpty(Stack* s){
    return s->top==-1;
}
bool isFull(Stack* s){
    return s->top==max-1;
}

void push(Stack* s,int x){
    if(isFull(s)){
        printf("The stack is full\n");
        return;
    }
    s->top++;
    s->arr[s->top]=x;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("The stack is empty\n");
        return -1;
    }
    int el=s->arr[s->top];
    s->top--;
    return el;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    else{
        return s->arr[s->top];
    }
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    int start=s->top;

    for(int i=start;i>=0;i--){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
    
}


int main() {
    Stack s;
    initialize(&s);

    int choice,value;
    int flag = 1;

    while (flag) {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Full\n");
        printf("6. Check if Stack is Empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                if (isFull(&s)) {
                    printf("Stack is Full\n");
                } else {
                    printf("Stack is not Full\n");
                }
                break;
            case 6:
                if (isEmpty(&s)) {
                    printf("Stack is Empty\n");
                } else {
                    printf("Stack is not Empty\n");
                }
                break;
            case 7:
                flag = 0; 
                break;
            default:
                printf("Invalid choice....Please enter a valid option.\n");
        }
    }

    return 0;
}