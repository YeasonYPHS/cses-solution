#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
int main()  { 
    cin.tie(0)->sync_with_stdio(0);
    tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> tr;
    queue<int> Q;
    int n,k,x,halfk,cnt=0;
    cin>>n>>k;
    halfk=(k-1)/2;
    for(int i=0;i<k;++i){
        cin>>x;
        tr.insert({x,++cnt});
        Q.push(x);
    }
    for(int i=k;i<=n;i++) {
        cout<<tr.find_by_order(halfk)->first<<"\n";
        cin>>x;
        tr.insert({x,++cnt});
        Q.push(x);
        tr.erase(tr.lower_bound({Q.front(),-1}));
        Q.pop();
    }    
    return  0; 
}    