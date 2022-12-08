#include <iostream>
using namespace std;

class Link
{
private:
  Link *_next;
  int _id;

public:
  Link(Link *next, int id);
  ~Link();
  Link *GetNext() const;
  int GetId() const;
};

class List
{
private:
  Link *_head;

public:
  List();
  ~List();
  void Add(int id);
  Link const *GetHead() const;
};
