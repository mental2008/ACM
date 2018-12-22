o = ['one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen','twenty']
p = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
pre = 0
for i in range(1,10):
    pre = pre + len(o[i-1])
print(pre)
res = 0
for i in range(1,20):
    res = res + len(o[i-1])
print(res)
for i in range(2,10):
    res = res + len(p[i-2])*10
    res = res + pre
    # print(p[i-2])
print(res)
ans = res
for i in range(1,10):
    ans = ans + res
    ans = ans + (len(o[i-1])+len('hundred'))*100
    ans = ans + len('and')*99
ans = ans + len('onethousand')
print(ans)
