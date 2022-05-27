#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
// bool cycledetectionBFS(vector<int>adj[],vector<int>&visited,int curr){
//     queue<pair<int,int>>pq;
//     pq.push({curr,-1});
//     visited[curr]=1;
//     while(!pq.empty()){
//         auto top=pq.front();
//         pq.pop();
//         auto node=top.first;
//         auto parent=top.second;
//         for(auto child:adj[node]){
//             if(!visited[child]){
//                 visited[child]=1;
//                 pq.push({child,node});
//             }else if(child!=parent){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool dfs(vector<int>mylist[],vector<int>&visited,int src,int parent){
    //enter at vertex
    visited[src]=1;
     //to go to all the adjacent nodes of a node
    for(auto child:mylist[src]){
        if(!visited[child] ){
            if(dfs(mylist,visited,child,src)){
                      return true;
            }
        }else if(child!=parent){
            return true;
        }    
    }
    return false;
   
    //on leave function from stack got wipe out by itself
}

// bool cycleDetect(vector<int>adj[],vector<int>&visited,int curr,int n){
//     //logic is simple or u can say same idea as of khans algorithm
//     vector<int>indegree(n,0);
//     for(int i=0;i<n;i++){
//         for(auto it:adj[i]){
//             indegree[it]++;
//         }
//     }
//     queue<int>q;
//     int  ans=0;
//     while(!q.empty()){
//         auto top=q.front();
//         q.pop();
//         ans++;
//         for(auto it:adj[top]){
//             if(--indegree[it]==0){
//                 q.push(it);
//             }
//         }
//     }
//     return ans!=n;
// }

int main(){
    int n,v;
    cout<<"Enter number of nodes and edges"<<endl;
    cin>>n>>v;
    vector<int> adj[n];
    for(int i=0;i<v;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(n,0);
    bool flag=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(adj,visited,i,-1)){
                flag=true;
            }
        }
    }
    if(flag){
        cout<<"Yes there is a cycle";
    }else{
        cout<<"No cycle";
    }

   
    return 0;
}