class Solution {
public:
    int BS(vector<int>&nums,int low,int high,int target){

        // base case 
        if(low> high) return -1;

        // main condition 
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(target > nums[mid])
            return BS(nums,mid+1,high,target);
        return BS(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        return BS(nums,0,nums.size()-1,target);
    }
};