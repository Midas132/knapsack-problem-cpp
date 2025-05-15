#include <iostream>
#include <vector>
using namespace std;

int n, B;

int koszt[103];
int smacznosc[103];

int T[103][10003];
bool wyn1[103][10003];

vector <int> wyn2;

int main()
{
    cin >> n >> B;
    for(int i = 1; i <= n; i++)
        cin >> koszt[i];
    for(int i = 1; i <= n; i++)
        cin >> smacznosc[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= B; j++)
        {
            if(j >= koszt[i]){
                T[i][j] = max(smacznosc[i] + T[i-1][j-koszt[i]], T[i-1][j]);
                if(smacznosc[i] + T[i-1][j-koszt[i]] >= T[i-1][j])
                {
                    wyn1[i][j] = true;
                }
            }
            else
            {
                T[i][j] = T[i-1][j];
            }
        }
    }
    int n1 = n;
    int B1 = B;
    for(int i = n; i >= 1; i--)
    {
        if(wyn1[n1][B1])
        {
            wyn2.push_back(i);
            B1 -= koszt[i];
        }
        n1--;
    }
    int ilosc = wyn2.size();
    cout << T[n][B] << '\n' << ilosc << '\n';
    for(int i = ilosc-1; i >= 0; i--)
    {
        cout << wyn2[i] << " ";
    }

}