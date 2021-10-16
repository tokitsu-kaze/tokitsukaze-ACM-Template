class DSU:
    def __init__(self):
        pass
    
    def init(self,n):
        self.pre=[i for i in range(n+1)]
    
    def find(self,x):
        if self.pre[x]!=x: self.pre[x]=self.find(self.pre[x])
        return self.pre[x]
    
    def merge(self,a,b):
        ra=self.find(a)
        rb=self.find(b)
        if ra!=rb:
            self.pre[ra]=rb
            return 1
        return 0