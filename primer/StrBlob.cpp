#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>
using namespace std;
StrBlob::StrBlob()
{
  data = make_shared<vector<string>>();
};
StrBlob::StrBlob(initializer_list<string> il)
{
  data = make_shared<vector<string>>(il);
}
StrBlob::~StrBlob(){
    // cout << "destory StrBlob" << endl;
};

void StrBlob::check(size_type i, const string &msg) const
{
  if (i >= data->size())
    throw out_of_range(msg);
}
string &StrBlob::front()
{
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}
string &StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

const string &StrBlob::front() const
{
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}
const string &StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

void StrBlob::print() const
{
  auto begin = data->begin(), end = data->end();
  for_each(begin, end, [](string s)
           { cout << s << endl; });
}
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end()
{
  return StrBlobPtr(*this, data->size());
}