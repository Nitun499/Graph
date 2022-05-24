#include<bits/stdc++.h>
using namespace std;
void toposort(vector<pair<int,int>>*adj,int src,stack<int>&st,vector<int>&visited){
    visited[src]=1;
    for(auto it:adj[src]){
        if(!visited[it.first]){
            toposort(adj,it.first,st,visited);
        }
    }
    st.push(src);
}
void helper(vector<pair<int,int>>*adj,int src,int n){
    //first do toposort 
    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            toposort(adj,i,st,visited);
        }
    }
    //now to all stuff that means bfs
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    queue<int>pq;
    pq.push(src);
    while(!pq.empty()){
        auto top=pq.front();
        pq.pop();
        if(dist[top]!=INT_MAX){
            for(auto it:adj[top]){
                if(dist[top]+it.second<dist[it.first]){
                    dist[it.first]=dist[top]+it.second;
                    pq.push(it.first);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<dist[i]<<" ";
        }else{
            cout<<"INT_MAX"<<" ";
        }
    }
}

int main(){
    // int n,m;
    // cin>>n>>m;
    // vector<pair<int,int>>adj[n];
    // for(int i=0;i<m;i++){
    //     int u,v,wt;
    //     cin>>u>>v>>wt;
    //     adj[u].push_back({v,wt});
    // }
    // helper(adj,0,n);
    vector<int>arr={1,2,4};

    arr.resize(5,0);
    arr[3]=11;
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}