#include "Lexer.hpp"

namespace Lua
{

Lexer::Lexer(const std::string &source)
	: source(source)
	, current(0)
{
}

Token Lexer::NextToken()
{
L_NextToken:
	// NOTE(ruarq): Should those be a lamdba?
	auto IsWhitespace = [](const char c) {
		return c == ' '
			|| c == '\n'
			|| c == '\t'
			|| c == '\r'
			|| c == '\v'
			|| c == '\f';
	};

	auto IsIdentifier = [](const char c) {
		return (c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')
			|| (c == '_');
	};

	auto IsDigit = [](const char c) {
		return c >= '0' && c <= '9';
	};

	if (Eof())
	{
		return Token::Type::Eof;
	}

	const char c = Consume();

	switch (c)
	{
		case ' ':
		case '\n':
		case '\t':
		case '\r':
		case '\v':
		case '\f':
			while (!Eof() && IsWhitespace(Current()))
			{
				Consume();
			}
			goto L_NextToken;

		case 'A' ... 'Z':
		case 'a' ... 'z':
		case '_': {
			std::string literal{ c };
			while (!Eof() && (IsIdentifier(Current()) || IsDigit(Current())))
			{
				literal += Consume();
			}

			const Token::Type type = GetKeywordType(literal);

			if (type == Token::Type::Identifier)
			{
				return Token(Token::Type::Identifier, literal);
			}
			else
			{
				return type;
			}
		}
		break;

		case '0' ... '9': {
			std::string literal{ c };
			while (!Eof() && IsDigit(Current()))
			{
				literal += Consume();
			}

			if (Current() == '.')
			{
				literal += Consume();
				while (!Eof() && IsDigit(Current()))
				{
					literal += Consume();
				}
			}

			return Token(Token::Type::Number, literal);
		}
		break;

		case '"':
		case '\'': {
			std::string literal;
			const char quote = c;

			while (!Eof() && Current() != quote && Current() != '\n')
			{
				literal += Consume();
			}

			if (Consume() != quote)
			{
				// TODO(ruarq): Diagnostics
				printf("Error: unterminated string.\n");
			}

			return Token(Token::Type::String, literal);
		}
		break;

		case '(':	return Token::Type::LParen;
		case ')':	return Token::Type::RParen;
		case '[':	return Token::Type::LBracket;
		case ']':	return Token::Type::RBracket;
		case '{':	return Token::Type::LCurly;
		case '}':	return Token::Type::RCurly;

		case '+':	return Token::Type::Plus;
		case '-':	return Token::Type::Minus;
		case '*':	return Token::Type::Star;
		case '%':	return Token::Type::Modulo;
		case '^':	return Token::Type::Caret;
		case '#':	return Token::Type::Hash;

		case '&':	return Token::Type::BitAnd;
		case '|':	return Token::Type::BitOr;

		case ',':	return Token::Type::Comma;
		case ';':	return Token::Type::Semicolon;

		// ., .., ...
		case '.':
			if (Current() == '.')
			{
				++current;
				if (Current() == '.')
				{
					++current;
					return Token::Type::Dot3;
				}

				return Token::Type::Dot2;
			}

			return Token::Type::Dot;

		// :, ::
		case ':':
			if (Current() == ':')
			{
				++current;
				return Token::Type::Colon2;
			}

			return Token::Type::Colon;

		// =, ==
		case '=':
			if (Current() == '=')
			{
				++current;
				return Token::Type::Equal;
			}

			return Token::Type::Assign;

		// <, <=, <<
		case '<':
			if (Current() == '=')
			{
				++current;
				return Token::Type::LessEqual;
			}
			else if (Current() == '<')
			{
				++current;
				return Token::Type::BitLShift;
			}

			return Token::Type::Less;

		// >, >=, >>
		case '>':
			if (Current() == '=')
			{
				++current;
				return Token::Type::GreaterEqual;
			}
			else if (Current() == '>')
			{
				++current;
				return Token::Type::BitRShift;
			}

			return Token::Type::Greater;

		// /, //
		case '/':
			if (Current() == '/')
			{
				++current;
				return Token::Type::Slash2;
			}

			return Token::Type::Slash;

		// ~, ~=
		case '~':
			if (Current() == '=')
			{
				++current;
				return Token::Type::NotEqual;
			}

			return Token::Type::BitFlip;

		default:
			break;
	}

	
	return Token::Type::Invalid;
}

bool Lexer::Eof() const
{
	return current >= source.size();
}

}
