#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(),x.end()

int main(){
    optimizeIO();

    long long int n;
    cin >> n;
    long long int sum = n * (n + 1) / 2;
 
    if (sum % 2 != 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
 
        long long int target = sum / 2;
        vector<long long int> set1, set2;
 
        for (long long int i = n; i >= 1; i--) {
            if (i <= target) {
                set1.push_back(i);
                target -= i;
            }
            else {
                set2.push_back(i);
            }
        }
        sort(all(set1)),sort(all(set2));
        cout << set1.size() << "\n";
        for (long long int num : set1) 
            cout << num << " ";
        cout << "\n";
 
        cout << set2.size() << "\n";
        for (long long int num : set2) 
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}