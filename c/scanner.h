#pragma once
#include <iostream>
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

class Scanner
{
public:
  Scanner(char *buf) : _buf(buf), _iLook(0)
  {
    cout << "Create Scanner with " << _buf << endl;
  }
  ~Scanner()
  {
    cout << "Destroy Scanner " << _buf << endl;
  }
  double GetNum()
  {
    return _num;
  }
  EToken Accept()
  {
    EatWhite();
    switch (_buf[_iLook])
    {
    case '+':
      _token = tPlus;
      _iLook++;
      break;
    case '*':
      _token = tMult;
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
      _num = strtod(_buf + _iLook, &end);
      _iLook = end - _buf;
      break;
    case 0:
      _token = tEnd;
      break;
    default:
      _token = tError;
      break;
    }
    return _token;
  }

private:
  const char *_buf;
  int _iLook;
  double _num;
  EToken _token;
  void EatWhite()
  {
    while (isspace(_buf[_iLook]))
    {
      _iLook++;
    }
  }
};