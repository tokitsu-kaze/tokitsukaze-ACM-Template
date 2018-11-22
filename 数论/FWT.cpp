//FWT
namespace FWT
{
	ll inv2;//2对p的逆元 
	const ll p=1e9+7;
	ll pow2(ll a,ll b)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
	void fwt(ll *a,int n,int f,int v)
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
	
	//结果存在a 
	void XOR(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,1,0);
		fwt(b,len,1,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		inv2=pow2(2,p-2);
		fwt(a,len,1,1);
	}
	void AND(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,2,0);
		fwt(b,len,2,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		fwt(a,len,2,1);
	}
	void OR(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,3,0);
		fwt(b,len,3,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		fwt(a,len,3,1);
	}
};
