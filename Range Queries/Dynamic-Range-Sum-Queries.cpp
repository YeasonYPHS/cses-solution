#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#include <cstdio>
#include <cstdint>
#define int uint_fast64_t
static char _i[1 << 24], _o[1 << 24], _, __[16]; int _i0, _o0;
inline void in(int &x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x*10 + (_ & 15)); }
inline void out(int x) { _ = 0; do { __[_++] = x % 10 | '0'; } while (x *= 0.1); while (_--) _o[_o0++] = __[_]; _o[_o0++] = '\n'; }
using namespace std;
const int N = 200005;
int n, m, tree[N<<1], arr[N];
void build(int arr[]){
    for (int i = 0; i < n; ++i)
        tree[n + i] = arr[i];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
void update(int p, int value){
    tree[p + n] = value;
    p+=n;
    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}
int query(int l, int r){
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l & 1)
            res += tree[l++];
        if (r & 1)
            res += tree[--r];
    }
    return res;
}
signed main() {
    fread(_i, 1, 1 << 24, stdin);
    int op, a, b, u;
    in(n);in(m);
    for (int i = 0;i < n;++i) in(arr[i]);
    build(arr);
    while (m--) {
        in(op);in(a);in(b);
        if (op == 1) update(a-1, b);
        else out(query(a-1, b));
    }
    fputs(_o, stdout);
}