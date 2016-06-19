#include <iostream>
#include <string>
using namespace std;
string s;

bool replace_before(char c, char c2, int n)
{
  for(int i = n - 1; i >= 0; i--)
  {
    if (s[i] == c)
    {
      s[i] = '#';
      return true;
    }
  }
  return false;
}

int main()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++)
  {
    cin >> s;
    int w = 0, g = 0, r = 0;
    bool ok = true;
    bool extra_w = false;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'W')
      {
        w++;
        extra_w = true;
      }
      if (s[i] == 'G')
      {
        g++;
        extra_w = false;
        if (--w < 0)
        {
          ok = false;
          break;
        }
      }
      if (s[i] == 'R')
      {
        r++;
        if (--g < 0)
        {
          ok = false;
          break;
        }
      }
    }
    if (ok && !extra_w && g == 0)
      cout << "possible" << endl;
    else
      cout << "impossible" << endl;
  }
}
