#AUTHOR: wkwkwill
#2020/06/13

t = int(input())

for i in range(0, t):
    arr = input()
    arr = arr.split()
    a = int(arr[0])
    b = int(arr[1])
    ans = min(max(a*2, b), max(a, b*2))**2
    print(ans)