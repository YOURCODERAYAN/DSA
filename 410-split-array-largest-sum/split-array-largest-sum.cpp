class Solution {
public:
    int countofelements(vector<int>&nums,int sum){
        int n=nums.size();
         int elements=1;
        long long elementsperarray=0;

        for(int i=0;i<n;i++){
            if(elementsperarray+nums[i] <= sum){
                elementsperarray+=nums[i];
            }
            else{
                elements++;
                elementsperarray=nums[i];
            }
        }
        return elements;
    }

    int bs(vector<int>&nums,int n,int k){
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid=(low+high)/2;
        int elements=countofelements(nums,mid);
        if(elements > k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return bs(nums,nums.size(),k);
    }
};