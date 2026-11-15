#pragma once
enum TokenType
{
	Number,
	Operat,
	OpenBr,
	CloseBr
};

struct Token
{
	TokenType type;
	string str;
	double val;
	int priority;

	Token(TokenType t = Number, string s = "", double v = 0.0, int p = 0)
		: type(t), str(s), val(v), priority(p) {
	}
};