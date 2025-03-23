#include<iostream>
#define int long long int
using namespace std;
int dp[200005]={0};
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,K,l=1,r=1,cnt=0;
    cin>>N>>K;
    for(int i=1;i<=N;++i) cin>>dp[i],dp[i]+=dp[i-1];
    while(l<=N){
        if(dp[r]-dp[l-1]==K) ++cnt,++l;
        else if(dp[r]-dp[l-1]<K) ++r;
        else ++l;
    }
    cout<<cnt<<'\n';
}