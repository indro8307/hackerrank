#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

vector<string> split_string(string);
#define MAX_NUM_CHILD_NODES   26
struct Tnode
{
    //unordered_map<char,Tnode*> children;
    vector<Tnode*> children;
    //unsigned long output;
    vector<int> hindex;
    Tnode *failover;
    char ch;
    Tnode(){
        children = vector<Tnode*>(26);
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        //output = 0;
        failover = NULL;
        ch = ' ';
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split_string(genes_temp_temp);

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split_string(health_temp_temp);

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

        // building a trie datastructure from these substrings
        Tnode *root = new Tnode();
        for(int i=0;i<genes.size();i++)
        {
            int len = strlen(genes[i].c_str());
            Tnode *node = root;
            for(int j=0;j<len;j++)
            {
                /* check if child exists */
                if(node->children[genes[i][j] - 'a'] != NULL)
                {
                    /* child node exists */
                    if(j == (len-1))
                    {
                        //node->children[genes[i][j] - 'a']->output += health[i];
                        node->children[genes[i][j] - 'a']->hindex.push_back(i);
                        sort(node->children[genes[i][j] - 'a']->hindex.begin(),node->children[genes[i][j] - 'a']->hindex.end());
                    }
                }
                else
                {
                    /* child node does not exist */
                    Tnode *tmpnode = new Tnode();
                    tmpnode->ch = genes[i][j];
                    if(j == (len-1))
                    {
                        //tmpnode->output += health[i];
                        tmpnode->hindex.push_back(i);
                        sort(tmpnode->hindex.begin(),tmpnode->hindex.end());
                    }
                    node->children[genes[i][j] - 'a'] = tmpnode;
                }
                node = node->children[genes[i][j] - 'a'];
            }
        }

        // Building the fails
        queue<Tnode*> qnodes;
        // inserting all the child of the root node in the queue first
        int a = 0;
        while(a < MAX_NUM_CHILD_NODES)
        {
            Tnode *tmpnode = root->children[a];
            if(tmpnode != NULL)
            {
                tmpnode->failover = root;
                qnodes.push(tmpnode);
            }
            a++;
        }
        while(!(qnodes.empty()))
        {
            Tnode *tmp = qnodes.front();
            qnodes.pop();
            // access each child and do the following:
            // 1. Set the failover for that node.
            // 2. update output based on the failover node
            // 3. push all children in the queue
            int a = 0;
            Tnode *v = NULL;
            while(a < MAX_NUM_CHILD_NODES)
            {
                Tnode *childnode = tmp->children[a];
                if(childnode != NULL)
                {
                    // check failover nodes
                    v = tmp->failover;
                    while(v!=NULL)
                    {
                        // check if this failover node contains  child with the same value
                        if(v->children[childnode->ch - 'a'] != NULL)
                        {
                            // node found. this will be the failover node
                            childnode->failover = v->children[childnode->ch - 'a'];
                            // update the output
                            //childnode->output += v->children[childnode->ch - 'a']->output;
                            /*int len = v->children[childnode->ch - 'a']->hindex.size();
                            for(int i=0;i<len;i++)
                            {
                                childnode->hindex.push_back(v->children[childnode->ch - 'a']->hindex[i]);
                            }
                            sort(childnode->hindex.begin(),childnode->hindex.end());*/
                            break;
                        }
                        else
                        {
                            // node not found. check the previous failover node
                            v = v->failover;
                        }
                    }
                    if(childnode->failover == NULL)
                    {
                        childnode->failover = root;
                    }
                    qnodes.push(childnode);
                }
                a++;
            }
        }    

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    unsigned long max_health=0;
    unsigned long min_health=0;
    for (int s_itr = 0; s_itr < s; s_itr++) {
        string firstLastd_temp;
        getline(cin, firstLastd_temp);

        vector<string> firstLastd = split_string(firstLastd_temp);

        int first = stoi(firstLastd[0]);

        int last = stoi(firstLastd[1]);

        string d = firstLastd[2];
 
        // Performing the search
        unsigned long h=0;
        int str_len = strlen(d.c_str());
        Tnode *temp1 = root;
        int l=0;
        bool printfailovers = false;
        Tnode *temp2 = NULL;
        while(l<str_len)
        {
            if(printfailovers == true)
            {
                if(temp1 == root)
                {
                    temp1 = temp2->children[d[l] - 'a'];
                    printfailovers = false;
                    l++;                     
                }
                else
                {
                    int index = 0;
                    for(int i=0;i<temp1->hindex.size();i++)
                    //for(int i=0;index<=last;i++)
                    {
                        index = temp1->hindex[i];
                        if(index > last)
                        {
                            break;
                        }
                        if((index >= first) && (index <= last))
                        {
                            h = h + health[index];
                        }
                    }
                    temp1 = temp1->failover;

                }
            }
            else if(temp1->children[d[l] - 'a'] != NULL)
            {
                // match found. do the following:
                // 1. if the node has any output, print them
                // 2. update temp1   
                //cout<<p->second.ch<<endl;
                int index = 0;
                for(int i=0;i<temp1->children[d[l] - 'a']->hindex.size();i++)
                //for(int i=0;index<=last;i++)
                {
                    index = temp1->children[d[l] - 'a']->hindex[i];
                    if(index > last)
                    {
                        break;
                    }
                    if((index >= first) && (index <= last))
                    {
                        h = h + health[index];
                    }
                }
                //h = h + temp1->children[d[l] - 'a']->output;
                temp2 = temp1;
                printfailovers = true;
                temp1 = temp1->children[d[l] - 'a']->failover;

            }
            else
            {
                // character is not found. If temp1 is the root node, then do       nothing.
                // just increment i
                if(temp1 == root)
                {
                    l++;
                    continue;
                }
                else
                {
                    // temp1 is not the root node and match is not found among the children
                    // fall back to the fail node and repeat search
                    temp1 = temp1->failover;
                }                
            }
        }
        if(s_itr==0)
        {
            min_health = max_health = h;
        }
        if(h<min_health){
            min_health = h;
        }
        else if(h>max_health){
            max_health = h;
        }                    
    }
    cout<<min_health<<" "<<max_health;
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
