#include <string>
#include <iostream>


std::string copyrights() {
	std::string s = "\n Pythagoras Tree (c) 2018 \n Azeem Mirza - azeemirza.com \n License: MIT (c) 2017 - 2018";
	return s;
}

int main (void) {
	
	std::cout << copyrights() << std::endl;
	getchar();
	return 0;

}