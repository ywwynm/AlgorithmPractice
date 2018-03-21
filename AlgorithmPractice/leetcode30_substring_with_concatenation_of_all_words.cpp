#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void show_int_vector(vector<int> list) {
    for (auto val : list) {
      cout << val << " ";
    }
    cout << endl;
  }

  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int s_len = s.length(), word_len = words[0].length();
    if (s_len < word_len) return res;

    int words_size = words.size();
    vector<int> map(s_len - word_len + 1);
    for (int i = 0; i <= s_len - word_len; i++) {
      bool same_to_one_word = false;
      for (int wi = 0; wi < words_size; wi++) {
        bool same_to_this_word = true;
        for (int j = i, k = 0; j < i + word_len; j++, k++) {
          if (s[j] != words[wi][k]) {
            same_to_this_word = false;
            break;
          }
        }
        if (same_to_this_word) {
          same_to_one_word = true;
          map[i] = wi;
          break;
        }
      }
      if (!same_to_one_word) map[i] = -1;
    }

    cout << "map: ";
    show_int_vector(map);

    int total_words_len = word_len * words_size;
    vector<bool> found(words_size, false);
    int matched_word_count = 0;
    int match_start_index = 0;
    for (int i = 0; i <= s_len - total_words_len; ) {
      cout << i << ", " << map[i];
      if (map[i] != -1) {
        cout << ", " << found[map[i]] << endl;
      } else cout << endl;
      if (map[i] == -1) {
        i++;
        match_start_index = i;
      } else {
        found[map[i]] = true;
        matched_word_count++;
        for (int j = i + word_len; matched_word_count != words_size; j += word_len) {
          if (map[j] == -1) {
            i++;
            break;
          } else {
            bool duplicated = false;
            for (int k = 0; k < words_size; k++) {
              if (found[map[j]]) {
                duplicated = true;
                break;
              }
            }
            if (duplicated) {
              i++;
              break;
            }
            found[map[j]] = true;
            matched_word_count++;
          }
        }
        if (matched_word_count == words_size) {
          res.push_back(match_start_index);
          found[map[i]] = false;
          match_start_index = i + word_len;
          i += total_words_len;
          matched_word_count--;
        } else {
          matched_word_count = 0;
          match_start_index = i;
          for (int j = 0; j < words_size; j++) found[j] = false;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  string s = "barfoobarthefoobarman";
  vector<string> words;
  words.push_back("foo");
  words.push_back("bar");
  vector<int> res = solution.findSubstring(s, words);
  solution.show_int_vector(res);
  return 0;
}