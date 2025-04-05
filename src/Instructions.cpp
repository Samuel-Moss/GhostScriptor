#include "../inc/Instructions.h"
#include "../inc/Handlers.h"

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

void Instructions::findDefinition() {
	for (const auto& instruction : instructionList) {
		std::string command = instruction.first;
		std::string param = instruction.second;

		std::string cmd = "";

		if (command == "TARGET") {
			std::cout << "Updated target to: " << param << std::endl;
		}
		else if (command == "PING") {
			cmd = "ping " + param;	
			execute(cmd);
		}
		else if (command == "TRACEROUTE") {
			cmd = "tracert " + param;
			execute(cmd);
		}
		else if (command == "HTTPHEADER") {
			cmd = "curl -I " + param;
			execute(cmd);
		}
		else if (command == "NMAP") {
			cmd = "nmap " + param;
			execute(cmd);
		}
		else if (command == "DNSLOOKUP") {
			cmd = "nslookup " + param;
			execute(cmd);
		}
		else if (command == "GEOIP") {
			cmd = "curl ip-api.com/json/" + param;
			execute(cmd);
		}
		else if (command == "HALT") {
			system("pause");
		}
		else if (command == "CLEAR") {
			system("cls");
		}

		else {
			std::cout << "Unknown instruction: " << command << std::endl;
		}
	}
}

void Instructions::execute(std::string cmd) {

	if (system(cmd.c_str()) == 0) {
		std::cout << "\n";
		hdl::outputResult(1, cmd + " completed successfully.");
	}
	else {
		std::cout << "\n";
		hdl::outputResult(0, cmd + " failed to complete. Do you have the required dependencies installed?.");
	}

	std::cout << "\n--------------------------------------------------------------\n\n";

}
