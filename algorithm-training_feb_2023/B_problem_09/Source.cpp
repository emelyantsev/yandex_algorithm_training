#include <iostream>
#include <vector>


class Matrix {

public:

	Matrix(int r, int c) : elements(r, std::vector<int>(c, 0)) , sums(r, std::vector<int>(c, 0)) {}

	void ReadInput() {

		int r = elements.size();
		int c = elements.front().size();

		for (int i = 0; i < r; ++i) {

			int curr_row_sum = 0;

			for (int j = 0; j < c; ++j) {


				std::cin >> elements[i][j];

				curr_row_sum += elements[i][j];

				sums[i][j] = (i == 0 ? 0 : sums[i - 1][j]) + curr_row_sum;
			}
		}
	}

	int GetSum(int r, int c) {

		if (r < 0 || c < 0) {
			return 0;
		}

		return sums[r][c];
	}



private:


	std::vector<std::vector<int>> elements;
	std::vector<std::vector<int>> sums;

};



int main() {

	int N, M, K;
	std::cin >> N >> M >> K;

	Matrix mat(N, M);
	mat.ReadInput();

	for (int i = 0; i < K; ++i) {


		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		--x1; --y1; --x2; --y2;

		int srb = mat.GetSum(x2, y2);
		int slf = mat.GetSum(x1 - 1, y1 - 1);
		int s1 = mat.GetSum(x1 - 1, y2);
		int s2 = mat.GetSum(x2, y1 - 1);

		int res = srb - s1 - s2 + slf;

		std::cout << res << std::endl;

	}

	return 0;
}