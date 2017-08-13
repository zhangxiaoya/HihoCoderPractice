#include <iostream>

int main(int argc, char* argv[])
{
	int T;
	while (std::cin >> T)
	{
		auto result = new int[T];
		for (auto i = 0; i < T; ++i)
		{
			int N, M;
			std::cin >> N >> M;
			auto fragments = new int[N + 1];

			for (auto j = 0; j < N; ++j)
				std::cin >> fragments[j + 1];

			if (M >= N)
			{
				result[i] = 100;
			}
			else
			{
				fragments[0] = fragments[1] - 1;
				for (auto j = 1; j < N; ++j)
					fragments[j] = fragments[j + 1] - fragments[j] - 1;
				fragments[N] = 100 - fragments[N];

				auto sum = 0;
				for (auto k = 0; k < M + 1; ++k)
					sum += fragments[k];

				auto maxSum = sum;
				for (auto k = M+1; k <= N; ++k)
				{
					sum -= fragments[k - M - 1];
					sum += fragments[k];
					if (sum > maxSum)
						maxSum = sum;
				}
				result[i] = maxSum + M;
			}

			delete[] fragments;
		}
		for (auto i = 0; i < T; ++i)
			std::cout << result[i] << std::endl;
		delete[] result;
	}
	return 0;
}
