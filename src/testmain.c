#include <stdio.h>
#include <munit.h>

#include "teenyml.h"


static MunitResult test_teenyml_dims(const MunitParameter params[], void* user_data) {
	dims3_t d = {}

	return MUNIT_OK;
}

static MunitTest teenyml_tests[] = {
    { (char*)"/teenyml", test_teenyml, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
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
