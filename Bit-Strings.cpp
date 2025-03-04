#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

const long long int M = 1e9+7;

int main(){
    optimizeIO();

    long long int a = 2, b, res = 1;
    cin >> b;
    a %= M;
    while(b){
        if(b&1) res = (res*a) % M;
        b >>= 1;
        a = (a*a) % M;
    }
    cout << res << "\n";

    return 0;
}