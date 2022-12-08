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
  Scanner(char const *buf);
  ~Scanner()
  {
    cout << "Scanner is destoried: " << _buf << endl;
  };
  EToken Token() const
  {

    cout << "Token: " << _token << endl;
    // cout << "_buf: " << _buf << endl;
    return _token;
  }
  EToken Accept();
  double Number() const;
  char const *const _buf;
  void SymbolName(char *strOut, int &len) const;

private:
  void EatWhite();

  int _iLook;
  int _iSymbol;
  int _lenSymbol;
  EToken _token;
  double _number;
};