#include <cmath>
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
# define M_PIl          3.141592653589793238462643383279502884L

inline std::string DecimalToRoman(double number)
{

	std::map<int, std::string> codes;
	codes[1] = "I";
	codes[4] = "IV";
	codes[5] = "V";
	codes[9] = "IX";
	codes[10] = "X";
	codes[40] = "XL";
	codes[50] = "L";
	codes[90] = "XC";
	codes[100] = "C";
	codes[400] = "CD";
	codes[500] = "D";
	codes[900] = "CM";
	codes[1000] = "M";

	std::ostringstream roman;
	std::vector<int> divisors;
	std::transform(codes.begin(), codes.end(), std::back_inserter(divisors), [](const std::pair<int, std::string>& x) {return x.first; });
	
	std::sort(divisors.rbegin(),divisors.rend());
	int r = 0;
	for(auto d:divisors)
	{
		int q = floor(number / d);
		r = number - q;
		for (int i = 0; i < q; ++i) roman << codes[d];
		number -= q*d;
		if (number == 0) break;
	}
	
	return roman.str();
}