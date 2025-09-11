class Solution {
public:
    int ball(vector<int>&nums ){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    long long splitsneeded(vector<int>& nums, int maxSize) {
        long long maxx=0;
        for(int i=0;i<nums.size();i++){
            maxx+=(nums[i]-1) / maxSize;
        }
        return maxx;
    }

    int minimumSize(vector<int>& nums, int maxOperations){
        int low=1 , high=ball(nums);
        while(low<=high){
            int mid=(low+high)/2;
            long long val=splitsneeded(nums,mid);
        if(val <= maxOperations ){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        }
        return low;
    }
};