#include "list.h"
#include <iostream>
using namespace std;

Link *Link::GetNext() const
{
  return _next;
}

Link::Link(Link *next, int id) : _next(next), _id(id)
{
  // cout << "Create link " << _id << endl;
}

Link::~Link()
{
  // cout << "Destory link " << _id << endl;
}

int Link::GetId() const
{
  return _id;
}

List::List() : _head(0) {}
List::~List()
{
  // cout << "Destory list " << endl;
  while (_head != 0)
  {
    Link *head = _head;
    _head = _head->GetNext();
    delete head;
  }
}
void List::Add(int id)
{
  Link *head = new Link(_head, id);
  _head = head;
}

Link const *List::GetHead() const
{
  return _head;
}