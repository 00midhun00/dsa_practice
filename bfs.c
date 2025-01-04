#include<stdio.h>
#define max 5


int main(){
    int visited[max]={0};
    int adj[max][max],i,j,start;
    int que[max],rear=-1,front=-1,k,n;
    printf("\n enter th no of vertex");
    scanf("%d",&n);
    printf("\n enter the adj matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&adj[i][j]);
    
    for(k=1;k<=n;k++)
       visited[k]=0;

    printf("\nenter the start vertex:");
    scanf("%d",&start);

    que[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear >= front){  //que is empty
        start =que[front++];
        printf("%c",start+64);

        for(i=1;i<=n;i++){ //add niebours

           if(adj[start][i] && visited[i] == 0){
            que[++rear] =i;
            visited[i]=1;
           }

        }
    }
    
}