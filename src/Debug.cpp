#include "Debug.hpp"

namespace Lua
{

void DebugExpression(const Ast::Expression *expr)
{
	if (auto numberExpr = dynamic_cast<const Ast::NumberExpression*>(expr))
	{
		std::cout << numberExpr->value;
	}
}

void DebugAssignStmt(const Ast::AssignStatement *assignStmt)
{
	std::cout << assignStmt->symbol << " = ";
	DebugExpression(assignStmt->expr);
	std::cout << "\n";
}

void Debug(const Ast::Node *ast)
{
	if (auto assignStmt = dynamic_cast<const Ast::AssignStatement*>(ast))
	{
		DebugAssignStmt(assignStmt);
	}
}

}
