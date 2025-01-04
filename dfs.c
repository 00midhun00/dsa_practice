#include<stdio.h>
#define max 7


int main(){
    int stack[max],visited[max];
    int top=-1,i,k,j,start,n;
    int adj[max][max];
    printf("\n enter th no of vertex");
    scanf("%d",&n);
    for(k=1;k<=n;k++){
        visited[k]=0;
    }
    printf("\n enter the adj matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&adj[i][j]);

    printf("\n enter the start vertex:");
    scanf("%d",&start);
    stack[++top]=start;
    visited[start]=1;

    while(top !=-1){ //stack empty

      start=stack[top--];
      printf("%c-",start +64);

      for(i=1;i<=n;i++){  //adding niebores
        if(adj[start][i] && visited[i] ==0){
            stack[++top]=i;
            visited[i]=1;
            break;
        }
      }

    }
}
