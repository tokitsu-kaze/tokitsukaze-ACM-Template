ll xor_sum(ll n)
{
    ll t=n&3;
    if (t&1) return t/2ull^1;
    return t/2ull^n;
}
