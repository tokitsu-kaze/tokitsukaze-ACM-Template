p=init_array_1d(MAX,0)
prime=init_array_1d(MAX,0)
tot=0
def init(n):
    global tot
    n=int(n)
    tot=0
    prime[1]=1
    for i in range(2,n,1):
        if prime[i]==0:
            prime[i]=i
            p[tot]=i
            tot+=1
        for j in range(0,tot,1):
            if i*p[j]>n: break
            prime[i*p[j]]=p[j]
            if i%p[j]==0: break
