class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end());

        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);

        for(int num : nums){
            for(int i = n / 2; i >= 1; i--){
                for(int s : dp[i - 1]){
                    dp[i].insert(s + num);
                }
            }
        }

        for(int k = 1; k <= n / 2; k++){
            if((sum * k) % n == 0){
                if(dp[k].count((sum * k) / n)){
                    return true;
                }
            }
        }

        return false;
    }
};
