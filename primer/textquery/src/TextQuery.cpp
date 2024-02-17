#include <TextQuery.h>
#include <sstream>
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
  string text;
  while (getline(is, text))
  {
    file->push_back(text);
    int n = file->size() - 1;
    istringstream line(text);
    string word;
    while (line >> word)
    {
      auto &lines = wm[word];
    }
  }
}