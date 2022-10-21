#pragma once
#include <iostream>
#include <cassert>
#include <string.h>
using namespace std;
enum EToken
{
  tEnd,
  tError,
  tNumber,
  tPlus,
  tMult,
  tMinus,
  tDivide,
  tLParen,
  tRParen,
  tAssign,
  tIdent
};
int maxSymLen = 5;
class Scanner
{
public:
  Scanner(char const *buf);
  ~Scanner();
  EToken Token() const { return _token; }
  EToken Accept();
  void SymbolName(char *strOut, int &len);
  double Number()
  {
    assert(_token == tNumber);
    return _number;
  }

private:
  void EatWhite();
  char const *const _buf;
  int _iLook;
  EToken _token;
  double _number;
  int _iSymbol;
  int _lenSymbol;
};

Scanner::Scanner(char const *buf)
    : _buf(buf), _iLook(0)
{
  cout << "Scanner with \"" << buf << "\"" << endl;
  Accept();
}

void Scanner::EatWhite()
{
  while (isspace(_buf[_iLook]))
    ++_iLook;
}

Scanner::~Scanner()
{
  cout << "Scanner destory " << endl;
}

void Scanner::SymbolName(char *strOut, int &len)
{
  assert(len >= maxSymLen);
  assert(_lenSymbol <= maxSymLen);
  strncpy(strOut, &_buf[_iSymbol], _lenSymbol);
  strOut[_lenSymbol] = 0;
  len = _lenSymbol;
}

EToken Scanner::Accept()
{
  EatWhite();
  switch (_buf[_iLook])
  {
  case '+':
    _token = tPlus;
    ++_iLook;
    break;
  case '*':
    _token = tMult;
    ++_iLook;
    break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case '.':
  {
    _token = tNumber;
    char *p;
    _number = strtod(&_buf[_iLook], &p);
    _iLook = p - _buf; // pointer subtraction
    break;
  }
  case '\0': // end of input
    _token = tEnd;
    break;
  default:
    if (isalpha(_buf[_iLook]) || _buf[_iLook] == '_')
    {
      _token = tIdent;
      _iSymbol = _iLook;
      int cLook; // initialized in the do loop
      do
      {
        ++_iLook;
        cLook = _buf[_iLook];
      } while (isalnum(cLook) || cLook == '_');
      _lenSymbol = _iLook - _iSymbol;
      if (_lenSymbol > maxSymLen)
        _lenSymbol = maxSymLen;
    }
    else
    {
      _token = tError;
    }

    break;
  }
  return Token();
}