#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int p[100005],r[100005];
int Find(int x){
    return p[x] == x ? x : p[x] = Find(p[x]);
}
void Union(int x,int y){
    int g1 = Find(x), g2 = Find(y);
    if(g1 != g2){
        if (r[g1] > r[g2]) {
            p[g2] = g1;
        }
        else if (r[g1] < r[g2]) {
            p[g1] = g2;
        } else {
            p[g2] = g1;
            ++r[g1];
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,M,x,y;
    map<int,int> mp;
    memset(r,1,sizeof(r));
    cin>>N>>M;
    for(int i=1;i<=N;++i) p[i]=i;
    while(M--){
        cin>>x>>y;
        Union(x,y);
    }
    for(int i=1;i<=N;++i){
        ++mp[Find(i)];
    }
    cout<<(mp.size()-1)<<'\n';
    for(auto it=next(mp.begin());it!=mp.end();++it)
        cout<<mp.begin()->first<<' '<<it->first<<'\n';
}