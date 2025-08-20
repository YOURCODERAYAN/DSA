class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // declaring of list of list
        vector<vector<int>> ans;
        // using of simple next permutaion STL

        sort(nums.begin() , nums.end());

        do{
             ans.push_back(nums);
        }
        while(next_permutation(nums.begin() , nums.end()));
         return ans;
    }
};