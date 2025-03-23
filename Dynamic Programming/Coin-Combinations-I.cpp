#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
long long dp[1000005];
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,M,x;
    cin>>N>>M;
    set<int> coinz;
    for(int i=0;i<N;++i) cin>>x,coinz.insert(x);
    dp[0]=1;
    for(int curr=0;curr<=M;++curr){
        for(auto it=make_reverse_iterator(coinz.upper_bound(curr));it!=coinz.rend();++it){
            //if(curr-coinz[i]>=0){
                dp[curr]+=dp[curr-*it];
                dp[curr]%=m;
                //cout<<curr<<' '<<dp[curr]<<' '<<*it<<'\n';
                
            //}
        }
    }
    cout<<dp[M];
}