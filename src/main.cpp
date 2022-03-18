#include <iostream>
#include <fstream>

#include "Lexer.hpp"

using namespace Lua;

std::string ReadFile(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return std::string();
	}

	std::string source, line;

	while (std::getline(file, line))
	{
		source += line + "\n";
	}

	return source;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " file\n";
		return 1;
	}

	const std::string source = ReadFile(argv[1]);
	Lexer lexer(source);
	
	Token token;
	do
	{
		token = lexer.NextToken();
		std::cout << ToString(token.type) << " <> '" << token.literal << "'\n";
	} while (token.type != Token::Type::Eof && token.type != Token::Type::Invalid);

	return 0;
}
