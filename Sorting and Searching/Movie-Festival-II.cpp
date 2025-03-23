#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,K,ans=0;
    cin>>N>>K;
    vector< pair<int,int> > v(N);
    for(int i=0;i<N;++i) cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    multiset<int> S;
    for(int i=0;i<K;++i) S.insert(0);
    for(int i=0;i<N;++i){
        auto it = S.upper_bound(v[i].second);
        if(it == begin(S)) continue;
        S.erase(--it);
        S.insert(v[i].first);
        ++ans;
    }
    cout<<ans;
}