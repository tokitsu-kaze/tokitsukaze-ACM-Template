struct Gauss
{
	static const int N=;
	bitset<N> mp[N];
	void init()
	{
		for(int i=0;i<N;i++) mp[i].reset();
	}
	int gauss(int n,int m)
	{
		int i,j,k,pos,r;
		r=0;
		for(k=1;k<=m;k++)
		{
			pos=r+1;
			if(pos>n) return -1; // no solution
			while(pos<n&&!mp[pos][k]) pos++;
			if(!mp[pos][k]) continue;
			r++;
			swap(mp[pos],mp[r]);
			for(i=r+1;i<=n;i++)
			{
				if(mp[i][k]) mp[i]^=mp[r];
			}
		}
		return r;
	}
	int work(int n,int m,int *res)
	{
		int i,j,cnt;
		cnt=gauss(n,m);
		if(cnt==-1) return -1;
		for(i=cnt+1;i<=n;i++)
		{
			if(mp[i][m+1])
			{
				// no solution
				return -1;
			}
		}
		if(cnt<m)
		{
			// multi solution
			
			/*
			1 1 0 0 0      1 1 0 0 0
			0 1 1 0 0  ->  0 1 1 0 0
			0 0 0 1 0      0 0 0 0 0
			0 0 0 0 0      0 0 0 1 0
			*/
			for(i=1;i<=n;i++)
			{
				if(!mp[i][i])
				{
					for(j=n;j>i;j--) swap(mp[j],mp[j-1]);
				}
			}
			
			//make solution
			
			return 1;
		}
		for(i=1;i<=m;i++) res[i]=mp[i][m+1];
		return 0;
	}
}gs;
/*
(mp[1][1]*x1) xor (mp[1][2]*x2) xor ... xor (mp[1][m]*xm) = mp[1][m+1]
(mp[2][1]*x1) xor (mp[2][2]*x2) xor ... xor (mp[2][m]*xm) = mp[2][m+1]
...
(mp[n][1]*x1) xor (mp[n][2]*x2) xor ... xor (mp[n][m]*xm) = mp[n][m+1]

a:0/1  x:0/1

x x x x | x
0 x x x | x
0 0 x x | x
0 0 0 x | x


O((n*m^2)/64)

gs.work(n,m,res); mp[1..n][1..m+1], res[1..m]

-1: no solution
0 : one solution
1 : multi solution
*/
