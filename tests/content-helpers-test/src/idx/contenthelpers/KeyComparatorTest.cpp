//
//  Created by Robert Binna
//
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <spider/contenthelpers/KeyComparator.hpp>

namespace spider { namespace contenthelpers {

BOOST_AUTO_TEST_SUITE(KeyComparatorTest)

BOOST_AUTO_TEST_CASE(testKeyComparatorForIntegralTypes) {
	typename spider::contenthelpers::KeyComparator<uint64_t>::type compare;

	BOOST_REQUIRE(compare(3, 4) == true);
	BOOST_REQUIRE(compare(4, 3) == false);
	BOOST_REQUIRE(compare(10, 10) == false);
}

BOOST_AUTO_TEST_CASE(testKeyComparatorForCString) {
	typename spider::contenthelpers::KeyComparator<const char*>::type compare;

	BOOST_REQUIRE(compare("A", "B") == true);
	BOOST_REQUIRE(compare("B", "A") == false);
	BOOST_REQUIRE(compare("A", "A") == false);
}


BOOST_AUTO_TEST_SUITE_END()

}}