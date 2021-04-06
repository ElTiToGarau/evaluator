OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main:
	g++ -c main.cc $(OPCIONS)

clean:
	rm *.o
