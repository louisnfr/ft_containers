#pragma once

namespace test {
void	run(test::Logger *logger, bool (*fn)(), const char name[]) {
	try {
		if (fn())
			logger->success(name);
		else
			throw std::runtime_error("test_failed");
	} catch (std::exception &e) {
		logger->error(name);
	}
}
} // namespace test
