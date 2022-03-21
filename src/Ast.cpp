#include "Ast.hpp"

namespace Lua::Ast
{

AssignStatement::~AssignStatement()
{
	delete expr;
}

}
