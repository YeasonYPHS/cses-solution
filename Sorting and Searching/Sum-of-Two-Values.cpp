#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <iostream>
#include <map>
using namespace std;
#define loop(x,n) for(int x = 1; x <= n; ++x)
#define int int_fast64_t
char __i[1 << 24], _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0;
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define out(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_];}
signed main() {
    fread_unlocked(_i, 1, 1 << 24, stdin);
    map<int, int> mp;
    int N,K,x;
    in(N);in(K);
    loop(i,N) {
        in(x);
        if (mp[K - x]) {
            out(mp[K - x]) _o[_o0++] = ' ';
            out(i); _o[_o0++] = '\n';
            fputs(_o, stdout);
            return 0;
        }
        mp[x] = i;
    }
    fputs("IMPOSSIBLE\n", stdout);
}