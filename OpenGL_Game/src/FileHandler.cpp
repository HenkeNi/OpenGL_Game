#include "pch.h"
#include "FileHandler.h"
//#include <vector>

namespace file_handler
{
	std::string getContentFromFile(const std::string& filepath)
	{
		std::ifstream file{ filepath };
		std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

		return content;
		//if (file)
		//{
		//	// get size of file
		//	file.seekg(0, std::ios::end);
		//	std::streampos length = file.tellg();
		//	file.seekg(0, std::ios::beg);


		//	std::vector<char> buffer{ length };
		//	file.read(&buffer[0], length);
		//}
	}

}