class Solution {
public:
    bool check(int n){
        int temp = n;
        while(temp>0){
            int d = temp%10;
            if(d==0 || n%d!=0) return false;
            temp/=10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(check(i)) ans.push_back(i);
        }
        return ans;
    }
};