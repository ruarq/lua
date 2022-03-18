#ifndef LUA_LEXER_HPP
#define LUA_LEXER_HPP

#include <cstddef>
#include <string>

#include "Token.hpp"

namespace Lua
{

class Lexer
{
public:
	/**
	 * @brief Construct a new Lexer object
	 * 
	 * @param source The string to lex
	 */
	Lexer(const std::string &source);

public:
	/**
	 * @brief Lex the next token
	 * 
	 * @return Token 
	 */
	Token NextToken();

private:
	/**
	 * @brief Check if the lexer is eof
	 * 
	 * @return true if eof
	 * @return false if not eof
	 */
	bool Eof() const;

	/**
	 * @brief Get the current character
	 * 
	 * @return char 
	 */
	inline char Current() const { return source[current]; }

	/**
	 * @brief Consume the next character
	 * 
	 * @return char 
	 */
	inline char Consume() { return source[current++]; }

private:
	const std::string &source; ///< Const ref to the source we lex
	size_t current;
};

}

#endif
