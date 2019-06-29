
string Sum(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    string out = "";
    int sz = max(a.size(),b.size()) + 1;
    while(a.size()<sz) a.push_back('0');
    while(b.size()<sz) b.push_back('0');

    int carry = 0;
    for(int i=0;i<sz;i++)
    {
        carry += a[i]-'0' + b[i]-'0';
        out.push_back((char)('0'+ carry%10));
        carry = carry / 10;
    }

    while(out.back() == '0') out.pop_back();
    reverse(out.begin(),out.end());

    return out;
}

string Minimize(string a,string b)
{
    if(a.size() < b.size()) return a;
    if(b.size() < a.size()) return b;

    for(int i=0;i<a.size();i++)
    {
        if(a[i] < b[i]) return a;
        if(b[i] < a[i]) return b;
    }
    return a;
}
