#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool subsecuencia(string s, string t)
{
    vector<int> indices;
    bool estaOrdenado = true;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j < t.size() && t[j] != s[i])
        {
            j++;
        }
        indices.push_back(j);
        j++;
    }
    for (int i = 1; i < indices.size(); i++)
    {
        if (!(indices[i - 1] < indices[i] && indices[i] < t.size()))
            estaOrdenado = false;
    }
    return estaOrdenado && indices.size() == s.size();
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;

    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}
