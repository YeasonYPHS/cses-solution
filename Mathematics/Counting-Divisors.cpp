#include <iostream>
#include <vector>
using namespace std;
int n, x, p[1000005];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 2; i < 1000005; i++){
        if (!p[i]){
            for (int j = i; j < 1000005; j += i){
                p[j] = i;
            }
        }
    }
    while (n--){
        cin >> x;
        vector <pair<int, int> > v;
        int ans = 1;
        while (p[x]){
            if (!v.empty() && p[x] == v.back().first) ++v.back().second;
            else v.push_back({p[x], 2});
            x /= p[x];
        }
        for (auto i:v) ans *= i.second;
        cout << ans << "\n";
    }
}