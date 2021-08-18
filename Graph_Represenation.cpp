#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
class Graph
{
    int V;
   
    vector<int> *visited;

public:
    vector<int> *v;
    Graph(int V)
    {
        this->V = V;
        v = new vector<int>[V];
        visited = new vector<int>(V,0);
    }
    //Directed graph
    void addEdge(int first, int second)
    {
        v[first].push_back(second);
        // v[second].push_back(first);
    }
    void PrintGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Adjacent vertexes to vertex " << i << "->";
            for (auto &it : v[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    //BFS util function
    void BFS(int s)
    {
        vector<int> visited(V, 0);
        queue<int> q;
        visited[s] = 1;
        q.push(s);
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (auto it : v[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    //DFS util function
    void DFSutil(int s,vector<int> & v,vector<int> adj[]){
        v[s]=1;
        cout<<s<<" ";
        for(auto it :adj[s]){
            if(!v[it]){
                DFSutil(it,v,adj);
            }
        }
    }
    void DFS(int nodes,vector<int> adj[]){
        vector<int> visited(V, 0);
        //this for loop is for non-connected graph
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                DFSutil(i,visited,adj);
            }
        }
    }
    //count number of paths from source to destination
    void CountPath(vector<int> adj[],int src,int &count){
        if(src==V-1){
            count++;
            return;
        }else{
            for(auto it : adj[src]){
                CountPath(adj,it,count);
            }
        }
    }
};


int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(2,3);
    g.addEdge(4,5);
    // g.BFS(2);
    int count=0;
    g.CountPath(g.v,0,count);
    cout<<count;
    
 
  

    return 0;
}