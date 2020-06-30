
Ini baru ngedeteksi fraud atau enggaknya
#1.Bikin set Shop (distinct shop)
#2 Iterate shopid
#3 If set found -> iterate each index of that unique shopid (assign starting time)
#4 assign ( current time - starting time) every i+1 index untul > 1 hour, then cek concent time rule
#5 if true (fraud) then remove set and move to next shopid, else balik ke #4
#6 add to shop list (yang buat disubmit)