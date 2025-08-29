class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]; // if single  element present in the array 
        // just writing manually for first and last element of the array
        // to prevent such kind of conditions
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1,high=n-2;

        // now perform simple binary search 
        while(low <= high){
            int mid=(low+high)/2;            
        
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
            return nums[mid];
        }
        //even odd concept apply 
        if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
    }
};