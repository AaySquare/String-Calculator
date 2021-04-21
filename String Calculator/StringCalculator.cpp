#include "StringCalculator.h"

#include <string>
#include <iostream>
#include <stdexcept>
#include <regex>

// To split the numbers string using delimiters and adding it to vector list
template <class Container>
void split(const std::string& str, Container& cont,
	const std::string delim = ",|\n|;")
{
	std::regex re(delim);
	std::copy(std::sregex_token_iterator(str.begin(), str.end(), re, -1),
	std::sregex_token_iterator(),
	std::back_inserter(cont));
}

// Adds numbers if string is not empty
int StringCalculator::Add(std::string numbers)
{
	std::vector<std::string> intNumbers;
	split(numbers, intNumbers);

	if (IsEmpty(numbers)) 
	{
		return 0;
	}
	if (numbers.length() == 1)
	{
		return StringToInt(numbers);
	}
	else
	{
		std::cout << GetSum(intNumbers);
		return GetSum(intNumbers);
	}
}

// To check if it is an empty string
bool StringCalculator::IsEmpty(std::string numbers)
{
	return numbers.empty();
}

// To convert string to integer
int StringCalculator::StringToInt(std::string numbers)
{
	return std::stoi(numbers);
}

int StringCalculator::GetSum(std::vector<std::string> numbers)
{
	CheckForNegatives(numbers);

	return CalculateIntegers(numbers);
}

// Checking if any number is a negative and throwing an exception string
void StringCalculator::CheckForNegatives(std::vector<std::string> numbers)
{
	std::vector<std::string> negativeNumbers;
	bool isNegative = false;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (StringToInt(numbers[i]) < 0)
		{
			isNegative = true;
			negativeNumbers.push_back(numbers[i]);
		}
	}

	if (isNegative)
	{
		std::cout << "negatives not allowed: ";
		std::string seperation = "";
		for (size_t i = 0; i < negativeNumbers.size(); i++)
		{
			std::cout << seperation << negativeNumbers[i];
			seperation = ",";
		}

		throw std::exception("negatives not allowed");
	}

}

// Checking if any number is less than 1000 and adding them, otherwise skip.
int StringCalculator::CalculateIntegers(std::vector<std::string> numbers)
{
	int sum = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (StringToInt(numbers[i]) > 1000)
		{
			continue;
		}
		sum += StringToInt(numbers[i]);
	}
	return sum;
}
