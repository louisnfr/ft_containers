#pragma once

#include "inc/red_black/node.hpp"

#define NODE node_type
#define VALUE key
#define SIZE 6
#define ROOT _root
#define IS_BLACK color

#define V_BLACK "\033[40m"
#define V_RED "\033[1;41m"
#define NOC "\033[0m"

public:
	void print_tree(NODE *ptr, int level = 0, bool is_right = 0) {
		int i;
		if (ptr != NIL) {
			print_tree(ptr->right, level + 1, 1);
			std::cout << std::endl;
			for (i = 1; i < level && ptr != ROOT; i++) {
				if (search_v(i))
					aff_chars("│", " ", 1);
				else
					aff_chars(" ", " ");
			}
			if (ptr != ROOT) {
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
			if (ptr->left != NIL && count_btw_p(ptr->left, 0) > 0) {
				std::vector<int> tmp;
				tmp.push_back(level + 1);
				tmp.push_back(count_btw_p(ptr->left, 0));
				aff.push_back(tmp);
			}
			if (ptr->IS_BLACK)
				std::cout << V_BLACK << ptr->VALUE << NOC;
			else
				std::cout  << V_RED << ptr->VALUE << NOC;
			print_tree(ptr->left, level + 1, 0);
		}
	}

private:
	int count_from_node(NODE *ptr, int count = 0) {
		if (ptr != NIL) {
			if (ptr->right != NIL)
				count += count_from_node(ptr->right);
			if (ptr->left != NIL)
				count += count_from_node(ptr->left);
			return (++count);
		}
		return count;
	}

	int count_btw_p(NODE *ptr, bool is_right) {
		if (is_right)
			return count_from_node(ptr->left);
		else
			return count_from_node(ptr->right);
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
		for (int i = SIZE; i - size > 0; i--)
					std::cout << b;
	}
