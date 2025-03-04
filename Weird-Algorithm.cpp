#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();
    
    long long int n;
    cin >> n;
    while(n>1) {
        cout << n << " ";
        n = ((n&1) ? ((n<<1)+n+1) : (n>>1));
    }
    cout << "1\n";

    return 0;
}