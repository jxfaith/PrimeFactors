#include <iostream>
#include <vector>
#include <string>

bool isPrime(int number) {
	for (int i = 2; i <= number; i++) {
		if (number%i==0 && number != i)
			return false;
	}
	return true;
}

std::vector<int> PrimeFactors(int number) {
	std::vector<int> v;
	int i = 2;
	while (number != 1) {
		if (number%i == 0 && isPrime(i)) {
			v.push_back(i);
			number /= i;
			i = 2;
		} else { 
			i++;
		}
	}
	return v;
}

int main() {
	std::cout << "Enter integer to factor" << std::endl;
	int myNumber;
	std::string dummy;
	std::vector<int> primeVect;

	while (1) {
		std::cin >> myNumber;
		if (!std::cin.fail()) {
			primeVect = PrimeFactors(myNumber);
			break;
		}
		else if (std::cin.eof()) {
			return 0;
		} 
		else {
			std::cin.clear();
			std::cin >> dummy;
			std::cout << "Invalid entry." << std::endl;
		}
	}
	
	std::cout << std::endl << "Factors:" << std::endl << std::endl;
	for (int n : primeVect) {
		std::cout << n << std::endl;
	}
	std::cout << std::endl;
}
