#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <cstdio>
static char _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0, t, dp[200005]={0};
inline int in() {int x; if (_i[_i0] == '-') { t = -1; _i0++; } else { t = 1; } for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); x *= t; return x;}
inline void out(int x) { if (x < 0) { _o[_o0++] = '-';x = -x; }_ = 0; do { __[_++] = x % 10 | '0'; } while (x *= 0.1); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n'; }
int main() {
    fread_unlocked(_i, 1, 1 << 24, stdin);
    int N=in(), M=in();
    for (int i = 1;i <= N;++i) {dp[i] = in() ^ dp[i - 1]; }
    while (M--) {out(dp[in()-1] ^ dp[in()]); }
    fputs_unlocked(_o, stdout);
}