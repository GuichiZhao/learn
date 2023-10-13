#pragma once
#include <string>
using namespace std;
struct Sales_data
{
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

public:
  // constructors added
  Sales_data() = default;
  Sales_data(const string &s) : bookNo(s) {}
  Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(istream &);
  std::string isbn() const
  {
    return this->bookNo;
  }
  Sales_data &combine(const Sales_data &);

private:
  inline double avg_price() const;

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);


inline istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

double Sales_data::avg_price() const
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}
