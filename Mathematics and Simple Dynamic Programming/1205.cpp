#include<iostream>
#include<cstdio>

using namespace std;
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    printf("%d\n", (n - 1) * (m - 1) - 1);
    return 0;
}