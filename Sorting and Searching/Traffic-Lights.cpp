#include <iostream>
#define max(a,b) a>b?a:b
#include <set>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,M,x;
    cin>>N>>M;
    set<int> S;
    multiset<int> K;
    S.insert(0),S.insert(N),K.insert(N);
    while(M--){
        cin>>x;
        auto r = S.upper_bound(x),l=prev(r);
        K.erase(K.find(*r-*l));
        K.insert(*r-x),K.insert(x-*l);
        S.insert(x);
        cout<<*prev(K.end())<<'\n';
    }
}