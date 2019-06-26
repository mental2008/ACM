def calc(x):
    cnt=0
    while x!=0:
        x=x//10
        cnt=cnt+1
    return cnt
f1=1
f2=1
index=1
while True:
    f1,f2=f2,f1+f2
    index=index+1
    if calc(f1)>=1000:
        print(index)
        break