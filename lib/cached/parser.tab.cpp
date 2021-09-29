/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         mzn_yyparse
#define yylex           mzn_yylex
#define yyerror         mzn_yyerror
#define yydebug         mzn_yydebug
#define yynerrs         mzn_yynerrs

/* First part of user prologue.  */

#define SCANNER static_cast<ParserState*>(parm)->yyscanner
#include <iostream>
#include <fstream>
#include <map>
#include <cerrno>

namespace MiniZinc{ class ParserLocation; }
#define YYLTYPE MiniZinc::ParserLocation
#define YYLTYPE_IS_DECLARED 1
#define YYLTYPE_IS_TRIVIAL 0

#define YYMAXDEPTH 10000
#define YYINITDEPTH 10000

#include <minizinc/parser.hh>
#include <minizinc/file_utils.hh>

using namespace std;
using namespace MiniZinc;

#define YYLLOC_DEFAULT(Current, Rhs, N) \
  do { \
    if (N > 0) { \
      (Current).filename(YYRHSLOC(Rhs, 1).filename()); \
      (Current).firstLine(YYRHSLOC(Rhs, 1).firstLine()); \
      (Current).firstColumn(YYRHSLOC(Rhs, 1).firstColumn()); \
      (Current).lastLine(YYRHSLOC(Rhs, N).lastLine()); \
      (Current).lastColumn(YYRHSLOC(Rhs, N).lastColumn()); \
    } else { \
      (Current).filename(YYRHSLOC(Rhs, 0).filename()); \
      (Current).firstLine(YYRHSLOC(Rhs, 0).lastLine()); \
      (Current).firstColumn(YYRHSLOC(Rhs, 0).lastColumn()); \
      (Current).lastLine(YYRHSLOC(Rhs, 0).lastLine()); \
      (Current).lastColumn(YYRHSLOC(Rhs, 0).lastColumn()); \
    } \
  } while (false)

int mzn_yyparse(void*);
int mzn_yylex(YYSTYPE*, YYLTYPE*, void* scanner);
int mzn_yylex_init (void** scanner);
int mzn_yylex_destroy (void* scanner);
int mzn_yyget_lineno (void* scanner);
void mzn_yyset_extra (void* user_defined ,void* yyscanner );

extern int yydebug;

namespace MiniZinc {

void yyerror(YYLTYPE* location, void* parm, const string& str) {
  ParserState* pp = static_cast<ParserState*>(parm);
  Model* m = pp->model;
  while (m->parent() != nullptr) {
    m = m->parent();
    pp->err << "(included from file '" << m->filename() << "')" << endl;
  }
  pp->err << location->toString() << ":" << endl;
  pp->printCurrentLine(location->firstColumn(),location->lastColumn());
  pp->err << "Error: " << str << std::endl;
  pp->hadError = true;
  pp->syntaxErrors.push_back(SyntaxError(Location(*location), str));
}

bool notInDatafile(YYLTYPE* location, void* parm, const string& item) {
  ParserState* pp = static_cast<ParserState*>(parm);
  if (pp->isDatafile) {
    yyerror(location,parm,item+" item not allowed in data file");
    return false;
  }
  return true;
}

Expression* createDocComment(const ParserLocation& loc, const std::string& s) {
  std::vector<Expression*> args(1);
  args[0] = new StringLit(loc, s);
  Call* c = new Call(Location(loc), Constants::constants().ann.doc_comment, args);
  c->type(Type::ann());
  return c;
}

Expression* createArrayAccess(const ParserLocation& loc, Expression* e, std::vector<std::vector<Expression*> >& idx) {
  Expression* ret = e;
  for (unsigned int i=0; i<idx.size(); i++) {
    ret = new ArrayAccess(Location(loc), ret, idx[i]);
  }
  return ret;
}

bool noTuple(ParserLocation& location, void* parm, Expression* e) {
  if (e != nullptr && e->isa<ArrayLit>() && e->cast<ArrayLit>()->isTuple()) {
    yyerror(&location, parm, "tuple not allowed here");
    return false;
  }
  return e != nullptr;
}

}



# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include <minizinc/parser.tab.hh>
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MZN_INTEGER_LITERAL = 3,        /* "integer literal"  */
  YYSYMBOL_MZN_BOOL_LITERAL = 4,           /* "bool literal"  */
  YYSYMBOL_MZN_FLOAT_LITERAL = 5,          /* "float literal"  */
  YYSYMBOL_MZN_IDENTIFIER = 6,             /* "identifier"  */
  YYSYMBOL_MZN_QUOTED_IDENTIFIER = 7,      /* "quoted identifier"  */
  YYSYMBOL_MZN_STRING_LITERAL = 8,         /* "string literal"  */
  YYSYMBOL_MZN_STRING_QUOTE_START = 9,     /* "interpolated string start"  */
  YYSYMBOL_MZN_STRING_QUOTE_MID = 10,      /* "interpolated string middle"  */
  YYSYMBOL_MZN_STRING_QUOTE_END = 11,      /* "interpolated string end"  */
  YYSYMBOL_MZN_TI_IDENTIFIER = 12,         /* "type-inst identifier"  */
  YYSYMBOL_MZN_TI_ENUM_IDENTIFIER = 13,    /* "type-inst enum identifier"  */
  YYSYMBOL_MZN_DOC_COMMENT = 14,           /* "documentation comment"  */
  YYSYMBOL_MZN_DOC_FILE_COMMENT = 15,      /* "file-level documentation comment"  */
  YYSYMBOL_MZN_VAR = 16,                   /* "var"  */
  YYSYMBOL_MZN_PAR = 17,                   /* "par"  */
  YYSYMBOL_MZN_ABSENT = 18,                /* "<>"  */
  YYSYMBOL_MZN_ANN = 19,                   /* "ann"  */
  YYSYMBOL_MZN_ANNOTATION = 20,            /* "annotation"  */
  YYSYMBOL_MZN_ANY = 21,                   /* "any"  */
  YYSYMBOL_MZN_ARRAY = 22,                 /* "array"  */
  YYSYMBOL_MZN_BOOL = 23,                  /* "bool"  */
  YYSYMBOL_MZN_CASE = 24,                  /* "case"  */
  YYSYMBOL_MZN_CONSTRAINT = 25,            /* "constraint"  */
  YYSYMBOL_MZN_DEFAULT = 26,               /* "default"  */
  YYSYMBOL_MZN_ELSE = 27,                  /* "else"  */
  YYSYMBOL_MZN_ELSEIF = 28,                /* "elseif"  */
  YYSYMBOL_MZN_ENDIF = 29,                 /* "endif"  */
  YYSYMBOL_MZN_ENUM = 30,                  /* "enum"  */
  YYSYMBOL_MZN_FLOAT = 31,                 /* "float"  */
  YYSYMBOL_MZN_FUNCTION = 32,              /* "function"  */
  YYSYMBOL_MZN_IF = 33,                    /* "if"  */
  YYSYMBOL_MZN_INCLUDE = 34,               /* "include"  */
  YYSYMBOL_MZN_INFINITY = 35,              /* "infinity"  */
  YYSYMBOL_MZN_INT = 36,                   /* "int"  */
  YYSYMBOL_MZN_LET = 37,                   /* "let"  */
  YYSYMBOL_MZN_LIST = 38,                  /* "list"  */
  YYSYMBOL_MZN_MAXIMIZE = 39,              /* "maximize"  */
  YYSYMBOL_MZN_MINIMIZE = 40,              /* "minimize"  */
  YYSYMBOL_MZN_OF = 41,                    /* "of"  */
  YYSYMBOL_MZN_OPT = 42,                   /* "opt"  */
  YYSYMBOL_MZN_SATISFY = 43,               /* "satisfy"  */
  YYSYMBOL_MZN_OUTPUT = 44,                /* "output"  */
  YYSYMBOL_MZN_PREDICATE = 45,             /* "predicate"  */
  YYSYMBOL_MZN_RECORD = 46,                /* "record"  */
  YYSYMBOL_MZN_SET = 47,                   /* "set"  */
  YYSYMBOL_MZN_SOLVE = 48,                 /* "solve"  */
  YYSYMBOL_MZN_STRING = 49,                /* "string"  */
  YYSYMBOL_MZN_TEST = 50,                  /* "test"  */
  YYSYMBOL_MZN_THEN = 51,                  /* "then"  */
  YYSYMBOL_MZN_TUPLE = 52,                 /* "tuple"  */
  YYSYMBOL_MZN_TYPE = 53,                  /* "type"  */
  YYSYMBOL_MZN_UNDERSCORE = 54,            /* "_"  */
  YYSYMBOL_MZN_VARIANT_RECORD = 55,        /* "variant_record"  */
  YYSYMBOL_MZN_WHERE = 56,                 /* "where"  */
  YYSYMBOL_MZN_LEFT_BRACKET = 57,          /* "["  */
  YYSYMBOL_MZN_LEFT_2D_BRACKET = 58,       /* "[|"  */
  YYSYMBOL_MZN_RIGHT_BRACKET = 59,         /* "]"  */
  YYSYMBOL_MZN_RIGHT_2D_BRACKET = 60,      /* "|]"  */
  YYSYMBOL_QUOTED_IDENTIFIER = 61,         /* QUOTED_IDENTIFIER  */
  YYSYMBOL_MZN_INVALID_INTEGER_LITERAL = 62, /* "invalid integer literal"  */
  YYSYMBOL_MZN_INVALID_FLOAT_LITERAL = 63, /* "invalid float literal"  */
  YYSYMBOL_MZN_UNTERMINATED_STRING = 64,   /* "unterminated string"  */
  YYSYMBOL_MZN_END_OF_LINE_IN_STRING = 65, /* "end of line inside string literal"  */
  YYSYMBOL_MZN_INVALID_NULL = 66,          /* "null character"  */
  YYSYMBOL_MZN_INVALID_STRING_LITERAL = 67, /* "invalid string literal"  */
  YYSYMBOL_MZN_EQUIV = 68,                 /* "<->"  */
  YYSYMBOL_MZN_IMPL = 69,                  /* "->"  */
  YYSYMBOL_MZN_RIMPL = 70,                 /* "<-"  */
  YYSYMBOL_MZN_OR = 71,                    /* "\\/"  */
  YYSYMBOL_MZN_XOR = 72,                   /* "xor"  */
  YYSYMBOL_MZN_AND = 73,                   /* "/\\"  */
  YYSYMBOL_MZN_LE = 74,                    /* "<"  */
  YYSYMBOL_MZN_GR = 75,                    /* ">"  */
  YYSYMBOL_MZN_LQ = 76,                    /* "<="  */
  YYSYMBOL_MZN_GQ = 77,                    /* ">="  */
  YYSYMBOL_MZN_EQ = 78,                    /* "="  */
  YYSYMBOL_MZN_NQ = 79,                    /* "!="  */
  YYSYMBOL_MZN_WEAK_EQ = 80,               /* "~="  */
  YYSYMBOL_MZN_WEAK_NQ = 81,               /* "~!="  */
  YYSYMBOL_MZN_IN = 82,                    /* "in"  */
  YYSYMBOL_MZN_SUBSET = 83,                /* "subset"  */
  YYSYMBOL_MZN_SUPERSET = 84,              /* "superset"  */
  YYSYMBOL_MZN_UNION = 85,                 /* "union"  */
  YYSYMBOL_MZN_DIFF = 86,                  /* "diff"  */
  YYSYMBOL_MZN_SYMDIFF = 87,               /* "symdiff"  */
  YYSYMBOL_MZN_DOTDOT = 88,                /* ".."  */
  YYSYMBOL_MZN_DOTDOT_LE = 89,             /* "..<"  */
  YYSYMBOL_MZN_LE_DOTDOT = 90,             /* "<.."  */
  YYSYMBOL_MZN_LE_DOTDOT_LE = 91,          /* "<..<"  */
  YYSYMBOL_MZN_PLUS = 92,                  /* "+"  */
  YYSYMBOL_MZN_MINUS = 93,                 /* "-"  */
  YYSYMBOL_MZN_WEAK_PLUS = 94,             /* "~+"  */
  YYSYMBOL_MZN_WEAK_MINUS = 95,            /* "~-"  */
  YYSYMBOL_MZN_MULT = 96,                  /* "*"  */
  YYSYMBOL_MZN_DIV = 97,                   /* "/"  */
  YYSYMBOL_MZN_IDIV = 98,                  /* "div"  */
  YYSYMBOL_MZN_MOD = 99,                   /* "mod"  */
  YYSYMBOL_MZN_WEAK_DIV = 100,             /* "~/"  */
  YYSYMBOL_MZN_WEAK_IDIV = 101,            /* "~div"  */
  YYSYMBOL_MZN_INTERSECT = 102,            /* "intersect"  */
  YYSYMBOL_MZN_WEAK_MULT = 103,            /* "~*"  */
  YYSYMBOL_MZN_POW = 104,                  /* "^"  */
  YYSYMBOL_MZN_POW_MINUS1 = 105,           /* "^-1"  */
  YYSYMBOL_MZN_NOT = 106,                  /* "not"  */
  YYSYMBOL_MZN_PLUSPLUS = 107,             /* "++"  */
  YYSYMBOL_MZN_COLONCOLON = 108,           /* "::"  */
  YYSYMBOL_PREC_ANNO = 109,                /* PREC_ANNO  */
  YYSYMBOL_MZN_EQUIV_QUOTED = 110,         /* "'<->'"  */
  YYSYMBOL_MZN_IMPL_QUOTED = 111,          /* "'->'"  */
  YYSYMBOL_MZN_RIMPL_QUOTED = 112,         /* "'<-'"  */
  YYSYMBOL_MZN_OR_QUOTED = 113,            /* "'\\/'"  */
  YYSYMBOL_MZN_XOR_QUOTED = 114,           /* "'xor'"  */
  YYSYMBOL_MZN_AND_QUOTED = 115,           /* "'/\\'"  */
  YYSYMBOL_MZN_LE_QUOTED = 116,            /* "'<'"  */
  YYSYMBOL_MZN_GR_QUOTED = 117,            /* "'>'"  */
  YYSYMBOL_MZN_LQ_QUOTED = 118,            /* "'<='"  */
  YYSYMBOL_MZN_GQ_QUOTED = 119,            /* "'>='"  */
  YYSYMBOL_MZN_EQ_QUOTED = 120,            /* "'='"  */
  YYSYMBOL_MZN_NQ_QUOTED = 121,            /* "'!='"  */
  YYSYMBOL_MZN_IN_QUOTED = 122,            /* "'in'"  */
  YYSYMBOL_MZN_SUBSET_QUOTED = 123,        /* "'subset'"  */
  YYSYMBOL_MZN_SUPERSET_QUOTED = 124,      /* "'superset'"  */
  YYSYMBOL_MZN_UNION_QUOTED = 125,         /* "'union'"  */
  YYSYMBOL_MZN_DIFF_QUOTED = 126,          /* "'diff'"  */
  YYSYMBOL_MZN_SYMDIFF_QUOTED = 127,       /* "'symdiff'"  */
  YYSYMBOL_MZN_DOTDOT_QUOTED = 128,        /* "'..'"  */
  YYSYMBOL_MZN_LE_DOTDOT_QUOTED = 129,     /* "'<..'"  */
  YYSYMBOL_MZN_DOTDOT_LE_QUOTED = 130,     /* "'..<'"  */
  YYSYMBOL_MZN_LE_DOTDOT_LE_QUOTED = 131,  /* "'<..<'"  */
  YYSYMBOL_MZN_PLUS_QUOTED = 132,          /* "'+'"  */
  YYSYMBOL_MZN_MINUS_QUOTED = 133,         /* "'-'"  */
  YYSYMBOL_MZN_MULT_QUOTED = 134,          /* "'*'"  */
  YYSYMBOL_MZN_DIV_QUOTED = 135,           /* "'/'"  */
  YYSYMBOL_MZN_IDIV_QUOTED = 136,          /* "'div'"  */
  YYSYMBOL_MZN_MOD_QUOTED = 137,           /* "'mod'"  */
  YYSYMBOL_MZN_INTERSECT_QUOTED = 138,     /* "'intersect'"  */
  YYSYMBOL_MZN_POW_QUOTED = 139,           /* "'^'"  */
  YYSYMBOL_MZN_NOT_QUOTED = 140,           /* "'not'"  */
  YYSYMBOL_MZN_COLONCOLON_QUOTED = 141,    /* "'::'"  */
  YYSYMBOL_MZN_PLUSPLUS_QUOTED = 142,      /* "'++'"  */
  YYSYMBOL_143_ = 143,                     /* ';'  */
  YYSYMBOL_144_ = 144,                     /* '{'  */
  YYSYMBOL_145_ = 145,                     /* '}'  */
  YYSYMBOL_146_ = 146,                     /* '('  */
  YYSYMBOL_147_ = 147,                     /* ')'  */
  YYSYMBOL_148_ = 148,                     /* ','  */
  YYSYMBOL_149_ = 149,                     /* ':'  */
  YYSYMBOL_150_ = 150,                     /* '|'  */
  YYSYMBOL_YYACCEPT = 151,                 /* $accept  */
  YYSYMBOL_model = 152,                    /* model  */
  YYSYMBOL_item_list = 153,                /* item_list  */
  YYSYMBOL_item_list_head = 154,           /* item_list_head  */
  YYSYMBOL_doc_file_comments = 155,        /* doc_file_comments  */
  YYSYMBOL_semi_or_none = 156,             /* semi_or_none  */
  YYSYMBOL_item = 157,                     /* item  */
  YYSYMBOL_item_tail = 158,                /* item_tail  */
  YYSYMBOL_error_item_start = 159,         /* error_item_start  */
  YYSYMBOL_include_item = 160,             /* include_item  */
  YYSYMBOL_vardecl_item = 161,             /* vardecl_item  */
  YYSYMBOL_enum_init = 162,                /* enum_init  */
  YYSYMBOL_enum_construct = 163,           /* enum_construct  */
  YYSYMBOL_string_lit_list = 164,          /* string_lit_list  */
  YYSYMBOL_enum_id_list = 165,             /* enum_id_list  */
  YYSYMBOL_assign_item = 166,              /* assign_item  */
  YYSYMBOL_constraint_item = 167,          /* constraint_item  */
  YYSYMBOL_solve_item = 168,               /* solve_item  */
  YYSYMBOL_output_item = 169,              /* output_item  */
  YYSYMBOL_predicate_item = 170,           /* predicate_item  */
  YYSYMBOL_function_item = 171,            /* function_item  */
  YYSYMBOL_annotation_item = 172,          /* annotation_item  */
  YYSYMBOL_ann_param = 173,                /* ann_param  */
  YYSYMBOL_operation_item_tail = 174,      /* operation_item_tail  */
  YYSYMBOL_params = 175,                   /* params  */
  YYSYMBOL_params_list = 176,              /* params_list  */
  YYSYMBOL_params_list_head = 177,         /* params_list_head  */
  YYSYMBOL_comma_or_none = 178,            /* comma_or_none  */
  YYSYMBOL_pipe_or_none = 179,             /* pipe_or_none  */
  YYSYMBOL_ti_expr_and_id_or_anon = 180,   /* ti_expr_and_id_or_anon  */
  YYSYMBOL_ti_expr_and_id = 181,           /* ti_expr_and_id  */
  YYSYMBOL_ti_expr_list = 182,             /* ti_expr_list  */
  YYSYMBOL_ti_expr_list_head = 183,        /* ti_expr_list_head  */
  YYSYMBOL_ti_expr = 184,                  /* ti_expr  */
  YYSYMBOL_base_ti_expr = 185,             /* base_ti_expr  */
  YYSYMBOL_opt_opt = 186,                  /* opt_opt  */
  YYSYMBOL_base_ti_expr_tail = 187,        /* base_ti_expr_tail  */
  YYSYMBOL_array_access_expr_list = 188,   /* array_access_expr_list  */
  YYSYMBOL_array_access_expr_list_head = 189, /* array_access_expr_list_head  */
  YYSYMBOL_array_access_expr = 190,        /* array_access_expr  */
  YYSYMBOL_expr_list = 191,                /* expr_list  */
  YYSYMBOL_expr_list_head = 192,           /* expr_list_head  */
  YYSYMBOL_set_expr = 193,                 /* set_expr  */
  YYSYMBOL_expr = 194,                     /* expr  */
  YYSYMBOL_expr_atom_head = 195,           /* expr_atom_head  */
  YYSYMBOL_expr_atom_head_nonstring = 196, /* expr_atom_head_nonstring  */
  YYSYMBOL_string_expr = 197,              /* string_expr  */
  YYSYMBOL_string_quote_rest = 198,        /* string_quote_rest  */
  YYSYMBOL_array_access_tail = 199,        /* array_access_tail  */
  YYSYMBOL_set_literal = 200,              /* set_literal  */
  YYSYMBOL_set_comp = 201,                 /* set_comp  */
  YYSYMBOL_comp_tail = 202,                /* comp_tail  */
  YYSYMBOL_generator_list = 203,           /* generator_list  */
  YYSYMBOL_generator_list_head = 204,      /* generator_list_head  */
  YYSYMBOL_generator = 205,                /* generator  */
  YYSYMBOL_generator_eq = 206,             /* generator_eq  */
  YYSYMBOL_id_list = 207,                  /* id_list  */
  YYSYMBOL_id_list_head = 208,             /* id_list_head  */
  YYSYMBOL_simple_array_literal = 209,     /* simple_array_literal  */
  YYSYMBOL_simple_array_literal_2d = 210,  /* simple_array_literal_2d  */
  YYSYMBOL_simple_array_literal_3d_list = 211, /* simple_array_literal_3d_list  */
  YYSYMBOL_simple_array_literal_2d_list = 212, /* simple_array_literal_2d_list  */
  YYSYMBOL_simple_array_literal_2d_indexed_list = 213, /* simple_array_literal_2d_indexed_list  */
  YYSYMBOL_simple_array_literal_2d_indexed_list_head = 214, /* simple_array_literal_2d_indexed_list_head  */
  YYSYMBOL_simple_array_literal_2d_indexed_list_row = 215, /* simple_array_literal_2d_indexed_list_row  */
  YYSYMBOL_simple_array_literal_2d_indexed_list_row_head = 216, /* simple_array_literal_2d_indexed_list_row_head  */
  YYSYMBOL_simple_array_comp = 217,        /* simple_array_comp  */
  YYSYMBOL_comp_expr = 218,                /* comp_expr  */
  YYSYMBOL_comp_expr_atom_head = 219,      /* comp_expr_atom_head  */
  YYSYMBOL_comp_expr_atom_head_nonstring = 220, /* comp_expr_atom_head_nonstring  */
  YYSYMBOL_comp_expr_list = 221,           /* comp_expr_list  */
  YYSYMBOL_comp_expr_list_head = 222,      /* comp_expr_list_head  */
  YYSYMBOL_if_then_else_expr = 223,        /* if_then_else_expr  */
  YYSYMBOL_elseif_list = 224,              /* elseif_list  */
  YYSYMBOL_quoted_op = 225,                /* quoted_op  */
  YYSYMBOL_quoted_op_call = 226,           /* quoted_op_call  */
  YYSYMBOL_call_expr = 227,                /* call_expr  */
  YYSYMBOL_comp_or_expr = 228,             /* comp_or_expr  */
  YYSYMBOL_comp_or_expr_head = 229,        /* comp_or_expr_head  */
  YYSYMBOL_let_expr = 230,                 /* let_expr  */
  YYSYMBOL_let_vardecl_item_list = 231,    /* let_vardecl_item_list  */
  YYSYMBOL_comma_or_semi = 232,            /* comma_or_semi  */
  YYSYMBOL_let_vardecl_item = 233,         /* let_vardecl_item  */
  YYSYMBOL_annotations = 234,              /* annotations  */
  YYSYMBOL_annotation_expr = 235,          /* annotation_expr  */
  YYSYMBOL_ne_annotations = 236,           /* ne_annotations  */
  YYSYMBOL_id_or_quoted_op = 237           /* id_or_quoted_op  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  208
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  151
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  500
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  859

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   397


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     146,   147,     2,     2,   148,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   149,   143,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   144,   150,   145,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   309,   309,   311,   313,   316,   325,   334,   343,   352,
     354,   357,   365,   374,   374,   376,   392,   396,   398,   400,
     401,   403,   405,   407,   409,   411,   414,   414,   414,   415,
     415,   415,   415,   415,   416,   419,   442,   446,   451,   461,
     479,   495,   499,   508,   513,   522,   523,   527,   535,   536,
     540,   544,   550,   552,   559,   564,   569,   576,   578,   587,
     598,   609,   620,   633,   643,   655,   668,   678,   679,   689,
     690,   695,   696,   698,   703,   704,   708,   712,   717,   717,
     718,   718,   721,   723,   727,   737,   741,   743,   747,   748,
     754,   763,   766,   774,   782,   791,   799,   808,   817,   827,
     834,   835,   839,   841,   843,   845,   847,   849,   851,   856,
     862,   865,   867,   871,   873,   875,   884,   895,   898,   900,
     906,   907,   909,   911,   913,   915,   924,   926,   928,   930,
     932,   934,   936,   945,   947,   949,   951,   953,   955,   957,
     959,   961,   963,   968,   973,   978,   983,   988,   993,   998,
    1004,  1010,  1012,  1025,  1026,  1028,  1030,  1032,  1034,  1036,
    1038,  1040,  1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1073,  1075,  1077,  1079,  1081,  1083,
    1085,  1094,  1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,
    1112,  1117,  1122,  1127,  1132,  1137,  1142,  1147,  1152,  1158,
    1160,  1167,  1179,  1181,  1185,  1187,  1189,  1191,  1193,  1195,
    1198,  1200,  1203,  1205,  1208,  1210,  1213,  1215,  1217,  1219,
    1221,  1223,  1225,  1227,  1229,  1231,  1233,  1234,  1237,  1239,
    1242,  1243,  1246,  1248,  1251,  1252,  1255,  1257,  1260,  1261,
    1264,  1266,  1269,  1270,  1273,  1275,  1278,  1279,  1282,  1284,
    1287,  1288,  1289,  1292,  1293,  1298,  1300,  1306,  1311,  1319,
    1326,  1335,  1337,  1342,  1348,  1351,  1354,  1356,  1358,  1364,
    1366,  1368,  1376,  1378,  1381,  1384,  1387,  1389,  1393,  1395,
    1407,  1409,  1470,  1510,  1513,  1518,  1525,  1530,  1533,  1536,
    1546,  1558,  1569,  1572,  1576,  1587,  1599,  1615,  1623,  1624,
    1626,  1628,  1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,
    1646,  1648,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1692,  1694,  1696,  1698,
    1700,  1702,  1704,  1706,  1708,  1710,  1717,  1724,  1731,  1738,
    1745,  1752,  1759,  1766,  1774,  1776,  1783,  1795,  1797,  1801,
    1811,  1819,  1828,  1838,  1840,  1843,  1845,  1848,  1850,  1853,
    1855,  1858,  1860,  1862,  1864,  1866,  1868,  1870,  1872,  1874,
    1876,  1878,  1879,  1882,  1884,  1887,  1888,  1891,  1893,  1896,
    1897,  1900,  1902,  1905,  1906,  1909,  1911,  1914,  1915,  1918,
    1920,  1923,  1924,  1927,  1929,  1932,  1933,  1934,  1937,  1938,
    1942,  1946,  1949,  1953,  1962,  1977,  1984,  2000,  2001,  2005,
    2007,  2009,  2011,  2013,  2015,  2017,  2019,  2021,  2023,  2025,
    2027,  2029,  2031,  2033,  2035,  2037,  2039,  2041,  2043,  2045,
    2047,  2049,  2051,  2053,  2055,  2057,  2059,  2063,  2071,  2103,
    2105,  2107,  2108,  2128,  2182,  2202,  2257,  2260,  2266,  2272,
    2274,  2278,  2285,  2294,  2296,  2304,  2306,  2315,  2315,  2318,
    2322,  2331,  2332,  2335,  2337,  2341,  2345,  2349,  2351,  2353,
    2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,  2373,
    2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,  2393,
    2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,  2413,
    2415
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"integer literal\"",
  "\"bool literal\"", "\"float literal\"", "\"identifier\"",
  "\"quoted identifier\"", "\"string literal\"",
  "\"interpolated string start\"", "\"interpolated string middle\"",
  "\"interpolated string end\"", "\"type-inst identifier\"",
  "\"type-inst enum identifier\"", "\"documentation comment\"",
  "\"file-level documentation comment\"", "\"var\"", "\"par\"", "\"<>\"",
  "\"ann\"", "\"annotation\"", "\"any\"", "\"array\"", "\"bool\"",
  "\"case\"", "\"constraint\"", "\"default\"", "\"else\"", "\"elseif\"",
  "\"endif\"", "\"enum\"", "\"float\"", "\"function\"", "\"if\"",
  "\"include\"", "\"infinity\"", "\"int\"", "\"let\"", "\"list\"",
  "\"maximize\"", "\"minimize\"", "\"of\"", "\"opt\"", "\"satisfy\"",
  "\"output\"", "\"predicate\"", "\"record\"", "\"set\"", "\"solve\"",
  "\"string\"", "\"test\"", "\"then\"", "\"tuple\"", "\"type\"", "\"_\"",
  "\"variant_record\"", "\"where\"", "\"[\"", "\"[|\"", "\"]\"", "\"|]\"",
  "QUOTED_IDENTIFIER", "\"invalid integer literal\"",
  "\"invalid float literal\"", "\"unterminated string\"",
  "\"end of line inside string literal\"", "\"null character\"",
  "\"invalid string literal\"", "\"<->\"", "\"->\"", "\"<-\"", "\"\\\\/\"",
  "\"xor\"", "\"/\\\\\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"=\"",
  "\"!=\"", "\"~=\"", "\"~!=\"", "\"in\"", "\"subset\"", "\"superset\"",
  "\"union\"", "\"diff\"", "\"symdiff\"", "\"..\"", "\"..<\"", "\"<..\"",
  "\"<..<\"", "\"+\"", "\"-\"", "\"~+\"", "\"~-\"", "\"*\"", "\"/\"",
  "\"div\"", "\"mod\"", "\"~/\"", "\"~div\"", "\"intersect\"", "\"~*\"",
  "\"^\"", "\"^-1\"", "\"not\"", "\"++\"", "\"::\"", "PREC_ANNO",
  "\"'<->'\"", "\"'->'\"", "\"'<-'\"", "\"'\\\\/'\"", "\"'xor'\"",
  "\"'/\\\\'\"", "\"'<'\"", "\"'>'\"", "\"'<='\"", "\"'>='\"", "\"'='\"",
  "\"'!='\"", "\"'in'\"", "\"'subset'\"", "\"'superset'\"", "\"'union'\"",
  "\"'diff'\"", "\"'symdiff'\"", "\"'..'\"", "\"'<..'\"", "\"'..<'\"",
  "\"'<..<'\"", "\"'+'\"", "\"'-'\"", "\"'*'\"", "\"'/'\"", "\"'div'\"",
  "\"'mod'\"", "\"'intersect'\"", "\"'^'\"", "\"'not'\"", "\"'::'\"",
  "\"'++'\"", "';'", "'{'", "'}'", "'('", "')'", "','", "':'", "'|'",
  "$accept", "model", "item_list", "item_list_head", "doc_file_comments",
  "semi_or_none", "item", "item_tail", "error_item_start", "include_item",
  "vardecl_item", "enum_init", "enum_construct", "string_lit_list",
  "enum_id_list", "assign_item", "constraint_item", "solve_item",
  "output_item", "predicate_item", "function_item", "annotation_item",
  "ann_param", "operation_item_tail", "params", "params_list",
  "params_list_head", "comma_or_none", "pipe_or_none",
  "ti_expr_and_id_or_anon", "ti_expr_and_id", "ti_expr_list",
  "ti_expr_list_head", "ti_expr", "base_ti_expr", "opt_opt",
  "base_ti_expr_tail", "array_access_expr_list",
  "array_access_expr_list_head", "array_access_expr", "expr_list",
  "expr_list_head", "set_expr", "expr", "expr_atom_head",
  "expr_atom_head_nonstring", "string_expr", "string_quote_rest",
  "array_access_tail", "set_literal", "set_comp", "comp_tail",
  "generator_list", "generator_list_head", "generator", "generator_eq",
  "id_list", "id_list_head", "simple_array_literal",
  "simple_array_literal_2d", "simple_array_literal_3d_list",
  "simple_array_literal_2d_list", "simple_array_literal_2d_indexed_list",
  "simple_array_literal_2d_indexed_list_head",
  "simple_array_literal_2d_indexed_list_row",
  "simple_array_literal_2d_indexed_list_row_head", "simple_array_comp",
  "comp_expr", "comp_expr_atom_head", "comp_expr_atom_head_nonstring",
  "comp_expr_list", "comp_expr_list_head", "if_then_else_expr",
  "elseif_list", "quoted_op", "quoted_op_call", "call_expr",
  "comp_or_expr", "comp_or_expr_head", "let_expr", "let_vardecl_item_list",
  "comma_or_semi", "let_vardecl_item", "annotations", "annotation_expr",
  "ne_annotations", "id_or_quoted_op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,    59,   123,   125,    40,    41,    44,    58,
     124
};
#endif

#define YYPACT_NINF (-730)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1131,  -134,   -65,   -59,   -38,    -8,  -730,  4158,  -730,  -730,
    2142,  -730,    38,    38,     8,  -730,    67,    73,    29,  -730,
    3438,   106,  -730,  2574,  4158,   150,    62,  -730,    25,   136,
    2862,  3582,   162,   152,    64,  -730,   179,   -47,  3726,   774,
    4302,  4302,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,
      49,    53,    91,    94,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,  -730,  -730,  -730,  3870,  4158,   239,  -730,    99,  1710,
     468,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,   166,    96,  -730,  -730,  4658,  -730,  -730,  -730,   -18,
      -7,     4,    12,    59,    75,   105,  -730,    86,  -730,  1998,
    -730,  -730,  -730,  4014,  4158,   108,  1420,    87,   -24,  4158,
    4158,  4158,   109,   110,   113,   114,    15,  7667,  -730,  -730,
    -730,  -730,  3006,  3150,  -730,   115,  -730,  2574,    43,  7667,
      64,    97,  7038,  -730,  -730,  2430,  2718,   221,  -730,    43,
    7667,   -58,  3294,   966,   135,   160,   -57,  -730,    89,   219,
     220,   222,   -13,   224,   225,    93,  -730,  4158,  4158,  4158,
     180,   186,   187,   188,  4158,  -730,   100,   127,   129,   130,
     131,  4381,  -730,  -730,   276,   192,   133,   143,  -730,  -730,
     925,  7667,   -46,   281,   193,  -730,   -86,    16,    16,  4158,
    4302,  4302,  4302,  -730,   191,   194,  4479,  5844,  -730,  1854,
    -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,  -730,  -730,  4158,   339,  4302,  4302,  4302,  4302,  4302,
    4302,  4302,  4302,  4302,  4302,  4302,  4302,  4302,  4302,  4302,
    4302,  4302,  4302,  4302,  4302,  4302,  4302,  4302,  4302,  4302,
     966,  -730,   144,  -730,   145,  -730,   147,  -730,   210,  -730,
     257,  -730,   260,  4158,  -730,   261,  -730,  4158,   287,   199,
    -730,  7765,  7667,  1565,  -730,  7136,   201,   202,  4014,  -730,
      34,    34,    34,  4158,  4158,  4158,  4158,  4158,  -730,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
     966,   308,  -730,   310,  -730,  1275,   275,   295,   207,  -730,
    4158,   278,  1224,  4158,  -730,   283,   214,    28,  -730,  -730,
    3294,  4158,   115,   348,  -730,  -730,  -730,  -730,  4158,  4158,
    -730,   966,   115,   348,  -730,  -730,  -730,  -730,   108,   264,
    -730,  -730,  -730,   265,    34,    34,    34,  4158,  4158,  4158,
    4158,   217,  -730,   361,  -730,   362,  -730,   363,  -730,   364,
    -730,   365,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,  4158,
    4158,  4158,   966,  4158,   428,  -730,  4158,  -730,  -730,   367,
    -730,   368,  -730,  -730,   273,  -730,   300,  -730,  4158,  -730,
    4158,  4158,  -730,  4814,  5623,  5721,  5746,  -730,  4158,  -730,
     428,   372,  1710,  -730,  7667,   -80,   329,     6,  7078,  7078,
    1102,  1102,  1102,  4836,  4836,  4836,  4836,   345,   345,   345,
     345,    11,    11,    11,    11,    11,    11,  1102,    11,    16,
      17,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  4716,  -730,
    7667,  -730,  4014,  -730,  4158,  -730,   304,  4158,   309,  4158,
    -730,   395,  4912,  5010,  5108,  5206,  -730,  7667,   351,    31,
    7805,  7903,  7903,  7939,  7939,   761,  8037,  8037,  8037,  8037,
    8037,  8037,  8037,  8037,  8064,  8064,  8064,  4934,  4934,  4934,
    5032,  5032,  5032,  5032,   503,   503,   503,   503,    27,    27,
      27,    27,    27,    27,  4934,    27,    34,    58,  -730,  3294,
    3294,   313,   314,   315,  -730,  -730,   214,  4158,   415,  2574,
    -730,  7667,    26,   357,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,  -730,
    -730,  -730,  -730,  -730,  -730,  -730,   115,  7234,  4158,   458,
    -730,   383,  -730,  2286,  -730,  7667,   348,   326,    64,  7667,
    7667,  -730,   348,    64,  -730,  -730,  5304,  5402,  5500,  5598,
     375,  -730,  -730,  -730,  -730,  -730,   351,    31,  7805,  7903,
    7903,  7939,  7939,   761,  8037,  8037,  8037,  8037,  8037,  8037,
    8037,  8037,  8064,  8064,  8064,  4934,  4934,  4934,  5032,  5032,
    5032,  5032,   503,   503,   503,   503,    27,    27,    27,    27,
      27,    27,  4934,    27,    34,    58,  -730,  4520,   398,   419,
    -730,   331,  -730,   430,   408,   343,  4618,  -730,  -730,  4158,
    4158,  -730,   -77,  7667,  7667,  4158,  4302,  4302,  4302,   347,
    -730,   376,  -730,  2574,  -730,  -730,  4158,  -730,   349,  7667,
    4158,  7332,  -730,  4158,  4158,  4158,  4158,  -730,  -730,  -730,
    -730,  2574,  -730,  7667,  2718,  -730,   353,   486,   491,   394,
    -730,  -730,   348,  -730,    63,  7667,    64,  4158,   421,  -730,
    -730,    64,   498,   427,    64,   427,  4158,  4158,  4158,  4158,
    -730,   378,   428,  4158,  -730,   428,  -730,  4158,  4158,   500,
    -730,  4158,  -730,   358,  4158,  5885,  6817,  6842,  6940,  -730,
    -730,   360,  5983,  4158,  6024,  4158,  6122,  6163,  6261,  6302,
    -730,  -730,  4158,  -730,   -42,  -730,   -41,    21,    64,  4158,
    4158,  7667,  4158,   427,  -730,  4158,  -730,   427,  -730,  6400,
    6441,  6539,  6580,  -730,   450,  7667,  -730,   459,  7667,  7430,
    -730,  7667,  4158,  -730,  -730,  -730,  -730,   348,  -730,  6678,
    -730,  7667,  -730,  -730,  -730,  -730,  6719,  -730,   506,  -730,
     511,  -730,   427,  7528,  7626,  7667,  -730,  7667,  -730,  -730,
    -730,  -730,  -730,  -730,  4158,  4158,    64,  -730,  -730,  -730,
    -730,  -730,  -730,  4158,  7667,  7667,   427,  7667,  -730
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,   218,   216,   222,   208,   255,     0,   108,   109,
       0,    11,   100,   100,   224,   106,     0,     0,     0,   103,
       0,     0,   104,     0,     0,     0,   220,   102,     0,     0,
       0,     0,     0,     0,   461,   105,     0,   212,     0,     0,
       0,     0,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
       0,     0,     0,     0,   427,   428,   429,   431,   432,   433,
     434,   430,   436,   435,     0,     0,     0,     2,    13,     0,
       5,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    36,     0,    88,    91,   107,   120,   202,   203,   226,
     230,   234,   238,   242,   246,     0,   441,   251,   250,     0,
     219,   217,   223,     0,     0,   210,     0,   209,   208,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   153,   256,
      15,   101,     0,     0,   225,    71,    99,     0,     0,    52,
     461,     0,     0,    35,   221,     0,     0,     0,    92,     0,
      57,    71,     0,     0,     0,   462,    71,   214,   213,   363,
     361,   367,   353,   369,   365,   357,   278,     0,     0,     0,
       0,     0,     0,     0,     0,   348,   371,   375,   379,   383,
     387,   401,   298,   347,     0,    78,   391,   396,   395,   280,
       0,   293,     0,     0,    80,   289,    78,   151,   152,     0,
       0,     0,     0,   261,     0,    78,   118,     0,     1,    14,
       4,    12,     6,    34,    29,    27,    32,    26,    28,    31,
      30,    33,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,   227,   232,   231,   236,   235,   240,   239,   244,
     243,   248,   247,     0,   253,   252,    10,   114,     0,    78,
     111,   113,    51,     0,   439,   447,     0,    78,     0,   211,
     200,   201,   199,     0,     0,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,    93,     0,    65,     0,    78,    86,
       0,    38,     0,     0,   454,   459,     0,     0,   453,    90,
       0,     0,    71,    67,    95,   463,   464,   465,     0,     0,
      54,     0,    71,    67,   215,   364,   362,   368,   355,   354,
     370,   366,   359,   358,   345,   346,   344,     0,     0,     0,
       0,     0,   373,   372,   377,   376,   381,   380,   385,   384,
     389,   388,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,    79,   400,   393,   392,
     398,   397,   283,   286,     0,   282,     0,   281,    81,   288,
      79,   290,   292,     0,     0,     0,     0,   262,    79,   117,
       0,   204,     0,     7,    37,   461,   150,   149,   147,   148,
     122,   123,   124,   125,   126,   127,   128,   135,   136,   142,
     143,   137,   138,   139,   140,   145,   146,   133,   144,   141,
     134,   121,   229,   233,   237,   241,   245,   249,     0,   254,
     115,   259,    79,   110,   116,   440,     0,     0,   442,    79,
     446,     0,     0,     0,     0,     0,   258,   119,   198,   197,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   195,   196,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   183,   184,   190,   191,   185,   186,
     187,   188,   193,   194,   181,   192,   189,   182,   154,     0,
       0,     0,     0,    78,    76,    82,    83,     0,     0,    79,
      85,    53,     0,   467,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   495,
     496,   497,   498,   494,   499,   500,    71,   407,     0,     0,
     458,     0,   457,     0,    96,    58,    67,     0,   461,    56,
      55,   466,    67,   461,   356,   360,     0,     0,     0,     0,
     349,   374,   378,   382,   386,   390,   343,   342,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     340,   341,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   328,   329,   335,   336,   330,   331,   332,   333,
     338,   339,   326,   337,   334,   327,   299,   402,   276,     0,
     264,    78,   266,   267,     0,    78,   403,   394,   399,   284,
       0,   291,    78,   295,   294,     0,     0,     0,     0,     0,
     206,   205,     8,    74,    84,   438,     0,   112,   444,   448,
       0,   449,   260,     0,     0,     0,     0,    98,    97,    73,
      72,    79,    75,    66,     0,    87,     0,    45,    48,    39,
      41,   468,    67,   405,     0,   460,   461,     0,     0,   456,
     455,   461,     0,    69,   461,    69,     0,     0,     0,     0,
     351,   350,     0,     0,   297,    79,   265,     0,     0,    79,
     275,     0,   287,     0,     0,     0,     0,     0,     0,   263,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    89,     0,    46,     0,    49,     0,     0,   461,     0,
       0,   451,     0,    69,    68,     0,    59,    69,    60,     0,
       0,     0,     0,   352,     0,   274,   269,   270,   268,   272,
     277,   404,   285,   132,   130,   129,   131,    67,   437,     0,
     443,   450,   180,   178,   177,   179,     0,    40,     0,    43,
       0,    42,    69,     0,     0,   452,    61,    70,    62,   325,
     323,   322,   324,   296,     0,     0,   461,   445,    44,    47,
      50,    63,   406,     0,   271,   273,    69,   408,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -730,  -730,  -730,  -730,   311,  -730,   -50,   509,  -730,  -730,
    -730,  -730,  -266,  -730,  -730,  -730,  -142,  -730,  -730,  -730,
    -730,  -730,  -306,  -729,  -121,  -181,  -730,  -149,  -730,  -198,
    -139,  -730,  -730,   -16,  -145,   512,   -22,   246,  -730,    32,
     -69,    24,   -19,   -20,   417,   -17,     7,   240,   -25,   490,
     492,  -440,  -730,  -730,  -224,  -222,  -730,  -730,   497,   501,
    -730,  -150,  -730,  -730,    95,    98,   504,  -730,  -730,  -730,
    -730,  -730,   507,  -730,  -730,  -730,   510,   268,  -730,   513,
    -730,  -730,   -61,   -32,  -235,  -730,  -730
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    76,    77,    78,    79,   210,    80,    81,   222,    82,
      83,   729,   730,   784,   786,    84,    85,    86,    87,    88,
      89,    90,   618,   796,   336,   562,   563,   452,   449,   564,
      91,   337,   338,    92,    93,   132,    94,   268,   269,   270,
     443,   205,    95,   127,   128,    97,    98,   129,   117,    99,
     100,   679,   680,   681,   682,   683,   684,   685,   101,   102,
     192,   444,   193,   194,   195,   196,   103,   181,   182,   183,
     184,   185,   104,   734,   105,   106,   107,   276,   277,   108,
     347,   613,   348,   704,   357,   155,   606
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     139,   349,   154,   344,   142,   204,   345,   141,   148,   109,
     113,   150,   158,   225,   445,   491,   798,   827,   225,   191,
     699,   197,   198,   225,   225,   287,   288,   726,   153,   212,
     353,   126,   726,   113,   290,   363,   437,   226,   290,   113,
     110,   290,   226,   226,   113,   175,   111,   352,   362,   113,
     113,     6,     7,   291,   206,   207,   459,   623,   157,   266,
     291,   113,   450,   451,   836,   290,   703,   112,   838,   113,
     114,   450,   764,   135,   252,   254,   256,   258,   260,   262,
     131,   115,   265,   727,   291,   136,   137,   251,   335,   335,
     789,   790,   368,   271,   272,   558,   275,   115,   253,   280,
     281,   282,   446,   851,   829,   381,   828,   830,   341,   255,
     332,   334,   140,   134,   250,   248,   113,   257,   249,   250,
     503,   339,   116,   249,   250,   250,   621,   858,   510,   346,
     354,   328,   113,   116,   329,   330,   355,   369,   116,   330,
     373,   329,   330,   113,   278,   340,   278,   374,   375,   376,
     113,   383,   385,   387,   389,   391,   351,   113,   143,   463,
     356,   439,   441,   289,   259,   728,   330,   144,   151,   145,
     728,   610,   153,   611,   358,   359,   612,   146,   360,   453,
     261,   454,   455,   456,   113,   156,   113,   113,   113,   570,
     113,   264,   279,   152,   364,   199,   565,   676,   372,   200,
     113,   278,   278,   464,   278,   382,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   616,   384,   355,   386,   388,   390,   201,   438,   208,
     202,   622,   209,   498,   223,   224,   342,   500,   440,   492,
     493,   263,   494,   275,   273,   283,   284,   356,   271,   285,
     286,   335,   350,   512,   513,   514,   515,   278,   361,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     741,   126,   804,   355,   278,   495,   744,   278,   278,   566,
     571,   278,   278,   607,   365,   366,   377,   367,   614,   370,
     371,   615,   378,   379,   380,   435,   457,   356,   619,   620,
     436,   447,   458,   448,   355,   465,   501,   502,   508,   559,
     509,   560,   225,   567,   568,   569,   572,   626,   627,   628,
     629,   608,   496,   609,   630,   497,   499,   617,   356,   624,
     625,   226,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   702,   677,   722,   355,   686,    96,   278,   278,
     278,   278,   278,   689,   278,   278,   788,    96,   191,   113,
     693,   694,   113,   278,   678,   278,   701,   250,   517,   356,
      96,   240,   241,   242,   243,   244,   245,    96,   247,   248,
     690,   708,   249,   250,   712,   710,   724,    96,    96,   330,
     719,   720,   731,   721,   736,   737,   631,   632,   633,   634,
     635,   739,   687,   688,   345,   742,   753,   700,   754,   755,
     750,   770,   271,   803,   540,   732,   757,   709,   213,   711,
     758,   759,   769,   214,   783,   773,    96,   785,   215,   782,
     216,   787,   217,   792,   794,   795,   810,   817,   812,   843,
     290,   846,   218,   219,   849,   844,   220,   850,   221,   130,
     462,   831,   771,   780,   511,   133,    96,   516,   176,   291,
     177,   806,   756,   807,   707,   178,   760,   717,   718,   179,
     763,   506,   180,   691,     0,   186,   692,   723,   187,    96,
      96,   188,   740,   725,    96,     0,     0,     0,     0,     0,
       0,     0,    96,    96,   565,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   781,
       0,     0,   565,     0,     0,     0,   743,     0,   735,     0,
       0,   745,     0,     0,     0,     0,     0,   346,     0,   320,
     321,   322,   323,   324,   325,   751,   327,   328,     0,     0,
     329,   330,     0,     0,     0,     0,     0,    96,    96,    96,
     762,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,     0,     0,     0,
       0,     0,     0,     0,     0,   765,     0,   766,   767,   768,
       0,     0,     0,     0,     0,     0,   772,   566,     0,     0,
     774,     0,     0,   776,   777,   778,   779,     0,     0,     0,
       0,     0,     0,     0,     0,   566,     0,     0,     0,   793,
       0,     0,   797,     0,     0,     0,     0,   791,     0,     0,
       0,     0,     0,     0,     0,     0,   799,   800,   801,   802,
       0,     0,     0,   805,     0,     0,     0,   808,   809,     0,
       0,   811,     0,   762,   694,     0,     0,     0,     0,     0,
       0,     0,    96,   819,     0,   821,   832,     0,     0,     0,
       0,     0,   826,     0,     0,     0,     0,    96,   290,   833,
     834,     0,   835,     0,     0,   837,     0,     2,     3,     4,
     118,     0,     6,     7,     0,     0,     0,   291,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,    26,
       0,    28,     0,     0,   856,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   854,   855,     0,     0,    37,     0,
       0,    38,    39,   857,   189,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   119,   120,   329,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
     121,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   122,   123,   124,   125,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    74,     0,
      75,     0,     0,     0,   190,     0,     0,     0,     2,     3,
       4,   118,     0,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      26,     0,    28,     0,     0,     0,     0,     0,     0,     2,
       3,     4,   118,     0,     6,     7,    96,    96,     0,    37,
       0,     0,    38,    39,    14,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,    26,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   120,     0,
      37,     0,     0,    38,    39,     0,     0,     0,     0,     0,
      96,   121,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   122,   123,   124,   125,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    73,     0,    74,
       0,    75,     0,     0,     0,   442,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,   225,
      74,     0,    75,    96,    96,    96,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,    -3,     1,     0,     2,     3,     4,     5,    96,     6,
       7,    96,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,    30,     0,    31,    32,     0,    33,    34,
      35,    36,     0,     0,     0,    37,     0,     0,    38,    39,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   247,   248,     0,     0,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,    73,     0,    74,   561,    75,     2,     3,
       4,   118,     0,     6,     7,     0,     0,     8,     9,     0,
       0,    12,    13,    14,    15,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,    22,     0,    24,     0,
      26,    27,    28,    29,     0,     0,     0,    30,     0,     0,
       0,     0,    33,     0,    35,     0,     0,     0,     0,    37,
       0,     0,    38,    39,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,     0,   605,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    73,     0,    74,
       0,    75,   -74,     2,     3,     4,   118,     0,     6,     7,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    26,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   122,   123,
     124,   125,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,     0,    74,     0,    75,   274,     2,     3,
       4,   118,     0,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      26,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,    38,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   122,   123,   124,   125,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    73,     0,    74,
       0,    75,   505,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     8,     9,    10,   211,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,    30,     0,    31,    32,     0,    33,    34,    35,
      36,     0,     0,     0,    37,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,     0,    74,     0,    75,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,    30,     0,    31,    32,
       0,    33,    34,    35,    36,     0,     0,     0,    37,     0,
       0,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    74,     0,
      75,     2,     3,     4,     5,     0,     6,     7,     0,     0,
       8,     9,    10,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
      30,     0,    31,    32,     0,    33,    34,    35,    36,     0,
       0,     0,    37,     0,     0,    38,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,     0,    74,     0,    75,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     8,     9,     0,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,    30,     0,    31,    32,     0,    33,
      34,    35,    36,     0,     0,     0,    37,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,     0,    75,     2,
       3,     4,   118,     0,     6,     7,     0,     0,     8,     9,
       0,     0,    12,    13,    14,    15,     0,    17,    18,    19,
       0,    20,     0,     0,     0,     0,     0,    22,     0,    24,
       0,    26,    27,    28,    29,     0,     0,     0,    30,     0,
       0,     0,     0,    33,     0,    35,     0,     0,     0,     0,
      37,     0,     0,    38,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
      74,   738,    75,     2,     3,     4,   118,     0,     6,     7,
       0,     0,     8,     9,     0,     0,    12,    13,    14,    15,
       0,    17,    18,    19,     0,    20,     0,     0,     0,     0,
       0,    22,     0,    24,     0,    26,    27,    28,    29,     0,
       0,     0,    30,     0,     0,     0,     0,    33,     0,    35,
       0,     0,     0,     0,    37,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,     0,    74,     0,    75,     2,     3,     4,
     118,     0,     6,     7,     0,     0,     8,     9,     0,     0,
      12,    13,    14,    15,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,    22,     0,    24,     0,    26,
      27,    28,    29,     0,     0,     0,    30,     0,     0,     0,
       0,    33,     0,    35,     0,     0,     0,     0,    37,     0,
       0,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    74,     0,
      75,     2,     3,     4,   118,     0,     6,     7,     0,     0,
       8,     9,     0,     0,    12,    13,    14,    15,     0,    17,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    24,     0,    26,    27,    28,     0,     0,     0,     0,
      30,     0,     0,     0,     0,    33,     0,    35,     0,     0,
       0,     0,    37,     0,     0,    38,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,     0,    74,     0,    75,     2,     3,     4,   118,     0,
       6,     7,     0,     0,     8,     9,     0,     0,     0,     0,
      14,    15,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    24,     0,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,    35,     0,     0,     0,     0,    37,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,     0,    75,     2,
       3,     4,   118,     0,     6,     7,     0,     0,     8,     9,
       0,     0,     0,     0,    14,    15,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    22,     0,    24,
       0,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,     0,    35,     0,     0,     0,     0,
      37,     0,     0,    38,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
      74,     0,    75,     2,     3,     4,   118,     0,     6,     7,
       0,     0,     8,     9,     0,     0,     0,     0,    14,    15,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    24,     0,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,     0,    35,
       0,     0,     0,     0,    37,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,     0,    74,     0,    75,     2,     3,     4,
     118,     0,     6,     7,     0,     0,     8,     9,     0,     0,
       0,     0,    14,    15,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    22,     0,    24,     0,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,    37,     0,
       0,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    74,     0,
      75,     2,     3,     4,   118,     0,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,    26,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,    38,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,   138,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   122,   123,   124,   125,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,     0,    74,     0,    75,     2,     3,     4,   118,     0,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,    26,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
     149,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     122,   123,   124,   125,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,     0,    75,   159,
     160,   161,   162,     0,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,   164,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,    38,    39,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   170,   171,   172,   173,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
      74,     0,   174,     2,     3,     4,   118,     0,     6,     7,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    26,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   122,   123,
     124,   125,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,     0,    74,   203,    75,     2,     3,     4,
     118,     0,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,    26,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,     0,     0,     0,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   122,   123,   124,   125,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    73,     0,    74,     0,
      75,     2,     3,     4,   118,     0,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,    26,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,    38,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   122,   123,   124,   125,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
      73,     0,    74,     0,    75,     2,     3,     4,   118,     0,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,    26,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   392,     0,
       0,     0,     0,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   393,     0,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,     0,    75,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   290,     0,   431,   432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,     0,     0,
     433,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,   329,   330,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   290,     0,   329,   330,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,     0,     0,     0,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   290,     0,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
       0,     0,   291,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,   249,   250,   761,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   290,     0,   329,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   705,   706,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   290,
       0,   329,   330,     0,   -75,   -75,   -75,   -75,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   291,   247,
     248,   290,     0,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,   695,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   290,     0,   329,
     330,     0,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   291,   327,   328,   290,
       0,   329,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
     713,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   290,     0,   329,   330,     0,
     -75,   -75,   -75,   -75,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   291,   327,   328,     0,     0,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   290,     0,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   715,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   290,     0,   329,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   716,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   290,
       0,   329,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   746,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   290,     0,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     747,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   290,     0,   329,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   748,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   227,   228,   329,   330,     0,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   225,     0,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   749,   226,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   696,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,     0,     0,     0,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   227,   228,   249,   250,
       0,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   290,     0,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   697,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,   698,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,   329,   330,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     290,   461,   329,   330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   813,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
     329,   330,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   290,
     818,   329,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   820,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,     0,     0,   329,
     330,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   290,   822,
     329,   330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     823,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,     0,     0,   329,   330,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   290,   824,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   825,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,     0,     0,   329,   330,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   290,   839,   329,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,     0,     0,   329,   330,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   290,   841,   329,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   842,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,     0,     0,   329,   330,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   225,   847,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   848,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,     0,
       0,     0,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   227,   228,   249,   250,     0,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   225,     0,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   814,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   815,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,     0,     0,     0,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   290,     0,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,     0,   816,     0,   343,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   290,     0,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -75,   -75,
       0,     0,   291,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,   249,   250,     0,     0,     0,
       0,     0,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   290,     0,   329,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   290,
       0,   329,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   290,     0,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   845,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   290,     0,   329,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,   852,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   290,     0,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,     0,     0,   853,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,     0,     0,   329,   330,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   290,     0,   329,   330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   504,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
       0,     0,   329,   330,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     290,     0,   329,   330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
     329,   330,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   290,     0,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,     0,     0,     0,     0,     0,     0,
       0,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,     0,     0,   329,   330,   -75,   -75,   -75,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,     0,
       0,   329,   330
};

static const yytype_int16 yycheck[] =
{
      20,   146,    34,   145,    24,    74,   145,    23,    30,   143,
      57,    31,    37,     7,    60,   250,   745,    59,     7,    39,
     460,    40,    41,     7,     7,    10,    11,     6,   108,    79,
     151,     7,     6,    57,     7,   156,   185,    26,     7,    57,
     105,     7,    26,    26,    57,    38,   105,   105,   105,    57,
      57,     8,     9,    26,    74,    75,   205,   363,   105,   109,
      26,    57,   148,   149,   793,     7,   146,   105,   797,    57,
      78,   148,   149,     6,    99,   100,   101,   102,   103,   104,
      42,   105,   107,    57,    26,    12,    57,   105,   146,   146,
      27,    28,   105,   113,   114,   330,   116,   105,   105,   119,
     120,   121,   148,   832,   145,   174,   148,   148,   140,   105,
     132,   133,     6,   105,   108,   104,    57,   105,   107,   108,
     269,   137,   146,   107,   108,   108,   361,   856,   277,   145,
     152,   104,    57,   146,   107,   108,   153,   162,   146,   108,
     165,   107,   108,    57,    57,   138,    57,   167,   168,   169,
      57,   176,   177,   178,   179,   180,   149,    57,     8,   209,
     153,   186,   187,   148,   105,   144,   108,   105,     6,   144,
     144,   143,   108,   145,    39,    40,   148,    41,    43,   199,
     105,   200,   201,   202,    57,     6,    57,    57,    57,   338,
      57,   105,   105,    41,   105,   146,   335,   432,   105,   146,
      57,    57,    57,   223,    57,   105,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   352,   105,   250,   105,   105,   105,   146,   105,     0,
     146,   362,   143,   263,    78,   149,   149,   267,   105,   105,
     105,   146,   105,   273,   146,   146,   146,   250,   278,   146,
     146,   146,    41,   283,   284,   285,   286,    57,   108,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     616,   287,   752,   330,    57,   105,   622,    57,    57,   335,
     340,    57,    57,   343,   105,   105,   146,   105,   350,   105,
     105,   351,   146,   146,   146,    59,   145,   330,   358,   359,
     148,    60,   148,   150,   361,     6,    59,   148,   147,    41,
     148,    41,     7,    78,    59,   148,    78,   377,   378,   379,
     380,    78,   105,   149,   147,   105,   105,    19,   361,   105,
     105,    26,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   462,   433,   563,   432,   436,     0,    57,    57,
      57,    57,    57,   150,    57,    57,   732,    10,   448,    57,
     450,   451,    57,    57,     6,    57,   461,   108,   458,   432,
      23,    96,    97,    98,    99,   100,   101,    30,   103,   104,
     150,   147,   107,   108,    59,   146,    41,    40,    41,   108,
     147,   147,   105,   148,     6,    82,   105,   105,   105,   105,
     105,   613,   105,   105,   613,   149,    78,   105,    59,   148,
     105,   105,   502,   105,   504,   606,    56,   507,    20,   509,
      82,   148,   145,    25,     8,   146,    79,     6,    30,   146,
      32,   107,    34,    82,     6,    78,     6,   147,   150,    59,
       7,   817,    44,    45,     8,    56,    48,     6,    50,    10,
     209,   787,   703,   721,   278,    13,   109,   287,    38,    26,
      38,   755,   681,   755,   502,    38,   685,   559,   560,    38,
     690,   273,    38,   448,    -1,    38,   448,   567,    38,   132,
     133,    38,   613,   569,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   703,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   724,
      -1,    -1,   721,    -1,    -1,    -1,   618,    -1,   608,    -1,
      -1,   623,    -1,    -1,    -1,    -1,    -1,   613,    -1,    96,
      97,    98,    99,   100,   101,   630,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,    -1,   200,   201,   202,
     689,    -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   695,    -1,   696,   697,   698,
      -1,    -1,    -1,    -1,    -1,    -1,   706,   703,    -1,    -1,
     710,    -1,    -1,   713,   714,   715,   716,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   721,    -1,    -1,    -1,   741,
      -1,    -1,   744,    -1,    -1,    -1,    -1,   737,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   746,   747,   748,   749,
      -1,    -1,    -1,   753,    -1,    -1,    -1,   757,   758,    -1,
      -1,   761,    -1,   812,   764,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   335,   773,    -1,   775,   788,    -1,    -1,    -1,
      -1,    -1,   782,    -1,    -1,    -1,    -1,   350,     7,   789,
     790,    -1,   792,    -1,    -1,   795,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      -1,    37,    -1,    -1,   846,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   844,   845,    -1,    -1,    54,    -1,
      -1,    57,    58,   853,    60,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    92,    93,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,    -1,   144,    -1,
     146,    -1,    -1,    -1,   150,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,   559,   560,    -1,    54,
      -1,    -1,    57,    58,    18,    -1,   569,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
     613,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,   144,
      -1,   146,    -1,    -1,    -1,   150,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,     7,
     144,    -1,   146,   696,   697,   698,    -1,    -1,    -1,    -1,
     703,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,   721,     8,
       9,   724,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    -1,    44,    45,    -1,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,   142,    -1,   144,     1,   146,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,   144,
      -1,   146,   147,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,   144,    -1,   146,   147,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,   144,
      -1,   146,   147,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    -1,    44,    45,    -1,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,   144,    -1,   146,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    -1,    44,    45,
      -1,    47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,    -1,   144,    -1,
     146,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    -1,    44,    45,    -1,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,    -1,   144,    -1,   146,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    -1,    44,    45,    -1,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,   142,    -1,   144,    -1,   146,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,   144,    -1,   146,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,    -1,   144,    -1,
     146,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    16,    17,    18,    19,    -1,    21,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,    -1,   144,    -1,   146,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,   142,    -1,   144,    -1,   146,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,    -1,
     144,    -1,   146,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,   144,    -1,   146,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,    -1,   144,    -1,
     146,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,    -1,   144,    -1,   146,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
     108,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,   142,    -1,   144,    -1,   146,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,    -1,
     144,    -1,   146,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,   144,   145,   146,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,    -1,   144,    -1,
     146,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,    -1,   144,    -1,   146,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,   142,    -1,   144,    -1,   146,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     7,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,   108,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     7,    -1,   107,   108,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     7,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    26,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,   108,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     7,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     7,
      -1,   107,   108,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    26,   103,
     104,     7,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     7,    -1,   107,
     108,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    26,   103,   104,     7,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     7,    -1,   107,   108,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    26,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     7,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     7,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     7,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     7,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     7,    -1,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    80,    81,   107,   108,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     7,    -1,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    26,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    80,    81,   107,   108,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     7,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,   108,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       7,   147,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
     107,   108,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     7,
     147,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
     108,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     7,   147,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,   107,   108,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     7,   147,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,   108,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     7,   147,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,   108,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     7,   147,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,   108,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     7,   147,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    80,    81,   107,   108,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     7,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     7,    -1,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,   147,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     7,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    26,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     7,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     7,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     7,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     7,    -1,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     7,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,   108,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     7,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,   108,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       7,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
     107,   108,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     7,    -1,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,   107,   108,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,   108
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      25,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      42,    44,    45,    47,    48,    49,    50,    54,    57,    58,
      92,    93,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   142,   144,   146,   152,   153,   154,   155,
     157,   158,   160,   161,   166,   167,   168,   169,   170,   171,
     172,   181,   184,   185,   187,   193,   195,   196,   197,   200,
     201,   209,   210,   217,   223,   225,   226,   227,   230,   143,
     105,   105,   105,    57,    78,   105,   146,   199,     6,    92,
      93,   106,   128,   129,   130,   131,   192,   194,   195,   198,
     158,    42,   186,   186,   105,     6,    12,    57,   108,   194,
       6,   184,   194,     8,   105,   144,    41,    47,   187,   108,
     194,     6,    41,   108,   234,   236,     6,   105,   199,     3,
       4,     5,     6,    18,    35,    54,    59,    92,    93,   106,
     128,   129,   130,   131,   146,   197,   200,   201,   209,   210,
     217,   218,   219,   220,   221,   222,   223,   227,   230,    60,
     150,   194,   211,   213,   214,   215,   216,   193,   193,   146,
     146,   146,   146,   145,   191,   192,   194,   194,     0,   143,
     156,    15,   157,    20,    25,    30,    32,    34,    44,    45,
      48,    50,   159,    78,   149,     7,    26,    80,    81,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   107,
     108,   105,   199,   105,   199,   105,   199,   105,   199,   105,
     199,   105,   199,   146,   105,   199,   157,    88,   188,   189,
     190,   194,   194,   146,   147,   194,   228,   229,    57,   105,
     194,   194,   194,   146,   146,   146,   146,    10,    11,   148,
       7,    26,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   107,
     108,    47,   187,    47,   187,   146,   175,   182,   183,   184,
     197,   234,   149,    51,   167,   181,   184,   231,   233,   185,
      41,   197,   105,   175,   187,   196,   197,   235,    39,    40,
      43,   108,   105,   175,   105,   105,   105,   105,   105,   199,
     105,   105,   105,   199,   194,   194,   194,   146,   146,   146,
     146,   191,   105,   199,   105,   199,   105,   199,   105,   199,
     105,   199,     7,    26,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   107,   108,   149,   150,    59,   148,   178,   105,   199,
     105,   199,   150,   191,   212,    60,   148,    60,   150,   179,
     148,   149,   178,   194,   193,   193,   193,   145,   148,   178,
     150,   147,   155,   157,   194,     6,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   235,   105,   105,   105,   105,   105,   105,   194,   105,
     194,    59,   148,   178,    88,   147,   228,    56,   147,   148,
     178,   188,   194,   194,   194,   194,   198,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   235,    41,
      41,     1,   176,   177,   180,   181,   184,    78,    59,   148,
     178,   194,    78,     6,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   142,   237,   194,    78,   149,
     143,   145,   148,   232,   187,   194,   175,    19,   173,   194,
     194,   235,   175,   173,   105,   105,   194,   194,   194,   194,
     147,   105,   105,   105,   105,   105,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   235,   194,     6,   202,
     203,   204,   205,   206,   207,   208,   194,   105,   105,   150,
     150,   215,   216,   194,   194,   148,   148,   148,   148,   202,
     105,   199,   157,   146,   234,   147,   148,   190,   147,   194,
     146,   194,    59,   148,   148,   148,   148,   187,   187,   147,
     147,   148,   178,   194,    41,   184,     6,    57,   144,   162,
     163,   105,   175,    29,   224,   194,     6,    82,   145,   167,
     233,   173,   149,   234,   173,   234,   148,   148,   148,   148,
     105,   199,   150,    78,    59,   148,   178,    56,    82,   148,
     178,   149,   191,   212,   149,   194,   193,   193,   193,   145,
     105,   176,   194,   146,   194,    56,   194,   194,   194,   194,
     180,   185,   146,     8,   164,     6,   165,   107,   173,    27,
      28,   194,    82,   234,     6,    78,   174,   234,   174,   194,
     194,   194,   194,   105,   202,   194,   205,   206,   194,   194,
       6,   194,   150,   147,   147,   147,   147,   147,   147,   194,
     147,   194,   147,   147,   147,   147,   194,    59,   148,   145,
     148,   163,   234,   194,   194,   194,   174,   194,   174,   147,
     147,   147,   147,    59,    56,    56,   173,   147,   147,     8,
       6,   174,    29,    51,   194,   194,   234,   194,   174
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   151,   152,   153,   153,   154,   154,   154,   154,   154,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   160,   161,   161,   161,   161,
     161,   162,   162,   163,   163,   164,   164,   164,   165,   165,
     165,   166,   167,   167,   168,   168,   168,   169,   169,   170,
     170,   170,   170,   171,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   181,   182,   183,   183,   184,   184,
     184,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   186,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   189,   189,   190,   190,   190,   190,   191,   192,   192,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   195,   195,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   197,   197,   198,   198,   199,
     199,   200,   200,   201,   202,   203,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   207,   208,   208,   209,   209,
     210,   210,   210,   211,   211,   211,   212,   212,   213,   214,
     214,   214,   215,   216,   216,   216,   217,   217,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   219,   219,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     221,   222,   222,   222,   222,   223,   223,   224,   224,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   226,   226,   227,
     227,   227,   227,   227,   227,   227,   228,   229,   229,   229,
     229,   230,   230,   231,   231,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     3,     4,     2,
       3,     1,     2,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     3,     5,
       7,     1,     3,     3,     4,     0,     1,     3,     0,     1,
       3,     3,     2,     4,     3,     4,     4,     2,     4,     6,
       6,     7,     7,     8,     9,     3,     5,     0,     3,     0,
       2,     0,     3,     3,     0,     2,     1,     3,     0,     1,
       0,     1,     1,     1,     4,     2,     1,     3,     1,     6,
       3,     1,     2,     3,     3,     3,     4,     5,     5,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     2,     2,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       6,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     6,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     1,     3,     4,     4,     5,     1,     2,
       2,     3,     1,     2,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     2,     3,
       1,     2,     2,     3,     1,     2,     2,     3,     1,     2,
       2,     3,     1,     2,     2,     3,     1,     2,     2,     3,
       1,     1,     2,     2,     3,     1,     2,     2,     3,     3,
       4,     2,     3,     5,     1,     2,     1,     1,     3,     3,
       3,     5,     3,     5,     3,     2,     1,     3,     2,     3,
       2,     3,     3,     2,     3,     5,     1,     3,     2,     1,
       2,     3,     2,     1,     3,     3,     7,     5,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     6,     6,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     3,
       4,     4,     5,     1,     2,     2,     3,     1,     2,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     2,     3,     1,     2,     2,     3,     1,
       2,     2,     3,     1,     2,     2,     3,     1,     2,     2,
       3,     1,     2,     2,     3,     1,     1,     2,     2,     3,
       2,     1,     3,     3,     5,     5,     8,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     4,     3,
       4,     1,     4,     7,     5,     8,     2,     1,     3,     3,
       5,     6,     7,     1,     1,     3,     3,     1,     1,     1,
       3,     0,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, parm, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, parm); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *parm)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (parm);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *parm)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, parm);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void *parm)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), parm);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parm); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *parm)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (parm);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *parm)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
{
  GCLock lock;
  yylloc.filename(ASTString(static_cast<ParserState*>(parm)->filename));
}


  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, SCANNER);
    }

  if (yychar <= END)
    {
      yychar = END;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* item_list_head: item  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[0].item)) {
          pp->model->addItem((yyvsp[0].item));
          GC::unlock();
          GC::lock();
        }
      }
    break;

  case 6: /* item_list_head: doc_file_comments item  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[0].item)) {
          pp->model->addItem((yyvsp[0].item));
          GC::unlock();
          GC::lock();
        }
      }
    break;

  case 7: /* item_list_head: item_list_head ';' item  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[0].item)) {
          pp->model->addItem((yyvsp[0].item));
          GC::unlock();
          GC::lock();
        }
      }
    break;

  case 8: /* item_list_head: item_list_head ';' doc_file_comments item  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[0].item)) {
          pp->model->addItem((yyvsp[0].item));
          GC::unlock();
          GC::lock();
        }
      }
    break;

  case 9: /* item_list_head: item error_item_start  */
{ yyerror(&(yylsp[0]), parm, "unexpected item, expecting ';' or end of file"); YYERROR; }
    break;

  case 11: /* doc_file_comments: "file-level documentation comment"  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->parseDocComments && (yyvsp[0].sValue)) {
          pp->model->addDocComment((yyvsp[0].sValue));
        }
        free((yyvsp[0].sValue));
      }
    break;

  case 12: /* doc_file_comments: doc_file_comments "file-level documentation comment"  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->parseDocComments && (yyvsp[0].sValue)) {
          pp->model->addDocComment((yyvsp[0].sValue));
        }
        free((yyvsp[0].sValue));
      }
    break;

  case 15: /* item: "documentation comment" item_tail  */
      { (yyval.item) = (yyvsp[0].item);
        ParserState* pp = static_cast<ParserState*>(parm);
        if (FunctionI* fi = Item::dynamicCast<FunctionI>((yyval.item))) {
          if (pp->parseDocComments) {
            fi->ann().add(createDocComment((yylsp[-1]),(yyvsp[-1].sValue)));
          }
        } else if (VarDeclI* vdi = Item::dynamicCast<VarDeclI>((yyval.item))) {
          if (pp->parseDocComments) {
            vdi->e()->addAnnotation(createDocComment((yylsp[-1]),(yyvsp[-1].sValue)));
          }
        } else {
          yyerror(&(yylsp[0]), parm, "documentation comments are only supported for function, predicate and variable declarations");
        }
        free((yyvsp[-1].sValue));
      }
    break;

  case 16: /* item: item_tail  */
      { (yyval.item) = (yyvsp[0].item); }
    break;

  case 17: /* item_tail: include_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"include") ? (yyvsp[0].item) : nullptr; }
    break;

  case 18: /* item_tail: vardecl_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"variable declaration") ? (yyvsp[0].item) : nullptr; }
    break;

  case 20: /* item_tail: constraint_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"constraint") ? (yyvsp[0].item) : nullptr; }
    break;

  case 21: /* item_tail: solve_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"solve") ? (yyvsp[0].item) : nullptr; }
    break;

  case 22: /* item_tail: output_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"output") ? (yyvsp[0].item) : nullptr; }
    break;

  case 23: /* item_tail: predicate_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"predicate") ? (yyvsp[0].item) : nullptr; }
    break;

  case 24: /* item_tail: function_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"predicate") ? (yyvsp[0].item) : nullptr; }
    break;

  case 25: /* item_tail: annotation_item  */
      { (yyval.item)=notInDatafile(&(yyloc),parm,"annotation") ? (yyvsp[0].item) : nullptr; }
    break;

  case 35: /* include_item: "include" "string literal"  */
      { ParserState* pp = static_cast<ParserState*>(parm);
        string canonicalName=pp->canonicalFilename((yyvsp[0].sValue));
        map<string,Model*>::iterator ret = pp->seenModels.find(canonicalName);
        IncludeI* ii = new IncludeI((yyloc),ASTString((yyvsp[0].sValue)));
        (yyval.item) = ii;
        if (ret == pp->seenModels.end()) {
          Model* im = new Model;
          im->setParent(pp->model);
          im->setFilename(canonicalName);
          string fpath = FileUtils::dir_name(pp->filename);
          if (fpath=="")
            fpath="./";
          pp->files.emplace_back(im, ii, fpath, canonicalName, pp->isSTDLib);
          ii->m(im);
          pp->seenModels.insert(pair<string,Model*>(canonicalName,im));
        } else {
          ii->m(ret->second, false);
        }
        free((yyvsp[0].sValue));
      }
    break;

  case 36: /* vardecl_item: ti_expr_and_id  */
      { if ((yyvsp[0].vardeclexpr))
          (yyval.item) = new VarDeclI((yyloc),(yyvsp[0].vardeclexpr));
      }
    break;

  case 37: /* vardecl_item: ti_expr_and_id "=" expr  */
      { if ((yyvsp[-2].vardeclexpr)) (yyvsp[-2].vardeclexpr)->e((yyvsp[0].expression));
        if ((yyvsp[-2].vardeclexpr))
          (yyval.item) = new VarDeclI((yyloc),(yyvsp[-2].vardeclexpr));
      }
    break;

  case 38: /* vardecl_item: "enum" "identifier" annotations  */
      {
        TypeInst* ti = new TypeInst((yyloc),Type::parsetint());
        ti->setIsEnum(true);
        VarDecl* vd = new VarDecl((yyloc),ti,(yyvsp[-1].sValue));
        if ((yyvsp[-1].sValue) && (yyvsp[0].expressions1d))
          vd->addAnnotations(*(yyvsp[0].expressions1d));
        free((yyvsp[-1].sValue));
        (yyval.item) = new VarDeclI((yyloc),vd);
      }
    break;

  case 39: /* vardecl_item: "enum" "identifier" annotations "=" enum_init  */
      {
        if ((yyvsp[0].expressions1d)) {
          TypeInst* ti = new TypeInst((yyloc),Type::parsetint());
          ti->setIsEnum(true);
          Expression* e;
          if ((yyvsp[0].expressions1d)->size()==1) {
            e = (*(yyvsp[0].expressions1d))[0];
          } else {
            ArrayLit* al = new ArrayLit((yyloc),*(yyvsp[0].expressions1d));
            e = new Call((yyloc), ASTString("enumFromConstructors"), {al});
          }
          VarDecl* vd = new VarDecl((yyloc),ti,(yyvsp[-3].sValue),e);
          (yyval.item) = new VarDeclI((yyloc),vd);
        }
        free((yyvsp[-3].sValue));
        delete (yyvsp[0].expressions1d);
      }
    break;

  case 40: /* vardecl_item: "enum" "identifier" annotations "=" "[" string_lit_list "]"  */
      {
        TypeInst* ti = new TypeInst((yyloc),Type::parsetint());
        ti->setIsEnum(true);
        vector<Expression*> args;
        args.push_back(new ArrayLit((yyloc),*(yyvsp[-1].expressions1d)));
        Call* sl = new Call((yyloc), Constants::constants().ids.anonEnumFromStrings, args);
        VarDecl* vd = new VarDecl((yyloc),ti,(yyvsp[-5].sValue),sl);
        if ((yyvsp[-5].sValue) && (yyvsp[-4].expressions1d))
          vd->addAnnotations(*(yyvsp[-4].expressions1d));
        free((yyvsp[-5].sValue));
        delete (yyvsp[-1].expressions1d);
        (yyval.item) = new VarDeclI((yyloc),vd);
      }
    break;

  case 41: /* enum_init: enum_construct  */
      {
        (yyval.expressions1d) = new std::vector<Expression*>({(yyvsp[0].expression)});
      }
    break;

  case 42: /* enum_init: enum_init "++" enum_construct  */
      {
        (yyval.expressions1d) = (yyvsp[-2].expressions1d);
        if ((yyval.expressions1d)) {
          (yyval.expressions1d)->push_back((yyvsp[0].expression));
        }
      }
    break;

  case 43: /* enum_construct: '{' enum_id_list '}'  */
      {
        (yyval.expression) = new SetLit((yyloc), *(yyvsp[-1].expressions1d));
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 44: /* enum_construct: "identifier" '(' expr ')'  */
      {
        vector<Expression*> args({(yyvsp[-1].expression)});
        (yyval.expression) = new Call((yyloc), ASTString((yyvsp[-3].sValue)), args);
        free((yyvsp[-3].sValue));
      }
    break;

  case 45: /* string_lit_list: %empty  */
      { (yyval.expressions1d) = new std::vector<Expression*>(); }
    break;

  case 46: /* string_lit_list: "string literal"  */
      { (yyval.expressions1d) = new std::vector<Expression*>();
        (yyval.expressions1d)->push_back(new StringLit((yyloc), (yyvsp[0].sValue))); free((yyvsp[0].sValue));
      }
    break;

  case 47: /* string_lit_list: string_lit_list ',' "string literal"  */
      { (yyval.expressions1d) = (yyvsp[-2].expressions1d);
        if ((yyval.expressions1d)) (yyval.expressions1d)->push_back(new StringLit((yyloc), (yyvsp[0].sValue)));
        free((yyvsp[0].sValue));
      }
    break;

  case 48: /* enum_id_list: %empty  */
      { (yyval.expressions1d) = new std::vector<Expression*>(); }
    break;

  case 49: /* enum_id_list: "identifier"  */
      { (yyval.expressions1d) = new std::vector<Expression*>();
        (yyval.expressions1d)->push_back(new Id((yyloc),(yyvsp[0].sValue),nullptr)); free((yyvsp[0].sValue));
      }
    break;

  case 50: /* enum_id_list: enum_id_list ',' "identifier"  */
      { (yyval.expressions1d) = (yyvsp[-2].expressions1d); if ((yyval.expressions1d)) (yyval.expressions1d)->push_back(new Id((yyloc),(yyvsp[0].sValue),nullptr)); free((yyvsp[0].sValue)); }
    break;

  case 51: /* assign_item: "identifier" "=" expr  */
      { (yyval.item) = new AssignI((yyloc),(yyvsp[-2].sValue),(yyvsp[0].expression));
        free((yyvsp[-2].sValue));
      }
    break;

  case 52: /* constraint_item: "constraint" expr  */
      { (yyval.item) = new ConstraintI((yyloc),(yyvsp[0].expression));}
    break;

  case 53: /* constraint_item: "constraint" "::" string_expr expr  */
      { (yyval.item) = new ConstraintI((yyloc),(yyvsp[0].expression));
        if ((yyvsp[0].expression) && (yyvsp[-1].expression))
          (yyval.item)->cast<ConstraintI>()->e()->ann().add(new Call((yylsp[-2]), ASTString("mzn_constraint_name"), {(yyvsp[-1].expression)}));
      }
    break;

  case 54: /* solve_item: "solve" annotations "satisfy"  */
      { (yyval.item) = SolveI::sat((yyloc));
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<SolveI>()->ann().add(*(yyvsp[-1].expressions1d));
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 55: /* solve_item: "solve" annotations "minimize" expr  */
      { (yyval.item) = SolveI::min((yyloc),(yyvsp[0].expression));
        if ((yyval.item) && (yyvsp[-2].expressions1d)) (yyval.item)->cast<SolveI>()->ann().add(*(yyvsp[-2].expressions1d));
        delete (yyvsp[-2].expressions1d);
      }
    break;

  case 56: /* solve_item: "solve" annotations "maximize" expr  */
      { (yyval.item) = SolveI::max((yyloc),(yyvsp[0].expression));
        if ((yyval.item) && (yyvsp[-2].expressions1d)) (yyval.item)->cast<SolveI>()->ann().add(*(yyvsp[-2].expressions1d));
        delete (yyvsp[-2].expressions1d);
      }
    break;

  case 57: /* output_item: "output" expr  */
      { (yyval.item) = new OutputI((yyloc),(yyvsp[0].expression)); }
    break;

  case 58: /* output_item: "output" "::" string_expr expr  */
      { (yyval.item) = new OutputI((yyloc),(yyvsp[0].expression));
        if ((yyval.item) && (yyvsp[-1].expression)) {
          (yyval.item)->cast<OutputI>()->ann().add(new Call((yyloc), ASTString("mzn_output_section"), {(yyvsp[-1].expression)}));
        }
      }
    break;

  case 59: /* predicate_item: "predicate" "identifier" params ann_param annotations operation_item_tail  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[-3].vardeclexprs) && (yyvsp[-2].vardeclexpr)) (yyvsp[-3].vardeclexprs)->push_back((yyvsp[-2].vardeclexpr));
        if ((yyvsp[-3].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString((yyvsp[-4].sValue)),new TypeInst((yyloc),
                                   Type::varbool()),*(yyvsp[-3].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib,(yyvsp[-2].vardeclexpr) != nullptr);
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<FunctionI>()->ann().add(*(yyvsp[-1].expressions1d));
        free((yyvsp[-4].sValue));
        delete (yyvsp[-3].vardeclexprs);
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 60: /* predicate_item: "test" "identifier" params ann_param annotations operation_item_tail  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[-3].vardeclexprs) && (yyvsp[-2].vardeclexpr)) (yyvsp[-3].vardeclexprs)->push_back((yyvsp[-2].vardeclexpr));
        if ((yyvsp[-3].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString((yyvsp[-4].sValue)),new TypeInst((yyloc),
                                   Type::parbool()),*(yyvsp[-3].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib,(yyvsp[-2].vardeclexpr) != nullptr);
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<FunctionI>()->ann().add(*(yyvsp[-1].expressions1d));
        free((yyvsp[-4].sValue));
        delete (yyvsp[-3].vardeclexprs);
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 61: /* predicate_item: "predicate" "identifier" "^-1" params ann_param annotations operation_item_tail  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[-3].vardeclexprs) && (yyvsp[-2].vardeclexpr)) (yyvsp[-3].vardeclexprs)->push_back((yyvsp[-2].vardeclexpr));
        if ((yyvsp[-3].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString(std::string((yyvsp[-5].sValue))+"⁻¹"),new TypeInst((yyloc),
                                   Type::varbool()),*(yyvsp[-3].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib,(yyvsp[-2].vardeclexpr) != nullptr);
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<FunctionI>()->ann().add(*(yyvsp[-1].expressions1d));
        free((yyvsp[-5].sValue));
        delete (yyvsp[-3].vardeclexprs);
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 62: /* predicate_item: "test" "identifier" "^-1" params ann_param annotations operation_item_tail  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[-3].vardeclexprs) && (yyvsp[-2].vardeclexpr)) (yyvsp[-3].vardeclexprs)->push_back((yyvsp[-2].vardeclexpr));
        if ((yyvsp[-3].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString(std::string((yyvsp[-5].sValue))+"⁻¹"),new TypeInst((yyloc),
                                   Type::parbool()),*(yyvsp[-3].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib,(yyvsp[-2].vardeclexpr) != nullptr);
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<FunctionI>()->ann().add(*(yyvsp[-1].expressions1d));
        free((yyvsp[-5].sValue));
        delete (yyvsp[-3].vardeclexprs);
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 63: /* function_item: "function" ti_expr ':' id_or_quoted_op params ann_param annotations operation_item_tail  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[-3].vardeclexprs) && (yyvsp[-2].vardeclexpr)) (yyvsp[-3].vardeclexprs)->push_back((yyvsp[-2].vardeclexpr));
        if ((yyvsp[-3].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString((yyvsp[-4].sValue)),(yyvsp[-6].tiexpr),*(yyvsp[-3].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib,(yyvsp[-2].vardeclexpr) != nullptr);
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<FunctionI>()->ann().add(*(yyvsp[-1].expressions1d));
        free((yyvsp[-4].sValue));
        delete (yyvsp[-3].vardeclexprs);
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 64: /* function_item: ti_expr ':' "identifier" '(' params_list ')' ann_param annotations operation_item_tail  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        if ((yyvsp[-4].vardeclexprs) && (yyvsp[-2].vardeclexpr)) (yyvsp[-4].vardeclexprs)->push_back((yyvsp[-2].vardeclexpr));
        if ((yyvsp[-4].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString((yyvsp[-6].sValue)),(yyvsp[-8].tiexpr),*(yyvsp[-4].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib,(yyvsp[-2].vardeclexpr) != nullptr);
        if ((yyval.item) && (yyvsp[-1].expressions1d)) (yyval.item)->cast<FunctionI>()->ann().add(*(yyvsp[-1].expressions1d));
        free((yyvsp[-6].sValue));
        delete (yyvsp[-4].vardeclexprs);
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 65: /* annotation_item: "annotation" "identifier" params  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        TypeInst* ti=new TypeInst((yylsp[-2]),Type::ann());
        if ((yyvsp[0].vardeclexprs)==nullptr || (yyvsp[0].vardeclexprs)->empty()) {
          VarDecl* vd = new VarDecl((yyloc),ti,(yyvsp[-1].sValue));
          (yyval.item) = new VarDeclI((yyloc),vd);
        } else {
          (yyval.item) = new FunctionI((yyloc),ASTString((yyvsp[-1].sValue)),ti,*(yyvsp[0].vardeclexprs),nullptr,pp->isSTDLib);
        }
        free((yyvsp[-1].sValue));
        delete (yyvsp[0].vardeclexprs);
      }
    break;

  case 66: /* annotation_item: "annotation" "identifier" params "=" expr  */
      {
        ParserState* pp = static_cast<ParserState*>(parm);
        TypeInst* ti=new TypeInst((yylsp[-4]),Type::ann());
        if ((yyvsp[-2].vardeclexprs)) (yyval.item) = new FunctionI((yyloc),ASTString((yyvsp[-3].sValue)),ti,*(yyvsp[-2].vardeclexprs),(yyvsp[0].expression),pp->isSTDLib);
        delete (yyvsp[-2].vardeclexprs);
      }
    break;

  case 67: /* ann_param: %empty  */
      { (yyval.vardeclexpr)=nullptr; }
    break;

  case 68: /* ann_param: "ann" ':' "identifier"  */
      { if ((yyvsp[0].sValue)) {
          auto* ident = new Id((yylsp[0]), (yyvsp[0].sValue), nullptr);
          auto* ti = new TypeInst((yyloc),Type::ann(1));
          (yyval.vardeclexpr) = new VarDecl((yyloc), ti, ident);
          (yyval.vardeclexpr)->toplevel(false);
        } }
    break;

  case 69: /* operation_item_tail: %empty  */
      { (yyval.expression)=nullptr; }
    break;

  case 70: /* operation_item_tail: "=" expr  */
      { (yyval.expression)=(yyvsp[0].expression); }
    break;

  case 71: /* params: %empty  */
      { (yyval.vardeclexprs)=new vector<VarDecl*>(); }
    break;

  case 72: /* params: '(' params_list ')'  */
      { (yyval.vardeclexprs)=(yyvsp[-1].vardeclexprs); }
    break;

  case 73: /* params: '(' error ')'  */
      { (yyval.vardeclexprs)=new vector<VarDecl*>(); }
    break;

  case 74: /* params_list: %empty  */
      { (yyval.vardeclexprs)=new vector<VarDecl*>(); }
    break;

  case 75: /* params_list: params_list_head comma_or_none  */
      { (yyval.vardeclexprs)=(yyvsp[-1].vardeclexprs); }
    break;

  case 76: /* params_list_head: ti_expr_and_id_or_anon  */
      { (yyval.vardeclexprs)=new vector<VarDecl*>();
        if ((yyvsp[0].vardeclexpr)) (yyvsp[0].vardeclexpr)->toplevel(false);
        if ((yyvsp[0].vardeclexpr)) (yyval.vardeclexprs)->push_back((yyvsp[0].vardeclexpr)); }
    break;

  case 77: /* params_list_head: params_list_head ',' ti_expr_and_id_or_anon  */
      { (yyval.vardeclexprs)=(yyvsp[-2].vardeclexprs);
        if ((yyvsp[0].vardeclexpr)) (yyvsp[0].vardeclexpr)->toplevel(false);
        if ((yyvsp[-2].vardeclexprs) && (yyvsp[0].vardeclexpr)) (yyvsp[-2].vardeclexprs)->push_back((yyvsp[0].vardeclexpr)); }
    break;

  case 82: /* ti_expr_and_id_or_anon: ti_expr_and_id  */
      { (yyval.vardeclexpr)=(yyvsp[0].vardeclexpr); }
    break;

  case 83: /* ti_expr_and_id_or_anon: ti_expr  */
      { if ((yyvsp[0].tiexpr)) (yyval.vardeclexpr)=new VarDecl((yyloc), (yyvsp[0].tiexpr), ""); }
    break;

  case 84: /* ti_expr_and_id: ti_expr ':' "identifier" annotations  */
      { if ((yyvsp[-3].tiexpr) && (yyvsp[-1].sValue)) {
          Id* ident = new Id((yylsp[-1]), (yyvsp[-1].sValue), nullptr);
          (yyval.vardeclexpr) = new VarDecl((yyloc), (yyvsp[-3].tiexpr), ident);
          if ((yyvsp[0].expressions1d)) (yyval.vardeclexpr)->ann().add(*(yyvsp[0].expressions1d));
        }
        free((yyvsp[-1].sValue));
        delete (yyvsp[0].expressions1d);
      }
    break;

  case 85: /* ti_expr_list: ti_expr_list_head comma_or_none  */
      { (yyval.tiexprs)=(yyvsp[-1].tiexprs); }
    break;

  case 86: /* ti_expr_list_head: ti_expr  */
      { (yyval.tiexprs)=new vector<TypeInst*>(); (yyval.tiexprs)->push_back((yyvsp[0].tiexpr)); }
    break;

  case 87: /* ti_expr_list_head: ti_expr_list_head ',' ti_expr  */
      { (yyval.tiexprs)=(yyvsp[-2].tiexprs); if ((yyvsp[-2].tiexprs) && (yyvsp[0].tiexpr)) (yyvsp[-2].tiexprs)->push_back((yyvsp[0].tiexpr)); }
    break;

  case 89: /* ti_expr: "array" "[" ti_expr_list "]" "of" base_ti_expr  */
      {
        (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr) && (yyvsp[-3].tiexprs)) (yyval.tiexpr)->setRanges(*(yyvsp[-3].tiexprs));
        delete (yyvsp[-3].tiexprs);
      }
    break;

  case 90: /* ti_expr: "list" "of" base_ti_expr  */
      {
        (yyval.tiexpr) = (yyvsp[0].tiexpr);
        std::vector<TypeInst*> ti(1);
        ti[0] = new TypeInst((yyloc),Type::parint());
        if ((yyval.tiexpr)) (yyval.tiexpr)->setRanges(ti);
      }
    break;

  case 91: /* base_ti_expr: base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
      }
    break;

  case 92: /* base_ti_expr: "opt" base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr)) {
          Type tt = (yyval.tiexpr)->type();
          tt.ot(Type::OT_OPTIONAL);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 93: /* base_ti_expr: "par" opt_opt base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr) && (yyvsp[-1].bValue)) {
          Type tt = (yyval.tiexpr)->type();
          tt.ot(Type::OT_OPTIONAL);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 94: /* base_ti_expr: "var" opt_opt base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr)) {
          Type tt = (yyval.tiexpr)->type();
          tt.ti(Type::TI_VAR);
          if ((yyvsp[-1].bValue)) tt.ot(Type::OT_OPTIONAL);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 95: /* base_ti_expr: "set" "of" base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr)) {
          Type tt = (yyval.tiexpr)->type();
          tt.st(Type::ST_SET);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 96: /* base_ti_expr: "opt" "set" "of" base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr)) {
          Type tt = (yyval.tiexpr)->type();
          tt.st(Type::ST_SET);
          tt.ot(Type::OT_OPTIONAL);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 97: /* base_ti_expr: "par" opt_opt "set" "of" base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr)) {
          Type tt = (yyval.tiexpr)->type();
          tt.st(Type::ST_SET);
          if ((yyvsp[-3].bValue)) tt.ot(Type::OT_OPTIONAL);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 98: /* base_ti_expr: "var" opt_opt "set" "of" base_ti_expr_tail  */
      { (yyval.tiexpr) = (yyvsp[0].tiexpr);
        if ((yyval.tiexpr)) {
          Type tt = (yyval.tiexpr)->type();
          tt.ti(Type::TI_VAR);
          tt.st(Type::ST_SET);
          if ((yyvsp[-3].bValue)) tt.ot(Type::OT_OPTIONAL);
          (yyval.tiexpr)->type(tt);
        }
      }
    break;

  case 99: /* base_ti_expr: "any" "type-inst identifier"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::mkAny(),new TIId((yyloc), (yyvsp[0].sValue)));
        free((yyvsp[0].sValue));
      }
    break;

  case 100: /* opt_opt: %empty  */
      { (yyval.bValue) = false; }
    break;

  case 101: /* opt_opt: "opt"  */
      { (yyval.bValue) = true; }
    break;

  case 102: /* base_ti_expr_tail: "int"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::parint()); }
    break;

  case 103: /* base_ti_expr_tail: "bool"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::parbool()); }
    break;

  case 104: /* base_ti_expr_tail: "float"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::parfloat()); }
    break;

  case 105: /* base_ti_expr_tail: "string"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::parstring()); }
    break;

  case 106: /* base_ti_expr_tail: "ann"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::ann()); }
    break;

  case 107: /* base_ti_expr_tail: set_expr  */
        { if ((yyvsp[0].expression)) (yyval.tiexpr) = new TypeInst((yyloc),Type(),(yyvsp[0].expression)); }
    break;

  case 108: /* base_ti_expr_tail: "type-inst identifier"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::top(),
                         new TIId((yyloc), (yyvsp[0].sValue)));
        free((yyvsp[0].sValue));
      }
    break;

  case 109: /* base_ti_expr_tail: "type-inst enum identifier"  */
      { (yyval.tiexpr) = new TypeInst((yyloc),Type::parint(),
          new TIId((yyloc), (yyvsp[0].sValue)));
          free((yyvsp[0].sValue));
      }
    break;

  case 111: /* array_access_expr_list_head: array_access_expr  */
      { (yyval.expressions1d)=new std::vector<MiniZinc::Expression*>; (yyval.expressions1d)->push_back((yyvsp[0].expression)); }
    break;

  case 112: /* array_access_expr_list_head: array_access_expr_list_head ',' array_access_expr  */
      { (yyval.expressions1d)=(yyvsp[-2].expressions1d); if ((yyval.expressions1d) && (yyvsp[0].expression)) (yyval.expressions1d)->push_back((yyvsp[0].expression)); }
    break;

  case 113: /* array_access_expr: expr  */
      { (yyval.expression) = (yyvsp[0].expression); }
    break;

  case 114: /* array_access_expr: ".."  */
      { (yyval.expression)=new SetLit((yyloc), IntSetVal::a(-IntVal::infinity(),IntVal::infinity())); }
    break;

  case 115: /* array_access_expr: ".." expr  */
      { if ((yyvsp[0].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a(-IntVal::infinity(),(yyvsp[0].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), IntLit::a(-IntVal::infinity()), BOT_DOTDOT, (yyvsp[0].expression));
        }
      }
    break;

  case 116: /* array_access_expr: expr ".."  */
      { if ((yyvsp[-1].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-1].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-1].expression)->cast<IntLit>()->v(),IntVal::infinity()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-1].expression), BOT_DOTDOT, IntLit::a(IntVal::infinity()));
        }
      }
    break;

  case 118: /* expr_list_head: expr  */
      { (yyval.expressions1d)=new std::vector<MiniZinc::Expression*>; (yyval.expressions1d)->push_back((yyvsp[0].expression)); }
    break;

  case 119: /* expr_list_head: expr_list_head ',' expr  */
      { (yyval.expressions1d)=(yyvsp[-2].expressions1d); if ((yyval.expressions1d) && (yyvsp[0].expression)) (yyval.expressions1d)->push_back((yyvsp[0].expression)); }
    break;

  case 121: /* set_expr: set_expr "::" annotation_expr  */
      { if ((yyvsp[-2].expression) && (yyvsp[0].expression)) (yyvsp[-2].expression)->addAnnotation((yyvsp[0].expression)); (yyval.expression)=(yyvsp[-2].expression); }
    break;

  case 122: /* set_expr: set_expr "union" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_UNION, (yyvsp[0].expression)); }
    break;

  case 123: /* set_expr: set_expr "diff" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DIFF, (yyvsp[0].expression)); }
    break;

  case 124: /* set_expr: set_expr "symdiff" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SYMDIFF, (yyvsp[0].expression)); }
    break;

  case 125: /* set_expr: set_expr ".." set_expr  */
      { if ((yyvsp[-2].expression)==nullptr || (yyvsp[0].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-2].expression)->isa<IntLit>() && (yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-2].expression)->cast<IntLit>()->v(),(yyvsp[0].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DOTDOT, (yyvsp[0].expression));
        }
      }
    break;

  case 126: /* set_expr: set_expr "..<" set_expr  */
      { (yyval.expression)=new Call((yyloc), ASTString("'..<'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); }
    break;

  case 127: /* set_expr: set_expr "<.." set_expr  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); }
    break;

  case 128: /* set_expr: set_expr "<..<" set_expr  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..<'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); }
    break;

  case 129: /* set_expr: "'..<'" '(' set_expr ',' set_expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'..<'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 130: /* set_expr: "'<..'" '(' set_expr ',' set_expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 131: /* set_expr: "'<..<'" '(' set_expr ',' set_expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..<'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 132: /* set_expr: "'..'" '(' expr ',' expr ')'  */
      { if ((yyvsp[-3].expression)==nullptr || (yyvsp[-1].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-3].expression)->isa<IntLit>() && (yyvsp[-1].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-3].expression)->cast<IntLit>()->v(),(yyvsp[-1].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-3].expression), BOT_DOTDOT, (yyvsp[-1].expression));
        }
      }
    break;

  case 133: /* set_expr: set_expr "intersect" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_INTERSECT, (yyvsp[0].expression)); }
    break;

  case 134: /* set_expr: set_expr "++" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_PLUSPLUS, (yyvsp[0].expression)); }
    break;

  case 135: /* set_expr: set_expr "+" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_PLUS, (yyvsp[0].expression)); }
    break;

  case 136: /* set_expr: set_expr "-" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MINUS, (yyvsp[0].expression)); }
    break;

  case 137: /* set_expr: set_expr "*" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MULT, (yyvsp[0].expression)); }
    break;

  case 138: /* set_expr: set_expr "/" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DIV, (yyvsp[0].expression)); }
    break;

  case 139: /* set_expr: set_expr "div" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IDIV, (yyvsp[0].expression)); }
    break;

  case 140: /* set_expr: set_expr "mod" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MOD, (yyvsp[0].expression)); }
    break;

  case 141: /* set_expr: set_expr "^" set_expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_POW, (yyvsp[0].expression)); }
    break;

  case 142: /* set_expr: set_expr "~+" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~+"), args);
      }
    break;

  case 143: /* set_expr: set_expr "~-" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~-"), args);
      }
    break;

  case 144: /* set_expr: set_expr "~*" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~*"), args);
      }
    break;

  case 145: /* set_expr: set_expr "~/" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~/"), args);
      }
    break;

  case 146: /* set_expr: set_expr "~div" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~div"), args);
      }
    break;

  case 147: /* set_expr: set_expr "~=" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~="), args);
      }
    break;

  case 148: /* set_expr: set_expr "~!=" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~!="), args);
      }
    break;

  case 149: /* set_expr: set_expr "default" set_expr  */
      {
        vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("default"), args);
      }
    break;

  case 150: /* set_expr: set_expr "quoted identifier" set_expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), (yyvsp[-1].sValue), args);
        free((yyvsp[-1].sValue));
      }
    break;

  case 151: /* set_expr: "+" set_expr  */
      { (yyval.expression)=new UnOp((yyloc), UOT_PLUS, (yyvsp[0].expression)); }
    break;

  case 152: /* set_expr: "-" set_expr  */
      { if ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression) = IntLit::a(-(yyvsp[0].expression)->cast<IntLit>()->v());
        } else if ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<FloatLit>()) {
          (yyval.expression) = FloatLit::a(-(yyvsp[0].expression)->cast<FloatLit>()->v());
        } else {
          (yyval.expression)=new UnOp((yyloc), UOT_MINUS, (yyvsp[0].expression));
        }
      }
    break;

  case 154: /* expr: expr "::" annotation_expr  */
      { if ((yyvsp[-2].expression) && (yyvsp[0].expression)) (yyvsp[-2].expression)->addAnnotation((yyvsp[0].expression)); (yyval.expression)=(yyvsp[-2].expression); }
    break;

  case 155: /* expr: expr "<->" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_EQUIV, (yyvsp[0].expression)); }
    break;

  case 156: /* expr: expr "->" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IMPL, (yyvsp[0].expression)); }
    break;

  case 157: /* expr: expr "<-" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_RIMPL, (yyvsp[0].expression)); }
    break;

  case 158: /* expr: expr "\\/" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_OR, (yyvsp[0].expression)); }
    break;

  case 159: /* expr: expr "xor" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_XOR, (yyvsp[0].expression)); }
    break;

  case 160: /* expr: expr "/\\" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_AND, (yyvsp[0].expression)); }
    break;

  case 161: /* expr: expr "<" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_LE, (yyvsp[0].expression)); }
    break;

  case 162: /* expr: expr ">" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_GR, (yyvsp[0].expression)); }
    break;

  case 163: /* expr: expr "<=" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_LQ, (yyvsp[0].expression)); }
    break;

  case 164: /* expr: expr ">=" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_GQ, (yyvsp[0].expression)); }
    break;

  case 165: /* expr: expr "=" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_EQ, (yyvsp[0].expression)); }
    break;

  case 166: /* expr: expr "!=" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_NQ, (yyvsp[0].expression)); }
    break;

  case 167: /* expr: expr "in" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IN, (yyvsp[0].expression)); }
    break;

  case 168: /* expr: expr "subset" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SUBSET, (yyvsp[0].expression)); }
    break;

  case 169: /* expr: expr "superset" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SUPERSET, (yyvsp[0].expression)); }
    break;

  case 170: /* expr: expr "union" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_UNION, (yyvsp[0].expression)); }
    break;

  case 171: /* expr: expr "diff" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DIFF, (yyvsp[0].expression)); }
    break;

  case 172: /* expr: expr "symdiff" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SYMDIFF, (yyvsp[0].expression)); }
    break;

  case 173: /* expr: expr ".." expr  */
      { if ((yyvsp[-2].expression)==nullptr || (yyvsp[0].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-2].expression)->isa<IntLit>() && (yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-2].expression)->cast<IntLit>()->v(),(yyvsp[0].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DOTDOT, (yyvsp[0].expression));
        }
      }
    break;

  case 174: /* expr: expr "..<" expr  */
      { (yyval.expression)=new Call((yyloc), ASTString("'..<'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); }
    break;

  case 175: /* expr: expr "<.." expr  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); }
    break;

  case 176: /* expr: expr "<..<" expr  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..<'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); }
    break;

  case 177: /* expr: "'..<'" '(' expr ',' expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'..<'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 178: /* expr: "'<..'" '(' expr ',' expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 179: /* expr: "'<..<'" '(' expr ',' expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..<'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 180: /* expr: "'..'" '(' expr ',' expr ')'  */
      { if ((yyvsp[-3].expression)==nullptr || (yyvsp[-1].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-3].expression)->isa<IntLit>() && (yyvsp[-1].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-3].expression)->cast<IntLit>()->v(),(yyvsp[-1].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-3].expression), BOT_DOTDOT, (yyvsp[-1].expression));
        }
      }
    break;

  case 181: /* expr: expr "intersect" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_INTERSECT, (yyvsp[0].expression)); }
    break;

  case 182: /* expr: expr "++" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_PLUSPLUS, (yyvsp[0].expression)); }
    break;

  case 183: /* expr: expr "+" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_PLUS, (yyvsp[0].expression)); }
    break;

  case 184: /* expr: expr "-" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MINUS, (yyvsp[0].expression)); }
    break;

  case 185: /* expr: expr "*" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MULT, (yyvsp[0].expression)); }
    break;

  case 186: /* expr: expr "/" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DIV, (yyvsp[0].expression)); }
    break;

  case 187: /* expr: expr "div" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IDIV, (yyvsp[0].expression)); }
    break;

  case 188: /* expr: expr "mod" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MOD, (yyvsp[0].expression)); }
    break;

  case 189: /* expr: expr "^" expr  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_POW, (yyvsp[0].expression)); }
    break;

  case 190: /* expr: expr "~+" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~+"), args);
      }
    break;

  case 191: /* expr: expr "~-" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~-"), args);
      }
    break;

  case 192: /* expr: expr "~*" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~*"), args);
      }
    break;

  case 193: /* expr: expr "~/" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~/"), args);
      }
    break;

  case 194: /* expr: expr "~div" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~div"), args);
      }
    break;

  case 195: /* expr: expr "~=" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~="), args);
      }
    break;

  case 196: /* expr: expr "~!=" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("~!="), args);
      }
    break;

  case 197: /* expr: expr "default" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), ASTString("default"), args);
      }
    break;

  case 198: /* expr: expr "quoted identifier" expr  */
      { vector<Expression*> args;
        args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
        (yyval.expression)=new Call((yyloc), (yyvsp[-1].sValue), args);
        free((yyvsp[-1].sValue));
      }
    break;

  case 199: /* expr: "not" expr  */
      { (yyval.expression)=new UnOp((yyloc), UOT_NOT, (yyvsp[0].expression)); }
    break;

  case 200: /* expr: "+" expr  */
      { if (((yyvsp[0].expression) && (yyvsp[0].expression)->isa<IntLit>()) || ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<FloatLit>())) {
          (yyval.expression) = (yyvsp[0].expression);
        } else {
          (yyval.expression)=new UnOp((yyloc), UOT_PLUS, (yyvsp[0].expression));
        }
      }
    break;

  case 201: /* expr: "-" expr  */
      { if ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression) = IntLit::a(-(yyvsp[0].expression)->cast<IntLit>()->v());
        } else if ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<FloatLit>()) {
          (yyval.expression) = FloatLit::a(-(yyvsp[0].expression)->cast<FloatLit>()->v());
        } else {
          (yyval.expression)=new UnOp((yyloc), UOT_MINUS, (yyvsp[0].expression));
        }
      }
    break;

  case 202: /* expr_atom_head: expr_atom_head_nonstring  */
      { (yyval.expression)=(yyvsp[0].expression); }
    break;

  case 203: /* expr_atom_head: string_expr  */
      { (yyval.expression)=(yyvsp[0].expression); }
    break;

  case 204: /* expr_atom_head_nonstring: '(' expr ')'  */
      { (yyval.expression)=(yyvsp[-1].expression); }
    break;

  case 205: /* expr_atom_head_nonstring: '(' expr ')' array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[0].expressions2d)); delete (yyvsp[0].expressions2d); }
    break;

  case 206: /* expr_atom_head_nonstring: '(' expr ')' "^-1"  */
      { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 207: /* expr_atom_head_nonstring: '(' expr ')' array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-3].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1)); delete (yyvsp[-1].expressions2d); }
    break;

  case 208: /* expr_atom_head_nonstring: "identifier"  */
      { (yyval.expression)=new Id((yyloc), (yyvsp[0].sValue), nullptr); free((yyvsp[0].sValue)); }
    break;

  case 209: /* expr_atom_head_nonstring: "identifier" array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), new Id((yylsp[-1]),(yyvsp[-1].sValue),nullptr), *(yyvsp[0].expressions2d));
        free((yyvsp[-1].sValue)); delete (yyvsp[0].expressions2d); }
    break;

  case 210: /* expr_atom_head_nonstring: "identifier" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),new Id((yyloc), (yyvsp[-1].sValue), nullptr), BOT_POW, IntLit::a(-1)); free((yyvsp[-1].sValue)); }
    break;

  case 211: /* expr_atom_head_nonstring: "identifier" array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), new Id((yylsp[-2]),(yyvsp[-2].sValue),nullptr), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        free((yyvsp[-2].sValue)); delete (yyvsp[-1].expressions2d); }
    break;

  case 212: /* expr_atom_head_nonstring: "_"  */
      { (yyval.expression)=new AnonVar((yyloc)); }
    break;

  case 213: /* expr_atom_head_nonstring: "_" array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), new AnonVar((yyloc)), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 214: /* expr_atom_head_nonstring: "_" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),new AnonVar((yyloc)), BOT_POW, IntLit::a(-1)); }
    break;

  case 215: /* expr_atom_head_nonstring: "_" array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), new AnonVar((yyloc)), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 216: /* expr_atom_head_nonstring: "bool literal"  */
      { (yyval.expression)=Constants::constants().boollit(((yyvsp[0].iValue)!=0)); }
    break;

  case 217: /* expr_atom_head_nonstring: "bool literal" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),Constants::constants().boollit(((yyvsp[-1].iValue)!=0)), BOT_POW, IntLit::a(-1)); }
    break;

  case 218: /* expr_atom_head_nonstring: "integer literal"  */
      { (yyval.expression)=IntLit::a((yyvsp[0].iValue)); }
    break;

  case 219: /* expr_atom_head_nonstring: "integer literal" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),IntLit::a((yyvsp[-1].iValue)), BOT_POW, IntLit::a(-1)); }
    break;

  case 220: /* expr_atom_head_nonstring: "infinity"  */
      { (yyval.expression)=IntLit::a(IntVal::infinity()); }
    break;

  case 221: /* expr_atom_head_nonstring: "infinity" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),IntLit::a(IntVal::infinity()), BOT_POW, IntLit::a(-1)); }
    break;

  case 222: /* expr_atom_head_nonstring: "float literal"  */
      { (yyval.expression)=FloatLit::a((yyvsp[0].dValue)); }
    break;

  case 223: /* expr_atom_head_nonstring: "float literal" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),FloatLit::a((yyvsp[-1].dValue)), BOT_POW, IntLit::a(-1)); }
    break;

  case 224: /* expr_atom_head_nonstring: "<>"  */
      { (yyval.expression)=Constants::constants().absent; }
    break;

  case 225: /* expr_atom_head_nonstring: "<>" "^-1"  */
      { (yyval.expression)=Constants::constants().absent; }
    break;

  case 227: /* expr_atom_head_nonstring: set_literal array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 228: /* expr_atom_head_nonstring: set_literal "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 229: /* expr_atom_head_nonstring: set_literal array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 231: /* expr_atom_head_nonstring: set_comp array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 232: /* expr_atom_head_nonstring: set_comp "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 233: /* expr_atom_head_nonstring: set_comp array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 235: /* expr_atom_head_nonstring: simple_array_literal array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 236: /* expr_atom_head_nonstring: simple_array_literal "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 237: /* expr_atom_head_nonstring: simple_array_literal array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 239: /* expr_atom_head_nonstring: simple_array_literal_2d array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 240: /* expr_atom_head_nonstring: simple_array_literal_2d "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 241: /* expr_atom_head_nonstring: simple_array_literal_2d array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 243: /* expr_atom_head_nonstring: simple_array_comp array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 244: /* expr_atom_head_nonstring: simple_array_comp "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 245: /* expr_atom_head_nonstring: simple_array_comp array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 247: /* expr_atom_head_nonstring: if_then_else_expr array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 248: /* expr_atom_head_nonstring: if_then_else_expr "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 249: /* expr_atom_head_nonstring: if_then_else_expr array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 252: /* expr_atom_head_nonstring: call_expr array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 254: /* expr_atom_head_nonstring: call_expr array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 255: /* string_expr: "string literal"  */
      { (yyval.expression)=new StringLit((yyloc), (yyvsp[0].sValue)); free((yyvsp[0].sValue)); }
    break;

  case 256: /* string_expr: "interpolated string start" string_quote_rest  */
      { (yyval.expression)=new BinOp((yyloc), new StringLit((yyloc), (yyvsp[-1].sValue)), BOT_PLUSPLUS, (yyvsp[0].expression));
        free((yyvsp[-1].sValue));
      }
    break;

  case 257: /* string_quote_rest: expr_list_head "interpolated string end"  */
      { if ((yyvsp[-1].expressions1d)) (yyval.expression)=new BinOp((yyloc), new Call((yyloc), ASTString("format"), *(yyvsp[-1].expressions1d)), BOT_PLUSPLUS, new StringLit((yyloc),(yyvsp[0].sValue)));
        free((yyvsp[0].sValue));
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 258: /* string_quote_rest: expr_list_head "interpolated string middle" string_quote_rest  */
      { if ((yyvsp[-2].expressions1d)) (yyval.expression)=new BinOp((yyloc), new Call((yyloc), ASTString("format"), *(yyvsp[-2].expressions1d)), BOT_PLUSPLUS,
                             new BinOp((yyloc), new StringLit((yyloc),(yyvsp[-1].sValue)), BOT_PLUSPLUS, (yyvsp[0].expression)));
        free((yyvsp[-1].sValue));
        delete (yyvsp[-2].expressions1d);
      }
    break;

  case 259: /* array_access_tail: "[" array_access_expr_list "]"  */
      { (yyval.expressions2d)=new std::vector<std::vector<Expression*> >();
        if ((yyvsp[-1].expressions1d)) {
          (yyval.expressions2d)->push_back(*(yyvsp[-1].expressions1d));
          delete (yyvsp[-1].expressions1d);
        }
      }
    break;

  case 260: /* array_access_tail: array_access_tail "[" array_access_expr_list "]"  */
      { (yyval.expressions2d)=(yyvsp[-3].expressions2d);
        if ((yyval.expressions2d) && (yyvsp[-1].expressions1d)) {
          (yyval.expressions2d)->push_back(*(yyvsp[-1].expressions1d));
          delete (yyvsp[-1].expressions1d);
        }
      }
    break;

  case 261: /* set_literal: '{' '}'  */
      { (yyval.expression) = new SetLit((yyloc), std::vector<Expression*>()); }
    break;

  case 262: /* set_literal: '{' expr_list '}'  */
      { if ((yyvsp[-1].expressions1d)) (yyval.expression) = new SetLit((yyloc), *(yyvsp[-1].expressions1d));
        delete (yyvsp[-1].expressions1d); }
    break;

  case 263: /* set_comp: '{' expr '|' comp_tail '}'  */
      { if ((yyvsp[-1].generatorsPointer)) (yyval.expression) = new Comprehension((yyloc), (yyvsp[-3].expression), *(yyvsp[-1].generatorsPointer), true);
        delete (yyvsp[-1].generatorsPointer);
      }
    break;

  case 264: /* comp_tail: generator_list  */
      { if ((yyvsp[0].generators)) (yyval.generatorsPointer)=new Generators; (yyval.generatorsPointer)->g = *(yyvsp[0].generators); delete (yyvsp[0].generators); }
    break;

  case 266: /* generator_list_head: generator  */
      { (yyval.generators)=new std::vector<Generator>; if ((yyvsp[0].generator)) (yyval.generators)->push_back(*(yyvsp[0].generator)); delete (yyvsp[0].generator); }
    break;

  case 267: /* generator_list_head: generator_eq  */
      { (yyval.generators)=new std::vector<Generator>; if ((yyvsp[0].generator)) (yyval.generators)->push_back(*(yyvsp[0].generator)); delete (yyvsp[0].generator); }
    break;

  case 268: /* generator_list_head: generator_eq "where" expr  */
      { (yyval.generators)=new std::vector<Generator>;
        if ((yyvsp[-2].generator)) (yyval.generators)->push_back(*(yyvsp[-2].generator));
        if ((yyvsp[-2].generator) && (yyvsp[0].expression)) (yyval.generators)->push_back(Generator((yyval.generators)->size(),(yyvsp[0].expression)));
        delete (yyvsp[-2].generator);
      }
    break;

  case 269: /* generator_list_head: generator_list_head ',' generator  */
      { (yyval.generators)=(yyvsp[-2].generators); if ((yyval.generators) && (yyvsp[0].generator)) (yyval.generators)->push_back(*(yyvsp[0].generator)); delete (yyvsp[0].generator); }
    break;

  case 270: /* generator_list_head: generator_list_head ',' generator_eq  */
      { (yyval.generators)=(yyvsp[-2].generators); if ((yyval.generators) && (yyvsp[0].generator)) (yyval.generators)->push_back(*(yyvsp[0].generator)); delete (yyvsp[0].generator); }
    break;

  case 271: /* generator_list_head: generator_list_head ',' generator_eq "where" expr  */
      { (yyval.generators)=(yyvsp[-4].generators);
        if ((yyval.generators) && (yyvsp[-2].generator)) (yyval.generators)->push_back(*(yyvsp[-2].generator));
        if ((yyval.generators) && (yyvsp[-2].generator) && (yyvsp[0].expression)) (yyval.generators)->push_back(Generator((yyval.generators)->size(),(yyvsp[0].expression)));
        delete (yyvsp[-2].generator);
      }
    break;

  case 272: /* generator: id_list "in" expr  */
      { if ((yyvsp[-2].strings) && (yyvsp[0].expression)) (yyval.generator)=new Generator(*(yyvsp[-2].strings),(yyvsp[0].expression),nullptr); else (yyval.generator)=nullptr; delete (yyvsp[-2].strings); }
    break;

  case 273: /* generator: id_list "in" expr "where" expr  */
      { if ((yyvsp[-4].strings) && (yyvsp[-2].expression)) (yyval.generator)=new Generator(*(yyvsp[-4].strings),(yyvsp[-2].expression),(yyvsp[0].expression)); else (yyval.generator)=nullptr; delete (yyvsp[-4].strings); }
    break;

  case 274: /* generator_eq: "identifier" "=" expr  */
      { if ((yyvsp[0].expression)) (yyval.generator)=new Generator({(yyvsp[-2].sValue)},nullptr,(yyvsp[0].expression)); else (yyval.generator)=nullptr; free((yyvsp[-2].sValue)); }
    break;

  case 276: /* id_list_head: "identifier"  */
      { (yyval.strings)=new std::vector<std::string>; (yyval.strings)->push_back((yyvsp[0].sValue)); free((yyvsp[0].sValue)); }
    break;

  case 277: /* id_list_head: id_list_head ',' "identifier"  */
      { (yyval.strings)=(yyvsp[-2].strings); if ((yyval.strings) && (yyvsp[0].sValue)) (yyval.strings)->push_back((yyvsp[0].sValue)); free((yyvsp[0].sValue)); }
    break;

  case 278: /* simple_array_literal: "[" "]"  */
      { (yyval.expression)=new ArrayLit((yyloc), std::vector<MiniZinc::Expression*>()); }
    break;

  case 279: /* simple_array_literal: "[" comp_expr_list "]"  */
      { if ((yyvsp[-1].indexedexpression2d)) {
          if ((yyvsp[-1].indexedexpression2d)->first.empty()) {
            (yyval.expression)=new ArrayLit((yyloc), (yyvsp[-1].indexedexpression2d)->second);
          } else {
            (yyval.expression)=new Call((yyloc), "array1d", {new ArrayLit((yyloc), (yyvsp[-1].indexedexpression2d)->first), new ArrayLit((yyloc), (yyvsp[-1].indexedexpression2d)->second)});
          }
          delete (yyvsp[-1].indexedexpression2d);
        }
      }
    break;

  case 280: /* simple_array_literal_2d: "[|" "|]"  */
      { (yyval.expression)=new ArrayLit((yyloc), std::vector<std::vector<Expression*> >()); }
    break;

  case 281: /* simple_array_literal_2d: "[|" simple_array_literal_2d_indexed_list "|]"  */
      { if ((yyvsp[-1].indexedexpressions2d)) {
          std::vector<std::vector<Expression*>> v((yyvsp[-1].indexedexpressions2d)->size());
          std::vector<Expression*> columnHeader;
          std::vector<Expression*> rowHeader;
          bool hadHeaderRow = false;
          for (unsigned int i = 0; i < (yyvsp[-1].indexedexpressions2d)->size(); i++) {
            if (i == 0 && (*(yyvsp[-1].indexedexpressions2d))[i].second.empty() && !(*(yyvsp[-1].indexedexpressions2d))[i].first.empty()) {
              hadHeaderRow = true;
              columnHeader = (*(yyvsp[-1].indexedexpressions2d))[i].first;
              v.resize(v.size()-1);
              continue;
            }
            if (i > 0 && (*(yyvsp[-1].indexedexpressions2d))[i].second.size() != (*(yyvsp[-1].indexedexpressions2d))[i-1].second.size()) {
              if (i == 1 && hadHeaderRow) {
                if ((*(yyvsp[-1].indexedexpressions2d))[i].second.size() != (*(yyvsp[-1].indexedexpressions2d))[i-1].first.size()) {
                  yyerror(&(yylsp[-1]), parm, "syntax error, sub-array of 2d array literal has different length from index row");
                }
              } else {
                yyerror(&(yylsp[-1]), parm, "syntax error, all sub-arrays of 2d array literal must have the same length");
              }
            }
            if (i > hadHeaderRow && (*(yyvsp[-1].indexedexpressions2d))[i].first.size() != (*(yyvsp[-1].indexedexpressions2d))[i-1].first.size()) {
              yyerror(&(yylsp[-1]), parm, "syntax error, mixing indexed and non-indexed sub-arrays in 2d array literal");
            }
            if (i >= hadHeaderRow && !(*(yyvsp[-1].indexedexpressions2d))[i].first.empty()) {
              rowHeader.push_back((*(yyvsp[-1].indexedexpressions2d))[i].first[0]);
            }
            for (unsigned int j = 0; j < (*(yyvsp[-1].indexedexpressions2d))[i].second.size(); j++) {
              v[i - hadHeaderRow].push_back((*(yyvsp[-1].indexedexpressions2d))[i].second[j]);
            }
          }
          if (columnHeader.empty() && rowHeader.empty()) {
            (yyval.expression)=new ArrayLit((yyloc), v);
          } else {
            std::vector<Expression*> vv;
            for (auto& row : v) {
              for (auto* e : row) {
                vv.push_back(e);
              }
            }
            if (rowHeader.empty()) {
              auto nRows = vv.size() / columnHeader.size();
              rowHeader.resize(nRows);
              for (unsigned int i = 0; i < nRows; i++) {
                rowHeader[i] = IntLit::a(i+1);
              }
            } else if (columnHeader.empty()) {
              auto nCols = vv.size() / rowHeader.size();
              columnHeader.resize(nCols);
              for (unsigned int i = 0; i < nCols; i++) {
                columnHeader[i] = IntLit::a(i+1);
              }
            }
            (yyval.expression)=new Call((yyloc), "array2d", {new ArrayLit((yyloc), rowHeader), new ArrayLit((yyloc), columnHeader), new ArrayLit((yyloc), vv)});
          }
          delete (yyvsp[-1].indexedexpressions2d);
        } else {
          (yyval.expression) = nullptr;
        }
      }
    break;

  case 282: /* simple_array_literal_2d: "[|" simple_array_literal_3d_list "|]"  */
    {
      if ((yyvsp[-1].expressions3d)) {
        std::vector<std::pair<int,int> > dims(3);
        dims[0] = std::pair<int,int>(1,static_cast<int>((yyvsp[-1].expressions3d)->size()));
        if ((yyvsp[-1].expressions3d)->size()==0) {
          dims[1] = std::pair<int,int>(1,0);
          dims[2] = std::pair<int,int>(1,0);
        } else {
          dims[1] = std::pair<int,int>(1,static_cast<int>((*(yyvsp[-1].expressions3d))[0].size()));
          if ((*(yyvsp[-1].expressions3d))[0].size()==0) {
            dims[2] = std::pair<int,int>(1,0);
          } else {
            dims[2] = std::pair<int,int>(1,static_cast<int>((*(yyvsp[-1].expressions3d))[0][0].size()));
          }
        }
        std::vector<Expression*> a;
        for (int i=0; i<dims[0].second; i++) {
          if ((*(yyvsp[-1].expressions3d))[i].size() != dims[1].second) {
            yyerror(&(yylsp[-1]), parm, "syntax error, all sub-arrays of 3d array literal must have the same length");
          } else {
            for (int j=0; j<dims[1].second; j++) {
              if ((*(yyvsp[-1].expressions3d))[i][j].size() != dims[2].second) {
                yyerror(&(yylsp[-1]), parm, "syntax error, all sub-arrays of 3d array literal must have the same length");
              } else {
                for (int k=0; k<dims[2].second; k++) {
                  a.push_back((*(yyvsp[-1].expressions3d))[i][j][k]);
                }
              }
            }
          }
        }
        (yyval.expression) = new ArrayLit((yyloc),a,dims);
        delete (yyvsp[-1].expressions3d);
      } else {
        (yyval.expression) = nullptr;
      }
    }
    break;

  case 283: /* simple_array_literal_3d_list: '|' '|'  */
      { (yyval.expressions3d)=new std::vector<std::vector<std::vector<MiniZinc::Expression*> > >;
      }
    break;

  case 284: /* simple_array_literal_3d_list: '|' simple_array_literal_2d_list '|'  */
      { (yyval.expressions3d)=new std::vector<std::vector<std::vector<MiniZinc::Expression*> > >;
        if ((yyvsp[-1].expressions2d)) (yyval.expressions3d)->push_back(*(yyvsp[-1].expressions2d));
        delete (yyvsp[-1].expressions2d);
      }
    break;

  case 285: /* simple_array_literal_3d_list: simple_array_literal_3d_list ',' '|' simple_array_literal_2d_list '|'  */
      { (yyval.expressions3d)=(yyvsp[-4].expressions3d);
        if ((yyval.expressions3d) && (yyvsp[-1].expressions2d)) (yyval.expressions3d)->push_back(*(yyvsp[-1].expressions2d));
        delete (yyvsp[-1].expressions2d);
      }
    break;

  case 286: /* simple_array_literal_2d_list: expr_list  */
      { (yyval.expressions2d)=new std::vector<std::vector<MiniZinc::Expression*> >;
        if ((yyvsp[0].expressions1d)) (yyval.expressions2d)->push_back(*(yyvsp[0].expressions1d));
        delete (yyvsp[0].expressions1d);
      }
    break;

  case 287: /* simple_array_literal_2d_list: simple_array_literal_2d_list '|' expr_list  */
      { (yyval.expressions2d)=(yyvsp[-2].expressions2d); if ((yyval.expressions2d) && (yyvsp[0].expressions1d)) (yyval.expressions2d)->push_back(*(yyvsp[0].expressions1d)); delete (yyvsp[0].expressions1d); }
    break;

  case 289: /* simple_array_literal_2d_indexed_list_head: simple_array_literal_2d_indexed_list_row  */
      { (yyval.indexedexpressions2d)=new std::vector<std::pair<std::vector<MiniZinc::Expression*>,std::vector<MiniZinc::Expression*>>>();
        if ((yyvsp[0].indexedexpression2d)) {
          if ((yyvsp[0].indexedexpression2d)->first.size() > 1 || ((yyvsp[0].indexedexpression2d)->first.size() == 1 && (yyvsp[0].indexedexpression2d)->second.empty())) {
            yyerror(&(yyloc),parm,"invalid array literal, mixing indexes and values");
          }
          (yyval.indexedexpressions2d)->push_back(*(yyvsp[0].indexedexpression2d));
          delete (yyvsp[0].indexedexpression2d);
        }
      }
    break;

  case 290: /* simple_array_literal_2d_indexed_list_head: simple_array_literal_2d_indexed_list_row_head ':'  */
      { (yyval.indexedexpressions2d)=new std::vector<std::pair<std::vector<MiniZinc::Expression*>,std::vector<MiniZinc::Expression*>>>();
        if ((yyvsp[-1].indexedexpression2d)) {
          if ((yyvsp[-1].indexedexpression2d)->second.size() != 1) {
            yyerror(&(yyloc),parm,"invalid array literal, mixing indexes and values");
          }
          (yyvsp[-1].indexedexpression2d)->first.push_back((yyvsp[-1].indexedexpression2d)->second.back());
          (yyvsp[-1].indexedexpression2d)->second.pop_back();
          (yyval.indexedexpressions2d)->push_back(*(yyvsp[-1].indexedexpression2d));
          delete (yyvsp[-1].indexedexpression2d);
        }
      }
    break;

  case 291: /* simple_array_literal_2d_indexed_list_head: simple_array_literal_2d_indexed_list_head '|' simple_array_literal_2d_indexed_list_row  */
      { (yyval.indexedexpressions2d)=(yyvsp[-2].indexedexpressions2d);
        if ((yyval.indexedexpressions2d) && (yyvsp[0].indexedexpression2d)) {
          if ((yyvsp[0].indexedexpression2d)->first.size() > 1 || ((yyvsp[0].indexedexpression2d)->first.size() == 1 && (yyvsp[0].indexedexpression2d)->second.empty())) {
            yyerror(&(yylsp[0]),parm,"invalid array literal, mixing indexes and values");
          }
          (yyval.indexedexpressions2d)->push_back(*(yyvsp[0].indexedexpression2d));
          delete (yyvsp[0].indexedexpression2d);
        }
      }
    break;

  case 293: /* simple_array_literal_2d_indexed_list_row_head: expr  */
      { (yyval.indexedexpression2d)=new std::pair<std::vector<MiniZinc::Expression*>,std::vector<MiniZinc::Expression*>>();
        (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression));
      }
    break;

  case 294: /* simple_array_literal_2d_indexed_list_row_head: simple_array_literal_2d_indexed_list_row_head ':' expr  */
      { (yyval.indexedexpression2d)=(yyvsp[-2].indexedexpression2d);
        if ((yyval.indexedexpression2d)) {
          if ((yyval.indexedexpression2d)->second.size() != 1) {
            yyerror(&(yyloc),parm,"invalid array literal, mixing indexes and values");
          }
          (yyval.indexedexpression2d)->first.push_back((yyval.indexedexpression2d)->second.back());
          (yyval.indexedexpression2d)->second.pop_back();
          (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression));
        }
      }
    break;

  case 295: /* simple_array_literal_2d_indexed_list_row_head: simple_array_literal_2d_indexed_list_row_head ',' expr  */
      { (yyval.indexedexpression2d)=(yyvsp[-2].indexedexpression2d);
        if ((yyval.indexedexpression2d)) {
          if ((yyval.indexedexpression2d)->second.empty()) {
            yyerror(&(yyloc),parm,"invalid array literal, mixing indexes and values");
          }
          (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression));
        }
      }
    break;

  case 296: /* simple_array_comp: "[" comp_expr ':' expr '|' comp_tail "]"  */
      { if ((yyvsp[-5].expression) && (yyvsp[-1].generatorsPointer)) {
          std::vector<Expression*> tv;
          if (auto* al = Expression::dynamicCast<ArrayLit>((yyvsp[-5].expression))) {
            for (unsigned int i=0; i<al->size(); i++) {
              tv.push_back((*al)[i]);
            }
          } else {
            tv.push_back((yyvsp[-5].expression));
          }          
          tv.push_back((yyvsp[-3].expression));
          auto* t = ArrayLit::constructTuple((yyloc),tv);
          (yyval.expression)=new Comprehension((yyloc), t, *(yyvsp[-1].generatorsPointer), false);
          delete (yyvsp[-1].generatorsPointer);
        }
      }
    break;

  case 297: /* simple_array_comp: "[" comp_expr '|' comp_tail "]"  */
      { if ((yyvsp[-1].generatorsPointer) && noTuple((yylsp[-3]),parm,(yyvsp[-3].expression))) (yyval.expression)=new Comprehension((yyloc), (yyvsp[-3].expression), *(yyvsp[-1].generatorsPointer), false);
        delete (yyvsp[-1].generatorsPointer);
      }
    break;

  case 299: /* comp_expr: comp_expr "::" annotation_expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression)) && (yyvsp[0].expression)) (yyvsp[-2].expression)->addAnnotation((yyvsp[0].expression)); (yyval.expression)=(yyvsp[-2].expression); }
    break;

  case 300: /* comp_expr: comp_expr "<->" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_EQUIV, (yyvsp[0].expression)); } }
    break;

  case 301: /* comp_expr: comp_expr "->" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IMPL, (yyvsp[0].expression)); } }
    break;

  case 302: /* comp_expr: comp_expr "<-" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_RIMPL, (yyvsp[0].expression)); } }
    break;

  case 303: /* comp_expr: comp_expr "\\/" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_OR, (yyvsp[0].expression)); } }
    break;

  case 304: /* comp_expr: comp_expr "xor" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_XOR, (yyvsp[0].expression)); } }
    break;

  case 305: /* comp_expr: comp_expr "/\\" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_AND, (yyvsp[0].expression)); } }
    break;

  case 306: /* comp_expr: comp_expr "<" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_LE, (yyvsp[0].expression)); } }
    break;

  case 307: /* comp_expr: comp_expr ">" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_GR, (yyvsp[0].expression)); } }
    break;

  case 308: /* comp_expr: comp_expr "<=" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_LQ, (yyvsp[0].expression)); } }
    break;

  case 309: /* comp_expr: comp_expr ">=" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_GQ, (yyvsp[0].expression)); } }
    break;

  case 310: /* comp_expr: comp_expr "=" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_EQ, (yyvsp[0].expression)); } }
    break;

  case 311: /* comp_expr: comp_expr "!=" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_NQ, (yyvsp[0].expression)); } }
    break;

  case 312: /* comp_expr: comp_expr "in" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IN, (yyvsp[0].expression)); } }
    break;

  case 313: /* comp_expr: comp_expr "subset" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SUBSET, (yyvsp[0].expression)); } }
    break;

  case 314: /* comp_expr: comp_expr "superset" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SUPERSET, (yyvsp[0].expression)); } }
    break;

  case 315: /* comp_expr: comp_expr "union" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_UNION, (yyvsp[0].expression)); } }
    break;

  case 316: /* comp_expr: comp_expr "diff" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DIFF, (yyvsp[0].expression)); } }
    break;

  case 317: /* comp_expr: comp_expr "symdiff" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_SYMDIFF, (yyvsp[0].expression)); } }
    break;

  case 318: /* comp_expr: comp_expr ".." expr  */
      { if (!noTuple((yylsp[-2]),parm,(yyvsp[-2].expression)) || (yyvsp[-2].expression)==nullptr || (yyvsp[0].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-2].expression)->isa<IntLit>() && (yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-2].expression)->cast<IntLit>()->v(),(yyvsp[0].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DOTDOT, (yyvsp[0].expression));
        }
      }
    break;

  case 319: /* comp_expr: comp_expr "..<" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new Call((yyloc), ASTString("'..<'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); } }
    break;

  case 320: /* comp_expr: comp_expr "<.." expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new Call((yyloc), ASTString("'<..'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); } }
    break;

  case 321: /* comp_expr: comp_expr "<..<" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new Call((yyloc), ASTString("'<..<'"), {(yyvsp[-2].expression), (yyvsp[0].expression)}); } }
    break;

  case 322: /* comp_expr: "'..<'" '(' expr ',' expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'..<'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 323: /* comp_expr: "'<..'" '(' expr ',' expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 324: /* comp_expr: "'<..<'" '(' expr ',' expr ')'  */
      { (yyval.expression)=new Call((yyloc), ASTString("'<..<'"), {(yyvsp[-3].expression), (yyvsp[-1].expression)}); }
    break;

  case 325: /* comp_expr: "'..'" '(' expr ',' expr ')'  */
      { if ((yyvsp[-3].expression)==nullptr || (yyvsp[-1].expression)==nullptr) {
          (yyval.expression) = nullptr;
        } else if ((yyvsp[-3].expression)->isa<IntLit>() && (yyvsp[-1].expression)->isa<IntLit>()) {
          (yyval.expression)=new SetLit((yyloc), IntSetVal::a((yyvsp[-3].expression)->cast<IntLit>()->v(),(yyvsp[-1].expression)->cast<IntLit>()->v()));
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-3].expression), BOT_DOTDOT, (yyvsp[-1].expression));
        }
      }
    break;

  case 326: /* comp_expr: comp_expr "intersect" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_INTERSECT, (yyvsp[0].expression)); } }
    break;

  case 327: /* comp_expr: comp_expr "++" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_PLUSPLUS, (yyvsp[0].expression)); } }
    break;

  case 328: /* comp_expr: comp_expr "+" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_PLUS, (yyvsp[0].expression)); } }
    break;

  case 329: /* comp_expr: comp_expr "-" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MINUS, (yyvsp[0].expression)); } }
    break;

  case 330: /* comp_expr: comp_expr "*" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MULT, (yyvsp[0].expression)); } }
    break;

  case 331: /* comp_expr: comp_expr "/" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_DIV, (yyvsp[0].expression)); } }
    break;

  case 332: /* comp_expr: comp_expr "div" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_IDIV, (yyvsp[0].expression)); } }
    break;

  case 333: /* comp_expr: comp_expr "mod" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_MOD, (yyvsp[0].expression)); } }
    break;

  case 334: /* comp_expr: comp_expr "^" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) { (yyval.expression)=new BinOp((yyloc), (yyvsp[-2].expression), BOT_POW, (yyvsp[0].expression)); } }
    break;

  case 335: /* comp_expr: comp_expr "~+" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~+"), args);
        }
      }
    break;

  case 336: /* comp_expr: comp_expr "~-" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~-"), args);
        }
      }
    break;

  case 337: /* comp_expr: comp_expr "~*" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~*"), args);
        }
      }
    break;

  case 338: /* comp_expr: comp_expr "~/" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~/"), args);
        }
      }
    break;

  case 339: /* comp_expr: comp_expr "~div" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~div"), args);
        }
      }
    break;

  case 340: /* comp_expr: comp_expr "~=" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~="), args);
        }
      }
    break;

  case 341: /* comp_expr: comp_expr "~!=" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("~!="), args);
        }
      }
    break;

  case 342: /* comp_expr: comp_expr "default" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), ASTString("default"), args);
        }
      }
    break;

  case 343: /* comp_expr: comp_expr "quoted identifier" expr  */
      { if (noTuple((yylsp[-2]),parm,(yyvsp[-2].expression))) {
          vector<Expression*> args;
          args.push_back((yyvsp[-2].expression)); args.push_back((yyvsp[0].expression));
          (yyval.expression)=new Call((yyloc), (yyvsp[-1].sValue), args);
          free((yyvsp[-1].sValue));
        }
      }
    break;

  case 344: /* comp_expr: "not" expr  */
      { (yyval.expression)=new UnOp((yyloc), UOT_NOT, (yyvsp[0].expression)); }
    break;

  case 345: /* comp_expr: "+" expr  */
      { if (((yyvsp[0].expression) && (yyvsp[0].expression)->isa<IntLit>()) || ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<FloatLit>())) {
          (yyval.expression) = (yyvsp[0].expression);
        } else {
          (yyval.expression)=new UnOp((yyloc), UOT_PLUS, (yyvsp[0].expression));
        }
      }
    break;

  case 346: /* comp_expr: "-" expr  */
      { if ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<IntLit>()) {
          (yyval.expression) = IntLit::a(-(yyvsp[0].expression)->cast<IntLit>()->v());
        } else if ((yyvsp[0].expression) && (yyvsp[0].expression)->isa<FloatLit>()) {
          (yyval.expression) = FloatLit::a(-(yyvsp[0].expression)->cast<FloatLit>()->v());
        } else {
          (yyval.expression)=new UnOp((yyloc), UOT_MINUS, (yyvsp[0].expression));
        }
      }
    break;

  case 347: /* comp_expr_atom_head: comp_expr_atom_head_nonstring  */
      { (yyval.expression)=(yyvsp[0].expression); }
    break;

  case 348: /* comp_expr_atom_head: string_expr  */
      { (yyval.expression)=(yyvsp[0].expression); }
    break;

  case 349: /* comp_expr_atom_head_nonstring: '(' expr_list ')'  */
      { if ((yyvsp[-1].expressions1d)) {
          if ((yyvsp[-1].expressions1d)->size()==1) {
            (yyval.expression) = (*(yyvsp[-1].expressions1d))[0];
          } else {
            (yyval.expression) = ArrayLit::constructTuple((yyloc), *(yyvsp[-1].expressions1d));
          }
        }
        delete (yyvsp[-1].expressions1d);
      }
    break;

  case 350: /* comp_expr_atom_head_nonstring: '(' expr_list ')' array_access_tail  */
      { if ((yyvsp[-2].expressions1d) && (yyvsp[-2].expressions1d)->size() != 1) {
          delete (yyvsp[-2].expressions1d);
          yyerror(&(yylsp[-2]), parm, "tuple not supported");
        } else {
          if ((yyvsp[-2].expressions1d) && (yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (*(yyvsp[-2].expressions1d))[0], *(yyvsp[0].expressions2d)); delete (yyvsp[0].expressions2d); delete (yyvsp[-2].expressions1d);
        }
      }
    break;

  case 351: /* comp_expr_atom_head_nonstring: '(' expr_list ')' "^-1"  */
      { if ((yyvsp[-2].expressions1d) && (yyvsp[-2].expressions1d)->size() != 1) {
          delete (yyvsp[-2].expressions1d);
          yyerror(&(yylsp[-2]), parm, "tuple not supported");
        } else {
          (yyval.expression)=new BinOp((yyloc), (*(yyvsp[-2].expressions1d))[0], BOT_POW, IntLit::a(-1));
          delete (yyvsp[-2].expressions1d);
        }
      }
    break;

  case 352: /* comp_expr_atom_head_nonstring: '(' expr_list ')' array_access_tail "^-1"  */
      { if ((yyvsp[-3].expressions1d) && (yyvsp[-3].expressions1d)->size() != 1) {
          delete (yyvsp[-3].expressions1d);
          yyerror(&(yylsp[-3]), parm, "tuple not supported");
        } else {
          if ((yyvsp[-3].expressions1d) && (yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (*(yyvsp[-3].expressions1d))[0], *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
          delete (yyvsp[-1].expressions2d);
          delete (yyvsp[-3].expressions1d);
        }
      }
    break;

  case 353: /* comp_expr_atom_head_nonstring: "identifier"  */
      { (yyval.expression)=new Id((yyloc), (yyvsp[0].sValue), nullptr); free((yyvsp[0].sValue)); }
    break;

  case 354: /* comp_expr_atom_head_nonstring: "identifier" array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), new Id((yylsp[-1]),(yyvsp[-1].sValue),nullptr), *(yyvsp[0].expressions2d));
        free((yyvsp[-1].sValue)); delete (yyvsp[0].expressions2d); }
    break;

  case 355: /* comp_expr_atom_head_nonstring: "identifier" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),new Id((yyloc), (yyvsp[-1].sValue), nullptr), BOT_POW, IntLit::a(-1)); free((yyvsp[-1].sValue)); }
    break;

  case 356: /* comp_expr_atom_head_nonstring: "identifier" array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), new Id((yylsp[-2]),(yyvsp[-2].sValue),nullptr), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        free((yyvsp[-2].sValue)); delete (yyvsp[-1].expressions2d); }
    break;

  case 357: /* comp_expr_atom_head_nonstring: "_"  */
      { (yyval.expression)=new AnonVar((yyloc)); }
    break;

  case 358: /* comp_expr_atom_head_nonstring: "_" array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), new AnonVar((yyloc)), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 359: /* comp_expr_atom_head_nonstring: "_" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),new AnonVar((yyloc)), BOT_POW, IntLit::a(-1)); }
    break;

  case 360: /* comp_expr_atom_head_nonstring: "_" array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), new AnonVar((yyloc)), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 361: /* comp_expr_atom_head_nonstring: "bool literal"  */
      { (yyval.expression)=Constants::constants().boollit(((yyvsp[0].iValue)!=0)); }
    break;

  case 362: /* comp_expr_atom_head_nonstring: "bool literal" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),Constants::constants().boollit(((yyvsp[-1].iValue)!=0)), BOT_POW, IntLit::a(-1)); }
    break;

  case 363: /* comp_expr_atom_head_nonstring: "integer literal"  */
      { (yyval.expression)=IntLit::a((yyvsp[0].iValue)); }
    break;

  case 364: /* comp_expr_atom_head_nonstring: "integer literal" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),IntLit::a((yyvsp[-1].iValue)), BOT_POW, IntLit::a(-1)); }
    break;

  case 365: /* comp_expr_atom_head_nonstring: "infinity"  */
      { (yyval.expression)=IntLit::a(IntVal::infinity()); }
    break;

  case 366: /* comp_expr_atom_head_nonstring: "infinity" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),IntLit::a(IntVal::infinity()), BOT_POW, IntLit::a(-1)); }
    break;

  case 367: /* comp_expr_atom_head_nonstring: "float literal"  */
      { (yyval.expression)=FloatLit::a((yyvsp[0].dValue)); }
    break;

  case 368: /* comp_expr_atom_head_nonstring: "float literal" "^-1"  */
      { (yyval.expression)=new BinOp((yyloc),FloatLit::a((yyvsp[-1].dValue)), BOT_POW, IntLit::a(-1)); }
    break;

  case 369: /* comp_expr_atom_head_nonstring: "<>"  */
      { (yyval.expression)=Constants::constants().absent; }
    break;

  case 370: /* comp_expr_atom_head_nonstring: "<>" "^-1"  */
      { (yyval.expression)=Constants::constants().absent; }
    break;

  case 372: /* comp_expr_atom_head_nonstring: set_literal array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 373: /* comp_expr_atom_head_nonstring: set_literal "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 374: /* comp_expr_atom_head_nonstring: set_literal array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 376: /* comp_expr_atom_head_nonstring: set_comp array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 377: /* comp_expr_atom_head_nonstring: set_comp "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 378: /* comp_expr_atom_head_nonstring: set_comp array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 380: /* comp_expr_atom_head_nonstring: simple_array_literal array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 381: /* comp_expr_atom_head_nonstring: simple_array_literal "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 382: /* comp_expr_atom_head_nonstring: simple_array_literal array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 384: /* comp_expr_atom_head_nonstring: simple_array_literal_2d array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 385: /* comp_expr_atom_head_nonstring: simple_array_literal_2d "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 386: /* comp_expr_atom_head_nonstring: simple_array_literal_2d array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 388: /* comp_expr_atom_head_nonstring: simple_array_comp array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 389: /* comp_expr_atom_head_nonstring: simple_array_comp "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 390: /* comp_expr_atom_head_nonstring: simple_array_comp array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 392: /* comp_expr_atom_head_nonstring: if_then_else_expr array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 393: /* comp_expr_atom_head_nonstring: if_then_else_expr "^-1"  */
      { (yyval.expression) = new BinOp((yyloc),(yyvsp[-1].expression), BOT_POW, IntLit::a(-1)); }
    break;

  case 394: /* comp_expr_atom_head_nonstring: if_then_else_expr array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=new BinOp((yyloc),createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d)), BOT_POW, IntLit::a(-1));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 397: /* comp_expr_atom_head_nonstring: call_expr array_access_tail  */
      { if ((yyvsp[0].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-1].expression), *(yyvsp[0].expressions2d));
        delete (yyvsp[0].expressions2d); }
    break;

  case 399: /* comp_expr_atom_head_nonstring: call_expr array_access_tail "^-1"  */
      { if ((yyvsp[-1].expressions2d)) (yyval.expression)=createArrayAccess((yyloc), (yyvsp[-2].expression), *(yyvsp[-1].expressions2d));
        delete (yyvsp[-1].expressions2d); }
    break;

  case 401: /* comp_expr_list_head: comp_expr  */
      { (yyval.indexedexpression2d)=new std::pair<std::vector<MiniZinc::Expression*>,std::vector<MiniZinc::Expression*>>;
        (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression)); }
    break;

  case 402: /* comp_expr_list_head: comp_expr ':' expr  */
      { (yyval.indexedexpression2d)=new std::pair<std::vector<MiniZinc::Expression*>,std::vector<MiniZinc::Expression*>>;
        (yyval.indexedexpression2d)->first.push_back((yyvsp[-2].expression));
        (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression)); }
    break;

  case 403: /* comp_expr_list_head: comp_expr_list_head ',' expr  */
      { (yyval.indexedexpression2d)=(yyvsp[-2].indexedexpression2d);
        if ((yyval.indexedexpression2d) && (yyvsp[0].expression)) {
          if (!(yyval.indexedexpression2d)->first.empty()) {
            yyerror(&(yyloc),parm,"invalid array literal, mixing indexed and non-indexed values");
          }
          (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression));
        }
      }
    break;

  case 404: /* comp_expr_list_head: comp_expr_list_head ',' expr ':' expr  */
      { (yyval.indexedexpression2d)=(yyvsp[-4].indexedexpression2d);
        if ((yyval.indexedexpression2d) && (yyvsp[-2].expression)) {
          if ((yyval.indexedexpression2d)->first.empty()) {
            yyerror(&(yyloc),parm,"invalid array literal, mixing indexed and non-indexed values");
          }
          (yyval.indexedexpression2d)->first.push_back((yyvsp[-2].expression));
          (yyval.indexedexpression2d)->second.push_back((yyvsp[0].expression));
        }
      }
    break;

  case 405: /* if_then_else_expr: "if" expr "then" expr "endif"  */
      {
        std::vector<Expression*> iexps;
        iexps.push_back((yyvsp[-3].expression));
        iexps.push_back((yyvsp[-1].expression));
        (yyval.expression)=new ITE((yyloc), iexps, nullptr);
      }
    break;

  case 406: /* if_then_else_expr: "if" expr "then" expr elseif_list "else" expr "endif"  */
      {
        std::vector<Expression*> iexps;
        iexps.push_back((yyvsp[-6].expression));
        iexps.push_back((yyvsp[-4].expression));
        if ((yyvsp[-3].expressions1d)) {
          for (unsigned int i=0; i<(yyvsp[-3].expressions1d)->size(); i+=2) {
            iexps.push_back((*(yyvsp[-3].expressions1d))[i]);
            iexps.push_back((*(yyvsp[-3].expressions1d))[i+1]);
          }
        }
        (yyval.expression)=new ITE((yyloc), iexps,(yyvsp[-1].expression));
        delete (yyvsp[-3].expressions1d);
      }
    break;

  case 407: /* elseif_list: %empty  */
      { (yyval.expressions1d)=new std::vector<MiniZinc::Expression*>; }
    break;

  case 408: /* elseif_list: elseif_list "elseif" expr "then" expr  */
      { (yyval.expressions1d)=(yyvsp[-4].expressions1d); if ((yyval.expressions1d) && (yyvsp[-2].expression) && (yyvsp[0].expression)) { (yyval.expressions1d)->push_back((yyvsp[-2].expression)); (yyval.expressions1d)->push_back((yyvsp[0].expression)); } }
    break;

  case 409: /* quoted_op: "'<->'"  */
      { (yyval.iValue)=BOT_EQUIV; }
    break;

  case 410: /* quoted_op: "'->'"  */
      { (yyval.iValue)=BOT_IMPL; }
    break;

  case 411: /* quoted_op: "'<-'"  */
      { (yyval.iValue)=BOT_RIMPL; }
    break;

  case 412: /* quoted_op: "'\\/'"  */
      { (yyval.iValue)=BOT_OR; }
    break;

  case 413: /* quoted_op: "'xor'"  */
      { (yyval.iValue)=BOT_XOR; }
    break;

  case 414: /* quoted_op: "'/\\'"  */
      { (yyval.iValue)=BOT_AND; }
    break;

  case 415: /* quoted_op: "'<'"  */
      { (yyval.iValue)=BOT_LE; }
    break;

  case 416: /* quoted_op: "'>'"  */
      { (yyval.iValue)=BOT_GR; }
    break;

  case 417: /* quoted_op: "'<='"  */
      { (yyval.iValue)=BOT_LQ; }
    break;

  case 418: /* quoted_op: "'>='"  */
      { (yyval.iValue)=BOT_GQ; }
    break;

  case 419: /* quoted_op: "'='"  */
      { (yyval.iValue)=BOT_EQ; }
    break;

  case 420: /* quoted_op: "'!='"  */
      { (yyval.iValue)=BOT_NQ; }
    break;

  case 421: /* quoted_op: "'in'"  */
      { (yyval.iValue)=BOT_IN; }
    break;

  case 422: /* quoted_op: "'subset'"  */
      { (yyval.iValue)=BOT_SUBSET; }
    break;

  case 423: /* quoted_op: "'superset'"  */
      { (yyval.iValue)=BOT_SUPERSET; }
    break;

  case 424: /* quoted_op: "'union'"  */
      { (yyval.iValue)=BOT_UNION; }
    break;

  case 425: /* quoted_op: "'diff'"  */
      { (yyval.iValue)=BOT_DIFF; }
    break;

  case 426: /* quoted_op: "'symdiff'"  */
      { (yyval.iValue)=BOT_SYMDIFF; }
    break;

  case 427: /* quoted_op: "'+'"  */
      { (yyval.iValue)=BOT_PLUS; }
    break;

  case 428: /* quoted_op: "'-'"  */
      { (yyval.iValue)=BOT_MINUS; }
    break;

  case 429: /* quoted_op: "'*'"  */
      { (yyval.iValue)=BOT_MULT; }
    break;

  case 430: /* quoted_op: "'^'"  */
      { (yyval.iValue)=BOT_POW; }
    break;

  case 431: /* quoted_op: "'/'"  */
      { (yyval.iValue)=BOT_DIV; }
    break;

  case 432: /* quoted_op: "'div'"  */
      { (yyval.iValue)=BOT_IDIV; }
    break;

  case 433: /* quoted_op: "'mod'"  */
      { (yyval.iValue)=BOT_MOD; }
    break;

  case 434: /* quoted_op: "'intersect'"  */
      { (yyval.iValue)=BOT_INTERSECT; }
    break;

  case 435: /* quoted_op: "'++'"  */
      { (yyval.iValue)=BOT_PLUSPLUS; }
    break;

  case 436: /* quoted_op: "'not'"  */
      { (yyval.iValue)=-1; }
    break;

  case 437: /* quoted_op_call: quoted_op '(' expr ',' expr ')'  */
      { if ((yyvsp[-5].iValue)==-1) {
          (yyval.expression)=nullptr;
          yyerror(&(yylsp[-3]), parm, "syntax error, unary operator with two arguments");
        } else {
          (yyval.expression)=new BinOp((yyloc), (yyvsp[-3].expression),static_cast<BinOpType>((yyvsp[-5].iValue)),(yyvsp[-1].expression));
        }
      }
    break;

  case 438: /* quoted_op_call: quoted_op '(' expr ')'  */
      { int uot=-1;
        switch ((yyvsp[-3].iValue)) {
        case -1:
          uot = UOT_NOT;
          break;
        case BOT_MINUS:
          uot = UOT_MINUS;
          break;
        case BOT_PLUS:
          uot = UOT_PLUS;
          break;
        default:
          yyerror(&(yylsp[-1]), parm, "syntax error, binary operator with unary argument list");
          break;
        }
        if (uot==-1)
          (yyval.expression)=nullptr;
        else {
          if (uot==UOT_PLUS && (yyvsp[-1].expression) && ((yyvsp[-1].expression)->isa<IntLit>() || (yyvsp[-1].expression)->isa<FloatLit>())) {
            (yyval.expression) = (yyvsp[-1].expression);
          } else if (uot==UOT_MINUS && (yyvsp[-1].expression) && (yyvsp[-1].expression)->isa<IntLit>()) {
            (yyval.expression) = IntLit::a(-(yyvsp[-1].expression)->cast<IntLit>()->v());
          } else if (uot==UOT_MINUS && (yyvsp[-1].expression) && (yyvsp[-1].expression)->isa<FloatLit>()) {
            (yyval.expression) = FloatLit::a(-(yyvsp[-1].expression)->cast<FloatLit>()->v());
          } else {
            (yyval.expression)=new UnOp((yyloc), static_cast<UnOpType>(uot),(yyvsp[-1].expression));
          }
        }
      }
    break;

  case 439: /* call_expr: "identifier" '(' ')'  */
      { (yyval.expression)=new Call((yyloc), (yyvsp[-2].sValue), std::vector<Expression*>()); free((yyvsp[-2].sValue)); }
    break;

  case 440: /* call_expr: "identifier" "^-1" '(' ')'  */
      { (yyval.expression)=new Call((yyloc), std::string((yyvsp[-3].sValue))+"⁻¹", std::vector<Expression*>()); free((yyvsp[-3].sValue)); }
    break;

  case 442: /* call_expr: "identifier" '(' comp_or_expr ')'  */
      { 
        if ((yyvsp[-1].expressionPairs)!=nullptr) {
          bool hadWhere = false;
          std::vector<Expression*> args;
          for (unsigned int i=0; i<(yyvsp[-1].expressionPairs)->size(); i++) {
            if ((*(yyvsp[-1].expressionPairs))[i].second) {
              yyerror(&(yylsp[-1]), parm, "syntax error, 'where' expression outside generator call");
              hadWhere = true;
              (yyval.expression)=nullptr;
            }
            args.push_back((*(yyvsp[-1].expressionPairs))[i].first);
          }
          if (!hadWhere) {
            (yyval.expression)=new Call((yyloc), (yyvsp[-3].sValue), args);
          }
        }
        free((yyvsp[-3].sValue));
        delete (yyvsp[-1].expressionPairs);
      }
    break;

  case 443: /* call_expr: "identifier" '(' comp_or_expr ')' '(' expr ')'  */
      { 
        vector<Generator> gens;
        vector<Id*> ids;
        if ((yyvsp[-4].expressionPairs)) {
          for (unsigned int i=0; i<(yyvsp[-4].expressionPairs)->size(); i++) {
            if (Id* id = Expression::dynamicCast<Id>((*(yyvsp[-4].expressionPairs))[i].first)) {
              if ((*(yyvsp[-4].expressionPairs))[i].second) {
                ParserLocation loc = (*(yyvsp[-4].expressionPairs))[i].second->loc().parserLocation();
                yyerror(&loc, parm, "illegal where expression in generator call");
              }
              ids.push_back(id);
            } else {
              if (BinOp* boe = Expression::dynamicCast<BinOp>((*(yyvsp[-4].expressionPairs))[i].first)) {
                if (boe->lhs() && boe->rhs()) {
                  Id* id = Expression::dynamicCast<Id>(boe->lhs());
                  if (id && boe->op() == BOT_IN) {
                    ids.push_back(id);
                    gens.push_back(Generator(ids,boe->rhs(),(*(yyvsp[-4].expressionPairs))[i].second));
                    ids = vector<Id*>();
                  } else if (id && boe->op() == BOT_EQ && ids.empty()) {
                    ids.push_back(id);
                    gens.push_back(Generator(ids,nullptr,boe->rhs()));
                    if ((*(yyvsp[-4].expressionPairs))[i].second) {
                      gens.push_back(Generator(gens.size(),(*(yyvsp[-4].expressionPairs))[i].second));
                    }
                    ids = vector<Id*>();
                  } else {
                    ParserLocation loc = (*(yyvsp[-4].expressionPairs))[i].first->loc().parserLocation();
                    yyerror(&loc, parm, "illegal expression in generator call");
                  }
                }
              } else {
                ParserLocation loc = (*(yyvsp[-4].expressionPairs))[i].first->loc().parserLocation();
                yyerror(&loc, parm, "illegal expression in generator call");
              }
            }
          }
        }
        if (ids.size() != 0) {
          yyerror(&(yylsp[-4]), parm, "illegal expression in generator call");
        }
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->hadError) {
          (yyval.expression)=nullptr;
        } else {
          Generators g; g.g = gens;
          Comprehension* ac = new Comprehension((yyloc), (yyvsp[-1].expression),g,false);
          vector<Expression*> args; args.push_back(ac);
          (yyval.expression)=new Call((yyloc), (yyvsp[-6].sValue), args);
        }
        free((yyvsp[-6].sValue));
        delete (yyvsp[-4].expressionPairs);
      }
    break;

  case 444: /* call_expr: "identifier" "^-1" '(' comp_or_expr ')'  */
      {
        if ((yyvsp[-1].expressionPairs)!=nullptr) {
          bool hadWhere = false;
          std::vector<Expression*> args;
          for (unsigned int i=0; i<(yyvsp[-1].expressionPairs)->size(); i++) {
            if ((*(yyvsp[-1].expressionPairs))[i].second) {
              yyerror(&(yylsp[-1]), parm, "syntax error, 'where' expression outside generator call");
              hadWhere = true;
              (yyval.expression)=nullptr;
            }
            args.push_back((*(yyvsp[-1].expressionPairs))[i].first);
          }
          if (!hadWhere) {
            (yyval.expression)=new Call((yyloc), std::string((yyvsp[-4].sValue))+"⁻¹", args);
          }
        }
        free((yyvsp[-4].sValue));
        delete (yyvsp[-1].expressionPairs);
      }
    break;

  case 445: /* call_expr: "identifier" "^-1" '(' comp_or_expr ')' '(' expr ')'  */
      {
        vector<Generator> gens;
        vector<Id*> ids;
        if ((yyvsp[-4].expressionPairs)) {
          for (unsigned int i=0; i<(yyvsp[-4].expressionPairs)->size(); i++) {
            if (Id* id = Expression::dynamicCast<Id>((*(yyvsp[-4].expressionPairs))[i].first)) {
              if ((*(yyvsp[-4].expressionPairs))[i].second) {
                ParserLocation loc = (*(yyvsp[-4].expressionPairs))[i].second->loc().parserLocation();
                yyerror(&loc, parm, "illegal where expression in generator call");
              }
              ids.push_back(id);
            } else {
              if (BinOp* boe = Expression::dynamicCast<BinOp>((*(yyvsp[-4].expressionPairs))[i].first)) {
                if (boe->lhs() && boe->rhs()) {
                  Id* id = Expression::dynamicCast<Id>(boe->lhs());
                  if (id && boe->op() == BOT_IN) {
                    ids.push_back(id);
                    gens.push_back(Generator(ids,boe->rhs(),(*(yyvsp[-4].expressionPairs))[i].second));
                    ids = vector<Id*>();
                  } else if (id && boe->op() == BOT_EQ && ids.empty()) {
                    ids.push_back(id);
                    gens.push_back(Generator(ids,nullptr,boe->rhs()));
                    if ((*(yyvsp[-4].expressionPairs))[i].second) {
                      gens.push_back(Generator(gens.size(),(*(yyvsp[-4].expressionPairs))[i].second));
                    }
                    ids = vector<Id*>();
                  } else {
                    ParserLocation loc = (*(yyvsp[-4].expressionPairs))[i].first->loc().parserLocation();
                    yyerror(&loc, parm, "illegal expression in generator call");
                  }
                }
              } else {
                ParserLocation loc = (*(yyvsp[-4].expressionPairs))[i].first->loc().parserLocation();
                yyerror(&loc, parm, "illegal expression in generator call");
              }
            }
          }
        }
        if (ids.size() != 0) {
          yyerror(&(yylsp[-4]), parm, "illegal expression in generator call");
        }
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->hadError) {
          (yyval.expression)=nullptr;
        } else {
          Generators g; g.g = gens;
          Comprehension* ac = new Comprehension((yyloc), (yyvsp[-1].expression),g,false);
          vector<Expression*> args; args.push_back(ac);
          (yyval.expression)=new Call((yyloc), std::string((yyvsp[-7].sValue))+"⁻¹", args);
        }
        free((yyvsp[-7].sValue));
        delete (yyvsp[-4].expressionPairs);
      }
    break;

  case 447: /* comp_or_expr_head: expr  */
      { (yyval.expressionPairs)=new vector<pair<Expression*,Expression*> >;
        if ((yyvsp[0].expression)) {
          (yyval.expressionPairs)->push_back(pair<Expression*,Expression*>((yyvsp[0].expression),nullptr));
        }
      }
    break;

  case 448: /* comp_or_expr_head: expr "where" expr  */
      { (yyval.expressionPairs)=new vector<pair<Expression*,Expression*> >;
        if ((yyvsp[-2].expression) && (yyvsp[0].expression)) {
          (yyval.expressionPairs)->push_back(pair<Expression*,Expression*>((yyvsp[-2].expression),(yyvsp[0].expression)));
        }
      }
    break;

  case 449: /* comp_or_expr_head: comp_or_expr_head ',' expr  */
      { (yyval.expressionPairs)=(yyvsp[-2].expressionPairs); if ((yyval.expressionPairs) && (yyvsp[0].expression)) (yyval.expressionPairs)->push_back(pair<Expression*,Expression*>((yyvsp[0].expression),nullptr)); }
    break;

  case 450: /* comp_or_expr_head: comp_or_expr_head ',' expr "where" expr  */
      { (yyval.expressionPairs)=(yyvsp[-4].expressionPairs); if ((yyval.expressionPairs) && (yyvsp[-2].expression) && (yyvsp[0].expression)) (yyval.expressionPairs)->push_back(pair<Expression*,Expression*>((yyvsp[-2].expression),(yyvsp[0].expression))); }
    break;

  case 451: /* let_expr: "let" '{' let_vardecl_item_list '}' "in" expr  */
      { if ((yyvsp[-3].expressions1d) && (yyvsp[0].expression)) {
          (yyval.expression)=new Let((yyloc), *(yyvsp[-3].expressions1d), (yyvsp[0].expression)); delete (yyvsp[-3].expressions1d);
        } else {
          (yyval.expression)=nullptr;
        }
      }
    break;

  case 452: /* let_expr: "let" '{' let_vardecl_item_list comma_or_semi '}' "in" expr  */
      { if ((yyvsp[-4].expressions1d) && (yyvsp[0].expression)) {
          (yyval.expression)=new Let((yyloc), *(yyvsp[-4].expressions1d), (yyvsp[0].expression)); delete (yyvsp[-4].expressions1d);
        } else {
          (yyval.expression)=nullptr;
        }
      }
    break;

  case 453: /* let_vardecl_item_list: let_vardecl_item  */
      { (yyval.expressions1d)=new vector<Expression*>; (yyval.expressions1d)->push_back((yyvsp[0].vardeclexpr)); }
    break;

  case 454: /* let_vardecl_item_list: constraint_item  */
      { (yyval.expressions1d)=new vector<Expression*>;
        if ((yyvsp[0].item)) {
          ConstraintI* ce = (yyvsp[0].item)->cast<ConstraintI>();
          (yyval.expressions1d)->push_back(ce->e());
          ce->e(nullptr);
        }
      }
    break;

  case 455: /* let_vardecl_item_list: let_vardecl_item_list comma_or_semi let_vardecl_item  */
      { (yyval.expressions1d)=(yyvsp[-2].expressions1d); if ((yyval.expressions1d) && (yyvsp[0].vardeclexpr)) (yyval.expressions1d)->push_back((yyvsp[0].vardeclexpr)); }
    break;

  case 456: /* let_vardecl_item_list: let_vardecl_item_list comma_or_semi constraint_item  */
      { (yyval.expressions1d)=(yyvsp[-2].expressions1d);
        if ((yyval.expressions1d) && (yyvsp[0].item)) {
          ConstraintI* ce = (yyvsp[0].item)->cast<ConstraintI>();
          (yyval.expressions1d)->push_back(ce->e());
          ce->e(nullptr);
        }
      }
    break;

  case 459: /* let_vardecl_item: ti_expr_and_id  */
      { (yyval.vardeclexpr) = (yyvsp[0].vardeclexpr);
        if ((yyval.vardeclexpr)) (yyval.vardeclexpr)->toplevel(false);
      }
    break;

  case 460: /* let_vardecl_item: ti_expr_and_id "=" expr  */
      { if ((yyvsp[-2].vardeclexpr)) (yyvsp[-2].vardeclexpr)->e((yyvsp[0].expression));
        (yyval.vardeclexpr) = (yyvsp[-2].vardeclexpr);
        if ((yyval.vardeclexpr)) (yyval.vardeclexpr)->loc((yyloc));
        if ((yyval.vardeclexpr)) (yyval.vardeclexpr)->toplevel(false);
      }
    break;

  case 461: /* annotations: %empty  */
      { (yyval.expressions1d)=nullptr; }
    break;

  case 463: /* annotation_expr: expr_atom_head_nonstring  */
      { (yyval.expression) = (yyvsp[0].expression); }
    break;

  case 464: /* annotation_expr: string_expr  */
      { (yyval.expression) = new Call((yylsp[0]), ASTString("mzn_expression_name"), {(yyvsp[0].expression)}); }
    break;

  case 465: /* ne_annotations: "::" annotation_expr  */
      { (yyval.expressions1d)=new std::vector<Expression*>(1);
        (*(yyval.expressions1d))[0] = (yyvsp[0].expression);
      }
    break;

  case 466: /* ne_annotations: ne_annotations "::" annotation_expr  */
      { (yyval.expressions1d)=(yyvsp[-2].expressions1d); if ((yyval.expressions1d)) (yyval.expressions1d)->push_back((yyvsp[0].expression)); }
    break;

  case 467: /* id_or_quoted_op: "identifier"  */
      { (yyval.sValue)=(yyvsp[0].sValue); }
    break;

  case 468: /* id_or_quoted_op: "identifier" "^-1"  */
      { (yyval.sValue)=strdup((std::string((yyvsp[-1].sValue))+"⁻¹").c_str()); }
    break;

  case 469: /* id_or_quoted_op: "'<->'"  */
      { (yyval.sValue)=strdup("'<->'"); }
    break;

  case 470: /* id_or_quoted_op: "'->'"  */
      { (yyval.sValue)=strdup("'->'"); }
    break;

  case 471: /* id_or_quoted_op: "'<-'"  */
      { (yyval.sValue)=strdup("'<-'"); }
    break;

  case 472: /* id_or_quoted_op: "'\\/'"  */
      { (yyval.sValue)=strdup("'\\/'"); }
    break;

  case 473: /* id_or_quoted_op: "'xor'"  */
      { (yyval.sValue)=strdup("'xor'"); }
    break;

  case 474: /* id_or_quoted_op: "'/\\'"  */
      { (yyval.sValue)=strdup("'/\\'"); }
    break;

  case 475: /* id_or_quoted_op: "'<'"  */
      { (yyval.sValue)=strdup("'<'"); }
    break;

  case 476: /* id_or_quoted_op: "'>'"  */
      { (yyval.sValue)=strdup("'>'"); }
    break;

  case 477: /* id_or_quoted_op: "'<='"  */
      { (yyval.sValue)=strdup("'<='"); }
    break;

  case 478: /* id_or_quoted_op: "'>='"  */
      { (yyval.sValue)=strdup("'>='"); }
    break;

  case 479: /* id_or_quoted_op: "'='"  */
      { (yyval.sValue)=strdup("'='"); }
    break;

  case 480: /* id_or_quoted_op: "'!='"  */
      { (yyval.sValue)=strdup("'!='"); }
    break;

  case 481: /* id_or_quoted_op: "'in'"  */
      { (yyval.sValue)=strdup("'in'"); }
    break;

  case 482: /* id_or_quoted_op: "'subset'"  */
      { (yyval.sValue)=strdup("'subset'"); }
    break;

  case 483: /* id_or_quoted_op: "'superset'"  */
      { (yyval.sValue)=strdup("'superset'"); }
    break;

  case 484: /* id_or_quoted_op: "'union'"  */
      { (yyval.sValue)=strdup("'union'"); }
    break;

  case 485: /* id_or_quoted_op: "'diff'"  */
      { (yyval.sValue)=strdup("'diff'"); }
    break;

  case 486: /* id_or_quoted_op: "'symdiff'"  */
      { (yyval.sValue)=strdup("'symdiff'"); }
    break;

  case 487: /* id_or_quoted_op: "'..'"  */
      { (yyval.sValue)=strdup("'..'"); }
    break;

  case 488: /* id_or_quoted_op: "'<..'"  */
      { (yyval.sValue)=strdup("'<..'"); }
    break;

  case 489: /* id_or_quoted_op: "'..<'"  */
      { (yyval.sValue)=strdup("'..<'"); }
    break;

  case 490: /* id_or_quoted_op: "'<..<'"  */
      { (yyval.sValue)=strdup("'<..<'"); }
    break;

  case 491: /* id_or_quoted_op: "'+'"  */
      { (yyval.sValue)=strdup("'+'"); }
    break;

  case 492: /* id_or_quoted_op: "'-'"  */
      { (yyval.sValue)=strdup("'-'"); }
    break;

  case 493: /* id_or_quoted_op: "'*'"  */
      { (yyval.sValue)=strdup("'*'"); }
    break;

  case 494: /* id_or_quoted_op: "'^'"  */
      { (yyval.sValue)=strdup("'^'"); }
    break;

  case 495: /* id_or_quoted_op: "'/'"  */
      { (yyval.sValue)=strdup("'/'"); }
    break;

  case 496: /* id_or_quoted_op: "'div'"  */
      { (yyval.sValue)=strdup("'div'"); }
    break;

  case 497: /* id_or_quoted_op: "'mod'"  */
      { (yyval.sValue)=strdup("'mod'"); }
    break;

  case 498: /* id_or_quoted_op: "'intersect'"  */
      { (yyval.sValue)=strdup("'intersect'"); }
    break;

  case 499: /* id_or_quoted_op: "'not'"  */
      { (yyval.sValue)=strdup("'not'"); }
    break;

  case 500: /* id_or_quoted_op: "'++'"  */
      { (yyval.sValue)=strdup("'++'"); }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, parm, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= END)
        {
          /* Return failure if at end of input.  */
          if (yychar == END)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, parm);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, parm);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, parm, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, parm);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, parm);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

