#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool pairSort(const pair<int, int> &a, const pair<int, int> &b)
{
    if ((double)a.second / a.first - (double)b.second / b.first <= 1e-3)
    {
        return a.first < b.first;
    }
    return (double)a.second / a.first > (double)b.second / b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int castLimit;
    cin >> castLimit;
    int nSkill;
    cin >> nSkill;
    vector<pair<int, int>> skill;
    for (int i = 0; i < nSkill; i++)
    {
        int limitSkill, dmgSkill;
        cin >> limitSkill >> dmgSkill;
        skill.push_back(make_pair(limitSkill,dmgSkill));
    }
    sort(skill.begin(), skill.end(), pairSort);

    int totalCast = 0;
    int i = 0;
    int maxDamage = 0;
    while (totalCast < castLimit && i < nSkill)
    {
        if (skill[i].first + totalCast <= castLimit)
        {
            maxDamage += skill[i].second;
            totalCast += skill[i].first;
        }
        else
        {
            totalCast += castLimit - totalCast;
        }
        i++;
    }
    cout << maxDamage << endl;
    return 0;
}

/*
100
5
20 100 = 5/dmg
40 100 = 2.5/dmg
40 100 = 2.5
20 60 = 3
20 60 = 3

100
4
50 100 = 2
25 100 = 4
25 100 = 4
1 101 = 101

1 * 101 + 25 * 4 + 25 * 4 + 49 * 2
101 + 100 + 100 + 98 = 399
*/

