#include <cstdio>
#include <cstdint>
#define MAX 22
#define int int_fast32_t
char __i[1 << MAX],_i[1 << MAX], _o[15], _, __[20]; int _i0, _o0,N,a[200005],ans=1;
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = (x << 3) + (x << 1) + (_ & 15)); }
#define out(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
inline void radix_sort(int *a, int n){
    int cnt[32768] = {0},tmpa[n],temp,cnt2[32768] = {0},i;
    for (i = 0; i < n; ++i)
        ++cnt[a[i] & 32767];
    for (i = 1; i < 32768; ++i)
        cnt[i] += cnt[i - 1];
    for (i = n - 1; i >= 0; i--){
        temp = a[i] & 32767;
        --cnt[temp];
        tmpa[cnt[temp]] = a[i];
    }
    for (i = 0; i < n; i++)
        ++cnt2[(tmpa[i] >> 15) & 32767];
    for (i = 1; i < 32768; ++i)
        cnt2[i] += cnt2[i - 1];
    for (i = n - 1; i >= 0; i--){
        temp = (tmpa[i] >> 15) & 32767;
        --cnt2[temp];
        a[cnt2[temp]] = tmpa[i];
    }
    return;
}
main() {
    fread_unlocked(_i, 1, 1 << MAX, stdin);
    in(N);
    for(int i=0;i<N;++i) in(a[i]);
    radix_sort(a,N);
    for(int i=0;i<N;++i){
        if(ans<a[i]) break;
        ans+=a[i];
    }
    out(ans);
    fputs(_o, stdout);
}