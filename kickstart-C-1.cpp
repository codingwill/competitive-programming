    #include <bits/stdc++.h>
    
    //BIAR MANTAB LAH YA
    #define Willy using
    #define Indrayana namespace
    #define Komara std
    
    Willy Indrayana Komara;
    
    using ll = long long int;
    
    int myMod(int a, int b)
    {
        if (a % b == 0) return 3;
        return a % b;
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin >> t;
        int num = t;
        while (t--)
        {
            int n, k;
            cin >> n >> k;
            bool cd = false;
            int input = 0, prev = 0;
            ll ans = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> input;
                if (input == k)
                {
                    cd = true;
                }
                else if (!(prev - input == 1))
                {
                    cd = false;
                }
                if (cd && input == 1) ++ans;
                prev = input;
            }
            cout << "Case #" << num-t << ": " << ans << endl;
        }
    }