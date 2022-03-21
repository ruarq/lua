#ifndef LUA_AST_HPP
#define LUA_AST_HPP

#include <string>

namespace Lua::Ast
{

/**
 * @brief Ast base class
 * 
 */
class Node
{
public:
	virtual ~Node() = default;
};

/**
 * @brief Ast expression base class
 * 
 */
class Expression : public Node
{
public:
	virtual ~Expression() = default;
};

/**
 * @brief Ast number expression
 * 
 */
class NumberExpression : public Expression
{
public:
	double value;
};

/**
 * @brief Ast statement base class
 * 
 */
class Statement : public Node
{
public:
	virtual ~Statement() = default;
};

/**
 * @brief Ast assign statement
 * 
 */
class AssignStatement : public Statement
{
public:
	virtual ~AssignStatement();

public:
	std::string symbol; // TODO(ruarq): Some kind of Identifier + Symbol class
	Expression *expr = nullptr;
};

}

#endif
