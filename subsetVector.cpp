#include <iostream>
#include <vector>
using namespace std;

vector<string> generateSubsets(string input, int i, string current){
    vector<string> output;
    if(i == input.length() - 1){
        output.push_back(current + input[i]);
        output.push_back(current);
        return output;
    }
    vector<string> with = generateSubsets(input, i+1, current + input[i]);
    vector<string> without = generateSubsets(input, i+1, current);
    output.insert(output.end(), with.begin(), with.end());
    output.insert(output.end(), without.begin(), without.end());
    return output;
}

int main(){
    string input = "1234";
    vector<string> output = generateSubsets(input, 0, "");
    for(int i = 0; i < output.size(); i++){
        cout<< output[i]<<endl;
    }
}
