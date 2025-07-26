class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int left_Total=0;

        for(int i=0;i<nums.size();i++){
            int right_Total=total-left_Total-nums[i];
            if(right_Total==left_Total){
                return i;
            }
            left_Total+=nums[i];
        }
        return -1;
    }
};