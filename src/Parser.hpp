#ifndef LUA_PARSER_HPP
#define LUA_PARSER_HPP

#include "Lexer.hpp"
#include "Token.hpp"
#include "Ast.hpp"

namespace Lua
{

class Parser
{
public:
	/**
	 * @brief Construct a new Parser object
	 * 
	 * @param lexer A reference to a lexer object that's used for tokenization
	 */
	Parser(Lexer &lexer);

public:
	/**
	 * @brief Run the parser
	 * 
	 * @return Ast::Node* 
	 */
	Ast::Node* Run();

private:
	/**
	 * @brief Parse a expression
	 * 
	 * @return Ast::Expression*
	 */
	Ast::Expression* Expression();

	/**
	 * @brief Parse a number expression
	 * 
	 * @return Ast::NumberExpression* 
	 */
	Ast::NumberExpression* NumberExpression();

	/**
	 * @brief Parse a statement
	 * 
	 * @return Ast::Statement* 
	 */
	Ast::Statement* Statement();

	/**
	 * @brief Parse a assign statement
	 * 
	 * @return Ast::AssignStatement* 
	 */
	Ast::AssignStatement* AssignStatement();

	/**
	 * @brief Lex the next token
	 */
	void NextToken();

	/**
	 * @brief Consume a specific token
	 *
	 */
	void Consume(const Token::Type type);

private:
	Lexer &lexer;
	Token currToken;
};

}

#endif
