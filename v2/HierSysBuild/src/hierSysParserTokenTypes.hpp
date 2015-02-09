#ifndef INC_hierSysParserTokenTypes_hpp_
#define INC_hierSysParserTokenTypes_hpp_

/* $ANTLR 2.7.7 (2006-11-01): "hierSys.g" -> "hierSysParserTokenTypes.hpp"$ */

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
		INPIPE = 6,
		UINTEGER = 7,
		OUTPIPE = 8,
		LBRACE = 9,
		INTERNALPIPE = 10,
		RBRACE = 11,
		INSTANCE = 12,
		IMPLIES = 13,
		WHITESPACE = 14,
		SINGLELINECOMMENT = 15,
		ALPHA = 16,
		DIGIT = 17,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_hierSysParserTokenTypes_hpp_*/