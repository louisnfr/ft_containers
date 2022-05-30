#ifndef UTILITY_LOGGER_HPP_
#define UTILITY_LOGGER_HPP_

#include <string.h>
#include <unistd.h>

#include <string>
#include <iostream>
#include <sstream>

namespace ft_test {
class Logger {
 private:
  std::string _prefix;

  std::string _pending_err;
  std::string _pending_success;

 public:
	explicit Logger(std::string const &prefix)
		: _prefix(prefix), _pending_err(""), _pending_success("") {
		_announce();
	}

	void	success(const char *test_name) {
		std::cout << "\033[1;42;37mPASSED\033[0m " << test_name;
		if (_pending_success != "") {
			std::cout << "\t\t\t\033[0;37m" << _pending_success
				<< "\033[0m" << std::endl;
			_pending_success = "";
		} else {
			std::cout << std::endl;
		}
	}
	void	error(const char *test_name) {
		std::cerr << "\033[1;41;37mFAILED\033[0m " << test_name;
		if (_pending_err != "") {
			std::cerr << "\t\t\t\033[0;37m"
				<< _pending_err.c_str() << "\033[0m" << std::endl;
			_pending_err = "";
		} else {
			std::cerr << std::endl;
		}
		sleep(1);
	}

	bool	err(const char *msg) {
		_pending_err = msg;
		return false;
	}
	bool	benchmark(time_t container, time_t ref) {
		size_t container_ms = container * 1000 / CLOCKS_PER_SEC;
		size_t ref_ms = ref * 1000 / CLOCKS_PER_SEC;

		std::stringstream ss;

		ss << "ft: " << container_ms << "ms, std: " << ref_ms << "ms";
		if (ref_ms == 0) {
			ss << " -> diff: too quick";
		} else {
			ss << " -> diff " << float(container) / float(ref) << "x";

			if (container > ref * 20) {
				_pending_err = ss.str();
				return false;
			}
		}
		_pending_success = ss.str();
		return true;
	}
	void	section(const char *section_name) {
		std::cout << std::endl;
		int section_size = (22 - strlen(section_name)) / 2;
		for (int i = 0; i < section_size; i++)
			std::cout << " ";
		std::cout << section_name;
		for (int i = 0; i < section_size; i++)
			std::cout << " ";
		std::cout << std::endl;
	}

 private:
	void	_announce() {
		int div_spaces = (22 - _prefix.size()) / 2;
		std::cout << "======================" << std::endl << "|";
		for (int i = 1; i < div_spaces; i++)
			std::cout << " ";
		std::cout << "\033[1;36m" << _prefix << "\033[0m";
		for (int i = 1; i < div_spaces; i++)
			std::cout << " ";
		std::cout << "|" << std::endl << "======================" << std::endl;
	}
};
}  // namespace ft_test

#endif  // UTILITY_LOGGER_HPP_
