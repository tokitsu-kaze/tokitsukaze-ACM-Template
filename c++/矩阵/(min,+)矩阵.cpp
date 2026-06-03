struct Matrix
{
	#define type ll
	static const int N=;
	int n;
	type c[N][N];
	Matrix(){}
	Matrix(int _n,type v=0)
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
	void init_identity_matrix(type val)
	{
		for(int i=0;i<n;i++) c[i][i]=val;
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					res.c[i][j]=min(res.c[i][j],c[i][k]+b.c[k][j]);
				}
			}
		}
		return res;
	}
	void print()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<c[i][j]<<" \n"[j+1==n];
			}
		}
	}
	#undef type
};
