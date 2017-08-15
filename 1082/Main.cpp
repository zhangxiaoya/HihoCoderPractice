#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	std::string str;
	while (std::getline(std::cin, str))
	{
		auto result = str;
		for(auto it = str.begin();it != str.end();++it)
		{
			if(*it >= 'A' && *it <= 'Z')
				*it += 'a' - 'A';
		}
		auto pos = str.find("marshtomp");

		if(pos != std::string::npos)
		{
			while (pos != std::string::npos)
			{
				result.replace(pos,9,"fjxmlhx");
				str.replace(pos,9,"fjxmlhx");
				pos = str.find("marshtomp", pos + 7);
			}
		}
		std::cout << result << std::endl;;
	}
	return 0;
}