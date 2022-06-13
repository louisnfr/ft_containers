// #pragma once

#include "inc/red_black/node.hpp"

#define __NODE node_type
#define __VALUE key
#define __SIZE 5
#define __ROOT _root
#define __IS_BLACK color
#define __NIL NIL

#define __BLACK "\033[40m"
#define __RED "\e[1;41m"
#define __STOP "\033[0m"

private:
	int count_from_node(__NODE *ptr, int count = 0) {
		if (ptr != __NIL) {
			if (ptr->right != __NIL)
				count += count_from_node(ptr->right);
			if (ptr->left != __NIL)
				count += count_from_node(ptr->left);
			return (++count);
		}
		return count;
	}

	int count_btw_p(__NODE *ptr, bool is_right) {
		if (is_right) {
			return count_from_node(ptr->left);
		}
		else {
			return count_from_node(ptr->right);
		}
	}

	std::vector<std::vector <int> > aff;

	bool search_v(int level) {
		for (size_t i = 0; i < aff.size(); i++) {
			if (aff[i][0] == level) {
				aff[i][1]--;
				if (aff[i][1] <= 0)
					aff.erase(aff.begin() + i);
				return (true);
			}
		}
		return (false);
	}

	void aff_chars(std::string a, std::string b, int size = -1) {
		size = (size == -1) ? a.size() : size;
		std::cout << a;
		for (int i = __SIZE; i - size > 0; i--)
					std::cout << b;
	}

public:

	void print_tree(__NODE *ptr, int level = 0, bool is_right = 0)
	{
		int i;
		if (ptr != __NIL)
		{
			print_tree(ptr->right, level + 1, 1);
			std::cout << std::endl;
			for (i = 1; i < level && ptr != __ROOT; i++) {
				if (search_v(i))
					aff_chars("│", " ", 1);
				else
					aff_chars(" ", " ");
			}
			if (ptr != __ROOT) {
				if (is_right && count_btw_p(ptr, is_right) > 0) {
					std::vector<int> tmp;
					tmp.push_back(level);
					tmp.push_back(count_btw_p(ptr, is_right));
					aff.push_back(tmp);
				}
				if (is_right)
						aff_chars("╭", "─", 1);
				else
						aff_chars("╰", "─", 1);
			}
			if (ptr->left != __NIL && count_btw_p(ptr->left, 0) > 0) {
				std::vector<int> tmp;
				tmp.push_back(level + 1);
				tmp.push_back(count_btw_p(ptr->left, 0));
				aff.push_back(tmp);
			}
			if (ptr->__IS_BLACK)
				std::cout << __BLACK << ptr->__VALUE << __STOP;
			else
				std::cout  << __RED << ptr->__VALUE << __STOP;
			print_tree(ptr->left, level + 1, 0);
		}
}
