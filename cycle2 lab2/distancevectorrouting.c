#include<stdio.h>
#define inf 999
struct routing{
    int dist[10];
    int hop[10];
};
struct routing nodes[10];

void init(int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            if(i!=j){
                nodes[i].dist[j] = inf;
                nodes[i].hop[j] = -20;
            }
            else{
                nodes[i].dist[j] = 0;
                nodes[i].hop[j] = -20;
            }

        }
    }
}

void update(int i,int j,int k){
    nodes[i].hop[j] = k;
    nodes[i].dist[j] = nodes[i].dist[k] + nodes[k].dist[j];
}

void dvr(int n){
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        for(k=0;k<n;k++)
        if(nodes[i].dist[j]>(nodes[i].dist[k] + nodes[k].dist[j]))
        update(i,j,k);
}

int main(){
    int i, j, n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    init(n);
    printf("Enter the distance vector\n");
    for(i=0;i<n;i++){
            printf("Enter for node %d\n",i);
        for(j=0;j<n;j++){
            scanf("%d",&nodes[i].dist[j]);
        }
    }
    dvr(n);
    printf("\nUpdated distance vector table\n");
    for(i=0;i<n;i++){
        printf("Updated node %c table\n",65+i);
        printf("To\t cost\t hop\n");
        for(j=0;j<n;j++){
            printf("%c\t %d\t %c\n",65+j,nodes[i].dist[j], 65+nodes[i].hop[j]);
        }
    }

    return 0;
}