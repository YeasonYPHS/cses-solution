#include <cstdio>
#include <cstdint>
#define MAX 22
//#define int int_fast16_t
char __i[1 << MAX],_i[1 << MAX], _o[1 << MAX], _, __[20]; int _i0, _o0,N,i,j,curr,ans=-1,start[200005],end[200005];
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define out(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
#define max(a,b) a>b?a:b
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
    for(int i=0;i<N;++i){in(start[i]);in(end[i]);}
    radix_sort(start,N);radix_sort(end,N);
    i=j=curr=0;
    while(i<N&&j<N){
        if(start[i]<end[j]) ++curr,++i;
        else --curr,++j;
        ans=max(ans,curr);
    }
    out(ans);
    fputs(_o, stdout);
}