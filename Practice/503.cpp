#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n, m;
int w[N];
int d[N], s[N], t[N];
LL b[N];

bool check(int mid)
{
    memset(b, 0, sizeof b);
    for (int i = 1; i <= mid; i ++ )
    {
        b[s[i]] += d[i];
        b[t[i] + 1] -= d[i];
    }

    LL s = 0;
    for (int i = 1; i <= n; i ++ )
    {
        s += b[i];
        if (s > w[i]) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    for (int i = 1; i <= m; i ++ ) scanf("%d%d%d", &d[i], &s[i], &t[i]);

    int l = 0, r = m;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    if (r == m) puts("0");
    else printf("-1\n%d\n", r + 1);

    return 0;
}