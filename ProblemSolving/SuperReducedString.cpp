/*
https://www.hackerrank.com/challenges/reduced-string/problem
*/



#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string ret = "Empty String";
    int i=1;
    while(i<s.length())
    {
        if(s[i]==s[i-1])
        {
            s.erase(i-1,2);
            if(s.length() == 0)
                return ret;
            else
                i--;
        }
        else
        {
            i++;
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
