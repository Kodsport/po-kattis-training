#include <utility>
#include <set>
#include <string>
#include <cassert>
#include <cstring>
#include <cmath>
#include "streamcorr.h"

using namespace std;
typedef long long int64;

bool author_messages = false;

void author_message(const char *s) {
  if (author_messages) {
    report_feedback(authormessage, s);
  }
}

set<int> fibonacci;

bool check_case() {
  int needed;
  judge_ans >> needed;
  int number = 0;
  judge_in >> number;
  int ansNeeded;
  if(!(author_out >> ansNeeded)){
      report_error("Not an integer on first line");
  }
  if(needed != ansNeeded){
      report_error("Wrong numger of numbers");
  }
  int64 sum = 0;
  for(int i = 0; i<needed; i++){
      int num;
      if(!(author_out >> num)) report_error("Not an integer on line %d", i);
      if(fibonacci.find(num) == fibonacci.end()){
          report_error("%d is not a fibonacci number\n", num);
      }
      sum += num;
  }
  if(number != sum){
      report_error("The numbers did not sum up");
  }
  return true;
}

int main(int argc, char **argv) {
  int a = 0, b = 1;
  while(a <= 1e9){
      fibonacci.insert(a);
      b = a + b;
      a = b - a;
  }
  init_io(argc, argv);
  /* Check if the author_messages option is given. */
  for (int i = 4; i < argc; ++i)
    if (!strcmp(argv[i], "author_messages"))
      author_messages = true;

  check_case();

  /* Check for trailing output in author file. */
  string trash;
  if (author_out >> trash) {
    author_message("Trailing output after last test case");
    report_error("Trailing output");
  }

  /* Yay! */
  author_message("Thank you for your great code.  It was fantastic.");
  accept();
}
