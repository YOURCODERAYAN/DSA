class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
            vector<int> ans(n);
            stack<int> st;
    for(int i=2*n-1 ;i>=0;i--){ // start iterating from 2*n-1 means the hypothetical array last index 
        int ind=i%n; // to  find the cyclic array index //
        int curr_ele=nums[ind];
    while(!st.empty() && st.top()<= curr_ele){
            st.pop();
    }
    if(i<n){ // now if our curr index value is less than the array size
        // or we can say that we are in the range of our actual array size
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }

    }
    st.push(curr_ele);
}
return ans;
    }
};