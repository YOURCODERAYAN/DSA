class Solution {
private:
    vector<int> NSE(vector<int>&arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
             ans[i]=!st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int  i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
        ans[i]=!st.empty() ? st.top() : -1;
                st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        int sum=0;
        vector<int> ns= NSE(arr);
        vector<int> ps=PSE(arr);
    for(int i=0;i<n;i++){
        int left=i-ps[i];
        int right=ns[i]-i;
    long long freq=(left*right*1LL);
    int val=(freq* arr[i]*1LL) % mod;
        sum=(sum+val) %mod;
    }
        return sum;
    
}
};