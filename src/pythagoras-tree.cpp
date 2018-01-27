#include <string>
#include <iostream>


std::string copyrights() {
	//char cp = (wchar_t) 184;
	std::string s = "Pythagoras Tree (c) 2018 \n\n";
	//s.insert(0,1, cp);
	return s;

}

int main (void) {
	
	std::cout << copyrights() << std::endl;
	getchar();
	return 0;

}