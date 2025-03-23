#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
 
using namespace std;
 
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, Q, l, r;
    cin >> N >> Q;
 
    int sqrt_N = sqrt(N)+1, arr[sqrt_N * sqrt_N], seg[sqrt_N+1];
    memset(arr, 0x7f7f7f7f, sizeof(arr));
    memset(seg, 0x7f7f7f7f, sizeof(seg));
 
    for(int i = 0;i < N; ++i) {
        cin >> arr[i];
        seg[i/sqrt_N] = min(seg[i/sqrt_N], arr[i]);
    }
    //for(int i=0;i<sqrt_N;++i) cout<<seg[i]<<' ';
    //cout<<'\n';
 
    while(Q--){
        cin >> l >> r; 
        --l, --r;// 0 4
        int seg_l = l / sqrt_N, seg_r = r / sqrt_N, ans = 0x7f7f7f7f;
        //cout << seg_l << ' ' << seg_r << '\n';
        if(seg_l == seg_r) {
            for(int i = l;i <= r; ++i) {
                ans = min(ans, arr[i]);
            }
        }
        else {
            for(int j = l;j <= (seg_l + 1) * sqrt_N; ++j){
                ans = min(ans, arr[j]);
            }
            for(int j = r;j >= (seg_r/* - 1*/) * sqrt_N; --j){
                ans = min(ans, arr[j]);
            }
            for(int i = seg_l+1; i < seg_r;++i){
                    ans = min(ans, seg[i]);
            }
        }
        //cout<<'\n';
        cout << ans << '\n';
    }
}