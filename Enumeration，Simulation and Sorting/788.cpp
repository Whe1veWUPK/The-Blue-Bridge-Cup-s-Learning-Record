#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int cmp[N];
long long int res = 0;

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1,k = 0;

    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
        {
            cmp[k ++] = q[i ++];
        }
        else
        {
            res += mid - i + 1;
            cmp[k ++] = q[j ++];
        }
    }

    while (i <= mid) cmp[k ++] = q[i ++];
    while (j <= r) cmp[k ++] = q[j ++];

    for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = cmp[j];
}

int main()
{
    int n;
    cin >> n;
    int q[n];
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    cout << res << endl;
    return 0;

}

