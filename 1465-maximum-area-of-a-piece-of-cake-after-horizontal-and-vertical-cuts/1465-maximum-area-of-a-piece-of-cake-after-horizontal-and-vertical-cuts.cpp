class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(vc.begin(), vc.end()); 
        sort(hc.begin(), hc.end());
        
        int maxh = max(hc[0]-0, h - hc.back());
        for(int i = 1; i < hc.size(); i++) {
            maxh = max(maxh, hc[i] - hc[i-1]);
        }
        
        int maxw = max(vc[0]-0, w - vc.back());
        for(int i = 1; i < vc.size(); i++) {
            maxw = max(maxw, vc[i] - vc[i-1]);
        }
        long long modulo = 1e9+7;
        return ((long long)maxh*(long long)maxw)%modulo;
    }
};