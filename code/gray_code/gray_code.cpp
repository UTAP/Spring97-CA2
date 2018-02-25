#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> gray_code(int length) {
  if (length) {
    vector<string> smaller_gray_code = gray_code(length - 1);
    vector<string> res;
    for (vector<string>::iterator i = smaller_gray_code.begin();
         i != smaller_gray_code.end(); i++)
      res.push_back("0" + *i);
    reverse(smaller_gray_code.begin(), smaller_gray_code.end());
    for (vector<string>::iterator i = smaller_gray_code.begin();
         i != smaller_gray_code.end(); i++)
      res.push_back("1" + *i);
    return res;
  } else {
    return vector<string>(1, "");
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> res = gray_code(n);
  for (vector<string>::iterator i = res.begin(); i != res.end(); i++)
    cout << *i << endl;
  return 0;
}
