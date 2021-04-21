#pragma once

#include <string>
#include <vector>

class StringCalculator
{
public:
	int Add(std::string numbers);

private:
	bool IsEmpty(std::string numbers);
	int StringToInt(std::string numbers);
	int GetSum(std::vector<std::string> numbers);
	void CheckForNegatives(std::vector<std::string> numbers);
	int CalculateIntegers(std::vector<std::string> numbers);
};

