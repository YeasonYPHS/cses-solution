#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();
    
    long long int N, a, b, s = 0;
    cin >> N >> a;
    while(--N) {
        cin >> b;
        s += (a>b ? a-b : 0);
        a = (a>b ? a : b);
    }
    cout << s << "\n";

    return 0;
}