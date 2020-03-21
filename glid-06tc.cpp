#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;

int a[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size = 13;
    int a[size];
    for (int i = 1; i <= size; i++)
    {
        int input;
        cin >> input;
        a[input-1] = i;
    }
    for (int i = 1; i <= size; i++) cout << a[i-1] << ' ';
}
/*
1 6 4 7 8 3 9 5 10 11 2
1 - 4 - - 3 - 5 - - 2

1 - 5 - 3 - 4 6 - 2

1 6 5 7 8 3 9 10 4 11 12 2
1 6 5 7 8 3 9 10 4 11 12 2

1 6 7 4 8 9 3 10 11 5 12 13 2
1 - - 4 - - 3 - - 5 - - 2

1 66 34 67 18 68 35 69 10 70 36 71 19 72 37 73 7 74 38 75 20 76 39 77 11 78 40 79 21 80 41 81 82 4 83 42 84 
22 85 43 86 12 87 44 88 23 89 45 90 8 91 46 92 24 93 47 94 13 95 48 96 25 97 49 98 99 3 100 50 101 26 102 51 
103 14 104 52 105 27 106 53 107 9 108 54 109 28 110 55 111 15 112 56 113 29 114 57 115 116 5 117 58 118 30 119 
59 120 16 121 60 122 31 123 61 124 125 6 126 62 127 32 128 63 129 17 130 64 131 33 132 65 133 134 2
*/
