#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
const int maxSymLen = 3;
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
  Scanner(const char *buf) : _buf(buf), _iLook(0)
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
  void SymbolName(char *strOut, int &len)
  {
    assert(len >= maxSymLen);
    strncpy(strOut, _buf + _iSymbol, _symbolLength);
    strOut[_symbolLength] = 0;
    len = _symbolLength;
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
      if (isalpha(_buf[_iLook]) || _buf[_iLook] == '_')
      {
        _token = tIdent;
        _iSymbol = _iLook;
        while (isalnum(_buf[_iLook]) || _buf[_iLook] == '_')
        {
          _iLook++;
        }
        _symbolLength = _iLook - _iSymbol;
        if (_symbolLength > maxSymLen)
        {
          _symbolLength = maxSymLen;
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

private:
  const char *_buf;
  int _iLook;
  double _num;
  int _iSymbol;
  int _symbolLength;
  EToken _token;
  void EatWhite()
  {
    while (isspace(_buf[_iLook]))
    {
      _iLook++;
    }
  }
};