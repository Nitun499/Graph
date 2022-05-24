#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
bool isSafe(int r,int c,int row,int col){
    return r>=0 && c>=0 && r<row && c<col;
}
//this can be only done by dijasktra algorithm bcoz we are allowed to move in all four directions
int mincost(vector<vector<int>>&arr){
    int row=arr.size();
    int col=arr[0].size();
    vector<vector<int>>dist(arr.size(),vector<int>(arr[0].size(),INT_MAX));
    dist[0][0]=arr[0][0];
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({dist[0][0],{0,0}});
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int x=top.second.first;
        int y=top.second.second;
        int cost=top.first;
        for(int i=0;i<4;i++){
            int nextx=x+dx[i];
            int nexty=y+dy[i];
            if(isSafe(nextx,nexty,row,col)){
                if(dist[nextx][nexty]>cost+arr[nextx][nexty]){
                    dist[nextx][nexty]=cost+arr[nextx][nexty];
                    pq.push({dist[nextx][nexty],{nextx,nexty}});
                }
            }
        }
    }
    return dist[row-1][col-1];
}

int main(){
    vector<vector<int>>arr={
        {10, 32, 67, 42},
        {25, 43, 11, 39},
        {35, 37, 85, 14},
        {32, 62, 45, 35}
       
    };
    int ans=mincost(arr);
    cout<<ans;
    return 0;
}