#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define n 5
#define m 5
using namespace std;
void RatInMaze(int x, int y, int maze[][m], string move, vector<string> &final ,bool visited[][m],int dx[],
int dy[])
{
    if(x==n-1 && y==n-1){
        final.push_back(move);
        return;
       
    }
    // //downward
    // if(x+1<n && maze[x+1][y]==1 && !visited[x+1][y]){
    //     visited[x][y]=true;
    //     RatInMaze(x+1,y,maze,move+'D',final,visited);
    //     visited[x][y]=false;
    // }
    // //left
    //   if(y-1>=0 && maze[x][y-1]==1 && !visited[x][y-1]){
    //     visited[x][y]=true;
    //     RatInMaze(x+1,y,maze,move+'L',final,visited);
    //     visited[x][y]=false;
    // }
    // //right
    //   if(y+1<n && maze[x][y+1]==1 && !visited[x][y+1]){
    //     visited[x][y]=true;
    //     RatInMaze(x,y+1,maze,move+'R',final,visited);
    //     visited[x][y]=false;
    // }
    // //upward
    //   if(x-1>=0 && maze[x-1][y]==1 && !visited[x-1][y]){
    //     visited[x][y]=true;
    //     RatInMaze(x-1,y,maze,move+'U',final,visited);
    //     visited[x][y]=false;
    // }
    //instead of running four if condition we can also make two array for direction in
    //which rat can move
    string path="DLRU";
    for(int index=0;index<4;index++){
        int nextx=x+dx[index];
        int nexty=y+dy[index];
        if(nextx<n && nexty<n && nextx>=0 && nexty>=0 && !visited[nextx][nexty] &&maze[nextx][nexty]){
            visited[x][y]=true;
             RatInMaze(nextx,nexty,maze,move+path[index],final,visited,dx,dy);
             visited[x][y]=false;
        }
    }
}

int main()
{
    int maze[n][m] = {{1, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}};
    vector<string> finalPath;
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    int dx[]={1,0,0,-1};
    int dy[]={0,-1,1,0};
    RatInMaze(0, 0, maze, "", finalPath, visited,dx,dy);
    for(int i=0;i<finalPath.size();i++){
        cout<<finalPath[i]<<" ";
    }

    return 0;
}