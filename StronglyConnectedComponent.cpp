#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
void dfstopo(int s,stack<int>&st,vector<int>& visited,vector<int>adj[]){
    visited[s]=1;
    for(auto it: adj[s]){
        if(!visited[it]){
            dfstopo(it,st,visited,adj);
        }
    }
    st.push(s);
}
 void revdfs(int s,vector<int> transpose[],vector<int>& visited){
     cout<<s<<" ";
     visited[s]=1;
     for(auto it : transpose[s]){
         if(!visited[it]){
             revdfs(it,transpose,visited);
         }
     }
 }

int main(){
 int n,v;
 cin>>n>>v;
 vector<int> adj[n];
 for(int i=0;i<v;i++){
     int a,b;
     cin>>a>>b;
     adj[a].push_back(b);
 }
 //toposort of the graph
 stack<int> st;
 vector<int> visited(n,0);
 for(int i=0;i<n;i++){
     if(!visited[i]){
         dfstopo(i,st,visited,adj);
     }
 }
 //transpose the graph
 vector<int> transpose[n];
 for(int i=0;i<n;i++){
     visited[i]=0;
     for(auto it : adj[i]){
         transpose[it].push_back(i);
     }
 }
 // do dfs according to finishing time vertexes
 while(!st.empty()){
     int node=st.top();
     st.pop();
     if(!visited[node]){
         cout<<"SCC : ";
         revdfs(node,transpose,visited);
     }
 }
    return 0;
}