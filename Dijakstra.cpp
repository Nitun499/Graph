#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define v 9
using namespace std;
void printSolution(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < v; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}
//time complexity -O(n^2);
//can be improved using priority_queue to O(nlogn)
void dijakstra(int graph[][v],int src){
    int dist[v];
    int visited[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX,visited[i]=0;
    }
    dist[src]=0;
    //run a loop for n-1 times
    for(int i=0;i<v-1;i++){
        //find min value vertex
        int min=INT_MAX,u;
        for(int j=0;j<v;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }
        visited[u]=1;
        //update neighbours of mst value
        for(int k=0;k<v;k++){
            if(graph[u][k] && !visited[k] && dist[u]!=INT_MAX){
                if(dist[u]+graph[u][k]<dist[k])
                    dist[k]=dist[u]+graph[u][k];
            }
        }
    }
    printSolution(dist);
}

int main(){
 
    int graph[v][v]={{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
    dijakstra(graph,0);
    return 0;
}