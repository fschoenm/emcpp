#include <future>

#include <catch.hpp>

/******************************************************************************
 *** Implementation ***********************************************************
 ******************************************************************************/

bool is_prime(uint64_t x) {
	bool result = true;

	for (uint64_t i = 2; i < x / 2; ++i) {
		if (x % i == 0)
			result = false;
	}

	return result;
}

/******************************************************************************
 *** Test cases ***************************************************************
 ******************************************************************************/

TEST_CASE("task") {
	static const uint64_t NUMBER = std::numeric_limits<uint32_t>::max() / 16;

	SECTION("parallel tasks") {
		auto f0 = std::async(std::launch::async, [] { return is_prime(NUMBER - 0); });
		auto f1 = std::async(std::launch::async, [] { return is_prime(NUMBER - 1); });
		auto f2 = std::async(std::launch::async, [] { return is_prime(NUMBER - 2); });
		auto f3 = std::async(std::launch::async, [] { return is_prime(NUMBER - 3); });

		f0.wait();
		f1.wait();
		f2.wait();
		f3.wait();

		CHECK_FALSE(f0.get());
		CHECK_FALSE(f1.get());
		CHECK_FALSE(f2.get());
		CHECK_FALSE(f3.get());
	}
}