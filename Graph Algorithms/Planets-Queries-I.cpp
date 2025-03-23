#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <cstdio>
const int N = 2e5+5,M = 30;
static char _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0, t, mp[N][M+1], n;
inline int in() {int x; if (_i[_i0] == '-') { t = -1; _i0++; } else { t = 1; } for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); x *= t; return x;}
inline void out(int x) { if (x < 0) { _o[_o0++] = '-';x = -x; }_ = 0; do { __[_++] = x % 10 | '0'; } while (x *= 0.1); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n'; }
inline int binary_jump(int k,int x){
    for(int i=0;i<M;++i)
        if(k & 1<<i) x=mp[x][i];
    return x;
}
int main(){
    fread_unlocked(_i, 1, 1 << 24, stdin);
    int n=in(),q=in(),x,k;
    for(int i=1;i<=n;++i) mp[i][0]=in();
    for(int i=1;i<M;++i){
        for(int j=1;j<=n;++j){
            mp[j][i]=mp[mp[j][i-1]][i-1];
        }
    }
    while(q--) out(binary_jump(in(),in()));
    fputs_unlocked(_o, stdout);
}