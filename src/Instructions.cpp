#include "../inc/Instructions.h"

void Instructions::getInstructions() {
	std::ifstream inputFile("./input/instructions.txt");
	std::string line, instruction, parameter;

	if (!inputFile.is_open()) {
		std::ofstream newFile("./input/instructions.txt");
		std::cout << "File not found, creating file" << std::endl;
		std::cout << "Please re-enter instructions" << std::endl;
		exit(1);
	};

	while (std::getline(inputFile, line)) {
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		std::stringstream ss(line);

		// Instruction i.e. NMAP, PING, ETC
		std::getline(ss, instruction, ' ');

		// PARAMETER IS AFTER THAT
		std::getline(ss, parameter);

		instructionList.emplace_back(std::make_pair(instruction, parameter));
		instructionCount++;

		instructionList.resize(instructionCount);
	}

	inputFile.close();
}

void Instructions::execute() {
	for (const auto& instruction : instructionList) {
		std::string command = instruction.first;
		std::string param = instruction.second;

		std::string cmd = "";

		if (command == "TARGET") {
			std::cout << "Updated target to: " << param << std::endl;
		}
		else if (command == "NMAP") {
			cmd = "nmap " + param;
		}
		else if (command == "PING") {
			cmd = "ping " + param;
			system(cmd.c_str());
		}
		else if (command == "TRACEROUTE") {
			cmd = "tracert " + param;
			system(cmd.c_str());
		}
		else if (command == "HTTPHEADER") {
			cmd = "curl -I " + param;
			system(cmd.c_str());
		}
		else if (command == "PORTSCAN") {
			cmd = "nmap " + param;
			system(cmd.c_str());

			if (system(cmd.c_str()) == 0) {
				std::cout << "Port scan completed successfully." << std::endl;
			}
			else {
				std::cout << "Port scan failed. Do you have the "  << std::endl;
			}
		}
		else if (command == "DNSLOOKUP") {
			cmd = "nslookup " + param;
			system(cmd.c_str());
		}
		else if (command == "GEOIP") {
			cmd = "curl ip-api.com/json/" + param;
			system(cmd.c_str());
		}
		else {
			std::cout << "Unknown instruction: " << command << std::endl;
		}
	}
}

