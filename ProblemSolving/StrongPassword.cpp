/*
https://www.hackerrank.com/challenges/strong-password/problem
*/

#include <bits/stdc++.h>

using namespace std;

#define MIN_LENGTH  6


// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    short length=n,numDigits=0,lcChar=0,upChar=0,spChar=0;
    int ret = 0;

    for(int i=0;i<n;i++)
    {
        if(isdigit(password[i]))
        {
            numDigits++;
        }
        else if((password[i]>='a') && (password[i]<='z'))
        {
            lcChar++;
        }
        else if((password[i]>='A') && (password[i]<='Z'))
        {
            upChar++;
        }
        else if((password[i]=='!') || (password[i]=='@') ||
                (password[i]=='$') || (password[i]=='%') ||
                (password[i]=='^') || (password[i]=='&') ||
                (password[i]=='*') || (password[i]=='(') ||
                (password[i]==')') || (password[i]=='-') ||
                (password[i]=='+') || (password[i]=='#') )   // !@#$%^&*()-+
        {
            spChar++;
        }
        if(numDigits && lcChar && upChar && spChar)
            break;
    }
    if(!numDigits)
        ret++;
    if(!lcChar)
        ret++;
    if(!upChar)
        ret++;
    if(!spChar)
        ret++;

    if(n<MIN_LENGTH)
    {
        ret = ret>(MIN_LENGTH-n)?(ret):(MIN_LENGTH-n);
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
