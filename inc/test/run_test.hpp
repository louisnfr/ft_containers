#pragma once

namespace ft_test {
void	run(ft_test::Logger *logger, bool (*fn)(), const char name[]) {
	try {
		if (fn())
			logger->success(name);
		else
			throw std::runtime_error("test_failed");
	} catch (std::exception &e) {
		logger->error(name);
	}
}
}  // namespace ft_test
