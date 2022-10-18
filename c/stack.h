#if !defined stack_h
#define stack_h

const int initStack = 1;
class Stack
{
public:
  int value=111;
  Stack();
  ~Stack();
  void Push(int i);
  int Pop();
  int Top() const;
  bool IsEmpty() const;

private:
  void Grow();
  int *_arr;
  int
      _capacity; // size of the array
  int
      _top;
};
#endif
