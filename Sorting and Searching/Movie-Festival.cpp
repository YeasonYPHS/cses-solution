#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){return a.second==b.second?a.first<b.first:a.second<b.second;}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,ans=0,currEnd=-1;
    cin>>N;
    pair<int,int> events[N];
    for(int i=0;i<N;++i) cin>>events[i].first>>events[i].second;
    sort(events,events+N,cmp);
    for(int i=0;i<N;++i){
        //cout<<events[i].first<<' '<<events[i].second<<'\n';
        if(currEnd <= events[i].first){
            currEnd=events[i].second;
            ++ans;
        }
    }
    cout<<ans<<'\n';
}