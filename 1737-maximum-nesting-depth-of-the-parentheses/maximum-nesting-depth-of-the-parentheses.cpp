/*class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
    for(int i=0;i<s.length();i++){

        if(s[i]=='(') st.push(i); // now it is a stack based approach so it is taking o(n)
                                    // for time but o(n) for space complexity 
        else if(s[i]==')') st.pop();

    int size=st.size();
    ans=max(ans,size);
        }
    return ans;
    }
};*/

// we can reduce this to o(1) to space 
class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int maxi=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='(') count++;
        else if(s[i]==')') count--;
    
    maxi=max(maxi,count);
    }
    return maxi;
    }
};

