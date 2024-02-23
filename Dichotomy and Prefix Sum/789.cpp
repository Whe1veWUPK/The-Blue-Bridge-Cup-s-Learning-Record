#include <cstdio>
#include <iostream>
const int N = 100001;
int arr[N], n, q;
using namespace std;
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; ++i)
    {
        int x;
        scanf("%d", &x);
        int l = 0;
        int r = n - 1;
        // find left point
        while (l < r)
        {
            int mid = l + r >> 1;
            if (arr[mid] >= x)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (arr[l] == x){
            cout << l << " ";
            // find right point
            r = n - 1;
            while(l<r){
                int mid = l + r +1>> 1;
                if(arr[mid]<=x){
                    l = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            cout << r << endl;
        }
        else{
            cout << -1 << " " << -1 << endl;
        }

    }
    return 0;
}