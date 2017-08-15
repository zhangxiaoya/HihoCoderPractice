#include <iostream>
#include <vector>
#include <string>

void RightRotated(std::vector<std::vector<char>>& matrix)
{
	for (auto i = 0; i < 3 - 1; ++i)
	{
		auto lastVal = matrix[0][i];

		auto t = matrix[i][3 - 1 - 0];
		matrix[i][3 - 1 - 0] = lastVal;
		lastVal = t;

		t = matrix[3 - 1 - 0][3 - 1 - i];
		matrix[3 - 1 - 0][3 - 1 - i] = lastVal;
		lastVal = t;

		t = matrix[3 - 1 - i][0];
		matrix[3 - 1 - i][0] = lastVal;
		lastVal = t;

		matrix[0][i] = lastVal;
	}
}

int main(int argc, char* argv[])
{
	int M, N;
	while (std::cin >> N >> M)
	{
		std::vector<std::vector<char>> matrix(N, std::vector<char>(M, '0'));
		std::vector<std::vector<char>> center(3, std::vector<char>(3, '0'));
		std::vector<int> result;

		std::string str;
		for (auto i = 0; i < N; ++i)
		{
			std::cin >> str;
			for (auto j = 0; j < M; ++j)
			{
				matrix[i][j] = str[j];
			}
		}
		for (auto i = 0; i < 3; ++i)
		{
			std::cin >> str;
			for (auto j = 0; j < 3; ++j)
			{
				center[i][j] = str[j];
			}
		}

		for (auto r = 0; r <= N - 3; ++r)
		{
			for (auto c = 0; c <= M - 3; ++c)
			{
				for (auto i = 0; i < 4; ++i)
				{
					auto allFlag = true;
					for (auto j = 0; j < 3; ++j)
					{
						auto rowFlag = true;
						for (auto k = 0; k < 3; ++k)
						{
							if (matrix[r + j][c + k] != center[j][k])
							{
								rowFlag = false;
								break;
							}
						}
						if (!rowFlag)
						{
							allFlag = false;
							break;
						}
					}
					if (allFlag)
					{
						result.push_back(r + 2);
						result.push_back(c + 2);
						break;
					}
					RightRotated(center);
				}
			}
		}

		for (auto i = 0; i < result.size(); i += 2)
			std::cout << result[i] << " " << result[i + 1] << std::endl;
	}
	return 0;
}
