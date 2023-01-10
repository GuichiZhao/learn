#include "Sales_data.h"
#include <iostream>
using namespace std;
double Sales_data::avg_price() const
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}
Sales_data::Sales_data(std::istream &is)
{
  read(is, *this); // read will read a transaction from is into this object
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold; // addthemembersofrhsinto
  revenue += rhs.revenue;       // the members of ‘‘this’’ object
  return *this;                 // return the object on which the function was called
}
istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
  return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs; // copy datamembersfromlhsintosum
  sum.combine(rhs);     // adddatamembersfromrhsintosum
  return sum;
}
