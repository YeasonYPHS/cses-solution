#include <iostream>
#define int long long int
using namespace std;
const int M = 1000000007;
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,cat_=1;
    cin>>n;
    if(n&1){
        cout<<"0\n";
        return 0;
    }
    n>>=1;
    int dp[n + 2];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n+1; ++i)
        dp[i] = dp[M % i] * (M - M / i) % M; 
    for (int i = 1; i <= n; ++i)
        cat_=(((cat_*((i<<2)-2))%M)*dp[i+1])%M;
    cout<<cat_;
}