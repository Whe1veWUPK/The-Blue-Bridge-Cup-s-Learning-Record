#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
const int N = 5000000;
struct Dir{
    int s, c, d;
    bool operator<(const Dir&t){
        if(s<t.s){
            return true;
        }
        else if(s==t.s&&c<t.c){
            return true;
        }
        else if(s==t.s&&c==t.c&&d<t.d){
            return true;
        }
        else{
            return false;
        }
    }
}sum[N];
int n, m;
using namespace std;
int main(){
    
    scanf("%d", &n);
    for (int c = 0; c * c <= n;++c){
        for (int d = c; c * c + d * d <= n;++d){
            sum[m].s = n - c * c - d * d;
            sum[m].c = c;
            sum[m].d = d;
            ++m;
        }
    }
    sort(sum, sum + m);
    // for (int i = 0; i < m;++i){
    //     printf("%d %d %d\n", sum[i].s, sum[i].c, sum[i].d);
    // }
    for (int a = 0; a * a <= n; ++a){
        for (int b = a; a * a + b * b <= n; ++b){
                int l = 0;
                int r = m - 1;
                int t = a * a + b * b;
                while (l < r){
                    int mid = l + r >> 1;
                    if (sum[mid].s>=t){
                        r = mid;
                    }
                    else{
                        l = mid + 1;
                   }
                }
                if(t+sum[l].c*sum[l].c+sum[l].d*sum[l].d==n){
                        printf("%d %d %d %d\n", a, b, sum[l].c, sum[l].d);
                        return 0;
                }

        }
    }

    return 0;
}