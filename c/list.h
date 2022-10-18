#pragma once
#include "link.h"
class List
{
public:
  List() : _pHead(0) {}
  ~List();
  void Add(int id);
  Link const *GetHead() const { return _pHead; }

private:
  Link *_pHead;
};

List::~List()
{
  // free the list
  while (_pHead != 0)
  {
    Link *pLink = _pHead;
    _pHead = _pHead->Next(); // unlink pLink
    delete pLink;
  }
}

void List::Add(int id)
{
  _pHead = new Link(_pHead, id);
}