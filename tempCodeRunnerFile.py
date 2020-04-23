def bigPow(x, y): 
    MOD = 1e9 + 7
    if (y == 0): 
        return 1
    if (y % 2 == 1): 
        return ((x * bigPow(x, y-1))) % MOD
    t = bigPow(x, y/2)
    return (t * t) % MOD

MOD = 1e9 + 7
t = int(input())
while (t > 0):
    n, a = input().split()
    n = int(n)
    a = int(a)
    red = a
    count = 0
    bef = a
    sum = red
    i = 2
    while (i <= n):
        count = 2*i - 1
        red = red * bef
        bef = red
        red = bigPow(red, count)
        sum = (sum + red) % MOD
        i += 1
    print(int(sum))
    t -= 1