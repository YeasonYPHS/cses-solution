#include <iostream>
#include <map>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    int N, S = 0, x;
    map<int,int> table;

    cin >> N;
    while(N--) {
        cin >> x;
        S+=(table[x]++?0:1);
    }
    cout << S << '\n';

    return 0;
}