#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,n,m,ans=0,x;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>> PQ;
    while(m--) cin>>x,PQ.push(x);
    while(PQ.size()>1){
        a=PQ.top();
        PQ.pop();
        PQ.push(PQ.top()+a);
        ans+=a+PQ.top();
        PQ.pop();
    }
    cout<<ans;
}