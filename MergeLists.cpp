
#define DEBUG 0

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool byRevAlphabet(string a, string b) { return tolower(a[0]) > tolower(b[0]);}
bool byStrLength(string a, string b) { return a.size() > b.size(); }

vector<string> MergeLists(vector<string> Original, vector<string> toAdd, vector<string> toDel){
    
    vector<string> Result;

    // add to Result only strings that aren't already in it
    // AND that are not in Delete list
    for (string word : Original) {

        if (find(Result.begin(), Result.end(), word) == Result.end()) {  // check in Result
            if (find(toDel.begin(), toDel.end(), word) == toDel.end())   //check in Delete
                Result.push_back(word);
        }
    }

    // add to Result only strings that it doesn't already have
    // AND that don't appear in Delete List
    for (string word : toAdd) {

        if (find(Result.begin(), Result.end(), word) == Result.end()) {//check in Result
            if (find(toDel.begin(), toDel.end(), word) == toDel.end())//check in Delete
                Result.push_back(word);
        }
    }

    //arrange in reverse alphabetical order for tie cases
    sort(Result.begin(), Result.end(), byRevAlphabet);

#if DEBUG   //debugging block to check correct alph. sorting
    cout << "after alph reverse Result is: ";
    for (string s : Result)
        cout << s << " ";
    cout << endl << endl;
#endif

    //sort by decreasing string length
    sort(Result.begin(), Result.end(), byStrLength);
    
    return Result;
}
