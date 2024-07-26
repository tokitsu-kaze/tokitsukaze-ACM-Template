struct fraction
{
	#define type ll
	type fz,fm;
	static void simplify(type &x,type &y)
	{
		if(y<0)
		{
			x*=-1;
			y*=-1;
		}
		type g=__gcd(abs(x),abs(y));
		x/=g,y/=g;
	}
	fraction(){fz=0,fm=1;}
	fraction(type x){fz=x,fm=1;}
	fraction(type _fz,type _fm)
	{
		fz=_fz,fm=_fm;
		simplify(fz,fm);
	}
	static type lcm(type x,type y){return x/__gcd(x,y)*y;}
	friend fraction operator +(const fraction &x,const fraction &y)
	{
		fraction res;
		res.fm=lcm(x.fm,y.fm);
		res.fz=x.fz*(res.fm/x.fm)+y.fz*(res.fm/y.fm);
		simplify(res.fz,res.fm);
		if(res.fz==0) res.fm=1;
		return res;
	}
	fraction operator +(const type &x)const{return fraction(*this)+fraction(x);}
	fraction operator -(const fraction &x)const{return fraction(*this)+fraction(-x.fz,x.fm);}
	fraction operator -(const type &x)const{return fraction(*this)+fraction(-x);}
	friend fraction operator *(const fraction &x,const fraction &y)
	{
		fraction res;
		res.fz=x.fz*y.fz;
		res.fm=x.fm*y.fm;
		simplify(res.fz,res.fm);
		if(res.fz==0) res.fm=1;
		return res;
	}
	fraction operator *(const type &x)const{return fraction(*this)*fraction(x);}
	fraction operator /(const fraction &x)const{return fraction(*this)*fraction(x.fm,x.fz);}
	fraction operator /(const type &x)const{return fraction(*this)*fraction(1,x);}
	friend bool operator <(const fraction &x,const fraction &y)
	{
		type t=lcm(x.fm,y.fm);
		return x.fz*(t/x.fm)<y.fz*(t/y.fm);
	}
	friend bool operator ==(const fraction &x,const fraction &y)
	{
		return x.fz==y.fz&&x.fm==y.fm;
	}
	void print()
	{
		if(fz==0) cout<<"0";
		else if(fm==1) cout<<fz;
		else cout<<fz<<"/"<<fm;
	}
	void println(){print(),puts("");}
	#undef type
};
