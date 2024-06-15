#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < (1 << k); i++)
    {
        vector<long long> v;
        for (int j = 0; j < k; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                v.push_back(a[j]);
            }
        }
        long long prod = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (prod > n / v[j])
            {
                prod = n + 1;
                break;
            }
            prod *= v[j];
        }
        if (v.size() % 2 == 0)
            ans -= n / prod;
        else
            ans += n / prod;
    }
    ans += n;
    cout << ans;
}