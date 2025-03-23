#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <stdio.h>
#include <cstdint>
#define int int_fast64_t
using namespace std;
#define m 1000000007
#define MAX 1000000
int f[MAX+1],inv[MAX+1];
void init(){
    f[0]=1,inv[0]=inv[1]=1,inv[MAX] = 397802501;
    for(int i=1;i<=MAX;++i) f[i]=(f[i-1]*i)%m;
    for(int i=MAX;i>=1;--i) inv[i-1]=inv[i]*i%m;
}
char __i[1 << 24], _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0;
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
inline void out(int x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++]='\n';}
signed main(){
    fread_unlocked(_i, 1, 1 << 24, stdin);//cin.tie(0)->sync_with_stdio(0);
    init();
    int N,a,b;
    in(N);
    while(N--){
        in(a);in(b);
        out(f[a]*inv[b]%m*inv[a-b]%m);
    }
    fputs_unlocked(_o, stdout);
}