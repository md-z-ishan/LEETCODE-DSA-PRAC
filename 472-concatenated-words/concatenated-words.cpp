class Solution {
public:
    
    bool canForm(string word, unordered_set<string>& dict) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(!dp[j]) continue;
                if(dict.count(word.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> result;

        for(string word : words){
            dict.erase(word);
            if(canForm(word, dict)){
                result.push_back(word);
            }
            dict.insert(word);
        }

        return result;
    }
};
