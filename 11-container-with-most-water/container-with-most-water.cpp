class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxwater=0;
        while(left<right){
            int h=min(height[left],height[right]);
            int w=right-left;
            maxwater=max(maxwater,h * w);

            //move the pointer pointing to the shorter  line
            if(height[left]<height[right])
                left++;
            
            else
                right--;

        }
        return maxwater;
    }
};