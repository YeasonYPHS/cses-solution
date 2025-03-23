#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n;
	tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ans;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		auto it = ans.upper_bound({k,INT_MAX});
		if (it == ans.end()) ans.insert({k,i});
		else ans.erase(it),ans.insert({k,i});
	}
	cout << ans.size();
	return 0;
}