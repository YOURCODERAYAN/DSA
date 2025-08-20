class Solution {
public:
    void  nextPermutation(vector<int>& nums) {
        int n =nums.size();

        // Step 1: found the break point 
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                index=i;
                break;
            }
        }

        // Step 2: Edge case if no break point found 
        if(index==-1){
        // reverse the whole array
            reverse (nums.begin() , nums.end());
            return ;
        }

        // Step 3: If break point found then found 
        // the next greater element 
        for(int i=n-1;i>index;i--){
            if(nums[i] > nums[index]){
                swap(nums[i] , nums[index]);
                break;
            }
        }

        // Step 4: reverse the rest i+1 to n-1 elements 
        // in the array
        reverse(nums.begin()+index+1 , nums.end());
        return ;
    }
};