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
    int n, m, q;
    cin >> n >> m >> q;
    vector<deque<int>> tump;
    vector<deque<int>> urutan(m+1);
    for (int i = 0; i < m; ++i)
    {
        int X;
        cin >> X;
        deque<int> s;
        for (int i = 0; i < X; ++i)
        {
            int input;
            cin >> input;
            s.push_back(input);
        }
        tump.push_back(s);
        deque<int> temp;
        temp.push_back(i);
        urutan[i+1] = temp;
    }
    
    map<int, int> piring;
    for (int i = 0; i < q; ++i)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int P, T;
            cin >> P >> T;
            piring[P]--;
            if (urutan[T].empty())
            {
                //cout << "t\n";
                deque<int> temp;
                temp.push_back(P);
                tump.push_back(temp);
                urutan[T].push_back(tump.size() - 1);
            }
            else
            {
                //cout << "t\n";
                int atas = urutan[T].back();
                tump[atas].push_back(P);
            }
        }
        else if (query == 2)
        {
            int T;
            cin >> T;
            int atas = urutan[T].back();
            //cout << atas << '\n';
            int plate = tump[atas].back();
            tump[atas].pop_back();
            if (tump[atas].empty()) 
            {
                //cout << 't' << '\n';   
                urutan[T].pop_back();
            }
            piring[plate]++;
            //cout << 't' << '\n';
        }
        else
        {
            int T1, T2;
            cin >> T1 >> T2;
            while (!urutan[T1].empty())
            {
                urutan[T2].push_back(urutan[T1].front());
                urutan[T1].pop_front();
            }
        }
        
        
    }
    for (int i = 1; i <= m; ++i)
    {
        bool ada = !urutan[i].empty();
        if (ada)
        {
            cout << i << ":";
        }
        while (!urutan[i].empty())
        {
            int bawah = urutan[i].front();
            //cout << bawah <<  '\n';
            while (!tump[bawah].empty())
            {
                cout << ' ' << tump[bawah].front();
                tump[bawah].pop_front();
            }
            urutan[i].pop_front();
        }
        if (ada) cout << '\n';
    }
        
}
 
/* ==================== KOTRETAN ===================== *\

5 3 5
3 1 3 5 
1 4 
1 2
3 3 2
3 2 1
3 1 2
3 2 3
3 3 1

4
add = 2
ans += 2*3
ans = 16

4 2 1 3 5
1 5 4 3 2

4
ans += 2*0
ans = 18



6 2 2 3 
5 5 8 6

2 2 3 5
5 8 6 6


1 3 5 4 2

2: 2 4 8 10 3 1 5 6 7
2: 2 4 8 10 3 1 5 6

*/