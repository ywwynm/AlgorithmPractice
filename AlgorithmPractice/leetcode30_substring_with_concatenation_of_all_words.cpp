#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int word_len = words[0].length();
    int total_words_len = word_len * words.size();
    for (int i = 0; i <= s.length() - total_words_len; i++) {

    }
    return res;
  }
};

int main() {
  Solution solution;
  string s = "barfoothefoobarman";
  vector<string> words;
  words.push_back("foo");
  words.push_back("bar");
  vector<int> res = solution.findSubstring(s, words);
  for (auto i : res) cout << i << " ";
  cout << endl;
  return 0;
}