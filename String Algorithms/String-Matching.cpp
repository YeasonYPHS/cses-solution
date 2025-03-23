#include <iostream>
using namespace std;
int f[1000005], ans;
string s, t;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> s >> t;
    f[0] = -1;
    for (int i = 1; i < t.length(); i++){
        int nxt = f[i-1];
        while (nxt != -1 && t[nxt+1] != t[i]){
            nxt = f[nxt];
        }
        if (t[nxt+1] == t[i]) nxt++;
        f[i] = nxt;
    }
    int pos = -1;
    for (int i = 0; i < s.length(); i++){
        while (pos != -1 && s[i] != t[pos+1]){
            pos = f[pos];
        }
        if (s[i] == t[pos+1]) pos++;
        if (pos == t.length()-1){
            ans++;
            pos = f[pos];
        }
    }
    cout << ans << "\n";
}