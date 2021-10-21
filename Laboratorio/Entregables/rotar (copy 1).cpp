#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j)
{
    string rot(s);
    for (int i = 0; i < s.size(); i++)
    {
        int p = (i + j) % s.size();
        rot[p] = s[i];
    }
    return rot;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;

    string res = rotar(s, j);
    cout << res;
    return 0;
}
