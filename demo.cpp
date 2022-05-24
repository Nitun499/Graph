
#include <bits/stdc++.h>
using namespace std;
int findpar(int a,vector<int>&parent){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=findpar(parent[a],parent);
}
void Union(int a,int b,vector<int>&parent,vector<int>&size){
	a=findpar(a,parent);
	b=findpar(b,parent);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main()
{
	int n;
	cin>>n;
	vector<int>parent(n+1,0),size(n+1,1);
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	int t;
	cin>>t;
	while(t--){
		int u,v;
		cin>>u>>v;
		Union(u,v,parent,size);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(parent[i]==i){
			ans++;
		}
	}
	cout<<ans<<endl;

}
// Write your code here

