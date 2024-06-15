#include <bits/stdc++.h>
using namespace std;
int main() {
    long long dp[501][501];
    long b, a[500];
    long long n, m;
    long long mod;
    long long ans = 0;
    cin >> n >> m >> b >> mod;
    for(int i=0; i<=500; i++)
        for(int j=0; j<=500; j++)
            dp[i][j]  = 0;
    dp[0][0] = 1;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        for(int ld=0; ld<m; ld++){  
            for(int bugs=0; bugs+a[i]<=b; bugs++){
                dp[ld+1][bugs+a[i]] = (dp[ld+1][bugs+a[i]] + dp[ld][bugs])%mod;
            }
        }
    }
    for(int i=0; i<=b; i++) {
        ans = (ans+dp[m][i])%mod;
    }
    cout << ans << endl;
    return 0;
}