#include <iostream>
#include <cstring>
#include <cstdio>

#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 30;
char g[N][N];
int w, h;
int res;
int sx, sy;
bool st[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int bfs(int ssx,int ssy)
{
    int cnt=1;
    queue<PII> q;
    q.push({sx,sy});
    while(q.size())
    {
        PII t=q.front();
        q.pop();
        int x=t.x,y=t.y;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a<0 || a>=h || b<0 || b>=w) continue;
            if(st[a][b]) continue;
            if(g[a][b]!='.') continue;
            st[a][b]=true;
            q.push({a,b});
            cnt++;
        }
    }
    return cnt;
}



int main()
{

    scanf("%d%d", &w, &h);
    for (int i = 0; i < h; ++i)
    {
        scanf("%s", g[i]);
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (g[i][j] == '@')
            {
                sx = i;
                sy = j;
            }
            break;
        }
    }

    cout << bfs(sx, sy) << endl;

    return 0;
}