/*class Solution {
public:
    int finddays(vector<int>& weights,int capacity){
        int n=weights.size();
        int day=1; // we are taking first case means day 1 
        int load=0;// in that day in the preliminary state the load will be 0
        for(int i=0;i<n;i++){
            if(load+weights[i] > capacity){
                day+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
         return day;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // we have to calculate range of this problem
        // we have to find maximum and we have to find the sum of all elements in the array

        int maxi=*max_element(weights.begin(), weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);

        // we have to do a traversal from [max.... to sum of all elements]
        for(int i=maxi;i<=sum;i++){
            // condition 
            if(finddays(weights,i) <= days ){
                return i;
            }
        }
        return -1;
        
    }
};*/

class Solution {
public:
    int finddays(vector<int>& weights,int capacity){
        int n= weights.size();
        int day=1;
        int load=0;

        for(int i=0;i<n;i++){
            if(load+weights[i] > capacity){
                day+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=(low+high)/2;

        int numofdays=finddays(weights,mid);

            if(numofdays <= days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

