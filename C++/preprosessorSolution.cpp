/*
https://www.hackerrank.com/challenges/preprocessor-solution/problem
*/

/* Enter your macros here */
#define INF 100000000
#define FUNCTION(arg1, op)    \
void arg1(int &a, int &b){   \
    if(b op a){ \
        a = b;  \
    }   \
}   \

#define toStr(x) #x
#define foreach(v, i) for(int i=0;i<v.size();i++)
#define io(v) cin>>v

