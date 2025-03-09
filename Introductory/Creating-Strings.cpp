#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    string s, out = "\n";
    int cnt = 0;

    cin >> s;
    sort(s.begin(), s.end());
    do {
        out += s + "\n";
        ++cnt;
    }while(next_permutation(s.begin(), s.end()));

    cout << cnt << out;

    return 0;
}