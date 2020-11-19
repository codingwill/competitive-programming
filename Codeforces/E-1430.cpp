#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
int kiri = 0, kanan = 0;
void solve();
 
ll fastpow(ll x, ll y, ll n = BIG) 
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
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
            if (x != middle) kiri++;
        }
        else
        {
            right = middle;
            kanan++;
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

/*================ SOLUTION ================*/

int N = 200500, n;
vector<int> fenwick(N, 0);

ll fenwickSum(int i)
{
	i++;
    ll sum = 0;
    while (i > 0)
    {
        sum += fenwick[i];
        i -= i & (-i);
    }
    return sum;
}

void fenwickUpdate(int i, int val)
{
	i++;
    while (i <= N)
    {
        fenwick[i] += val;
        i += i & -i;
    }
}

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    vector<queue<int>> charIndex(30);
    for (int i = 0; i < t.length(); ++i)
    {
        int x = t[i] - 'a';
        charIndex[x].push(i+1);
    }
    ll sum = 0;
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        int x = s[i] - 'a';
        int num = charIndex[x].front();
        charIndex[x].pop();
        ans += sum - fenwickSum(num);
        fenwickUpdate(num, 1);
        sum++;
    }
    cout << ans << '\n';
}
 
/* ========= KOTRETAN ========= \*

9
icpcsguru
967854123       <= INDEX YANG DITUJU
011145666 = 30  <= MOVEMENT/SWAP YANG DIBUTUHKAN TIAP CHAR (i = 0 swap, c = 1 swap, p = 1 swap, c = 1 swap, s = 4 swap)
                CARANYA: UPDATE DAN SORT TIAP CHAR DIMULAI DARI KIRI TAPI JANGAN PAKE SORT, LOGIKANYA PAKE PREFIX SUM
                         TAPI KARENA KITA MESTI UPDATE DATA TERBARU DI TIAP INDEX CHAR, PREFIX SUM GA VIABLE KARENA O(N) PAS UPDATE
                         JADI MESTI PAKE FENWICK TREE, ATAU SEGMENT TREE (SESUAI SELERA AJA MAU MAKE YANG MANA). DUA-DUANYA SAMA-SAMA
                         O(LOG(N)) BUAT UPDATE/GET;
                LOGIKA : PAS UPDATE INDEX/CHAR BARU, SELISIHKAN TOTAL UPDATE SAMA TOTAL NILAI INDEX KE-1 SAMPAI KE INDEX YANG BARU DIUPDATE
                         TERUS ISI NILAI 1 DI INDEX YANG BARU DIUPDATE. (ITU SAMA DENGAN LANGKAH SWAP YANG DIBUTUHIN, PERSIS KAYAK INVERSION ARRAY DI 
                         TOPIK SORTING);
sort jadi:
urugscpci
123456789

STEP LEBIH LENGKAP:
967854123
9 <- 9 || 0 SWAP
96 <- 6 || 1 SWAP KARENA 6 HARUS DI URUTAN KE-1
697 <- 7 || 1 SWAP KARENA 7 HARUS DI URUTAN KE-2
6798 <- 8 || 1 SWAP KARENA 8 HARUS DI URUTAN KE-3
67895 <- 5 || 4 SWAP KARENA 5 HARUS DI URUTAN KE-1
567894 <- 4 || 5 SWAP KARENA 4 HARUS DI URUTAN KE-1
4567891 <- 1 || 6 SWAP KARENA 1 HARUS DI URUTAN KE-1
14567892 <- 2 || 6 SWAP KARENA 2 HARUS DI URUTAN KE-2
124567893 <- 3 || 6 SWAP KARENA 3 HARUS DI URUTAN KE-3
123456789 (DONE!) || 0 + 1 + 1 + 1 + 4 + 5 + 6 + 6 + 6 = 30 

5
aaaza
13425
00020 = 2

azaaa
12345

*/
