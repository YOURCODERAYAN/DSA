class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;//initialization of counter variable cnt1 and cnt2
        int el1=INT_MIN;// initialization of elements el1 and el2
        int el2=INT_MIN;

        // applying algorithm of n/2 but slightly extending some conditions

        for(int i=0;i<n;i++){
            if(cnt1==0  && el2!=nums[i]){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i]){
                cnt2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else{
                cnt1--,cnt2--;
            }
        }

        vector<int> ls ; // list of answers
        // manually checking if the stored elements
        // in el1 and el2 are the majority ones or not 
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
        }
        int mini=int(n/3)+1;
        if(cnt1>=mini) ls.push_back(el1);
        if(cnt2>=mini) ls.push_back(el2);
        return ls;
    }
};