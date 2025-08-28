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

// 