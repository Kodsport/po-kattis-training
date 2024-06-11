/* Output validator for "A Different Problem".  This validator is
 * mostly provided as an example, the problem is so simple that it
 * does not need a custom output validator.
 *
 * The output validator can be given a command-line argument
 * "author_messages".  If this argument is given, the validator gives
 * helpful feedback to the author of the submission.
 *
 * Note: if you start writing error messages in, say, Swedish, make
 * sure your file is UTF-8 coded.
 */
#include <utility>
#include <string>
#include <cassert>
#include <cstring>
#include <cmath>
#include "streamcorr.h"

using namespace std;
typedef long long int64;

bool author_messages = false;

/* Wrapper for author message printing so that they are only printed in
 * case the author_messages option was given.  If the validator should
 * always print author messages, you can just call
 * report_feedback(authormessage, ...) directly.
 */
void author_message(const char *s) {
  if (author_messages) {
    report_feedback(authormessage, s);
  }
}

/* Check one test case.  Returns false if there were no more test
 * cases to check. */
bool check_case() {
  int64 N, M;
  if (!(judge_in >> N >> M))
    return false;
  
  string output;
  if (!(author_out >> output)) {
    author_message("I expected an answer for the next test case but for some reason there was only end-of-file");
    report_error("EOF while reading answer for test case");
  }

  int64 outval;
  if (sscanf(output.c_str(), "%lld", &outval) != 1) {
    author_message("I'm not sure what it is that you have printed but it wasn't an integer");
    report_error("'%s' is not an integer", output.c_str());
  }

  if (outval != abs(N-M)) {
    author_message("That number you gave me is not the correct answer.");
    report_error("%lld != abs(%lld-%lld)", outval, N, M);
  }

  return true;
}

int main(int argc, char **argv) {
  init_io(argc, argv);
  /* Check if the author_messages option is given. */
  for (int i = 4; i < argc; ++i)
    if (!strcmp(argv[i], "author_messages"))
      author_messages = true;

  while (check_case());

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
