#include<stdio.h>
#include<stdlib.h>
int a[100],len=0,i;
void create(){
    int i;
    printf("enter the length of array:");
    scanf("%d",&len);
    printf("enter array:");
    for(i=0;i<len;i++){
       scanf("%d",&a[i]);
    
    }
}

void insert(){
   int i,pos,data;
   printf("enter the position you want to insert:");
   scanf("%d",&pos);
   for(i=len;i>=pos;i--){
      a[i]=a[i-1];
   }
      printf("enter the new data");
      scanf("%d",&data);
      a[pos-1]=data;
      len++;
      printf("new arr:");
      for(i=0;i<len;i++){
      printf("%d",a[i]);
      printf("\n");
      }


}


void delete(){
   int pos;
   printf("enter the position u want tot delete:");
   scanf("%d",&pos);
   for(i=pos-1;i<=len;i++){
      a[i]=a[i+1];
   }
      len--;
      printf("new array is:");
      for(i=0;i<len;i++){
         printf("%d",a[i]);
         printf("\n");
      
      }
   }


void view(){
    for(i=0;i<len;i++){
       printf("%d",a[i]);
    
    }


}

int main(){
    int opt;
    
    while(1){
      printf("1)create\n2)insert\n3)delete\n4)view\n5)exit\n");
    scanf("%d",&opt);
        switch(opt){
           case 1:create();
                  break;
           case 2:insert();
                  break;
           case 3:delete();
                  break;
           case 4:view();
                 break;
           case 5:exit(0);
                 break;
           default:printf("invalid option :");
        
        
        }
    
    
    }

}
