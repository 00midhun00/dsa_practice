#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,ne=1,n;
int min,mincost=0,adj[25][25],parent[25];
int find(int i){
    while(parent[i]){
      i=parent[i];
      }
      return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}


void main(){
    printf("\n enter the no of vertices:");
    scanf("%d",&n);
    printf("\nenter the cost adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j] == 0){
                adj[i][j]=999;
            }
        }
    }

    printf("\n the edges of minimum cost spanning tree are:\n");
    while(ne < n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(adj[i][j] < min){
                    min=adj[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("\n %d edge (%d,%d) \n",ne++,a,b,min);
            mincost +=min;
        }
        adj[a][b]=adj[b][a]=999;
    }
    printf("\n minimum cost=%d\n ",mincost);
}