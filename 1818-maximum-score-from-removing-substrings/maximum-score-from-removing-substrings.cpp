class Solution {
public:
    int getscore(string &s,char a,char b,int points){
        stack<char> st;
        int score=0;
        for(char ch:s){
            if(!st.empty() && st.top()==a && ch==b){
                st.pop();
                score+=points;
            }
            else{
                st.push(ch);
            }
        }
        s=" ";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return score;
    }
    int maximumGain(string s, int x, int y) {
        int total=0;
        if(x>y){
            total+=getscore(s,'a','b',x);
            total+=getscore(s,'b','a',y);
        }
        else{
            total+=getscore(s,'b','a',y);
            total+=getscore(s,'a','b',x);
        }
        return total;
    }
};