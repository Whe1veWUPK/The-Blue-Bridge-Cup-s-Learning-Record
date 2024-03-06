#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
const int N = 5000001;


int t, n;
int s[N];
void solve(int r){
    scanf("%d", &n);
    memset(s, 0, sizeof s);
    char a[N];
    for (int i = 1; i <= n;++i){
        cin >> a[i];

        s[i] = s[i - 1] + (int)(a[i]-'0');
    }
    int res = 0;
    if(n%2==0){
        
        for (int i = n / 2; i <= n;++i){
            res = max(res, s[i] - s[i - n / 2]);
            
        }
       
    }
    else{
        for (int i = n / 2 + 1; i <= n; ++i){
            res = max(res, s[i] - s[i - n / 2 - 1]);
        }
    }
    printf("Case #%d: %d\n", r, res);


}
int main(){
    scanf("%d", &t);
    int r = 1;
    while(t--){
        solve(r);
        ++r;
    }
    return 0;
}