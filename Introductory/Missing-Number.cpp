#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    int n, k, p = 1;
    cin >> n;
    
    for(int i=2;i<=n;++i) {
        p^=i;
    }

    for(int i=0;i<n-1;++i) {
        cin >> k, p^=k;
    }

    cout << p << "\n";

    return 0;
}