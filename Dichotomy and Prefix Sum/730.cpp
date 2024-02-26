#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;
const int N = 100001;
int H[N];

bool startSkip(int mid,int n,int maxValue){
    //cout << "mid is " << mid << endl;

    for (int i = 1; i <= n; ++i){   
        if(mid>=maxValue){
            return true;
        }
        if(H[i]<=mid){
            int temp = mid - H[i];
            mid += temp;
        }
        else{
            //cout << H[i] << " > " << mid << endl;
            int temp = H[i] - mid;
            mid -= temp;
        }
        if(mid<0){
            //printf("Now mid is %lld\n", mid);
            return false;
        }
        
    }
    return true;
}
int main(){
    int n;
    scanf("%d", &n);
    int minValue = INT_MAX;
    H[0] = 0;
    int maxValue = 0;
    for (int i = 1; i <= n;++i){
        scanf("%d", &H[i]);
        maxValue = max(maxValue, H[i]);
    }
    // for (int i = 0; i <=30;++i){
    //     printf("%d ", H[i]);
    // }
    // puts("");
    int l = 1;
    int r = 100000;
    while(l<r){
        int mid = (l + r) >> 1;
        //printf("mid is %d", mid);
        if(startSkip(mid,n,maxValue)){
            r = mid;
            minValue = min(minValue, mid);
        }
        else{
            //printf("Can not skip , now mid is %d\n", mid);
            l = mid + 1;
        }
        
    }
    
    printf("%d\n", minValue);
    return 0;
}