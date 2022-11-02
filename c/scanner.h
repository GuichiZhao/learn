#pragma once
#include <iostream>
using namespace std;

class Scanner
{
public:
  Scanner(char *buf) : _buf(buf)
  {
    cout << "Create Scanner with" << _buf << endl;
  }
  ~Scanner()
  {
    cout << "Destroy Scanner " << _buf << endl;
  }

private:
  const char *_buf;
};