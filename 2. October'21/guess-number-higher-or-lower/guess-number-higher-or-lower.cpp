/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n) != 0) 
        {
            int start = 1; 
            int end = n+1;
            while(start<end) 
            {
                int mid = start + (end-start)/2;

                if(guess(mid)==-1) {
                    end = mid;
                }
                else if (guess(mid)==1) {
                    start = mid+1;
                }
                else if(guess(mid)==0){
                    return mid;
                }
            }
        }
        return n;
    }
};