#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, count, s = 0, a[100][100];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                break;
            }
            else
                count++;
        }
        if (count == n)
        {
            cout << "not strongly connected";
            ++s;
            break;
        }
    }
    if (s == 0)
        cout << "strongly connected";
    return 0;
}