#include <iostream>
#include "Matrix.h" 
#include <random>
#include <cctype>

template <class Matrix>
void FillMatrix(Matrix& matrix, bool order) {
	int current = 1;
	int max = matrix.get_rows() * matrix.get_cols();
	int iterrationLen = matrix.get_rows();
	int iterrations = 0;
	bool isVertical = order;
	bool isPositive = true;
	int i = 0;
	int j = 0;
	while (current <= max) {
		if (isVertical) {
			if (isPositive) {
				for (auto x = 0; x < iterrationLen; x++) {
					matrix(i,j) = current;
					current++;
					j++;
				}
				j--;
				if (order) {
					i++;
				}
				else
				{
					i--;
				}
				
			}
			else {
				for (auto x = 0; x < iterrationLen; x++) {
					matrix(i, j) = current;
					current++;
					j--;
				}
				j++;
				if (order) {
					i--;
				}
				else
				{
					i++;
				}
			}
		}
		else {
			if (isPositive) {
				for (auto x = 0; x < iterrationLen; x++) {
					matrix(i, j) = current;
					current++;
					i++;
				}
				i--;
				if (order) {
					j--;
				}
				else
				{
					j++;
				}
				
			}
			else {
				for (auto x = 0; x < iterrationLen; x++) {
					matrix(i, j) = current;
					current++;
					i--;
				}
				i++;
				if (order) {
					j++;
				}
				else
				{
					j--;
				}
				
			}
		}
		isVertical = !isVertical;
		iterrations++;
		if (iterrations % 2 == 0) {
			isPositive = !isPositive;
		}
		if (iterrations % 2 == 1) {
			iterrationLen--;
		}
	}
}

using u32 = uint_least32_t;
using engine = std::mt19937;
int main()
{
	std::random_device os_seed;
	const u32 seed = os_seed();
	engine generator(seed);
	std::uniform_int_distribution< u32 > distribute(3, 10);
	int random = distribute(generator);

	srand((unsigned)time(NULL));
	bool order = rand() % 2;
	if (order) {
		std::cout << "Order is: clockwise" << std::endl;
	}
	else{
		std::cout << "Order is: counter clockwise" << std::endl;
	}
	std::cout << "Matrix size: " << random << std:: endl;
	Matrix<int> matrix(random, random, 0);
	FillMatrix(matrix, order);
	for (unsigned i = 0; i < matrix.get_rows(); i++) {
		for (unsigned j = 0; j < matrix.get_cols(); j++) {
			if (matrix(i, j) < 10) {
				std::cout << ' ' << matrix(i, j) << ", ";
			}
			else
			{
				std::cout << matrix(i, j) << ", ";
			}
		}
		std::cout << std::endl;
	
	}
}




