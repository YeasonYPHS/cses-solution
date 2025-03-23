#include <bits/stdc++.h>
using namespace std;
int N,Q,x;
set<int> S={0};
multiset<int> res;
void modify(int x){
    if(x==0 || x==N) return;
    auto it = S.find(x);
    if (it != end(S)) {  // x is currently present in dif, remove it
        int a = *prev(it), b = *next(it);
        res.erase(res.find(x - a)), res.erase(res.find(b - x));  // update ret
        res.insert(b - a);
        S.erase(it);             // remove x from dif
    }
	else{                       // x is not currently in dif, insert it
        it = S.insert(x).first;  // insert x into dif
        // it = iterator corresponding to x
        int a = *prev(it), b = *next(it);
        res.erase(res.find(b - a));  // update res
        res.insert(x - a), res.insert(b - x);
    }
	    
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    N=s.size();
    S.insert(N);
    for(int i=0;i<N-1;++i) if(s[i]!=s[i+1]) S.insert(i+1);
    for(auto it = S.begin(); next(it) != S.end(); it++) res.insert(*next(it) - *it);
    cout<<'\n';
    cin>>Q;
    while(Q--){
        cin>>x;
        modify(x);
        modify(x-1);
        cout<<*res.rbegin()<<'\n';
    }
}