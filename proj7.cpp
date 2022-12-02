#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Prototypes
bool beginWithNum (string &words);
bool beginWithChar (string &words);
string separateStr (string &words);
bool compareCharValues (const pair<char, int> &a, const pair<char, int> &b);
bool compareStrValues (const pair<string, int> &a, const pair<string, int> &b);
vector<pair<string, int>> sortString (unordered_map<string, int> &W);
void Print (vector<pair<string,int>> &V);
void findFrequencyChar (string &words);
void findFrequencyWordsNumbers (string &words);

int main() {

    string words;

    do {
        cout << R"(Type "quit*" to quit and "*" to enter.)" << endl;
        cout << "Please enter words, phrases, or sentences: " << endl;
        getline(cin,words, '*');
        //Convert string to lowercase
        //Source: GeeksforGeeks.com
        transform(words.begin(), words.end(), words.begin(), ::tolower);
        findFrequencyChar(words);
        cout << endl;
        findFrequencyWordsNumbers(words);
    }
    while (words != "quit");

    return 0;
}


// *************************************************************
// *                     Helper Functions                      *
// *************************************************************

// *************************************************************
// * Name: beginWithNum()                                      *
// * Description: Function that determines whether a string    *
// * word is a number.                                         *
// * Source: N/A                                               *
// *************************************************************

bool beginWithNum (string &words) {

    if (words.length() == 0 ) {
        return false;
    }
    return isdigit(words[0]);
}

// *************************************************************
// * Name: beginWithChar()                                     *
// * Description: Function that determines whether a string    *
// * word is a character.                                      *
// * Source: N/A                                               *
// *************************************************************

bool beginWithChar (string &words) {

    if (words.length() == 0) {
        return false;
    }
    return isalpha(words[0]);
}



// *************************************************************
// * Name: separateStr()                                       *
// * Description: Function that takes in a string and          *
// * separates it with a space if words are next to numbers    *
// * are next to unique characters.                            *
// * Source: N/A                                               *
// *************************************************************


string separateStr (string &words) {

    string space = " ";
    string temp;
    int counter = 0;
    for (int i = 0; i < words[i] + counter; i++) {
        if (isalpha(words[i])) {
            if (isalpha(words[i-1])) temp += words[i];
            else {
                temp += space + words[i];
                counter++;
            }

        } else if (isdigit(words[i])) {
            if (isdigit(words[i-1])) temp += words[i];
            else {
                temp += space + words[i];
                counter++;
            }
        } else {
            temp += space + words[i];
            counter++;
        }
    }
    return temp;

}


// *************************************************************
// * Name: compareCharValues()                                 *
// * Description: Function that sorts the Hash Table. If the   *
// * integers aren't equal then it sorts out those values,     *
// * but if those are equal then it sorts out the char values. *
// * Source: N/A                                               *
// *************************************************************

bool compareCharValues (const pair<char, int> &a, const pair<char, int> &b) {

    if (a.second != b.second) {
        return a.second > b.second;
    }

    return a.first < b.first;

}


// *************************************************************
// * Name: compareStrValues()                                  *
// * Description: Function that sorts the Hash Table. If the   *
// * integers aren't equal then it sorts out those values, but *
// * if those are equal then it sorts out the string values.   *
// * Source: N/A                                               *
// *************************************************************

bool compareStrValues (const pair<string, int> &a, const pair<string, int> &b) {

    if (a.second != b.second) {
        return a.second > b.second;
    }

    return a.first < b.first;

}


// *************************************************************
// * Name: sortString()                                        *
// * Description: Function that puts the map into a Hash table *
// * before sorting it. Returns Hash table.                    *
// * Source: N/A                                               *
// *************************************************************


vector<pair<string, int>> sortString (unordered_map<string, int> &W) {

    vector<pair<string, int>> V;
    for (auto x : W)
        V.emplace_back(x);
    sort(V.begin(), V.end(), compareStrValues);
    return V;
}

// *************************************************************
// * Name: Print()                                             *
// * Description: Function that prints the top ten words and   *
// * numbers of Hash table.                                    *
// * Source: N/A                                               *
// *************************************************************

void Print (vector<pair<string,int>> &V) {

    if (V.size() < 10) {
        for(auto & i : V)
            cout << i.first << " " << i.second << endl;
    } else {
        for(int i = 0; i < 10; i++) {
            cout << V[i].first << " " << V[i].second << endl;
        }
    }

    cout << endl;

}



// *************************************************************
// *                        Char                               *
// *************************************************************

// *************************************************************
// * Name: findFrequencyChar()                                 *
// * Description: Function that puts the string into a Hash    *
// * Table using the map STL. It declares a map W that takes   *
// * each character and counts each unique char. Prints the    *
// * HashTable and the char count after sorting the Hash table *
// * Source: GeeksforGeeks.com                                 *
// *************************************************************

void findFrequencyChar (string &words) {

    unordered_map<char, int> W;
    int charCount = 0;

    //Insert pair into map W
    for (int i = 0; words[i]; i++) {
        if (W.find(words[i]) == W.end()) {
            W.insert(make_pair(words[i],1));
            charCount++;
        } else {
            W[words[i]]++;
            charCount++;
        }
    }

    //Sort the map W by putting it into Hash Table V
    vector<pair<char, int>> V;
    for (auto x : W)
        V.emplace_back(x);
    sort(V.begin(), V.end(), compareCharValues);

    //Print out the Char Count
    cout << "Total Characters: " << charCount << endl;

    char space = ' ';
    auto tab = '\t';
    auto nline = 'endl';
    //Print out the TOP TEN Pairs
    if (V.size() < 10) {
        for(auto & i : V) {
            if (i.first == space) cout << "space " << i.second << endl;
            else if (i.first == tab) cout << "tab " << i.second << endl;
            else if (i.first == nline) cout << "new line " << i.second << endl;
            else cout << i.first << " " << i.second << endl;
        }
    } else {
        for(int i = 0; i < 10; i++) {
            if (V[i].first == space) cout << " " << V[i].second << endl;
            else if (V[i].first == tab) cout << "tab " << V[i].second << endl;
            else if (V[i].first == nline) cout << "new line " << V[i].second << endl;
            else cout << V[i].first << " " << V[i].second << endl;
        }
    }

}


// *************************************************************
// *                     Words & Numbers                       *
// *************************************************************

// *************************************************************
// * Name: findFrequencyStr()                                  *
// * Description: Function that puts the string into a Hash    *
// * Table using the map STL. It declares a map W and N that   *
// * takes each string and counts each unique word and number. *
// * Calls the Sort function to sort each Hash table and calls *
// * Prints function.                                          *
// * and the word count.                                       *
// * Source: GeeksforGeeks.com                                 *
// *************************************************************

void findFrequencyWordsNumbers (string &words) {

    unordered_map<string, int> W;
    unordered_map<string, int> N;

    stringstream stringInput(separateStr(words));
    int wordCount = 0;
    int numCount = 0;

    //Insert pair into map W and count number of Words
    while (stringInput >> words) {
        if (beginWithChar(words)) {
            if (W.find(words) == W.end()) {
                W.insert(make_pair(words, 1));
                wordCount++;
            } else {
                W.find(words)->second++;
                wordCount++;
            }
        } else if (beginWithNum(words)) {
            if (N.find(words) == N.end()) {
                N.insert(make_pair(words, 1));
                numCount++;
            } else {
                N.find(words)->second++;
                numCount++;
            }
        }
    }

    //Sort map W and N by putting it in Hash Table V and Print Word and Num
    auto V = sortString(W);
    auto V2 = sortString(N);

    cout << "Total word count: " << wordCount << endl;
    Print(V);
    cout << "Total number count: " << numCount << endl;
    Print(V2);

}
