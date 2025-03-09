#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    int N;
    cin >> N;

    if(N<=4){
        if(N==1) cout << "1\n";
        else if(N==4) cout << "2 4 1 3\n";
        else cout << "NO SOLUTION\n";
    }
    else{
        for(int i = 0;i < N/2; ++i)
            cout << (i<<1)+1 << " ";
        if(N&1) cout << N << "\n";
        for(int i=0;i<N/2;++i)
            cout << (i<<1)+2 << " ";
    }

    return 0;
}