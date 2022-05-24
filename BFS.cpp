#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
vector<int>ans;
void bfs(vector<int>adj[],vector<int>&visited,int curr){
    queue<int>q;
    q.push(curr);
    visited[curr]=1;
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto it:adj[top]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
}

int main(){
     int n,v; 
    cin>>n>>v;
    vector<int>adj[n+1];
    for(int i=0;i<v;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(adj,visited,i);
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
   
    return 0;
}