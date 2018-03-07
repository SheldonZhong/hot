//
//  Created by Robert Binna
//
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <spider/contenthelpers/IdentityKeyExtractor.hpp>

namespace spider { namespace contenthelpers {

BOOST_AUTO_TEST_SUITE(IdentityKeyExtractorTest)

BOOST_AUTO_TEST_CASE(testExtractUint64) {
	spider::contenthelpers::IdentityKeyExtractor<uint64_t> extractKey;
	BOOST_REQUIRE_EQUAL(extractKey(32u), 32u);
	BOOST_REQUIRE_EQUAL(extractKey(0u), 0u);
	BOOST_REQUIRE_EQUAL(extractKey(UINT64_MAX), UINT64_MAX);
}

BOOST_AUTO_TEST_CASE(testExtractPointer) {
	char const * test = "Hallo";
	spider::contenthelpers::IdentityKeyExtractor<char const *> extractKey;
	BOOST_REQUIRE_EQUAL(extractKey(test), test);
}

BOOST_AUTO_TEST_SUITE_END()

}}