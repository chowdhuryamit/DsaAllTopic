#include <iostream>
#include <string>
using namespace std;

int solve(string& s, int index) {
    // Base case: If we reach the end of the string, it's a valid decoding
    if (index >= s.size()) {
        return 1;
    }

    // If the current character is '0', it cannot be decoded
    if (s[index] == '0') {
        return 0;
    }

    // Decode single-digit (valid if current character is non-zero)
    int ans = solve(s, index + 1);

    // Decode two-digit (valid if within range 10 to 26)
    if (index + 1 < s.size()) {
        int twoDigit = (s[index] - '0') * 10 + (s[index + 1] - '0'); // Form two-digit number
        if (twoDigit >= 10 && twoDigit <= 26) {
            ans += solve(s, index + 2);
        }
    }

    return ans;
}

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0; // Early return for invalid inputs
    return solve(s, 0);
}

int main() {
    string s = "1201234";
    cout << "Number of ways to decode: " << numDecodings(s) << endl;
    return 0;
}
