class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }

    //     int left = 0;
    //     int right = s.size() - 1;

    //     while (left < right) {
    //         swap(s[left], s[right]);
    //         left++;
    //         right--;
    //     }
     }
};
