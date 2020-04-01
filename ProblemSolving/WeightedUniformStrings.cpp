/*
https://www.hackerrank.com/challenges/weighted-uniform-string/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    int len = s.length();
    vector<string> ret(queries.size());
    map<char,vector<unsigned long>> m;
    map<char,vector<unsigned long>>::iterator it;
    char prev = s[0];
    int tempweight = (s[0]-'a')+1;
    //m[0] = (s[0]-'a')+1;

    for(int i=1;i<len;i++)
    {
        if(s[i] == prev)
        {
            tempweight += (s[i]-'a')+1;
        }
        else
        {
            it = m.find(prev);
            if(it != m.end())
            {
                (it->second).push_back(tempweight);
                tempweight = (s[i]-'a')+1;
            }
            else
            {
                vector<unsigned long> w;
                w.push_back(tempweight);
                m[prev] = w;
                tempweight = (s[i]-'a')+1;
            }
        }
        prev = s[i];
    }
    it = m.find(prev);
    if(it != m.end())
    {
        (it->second).push_back(tempweight);
    }
    else
    {
        vector<unsigned long> w;
        w.push_back(tempweight);
        m[prev] = w;
    }    
    /*for(map<char,vector<unsigned long>>::iterator i=m.begin();i!=m.end();i++)
    {
        vector<unsigned long> v = i->second;
        cout<<i->first<<endl;
        for(int k=0;k<v.size();k++)
        {
            cout<<"    "<<v[k]<<endl;
        }
    }                                                  
    */
    unsigned long num =0, b=0;
    for(int j=0;j<queries.size();j++)
    {
        ret[j] = "No";
        num = b = 0;
        for(it=m.begin();it!=m.end();it++)
        {
            vector<unsigned long> w = it->second;
            for(int i=0;i<w.size();i++)
            {
                if(queries[j] > w[i])
                    continue;
                num =  (it->first-'a')+1;
                b = w[i] - queries[j];
                if(b%num == 0)
                { 
                    ret[j] = "Yes";
                    break;
                }                
            }
            if(ret[j] == "Yes")
                break;
            //cout<<queries[j]<<"%"<<it->second<<endl;
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
