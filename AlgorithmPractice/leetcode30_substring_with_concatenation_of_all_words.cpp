//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//  void show_int_vector(vector<int> list) {
//    for (auto val : list) {
//      cout << val << " ";
//    }
//    cout << endl;
//  }
//
//  vector<int> findSubstring(string s, vector<string>& words) {
//    vector<int> res;
//    int s_len = s.length(), word_len = words[0].length();
//    if (s_len < word_len) return res;
//
//    int words_size = words.size();
//    vector<int> map(s_len - word_len + 1);
//    for (int i = 0; i <= s_len - word_len; i++) {
//      bool same_to_one_word = false;
//      for (int wi = 0; wi < words_size; wi++) {
//        bool same_to_this_word = true;
//        for (int j = i, k = 0; j < i + word_len; j++, k++) {
//          if (s[j] != words[wi][k]) {
//            same_to_this_word = false;
//            break;
//          }
//        }
//        if (same_to_this_word) {
//          same_to_one_word = true;
//          map[i] = wi;
//          break;
//        }
//      }
//      if (!same_to_one_word) map[i] = -1;
//    }
//
//    /*cout << "map: ";
//    show_int_vector(map);*/
//
//    int total_words_len = word_len * words_size;
//    vector<bool> found(words_size, false);
//    int matched_word_count = 0;
//    int match_start_index = 0;
//    for (int i = 0; i <= s_len - word_len; ) {
//      cout << "match_start: " << match_start_index << endl;
//      cout << "matched_word_count: " << matched_word_count << endl;
//      cout << i << ", " << map[i];
//      if (map[i] != -1) {
//        cout << ", " << found[map[i]] << endl;
//      } else cout << endl;
//
//      if (map[i] == -1) {
//        cout << "i, map[" << i << "] == -1" << endl;
//        i++;
//        matched_word_count = 0;
//        match_start_index = i;
//        for (int j = 0; j < words_size; j++) found[j] = false;
//      } else {
//        bool break_by_duplicate = false;
//        for (int j = i; matched_word_count != words_size; j += word_len) {
//          if (map[j] == -1) {
//            cout << "j, map[" << i << "] == -1" << endl;
//            i++;
//            break;
//          } else {
//            bool duplicated = false;
//            for (int k = 0; k < words_size; k++) {
//              if (found[map[j]]) {
//                duplicated = true;
//                break;
//              }
//            }
//            if (duplicated) {
//              cout << "duplicated, map[" << i << "]" << endl;
//              break_by_duplicate = true;
//              break;
//            }
//            found[map[j]] = true;
//            matched_word_count++;
//          }
//        }
//        if (matched_word_count == words_size) {
//          cout << match_start_index << " is pushed to res" << endl;
//          res.push_back(match_start_index);
//          found[map[match_start_index]] = false;
//          match_start_index += word_len;
//          i = match_start_index + total_words_len - word_len;
//          matched_word_count--;
//        } else {
//          if (break_by_duplicate) {
//            found[map[match_start_index]] = false;
//            match_start_index += word_len;
//            if (i < match_start_index) {
//              i = match_start_index;
//            }
//            matched_word_count--;
//          } else {
//            matched_word_count = 0;
//            match_start_index = i;
//            for (int j = 0; j < words_size; j++) found[j] = false;
//          }
//        }
//      }
//    }
//    return res;
//  }
//};
//
//int main() {
//  Solution solution;
//  string s = "barfoofoobarthefoobarman";
//  vector<string> words;
//  words.push_back("bar");
//  words.push_back("foo");
//  words.push_back("the");
//  vector<int> res = solution.findSubstring(s, words);
//  solution.show_int_vector(res);
//  return 0;
//}

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    if (s == "" || words.size() == 0) return ret;
    int sLen = s.length(), wLen = words[0].length();
    if (sLen < wLen) {
      return ret;
    }

    unordered_map<string, int> map;
    for (auto word : words) map.insert_or_assign(word, 0);
    for (auto word : words) map[word]++;

    int wSize = words.size();
    for (int i = 0; i < sLen - wSize * wLen + 1; i++) {
      unordered_map<string, int> seen;
      int leftWord = wSize;
      for (int j = i; j < sLen; ) {
        string tmp = s.substr(j, wLen);
        if (map.find(tmp) == map.end()) break;
        if (seen.find(tmp) != seen.end()) {
          seen[tmp]++;
        } else {
          seen.insert(make_pair(tmp, 1));
        }
        if (seen[tmp] > map[tmp]) break;
        leftWord--;
        if (leftWord == 0) {
          ret.push_back(i);
          break;
        }
        j += wLen;
      }
    }
    return ret;
  }

  vector<int> better(string s, vector<string>& words) {
    vector<int> ret;
    if (s.empty() || words.empty()) return ret;
    int sLen = s.length(), wLen = words[0].length();
    if (sLen < wLen) {
      return ret;
    }

    unordered_map<string, int> map;
    for (auto word : words) map[word]++;

    int wSize = words.size();
    for (int i = 0; i < wLen; i++) {
      int start = i, seenCount = 0;
      unordered_map<string, int> seen;
      for (int j = i; j <= sLen - wLen; j += wLen) {
        string cur = s.substr(j, wLen);
        if (map.find(cur) == map.end()) { // 遇到了不正确的词
          seen.clear();
          start = j + wLen;
          seenCount = 0;
        } else {
          seen[cur]++;
          if (seen[cur] <= map[cur]) {
            seenCount++;
          } else {
            while (seen[cur] > map[cur]) {
              string tmp = s.substr(start, wLen);
              seen[tmp]--;
              if (seen[tmp] < map[tmp]) {
                seenCount--;
              }
              start += wLen;
            }
          }
          if (seenCount == wSize) {
            ret.push_back(start);
            seen[s.substr(start, wLen)]--;
            seenCount--;
            start += wLen;
          }
        }
      }
    }

    return ret;
  }
};

//int main() {
//  Solution s;
//  string words[] = { "aa","aa" };
//  vector<string> vwords(words, words + 2);
//  vector<int> indices = s.better("aaaaa", vwords);
//  for (auto i : indices) cout << i << " ";
//  cout << endl;
//  return 0;
//}