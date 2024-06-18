#include "validator.h"

std::vector<std::string> splitStringBySpace(const std::string& str) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

void check_word(string s)
{
    assert(s.size()>0);
    assert(s.size()<=15);
    for (auto c : s)
    {
        assert(c>='a'&&c<='z');
    }
}

void run() {
    int n = Int(1, int(1e4));
    Endl();

    string words = Line();

    int m = Int(1, int(1e4));
    Endl();

    set<string> keys;
    for (int i = 0; i < m; i++)
    {
        string l = Line();
        string a = splitStringBySpace(l)[0];
        string b = splitStringBySpace(l)[1];
        assert(keys.find(a)==keys.end());
        keys.insert(a);
        check_word(a);
        check_word(b);
    }

    int count = 0;
    for (auto s : splitStringBySpace(words))
    {
        assert(keys.find(s)!=keys.end());
        check_word(s);
        count++;
    }
    assert(count==n);

    Eof();
}
