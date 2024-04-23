#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int inc(const int &x,const int &y){return x+y>=mod?x+y-mod:x+y;}
int dec(const int &x,const int &y){return x-y<0?x-y+mod:x-y;}
int mul(const int &x,const int &y){return 1LL*x*x%mod;}
int qpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b&1) res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
struct NTT
{
	const int g=3;
	const int _mod=998244353;
	int len;
	vector<int> omega,omegaInv;
	NTT(){assert(mod==_mod);len=0;}
	inline void init(int n)
	{
		int last_len=len;
		len=1;
		while(len<=n) len<<=1;
		if(last_len==len) return;
		omega.resize(len);
		omegaInv.resize(len);
		omega[0]=omegaInv[0]=1;
		const int primitive=qpow(g,(mod-1)/len);
		for(int i=1;i<len;i++) omega[i]=omegaInv[len-i]=mul(omega[i-1],primitive);
	}
	void DFT(vector<int> &a)
	{
		int *w=omega.data();
		if(a.size()<len) a.resize(len);
		int *b=a.data();
		int h,t,i,j,x,y;
		for(h=(len>>1);h;h>>=1)
		{
			for(t=len/(h<<1),j=0;j<len;j+=(h<<1))
			{
				const int *wn=w;
				for(i=j;i<j+h;i++) 
				{
					x=b[i],y=b[i+h];
					b[i]=inc(x,y);
					b[i+h]=mul(dec(x,y),*wn);
					wn+=t;
				}
			}
		}
	}
	void IDFT(vector<int> &a)
	{
		int *w=omegaInv.data();	
		if(a.size()<len) a.resize(len);
		int *b=a.data();
		int h,t,i,j,x,y;
		for(h=1;h<len;h<<=1)
		{
			for(t=len/(h<<1),j=0;j<len;j+=h<<1)
			{
				const int *wn=w;
				for (i=j;i<j+h;i++)
				{
					x=b[i],y=mul(b[i+h],*wn);
					b[i]=inc(x,y);
					b[i+h]=dec(x,y);
					wn+=t;
				}
			}
		}
		const int tmp=mod-(mod-1)/len;
		for(i=0;i<len;i++) b[i]=mul(b[i],tmp);
	}
}ntt;
struct Poly
{
	vector<int> v;
	Poly(){}
	Poly(vector<int> v):v(v){}
	Poly(const Poly &x):v(x.v){}
	Poly(initializer_list<int> v):v(v){}
	int deg() const {return v.size()-1;}
	void redeg(int k){v.resize(k+1);}
	Poly slice(int k) const
	{
		if(k<v.size()) return vector<int>(v.begin(),v.begin()+k+1);
		vector<int> res(v);
		res.resize(k+1);
		return res;
	}
	Poly clone() const {return slice(deg());}
	void shrink()
	{
		int c=deg();
		while(c>=0&&v[c]==0) c--;
		v.resize(c+1);
	}
	int operator[](int k) const {return v.size()<=k?0:v[k];}
	int& operator[](int k)
	{
		if(v.size()<=k) v.resize(k+1);
		return v[k];
	}
	friend Poly operator+(const Poly &x,const Poly &y)
	{
		Poly z;
		int deg=max(x.deg(),y.deg());
		for(int i=0;i<=deg;i++) z[i]=inc(x[i],y[i]);
		return z;
	}
	friend Poly operator-(const Poly &x,const Poly &y)
	{
		Poly z;
		int deg=max(x.deg(),y.deg());
		for(int i=0;i<=deg;i++) z[i]=dec(x[i],y[i]);
		return z;
	}
	friend Poly operator*(const Poly &_P, const Poly &_Q)
	{
		Poly P = _P.clone(), Q = _Q.clone();
		int deg = P.deg() + Q.deg();
		Poly R;
		if (P.deg() + Q.deg() <= 31)
		{
			R.redeg(P.deg() + Q.deg());
			int *r = R.v.data();
			const int *p = P.v.data(), *q = Q.v.data();
	
			for (int i = 0; i <= P.deg(); ++i)
				for (int j = 0; j <= Q.deg(); ++j)
					r[i + j] = inc(r[i + j], mul(p[i], q[j]));
			return R.slice(deg);
		}
		else
		{
			ntt.init(P.deg() + Q.deg() );
			ntt.DFT(P.v); ntt.DFT(Q.v);
			R.v.resize(ntt.len);
			int *r = R.v.data();
			const int *p = P.v.data(), *q = Q.v.data();
			for (int i = 0; i < ntt.len; ++i) r[i] = mul(p[i], q[i]);
			ntt.IDFT(R.v);
			return R.slice(deg);
		}
	}
	void println() {for(int i=0;i<=deg();i++) printf("%d%c",v[i]," \n"[i==deg()]);}
};

// https://qoj.ac/submission/35167
int main()
{
	Poly a={1,1};
	Poly b={1,1};
	(a*b).println();
	return 0;
}
