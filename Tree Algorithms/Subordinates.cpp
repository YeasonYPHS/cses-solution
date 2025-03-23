#include <iostream>
#include <vector>
char _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0, t;
#define in(x) { if(_i[_i0] == '-'){ t = -1 ; _i0++; }else{ t = 1; } for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); x*=t;}
#define out(x) { if(x<0){_o[_o0++]='-';x=-x;}_ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = ' ';}
using namespace std;
vector<int> V[200005];
int cnt[200005]={};
int dfs(int x){
    if(cnt[x]>0) return cnt[x];
    for(auto it:V[x])
        cnt[x]+=dfs(it)+1;
    return cnt[x];
}
int main(){
    fread(_i, 1, 1 << 24, stdin);
    int N,x;
    in(N);
    for(int i=2;i<=N;++i){
        in(x);
        V[x].emplace_back(i);
    }
    for(int i=1;i<=N;++i){
        x=dfs(i);
        out(x);
    }
    fwrite(_o, 1, _o0, stdout);
}