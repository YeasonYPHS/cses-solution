#include <cstdio>
#include <cstdint>
#define MOD 1000000007
main() {
    int_fast64_t N, i=7, dp[7] = { 1,1,2,4,8,16,32 }, sum = 1;
    scanf("%lld",&N);
    for (;i<=N;++i) dp[i % 7] = ((dp[(i + 6) % 7]<<1) - dp[i % 7] + MOD) % MOD;
    printf("%lld", dp[N % 7]);
}