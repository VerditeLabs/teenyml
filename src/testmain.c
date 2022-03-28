#include <stdio.h>
#include <munit.h>

#include "teenyml.h"


static MunitResult test_teenyml_dims(const MunitParameter params[], void* user_data) {
  auto extent = tml_dims3(ANON_ARRAY(s32,3,3,6,9));
  munit_assert_true(tml_dims2len(extent) == 162);
  for (int i = 0; i < extent.x; i++) {
    for (int j = 0; j < extent.y; j++) {
      for (int k = 0; k < extent.z; k++) {
        auto idx = tml_dims3(ANON_ARRAY(s32, 3, i,j,k));
        printf("%d\n", tml_idx(extent, idx));
        auto idx2 = tml_dims3(idx);
        printf("%d %d %d\n", idx.x, idx.y, idx.z);
      }
    }
  }
  return MUNIT_OK;
}

static MunitTest teenyml_tests[] = {
  { (char*)"/teenyml", test_teenyml_dims, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite teenyml_test_suite = {
  (char*)"",
  teenyml_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char** argv)
{
  return munit_suite_main(&teenyml_test_suite, (void*)"teenyml", argc, argv);
}
