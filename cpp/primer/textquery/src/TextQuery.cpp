#include "TextQuery.h"
#include "QueryResult.h"
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
      // lines is a shared_ptr
      if (!lines)
      {
        lines.reset(new set<line_no>);
      }
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const string &sought) const
{
  // we’llreturnapointertothissetifwedon’tfindsought
  static shared_ptr<set<line_no>> nodata(new set<line_no>); // usefindandnotasubscripttoavoidaddingwordstowm!
  auto loc = wm.find(sought);
  if (loc == wm.end())
    return QueryResult(sought, nodata, file); // not found
  else
    return QueryResult(sought, loc->second, file);
}