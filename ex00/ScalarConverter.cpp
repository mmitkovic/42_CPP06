#include "ScalarConverter.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

bool is_digit(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

bool is_dot(const std::string &str)
{
	size_t pos = str.find('.');
	return pos != std::string::npos ? true : false;
}

void ScalarConverter::convert(const std::string str)
{
	if (str.empty()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	// PSEUDO LITERALS check
	if (str == "nanf" || str == "+inff" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (str == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (str == "-inff") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
	else if (str == "nan" || str == "+inf" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nan") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (str == "+inf") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (str == "-inf") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
	// CHAR check
	else if (str.size() == 1 && !is_digit(str))
	{
		int i = static_cast<int>(str[0]);
		float f = static_cast<float>(str[0]);
		double d = static_cast<double>(str[0]);
		std::cout << "char: " << str << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
	{
		// NUMERIC types
		bool intOverflow = false;
		char *end;
		double number;
		number = strtod(str.c_str(), &end);
		if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
			intOverflow = true;
		if (*end == '\0') {
			if (is_dot(str)) {
				// DOUBLE
				char c = static_cast<char>(number);
				int i = static_cast<int>(number);
				float f = static_cast<float>(number);
				// char
				if (number < 0 || number > 127)
					std::cout << "char: impossible" << std::endl;
				else if ((c >= 0 && c <= 32) || c == 127)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: " << c << std::endl;
				// int
				if (intOverflow)
					std::cout << "int: impossible" << std::endl;
				else
					std::cout << "int: " << i << std::endl;
				// float & double
				if (fmod(number, 1.0) == 0) {
					std::cout << "float: " << std::fixed << std::setprecision(1) << number << "f" << std::endl;
					std::cout << "double: " << std::fixed << std::setprecision(1) << number << std::endl;
				}
				else {
					std::cout << "float: " << f << "f" << std::endl;
					std::cout << "double: " << number << std::endl;
				}
			}
			else {
				// INT
				char c = static_cast<char>(number);
				int i = static_cast<int>(number);
				float f = static_cast<float>(number);
				double d = static_cast<double>(number);
				// char
				if (number < 0 || number > 127)
					std::cout << "char: impossible" << std::endl;
				else if ((c >= 0 && c <= 32) || c == 127)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: " << c << std::endl;
				// int
				if (intOverflow)
					std::cout << "int: impossible" << std::endl;
				else
					std::cout << "int: " << i << std::endl;
				// float
				std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
				// double
				std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
			}
		}
		else if (*end == 'f' && *(end+1) == '\0') {
			// FLOAT
			char c = static_cast<char>(number);
			int i = static_cast<int>(number);
			float f = static_cast<float>(number);
			double d = static_cast<double>(number);
			// char
			if (number < 0 || number > 127)
				std::cout << "char: impossible" << std::endl;
			else if ((c >= 0 && c <= 32) || c == 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << c << std::endl;
			// int
			if (intOverflow)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << i << std::endl;
			// float & double
			if (fmod(number, 1.0) == 0) {
				std::cout << "float: " << std::fixed << std::setprecision(1) << number << "f" << std::endl;
				std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
			}
			else {
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << d << std::endl;
			}
		}
		else {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
}
