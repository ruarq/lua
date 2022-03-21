#include "Parser.hpp"

namespace Lua
{

Parser::Parser(Lexer &lexer)
	: lexer(lexer)
{
}

Ast::Node* Parser::Run()
{
	return Statement();
}

Ast::Expression* Parser::Expression()
{
	NextToken();

	switch (currToken.type)
	{
		case Token::Type::Number:
			return NumberExpression();

		default:
			break;
	}

	return nullptr;
}

Ast::NumberExpression* Parser::NumberExpression()
{
	auto numberExpr = new Ast::NumberExpression();
	numberExpr->value = std::stod(currToken.literal);
	return numberExpr;
}

Ast::Statement* Parser::Statement()
{
	NextToken();

	switch (currToken.type)
	{
		case Token::Type::Identifier:
			return AssignStatement();

		default:
			break;
	}

	return nullptr;
}

Ast::AssignStatement* Parser::AssignStatement()
{
	auto assignStmt = new Ast::AssignStatement();
	assignStmt->symbol = currToken.literal;
	Consume(Token::Type::Assign);
	assignStmt->expr = Expression();
	return assignStmt;
}

void Parser::NextToken()
{
	currToken = lexer.NextToken();
}

void Parser::Consume(const Token::Type type)
{
	NextToken();

	if (currToken.type != type)
	{
		printf("Error: Unexpected token\n");
	}
}

}
