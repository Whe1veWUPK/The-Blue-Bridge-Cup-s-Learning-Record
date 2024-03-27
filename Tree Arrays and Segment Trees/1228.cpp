#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 10010;
struct  Segement
{
    int x, y1, y2;
    int k;
    bool operator<(Segement const& t){
        return x < t.x;
    }
}seg[N*2];
struct Node{
    int l, r;
    int cnt;
    int len;
} tr[N * 4];
void build(int u,int l,int r){
    tr[u] = {l, r,0,0};
    if(l==r){
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
void pushup(int u){
    if(tr[u].cnt>0){
        tr[u].len = tr[u].r - tr[u].l + 1;
    }
    else if(tr[u].l==tr[u].r){
        tr[u].len = 0;
    }
    else{
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
}
void modify(int u,int l,int r, int k){
    if (tr[u].l>=l&&tr[u].r<=r){
        tr[u].cnt += k;
        pushup(u);
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid){
            modify(u << 1, l, r,k);
        }
        if(r>mid){
            modify(u << 1 | 1, l, r,k);
        }
        pushup(u);
    }
}
int n;
int main(){
    scanf("%d", &n);
    int x1, y1, x2, y2;
    int m = 0;
    for (int i = 0; i < n; ++i){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seg[m++] = {x1, y1, y2, 1};
        seg[m++] = {x2, y1, y2, -1};
    }
    sort(seg, seg + m);
    build(1, 0, 10000);
    int res = 0;
    for (int i = 0; i < m;++i){
        if(i>0){
            res += tr[1].len * (seg[i].x - seg[i - 1].x);
        }
        modify(1, seg[i].y1, seg[i].y2 - 1,seg[i].k);

    }
    printf("%d\n", res);
    return 0;
}
