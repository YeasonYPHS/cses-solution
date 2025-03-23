#include <iostream>
#include <bitset>
#define MAX 100005
using namespace std;
bitset <MAX> dp;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    dp.reset(),dp.set(0,1);
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        dp |= dp<<x;
    }
    cout<<dp.count()-1<<'\n';
    for(int i=1;i<MAX;++i) if(dp[i]) cout<<i<<' ';
}