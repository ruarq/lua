#ifndef LUA_TOKEN_HPP
#define LUA_TOKEN_HPP

#include <string>

namespace Lua
{

class Token
{
public:
	enum class Type
	{
		Eof,
		Invalid,

		// ASCII token types
		// TODO(ruarq): What is '~=' and what does it do?

		LParen,			///< (
		RParen,			///< )
		LBracket,		///< [
		RBracket,		///< ]
		LCurly,			///< {
		RCurly,			///< }

		Plus,			///< +
		Minus,			///< -
		Star,			///< *
		Slash,			///< /
		Slash2,			///< //
		Modulo,			///< %
		Caret,			///< ^
		Hash,			///< #

		BitAnd,			///< &
		BitOr,			///< |
		BitFlip,		///< ~
		BitLShift,		///< <<
		BitRShift,		///< >>

		Assign,			///< =

		Equal,			///< ==
		Less,			///< <
		Greater,		///< >
		LessEqual,		///< <=
		GreaterEqual,	///< >=

		Dot,			///< .
		Dot2,			///< ..
		Dot3,			///< ...
		Comma,			///< ,
		Colon,			///< :
		Colon2,			///< ::
		Semicolon,		///< ;

		// Keywords

		Local,			///< local

		If,				///< if
		ElseIf,			///< elseif
		Else,			///< else
		Then,			///< then
		And,			///< and
		Or,				///< or
		Not,			///< not

		Function,		///< function
		Return,			///< return
		End,			///< end

		Do,				///< do
		While,			///< while
		For,			///< for
		In,				///< in
		Repeat,			///< repeat
		Until,			///< until
		Break,			///< break
		Goto,			///< goto

		True,			///< true
		False,			///< false
		Nil,			///< nil
		String,			///< string literal
		Number,			///< number literal

		Identifier
	};

public:
	/**
	 * @brief Construct a new Token object
	 */
	Token() = default;

	/**
	 * @brief Construct a new Token object
	 * 
	 * @param type The type of the token
	 */
	Token(const Type type);

	/**
	 * @brief Construct a new Token object
	 * 
	 * @param type The type of the token
	 * @param literal The literal of the token
	 */
	Token(const Type type, const std::string &literal);

public:
	Type type;
	std::string literal;
};

constexpr const char* ToString(const Token::Type type)
{
	switch (type)
	{
		case Token::Type::Eof:			return "eof";
		case Token::Type::Invalid:		return "invalid";

		// ASCII token types

		case Token::Type::LParen:		return "(";
		case Token::Type::RParen:		return ")";
		case Token::Type::LBracket:		return "[";
		case Token::Type::RBracket:		return "]";
		case Token::Type::LCurly:		return "{";
		case Token::Type::RCurly:		return "}";

		case Token::Type::Plus:			return "+";
		case Token::Type::Minus:		return "-";
		case Token::Type::Star:			return "*";
		case Token::Type::Slash:		return "/";
		case Token::Type::Slash2:		return "//";
		case Token::Type::Modulo:		return "%";
		case Token::Type::Caret:		return "^";
		case Token::Type::Hash:			return "#";

		case Token::Type::BitAnd:		return "&";
		case Token::Type::BitOr:		return "|";
		case Token::Type::BitFlip:		return "~";
		case Token::Type::BitLShift:	return "<<";
		case Token::Type::BitRShift:	return ">>";

		case Token::Type::Assign:		return "=";

		case Token::Type::Equal:		return "==";
		case Token::Type::Less:			return "<";
		case Token::Type::Greater:		return ">";
		case Token::Type::LessEqual:	return "<=";
		case Token::Type::GreaterEqual:	return ">=";

		case Token::Type::Dot:			return ".";
		case Token::Type::Dot2:			return "..";
		case Token::Type::Dot3:			return "...";
		case Token::Type::Comma:		return ",";
		case Token::Type::Colon:		return ":";
		case Token::Type::Colon2:		return "::";
		case Token::Type::Semicolon:	return ";";

		// Keywords

		case Token::Type::Local:		return "local";

		case Token::Type::If:			return "if";
		case Token::Type::ElseIf:		return "elseif";
		case Token::Type::Else:			return "else";
		case Token::Type::Then:			return "then";
		case Token::Type::And:			return "and";
		case Token::Type::Or:			return "or";
		case Token::Type::Not:			return "not";

		case Token::Type::Function:		return "function";
		case Token::Type::Return:		return "return";
		case Token::Type::End:			return "end";

		case Token::Type::Do:			return "do";
		case Token::Type::While:		return "while";
		case Token::Type::For:			return "for";
		case Token::Type::In:			return "in";
		case Token::Type::Repeat:		return "repeat";
		case Token::Type::Until:		return "until";
		case Token::Type::Break:		return "break";
		case Token::Type::Goto:			return "goto";

		case Token::Type::True:			return "true";
		case Token::Type::False:		return "false";
		case Token::Type::Nil:			return "nil";
		case Token::Type::String:		return "string";
		case Token::Type::Number:		return "number";

		case Token::Type::Identifier:	return "identifier";

		default:
			break;
	}

	return nullptr;
}

}

#endif
