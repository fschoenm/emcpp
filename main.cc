#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <string>

TEST_CASE("string") {
	std::string s = "Hello World!";

	SECTION("size") {
		CHECK(s.size() == 12);
		CHECK(s.size() < 13);
		CHECK(s.size() > 11);
		CHECK(s.size() != 0);
	}

	SECTION("empty") {
		CHECK_FALSE(s.empty());
	}

	SECTION("equality") {
		CHECK(s == "Hello World!");
		CHECK(s != "Hallo Welt!");
	}
}