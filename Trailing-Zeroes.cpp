#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    long long int n, count = 0;
    cin >> n;

    for(long long int i = 5; n/i >= 1; i*=5)
        count+=n/i;
    
    cout << count << "\n";

    return 0;
}