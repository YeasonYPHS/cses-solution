#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <cstdio>
#include <bitset>
#include <cstring>
#define MAX 29
char __i[1 << MAX],_i[1 << MAX], _o[1 << MAX], _, __[16]; int _i0, _o0;
#define in(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define out(x) { _ = 0; do {__[_++] = x % 10 | '0'; } while ( x *= 0.1 ); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n';}
int n,m,res=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
std::bitset<1005> mp[1005];
inline bool inbound(int x,int y){return x>=0 && x<n && y>=0 && y<m;}
void dfs(int x,int y){
	for(int i=0,a,b;i<4;++i){
		a=x+dx[i],b=y+dy[i];
		if(inbound(a,b) && mp[a][b]){
			mp[a][b]=0;
			dfs(a,b);
		}
	}
}
main(){
	fread_unlocked(_i, 1, 1 << MAX, stdin);
  	char ch;
  	in(n);in(m);
  	for(int i=0;i<n;++i,_i0++)
    	for(int j=0;j<m;++j)
        	mp[i][j]=(_i[_i0++]=='.');
    /*
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j)
    	    _o[_o0++]=mp[i][j]?'.':'#';
    	_o[_o0++]='\n';
    }*/
 	for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		if(mp[i][j]){
    			++res;
    			dfs(i,j);
			}
    	}
  	}
  	out(res);
    fwrite_unlocked(_o, 1, _o0, stdout);
}