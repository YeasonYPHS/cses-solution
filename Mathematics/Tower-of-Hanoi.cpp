#include <iostream>
 
using namespace std;
 
#define optimizeIO() cin.tie(0)->sync_with_stdio(0)
 
void hanoi(int n, char A, char B, char C){
    if(n == 1)
        cout << A << ' ' << C << '\n';
    else{
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}
 
int main(){
    optimizeIO();
 
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n';
    hanoi(n, '1', '2', '3');
 
 
    return 0;
}