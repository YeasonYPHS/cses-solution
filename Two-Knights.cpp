#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    long long int n;
    cin >> n;
    for(long long int i = 1;i <= n; ++i) cout << ((i - 1)*(i + 4)*(i*i - 3*i + 4) / 2) << "\n";

    return 0;
}