#include <iostream>
#include <string>

using namespace std;

string ReplacePatternWithAsterisks(const string& s, bool& foundPattern) {
    foundPattern = false;
    string result = "";
    size_t length = s.length();

    for (size_t i = 0; i < length; ++i) {
        if (i + 2 < length && (s.substr(i, 3) == "OGO" || s.substr(i, 3) == "AGA")) {
            result += "**";
            foundPattern = true;
            i += 2;
        }
        else {
            result += s[i];
        }
    }

    return result;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    bool foundPattern;
    string result = ReplacePatternWithAsterisks(str, foundPattern);

    if (foundPattern) {
        cout << "Pattern 'OGO' or 'AGA' found: yes" << endl;
    }
    else {
        cout << "Pattern 'OGO' or 'AGA' found: no" << endl;
    }

    cout << "Modified string: " << result << endl;

    return 0;
}
