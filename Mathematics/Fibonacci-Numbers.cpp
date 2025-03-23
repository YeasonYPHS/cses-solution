#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <stdio.h>
#include <cstring>
#define int long long
char __i[1 << 24],_i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0;
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define out(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
const int M = 1e9+7;
struct mat{
    int a[2][2];
    mat(){memset(a, 0, sizeof(a));}
    mat operator * (const mat &b)const{
        mat ret;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
                for (int k = 0; k < 2; ++k){
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j]) % M;
                }
            }
        }
        return ret;
    }
};
main(){
    fread_unlocked(_i, 1, 1 << 24, stdin);
    int n;
    in(n);
    mat ret,p;
    ret.a[1][0] = p.a[0][1] = p.a[1][0] = p.a[1][1] = 1;
    while (n){
        if (n & 1) ret = p * ret;
        p=p*p, n >>= 1;
    }
    out(ret.a[0][0]);
    fwrite_unlocked(_o, 1, _o0, stdout);
	return 0;
}