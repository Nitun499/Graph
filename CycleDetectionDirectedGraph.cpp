#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
//Time Complexity :O(V+E)
//Space Complexity :2*O(V)
bool helper(vector<int>adj[],vector<bool>visited,vector<bool>& recstack,int curr){
    visited[curr]=true;
    recstack[curr]=true;
    for(auto it:adj[curr]){
        if(!visited[it] && helper(adj,visited,recstack,it)){
            return true;
        }else if(recstack[it]){
            return true;
        }
    }
    recstack[curr]=false;
    return false;
    
}

int main(){
    int n,v;
    cin>>n>>v;
    vector<int>adj[n];
    for(int i=0;i<v;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool ans=false;
    vector<bool>visited(n,false),recstack(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i] && helper(adj,visited,recstack,i)){
            ans=true;
            break;
        }
    }
    if(ans){
        cout<<"There is a cycle "<<endl;
    }else{
        cout<<"No cycle"<<endl;
    }
   
    return 0;
}