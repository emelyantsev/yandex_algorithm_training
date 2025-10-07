#include <iostream>
#include <algorithm>


struct Rect {

	int w = 0 ;
	int h = 0;
};


int main() {


	int w1, h1;
	int w2, h2;

	std::cin >> w1 >> h1 >> w2 >> h2;

	Rect r1, r2;

	if (w1 < h1) {
		std::swap(w1, h1);
	}
	r1.h = h1;
	r1.w = w1;

	if (w2 < h2) {
		std::swap(w2, h2);
	}
	r2.h = h2;
	r2.w = w2;

	if (r1.w < r2.w) {
		std::swap(r1, r2);
	}


	int w, h;
	int S;

	int wi = r1.w;
	int hi = r1.h + r2.h;
	int Si = wi * hi;

	w = wi;
	h = hi;
	S = Si;


	wi = r1.w + r2.w;
	hi = std::max(r1.h, r2.h);
	Si = wi * hi;

	if (Si < S) {

		w = wi;
		h = hi;
	}

	wi = r1.w + r2.h;
	hi = std::max(r1.h, r2.w);
	Si = wi * hi;

	if (Si < S) {

		w = wi;
		h = hi;
	}

	


	std::cout << w << " " << h << std::endl;
}
	