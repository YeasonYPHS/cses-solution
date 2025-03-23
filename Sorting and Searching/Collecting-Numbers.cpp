#include <cstdio>
#include <cstdint>
#define MAX 22
#define int int_fast16_t
char __i[1 << MAX],_i[1 << MAX], _o[1 << MAX], _, __[20]; int _i0, _o0,N,x,ans=1,pos[200005];
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define out(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
main() {
    fread_unlocked(_i, 1, 1 << MAX, stdin);
    in(N);
    for(int i=1;i<=N;++i){in(x);pos[x]=i;}
    for(int i=1;i<N;++i) if(pos[i]>pos[i+1]) ++ans;
    out(ans);
    fputs(_o, stdout);
}