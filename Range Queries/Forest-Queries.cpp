#include <cstdio>
#define getchar getchar_unlocked
using namespace std;
int main(){
    int n,q,x1,y1,x2,y2;
    char ch;
    scanf("%d%d",&n,&q);getchar();
    int dp[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ch=getchar();
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+int(ch=='*');
        }
        getchar();
    }
    while(q--){
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        printf("%d\n",dp[y2][x2]-dp[y1-1][x2]-dp[y2][x1-1]+dp[y1-1][x1-1]);
    }
}