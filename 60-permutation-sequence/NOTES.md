```cpp
class Solution {
public:
string getPermutation(int n, int k) {
string s;
for(char c = '1'; c < '1'+n; c++) {
s+=c;
}
n = s.length();
permute(s, 0, n, k);
sort(res.begin(), res.end());
return res[k-1];
}
vector<string> res;
void permute(string&s, int idx, int n, int k) {
if (idx==n) {
// cout<<s<<endl;
res.push_back(s);
return;
}
for(int i = idx; i < n; i++) {
// if(res.size()==k) return;
swap(s[i], s[idx]);
permute(s, idx+1, n, k);
swap(s[i], s[idx]);
}
return;
}
};
```
This is the brute force method by making all the possible permutations, then sorting those and returning k-1.
TC - n! * n (for recursion, n multiple as it will be making a deep copy of each string in the ds)
Also there is the sorting of n! elements in klogk time where k is n!.
​