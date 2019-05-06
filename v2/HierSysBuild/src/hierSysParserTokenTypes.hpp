#ifndef INC_hierSysParserTokenTypes_hpp_
#define INC_hierSysParserTokenTypes_hpp_

/* $ANTLR 2.7.7 (20190421): "hierSys.g" -> "hierSysParserTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API hierSysParserTokenTypes {
#endif
	enum {
		EOF_ = 1,
		SYSTEM = 4,
		SIMPLE_IDENTIFIER = 5,
		LIBRARY = 6,
		IN = 7,
		OUT = 8,
		LBRACE = 9,
		RBRACE = 10,
		NOBLOCK = 11,
		P2P = 12,
		SHIFTREG = 13,
		BYPASS = 14,
		PIPE = 15,
		SIGNAL = 16,
		UINTEGER = 17,
		DEPTH = 18,
		INSTANCE = 19,
		COLON = 20,
		IMPLIES = 21,
		LIFO = 22,
		UINT = 23,
		LESS = 24,
		GREATER = 25,
		THREAD = 26,
		DEFAULT = 27,
		NOW = 28,
		TICK = 29,
		STRING = 30,
		VARIABLE = 31,
		CONSTANT = 32,
		ASSIGNEQUAL = 33,
		SPLIT = 34,
		LPAREN = 35,
		RPAREN = 36,
		NuLL = 37,
		GOTO = 38,
		LOG = 39,
		IF = 40,
		ELSE = 41,
		BINARY = 42,
		HEXADECIMAL = 43,
		COMMA = 44,
		REQ = 45,
		ACK = 46,
		LBRACKET = 47,
		RBRACKET = 48,
		SLICE = 49,
		MUX = 50,
		NOT = 51,
		OR = 52,
		AND = 53,
		NOR = 54,
		NAND = 55,
		XOR = 56,
		XNOR = 57,
		SHL = 58,
		SHR = 59,
		ROL = 60,
		ROR = 61,
		PLUS = 62,
		MINUS = 63,
		MUL = 64,
		DIV = 65,
		EQUAL = 66,
		NOTEQUAL = 67,
		LESSEQUAL = 68,
		GREATEREQUAL = 69,
		INTEGER = 70,
		UNSIGNED = 71,
		SIGNED = 72,
		ARRAY = 73,
		OF = 74,
		PARAMETER = 75,
		HEXCSTYLEINTEGER = 76,
		POWER = 77,
		CONCAT = 78,
		EMIT = 79,
		WHITESPACE = 80,
		SINGLELINECOMMENT = 81,
		ALPHA = 82,
		DIGIT = 83,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_hierSysParserTokenTypes_hpp_*/
