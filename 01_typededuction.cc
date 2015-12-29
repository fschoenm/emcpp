#include <iostream>
#include <string>

#include <catch.hpp>

// implementation
template <class T, std::size_t N>
constexpr std::size_t array_size(T (&)[N]) noexcept {
	return N;
}

// test cases
TEST_CASE("array_size", "[mandatory][types]") {
	SECTION("basic") {
		int a0[] = { 1 };
		CHECK(array_size(a0) == 1);

		int a1[] = { 1, 2, 3 };
		CHECK(array_size(a1) == 3);
	}

	SECTION("complex types") {
		std::string a0[] = { "Hello" };
		CHECK(array_size(a0) == 1);

		std::string a1[] = { "Hello", "World", "!" };
		CHECK(array_size(a1) == 3);
	}
}
