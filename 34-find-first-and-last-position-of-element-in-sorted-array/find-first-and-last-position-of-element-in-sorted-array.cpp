/*class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        int ans=n;

        while(low <= high){
            int mid=(low+high) /2 ;
            if(nums[mid] >= target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    int upper_bound(vector<int> &nums ,int target){
        int n=nums.size();
        int low=0,high=n-1;

        int ans=n;

        while(low <=high){
            int mid=(low+high) /2;
            if(nums[mid] > target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target){
        int n=nums.size();
        int lb=lower_bound(nums,target);
        int ub=upper_bound(nums,target);
        if(lb==n || nums[lb]!=target) return {-1,-1};
        else{

        
         return {lb,ub-1};
       }
    }
};*/

// if i add normal binary search approach 
class Solution {
public:
int first_occurance(vector<int> &nums,int target){
    int n=nums.size();
    int first=-1;
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+high) /2 ;
        if(nums[mid]==target){
        first=mid;
        high=mid-1;
        }

        else if(nums[mid] < target) 
            low=mid+1;

        else
            high=mid-1;
    }
    return first;
}

int last_occurance(vector<int> &nums ,int target){
    int n=nums.size();
    int last=-1;
    int low=0 ,high=n-1;

    while(low <=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            last=mid;
            low=mid+1;
        }
        else if(nums[mid] < target)
            low=mid+1;

        else
            high=mid-1;
        
    }
    return last;
}

vector<int> searchRange(vector<int>&nums,int target){
    int n=nums.size();
    int first=first_occurance(nums,target);
    if(first==-1) return{-1,-1};
    int last=last_occurance(nums,target);
    return {first,last};
}
};
