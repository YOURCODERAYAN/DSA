class Solution {
public:
    int reverse_a(int n){
        int revN=0;
    while(n > 0){
        int lastdi=n%10;
        n=n/10;
    revN=(revN*10)+lastdi;
    }
    return revN;
    }
public:
    int mirrorDistance(int n) {
        int mirrior=abs(n-reverse_a(n));
    return mirrior;
    }
};