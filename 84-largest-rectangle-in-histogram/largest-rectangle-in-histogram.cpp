class Solution {
private:
    vector<int> find_NSE(vector<int>&heights){

    int n=heights.size();
    stack<int> st;
    vector<int> nse_ind(n,n);
    for(int i=n-1;i>=0;i--){
        int curr_ele=heights[i];
    while(!st.empty() && heights[st.top()] >= curr_ele)
        st.pop();
    nse_ind[i]=!st.empty() ? st.top() : n;
        st.push(i);
    }
    return nse_ind;
    }

    vector<int> find_PSE(vector<int>&heights){
        int n=heights.size();
        stack<int> st;
        vector<int> pse_ind(n,-1);
    for(int i=0;i<n;i++){
        int curr_ele=heights[i];
        while(!st.empty() && heights[st.top()] > curr_ele)
            st.pop();
        pse_ind[i] = !st.empty()  ? st.top() : -1;
        st.push(i);
    }
    return pse_ind;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> ns=find_NSE(heights);
        vector<int> ps=find_PSE(heights);   
        int maxi=0;
        for(int i=0;i<n;i++){
        maxi=max(maxi,heights[i] * ( ns[i] - ps[i] -1));
    }
    return maxi;
}
};