#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long maxWeight;
    cin >> n >> maxWeight;
    vector<long long> people(n);
    for (int i = 0; i < n; i++)
        cin >> people[i];
    int lim = 1 << n;
    vector<pair<long long, long long>> dp(lim);
    dp[0] = {1, 0};
    for (int mask = 1; mask < lim; mask++)
    {
        pair<long long, long long> final = {INT_MAX, INT_MAX};
        for (int i = 0; i < n; i++)
        {
            if (((1 << i) & mask) == 0)
                continue;
            auto res = dp[(1 << i) ^ mask];
            if (res.second + people[i] <= maxWeight)
            {
                res.second += people[i];
            }
            else
            {
                res.first += 1;
                res.second = people[i];
            }
            final = min(final, res);
        }
        dp[mask] = final;
    }
    cout << dp[lim - 1].first;
    return 0;
}