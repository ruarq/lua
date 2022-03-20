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

Token::Type GetKeywordType(const std::string &literal)
{
	if (literal == "local")			return Token::Type::Local;
	else if (literal == "if")		return Token::Type::If;
	else if (literal == "elseif")	return Token::Type::ElseIf;
	else if (literal == "else")		return Token::Type::Else;
	else if (literal == "then")		return Token::Type::Then;
	else if (literal == "and")		return Token::Type::And;
	else if (literal == "or")		return Token::Type::Or;
	else if (literal == "not")		return Token::Type::Not;
	else if (literal == "function")	return Token::Type::Function;
	else if (literal == "return")	return Token::Type::Return;
	else if (literal == "end")		return Token::Type::End;
	else if (literal == "do")		return Token::Type::Do;
	else if (literal == "while")	return Token::Type::While;
	else if (literal == "for")		return Token::Type::For;
	else if (literal == "in")		return Token::Type::In;
	else if (literal == "repeat")	return Token::Type::Repeat;
	else if (literal == "until")	return Token::Type::Until;
	else if (literal == "break")	return Token::Type::Break;
	else if (literal == "goto")		return Token::Type::Goto;
	else if (literal == "true")		return Token::Type::True;
	else if (literal == "false")	return Token::Type::False;
	else if (literal == "nil")		return Token::Type::Nil;
	else							return Token::Type::Identifier;
}

}
