#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr

bool cycleDetect(vector<int>adj[],vector<int>&visited,int curr,int n){
    //logic is simple or u can say same idea as of khans algorithm
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    int  ans=0;
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        ans++;
        for(auto it:adj[top]){
            if(--indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans!=n;
}

int main(){
    int n,v;
    cout<<"Enter number of nodes and edges"<<endl;
    cin>>n>>v;
    vector<int> adj[n];
    for(int i=0;i<v;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>visited(n,0);

   
    return 0;
}