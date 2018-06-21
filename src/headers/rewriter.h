#pragma once
#include <string>
#include <map>
#ifndef REWRITER

std::string replacer(std::string atom, int p, std::string a) {

	atom.replace(p, 1, a);
	return atom;

}

std::string rewriter(std::string atom, std::map<char, std::string> m, int itr) {
	std::map<char, std::string >::iterator iter;
	iter = m.begin();
	int atomPos = 0;
	for (int i = 0; i < itr; ) {
		
		for (atomPos = 0; atomPos < atom.length();) {

			if (atom[atomPos] == 'X' || 
				atom[atomPos] == '-' || 
				atom[atomPos] == '+' || 
				atom[atomPos] == '[' || 
				atom[atomPos] == ']' || 
				atom[atomPos] == 'M' || 
				atom[atomPos] == ' ') {

				atomPos++;

			}

			else if (atom[atomPos] == 'S') {
				
				iter = m.find(atom[atomPos]);
				atom = replacer(atom, atomPos, iter->second);
				atomPos += iter->second.length();

			}

		}

		i++;
	}

	return atom;

}
#endif //REWRITER