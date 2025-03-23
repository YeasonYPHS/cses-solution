#include <iostream>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,M,x,ans;
    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> S;
    cin>>N>>M;
    while(N--){
        cin>>x;
        S.insert(x);
    }
    while(M--){
        cin>>x;
        auto it = S.upper_bound(x+1);
		if (it == S.begin()) cout<<"-1\n";
		else cout<<*(--it)<<"\n",S.erase(it);
    }
}