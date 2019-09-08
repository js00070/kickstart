#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

int table[256][256] = {0};
int dis[256][256];
int vis[256][256];
int r,c;

bool isValid(int i,int j){
    if(i >=0 && j>=0 && i<r && j<c){
        return true;
    }
    return false;
}

void flushVis(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            vis[i][j] = 0;
        }
    }
}

int main(){
    int T = 0;
    cin>>T;
    for(int t=0;t<T;t++){
        // int r,c;
        queue<pair<int,int>> q;
        
        cin>>r>>c;
        getchar();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                char ch=getchar();
                table[i][j] = ch - '0';
                if(table[i][j]){
                    q.push(make_pair(i,j));
                    dis[i][j] = 0;
                    vis[i][j] = 1;
                }else{
                    dis[i][j] = 0x7FFFFFFF;
                    vis[i][j] = 0;
                }
            }
            getchar();
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            int d = dis[i][j];
            if(isValid(i-1,j)){
                dis[i-1][j] = min(dis[i-1][j],d+1);
                if(!vis[i-1][j]){
                    q.push(make_pair(i-1,j));
                    vis[i-1][j] = 1;
                }
            }
            if(isValid(i+1,j)){
                dis[i+1][j] = min(dis[i+1][j],d+1);
                if(!vis[i+1][j]){
                    q.push(make_pair(i+1,j));
                    vis[i+1][j] = 1;
                }
            }
            if(isValid(i,j-1)){
                dis[i][j-1] = min(dis[i][j-1],d+1);
                if(!vis[i][j-1]){
                    q.push(make_pair(i,j-1));
                    vis[i][j-1] = 1;
                }
            }
            if(isValid(i,j+1)){
                dis[i][j+1] = min(dis[i][j+1],d+1);
                if(!vis[i][j+1]){
                    q.push(make_pair(i,j+1));
                    vis[i][j+1] = 1;
                }
            }
            q.pop();
        }
        int k = 0;

        // dist((x1, y1), (x2, y2)) = max(abs(x1 + y1 - (x2 + y2)), abs(x1 - y1 - (x2 - y2))) 
        
        printf("Case #%d: %d\n",t+1,k);
    }
    return 0;
}