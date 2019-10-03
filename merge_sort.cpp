#include <iostream>
#include <vector>
#include <limits>

template<typename T>
std::vector<T> merge(const std::vector<T>& a, const std::vector<T>& b) 
{ 
	// Merges two already sorted vectors into a combined sorted vector
	int iter_a{}; // Iterates over all elements of a for merge
	int iter_b{}; // Iterates over all elements of b for merge
	const unsigned int size_a{a.size()};
	const unsigned int size_b{b.size()};
	std::vector<T> output{};
	while (size_a + size_b - iter_a - iter_b > 0)
	{
		// Compares the current elements of a and b, and appends the smaller one to output
		if (iter_a == size_a)
		{
			// The case where all elements of a are in the output vector
			output.push_back(b.at(iter_b));
			iter_b++;
		}
		else if (iter_b == size_b)
		{
			// The case where all elements of b are in the output vector
			output.push_back(a.at(iter_a));
			iter_a++;
		}
		else if (a.at(iter_a) < b.at(iter_b))
		{
			output.push_back(a.at(iter_a));
			iter_a++;
		}
		else if (a.at(iter_a) == b.at(iter_b))
		{
			output.push_back(a.at(iter_a));
			output.push_back(b.at(iter_b));
			iter_a++;
			iter_b++;
		}
		else {
			output.push_back(b.at(iter_b));
			iter_b++;
		}
	}
	return output;
}

template <typename T>
std::vector<T> msort(const std::vector<T>& input)
{
	if (input.size() == 1)
	{
		return input; // Base case, a vector with one element is sorted by definition
	}
	else {
		std::vector<T> left(input.begin(), input.begin() + (input.size() / 2)); // Left half
		std::vector<T> right(input.begin() + (input.size() / 2), input.end()); // Right half
		return merge(msort(left), msort(right)); // Recursively break the vector into two halves and merge
	}
}


int main()
{
	std::vector<int> a{};
	int num{};
	while (std::cout << "Enter the number of elements: " && !(std::cin >> num)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input; please re-enter.\n";
	}
	for (int i{}; i < num; i++)
	{
		int temp{};
		while (std::cout << "Enter element " << i << ": " && !(std::cin >> temp))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter.\n";
		}
		a.push_back(temp);
	}
	std::vector<int> f{msort(a)};
	std::cout << "Sorted List:" << '\n';
	for (const int& i : f)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}
