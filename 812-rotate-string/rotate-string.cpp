class Solution {
public:

    void rotateanticlockwise(string&s){
        char c=s[0];
        int index=1;
        while(index < s.size()){
            s[index-1]=s[index];
            index++;
        }
        s[s.size()-1]=c;
    }
    bool rotateString(string s, string goal) {

        if(s.size()!=goal.size()){
            return false;
        }
        if(s==goal) return true;

        for(int i=1;i<s.size();i++){

        rotateanticlockwise(s);
            if(s==goal) return true;
        
        }
        return false;
    }
};