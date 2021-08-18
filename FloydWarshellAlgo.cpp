#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define V 4
#define V 4
#define INF INT_MAX
using namespace std;
void Print(int dist[][V]);
void Floyds(int v[][V])
{
    int dist[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = v[i][j];
        }
    }
    //Include each vertex and update pair wise distance
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF)
                {
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    Print(dist);
   
}
void Print(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)

        {
            if(dist[i][j]==INF){
                cout<<"INF"<<" ";
            }else{
                 cout << dist[i][j] << " ";
            }
           
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    // Print(graph);
    // cout << "After opertation " << endl;
    Floyds(graph);
   
    
    return 0;
}