#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;};
    void display(struct Node * temp ){
       int count = 0;
        while(temp!=NULL){
            printf("-<%d>-",temp->data);
            temp=temp->next;
            count++;
        } 

        printf("\nTotal nodes: %d\n", count);
    }
    struct Node* insertionstart(struct Node *head,int data){
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=data;
        temp->next=head;
       return temp;
    }
    struct Node*insertionmid(struct Node *head,int data,int pos){
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=data;
        struct Node *p=head;
        int i=0;
        while(i!=pos-1){
            p=p->next;
            i++;
        }
        temp->next=p->next;
        p->next=temp;
        return head;
    }
    struct Node* insertionend(struct Node *head,int data){
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=data;
        struct Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->next=NULL;
        return head;
    }
    struct Node* deletionstart(struct Node *head){
        struct Node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct Node* deletionend(struct Node *head){
        struct Node *p=head;
        struct Node *q=head->next;
        while(q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        free(q);
        return head;
    }
    struct NOde* deletionByIndex(struct Node *head,int index){
        struct Node *p=head;
        struct Node *q=head->next;
        int i=0;
        while(i!=index-1){
            p=p->next;
            q=q->next;
            i++;
        }
        p->next=q->next;
        free(q);
        return head;
    }
    struct Node* deletionByValue(struct Node *head,int value){
        struct Node *p=head;
        struct Node *q=head->next;
        while(q->data!=value && q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        if(q->data==value){
            p->next=q->next;
            free(q);
        }
        return head;
    }
    struct Node* Search(struct Node *head,int value){
        struct Node *p=head;
        while(p!=NULL){
            if(p->data==value){
                return p;
            }
            p=p->next;
        }
        return NULL;
    }
  struct Node* reverse(struct Node *head){
        struct Node *prev=NULL;
        struct Node *current=head;
        struct Node *next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
        return head;
    }

    int main() {
        struct Node *head = NULL;
        struct Node *second = NULL;
        struct Node *third = NULL;
        head = (struct Node*)malloc(sizeof(struct Node));
        second = (struct Node*)malloc(sizeof(struct Node));
        third = (struct Node*)malloc(sizeof(struct Node));
        head->data = 1;
        head->next = second;
        second->data = 2;
        second->next = third;
        third->data = 3;
        third->next = NULL;
        display(head);
        head = insertionstart(head, 0);
        display(head);
        head = insertionmid(head, 5, 2);
        display(head);
        head = insertionend(head, 4);
        display(head);
        head = deletionstart(head);
        display(head);
        head = deletionend(head);
        display(head);
        head = deletionByIndex(head, 1);
        display(head);
        head = deletionByValue(head, 2);
        display(head);
        struct Node *foundNode = Search(head, 3);
        if (foundNode != NULL) {
            printf("Node with value 3 found: %d\n", foundNode->data);
        } else {
            printf("Node with value 3 not found.\n");
        }
        head = reverse(head);
        display(head);
    }