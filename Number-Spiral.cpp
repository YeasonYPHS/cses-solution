#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    long long int T, y, x, k;
    cin >> T;
    while(T--){
        cin >> y >> x;
        if(x == y) k = y*(y-1)+1;
        else if(x > y) k = x*(x - 1) + 1 + (y-x)*(x & 1? -1 : 1);
        else k = y*(y - 1) + 1 + (x - y)*(y & 1? 1 : -1);
        cout << k << "\n";
    }


    return 0;
}