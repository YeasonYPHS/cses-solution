#include<iostream>
#include<map>
#define int long long int
using namespace std;
int a[200005]={0};
main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,K,dp=0,cnt=0;
    map<int,int> mp;
    mp[0]=1;
    cin>>N>>K;
    for(int i=0;i<N;++i) cin>>a[i];
    for(int i=0;i<N;++i)
        dp+=a[i],cnt+=mp[dp-K],++mp[dp];
    cout<<cnt<<'\n';
}