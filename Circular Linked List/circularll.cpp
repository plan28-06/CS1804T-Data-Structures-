#include<stdio.h>
#include<iostream>
#include<stdlib.h>


class circularlinkedlist{
    public:
        int count=0;
        struct node {
        int data;
        struct node * next;
        };
        struct node * head;
        struct node * tail;
        circularlinkedlist(){
        head = NULL;
        tail = NULL;
        }
        void insertbeg(int);
        void insertatend(int);
        void display();
        void insertatpos(int , int );
        void deleteatbeg();
        void deleteatend();
        void deleteatpos(int);
        void search(int);
};

int main(){
    circularlinkedlist list1;
    int choice, num,pos;
    while(true){
        system("clear");
        printf("Enter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit\n");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        if (choice ==1){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.insertbeg(num);
        }
        else if (choice == 8){
            list1.display();
        }
        else if (choice == 2){
            printf("Enter number to insert:");
            scanf("%d",&num);
            list1.insertatend(num);
        }
        else if (choice == 9 ){
            exit(1);
        }
        else if (choice == 3){
            printf("Enter number to insert:");
            scanf("%d",&num);
            printf("Enter index to insert at:");
            scanf("%d",&pos);
            list1.insertatpos(num,pos);
        }
        else if (choice == 4){
            list1.deleteatbeg();
        }
        else if (choice == 5){
            list1.deleteatend();
        }
        else if (choice == 6){
            printf("Enter index to delete from:");
            scanf("%d",&pos);
            list1.deleteatpos(pos);
        }
        else if (choice == 7){
            printf("Enter number to search:");
            scanf("%d",&num);
            list1.search(num);
        }
        getchar();
        getchar();
        
    }
    return 0;
}


void circularlinkedlist::insertbeg(int num){
        if (count == 0){
            struct node * newnode = (struct node *) malloc(sizeof(node));
            head = newnode;
            newnode->next = head;
            newnode->data = num;
            count++;
            tail = newnode;
        }
        else{
            struct node * newnode = (struct node *) malloc(sizeof(node));
            newnode->next = head;
            newnode->data = num;
            head = newnode;
            count++;
        }
}

void circularlinkedlist::insertatend(int num){
    if (count ==1){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = num;
        newnode->next = head;
        head->next = newnode;
        tail = newnode;
        count++;
    }

    else if (count == 0){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        head = newnode;
        tail = newnode;
        newnode->data = num;
        newnode->next = head;
        count++;
    }
    else{
    struct node * newnode = (struct node *) malloc(sizeof(node));
    struct node * tempnode = head;
    for (int i =0 ; i < count - 1 ; i++){
        tempnode = tempnode->next;
    }
    newnode->data = num;
    tempnode->next = newnode;
    newnode->next = head;
    tail=newnode;
    count++;
    }
}


void circularlinkedlist::insertatpos(int num , int pos){
    if (pos == 0 ){
        insertbeg(num);
    }
    else if (pos > count){
        printf("Can't insert here");
    }
    if (pos ==1){
        struct node * newnode = (struct node *) malloc(sizeof(node));
        newnode->data = num;
        newnode->next = head->next;
        head->next = newnode;
        if (pos == count){
            tail = newnode;
        }
        count++;
    }
    else{
        struct node * newnode = (struct node *) malloc(sizeof(node));
        struct node * tempnode = head;
        for (int i =0 ; i< pos -1 ; i++){
            tempnode = tempnode->next;
        }
        newnode->next = tempnode->next;
        newnode->data = num;
        if (pos == count){
            tail = newnode;
        }
        tempnode->next = newnode;
        count++;
    }
}

void circularlinkedlist::display(){
    if (count ==0){
        printf("List empty");
    }
    else{
        struct node * tempnode = head;
        for (int i = 0; i<count;i++){
            printf("%d\t", tempnode->data);
            if (tempnode-> next != head){
                tempnode = tempnode-> next;
            }
        }
    }
}

void circularlinkedlist::deleteatbeg(){
    if (count ==0){
        printf("The list is empty\n");
    }
    else if (count ==1){
        int c = head->data;
        head = NULL;
        tail = NULL;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
    else{
        int c = head->data;
        head = head->next;
        tail->next = head;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
}

 void circularlinkedlist::deleteatend(){
    if (count ==0){
        printf("The list is empty\n");
    }
    else if (count ==1){
        int c = head->data;
        count--;
        head = NULL;
        tail = NULL;
        printf("\n Deleted element is %d\n",c);
    }
    else if (count == 2){
        struct node * tempnode = head;
        int c = tempnode -> next -> data;
        tempnode->next = head;
        tail = tempnode;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
    else{
        struct node * tempnode = head;
        for (int i =0; i<count-2;i++){
            tempnode = tempnode->next;
        }
        int c = tempnode->next->data;
        tempnode->next =head;
        tail = tempnode;
        count--;
        printf("\n Deleted element is %d\n",c);
    }
}

void circularlinkedlist::deleteatpos(int pos){
    if (count ==0){
        printf("List is empty");
    }
    else if (pos>count-1){
        printf("Can't Delete here");
    }
    else{
        if (pos == 0){
            deleteatbeg();
        }
        else if (pos ==1){
            struct node * tempnode = head;
            int c = tempnode->next->data;
            if (pos == count -1){
                tempnode->next = head;
                tail = tempnode;
            }
            else{
                tempnode->next = tempnode->next->next;
            }
            count --;
            printf("\n Deleted element is %d\n",c);
        }
        else if (pos == 2){
            struct node * tempnode = head;
            tempnode = tempnode->next;
            int c = tempnode->next->data;
            count--;
            if (pos == count -1){
                tempnode->next = head;
                tail = tempnode;
            }
            else{
                tempnode->next = tempnode->next->next;
            }
            printf("\n Deleted element is %d\n",c);
        }
        else{
            struct node * tempnode = head;
            for (int i =0; i<pos-1;i++){
                tempnode = tempnode->next;
            }
            int c = tempnode->next->data;
            if (pos == count -1){
                tempnode->next = head;
                tail = tempnode;
            }
            else{
                tempnode->next = tempnode->next->next;
            }
            count--;
            printf("\n Deleted element is %d\n",c);
        }
    }
}

void circularlinkedlist::search(int num){
    struct node * tempnode = head;
    int i=0;
    if (count == 0){
        printf("\nList Empty\n");
    }
    else if(count == 1){
        if (tempnode->data == num){
            printf("The number has been found");
        }
        else{
            printf("The number has not been found");
        }
    }
    else{
        do{
            if (tempnode->data == num){
                i = 1;
                break;
            }
            else{
                tempnode = tempnode->next;
                continue;
            }
        } while ((tempnode!=head));
        if (i==1){
            printf("The number has been found");
        }
        else{
            printf("The number has not been found");
        }
    }
}