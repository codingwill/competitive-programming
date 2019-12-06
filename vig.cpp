#include <iostream>
#include <string>
using namespace std;

class Vigenere {
    public:
    string k;
    Vigenere(string k) {
        for (int i = 0; i < k.size(); ++i) {
            if (k[i] >= 'A' && k[i] <= 'Z')
                this->k += k[i];
            else if (k[i] >= 'a' && k[i] <= 'z')
                this->k += k[i] + 'A' - 'a';
        }
    }
    string enkripsi(string t) {
        string output;
        for (int i = 0, j = 0; i < t.length(); ++i) {
            char c = t[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c + k[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
            j = (j + 1) % k.length();
        }
        return output;
    }
    string dekripsi(string t) {
        string hasil;
        for (int i = 0, j = 0; i < t.length(); ++i) {
            char c = t[i];
            bool caps = true;
            if ((int)c >= (int)'a' && (int)c <= (int)'z')
                caps = false;
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            if (caps)
                hasil += (c - k[j] + 26) % 26 + 'A';
            else
                hasil += (c - k[j] + 26) % 26 + 'a';
            j = (j + 1) % k.length();
        }
        return hasil;
    }
};


int main() 
{
    string key, input;
    cout << "Masukkan key: "; cin >> key;
    Vigenere f(key);
    cout << "Masukkan input: "; cin >> input;
    string hasilDekripsi = f.dekripsi(input);
    cout << "Input: "<< input << endl;
    cout << "Output: " << hasilDekripsi << endl;
}