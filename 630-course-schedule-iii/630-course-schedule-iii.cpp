class Solution {
public:
    struct myComp {
        constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
            const noexcept
        {
            return a.first < b.first;
        }
    };
    
    static bool comp(vector<int>a, vector<int>b){
        return a[1]<b[1];
        
    }
    int scheduleCourse(vector<vector<int>>& c) {
        
        sort(c.begin(), c.end(), comp);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp>pq;
        
        int res = 0, totTime = 0; 
        for(int i = 0; i < c.size(); i++) {
            if(c[i][0]>c[i][1]) continue;
            
            if(totTime+c[i][0] <= c[i][1]) {
                pq.push({c[i][0], c[i][1]});
                totTime += c[i][0];
                res += 1;
            }else if(pq.size()){
                cout<<i<<endl;
                auto top = pq.top(); 
                if(top.first > c[i][0]){
                    pq.pop(); 
                    totTime -= top.first;
                    
                    pq.push({c[i][0],c[i][1]});
                    totTime += c[i][0];
                }else continue;
            }
        }
        
        return res;
    }
};