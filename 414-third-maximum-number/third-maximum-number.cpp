class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long max1=LONG_MIN,  max2=LONG_MIN , max3=LONG_MIN;

            for(int i=0 ; i < n ; i++){
                if(max1 < nums[i]){
                    max3 = max2;
                    max2 = max1;
                    max1 = nums[i];
                }
                else if(max2 < nums[i] && nums[i]!=max1){
                    max3 = max2;
                    max2 = nums[i];
                }
                else if(max3 < nums[i]  && nums[i]!=max2 && nums[i]!=max1){
                    max3 = nums[i];
                } 
            }
             return (max3==LONG_MIN) ? max1 : max3;
    }
};