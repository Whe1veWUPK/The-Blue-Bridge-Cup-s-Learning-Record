#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010;
int a[N];
struct Node{
    int l, r;
    int sum;
}tr[4*N];
int n, m;
void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u,int l,int r){
    if(l==r){
        tr[u] = {l, r, a[l]};
    }
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
int query(int u,int l, int r){
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u].sum;
    }
    int sum = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l<=mid){
        sum = query(u << 1, l, r);
    }
    if(r>mid){
        sum += query(u << 1 | 1, l, r);
    }
    return sum;
}
void modify(int u,int a,int b){
    if(tr[u].l==tr[u].r){
        tr[u].sum += b;
        return;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(a<=mid){
            modify(u << 1, a, b);
        }
        if(a>mid){
            modify(u << 1 | 1, a, b);
        }
        pushup(u);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;++i){
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    int k, a, b;
    while(m--){
        scanf("%d%d%d", &k, &a, &b);
        if(k==0){
            printf("%d\n", query(1, a, b));
        }
        else{
            modify(1, a, b);
        }

    }
    return 0;
}

