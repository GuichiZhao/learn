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
  EToken Token() const { return _token; }
  EToken Accept();
  double Number() const;
  void SymbolName(char *strOut, int &len) const;

private:
  void EatWhite();
  char const *const _buf;
  int _iLook;
  int _iSymbol;
  int _lenSymbol;
  EToken _token;
  double _number;
};