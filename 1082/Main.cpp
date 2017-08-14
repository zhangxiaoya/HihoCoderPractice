#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	std::string str;
	std::vector<std::string> output;
	while (std::getline(std::cin, str))
	{
		std::string temp = str;
		std::string result = "";
		for(auto it = str.begin();it != str.end();++it)
		{
			if(*it >= 'A' && *it <= 'Z')
				*it += 'a' - 'A';
		}
		auto pos = str.find("marshtomp");

		if(pos != std::string::npos)
		{
			while (pos != -1)
			{
				auto nextPos = pos + 9;
				result += temp.substr(0, pos) + "fjxmlhx" + temp.substr(nextPos, str.length());
				pos = str.find("marshtomp", nextPos);
			}
		}
		output.push_back(result);
	}
	for (int i = 0; i < output.size(); ++i)
		std::cout << output[i] << std::endl;
	return 0;
}

