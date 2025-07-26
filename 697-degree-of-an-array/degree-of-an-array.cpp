class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> count,first,last;
        int degree=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
        // first loop for couting maximum degree//
            if(first.count(num)==0) first[num]=i;
            last[num]=i;
            count[num]++;
            degree=max(degree,count[num]);
        }
        // second loop for finding the min length subarray with same degree//
        int minlen=nums.size();
        for(auto& [num,freq]:count){
            if(freq==degree){
                minlen=min(minlen,last[num]-first[num]+1);
            }
        }
        return minlen;
    }
};