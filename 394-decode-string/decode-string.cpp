class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;
        for(char c : s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            else if(c == '['){
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }
            else if(c == ']'){
                int repeat = numStack.top();
                numStack.pop();
                string temp = curr;
                for(int i = 1; i < repeat; i++)
                    curr += temp;

                curr = strStack.top() + curr;
                strStack.pop();
            }
            else{
                curr += c;
            }
        }
        return curr;
    }
};