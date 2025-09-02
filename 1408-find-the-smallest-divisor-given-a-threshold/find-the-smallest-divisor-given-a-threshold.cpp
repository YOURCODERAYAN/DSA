/*class Solution {
public:
// this is Brute Force approach 
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(); // this is the size of the array 

        int maxi=*max_element(nums.begin(),nums.end()); // finding maxi bceause the divisor range is [1...max(nums[i])]

        for(int d=1;d<=maxi;d++){
            int sum = 0; // initializeing sum to zero becausde we have to find the min value or we can say min divisor

        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i] / (double) d);
        }
            if(sum <= threshold){
                return d;
            }
        }
        return -1;
    }
};*/
class Solution {
public:
// Optimal Solution  using Binary Search 
    // first we have to take out the sum by doing  the calculation
int sum(vector<int>&nums,int div){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double) nums[i] / (double) div);
    }
    return sum;
}

// now implement binary search
int smallestDivisor(vector<int>& nums, int threshold){
    int n=nums.size();

    int low=1,high=*max_element(nums.begin(),nums.end());

    while(low <= high){
        int mid=(low+high)/2;

        if(sum(nums,mid) <= threshold ){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
} 
};
