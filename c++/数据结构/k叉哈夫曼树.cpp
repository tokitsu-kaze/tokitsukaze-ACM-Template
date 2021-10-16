int a[MAX];
int Huffman(int k)
{
	int i,res,s;
	queue<int> q,d;
	s=((n-1)%(k-1)?k-1-(n-1)%(k-1):0);//计算要补多少个0 
	while(s--) q.push(0);
	for(i=1;i<=n;i++) q.push(a[i]);
	res=0;
	while(sz(q)+sz(d)>1)
	{
		s=0;
		for(i=0;i<k;i++)
		{
			if(sz(q)&&sz(d))
			{
				if(q.front()<d.front())
				{
					s+=q.front();
					q.pop();
				}
				else
				{
					s+=d.front();
					d.pop();
				}
			}
			else if(sz(q))
			{
				s+=q.front();
				q.pop();
			}
			else if(sz(d))
			{
				s+=d.front();
				d.pop();
			}
		}
		res+=s;
		d.push(s);
	}
	return res;
} 
