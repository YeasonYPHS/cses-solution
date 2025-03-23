#include <bits/stdc++.h>
#include <bits/extc++.h>
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;
int main()  { 
    cin.tie(0)->sync_with_stdio(0);
    tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> tr;
    int n,q,x,y,t,cnt=0;
    char op;
    cin>>n>>q;
    vector<int> employee(n+1);
    for(int i=1;i<=n;++i){
        cin>>t;
        employee[i]=t;
        tr.insert({t,i});
    }
    while(q--){
        cin>>op>>x>>y;
        if(op=='!'){
            tr.erase(tr.lower_bound({employee[x],-1}));
            employee[x]=y;
            tr.insert({y,++cnt});
        }
        else{
            cout<<tr.order_of_key({y,MOD})-tr.order_of_key({x-1,MOD})<<'\n';
        }
    }
    return  0; 
}   