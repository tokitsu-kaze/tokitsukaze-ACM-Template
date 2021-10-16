struct node
{
	int x,y;
	void input(){scanf("%d%d",&x,&y);}
}p[511];
int main()
{
	int n,i,j,ans;
	while(~scanf("%d",&n))
	{
		map<pair<int,int>,int> mp;
		for(i=0;i<n;i++)
		{
			p[i].input();
			mp[MP(p[i].x,p[i].y)]=1;
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int a,b,c,d,e,f,g,h;
				a=p[i].x;
				b=p[i].y;
				c=p[j].x;
				d=p[j].y;
				e=a+b+c-d;
				f=-a+b+c+d;
				g=a-b+c+d;
				h=a+b-c+d;
				if(abs(e%2)+abs(f%2)+abs(g%2)+abs(h%2)==0)
				{
					if(mp[MP(e/2,f/2)]&&mp[MP(g/2,h/2)]) ans++;
				}
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
