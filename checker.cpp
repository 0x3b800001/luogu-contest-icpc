#include <sys/time.h>
#include <time.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include "testlib.h"

namespace IOI_ICPC {
int gettimeint(std::string s) {
  assert(s.size() == 5);
  assert(std::isdigit(s[0]));
  assert(std::isdigit(s[1]));
  assert(s[2] == ':');
  assert(std::isdigit(s[3]));
  assert(std::isdigit(s[4]));
  int h = (s[0] - '0') * 10 + (s[1] - '0');
  int m = (s[3] - '0') * 10 + (s[4] - '0');
  assert(0 <= h && h < 24);
  assert(0 <= m && m < 60);
  return h * 60 + m;
}
bool compareWords(std::string a, std::string b) {
  std::vector<std::string> va, vb;
  std::stringstream sa;
  sa << a;
  std::string cur;
  while (sa >> cur) va.push_back(cur);
  std::stringstream sb;
  sb << b;
  while (sb >> cur) vb.push_back(cur);
  return (va == vb);
}
timeval nowtime;
int Minute;
void GetMinute(std::string Starttime) {
  gettimeofday(&nowtime, NULL);
  tm* tmp = localtime(&nowtime.tv_sec);
  const int st = gettimeint(Starttime);
  int h = tmp->tm_hour, m = tmp->tm_min,
      v = (h * 60 + m - st + 480 + 60 * 48) % (60 * 24);
  Minute = v;
}
void quitWA() { quitf(_wa, "Wrong Answer."); }
void quitUKE() { quitf(_fail, "Unknown Error."); }
void quitAC() { quitp(Minute, "ok"); }
}  // namespace IOI_ICPC

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  IOI_ICPC::GetMinute("00:00");
  std::string strAnswer;
  while (!ans.eof()) {
    std::string j = ans.readString();
    if (j == "" && ans.eof()) break;
    std::string p = ouf.readString();
    strAnswer = p;
    if (!IOI_ICPC::compareWords(j, p)) IOI_ICPC::quitWA();
  }
  IOI_ICPC::quitAC();
  return 0;
}
