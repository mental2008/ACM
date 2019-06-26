

f1 = 1
f2 = 1
i = 3
while i <= 100:
    f1, f2 = f2, f1 + f2
    print(i, f2, f2&(f2-1), f2-(f2&(f2-1)))
    i = i + 1