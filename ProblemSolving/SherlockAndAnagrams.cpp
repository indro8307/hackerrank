/*
https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map<string,int> mymap;
    map<string,int>::iterator it;
    int len = s.length();
    vector< vector<string> > str(len-1, vector<string>(len));
    int l = len;
    for(int i=0;i<(len-1);i++)
    {
        for(int j=0;j<l;j++)
        {
            str[i][j] = s.substr(j,(i+1));
            sort(str[i][j].begin(),str[i][j].end());
            it = mymap.find(str[i][j]);
            if(it != mymap.end())
            {
                it->second++;
            }
            else 
            {
                mymap[str[i][j]] = 1;
            }
        }
        l--;
    }  
    int sz = mymap.size();
    int count=0;
    for(map<string,int>::iterator p=mymap.begin();p!=mymap.end();p++)
    {
        if(p->second > 1)
        {
            if(p->second == 2)
            {
                count+= 1;
            }
            else if(p->second == 3)
            {
                count += 3;
            }
            else
            {
                int val = p->second;
                int tmp = val-2;
                int sum = ((tmp*(tmp+1))/2) - 1;
                sum = sum + val;
                count += sum;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
