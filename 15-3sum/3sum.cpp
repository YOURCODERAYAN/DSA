class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        // first step to sort the array 
        sort(nums.begin(),nums.end());
        // outer loop we have to go through
        for(int i=0;i<n;i++){
            //removing duplicates 
            if(i!=0 && nums[i]==nums[i-1]) continue;
            //move two pointers
            int j=i+1;
           int k=n-1;
           while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicate or can say same value from the left and right side
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
        }
        return ans;
    }
};