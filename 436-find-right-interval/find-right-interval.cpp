class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> starts ; // storing {start,ind}
        for(int i=0;i<n;i++) {
            starts.emplace_back(intervals[i][0] , i);
        }
        sort(starts.begin(),starts.end()); // sort the start

        vector<int> res;
        for(auto interval: intervals ){
            int end=interval[1];
            int low=0 , high=n-1;
            int index=-1;
            while(low<=high){
                int mid=(low+high)/2;
            if(starts[mid].first >= end){
                index=starts[mid].second;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            }
            res.push_back(index);
        }
        return res;
    }
};