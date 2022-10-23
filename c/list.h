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
void List::Add(int id)
{
  // add in front of the list
  Link *pLink = new Link(_pHead, id);
  _pHead = pLink;
}

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