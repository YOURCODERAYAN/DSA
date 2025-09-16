class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) 
            return false;

        unordered_map<char,char> mpp;
        unordered_map<char,char> rev;

    for(int i=0;i<s.size();i++){
        char original=s[i];
        char replacement=t[i];

    if(mpp.find(original)==mpp.end()){
        if(rev.find(replacement)!=rev.end())
                return false;
        mpp[original]=replacement;
        rev[replacement]=original;
    }
    else{
        char mappedchar=mpp[original];
        if(mappedchar!=replacement)
                return false;
        }
    }
    return true;
    }
};