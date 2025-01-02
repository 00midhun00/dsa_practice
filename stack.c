#include<stdio.h>
#include<stdlib.h>
int stack[100],i,j,opt=0,top=-1,n;
void push();
void pop();
void show();
void peek();

void push(){
    int val;
    if(top == n){
      printf("\n over flow");
    }else{
        printf("\n enter the value");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }  
}

void pop(){

    if(top==-1){
        printf("\n underflow");
    }else{
        top=top-1;
    }
}

void peek(){
    if(top==-1){
        printf("\n underflow");
    }else{
        printf("stck top element is %d",stack[top]);
    }
}

void show(){
    for(i=top;i>=0;i--){
        printf(" |%d| ",stack[i]);
    }
}

int main(){
    printf("\n enter the no of elements in stack:");
    scanf("%d",&n);
    while(1){
        printf("\nchose an option:");
        printf("\n1)push\n2)pop\n3)peek\n4)show\n5)exit");
        scanf("%d",&opt);
        switch(opt){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:show();
            break;
            case 5:exit(0);
        }
    }
}
