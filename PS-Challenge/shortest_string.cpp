#include <bits/stdc++.h>
using namespace std;

string shortestWord(const vector<string>& words) {
    if (words.empty()) return "";

    string res = words[0];
    for (auto &word : words) {
        if (word.length() < res.length())
            res = word;
    }
    return res;
}

int main() {
     vector<string> words = {"code", "backend", "ai", "circle"};
    cout << shortestWord(words) << endl;
    return 0;
}
