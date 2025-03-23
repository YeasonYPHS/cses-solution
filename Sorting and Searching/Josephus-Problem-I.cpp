#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
void orderOfExecution(int N, int K){
    tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> V;
    // [1, N] in the set
    for (int i = 1; i <= N; ++i)
        V.insert(i);
    int pos = 0;
    while (V.size() > 1) {
        pos = (pos + K) % (int)V.size();
        cout << *(V.find_by_order(pos)) << ' ';
        V.erase(*(V.find_by_order(pos)));
        pos %= (int)V.size();
    }
    cout << *(V.find_by_order(0));
}
int main(){
    int n;
    cin>>n;
    orderOfExecution(n, 1);
    return 0;
}