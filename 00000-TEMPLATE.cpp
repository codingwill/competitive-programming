#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)
 
#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>
 
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

/* 2
#define F first
#define S second
#define vec vector
#define ms multiset
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
*/

using namespace std;
 
int main(void) 
{
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    int x, y;
    double grad[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (y0 - y == 0)
        {
            grad[i] = DBL_MAX;
            continue;
        }
        grad[i] = (float)(x0 - x)/(y0 - y);
    }
    sort(grad, grad+n);
    int count = 1;
    /*
    for (int i = 0; i < n; i++)
    {
        cout << grad[i] << " ";
    }
    */
    //cout << endl;
    for (int i = 0; i < n-1; i++)
    {
        if (abs(grad[i] - grad[i+1]) > 1e-9)
        {
            count++;
        }
    }
    cout << count << endl;
}