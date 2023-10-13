#include <iostream>
#include "Sales_Data.h"

ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold; // add the members of rhs into
  revenue += rhs.revenue;
  // the members of ‘‘this’’ object
  return *this; // return the object on which the function was called
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs; // copy data members from lhs into sum
  sum.combine(rhs);
  // add data members from rhs into sum
  return sum;
}

Sales_data::Sales_data(std::istream &is)
{
  read(is, *this); // read will read a transaction from is into this object
}

