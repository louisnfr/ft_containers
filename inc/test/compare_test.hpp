#pragma once

namespace test {
bool fncomp(int lhs, int rhs) {
	return lhs < rhs;
}

struct classcomp {
	bool operator()(const int& lhs, const int& rhs) const {
		return lhs < rhs;
	}
};
} // namespace test
