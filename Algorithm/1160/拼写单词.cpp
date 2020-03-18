#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
	if (words.empty()) return 0;
	int ans = 0;
	unordered_map<char, int> chars_cnt;
	for (char c : chars)
		++chars_cnt[c];
	for (string word : words)
	{
		unordered_map<char, int> word_cnt;
		for (char c : word)
			++word_cnt[c];
		bool is_ans = true;
		for (char c : word)
			if (chars_cnt[c] < word_cnt[c])
			{
				is_ans = false;
				break;
			}
		if (is_ans)
			ans += word.size();
	}
	return ans;
}

void main()
{
	vector<string> words = {/*"cat", "bt", "hat",*/ "tree"};

	int ans = countCharacters(words,"atach");
}