#include <iostream>
#include <fstream>

int main() {
  std::string s;
  int t, TL, ML;
  std::cout << "Input name (___1.in, ...): ";
  std::getline(std::cin, s);
  std::cout << "Input TL (ms), ML (kb), Subtask number: \n";
  std::cin >> TL >> ML >> t;
  std::ofstream yml("config.yml");
  for (int i = 1; i <= t; ++i) {
    std::cout << "Subtask " << i << ": input number l, r and score:\n";
    int l, r, sc;
    std::cin >> l >> r >> sc;
    for (int j = l; j <= r; ++j) {
      yml << s << j << ".in:\n timeLimit: " << TL << "\n memoryLimit: " << ML
          << "\n score: 1\n subtaskId: " << i << "\n\n";
    }
    std::ofstream jf("Sub" + std::to_string(i) + ".txt");
    jf << "if";
    for (int j = l; j < r; ++j) {
      jf << "(@status" << j << "==AC)and";
    }
    jf << "(@status" << r << "==AC);then\n @total_score=" << sc
       << ";\n @final_status=AC;\n @final_time=@score" << l
       << "*60*1000;\nelse\n @total_score=0;\n @final_status=UNAC;\n "
          "@final_time=0;\nfi\n@final_memory=0;";
    jf.close();
  }
  yml.close();
  std::ofstream total("total.txt");
  total << "if";
  for (int i = 1; i < t; ++i) {
    total << "(@status" << i << "==AC)and";
  }
  total << "(@status" << t
        << "==AC);then\n @final_status=AC;\nelse\n "
           "@final_status=UNAC;\nfi\n@final_memory=0;\n@final_time=0;\n@total_"
           "score=";
  for (int i = 1; i < t; ++i) total << "@score" << i << "+";
  total << "@score" << t << ";\n";
  for (int i = t; i >= 1; --i)
    total << "if(@status" << i << "==AC);then\n @final_time=@time" << i
          << ";\nfi\n";
  return 0;
}
