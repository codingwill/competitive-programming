void suffixArray()
{
    string s;
    cin >> s;
    s += '$';
    int n = s.length();
    vector<pair<pair<int, int>, int>> suf(n); //suffix
    vector<int> equ(n, 0); //equivalency
    for (int i = 0; i < n; ++i)
    {
        suf[i] = make_pair(make_pair(s[i], 0), i);
    }
    sort(suf.begin(), suf.end());
    //assign equivalency
    for (int i = 1; i < n; ++i)
    {
        int cur = suf[i].second;
        int prev = suf[i-1].second;
        equ[cur] = equ[prev];
        if (suf[i].first != suf[i-1].first)
        {
            equ[cur]++;
        }
    }
    int k = 1;
    while (true)
    {   
        int x = -1;
        //cout << k << '\n';
        equ[n-1] = 0;
        vector<pair<pair<int, int>, int>> temp(n); //temp cur suffix
        for (int i = 0; i < n; ++i)
        {
            int first = suf[i].second;
            int second = (first + fastpow(2, k) - 1) % n;
            suf[i] = make_pair(make_pair(equ[i], equ[(i + (fastpow(2, k) / 2)) % n]), i);
        }
        sort(suf.begin(), suf.end());
        //assign equivalency
        for (int i = 1; i < n; ++i)
        {
            int cur = suf[i].second;
            int prev = suf[i-1].second;
            equ[cur] = equ[prev];
            if (suf[i].first != suf[i-1].first)
            {  
                equ[cur]++;
            }
            x = equ[cur];
        }
        if (x == n-1) break;
        k++;
    }
    int t;
    cin >> t;
    while (t--)
    {
        string query;
        cin >> query;
        int len = query.length();
        int left = 0;
        int right = n;
        bool found = false;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (s.substr(suf[mid].second, len) == query) 
            {
                found = true;
                break;
            }
            if (s.substr(suf[mid].second, len) < query) left = mid + 1;
            else right = mid;
        }
        found ? cout << "Yes\n" : cout << "No\n";
    }
}