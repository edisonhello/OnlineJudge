#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

void parse(vector<string>&, string);
int find(vector<string>, string);
vector<string> negative(vector<string>);
vector<string> slice(vector<string>, int, int);

int main() {
  string s;
  int n;
  scanf("%d\n", &n);
  for (int j = 0; j < n; ++j) {
    getline(cin, s);
    vector<string> token;
    parse(token, s);
    int IF = find(token, "IF");
    int THEN = find(token, "THEN");
    cout << "IF ";
    vector<string> s1 = slice(token, IF + 1, THEN);
    vector<string> s2 = slice(token, THEN + 1, token.size());

    for (int i = 0; i < negative(s2).size(); ++i) {
      cout << negative(s2)[i] << ' ';
    }
    cout << "THEN ";
    for (int i = 0; i < negative(s1).size(); ++i) {
      if (i == negative(s1).size() - 1) {
        cout << negative(s1)[i];
      } else {
        cout << negative(s1)[i] << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

void parse(vector<string>& token, string s) {
  int i = 0;
  int j = 0;
  while (i < s.length()) {
    if (s[i] == ' ') {
      token.push_back(s.substr(j, i - j));
      j = i + 1;
    }
    i++;
  }
  token.push_back(s.substr(j, i - j));
}

int find(vector<string> token, string target) {
  for (int i = 0; i < token.size(); ++i) {
    if (token[i] == target) return i;
  }
  return -1;
}

vector<string> slice(vector<string> vec, int start, int end) {
  vector<string> ans;
  for (int i = start; i < end; ++i) {
    ans.push_back(vec[i]);
  }
  return ans;
}

vector<string> negative(vector<string> statement) {
  vector<string> ans;
  if (find(statement, "or") != -1) {
    for (int i = 0; i < negative(slice(statement, 0, find(statement, "or"))).size(); ++i) {
      ans.push_back(negative(slice(statement, 0, find(statement, "or")))[i]);
    }
    ans.push_back("and");
    for (int i = 0; i < negative(slice(statement, find(statement, "or") + 1, statement.size())).size(); ++i) {
      ans.push_back(negative(slice(statement, find(statement, "or") + 1, statement.size()))[i]);
    }
  } else if (find(statement, "and") != -1) {
    for (int i = 0; i < negative(slice(statement, 0, find(statement, "and"))).size(); ++i) {
      ans.push_back(negative(slice(statement, 0, find(statement, "and")))[i]);
    }
    ans.push_back("or");
    for (int i = 0; i < negative(slice(statement, find(statement, "and") + 1, statement.size())).size(); ++i) {
      ans.push_back(negative(slice(statement, find(statement, "and") + 1, statement.size()))[i]);
    }
    ans.push_back(statement[find(statement, "not") == 0 ? 1 : 0]);
  } else {
    ans.push_back("not");
    for (int i = 0; i < statement.size(); ++i) {
      ans.push_back(statement[i]);
    }
  }
  return ans;
}
