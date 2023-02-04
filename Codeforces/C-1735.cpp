#include <bits/stdc++.h>
/*
** Author: codingwill (Willy I. K.)
** 2022/10/02
*/
using namespace std;
using ll = long long int;

/*===================== CONSTANT =====================*/

const ll BIG = 1e18 + 1;
const ll MOD = 1e9 + 7;
const int m = 998244353;

/*============== FUNCTION INITIALIZATION =============*/

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*================ IMPORTANT FUNCTION ================*/

ll fastpow(ll x, ll y, ll n = m)
{
    x %= n;
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
            ans = (ans * x) % n;
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
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
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
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool stringSort(string &a, string &b)
{
    if (a.length() > b.length())
        return a.length() > b.length();
    return a > b;
}

void binsearch(int n, int x)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int middle = (left + right) / 2;
        // cout << middle << '\n';
        // if (middle == x) break;
        if (middle <= x)
        {
            left = middle + 1;
            if (x != middle)
                ;
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

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*===================== SOLUTION =====================*/

void nextCyclicAlphabet(char &character)
{
    character++;
    if (character > 'z')
        character = 'a';
}

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string result = "";
        map<char, char> encryption;
        map<char, bool> hasEncryption;
        set<char> uniqueChar;
        int totalKeys = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            uniqueChar.insert(s[i]);
        }

        for (int i = 0; i < s.length(); ++i)
        {
            char currentChar = s[i];
            char potentialEncryptedChar = 'a';

            while (potentialEncryptedChar <= 'z')
            {
                if (encryption[currentChar] != NULL)
                {
                    result += encryption[currentChar];
                    break;
                }

                if ((currentChar == potentialEncryptedChar || hasEncryption[potentialEncryptedChar] != 0 || encryption[potentialEncryptedChar] == currentChar || encryption[potentialEncryptedChar] != NULL) && (totalKeys < uniqueChar.size()))
                {
                    nextCyclicAlphabet(potentialEncryptedChar);
                    continue;
                }
                // cout << currentChar << " : " << encryption.size() << " : " << uniqueChar.size() << '\n';
                cout << "{";
                for (auto k : encryption)
                {
                    cout << k.first << " => " << k.second << ", ";
                }
                cout << "}" << '\n';
                result += potentialEncryptedChar;
                encryption[currentChar] = potentialEncryptedChar;
                hasEncryption[potentialEncryptedChar] = true;
                nextCyclicAlphabet(potentialEncryptedChar);
                totalKeys++;
                break;
            }
        }
        for (auto i : encryption)
        {
            cout << i.first << ": " << i.second << '\n';
        }

        cout << '{';
        for (auto i : hasEncryption)
        {
            cout << i.first << ", ";
        }
        cout << '}' << '\n';

        cout << result << '\n';
    }
}
/* ==================== KOTRETAN ===================== *\

5 4
2 3 4 3 3
1
2
3
10

11 (12) 13 14 (15) (16) 17 (18) 19 20 (21) 22 23
*/