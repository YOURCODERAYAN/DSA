class Solution {
public:
    void Reverse(vector<int> &nums,int start,int end){
        while(start <= end ){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(k==0) return ;

        Reverse(nums,0,n-k-1);
        Reverse(nums,n-k,n-1);
        Reverse(nums,0,n-1);
    }


};