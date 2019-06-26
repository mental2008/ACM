n=100
res=1
for i in range(1,n+1):
    res=res*i
ans=0
while res != 0:
    ans=ans+res%10
    res=res//10
print(ans)