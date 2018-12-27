#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    const int wordsSize = words.size();
    vector<int> lenOfWords(wordsSize, 0);
    for (int i = 0; i < wordsSize; i++) {
      lenOfWords[i] = words[i].size();
    }
    vector<string> ret;
    int idxRowStart = 0;
    int idxCurWord = 0; // index of word
    int wordLenCurRow = 0;
    while (idxCurWord < wordsSize + 1) {
      if (idxCurWord >= wordsSize || wordLenCurRow + lenOfWords[idxCurWord] >= maxWidth) {
        int lenOfWordsCurRow = 0;
        for (int i = idxRowStart; i < idxCurWord; i++) {
          lenOfWordsCurRow += lenOfWords[i];
        }
        int leftSpacesSize = maxWidth - lenOfWordsCurRow;
        int leftSpaceCount = idxCurWord - idxRowStart - 1;
        if (leftSpaceCount == 0) {
          string str = words[idxRowStart];
          for (int i = 0; i < leftSpacesSize; i++) {
            str += " ";
          }
          ret.push_back(str);
          if (idxCurWord >= wordsSize - 1) {
            break;
          }
          idxRowStart = idxCurWord;
          wordLenCurRow = lenOfWords[idxCurWord] + 1;
          idxCurWord++;
          continue;
        }
        int average = leftSpacesSize / leftSpaceCount;
        int mod = leftSpacesSize % leftSpaceCount;
        vector<int> gapSpacesCount(leftSpaceCount, average);
        for (int i = 0; i < mod; i++) gapSpacesCount[i]++;
        string str = words[idxRowStart];
        for (int i = 0; i < leftSpaceCount; i++) {
          for (int j = 0; j < gapSpacesCount[i]; j++) {
            str += " ";
          }
          str += words[idxRowStart + i + 1];
        }
        ret.push_back(str);
        idxRowStart = idxCurWord;
        if (idxCurWord >= wordsSize) break;
        wordLenCurRow = lenOfWords[idxCurWord] + 1;
      } else {
        wordLenCurRow += lenOfWords[idxCurWord] + 1; // at least one space between each two words
      }
      idxCurWord++;
    }
    return ret;
  }
};


int main() {
  // string test[] = { "This", "is", "an", "example", "of", "text", "justification." };
  string test[] = { "What","must","be","acknowledgment","shall","be" };
  vector<string> words(test, test + 6);
  Solution s;
  vector<string> output = s.fullJustify(words, 16);
  for (string str: output) {
    cout << str << endl;
  }
  return 0;
}