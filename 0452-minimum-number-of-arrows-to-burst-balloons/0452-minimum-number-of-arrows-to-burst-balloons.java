
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1] , b[1]));
        
        int n = points.length;
        int res = 0; 
        
        int start, end; 
        for(int i = 0; i < n; i++) {
            start = points[i][1];
            while(i<n-1 && start>=points[i+1][0]) i++;
            res++;
        }
        
        return res; 

    }
}