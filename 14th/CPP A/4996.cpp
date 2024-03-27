#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>


int get(int x){
    return x / 4 + (x + 1) / 2;
}

int l, r;
int main(){
    scanf("%d%d", &l, &r);
    printf("%d\n", get(r) - get(l - 1));
    return 0;
}