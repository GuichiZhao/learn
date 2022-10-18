#if !defined sequencer_h
#define sequencer_h

#include "stack.h"
class Sequencer
{
private:
  Stack const & _stack;
  int cur;

public:
  Sequencer(Stack & s);
  bool atEnd() const;
  void advance();
  int getNun();
  void log();
};

#endif
