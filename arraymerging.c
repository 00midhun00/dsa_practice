#include<stdio.h>
#include<stdlib.h>
int main(){
   int a[100],b[100];
   int n1,n2,i,j,total,size=0,temp;

   printf("enter the size of two arr:");
   scanf("%d %d",&n1,&n2);
   printf("1st arr:");
   for(i=0;i<n1;i++)
      scanf("%d",&a[i]);

   printf("2nd arr:");
   for(i=0;i<n2;i++)
      scanf("%d",&b[i]);
    //merging  
   total=n1+n2;
   for (i=n1;i<total;i++){
       a[i]=b[size];
       size++;
   }
   //sorting
   for(i=0;i<total;i++){
      for(j=0;j<total-1;j++){
        if(a[j] > a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
      }

   }

   printf("after sorting:");
   for(i=0;i<total;i++){
    printf("%d",a[i]);
   }
}