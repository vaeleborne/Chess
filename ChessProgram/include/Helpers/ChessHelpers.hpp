#ifndef CHESS_HELPERS_HPP
#define CHESS_HELPERS_HPP
#include <string>
#include <sstream>
namespace Chess
{

	std::string ToLower(const std::string& input)
	{
		std::stringstream out;
		for (char c : input)
		{
			out << std::tolower(c);
		}
		return out.str();
	}

	bool IsKingSideCastle(const std::string& notation)
	{
		std::string test = ToLower(notation);
		return test == "0-0" || test == "o-o" || test == "0-o" || test == "o-0";
	}

	bool IsQueenSideCastle(const std::string& notation)
	{
		std::string test = ToLower(notation);
		bool testSetOne = test == "0-0-0" || test == "0-0-o" || test == "0-o-0" || test == "0-o-o";
		bool testSetTwo = test  == "o-0-0" || test == "o-0-o" || "o-o-0" || "o-o-o";

		return testSetOne || testSetTwo;
	}

	bool IsCastlingExpression(const std::string& notation)
	{
		return IsKingSideCastle(notation) || IsQueenSideCastle(notation);
	}


}

#endif