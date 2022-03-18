#include "Token.hpp"

namespace Lua
{

Token::Token(const Type type)
	: type(type)
{
}

Token::Token(const Type type, const std::string &literal)
	: type(type)
	, literal(literal)
{
}

}
