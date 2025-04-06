#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
//Functino To Create Linked List
struct node *create(int n){
    struct node *head=NULL;
    struct node *temp=NULL;
    for(int i=0;i<n;i++){
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the Data For Node[%d]=",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }else{
            temp->next=newnode;
        }
        temp=newnode;
    }
    return head;
}
//Function To Display Linked List
void display(struct node *head){
    if(head==NULL){
        printf("Linked List is Empty\n");
        return ;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
//Function To Search Particular List
void search(struct node *head){
    if(head==NULL){
        return;
    }
    int key,found=-1;
    struct node *temp=head;
    printf("Enter the Key To be Searched:");
    scanf("%d",&key);
    while(temp!=NULL){
        if(temp->data==key){
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==-1){
        printf("Not Found\n");
    }else{
        printf("Found\n");
    }
}
//Function To linked List
struct node *reverse(struct node *head){
    if(head==NULL){
        return NULL;
    }
    struct node *currentnode=head,*previousnode=NULL,*nextnode=NULL;
    while(currentnode!=NULL){
        nextnode=currentnode->next;
        currentnode->next=previousnode;
        previousnode=currentnode;
        currentnode=nextnode;
    }
    return previousnode;
}
// case: 1 Insertion at Begining of linked List
struct node *insertatfirst(struct node *head){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data To Be insert:");
    scanf("%d",&ptr->data);
    ptr->next=head;
    return ptr;
}
//case:2 Insert At End Of Linked List
struct node *insertatend(struct node *head){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data To be Insert:");
    scanf("%d",&ptr->data);
     ptr->next=NULL;
     if(head==NULL){
         return ptr;
     }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    return head;
}
// case: 3 Insert After a Given Key
struct node *insertafter(struct node *head){
    if(head==NULL){
        return NULL;
    }
    int key;
    printf("Enter the Key:");
    scanf("%d",&key);
    struct node *temp=head;
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp!=NULL){
        struct node *ptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter the Data To be insert:");
        scanf("%d",&ptr->data);
         ptr->next=temp->next;
        temp->next=ptr;
        return head;
    }else{
        printf("Key Not Found\n");
        return head;
    }
}
// case:4 Insert at Given Index
struct node *insertatindex(struct node *head,int n){
    int index;
    printf("Enter the Index:");
    scanf("%d",&index);
    if(index==0){
        head=insertatfirst(head);
    }else if(index==n){
       head= insertatend(head);
    }else if(index>n){
        printf("Invalid Position\n");
        return head;
    }else{
           struct node *temp=head;
        int i=0;
        while(i!=index-1){
            temp=temp->next;
        }
        struct node *ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data To be Insert:");
        scanf("%d",&ptr->data);
        ptr->next=temp->next;
        ptr->next=temp;
        return head;
    }
}
// case 1: Deletion of First Node of Linked List
struct node *deletionatfirst(struct node *head){
    if(head==NULL){
        return NULL;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
// case 2: Deletion of Last Node of Linked List
struct node *deletionatend(struct node *head){
    if(head==NULL){
        return NULL;
    }
    struct node *p=head;
    struct node*q=head->next;
    if(q==NULL){
        free(p);
        return NULL;
    }
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
// case: 3 Deletion of  Given Key
struct node *deletionkey(struct node *head){
    if(head==NULL){
        return NULL;
    }
    int key;
    printf("Enter Key:");
    scanf("%d",&key);
    struct node *p=head;
    if(p->data==key){
        head=head->next;
        free(p);
        return NULL;
    }
    struct node *q=head->next;
    while(q!=NULL && q->data!=key){
        p=p->next;
        q=q->next;
    }
    if(q!=NULL){
        p->next=q->next;
        free(q);
        return head;
    }
    else{
        printf("Key Not found\n");
        return head;
    }
}
// case: 4 Deletion of Given Index
struct node *deletionindex(struct node *head,int n){
    if(head==NULL){
        return NULL;
    }
    int index;
    printf("Enter Index:");
    scanf("%d",&index);
    if(index==0){
        head=deletionatfirst(head);
    }else if(index==n-1)
    {
       head=deletionatend(head);
    }else if(index>=n){
        printf("Invalid Inddex\n");
        return head;
    }
    else{
        struct node *p=head;
        struct node *q=head->next;
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
}
int main(){
    int n;
    printf("Enter the Number of Nodes To be Created:");
    scanf("%d",&n);
    struct node *head=create(n);
    display(head);
    head=deletionindex(head,n);
    display(head);
    return 0;
}