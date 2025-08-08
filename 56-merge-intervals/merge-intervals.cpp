class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //sort the array (if it is not sorted)
        sort(intervals.begin(),intervals.end());
        //declaring of an empty list
        vector<vector<int>> ans;
        // the loop for traversing the whole array
        for(int i=0;i<n;i++){
            //case 1:
            if(ans.empty()|| intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            // case2:
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};