if(res<diff) {
res = diff;
seat = (i+prev)/2;
}
prev = i;
}
}
if (seats[lst]==false) {
while(seats[lst] != 1 and lst>0) {
lst--;
}
if(res<(n-lst-1)) {
res = (n-lst-1);
seat = n-1;
}
}
seats[seat] = true;
checkAny += 1;
return seat;
}
```
### O (logn)