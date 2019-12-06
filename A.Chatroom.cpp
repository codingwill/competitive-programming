#include <bits/stdc++.h>

using namespace std;

int main()
{
    string chat;
    cin >> chat;
    int len = chat.length();
    string chatRapi;
    int indeks = 0;
    int i;
    for (i = 0; i < len - 1; i++)
    {
        if (chat[i] != chat[i + 1])
        {
            chatRapi[indeks] = chat[i];
            indeks++;
        }
    }
    if (chat[i] != chat[i-1])
    {
        chatRapi[indeks] = chat[i];
    }
    else
    {
        chatRapi.erase(indeks, 1);
    }
    
    cout << chatRapi[6] << endl;
}