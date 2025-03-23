#include <iostream>
using namespace std;
int n, g[1005][1005], mod = 1e9 + 7;
char c;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        g[0][i] = 1;
        g[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin.ignore();
        for (int j = 1; j <= n; ++j) {
            cin >> c;
            if (c == '*') g[i][j] = 0;
            else if (i == 1) {
                g[i][j] += g[i][j - 1];
                g[i][j] %= mod;
            }
            else if (j == 1) {
                g[i][j] += g[i - 1][j];
                g[i][j] %= mod;
            }
            else {
                g[i][j] += g[i - 1][j];
                g[i][j] %= mod;
                g[i][j] += g[i][j - 1];
                g[i][j] %= mod;
            }
        }
        //cin.ignore();
    }
    cout << g[n][n];
}