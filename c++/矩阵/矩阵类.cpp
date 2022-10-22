const ll mod=1e9+7;
struct Matrix
{
	static const int N=;
	int n;
	ll c[N][N];
	Matrix(){}
	Matrix(int _n,ll v=0)
	{
		int i,j;
		n=_n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	void init_identity_matrix() {for(int i=0;i<n;i++) c[i][i]=1;}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]+=c[i][k]*b.c[k][j];
					if(res.c[i][j]>=mod) res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,ll b)
{
	Matrix res(a.n);
	res.init_identity_matrix();
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

