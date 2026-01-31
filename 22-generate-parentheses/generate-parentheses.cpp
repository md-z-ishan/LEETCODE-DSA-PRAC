class Solution {
public:
    vector<string>ans;
    void generate(string &s,int open,int close,int n){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            generate(s,open+1,close,n);
            s.pop_back();
        }
        if(close<open){
             s.push_back(')');
            generate(s,open,close+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(s,0,0,n);
        return ans;
    }
};