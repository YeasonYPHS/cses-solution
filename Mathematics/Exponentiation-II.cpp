#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <stdio.h>
#include <cstdint>
#define int int_fast64_t
#define MAX 29
static char __i[1 << MAX], _i[1 << MAX], _o[1 << MAX], _, __[16]; int _i0, _o0;
#define scanu(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define putnumu(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
const int M = 1e9 + 7;
main() {
    fread_unlocked(_i, 1, 1 << MAX, stdin);
    int N, a, b, c, res;
    scanu(N);
    while (N--) {
        scanu(a);scanu(b);scanu(c);
        res = 1;
        b %= (M - 1);
        while (c > 0) {
            if (c & 1) res = (res * b) % (M - 1);
            c >>= 1;
            b = (b * b) % (M - 1);
        }
        b = res;res = 1;
        a %= M;
        while (b > 0) {
            if (b & 1) res = (res * a) % M;
            b >>= 1;
            a = (a * a) % M;
        }
        putnumu(res);
    }
    fputs(_o, stdout);
    return 0;
}