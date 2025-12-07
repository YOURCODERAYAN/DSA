class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int size=nums.size();
            if(size==0){
                    return 0;
            }
                int odd_cnt=0;
        for(auto arr : nums){
                if(arr%2!=0){
                        odd_cnt++;
                }
            }
        if(odd_cnt%2==0){
                return size-1;
        }
        else{
                return 0;
        }
        
    }
};