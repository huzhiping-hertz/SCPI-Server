#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include "CommonUtility/NetUtility.h"

using namespace HZP;

TEST_CASE("Common Utility Test","[utility]") {

	bool rs = NetUtility::Ping("127.0.0.1");
	REQUIRE(rs== true);
	bool failCheck = NetUtility::Ping("200.200.200.200");
	REQUIRE(failCheck == false);
}