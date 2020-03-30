#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
//TIPE DATA BENTUKAN
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;


bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}


int fact(int n)
{
    if (n <= 0) return 1;
    return n * fact(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string s2, s3;
    int batas = s.length()/2;
    s2 = s.substr(0, batas);
    s3 = s.length() % 2 == 0 ? s.substr(batas, batas) : s.substr(batas+1, batas);
    reverse(s3.begin(), s3.end());
    if (s2 == s3)
    {
        //cout << "t1" << endl;
        string s4, s5;
        batas = s2.length()/2;
        s4 = s2.substr(0, batas);
        s5 = s2.length() % 2 == 0 ? s2.substr(batas, batas) : s2.substr(batas+1, batas);
        reverse(s5.begin(), s5.end());
        //cout << s4 << ' ' << s5 << endl;
        if (s4 == s5)
        {
            //cout << "t2" << endl;
            batas = s3.length()/2;
            s4 = s3.substr(0, batas);
            s5 = s3.length() % 2 == 0 ? s3.substr(batas, batas) : s3.substr(batas+1, batas);
            reverse(s5.begin(), s5.end());
            if (s4 == s5)
            {
                puts("Yes");
                return 0;
            }
        }
        
    }
    puts("No");
    return 0;
}