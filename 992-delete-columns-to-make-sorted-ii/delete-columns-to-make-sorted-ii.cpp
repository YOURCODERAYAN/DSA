class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
            int n=strs.size();
            int m=strs[0].size();
            int res=0;
        vector<bool> is_sorted(n-1 , false);
    for(int j=0;j<m;j++){
            bool red=false;
        
        for(int i=0;i<n-1;i++){
                if(!is_sorted[i]){
                    if(strs[i][j] > strs[i+1][j]){
                        red=true;
                    break;
                }
            }
        }
        if(red){
                res++;
        }
        else{
            for(int i=0;i<n-1;i++){
                    if(strs[i][j] < strs[i+1][j]){
                        is_sorted[i]=true;
                        
                    }
            }
        }
    }
    return res;
            
    }
};