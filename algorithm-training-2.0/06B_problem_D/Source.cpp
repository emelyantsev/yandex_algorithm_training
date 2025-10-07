// WA for test # 16 possibly due to issues with long long int / similar python solution is OK

#include <iostream>
#include <cassert>


long long getCount(long long A, long long K, long long B, long long M, long long d) {

	long long ac = (d / K) * (K - 1) * A + (d % K) * A;
	long long bc = (d / M) * (M - 1) * B + (d % M) * B;

	return ac + bc;
}


int main() {

	long long A, K, B, M, X;

	std::cin >> A >> K >> B >> M >> X;

	long long l = 1;
	long long r = X;

	while (true) {

		long long mid = l + (r - l) / 2;

		long long count = getCount(A, K, B, M, mid);

		if (count >= X) {

			long long prev_count = getCount(A, K, B, M, mid - 1);

			if (prev_count < X) {
				std::cout << mid << std::endl;
				return 0;
			}
			else {
				r = mid - 1;
			}
		}
		else {
			l = mid + 1;
		}

	}



	return 0;
}