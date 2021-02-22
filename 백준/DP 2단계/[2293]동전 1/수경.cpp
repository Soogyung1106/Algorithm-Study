#include <cstdio>

int main() {
    int n, k;
    int coins[101];
    int dp[10001] = {0};

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }
    
    dp[0] = 1;

    for (int i = 1; i <= n; i++) { //사용할 동전
        for (int j = 1; j <= k; j++) { //j원을 만드는 경우
            if (j >= coins[i]) {
                dp[j] += dp[j-coins[i]]; 
                // 1원을 가지고 1원....10원을 만드는 경우
                // 2원을 가지고 1원....10원을
                // 5원을 가지고 
                // dp[10원을 만드는 경우] += dp[9(10-1원을 사용)]
            }
        }
    }

    printf("%d\n", dp[k]);

    return 0;
}
