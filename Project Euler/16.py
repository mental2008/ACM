ans = 1
for i in range(1000):
    ans = ans * 2
res = 0
while ans != 0:
    res = res + ans % 10
    ans = ans // 10
print(res)