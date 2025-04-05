#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#pragma once

class Instructions {
	private:
		uint16_t instructionCount;
		std::vector <std::pair<std::string, std::string>> instructionList;

	public:
		void getInstructions();
		void execute();
};