#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<char> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n > 2)
        {
            cout << "YES" << endl
                 << 2 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i];
                if (i == 0)
                    cout << " ";
            }
            cout << endl;
        }
        if (n == 2)
        {
            if (arr[0] >= arr[1])
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl
                     << 2 << endl;
                cout << arr[0] << " " << arr[1] << endl;
            }
        }
    }
}