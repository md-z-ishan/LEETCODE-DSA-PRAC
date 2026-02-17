class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        int ans = 0;

        for(auto it : mp){
            int num = it.first;

            if(mp.count(num + 1)){
                ans = max(ans, mp[num] + mp[num + 1]);
            }
        }

        return ans;
    }
};