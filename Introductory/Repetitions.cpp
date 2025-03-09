#include <iostream>
#include <cmath>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int solve(){
    int x = -1, cnt = 0;
    char now, last='#';
    while(now = getchar()){
        if(now == EOF) break;
        if(now == last) ++cnt;
        else x = max(x, cnt), cnt = 0;
        last = now;
    }
    return x+1;
}

int main(){
    //optimizeIO();
    cout << solve() << "\n";

    return 0;
}