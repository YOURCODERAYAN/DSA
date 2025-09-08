/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return -1;
    }
};*/

/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
        long long  xorr=nums[i]^nums[j];
            if(xorr==0){
                return nums[i];
            }
        }
    }
       
    return -1;
    }
};*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1 , high=nums.size()-1;
        int ans=-1;

        while(low <= high){
            int mid=(low+high)/2;
            int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] <= mid)
                cnt++;
        }

        if(cnt > mid){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        }
        return ans;
    }

};

