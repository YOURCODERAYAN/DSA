class Solution {
public:

    int mincount(vector<int>&freq){
       int minCount=INT_MAX;
        for(int count: freq){
            if(count!=0){
                minCount=min(minCount, count);
            }
        }
        return minCount;
    }

    int maxcount(vector<int>&freq){
       int  maxCount=0;
        for(int count:freq){
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
    int beautySum(string s) {
        int sum=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int beauty=maxcount(freq) - mincount(freq);
                sum+=beauty;
            }
        }
        return sum;
    }
};