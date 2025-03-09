#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)
#define ll long long int

ll minDiff(ll arr[], ll i, ll t, ll x){
    if(i == 0) return llabs((t - (x << 1)));
    return min(minDiff(arr, i-1, t, x + arr[i]), minDiff(arr, i-1, t, x));
}

int main(){
    optimizeIO();

    ll N, arr[20], t=0;
    cin >> N;
    for(ll i = 0;i < N; ++i) {
        cin >> arr[i];
        t += arr[i];
    }
    cout << minDiff(arr, N-1, t, 0) << "\n";

    return 0;
}