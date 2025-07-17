class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i=0;i<nums.size();i++){
        int num=nums[i];
        strs.push_back(to_string(num));
        }
        sort(strs.begin(),strs.end(),[](string a,string b){
            return a+b > b+a;
        });
        if(strs[0]=="0") 
        {
            return "0";
        }
        string result="";
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            result+=s;
        }
        
        return result;
    }
};