class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        
       
        while (ss >> word) {
            words.push_back(word);
        }
        
        
        if (pattern.length() != words.size()) return false;
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern[i];
            string w = words[i];
            
            
            if (charToWord.count(p)) {
                if (charToWord[p] != w) return false;
            } else {
                charToWord[p] = w;
            }

            if (wordToChar.count(w)) {
                if (wordToChar[w] != p) return false;
            } else {
                wordToChar[w] = p;
            }
        }
        
        return true;
    }
};
