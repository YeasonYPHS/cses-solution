#include <iostream>
#include <stack>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,x;
    cin>>N;
    stack<pair<int,int>> S;
    S.push({0,0});
    for(int i=1;i<=N;++i){
        cin>>x;
        while(!S.empty() && S.top().first >= x) S.pop();
        cout<<S.top().second<<' ';
        S.push({x,i});
    }
}