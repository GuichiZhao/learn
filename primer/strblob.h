#include <vector>
#include <string>
#include <memory>
using namespace std;
class StrBlob
{
public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  ~StrBlob();
  StrBlob(std::initializer_list<std::string> il);
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