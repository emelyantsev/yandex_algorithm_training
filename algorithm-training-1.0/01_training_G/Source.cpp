#include <iostream>


int main() {


	int N, K, M;

	std::cin >> N >> K >> M;

	int res = 0;


	while (true) {

		int cs = N / K;

		if (cs == 0) {
			break;
		}

		int cd = K / M;

		if (cd == 0) {
			break;
		}

		res += cs * cd;

		

		N = N % K + cs * (K % M);

//		std::cout << cs << " " << cd << " " << N << " " << res << std::endl;

	}

	std::cout << res << std::endl;

}