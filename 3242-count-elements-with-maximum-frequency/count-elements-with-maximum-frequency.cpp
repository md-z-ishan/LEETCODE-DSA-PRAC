#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int maxFreq = 0, total = 0;

        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                total = maxFreq;
            } 
            else if (freq[num] == maxFreq) {
                total += maxFreq;
            }
        }
        return total;
    }
};
