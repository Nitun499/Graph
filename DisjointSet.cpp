#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
class Disjoint{
   unordered_map<int,int> parent;
   unordered_map<int,int> rank;
   public:
   void makeset(vector<int> &universe){
       for(auto i : universe){
           parent[i]=i;
           rank[i]=0;
       }
   }
   int find(int k){
       if(parent[k]==k){
           return parent[k];
       }
       parent[k]=find(parent[k]);
       return parent[k];
   }
   void Union(int a,int b){
       int p1=find(a);
       int p2=find(b);
       if(p1==p2){
           return;
       }
       else if(rank[p1]>rank[p2]){
           parent[p2]=p1;
       }else if(rank[p1]<rank[p2]){
           parent[p1]=p2;
       }else{
           parent[p1]=p2;
           rank[p2]++;
       }
   }
   void printset(vector<int> & universe,Disjoint &ds){
       for (int i: universe) {
        cout << ds.find(i) << ' ';
    }
    cout << endl;
   }
};

int main(){
    Disjoint ds;
    vector<int> universe={1,2,3,4,5};
    ds.makeset(universe);
    ds.printset(universe,ds);
    ds.Union(4, 3); 
    ds.printset(universe,ds);
    ds.Union(2, 1);
    ds.printset(universe,ds);
    ds.Union(1, 3); 
    ds.printset(universe,ds);




    return 0;
}