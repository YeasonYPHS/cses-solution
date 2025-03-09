#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

int main(){
    optimizeIO();

    int N, a, b;
    cin >> N;
    while(N--) {
        cin >> a >> b;
        cout<<((a+b)%3==0&&(a>b?a<=b*2:b<=a*2)?"YES":"NO")<<'\n';
    }
    
    return 0;
}