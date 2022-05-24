#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>mylist[],vector<int>&visited,int src){
    //enter at vertex
    visited[src]=1;
     cout<<src<<" ";
     //to go to all the adjacent nodes of a node
    for(auto child:mylist[src]){
        if(visited[child]) continue;
        dfs(mylist,visited,child);
    }
   
    //on leave function from stack got wipe out by itself
}
void bfs(vector<int>mylist[],vector<int>&visited,int src){
    //make a queue
    queue<int>q;
    q.push(src);
    visited[src]=1;
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        cout<<top<<" ";
        //go to all its adjacent nodes
        for(auto child:mylist[top]){
            if(visited[child])continue;
            visited[child]=1;
            q.push(child);
        }
    }
    
}
int main(){
    //nunber  of vertexes and number of edges
    int n,v; 
    cin>>n>>v;
    vector<int>mylist[n];
    for(int i=0;i<v;i++){
        int u,v;
        cin>>u>>v;
        //undirected
        mylist[u].push_back(v);
        mylist[v].push_back(u);
    }
    // cout<<"mylistacency list is-> "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<"Vertex "<<i<<"-> ";
    //     for(auto child:mylist[i]){
    //         cout<<child<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int>visited(n,0);
    //for more than one component
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        cout<<"Component of graph-> ";
        bfs(mylist,visited,i);
        cout<<endl;
    }
    
    return 0;
}