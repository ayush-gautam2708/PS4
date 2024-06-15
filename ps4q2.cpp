#include <bits/stdc++.h>
using namespace std;
bool check(long long l, long long r, string &s, string &t, long long n)
{
    vector<long long> ctx(n, 0), cty(n, 0);
    long long a = 0, b = 0;
    for (long long i = l; i <= r; i++)
    {
        if (t[i] == 'A')
            a++;
        else if (t[i] == 'B')
            b++;
    }

    for (long long i = l; i <= r; i++)
    {
        if (s[i] == 'A')
            a--;
        else if (s[i] == 'B')
            b--;
    }

    if (a < 0 || b < 0)
        return false;

    for (long long i = l; i <= r; i++)
    {
        if (s[i] == 'C')
        {
            if (a > 0)
            {
                s[i] = 'A';
                a--;
            }
        }
    }

    if (s[l] == 'A')
        ctx[l] = 1;
    if (t[l] == 'A')
        cty[l] = 1;
    if (ctx[l] < cty[l])
        return false;
    for (long long i = l + 1; i <= r; i++)
    {
        if (s[i] == 'A')
            ctx[i] = ctx[i - 1] + 1;
        else
            ctx[i] = ctx[i - 1];
        if (t[i] == 'A')
            cty[i] = cty[i - 1] + 1;
        else
            cty[i] = cty[i - 1];
        if (ctx[i] < cty[i])
            return false;
    }

    return true;
}

int main()
{
    long long TC = 1;
    cin >> TC;
    while (TC--)
    {
        long long n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        bool f = true;

        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == t[i] && s[i] == 'C')
            {
                v.push_back(i);
            }
            if (t[i] == 'C' && s[i] != 'C')
            {
                f = false;
                break;
            }
        }

        if (!f)
        {
            cout << "No\n";
            continue;
        }

        for (long long j = 0; j < v.size(); j++)
        {
            long long l = 0;
            if (j - 1 >= 0)
                l = v[j - 1] + 1;
            bool f1 = true;
            long long r = v[j] - 1;
            if (l <= r)
                f1 &= check(l, r, s, t, n);
            if (!f1)
            {
                f = false;
                break;
            }
        }

        if (v.size() == 0)
        {
            f = check(0, n - 1, s, t, n);
        }
        else
        {
            long long l = v.back() + 1;
            long long r = n - 1;
            if (l <= r)
                f &= check(l, r, s, t, n);
        }

        if (f)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}