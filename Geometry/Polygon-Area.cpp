#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <iostream>
#include <cstdint>
using namespace std;
#define int int_fast64_t
struct point{
    int x;
    int y;
};
int cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,ans=0;
    cin>>N;
    point p[N],o;
    for(int i=0;i<N;++i) cin>>p[i].x>>p[i].y;
    for(int i=N-1,j=0;j<N;i=j++) ans += p[i].x * p[j].y,ans -= p[i].y * p[j].x;
    cout<<(ans<0?-ans:ans);
}