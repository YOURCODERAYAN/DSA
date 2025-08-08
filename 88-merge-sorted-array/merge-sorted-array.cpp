class Solution {
private:
    void swapIfGreater(vector<int> &nums1,vector<int>& nums2,int index1,int index2){
        if(nums1[index1]>nums2[index2]){
            swap(nums1[index1],nums2[index2]);
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //length of imaginary single array
        int len=n+m;
        //initial gap
        int gap=(len/2)+(len%2);

        while(gap>0){
            //placing of two pointers
            int left=0;
            int right=left+gap;
        while(right<len){
            //case1: when leftpointer is on arr1[] and rightpointer is on arr2[]
            if(left<m && right>=m){
                swapIfGreater(nums1,nums2,left,right-m);
            }
            else if(left>=m){
                swapIfGreater(nums2,nums2,left-m,right-m);
            }
            else{
                swapIfGreater(nums1,nums1,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;

         gap=(gap/2)+(gap%2);
    }

    for(int i=0;i<n;i++){
        nums1[m+i]=nums2[i];
    }
}
};