class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ContentChildren=0;
        int Cookieindex=0;
        while(Cookieindex<s.size() && ContentChildren < g.size()){
            if(s[Cookieindex] >= g[ContentChildren]){
            ContentChildren++;
        }
        Cookieindex++;
    }
    return ContentChildren;
    }
};