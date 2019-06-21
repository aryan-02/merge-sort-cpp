#include <iostream>
#include <vector>
#include <limits>

std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b)
{
	int iter_a{};
	int iter_b{};
	const unsigned int size_a{a.size()};
	const unsigned int size_b{b.size()};
	std::vector<int> output{};
	while (size_a + size_b - iter_a - iter_b > 0)
	{
		if (iter_a == size_a)
		{
			output.push_back(b.at(iter_b));
			iter_b++;
		}
		else if (iter_b == size_b)
		{
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

std::vector<int> msort(const std::vector<int>& input)
{
	if (input.size() == 1)
	{
		return input;
	}
	else {
		std::vector<int> left(input.begin(), input.begin() + (input.size() / 2));
		std::vector<int> right(input.begin() + (input.size() / 2), input.end());
		return merge(msort(left), msort(right));
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
	for (int i : f)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}
