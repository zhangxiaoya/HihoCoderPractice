#include <iostream>
#include <string>
#include <vector>

int RemoveDuplicated(std::string& str)
{
	auto count = 0;
	if (str.empty())
		return count;
	for (auto i = 0; i < str.length() - 1;)
	{
		auto j = i + 1;
		for (; j < str.length(); ++j)
		{
			if (str[j] != str[i])
			{
				break;
			}
		}

		if (j == i + 1 && str[i] != str[j])
		{
			i = j;
			continue;
		}
		str = str.substr(0, i) + str.substr(j, str.length() - j);
		count += j - i;
		if(str.empty())
			return count;
	}
	return count;
}

int main(int argc, char* argv[])
{
	int T;
	while (std::cin >> T)
	{
		auto result = new int[T];
		std::vector<std::string> insertStr = {"A","B","C"};

		for (auto c = 0; c < T; ++c)
		{
			std::string str;
			std::cin >> str;

			auto maxCount = 0;

			for(auto ic = 0; ic < 3;++ic)
			{
				for (auto i = 0; i <= str.length(); ++i)
				{
					auto extendedStr = str;
					extendedStr.insert(i, insertStr[ic]);

					auto currentCount = 0;
					auto count = RemoveDuplicated(extendedStr);
					currentCount += count;

					while (count != 0)
					{
						count = RemoveDuplicated(extendedStr);
						currentCount += count;
					}
					if (currentCount > maxCount)
						maxCount = currentCount;
				}
			}
			
			result[c] = maxCount;
		}

		for (auto c = 0; c < T; ++c)
			std::cout << result[c] << std::endl;

		delete[] result;
	}
	return 0;
}
