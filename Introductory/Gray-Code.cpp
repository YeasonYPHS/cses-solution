#include <iostream>
#include <bitset>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    int N;
    bitset<16> ans;
    cin >> N;
    for(int i = 0 ; i < ( 1 << N ) ; ++i ){
        ans = i ^ (i >> 1);
        for(int j = N - 1 ; j >= 0 ; j-- )
            cout << char(ans[j]+'0');
        cout << "\n";
    }


    return 0;
}