namespace FWT
{
	const int p=998244353;
	const ll inv2=(p+1)/2;
	void fwt(vector<int> &a,int n,int f,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					ll x=a[i+j],y=a[i+j+d];
					if(!v)
					{
						if(f==1) a[i+j]=(x+y)%p,a[i+j+d]=(x-y+p)%p;//xor
						else if(f==2) a[i+j]=(x+y)%p;//and
						else if(f==3) a[i+j+d]=(x+y)%p;//or
					}
					else
					{
						if(f==1) a[i+j]=(x+y)*inv2%p,a[i+j+d]=(x-y+p)%p*inv2%p;//xor
						else if(f==2) a[i+j]=(x-y+p)%p;//and
						else if(f==3) a[i+j+d]=(y-x+p)%p;//or
					}
				}
			}
		}
	}
	
	vector<int> XOR(vector<int> a,vector<int> b)
	{
		int n,len;
		n=a.size();
		for(len=1;len<n;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		fwt(a,len,1,0);
		fwt(b,len,1,0);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*b[i]%p;
		fwt(a,len,1,1);
		return a;
	}
	vector<int> AND(vector<int> a,vector<int> b)
	{
		int n,len;
		n=a.size();
		for(len=1;len<n;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		fwt(a,len,2,0);
		fwt(b,len,2,0);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*b[i]%p;
		fwt(a,len,2,1);
		return a;
	}
	vector<int> OR(vector<int> a,vector<int> b)
	{
		int n,len;
		n=a.size();
		for(len=1;len<n;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		fwt(a,len,3,0);
		fwt(b,len,3,0);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*b[i]%p;
		fwt(a,len,3,1);
		return a;
	}
};
