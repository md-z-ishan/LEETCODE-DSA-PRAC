class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
      int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        int diff = mx - mn;
        if(diff <= 2*k) return 0;
        return diff - 2*k ;
    }
};