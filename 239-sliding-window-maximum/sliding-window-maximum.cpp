class Solution {
/*public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<int> ans;
    for(int i=0;i<=n-k;i++){
           int curr_max=nums[i];
        for(int j=i;j<=i+k-1 ;j++)
            curr_max=max(curr_max , nums[j]);
       
        ans.push_back(curr_max);
    }
    return ans;
    }
}; //simple brute force solution */

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n=nums.size();
            vector<int> ans ;
            deque<int> dq;

    for(int i=0;i<n;i++){

        if(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <=nums[i])
            dq.pop_back();

    dq.push_back(i);
    if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
    }
};


