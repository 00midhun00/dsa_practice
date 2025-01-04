#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;

};

struct node* createnode(int data){
    struct node *p;  //creating node pointer
    p=(struct node*)malloc(sizeof(struct node)); //allocating memoery in heap
    p->data=data;//setting the data
    p->left=NULL;//settin l and r NULL
    p->right=NULL;
    return p; //returning the created node
}

void insert(struct node *root,int key){
   struct node *prev=NULL;
   while(root!=NULL){
    prev=root;
    if(key==root->data){
        printf("\n connot insert alredy in bst");
        return;
    }else if(key<root->data){
        root=root->left;
    }else{
        root=root->right;
    }
   }
   struct node *new=createnode(key);
   if(key < prev->data){
    prev->left=new;
   }else{
    prev->right=new;
   }

}

struct node* findmin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    printf("%d",root->data);
}

void  inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("\n%d",root->data);
        inorder(root->right);
    }

}

struct node *search(struct node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }else if(key <root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

struct node *inorderpre(struct node *root){
    //inorder predesisor is the node in the left subtrees right most child
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node *delete(struct node *root,int value){
    struct node *ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left ==NULL && root->right == NULL){
        free(root);
        return NULL;
    } 
    //search for the node to be deleted
    if(value < root->data){
        root->left=delete(root->left,value);
    }else if(value >root->data){
        root->right=delete(root->right,value);
    }else{
        //deletion strtegy when the node is found
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=delete(root->left,ipre->data);
        }
        return root;

}


int main(){

    /*
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;

    struct node *p1;
    p1=(struct node*)malloc(sizeof(struct node));
    p1->left=NULL;
    p1->right=NULL;

    struct node *p2;
    p2=(struct node*)malloc(sizeof(struct node));
    p2->left=NULL;
    p2->right=NULL;

    p->left=p1;
    p->right=p2; 
    */
   
   struct node *p=createnode(5);
   struct node *p1=createnode(3);
   struct node *p2=createnode(6);
   struct node *p3=createnode(1);
   struct node *p4=createnode(4);
   p->left=p1;
   p->right=p2;

   p1->left=p3;
   p1->right=p4;

   // insert(p,7);
   //printf("%d",p->right->right->data);
   //findmin(p);
   //inorder(p);
   struct node *n =search(p,10);
   if(n!=NULL){
   printf("\t%d found",n->data);
   }
   else{
      printf("\n element not found");
   }
   inorder(p);
   printf("_");
   delete(p,4);
   printf("\t");
   inorder(p);

   
   
    return 0;
}