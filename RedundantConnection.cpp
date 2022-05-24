#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
class Dsu{
   unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    public:
    void makeset(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }  
    }
    //path compression
    int findparent(int i){
        if(parent[i]==i){
            return parent[i];
        }
        return parent[i]=findparent(parent[i]);
    }
    void unionf(int a,int b){
        a=findparent(a);
        b=findparent(b);
        if(rank[a]>rank[b]){
            parent[b]=a;
        }else if(rank[b]>rank[a]){
            parent[a]=b;
        }else{
            parent[a]=b;
            rank[b]++;
        }
    }
 };
//number of operations to make network connected
//given an undirected graph(disconnected) we have to find operations to connect them all in a single component
int main(){
    
   
    return 0;
}