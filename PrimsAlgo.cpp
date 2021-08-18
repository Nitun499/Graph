#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define V 5
using namespace std;
void printMST(int parent[], int graph[V][V])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

//time complexity -O(n^2);
//can be improved using priority_queue to O(nlogn)
void PrimsMst(int graph[][V],int src){
    int dist[V];
    int visited[V];
    int parent[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[src]=0;
    parent[src]=-1;
   
    //run a loop for n-1 times
    for(int i=0;i<V-1;i++){
        //find min value vertex
        int min=INT_MAX,u;
        for(int j=0;j<V;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }
        visited[u]=1;
        //update neighbours of mst value
        for(int k=0;k<V;k++){
            if(graph[u][k] && !visited[k] ){
                if(graph[u][k]<dist[k]){
                    dist[k]=graph[u][k];
                    parent[k]=u;
                }
            }
        }
    }
    printMST(parent,graph);
   
}

int main(){
 
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    PrimsMst(graph,0);
    return 0;
}