#pragma once
#include <string>
#include <set>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
class QueryResult;
class TextQuery
{
public:
  using line_no = vector<string>::size_type;
  TextQuery(ifstream &input);
  QueryResult query(const string &) const;

private:
  shared_ptr<vector<string>> file;
  map<string, shared_ptr<set<line_no>>> wm;
};
ostream &print(ostream &os, const QueryResult &qr);
