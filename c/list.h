#pragma once
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
  Link *GetNext() const
  {
    return _next;
  }
  int GetId() const
  {
    return _id;
  }
};

Link::Link(Link *next, int id) : _next(next), _id(id)
{
  cout << "Create link " << _id << endl;
}

Link::~Link()
{
  cout << "Destory link " << _id << endl;
}

class List
{
private:
  Link *_head;

public:
  List() : _head(0)
  {
    // cout << "Create list " << endl;
  }
  ~List()
  {
    // cout << "Destory list " << endl;
    while (_head != 0)
    {
      Link *head = _head;
      _head = _head->GetNext();
      delete head;
    }
  }
  void Add(int id)
  {
    Link *head = new Link(_head, id);
    _head = head;
  }
  Link const *GetHead() const
  {
    return _head;
  }
};
