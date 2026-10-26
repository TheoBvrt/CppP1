#ifndef PmergeMe_hpp
# define PmergeMe_hpp

# include <iostream>
# include <sstream>
# include <vector> 
# include <iostream>
# include <cstdlib>
# include <climits>
# include <cctype>
# include <string>
# include <deque>


class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void parseArg(char *argv[], int argc);
		void sortAndDisplay();
	private:
		std::vector<int> vecTab;
		std::deque<int> deqTab;
};


#endif