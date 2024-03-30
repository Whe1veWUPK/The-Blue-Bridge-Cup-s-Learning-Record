#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 5000;
typedef long long LL;
string s;

bool check(int i, int j){
     while(i<j){
        if(s[i]>s[j]){
            return true;
        }
        else if(s[i]==s[j]){
            ++i;
            --j;
        }
        else{
            break;
        }
     }
     return false;
}
int main(){
    cin >> s;
    int n = s.length();
    LL res = 0;
    for (int i = 0; i < n;++i){
        for (int j = i + 1; j < n;++j){
            if(s[i]>s[j]){
                ++res;
            }
            else{
                if(check(i, j)){
                    ++res;
                }
                else{
                    continue;
                }
            }
        }
    }
    printf("%lld", res);
    return 0;
}