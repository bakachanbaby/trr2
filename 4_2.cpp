#include <bits/stdc++.h>
using namespace std;
#define MAX 100;
int a[100][100], b[100], c[100];
int n, y, d;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
        c[i] = 0;
}
void R()
{
    cout << "1 ";
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    d++;
    cout << endl;
}
void H(int y)
{
    int j, k;
    for (int j = 1; j <= n; j++)
    {
        if (a[b[y - 1]][j] == 1 && c[j] == 0)
        {
            b[y] = j;
            c[j] = 1;
            if (y < n)
            {

                H(y + 1);
            }
            else if (b[y] == b[0])
                R();
            c[j] = 0;
        }
    }
}
int main()
{
    b[0] = 1;
    d = 0;
    cin >> n;
    cin >> y;
    init();
    H(y);
}