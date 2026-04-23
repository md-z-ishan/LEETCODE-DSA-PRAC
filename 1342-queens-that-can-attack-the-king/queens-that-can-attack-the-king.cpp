class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        set<pair<int,int>> st;
        for(auto &q : queens) {
            st.insert({q[0], q[1]});
        }
        
        vector<vector<int>> ans;
        
        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };
        
        for(auto &d : dir) {
            int x = king[0];
            int y = king[1];
            
            while(x >= 0 && y >= 0 && x < 8 && y < 8) {
                x += d.first;
                y += d.second;
                
                if(st.count({x,y})) {
                    ans.push_back({x,y});
                    break;
                }
            }
        }
        
        return ans;
    }
};