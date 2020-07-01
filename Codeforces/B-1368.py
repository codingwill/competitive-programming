#include <bits/stdc++.h>
#
# Author: wkwkwill (Willy I. K.)
# 2020/06/18

ans = "codeforce"
s = "s"

k = int(input())
j = 1;
while (j <= k):
    if (j > 2**24):
        break
    if (j >= 2):
        s += s
    j += j

j /= 2
print("codeforce", end='')
i = 0
while (i < int(k / j)):
    print(s, end='')
    i += 1
i = 0
while (i < int(k % j)):
    print("s", end='')
    i += 1