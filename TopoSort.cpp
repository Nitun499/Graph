#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
void dfstopo(int s,vector<int>adj[],vector<int> & visited,stack<int> &st){
    visited[s]=1;
    for(auto it : adj[s]){
        if(!visited[it]){
            dfstopo(it,adj,visited,st);
        }
    }
    st.push(s);
}
void toposort(vector<int> adj[],int n){
    stack<int> st;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
             dfstopo(i,adj,visited,st);
        }
       
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
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
   
    toposort(adj,n);
    return 0;
}