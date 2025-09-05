class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();// size of first array vector
        int n2=nums2.size();// size of second array vector
        // if we have to check 
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int n=n1+n2;

        int left=(n1+n2+1)/2; // length of the left part of the symmetry
        // after this we can apply binary search
        int low=0,high=n1;

        while(low <= high){

        int mid1=(low+high) >> 1;
        int mid2=left-mid1;
        // now from this step we have to calculate 
        // l1,l2,r1,r2

        int l1=INT_MIN,l2=INT_MIN;// assinging by default values for l1 and l2
        int r1=INT_MAX,r2=INT_MAX;// assinging by default values for r1 and r2

        if(mid1< n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];

        if(mid1 - 1 >= 0) l1=nums1[mid1-1];
        if(mid2 - 1 >= 0) l2=nums2[mid2-1];

        if(l1 <= r2 && l2 <=r1){
            if(n%2==1) return max(l1,l2);
            return ((double) (max(l1,l2) + min(r1,r2))) /2.0;
        }
        else if
            (l1 > r2) high=mid1-1;

        else
            low=mid1+1;
        }
      
      return 0;
    
    }
    
};