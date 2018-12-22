ans = 0
with open("13.in") as f:
    for line in f.readlines():
        res = int(line)
        ans = ans + res
print(ans)