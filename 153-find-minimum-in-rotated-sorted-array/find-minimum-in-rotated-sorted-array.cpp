class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        int ans=INT_MAX;// Keeping the ans variable and initialize it to INT_MAX//

        while(low <= high){
            int mid=(low+high) / 2 ;

            if(nums[low] <= nums[mid]){
                ans=min(ans,nums[low]);
                low =mid+1;
            }
            else{ // nums[mid] <= nums[high]
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};

/*// more optimized way to do if i want 
int findMin(vector<int>&nums){
    int n =nums.size();
    int low=0,high=n-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high) / 2;

        // the search space is sorted 
        // therefore the nums[low]
        // will always be the minimum in that search space 
        if(nums[low] <= nums[high]){
            ans = min(ans,nums[low]);
            break;
        }

        if(nums[low] <= nums[mid]){
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
return ans;*/

