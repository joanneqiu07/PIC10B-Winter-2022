/* PIC 10B, Final Exam Part II
   Problem: Combination
   Author: Joanne Qiu
   Date: 03/17/2022
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void make_comb(vector<vector<int>>& comb, vector<int>& temp, vector<int> num, int n, int pos, int k)
{
    // append the temp vector to the comb vector when k == 0
    if (k == 0)
    {
        comb.push_back(temp);
        return;
    }
    
    // the recursion makes the different temp vectors with different starting points i
    for (int i = pos; i < n; ++i)
    {
        // different starting points i
        temp.push_back(num[i]);
        
        // append the integers to the temp vector until k == 0
        make_comb(comb,temp, num, n, i+1, k-1);
        
        // remove the current last integer
        temp.pop_back();
    }
}


int main() {
    // declare the input and output stream
    ifstream input;
    ofstream output;
    
    // open the input file
    input.open("numbers.txt");
    
    // test if the file is open
    if (input.fail()) {
        cout << "Error opening number.txt" << endl;
        return 1;
    }
    
    // get the distinct integers from the file
    int num, n;
    string s;
    vector<int> in;
    while (getline(input, s, ','))
    {
        istringstream instr(s);
        instr >> num;
        // test if an integer already exists in the vector
        if (find(in.begin(), in.end(), num) == in.end()) in.push_back(num);
    }
    n = in.size();
    sort(in.begin(), in.end());
    
    // get the length of combinations from the user
    int k;
    cout << "There are n = " << n << " distinct numbers in the file. Input an non-negative integer k ≤ n: ";
    cin >> k;
    
    // set the name for the output file and open the file
    string file_name = to_string(k) + "_combinations.txt";
    output.open(file_name);
    
    // make the combinations
    vector<vector<int>> answer;
    vector<int> temp;
    make_comb(answer, temp, in, n, 0, k);
    int len = answer.size();
    output << "There are " << len << " " << k << "-combinations from this input:" << "\n";
    
    // save the combinations to the output file
    for (int i = 0; i < answer.size(); i++) {
        output << "(";
        for (int j = 0; j < answer[i].size(); j++) {
            if (j == answer[i].size() - 1) output << answer[i][j];
            else output << answer[i][j] << ",";
        }
        output << ")" << "\n";
    }
    
    // close the files
    input.close();
    output.close();
    
    return 0;
}
