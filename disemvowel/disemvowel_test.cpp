#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
	char* output = disemvowel((char*) "");
  ASSERT_STREQ("", output);
	free(output);
}

TEST(Disemvowel, HandleNoVowels) {
	char* output = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", output );
  free(output);
}

TEST(Disemvowel, HandleOnlyVowels) {
	char* output = disemvowel((char*) "aeiouAEIOUOIEAuoiea"); 
  ASSERT_STREQ("", output);
  free(output);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
	char* output = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", output);
  free(output);
}

TEST(Disemvowel, HandlePunctuation) {
	char* output = disemvowel((char*) "An (Unexplained) Elephant!"); 
  ASSERT_STREQ("n (nxplnd) lphnt!", output);
  free(output);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
 
 char* teststr = disemvowel(str);
  ASSERT_STREQ("xyz", teststr);
  free(teststr);

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
