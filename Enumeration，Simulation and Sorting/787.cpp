#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 100010;

int a[N];

int n;
void mergeSort(int left,int right){
    if(right-left<=1){
        if(a[left]>a[right]){
            swap(a[left], a[right]);
        }
        return;
    }
    int mid = left + right >> 1;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    int *t = new int[right - left + 1];
    for (int i=0,l = left,r=mid+1; i<right-left+1;++i){
        if(a[l]<=a[r]&&l<=mid&&r<=right){
            t[i] = a[l];
            ++l;
        }
        else if(a[r]<a[l]&&l<=mid&&r<=right){
            t[i] = a[r];
            ++r;
        }
        else if(l>mid){
            t[i] = a[r];
            ++r;
        }
        else if(r>right){
            t[i] = a[l];
            ++l;
        }
    }
    for (int i = 0; i < right - left + 1;++i){
        a[i + left] = t[i];
    }
    delete[] t;
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n;++i){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}