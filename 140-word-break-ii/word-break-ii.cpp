class Solution {
public:
    unordered_map<int, vector<string>> dp;
    unordered_set<string> dict;

    vector<string> solve(string &s, int start){
        
        if(dp.count(start)) return dp[start];

        vector<string> res;

        if(start == s.size()){
            res.push_back("");
            return dp[start] = res;
        }

        string word;

        for(int i = start; i < s.size(); i++){
            word += s[i];

            if(dict.count(word)){
                vector<string> temp = solve(s, i + 1);

                for(string t : temp){
                    if(t == "")
                        res.push_back(word);
                    else
                        res.push_back(word + " " + t);
                }
            }
        }

        return dp[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string w : wordDict) dict.insert(w);
        return solve(s, 0);
    }
};