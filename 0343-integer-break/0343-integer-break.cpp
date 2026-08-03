class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n + 1, 0);

        dp[1] = 0;

        for(int i = 2; i <= n; i++) {

            for(int j = 1; j < i; j++) {

                dp[i] = max(dp[i],
                            max(j * (i - j),
                            max(dp[j] * (i - j),
                            max(j * dp[i - j],
                                dp[j] * dp[i - j]))));
            }
        }

        return dp[n];
    }
};