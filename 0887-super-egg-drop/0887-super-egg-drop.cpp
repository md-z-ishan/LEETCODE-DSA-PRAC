class Solution {
public:
    int dp[101][10002];
    int solve(int e, int f) {
        if (e == 1)
            return f;
        if (f == 0 || f == 1)
            return f;
        if (dp[e][f] != -1) {
            return dp[e][f];
        }
        int left = 1;
        int right = f;
        int ans = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int broke = solve(e - 1, mid - 1);
            int nbroke = solve(e, f - mid);
            int temp = 1 + max(broke, nbroke);
            ans = min(ans, temp);
            if (broke < nbroke) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int k, int n) { 
        memset(dp,-1,sizeof(dp));
        return solve(k, n); 
        }
};