#ifndef INC_vcParserTokenTypes_hpp_
#define INC_vcParserTokenTypes_hpp_

/* $ANTLR 2.7.7 (2006-11-01): "vc.g" -> "vcParserTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API vcParserTokenTypes {
#endif
	enum {
		EOF_ = 1,
		PIPE = 4,
		UINTEGER = 5,
		MEMORYSPACE = 6,
		LBRACE = 7,
		RBRACE = 8,
		CAPACITY = 9,
		DATAWIDTH = 10,
		ADDRWIDTH = 11,
		OBJECT = 12,
		COLON = 13,
		ASSIGN_OP = 14,
		MODULE = 15,
		SIMPLE_IDENTIFIER = 16,
		EQUIVALENT = 17,
		LPAREN = 18,
		RPAREN = 19,
		DIV_OP = 20,
		ENTRY = 21,
		EXIT = 22,
		CONTROLPATH = 23,
		PLACE = 24,
		TRANSITION = 25,
		SERIESBLOCK = 26,
		PARALLELBLOCK = 27,
		BRANCHBLOCK = 28,
		MERGE = 29,
		BRANCH = 30,
		FORKBLOCK = 31,
		JOIN = 32,
		FORK = 33,
		DATAPATH = 34,
		PLUS_OP = 35,
		MINUS_OP = 36,
		MUL_OP = 37,
		SHL_OP = 38,
		SHR_OP = 39,
		GT_OP = 40,
		GE_OP = 41,
		EQ_OP = 42,
		LT_OP = 43,
		LE_OP = 44,
		NEQ_OP = 45,
		BITSEL_OP = 46,
		CONCAT_OP = 47,
		OR_OP = 48,
		AND_OP = 49,
		XOR_OP = 50,
		NOR_OP = 51,
		NAND_OP = 52,
		XNOR_OP = 53,
		NOT_OP = 54,
		BRANCH_OP = 55,
		SELECT_OP = 56,
		CALL = 57,
		INLINE = 58,
		IOPORT = 59,
		IN = 60,
		OUT = 61,
		LOAD = 62,
		FROM = 63,
		STORE = 64,
		TO = 65,
		PHI = 66,
		LBRACKET = 67,
		RBRACKET = 68,
		CONSTANT = 69,
		WIRE = 70,
		COMMA = 71,
		BINARYSTRING = 72,
		HEXSTRING = 73,
		MINUS = 74,
		LITERAL_C = 75,
		LITERAL_M = 76,
		INT = 77,
		FLOAT = 78,
		POINTER = 79,
		ARRAY = 80,
		OF = 81,
		RECORD = 82,
		ATTRIBUTE = 83,
		IMPLIES = 84,
		QUOTED_STRING = 85,
		DPE = 86,
		LIBRARY = 87,
		REQS = 88,
		ACKS = 89,
		HIDDEN = 90,
		PARAMETER = 91,
		PORT = 92,
		MAP = 93,
		MIN = 94,
		MAX = 95,
		DPEINSTANCE = 96,
		LINK = 97,
		AT = 98,
		UGT_OP = 99,
		UGE_OP = 100,
		ULT_OP = 101,
		ULE_OP = 102,
		UNORDERED_OP = 103,
		WHITESPACE = 104,
		SINGLELINECOMMENT = 105,
		HIERARCHICAL_IDENTIFIER = 106,
		ALPHA = 107,
		DIGIT = 108,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_vcParserTokenTypes_hpp_*/
