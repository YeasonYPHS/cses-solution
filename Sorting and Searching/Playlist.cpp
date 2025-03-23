#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include<cstdio>
#include<map>
#define max(a,b) a>b?a:b
using namespace std;
//#define int unsigned long long int
static char _i[1 << 24], _o[1 << 24], _, __[30]; int _i0, _o0, _t ,a , b;
inline void in(int &x) {if(_i[_i0] == '-'){ _t = -1 ; _i0++; }else{ _t = 1; } for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); x*=_t;}
inline void out(int x) { if( x < 0 ){ _o[_o0++] = '-' ; x = -x ; } _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
main(){
    size_t _l = fread(_i, 1, 1 << 24, stdin);
    int N,mx=-1;
    in(N);
    int arr[N+1];
    map<int,int> mp;
    for(int i=1,l=1;i<=N;++i){
        in(arr[i]);
        if(mp[arr[i]]>0){
            for(;l<=mp[arr[i]];++l)
                mp[arr[l]]=0;
        }
        mp[arr[i]]=i;
        mx=max(mx,i-l+1);
    }
    out(mx);
    fwrite(_o,1,_o0,stdout);
}