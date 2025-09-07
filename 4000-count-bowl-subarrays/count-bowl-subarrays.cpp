class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long count=0;
        int n=nums.size();
        stack<int> st; // declaring the stack // here monotonic stack 
    for(int right=0;right<n;right++){
        while(!st.empty()  && nums[st.top()] <= nums[right]){
            int left=st.top();
            st.pop();
            if(right-left+1 >= 3){
                count++;
            }
        }
    if(!st.empty() && (right - st.top()+1)>=3){
        count++;
     }
     st.push(right);
    }
    return count;
    }
};