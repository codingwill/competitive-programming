#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string s) 
{
    //cout << s.length() << '\n';
    char a, b;
    char minim = 'z';
    int index = -1;
    char maks = 'a';
    //cout << 't' << '\n';
    int first = -1;
    for (int i = s.length()-2; i >= 0; --i)
    {
        maks = max(maks, s[i+1]);
        minim = 'z';
        if (maks > s[i])
        {
            //cout << 't' << '\n';
            
            for (int j = i+1; j < s.length(); ++j)
            {
                if (minim >= s[j] && s[j] > s[i])
                {
                    //cout << minim << ' ' << s[j] << '\n';
                    index = j;
                    minim = s[j];
                }
                
            }
            swap(s[i], s[index]);
            first = i;
            break;
        }
    }
    //cout << minim << '\n';
    if (index != -1) sort(s.begin() + (first + 1), s.end());
    //cout << first << ' ' << index << ' ' << s.length() << '\n';
    //cout << s << '\n';
    if (index == -1) return "no answer";
    else return s.c_str();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);
        cout << result << '\n';
        fout << result << "\n";
    }

    fout.close();

    return 0;
}
