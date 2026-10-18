class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();
        for(int i = 0;i<k;i++){
            bool isLeft = (i==0 || flowerbed[i-1]==0);
            bool isRight  = (i == k-1 || flowerbed[i+1] == 0);
            if(isLeft && isRight && flowerbed[i]==0){
                flowerbed[i] = 1;
                n--;
            }
            if(n<=0){
                return true;
            }
        }
        return n<=0;
    }
};