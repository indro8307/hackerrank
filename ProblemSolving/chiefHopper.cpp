/*
https://www.hackerrank.com/challenges/chief-hopper/problem
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the chiefHopper function below.
int chiefHopper(vector<int> arr) {
    long long botEnergy = 0;
    int minEnergy = 0;
    int tempEnergy = 0;
    int prevEnergy = 0;
    int i=0;
    while(i<arr.size())
    {
        tempEnergy = arr[i];
        botEnergy = tempEnergy;
        for(int j=0;j<arr.size();j++)
        {
            //botEnergy = (botEnergy>arr[j])?(botEnergy+(botEnergy-arr[j])):(botEnergy-(arr[j]-botEnergy));
            //cout<<i<<" "<<j<<". botEnergy = "<<botEnergy<<" "<<arr[j]<<endl; 
            if(botEnergy>arr[j])
            {
                botEnergy = botEnergy + (botEnergy - arr[j]);
            }
            else 
            {
                //cout<<"here"<<endl;
                botEnergy = botEnergy - (arr[j] - botEnergy);
            }
            if(botEnergy > 10516532)
            {
                break;
            }
            if(botEnergy < 0)
            {
                break;
            }
        }
        if(botEnergy < 0)
        {
            i++;
        }
        else {
            break;
        }
    }
    //cout<<"tempEnergy = "<<tempEnergy<<endl;
    // now search in the backward 
    while(tempEnergy > 0)
    {
        botEnergy = tempEnergy;
        for(int i=0;i<arr.size();i++)
        {
            //botEnergy = (botEnergy>arr[i])?(botEnergy+(botEnergy-arr[i])):(botEnergy-(arr[i]-botEnergy));
            if(botEnergy>arr[i])
            {
                botEnergy = botEnergy + (botEnergy - arr[i]);
            }
            else 
            {
                botEnergy = botEnergy - (arr[i] - botEnergy);
            }            
            //cout<<tempEnergy<<". botEnergy = "<<botEnergy<<endl;
            // 10516532 is a random safe number.
            // Assuming that if botEnergy exceeds this number, then energy would be sufficient to cover all heights.
            // Not a very elegant approach, but it worked.
            if(botEnergy > 10516532)   
            {
                break;
            }            
            if(botEnergy < 0)
            {
                break;
            }
        }
        if(botEnergy < 0)
        {
            break;
        }
        prevEnergy = tempEnergy;        
        tempEnergy--;
    }    
    //minEnergy++;
    return prevEnergy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = chiefHopper(arr);

    fout << result << "\n";

    fout.close();

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
