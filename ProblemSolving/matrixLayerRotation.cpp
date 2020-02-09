#include <bits/stdc++.h>
#include <deque>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    // find the size of the matrix
    int m = matrix.size();  // number of rows
    int n = matrix[0].size();  // umber of columns
    int arr[m][n] = {0};

    // find the number of inner arrays
    int m_inner = m;
    int n_inner = n;
    int count = 0;
    while((m_inner>=2) && (n_inner>=2))
    {
        m_inner = m_inner-2;
        n_inner = n_inner-2;
        count++;
    }
    // store each layer in separate deque s
    int i=0;
    int row = 0;
    int col = 0;
    int jcol = 0;
    int jrow = 1;
    int jrow1 = 0;
    while(i<count)
    {
        //copy the i'th layer in a deque
        deque<int> b;
        //int num_elements = (2*m)+(2*(n-2));
        for(int j=jcol;j<n;j++)
        {
            b.push_back(matrix[row][j]);
        }
        for(int j=jrow;j<m;j++)
        {
            b.push_back(matrix[j][n-1]);
        }
        for(int j=n-2;j>=jcol;j--)
        {
            b.push_back(matrix[m-1][j]);
        }
        for(int j=m-2;j>jrow1;j--)
        {
            b.push_back(matrix[j][col]);
        }    
        // now rotate this r%b.size() times
        int z = r%b.size();
        for(int k=0;k<z;k++)
        {
            int temp = b.front();
            b.pop_front();
            b.push_back(temp);
        }
        //write the updated list to the new 2D array
        for(int j=jcol;j<n;j++)
        {
            arr[row][j] = b.front();
            b.pop_front();
        }
        for(int j=jrow;j<m;j++)
        {
            arr[j][n-1] = b.front();
            b.pop_front();
        }
        for(int j=n-2;j>=jcol;j--)
        {
            arr[m-1][j] = b.front();
            b.pop_front();
        }
        for(int j=m-2;j>jrow1;j--)
        {
            arr[j][col] = b.front();
            b.pop_front();
        }
        i++;               
        row++;
        col++;
        n--;
        m--;
        jcol++;
        jrow++;
        jrow1++;
    } 
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
