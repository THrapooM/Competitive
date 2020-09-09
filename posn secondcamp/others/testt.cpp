#include <bits/stdc++.h>

using namespace std;

int L = 0, R = 1;
double data[4][2];

bool format = R; // 0 = L, 1 = R

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; ++i)
        cin >> data[i][0] >> data[i][1];

    if (format == R)
        for (int i = 0; i < 4; i++)
        {
            cout << right << setw(5) << (int)data[i][0] << " " << right << setw(10) << setprecision(2) << fixed << data[i][1] << endl;
        }

    else
        for (int i = 0; i < 4; i++)
            cout << left << setw(5) << (int)data[i][0] << " " << left << setw(10) << setprecision(2) << fixed << data[i][1] << endl;
}