#include <iostream>
#include <cassert>
#include <cstring>
#include "scanner.h"
using namespace std;
const int maxSymLen = 3;

Scanner::Scanner(char const *buf) : _buf(buf), _iLook(0)
{
  cout << "scan the string: " << _buf << endl;
  Accept();
}

double Scanner::Number() const
{
  return _number;
};

EToken Scanner::Accept()
{
  EatWhite();
  switch (_buf[_iLook])
  {
  case '+':
    _token = tPlus;
    _iLook++;
    break;
  case '-':
    _token = tMinus;
    _iLook++;
    break;
  case '*':
    _token = tMult;
    _iLook++;
    break;
  case '/':
    _token = tDivide;
    _iLook++;
    break;
  case '(':
    _token = tLParen;
    _iLook++;
    break;
  case ')':
    _token = tRParen;
    _iLook++;
    break;
  case '=':
    _token=tAssign;
    _iLook++;
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
    _token = tNumber;
    char *end;
    _number = strtod(_buf + _iLook, &end);
    _iLook = end - _buf;
    break;
  case 0:
    _token = tEnd;
    break;
  default:
    if (isalpha(_buf[_iLook]) || _buf[_iLook] == '_')
    {
      _token = tIdent;
      _iSymbol = _iLook;
      while (isalnum(_buf[_iLook]) || _buf[_iLook] == '_')
      {
        _iLook++;
      }
      _lenSymbol = _iLook - _iSymbol;
      if (_lenSymbol > maxSymLen)
      {
        _lenSymbol = maxSymLen;
      }
    }
    else
    {
      _token = tError;
    }

    break;
  }
  return _token;
}

void Scanner::SymbolName(char *strOut, int &len) const
{
  assert(len >= maxSymLen);
  strncpy(strOut, _buf + _iSymbol, _lenSymbol);
  strOut[_lenSymbol] = 0;
  len = _lenSymbol;
}

void Scanner::EatWhite()
{
  while (isspace(_buf[_iLook]))
  {
    cout << "white detected" << endl;
    ++_iLook;
  }
}