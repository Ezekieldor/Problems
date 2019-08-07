#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string a, b;
int vet[33], vetB[33];

bool IsSame ()
{
    int i;
    for (i = 0; i < 26 && vet[i] == vetB[i]; i++);
    if (i == 26) return true;
    return false;
}

int main ()
{
    cin >> a >> b;
    ll ant = 0;
    ll res = 0;

    for (int i = 0; i < (int)b.size (); i++) vetB[b[i] - 'a']++;

    for (ll i = 0, j = 0; i < (int)a.size (); i++)
    {
        vet[a[i] - 'a']++;

        if (i - j + 1 == (int)b.size ())
        {
            if (IsSame ())
            {
                res += (j - ant + 1) * (a.size () - i);
                ant = j + 1;
            }
            vet[a[j] - 'a']--;
            j++;
        }
    }

    cout << res << endl;
}
