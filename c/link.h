#pragma once
class Link
{
public:
  Link(Link *pNext, int id)
      : _pNext(pNext), _id(id) {}
  Link *Next() const { return _pNext; }
  int Id() const { return _id; }

private:
  int _id;
  Link *_pNext;
};