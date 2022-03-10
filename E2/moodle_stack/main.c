#include "reverse.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_report(char *str, char *res) {
  if (!str || !res)
    return;

  if (strcmp(str, res) == 0) {
    printf("-- OK\n");
  } else {
    printf("-- FAIL, it should be [%s]\n", res);
  }
}

void test_string(char *str, char *res1, char *res2) {
  // don't bother to return Status
  // if not NULL, res1 and res2 contain the correct answers, to be compared
  // with the obtained results
  char *strinv = NULL, *strwords = NULL;

  if (!str)
    return;

  printf("Source string: [%s]\n", str);

  // invert the string
  strinv = string_invert(str);
  if (strinv) {
    printf("Reversed string: [%s]\n", strinv);
    test_report(strinv, res1);
  } else {
    printf("Error: string_invert returned NULL\n");
  }

  // reverse each of the words of the string, and output them in reverse order
  strwords = malloc((strlen(str) + 1) * sizeof(char));
  if (strwords && reverseWords(strwords, str) == OK) {
    printf("Reversed words: [%s]\n", strwords);
    test_report(strwords, res2);
  } else {
    printf("Error reversing words: %s\n",
           strwords ? "ERROR Status" : "failed malloc");
  }

  free(strinv); // Why? if you don't know the answer, comment this out and run
                // the program with valgrind. Where is strinv allocated?
  free(strwords);
}

void basic_tests() {
  char *strs[] = {"supercalifragilistico", "hello world",
                  "Programming is nice!!", " hello   world ",
                  "Amor a Roma",           "A ti no bonita"};
  char *strs_inv[] = {"ocitsiligarfilacrepus", "dlrow olleh",
                      "!!ecin si gnimmargorP", " dlrow   olleh ",
                      "amoR a romA",           "atinob on it A"};

  char *strs_word[] = {"ocitsiligarfilacrepus", "olleh dlrow",
                       "gnimmargorP si !!ecin", " olleh   dlrow ",
                       "romA a amoR",           "A it on atinob"};

  int i;
  int numstr = sizeof(strs) / sizeof(strs[0]);

  for (i = 0; i < numstr; i++) {
    // pass solutions to the test_string function
    test_string(strs[i], strs_inv[i], strs_word[i]);
  }
}

int main(int argc, char *argv[]) {

  if (argc == 1) {
    basic_tests();
  } else if (argc == 2) {
    test_string(argv[1], NULL,
                NULL); // could modify to accept as additional
                       // program arguments the expected results
  } else {
    printf("Wrong number of arguments. Don't forget to quote your sentence if "
           "it has spaces. Exiting \n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
