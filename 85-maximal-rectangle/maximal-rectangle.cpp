class Solution {
private:
    vector<int> NSE(vector<int>&arr){
        int n=arr.size();
    stack<int> st;
    vector<int> ans(n,n);
    for(int i=n-1;i>=0;i--){
        int curr_ele=arr[i];
    while(!st.empty() && arr[st.top()] >= curr_ele)
        st.pop();
    ans[i]=!st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
    }

    vector<int> PSE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int curr_ele=arr[i];
        while(!st.empty() && arr[st.top()] > curr_ele)
            st.pop();
    ans[i]=!st.empty() ? st.top() :-1;
            st.push(i);
        }
        return ans;
    }

    int histogram(vector<int> & arr){
        int n=arr.size();
        vector<int> ns=NSE(arr);
        vector<int> ps=PSE(arr);
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi , arr[i] * (ns[i] - ps[i] -1));
    }
    return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m =matrix[0].size();
    vector<int> height(m,0);
        int max_Area=0;
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
                height[j]+=1;
            }
            else{
                height[j]=0;
            }
        }
        int curr_area=histogram(height);
        max_Area=max(max_Area , curr_area);
    }
    return max_Area;
    }
};