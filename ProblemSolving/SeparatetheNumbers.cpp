/*
https://www.hackerrank.com/challenges/separate-the-numbers/problem
*/

#include <bits/stdc++.h>
#include <sstream>

using namespace std;

unsigned long long formint(string s)
{
    stringstream str(s);
    unsigned long long a;
    str >> a;
    return a;
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    int pointerstart = 0;
    int pointerend = 0;   
    int len = s.length();
    unsigned long long lnum;
    unsigned long long rnum1;
    unsigned long long rnum2;
    int lenofnum;
    bool a = false, b=false, set=false;
    unsigned long long sval;
    //cout<<s<<endl;
    int count = 1;
    while(pointerend < len)
    {
        lnum = formint(s.substr(pointerstart,(pointerend-pointerstart)+1));
        //cout<<lnum<< " ";
        if(((pointerend+1) + ((pointerend-pointerstart)+1)) > len)
        {
            if((pointerend+1) < len)
                b=false;
            break;
        }
        rnum1 = formint(s.substr(pointerend+1,(pointerend-pointerstart)+1));
        //cout<<rnum1 << " ";
        if(((pointerend+1) + ((pointerend-pointerstart)+2)) > len)
            a = true;
        rnum2 = formint(s.substr(pointerend+1,(pointerend-pointerstart)+2));
        //cout<<rnum2<< " " <<endl;
        lenofnum = (pointerend - pointerstart)+1;
        if(((rnum1-lnum) == 1) && (s[pointerend+1] != '0'))
        {
            pointerstart = pointerstart + lenofnum;
            pointerend =  pointerend + lenofnum;
            if(set==false)
            {
                sval = lnum;
                set=true;
            }
            b=true;
            if(a==true)
                break;
        }
        else if(((rnum2-lnum) == 1) && (s[pointerend+1] != '0'))
        {
            pointerstart = pointerstart + lenofnum;
            pointerend =  pointerend + lenofnum + 1;
            if(set==false)
            {
                sval = lnum;
                set=true;
            }            
            b=true;
        }
        else
        {
            b = false;
            pointerstart = 0;
            set = false;
            pointerend = count;
            count++;
        }
    }
    if(b==true)
        cout<< "YES " << sval << endl;
    else
        cout<< "NO" <<endl;
    
    return;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
