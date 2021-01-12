#include <iostream>
#include <vector>

using namespace std;
bool isValidPart(const string &s);
vector<string> restoreIpAddresses(string s);
int main() {
	string s = "25525511135";
	vector<string> res;
	res = restoreIpAddresses(s);

	for(int i=0; i<res.size(); i++){
		cout << res[i] << " , ";
	}
	return 0;
}

vector<string> restoreIpAddresses(string s) {
    if (s.length() < 3 || s.length() > 12) return {};
    vector<string> ans;
    for (int i = 1; i < 4; ++i) {
    	string first = s.substr(0, i);
        if (isValidPart(first)) {
            for (int j = 1; i + j < s.length(); ++j) {
                const string second = s.substr(i, j);
                if (isValidPart(second)) {
                    for (size_t k = 1; k + i + j < s.length() && k < 4; ++k) {
                        const string third = s.substr(i + j, k),
                        fourth = s.substr(i + j + k);
                        if (isValidPart(third) && isValidPart(fourth)) {
                            ans.emplace_back(first + "." + second + "." + third + "." + fourth);
                        }
                    }
                }
            }
        }
    }

    return ans;
}

bool isValidPart(const string &s) {
    if (s.length() > 3)
        return false;
    // "00", "000", "01", etc. Are not valid, but "0" is valid.
    if (s[0] == '0' && s.length() > 1)
        return false;

    int val = stoi(s);
    return val <= 255 && val >= 0;
}
