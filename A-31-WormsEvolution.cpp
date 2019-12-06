#include <bits/stdc++.h>

using namespace std;


struct Form
{
    int index, nilai;
};

bool CompareIsiStruct (Form i, Form j)
{
    return i.nilai < j.nilai;
}


int main()
{
    int n;
    cin >> n;
    Form form[n];
    for (int i = 0; i < n; i++)
    {
        form[i].index = i;
        cin >> form[i].nilai;
    }
    sort(form, form + n, CompareIsiStruct);
    /*
    for (int i = 0; i < n; i++)
    {
        cout << form[i].nilai << " ";
    }
    cout << endl;
    */
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = i + 2; k < n; k++)
            {
                if (form[k].nilai == form[i].nilai + form[j].nilai)
                {
                    cout << form[k].index + 1 << " " << form[j].index + 1 << " " << form[i].index + 1 << endl;
                    return 0;                   
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}