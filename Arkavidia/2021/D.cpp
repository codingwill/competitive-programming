#include <bits/stdc++.h>
#include <chrono>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/12/01
*/
using namespace std;
using ll = long long int;

/*===================== CONSTANT =====================*/

const ll BIG = 1e18 + 1;
const ll MOD = 1e9 + 7;
const int m = 998244353;

/*============== FUNCTION INITIALIZATION =============*/

void solve();

/*================ IMPORTANT FUNCTION ================*/

ll fastpow(ll x, ll y, ll n = m) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}
 
bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}
 
bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
 
bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
 
int main()
{
    //input output optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(10);
    
    //debug time
    /*
    auto start = chrono::high_resolution_clock::now();
    freopen("input.txt", "r", stdin);
    */

    //solve function
    solve();
    
    //debug time
    /*
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    ofstream file;
    file.open("time.txt");
    file << duration.count() << " ms.";
    file.close();
    */
    return 0;
}
  
ll factorial(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return factorial(n) / ((factorial(r) * factorial(n - r)) % MOD); 
} 

bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


bool stringSort(string &a, string &b)
{
    if (a.length() > b.length()) return a.length() > b.length();
    return a > b;
}

void binsearch(int n, int x)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int middle = (left + right) / 2;
        //cout << middle << '\n';
        //if (middle == x) break;
        if (middle <= x)
        {
            left = middle + 1;
            if (x != middle);
        }
        else
        {
            right = middle;
        }
    }
}

int sequence(int a, int b)
{
    ll res = 1; 
    for (ll i = b; i <= a; i++) 
        res = (res * i) % MOD; 
    return res; 
}

int gcd(ll a, ll b) 
{
    while (b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*===================== SOLUTION =====================*/

 
ll Lucas(ll n, ll r)
{
	if(r < 0 ||r > n)
	{
		return 0;
	}
	
	if(r == 0 || r == n)
	{
		return 1;
	}
	
	if(n >= 2)
	{
		return (Lucas(n/2, r/2) * Lucas(n%2, r%2)) % 2;
	}
	
	return 1;
}


void solve()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    bitset<200005> isOdd;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    ll ans = x[0];
    ll sisa = n-1;
    for (int i = 1; i <= sisa; ++i) 
    {
        if (Lucas(sisa, i) & 1) isOdd[i] = true;
        else isOdd[i] = false;
    }
    for (int i = 1; i < n; ++i)
    {
        if (isOdd[i])
        {
            ans ^= x[i];
        }
    }
    cout << ans << '\n';

}
 
/* ==================== KOTRETAN ===================== *\

4
7 8 9 2 
(7 ^ 8) ^ (8 ^ 9) ^ (9 ^ 2)
15 1 11
10 14
4

3
1 3 5
(1 ^ 3) (3 ^ 5)
[(1 ^ 3) ^ (3 ^ 5)]


4
5 4 3 2
(5^4) (4^3) (3^2)
[(5^4) ^ (4^3)] [(4^3) ^ (3^2)]

1 7 1
6 6
0

5 
6 7 1 3 4
(6 ^ 7) (7 ^ 1) (1 ^ 3) (3 ^ 4)
[(6^7) ^ (7^1)] [(7^1) ^ (1^3)] [(1^3) ^ (3^4)]
{[(6^7) ^ (7^1)] ^ [(7^1) ^ (1^3)]} {[(7^1) ^ (1^3)] ^ [(1^3) ^ (3^4)]}
6 = 1
7 = 4
1 = 6
3 = 4
4 = 1

1 6 2 7
7 4 5
3 1
2

6
13 6 28 46 52 19
[(13^6)^(6^28)] ^ [(6^28)^(28^46)] ^ [(28^46)^(46^52)] ^ [(46^52)^(52^19)]
13 = 1
6 = 3
28 = 4
46 = 4
52 - 3
19 = 1

11 26 50 26 39
17 40 40 61
57 0 21
57 21
44

5
1 1 1 6 3
0 0 7 5
0 7 2
7 5
2

*/