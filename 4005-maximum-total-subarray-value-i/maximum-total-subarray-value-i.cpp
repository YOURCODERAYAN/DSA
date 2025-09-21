class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n =nums.size();
        long long maxi;
        long long mini;
    sort(nums.begin(),nums.end());

    maxi=*max_element(nums.begin(),nums.end());
    mini=*min_element(nums.begin(),nums.end());
    long long val= k * (maxi-mini);
    return val;
    }
};