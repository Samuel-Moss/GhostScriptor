#include "../inc/Instructions.h"

void Instructions::getInstructions() {
	std::ifstream inputFile("./input/instructions.txt");
	std::string line, instruction, parameter;

	if (!inputFile.is_open()) {
		std::ofstream newFile("./input/instructions.txt");
		std::cout << "File not found, creating file" << std::endl;
		std::cout << "Please re-enter instructions" << std::endl;
		exit(1);
	}

	while (std::getline(inputFile, line)) {
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		std::stringstream ss(line);

		// Instruction i.e. NMAP, PING, ETC
		std::getline(ss, instruction, ' ');

		// PARAMETER IS AFTER THAT
		std::getline(ss, parameter);

		instructionList.emplace_back(std::make_pair(instruction, parameter));
		instructionCount++;
	}

	for (const auto& instruction : instructionList) {
		std::cout << instruction.first << " " << instruction.second << std::endl;
	}

	inputFile.close();
}