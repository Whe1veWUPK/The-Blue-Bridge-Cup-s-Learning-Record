#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 210;
int T;
int R, C;
char m[N][N];

int dis[N][N];
PII start, des;
int bfs(PII start, PII des){
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    queue<PII> q;
    memset(dis, -1, sizeof dis);
    q.push(start);
    dis[start.x][start.y] = 0;
    while(!q.empty()){
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4;++i){
            int a=t.x+ dx[i];
            int b= t.y+dy[i];
            if(dis[a][b]>-1){
                continue;
            }
            if(a<0||a>=R||b<0||b>=C){
                continue;
            }
            if(m[a][b]=='#'){
                continue;
            }
            
            dis[a][b] = dis[t.x][t.y] + 1;
            if(des==make_pair(a,b)){
                return dis[a][b];
            }
            q.push({a, b});
        }
    }
    return -1;
}
int main(){
    scanf("%d", &T);
    while(T--){
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R;++i){
        scanf("%s", m[i]);
    }
    for (int i = 0; i < R;++i){
        for (int j = 0; j < C;++j){
            if(m[i][j]=='S'){
                start = {i, j};
            }
            if(m[i][j]=='E'){
                des = {i, j};
            }
        }
    }

    int res = bfs(start, des);
       if(res==-1){
           printf("oop!\n");
       }
       else{
           printf("%d\n", res);
       }
    }
    return 0;
}