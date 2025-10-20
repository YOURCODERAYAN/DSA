class Solution {
/*public:
    bool isPowerOfTwo(int n) {
        if(n==1)return true;
        if(n==0||n%2!=0)return false;
        return isPowerOfTwo(n/2);
    }*/

public:
    bool isPowerOfTwo(int n){
    

        if( n  > 0 && (n&(n-1))==0){
            return true;
        }
        else{
            return false;
        }
    }
};