/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak( MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=0 ,high= n-1;
        while(low < high){
        int mid=(low+high)/2;
    if(mountainArr.get(mid)< mountainArr.get(mid+1))
            low=mid+1;
    else
        high=mid;
        }

    return low;
    }

    // now  for the asecding slope
    int ascending(MountainArray &mountainArr , int low, int high,int target ){
        while(low<=high){
            int mid=(low+high)/2;
        if(mountainArr.get(mid)==target) 
                return mid;
        else if(mountainArr.get(mid) < target){
                low=mid+1;
        }
        else {
            high=mid-1;
        }

        }
        return -1;
        }

    int desecding (MountainArray &mountainArr , int low , int high, int target){
        while(low<=high){
            int mid=(low+high)/2;
        if(mountainArr.get(mid)==target)
                return mid;
        else if(mountainArr.get(mid) > target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n= mountainArr.length();
    int peakelements=peak(mountainArr);
    int index=ascending(mountainArr,0,peakelements,target);
    if(index!=-1) return index;
    return desecding(mountainArr, peakelements+1,n-1,target);
    }
};