class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        vector<char> p(n,1);
        p[0]=p[1]=0;
        for(int i=2;i*i<n;i++)
            if(p[i])
                for(int j=i*i;j<n;j+=i) p[j]=0;
        return accumulate(p.begin(),p.end(),0);

    }
};