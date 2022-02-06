class Solution {
public:
    bool canEat(vector<int>&piles , int givenSpeed , long long int hours){
    // bananas eat per hour is givenSpeed 
        int tot = 0;
        for(int it : piles){
            tot += it/givenSpeed + (it%givenSpeed != 0);
        }
        return tot <= hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // eat all bananas in h hours 
        int n = piles.size();
        int minSpeed = 1;       
        int maxSpeed = *max_element(piles.begin(), piles.end());
        
        while(maxSpeed >= minSpeed ){
            int givenSpeed = minSpeed + (maxSpeed - minSpeed)/2;
            if(canEat(piles , givenSpeed , h)){
                maxSpeed = givenSpeed-1;
            }
            else{
                minSpeed = givenSpeed+1;
            }
        }

        return minSpeed;
    }
};