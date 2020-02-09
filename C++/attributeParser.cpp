/*
https://www.hackerrank.com/challenges/attribute-parser/problem
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <map>
#include <stack>
using namespace std;

class node
{
public:
    string name;
    //map<string,node> child;
    node *child[100];
    int index;
};

//map<string,node*> level1;
vector<node*> level1;

bool checkHierarchy(char* tag, node **tmp)
{
    bool ret = false;
    vector<node*>::iterator it;
    if(*tmp==NULL){
        for(it = level1.begin();it != level1.end();it++)
        {
            string s(tag);
            node *a = *it;
            if(a->name == s){
                ret = true;
                *tmp = a;
                break;
            }
        }
    }
    else{
        for(int i=0;i<(*tmp)->index;i++){
            string s(tag);
            if(s == (*tmp)->child[i]->name){
                *tmp = (*tmp)->child[i];
                ret = true;
                break;
            }
        }
    }               
    return ret;     
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    string in_str;
    std::getline(std::cin, in_str);
    std::istringstream sin(in_str);
    sin>>N>>Q;

    // Readng the HRML file
    int i=0;
    vector<string> hrml_code(N);
    while(i<N)
    {
        std::getline(std::cin, hrml_code[i]);
        i++;
    }
    
    // Reading the queries
    i = 0;
    vector<string> queries(Q);
    while(i<Q)
    {
        std::getline(std::cin, queries[i]);
        i++;
    }

    //create a hierarchy of nodes
    i=0;
    stack<node*> exp;
    while(i<N)
    {
        std::istringstream z(hrml_code[i].c_str());
        string tag;
        z>>tag;
        /* strip '<', '>' and '/' characters*/
        tag.erase(std::remove(tag.begin(),tag.end(),'<'),tag.end());
        tag.erase(std::remove(tag.begin(),tag.end(),'>'),tag.end());
        if(strstr(tag.c_str(),"/")){
            // this is a closing tag
            tag.erase(std::remove(tag.begin(),tag.end(),'/'),tag.end());
            if(tag == exp.top()->name){
                node *tmp = exp.top();
                exp.pop();
                if(exp.empty()){
                    level1.push_back(tmp);
                }
            }
            else{
                cout<<"ERROR: should not have reached here"<<endl;
            }
            
        }
        else{
            //node a;
            // if exp is empty, then tag is level1 element
            if(!exp.empty()){
                node *tmp = exp.top();
                node *child1 = new node();
                child1->name = tag;
                child1->index = 0;
                tmp->child[tmp->index] = child1;
                tmp->index++;
                exp.push(child1);
            }
            else{
                node *a = new node();
                a->name = tag;
                a->index = 0;
                exp.push(a);
            }
            
        }


        i++;
    }
    
    vector<node*>::iterator it;
    // Parse each query
    i = 0;
    int j = 0;
    char temp[200] = {0};
    while(i<Q)
    {
        strcpy(temp,queries[i].c_str());
        char *tok = strtok(temp,".");
        j = 0;
        node *tmp1 = NULL;
            // the query is in the form of tag1.tag2. ...
            // Have to parse the query here
            while(tok != NULL){
                if(strstr(tok,"~")){
                    char *tok_val = strtok(tok,"~");
                    if(!checkHierarchy(tok_val,&tmp1)){
                        cout<<"Not Found!"<<endl;
                        break;
                    }
                    std::ostringstream sout;
                    sout<<"<"<<tok_val<<" ";
                    j=0;
                    while(j<N){
                        char *a = strstr((char*)hrml_code[j].c_str(), sout.str().c_str());
                        if(a != NULL){
                            break;
                        }
                        j++;
                    }
                    if(j==N){
                        cout<<"Not Found!"<<endl;
                        break;
                    }
                    tok_val = strtok(NULL,"~");
                    std::ostringstream sout1;
                    sout1<<" "<<tok_val<<" ";
                    char *b = strstr((char*)hrml_code[j].c_str(), sout1.str().c_str());
                    if(b == NULL){
                        cout<<"Not Found!"<<endl;
                        break;
                    }
                    else{
                        std::istringstream str2(b);
                        string a,b,c;
                        str2>>a>>b>>c;
                        char *d = strtok((char*)c.c_str(),"\"");
                        cout<<d<<endl;
                        break;
                    }
                }
                else{
                    if(!checkHierarchy(tok,&tmp1)){
                        cout<<"Not Found!"<<endl;
                        break;
                    }
                    tok = strtok(NULL,".");
                }
                
            }

        i++;
    }
    return 0;
}
