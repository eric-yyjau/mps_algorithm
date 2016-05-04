#include <string>
#include <ctype.h>
#include <cstring>
#include <cassert>

using namespace std;

size_t
myStrGetTok(const string& str, string& tok, size_t pos =0,
            const char del =' ');
bool
myStr2Int(const string& str, int& num);

int
myStrNCmp(const string& s1, const string& s2, unsigned n);

bool
isValidVarName(const string& str);