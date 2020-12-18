n = int(input())
ans = 1
if n == 2:
    print(3)
elif n == 3:
    print(7)
else:
    while n > 2:
        ans *= n
        n -= 1
    print(ans + 1)