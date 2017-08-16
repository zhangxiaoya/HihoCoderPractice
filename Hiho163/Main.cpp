#include <iostream>
#include<math.h>

int main(int argc, char* argv[])
{
	int64_t n, x, y;
	while (std::cin >> n >> x >> y)
	{
		int64_t N = pow(2, n);
		int64_t result = 1;

		for (auto i = 0; i < n; ++i)
		{
			if (x <= N / 2 && y <= N / 2)
			{
				int64_t t = y;
				y = x;
				x = t;
				N = N / 2;
			}
			else if (x <= N / 2 && y > N / 2)
			{
				N /= 2;
				result += N * N;
				y -= N;
			}
			else if (x > N / 2 && y > N / 2)
			{
				N /= 2;
				result += N * N * 2;
				x -= N;
				y -= N;
			}
			else
			{
				N /= 2;
				result += N * N * 3;
				int64_t  t = y;
				y = 2 * N - x + 1;
				x = N - t + 1;
			}
		}
		std::cout << result<<std::endl;
	}
	return 0;
}