/*
https://www.hackerrank.com/challenges/magic-square-forming/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int refarr[8] = {8,3,4,9,2,7,6,1};
    vector<int> cost(8,0);
    deque<int> a;
    a.push_back(s[0][0]);
    a.push_back(s[0][1]);
    a.push_back(s[0][2]);
    a.push_back(s[1][2]);
    a.push_back(s[2][2]);
    a.push_back(s[2][1]);
    a.push_back(s[2][0]);
    a.push_back(s[1][0]);

    cost[0] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5);

    int front1 = a.front();
    a.pop_front();
    int front2 = a.front();
    a.pop_front();
    a.push_back(front1);
    a.push_back(front2);

     cost[1] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5);   

    front1 = a.front();
    a.pop_front();
    front2 = a.front();
    a.pop_front();
    a.push_back(front1);
    a.push_back(front2);

     cost[2] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5); 

    front1 = a.front();
    a.pop_front();
    front2 = a.front();
    a.pop_front();
    a.push_back(front1);
    a.push_back(front2);

     cost[3] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5); 

    a.clear();
    a.push_back(s[0][2]);
    a.push_back(s[0][1]);
    a.push_back(s[0][0]);
    a.push_back(s[1][0]);
    a.push_back(s[2][0]);
    a.push_back(s[2][1]);
    a.push_back(s[2][2]);
    a.push_back(s[1][2]);

    cost[4] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5);

    front1 = a.front();
    a.pop_front();
    front2 = a.front();
    a.pop_front();
    a.push_back(front1);
    a.push_back(front2);

     cost[5] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5);   

    front1 = a.front();
    a.pop_front();
    front2 = a.front();
    a.pop_front();
    a.push_back(front1);
    a.push_back(front2);

     cost[6] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5); 

    front1 = a.front();
    a.pop_front();
    front2 = a.front();
    a.pop_front();
    a.push_back(front1);
    a.push_back(front2);

     cost[7] = abs(refarr[0]-a[0]) +
                abs(refarr[1]-a[1]) +
                abs(refarr[2]-a[2]) +
                abs(refarr[3]-a[3]) +
                abs(refarr[4]-a[4]) +
                abs(refarr[5]-a[5]) +
                abs(refarr[6]-a[6]) +
                abs(refarr[7]-a[7]) +
                abs(s[1][1]-5); 

    sort(cost.begin(),cost.end());
    return cost[0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
