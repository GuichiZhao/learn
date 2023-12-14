#pragma once
#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;
using namespace std;
class StrBlob
{
  friend class StrBlobPtr;
  // other members as in § 12.1.1 (p. 456)

  // and one past the last element
public:
  StrBlobPtr begin(); // return StrBlobPtr to the ﬁrst element
  StrBlobPtr end();
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  ~StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  StrBlob(const StrBlob &c)
  {
    data = make_shared<vector<string>>(*c.data);
  };
  StrBlob operator=(const StrBlob &c)
  {
    data = make_shared<vector<string>>(*c.data);
    return *this;
  }
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();

  void push_back(const std::string &t) const { data->push_back(t); }

  // element access
  string &front();
  string &back();
  const string &front() const;
  const string &back() const;

  //   string &front();
  // string &back();
  void print() const;

private:
  shared_ptr<vector<string>> data;
  // throws msg if data[i] isn’t valid
  void check(size_type i, const std::string &msg) const;
};