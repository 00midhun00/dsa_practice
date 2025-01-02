#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
};
typedef struct node node;
node *head;

void bigininsert(){
      node *ptr;
      int item;
      ptr=(node*)malloc(sizeof(node));
      if(ptr==NULL){
        printf("\n overflow");
      }else{
        printf("\nenter the value:");
        scanf("%d",&item);
        //core idea for bigin insert
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n node inserted!");
      }

}

void endinsert(){
    node *ptr,*tmp;
    int item;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("\n overflow");
    }else{
        printf("\n enter the value:");
        scanf("%d",&item);
        ptr->data=item;

        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
            printf("node inserted!");
        }else{
            //main logic
            tmp=head;
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=ptr;
            ptr->next=NULL;
            printf("\n node inserted:");
        }
    }

}

void posinsert(){
    int i,loc,item;
    node *ptr,*tmp;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("\n over flow. ");
    }else{
        printf("\nenter the value:");
        scanf("%d",&item);
        ptr->data=item;
        printf("\n enter the loc:");
        scanf("%d",&loc);
        tmp=head;
        //core idea
        for(i=0;i<loc;i++){
            tmp=tmp->next;
            if(tmp == NULL){
                printf("\n cant insert");
            }
        }
        ptr->next=tmp->next;
        tmp->next=ptr;
        printf("\n node inserted!");


    }

} 

void bigindelete(){
    node *ptr;
    if(head==NULL){
        printf("\nlist is empty");
    }else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\n node deleted fron biginning!");
    }
}

void enddelete(){
    node *ptr1,*ptr;
    if(head == NULL){
        printf("\n list is empty");
    }else if(head->next==NULL){
        head=NULL;
        free(head);
        printf("\n the only node is deleted");
    }else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\n deleted!");

    }
}

void posdelete(){
    node *ptr1,*ptr;
    int loc,i;
    printf("\n enter the location:");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++){
        ptr1=ptr;
        ptr=ptr->next;
        if(ptr==NULL){
            printf("\n cant delete");
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
    printf("node deleted at %d",loc);
}

void search(){
    node *ptr;
    int item,i=0,flag;
    ptr=head;
    if(ptr==NULL){
        printf("\n empty list");
    }else{
        printf("\n enter an item u want o search:");
        scanf("%d",&item);
        while(ptr!=NULL){
            if(ptr->data == item){
                printf("\nitem found at %d",i);
                flag=0;
            }else{
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag=1){
            printf("\n item not found:");
        }
    }

}

void display(){
    node *ptr;
    ptr=head;
    if(ptr==NULL){
      printf("\n nothing to print:");
    }else{
          while(ptr!=NULL){
            printf("-%d",ptr->data);
            ptr=ptr->next;
        }
    }
}

int main(){
    
    int choice=0;
    while(1){
        printf("\n main menu..................\n");
        printf("1)bigininsert\n2)display\n3)endinsert\n4)posinsert\n5)bigindelete\n6)enddelete\n7)posdelete\n8)search\n9)exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:bigininsert();
            break;
            case 2:display();
            break;
            case 3:endinsert();
            break;
            case 4:posinsert();
            break;
            case 5:bigindelete();
            break;
            case 6:enddelete();
            break;
            case 7:posdelete();
            break;
            case 8:search();
            break;
            case 9:exit(0);
            
        }
    }
    return 0;
}

