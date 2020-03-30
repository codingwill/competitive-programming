a = 54500

limapuluh = a // 50000
duapuluh = (a % 50000) // 20000
sepuluh = (a % 20000) // 10000 
lima = (a % 10000) // 5000
dua = (a % 5000) // 2000
seribu = (a % 2000) // 1000
limaratus = (a % 1000) // 500
duaratus = (a % 500) // 100
seratus = (a % 200) // 100

print(limapuluh,"x 50k");
print(duapuluh, "x 20k");
print(dua, "x 1k");
print(limaratus, "x 500");