/*
https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the decentNumber function below.
void decentNumber(int n) {
    //cout<<"n = "<<n<<endl;
    if(n%3 == 0)
    {
        /* number can have all 5s*/
        for(int i=0;i<n;i++)
        {
            cout<<"5";
        }
        cout<<endl;
    }
    else
    {
        int m = n-5;
        while(m>0)
        {
            if(m%3==0)
            {
                break;
            }
            m = m-5;
        }
        if(m<0)
        {
            cout<<"-1"<<endl;
        }
        else if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                cout<<"3";
            }
            cout<<endl;
        }
        else if(m>0)
        {
            for(int i=0;i<n;i++)
            {
                if(i<m)
                {
                    cout<<"5";
                }
                else 
                {
                    cout<<"3";
                }
            }
            cout<<endl;
        }
    }

}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
