#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; (ans << 1) <= n; i++)
        {
            ans = 1 << i;
        }
        cout << ans - 1 << endl;
    }
}