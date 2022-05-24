#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
//Link for Alien Dictionary Question
//https://practice.geeksforgeeks.org/problems/alien-dictionary/1#
 void dfs(vector<int>adj[],vector<int>&visited,stack<int>&st,int curr){
        visited[curr]=1;
        for(auto it:adj[curr]){
            if(!visited[it]){
                dfs(adj,visited,st,it);
            }
        }
        st.push(curr);
    }
string findOrder(string dict[], int N, int K) {
        //code here
        //first we would make a graph and then store toposort
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string word1=dict[i];
            string word2=dict[i+1];
            for(int j=0;j<min(word1.length(),word2.length());j++){
                if(word1[j]!=word2[j]){
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        vector<int>visited(K,0);
        stack<int>st;
        for(int i=0;i<K;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        string ans="";
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            ans+=(char)(top+'a');
        }
        // cout<<ans<<endl;
        return ans;
        
    }

int main(){
    
   
    return 0;
}