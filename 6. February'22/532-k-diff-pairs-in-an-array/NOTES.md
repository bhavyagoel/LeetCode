if(temp[num]) {
res += 1;
while(i<n and num == nums[i]) i++;
i--;
}
temp[num] = 1;
}
}
else {
for(int i = 0; i < n; i++) {
int num = nums[i];
int check = k + num;
res += temp[check];
if(temp[check]) temp[check]--;
cout<<res<<" ";
check = num-k;
res += temp[check];
if(temp[check]) temp[check]--;
cout<<res<<" ";
if(num!=k) {
check = num-k;
res += temp[check];
if(temp[check]) temp[check]--;
}
cout<<res<<endl;
temp[num] = 1;
}
}
return res;
}
};
```
​
Here for 0 it is counted twice like (3,0) and (0,3).