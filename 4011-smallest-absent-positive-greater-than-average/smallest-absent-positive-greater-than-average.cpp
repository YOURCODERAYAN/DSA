class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg =0; // for taking out the avg of nums
    
    map<int,int> mpp; // declaring map 
            for(int i:nums){
                    avg+=i;
                    mpp[i]++;
                }
        int n=nums.size();
        avg/=n;
        for(int i=max(avg+1,1) ;i<=101;i++){
            if(mpp.find(i)==mpp.end()){
                return i;
            }
        }
        return -1;
    }
};