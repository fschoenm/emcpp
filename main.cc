#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <string>

TEST_CASE("String") {
	std::string s = "Hello World!";

	SECTION("Length") {
		CHECK(s.size() == 12);
		CHECK(s.size() < 13);
		CHECK(s.size() > 11);
		CHECK(s.size() != 0);
	}

	SECTION("Empty") {
		CHECK_FALSE(s.empty());
	}

	SECTION("Equality") {
		CHECK(s == "Hello World!");
		CHECK(s != "Hallo Welt!");
	}
}