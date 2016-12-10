#include <iostream>
#include <vector>
#include <string>

//check to see if integer is prime
bool isPrime(int number) {

	// loop all integers from 2 to the number
	for (int i = 2; i <= number; i++) {

		//  if loop integer can divide the number evenly and the loop integer isn't equal to the number, it isn't prime.
		if (number%i==0 && number != i)
			return false;
	}

	// if the loop completes without returning false, the number is prime
	return true;
}

// build a vector containing all factors of an input number
std::vector<int> PrimeFactors(int number) {
	std::vector<int> v;

	// while the number remains incompletely factored:
	int i = 2;
	while (number != 1) {

		// check if i is a prime factor of the number
		if (number%i == 0 && isPrime(i)) {

			// Append it to the vector
			v.push_back(i);

			// divide the number by the factor
			number /= i;

			// and reset i
			i = 2;

		} else { 

			// else increment i
			i++;
		}
	}

	// finally, return the factors
	return v;
}

int main() {
	int myNumber;
	std::string dummy;
	std::vector<int> primeVect;

	std::cout << "Enter integer to factor" << std::endl;

	// input loop;
	while (1) {
		std::cin >> myNumber;

		// if cin was an integer, assign the outpute of PrimeFactors
		if (!std::cin.fail()) {
			primeVect = PrimeFactors(myNumber);
			break;
		}

		// else if the input was an EOF, end the program
		else if (std::cin.eof()) {
			return 0;
		} 

		// else the input as invalid, re-prompt input
		else {
			std::cin.clear();
			std::cin >> dummy;
			std::cout << "Invalid entry." << std::endl;
		}
	}
	
	// print the prime factors, with a little formatting.
	std::cout << std::endl << "Factors:" << std::endl << std::endl;
	for (int n : primeVect) {
		std::cout << n << std::endl;
	}
	std::cout << std::endl;
}
