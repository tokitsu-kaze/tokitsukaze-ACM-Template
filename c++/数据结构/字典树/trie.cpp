struct Trie
{
	#define type int
	struct trie
	{
		int v;
		trie *next[26];
		trie()
		{
			v=0;
			for(int i=0;i<26;i++) next[i]=NULL;
		}
	}*root;
	void insert(trie *p,char *s)
	{
		int i=0,t;
		while(s[i])
		{
			t=s[i]-'a';
			if(p->next[t]==NULL) p->next[t]=new trie;
			p=p->next[t];
			p->v++;  //may need change
			i++;
		}
	}
	int find(trie *p,char *s)
	{
		int i=0,t;
		while(s[i])
		{
			t=s[i]-'a';
			if(p->next[t]==NULL) return 0;
			p=p->next[t];
			i++;
		}
		return p->v;  //may need change
	} 
	//É¾³ýÇ°×ºÎªsµÄ×Ö·û´® 
	void del(char *s)
	{
		int i=0,t,temp;
		trie *p,*pre;
		pre=p=root;
		while(s[i])
		{
			t=s[i]-'a';
			if(p->next[t]==NULL) return;
			if(!s[i+1])
			{
				temp=p->next[t]->v;
				p->next[t]=NULL;
				break;
			}
			pre=p;
			p=p->next[t];
			i++;
		}
		i=0;
		p=root;
		while(s[i])
		{
			t=s[i]-'a';
			if(p->next[t]==NULL) return;
			p=p->next[t];
			p->v-=temp;
			i++;
		}
	}
	#undef type
}tr;
