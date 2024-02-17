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
  using line_no = std::vector<std::string>::size_type;
  TextQuery(ifstream &input);
  QueryResult query(const std::string &) const;
  ~TextQuery();

private:
  std::shared_ptr<std::vector<std::string>> file;
  map<string, shared_ptr<set<line_no>>> wm;
};

