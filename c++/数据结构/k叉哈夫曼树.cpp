struct k_Huffman
{
	#define type ll
	type work(int n,int k,type *a)// a[1..n], sorted 
	{
		int i;
		type res,s;
		queue<type> q,d;
		s=((n-1)%(k-1)?k-1-(n-1)%(k-1):0);//计算要补多少个0 
		while(s--) q.push(0);
		for(i=1;i<=n;i++) q.push(a[i]);
		res=0;
		while(q.size()+d.size()>1)
		{
			s=0;
			for(i=0;i<k;i++)
			{
				if(q.size()&&d.size())
				{
					if(q.front()<=d.front())
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
				else if(q.size())
				{
					s+=q.front();
					q.pop();
				}
				else if(d.size())
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
	#undef type
}hfm;

