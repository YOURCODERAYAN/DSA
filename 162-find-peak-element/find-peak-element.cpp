class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0; // if only one single element present in the array
        // now manually checking for the very first and last element of the array

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low=1,high=n-2;

        // now simply performing the binary search algorithm 
        while(low <= high){
            int mid=(low+high) /2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            // now this part we have to check in which slope of the graph 
            // the mid relies depend upon that we have to found peak element 
            else if(nums[mid] > nums[mid-1]){
                low=mid+1;
            }
            else if (nums[mid] > nums[mid+1]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};