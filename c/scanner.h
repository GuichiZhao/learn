#pragma once
#include<iostream>
using namespace std;
class Scanner
{
public:
  Scanner(char const *buf);
  ~Scanner();

private:
  char const *const _buf;
};
Scanner::Scanner(char const *buf)
    : _buf(buf)
{
  cout << "Scanner with \"" << buf << "\"" << endl;
}

Scanner::~Scanner(){
  cout << "Scanner destory " << endl;
}