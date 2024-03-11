#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

Time x[3], y[3];
int T;
void toTime(Time *t, string info)
{
    t->hour = (info[0] - '0') * 10 + info[1] - '0';
    t->minute = (info[3] - '0') * 10 + info[4] - '0';
    t->second = (info[6] - '0') * 10 + info[7] - '0';
}
int toSeconds(Time t)
{
    return t.hour * 3600 + t.minute * 60 + t.second;
}
int calRes(int f1,int f2)
{
    // cout << toSeconds(y[2]) << " " << toSeconds(x[1]) << endl;
    return (f1 * 24 * 3600 - toSeconds(x[1]) + toSeconds(y[2]) + f2 * 24 * 3600 - toSeconds(y[1]) + toSeconds(x[2])) / 2;
}
bool needZero(int t)
{
    if (t >= 0 && t <= 9)
    {
        return true;
    }
    return false;
}

void printRes(int res)
{
    int hour = res / 3600;
    int minute = (res % 3600) / 60;
    int second = res % 60;
    if (needZero(hour))
    {
        cout << "0" << hour << ":";
    }
    else
    {
        cout << hour << ":";
    }
    if (needZero(minute))
    {
        cout << "0" << minute << ":";
    }
    else
    {
        cout << minute << ":";
    }
    if (needZero(second))
    {
        cout << "0" << second << endl;
    }
    else
    {
        cout << second << endl;
    }
}


void solve()
{
    string buffer1[3];
    string buffer2[3];
    for (int i = 0; i < 2; ++i)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int cnt = 0;
        if (i == 0)
        {
            while (iss >> buffer1[cnt])
            {
                ++cnt;
            }
        }
        else
        {
            cnt = 0;
            while (iss >> buffer2[cnt])
            {
                ++cnt;
            }
        }
    }
    toTime(&x[1], buffer1[0]);
    toTime(&y[2], buffer1[1]);
    toTime(&y[1], buffer2[0]);
    toTime(&x[2], buffer2[1]);
    int f1 = 0, f2 = 0;
    if(buffer1[2].size()>0){
        f1 = buffer1[2][2] - '0';
    }
    if(buffer2[2].size()>0){
        f2 = buffer2[2][2] - '0';
    }
    //cout << f1 << " " << f2 << endl;
    int res = calRes(f1, f2);
    printRes(res);
}
int main()
{
    cin >> T;
    string line;
    getline(cin, line);

    while (T--)
    {
        solve();
    }
    return 0;
}
