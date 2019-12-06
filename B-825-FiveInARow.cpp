#include <bits/stdc++.h>

using namespace std;

int main()
{
    int row = 10, col = 10;
    char mat[row][col];
    int sumX = 0;
    int kosong = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }    
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 'X')
            {
                sumX = 0;
                kosong = 0;
                if (i + 4 < 10)
                {
                    for (int k = i + 1; k < i + 5; k++)
                    {
                        if (mat[k][j] == 'X')
                        {
                            sumX++;
                            if (sumX == 3)
                            {
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            kosong++;
                            if (kosong > 1)
                                break;
                        }
                        
                    }
                }
                if (j + 4 < 10)
                {
                    for (int k = j + 1; k < j + 5; k++)
                    {
                        if (mat[i][k] == 'X')
                        {
                            sumX++;
                            cout << k << endl;
                            if (sumX == 3)
                            {
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            //cout << k << endl;
                            kosong++;
                            if (kosong > 1)
                                break;
                        }
                    }
                }
                if (i - 4 < 10)
                {
                    for (int k = i - 1; k < i - 5; k--)
                    {
                        if (mat[k][j] == 'X')
                        {
                            sumX++;
                            if (sumX == 3)
                            {
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            kosong++;
                            if (kosong > 1)
                                break;
                        }
                    }
                }

                if (j - 4 < 10)
                {
                    for (int k = j - 1; k < j - 5; k--)
                    {
                        if (mat[i][k] == 'X')
                        {
                            sumX++;
                            if (sumX == 3)
                            {
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            kosong++;
                            if (kosong > 1)
                                break;
                        }
                    }
                }
            }
        }    
    }
    cout << "NO" << endl;
    return 0;
}