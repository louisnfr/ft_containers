# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 19:22:29 by lraffin           #+#    #+#              #
#    Updated: 2022/06/23 01:13:52 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT = ft_containers
NAME_STD = std_containers

SRC =	main.cpp \
		# subject_main.cpp

HOST = $(shell hostname)
ifeq ($(HOST),macbook)
	CXX = c++-11
else
	CXX = c++
endif

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I. #$(BENCHMARK)
BENCHMARK = -O3 -D BENCHMARK=1

S = src
I = inc

B = .build
B_FT = .build/ft
B_STD = .build/std

O_FT = $(SRC:%.cpp=$(B_FT)/%.o)
O_STD = $(SRC:%.cpp=$(B_STD)/%.o)

D_FT = $(SRC:%.cpp=$(B_FT)/%.d)
D_STD = $(SRC:%.cpp=$(B_STD)/%.d)

all: $(NAME_FT)

$(NAME_FT): $(O_FT)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(DONE) $@"

$(NAME_STD): $(O_STD)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(DONE) $@"

-include $(D_FT)
-include $(D_STD)

$(B_FT)/%.o: $(S)/%.cpp
	@mkdir -p $(B_FT)
	@echo "$(COMPILE)$(NOC) $*.cpp"
	@$(CXX) $(CXXFLAGS) -MMD -MP -I$(I) -c $< -o $@

$(B_STD)/%.o: $(S)/%.cpp
	@mkdir -p $(B_STD)
	@echo "$(COMPILE)$(NOC) $*.cpp"
	@$(CXX) $(CXXFLAGS) -MMD -MP -DSTD -I$(I) -c $< -o $@

clean:
	@echo "$(INFO) deleting $(B)"
	@rm -rf $(B)

fclean: clean
	@echo "$(INFO) deleting binaries"
	@rm -f $(NAME_FT) $(NAME_STD)

re: fclean all

std: $(NAME_STD)

diff: $(NAME_FT) $(NAME_STD)
	@./$(NAME_FT) &> $(NAME_FT).txt
	@./$(NAME_STD) &> $(NAME_STD).txt
	-@diff -ys $(NAME_FT).txt $(NAME_STD).txt
	@rm -rf $(NAME_FT).txt $(NAME_STD).txt

lint:
	cpplint --recursive --filter=-whitespace/tab,-whitespace/indent,-whitespace/comments,-legal/copyright,-build/include_what_you_use,-runtime/int,-build/explicit_make_pair .

.PHONY: all clean fclean re std diff lint

YELLOW	= \033[38;5;184m
GREEN	= \033[38;5;46m
CYAN	= \033[0;49;96m
COMPILE	= [$(CYAN)COMP$(NOC)]
INFO	= [$(YELLOW)INFO$(NOC)]
DONE	= [$(GREEN)DONE$(NOC)]
NOC		= \033[0m
