#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define int long long
using namespace std;
int n;
 
signed main(){
    ios
    cin>>n;
    int arr[n+5],lft[n+5],rht[n+5];
    memset(arr,0,sizeof(arr));
    
    for(int i=1;i<=n;i++)cin>>arr[i];
    vector<int> stk(1,0);
    
    for(int i=1;i<=n;i++){
        while(arr[i]<=arr[stk.back()])stk.pop_back();
        lft[i] = i-stk.back();
        stk.push_back(i);
    }
    while(!stk.empty())stk.pop_back();
    
    stk.push_back(n+1);
    
    for(int i=n;i>=1;i--){
        while(arr[i]<=arr[stk.back()])stk.pop_back();
        rht[i] = stk.back()-i-1;
        stk.push_back(i);
    }
    int ans[n+5];
    for(int i=1;i<=n;i++){
        ans[i-1] = arr[i]*(lft[i]+rht[i]);
    }
    cout<<*max_element(ans,ans+n)<<endl;
}