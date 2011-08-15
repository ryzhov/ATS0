
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 75 "cfg.y"


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#include "route.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "pvar.h"
#include "blacklists.h"


#include "config.h"
#ifdef USE_TLS
#include "tls/tls_config.h"
#include "tls/tls_domain.h"
#endif

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H


extern int yylex();
static void yyerror(char* s);
static void yyerrorf(char* fmt, ...);
static char* tmp;
static int i_tmp;
static void* cmd_tmp;
static struct socket_id* lst_tmp;
static int rt;  /* Type of route block for find_export */
static str* str_tmp;
static str s_tmp;
static str tstr;
static struct ip_addr* ip_tmp;
static pv_spec_t *spec;
static pv_elem_t *pvmodel;
static struct bl_rule *bl_head = 0;
static struct bl_rule *bl_tail = 0;
static struct stat statf;

action_elem_t elems[MAX_ACTION_ELEMS];

#if !defined(USE_TLS) || !defined(USE_TCP) ||  !defined(USE_MCAST)
static void warn(char* s);
#endif
static struct socket_id* mk_listen_id(char*, int, int);
static struct socket_id* set_listen_id_adv(struct socket_id *, char *, int);

static char *mpath=NULL;
static char mpath_buf[256];
static int  mpath_len = 0;

extern int line;

#define mk_action0(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		_res = mk_action(_type, 0, 0, line); \
	} while(0)
#define mk_action1(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		_res = mk_action(_type, 1, elems, line); \
	} while(0)
#define mk_action2(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		_res = mk_action(_type, 2, elems, line); \
	} while(0)
#define mk_action3(_res, _type, _p1_type, _p2_type, _p3_type, _p1, _p2, _p3) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		elems[2].type = _p3_type; \
		elems[2].u.data = _p3; \
		_res = mk_action(_type, 3, elems, line); \
	} while(0)



/* Line 189 of yacc.c  */
#line 182 "cfg.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FORWARD = 258,
     SEND = 259,
     DROP = 260,
     EXIT = 261,
     RETURN = 262,
     LOG_TOK = 263,
     ERROR = 264,
     ROUTE = 265,
     ROUTE_FAILURE = 266,
     ROUTE_ONREPLY = 267,
     ROUTE_BRANCH = 268,
     ROUTE_ERROR = 269,
     ROUTE_LOCAL = 270,
     ROUTE_STARTUP = 271,
     ROUTE_TIMER = 272,
     SET_HOST = 273,
     SET_HOSTPORT = 274,
     PREFIX = 275,
     STRIP = 276,
     STRIP_TAIL = 277,
     APPEND_BRANCH = 278,
     PV_PRINTF = 279,
     SET_USER = 280,
     SET_USERPASS = 281,
     SET_PORT = 282,
     SET_URI = 283,
     REVERT_URI = 284,
     SET_DSTURI = 285,
     RESET_DSTURI = 286,
     ISDSTURISET = 287,
     FORCE_RPORT = 288,
     FORCE_LOCAL_RPORT = 289,
     FORCE_TCP_ALIAS = 290,
     IF = 291,
     ELSE = 292,
     SWITCH = 293,
     CASE = 294,
     DEFAULT = 295,
     SBREAK = 296,
     WHILE = 297,
     SET_ADV_ADDRESS = 298,
     SET_ADV_PORT = 299,
     FORCE_SEND_SOCKET = 300,
     SERIALIZE_BRANCHES = 301,
     NEXT_BRANCHES = 302,
     USE_BLACKLIST = 303,
     UNUSE_BLACKLIST = 304,
     MAX_LEN = 305,
     SETDEBUG = 306,
     SETFLAG = 307,
     RESETFLAG = 308,
     ISFLAGSET = 309,
     SETBFLAG = 310,
     RESETBFLAG = 311,
     ISBFLAGSET = 312,
     SETSFLAG = 313,
     RESETSFLAG = 314,
     ISSFLAGSET = 315,
     METHOD = 316,
     URI = 317,
     FROM_URI = 318,
     TO_URI = 319,
     SRCIP = 320,
     SRCPORT = 321,
     DSTIP = 322,
     DSTPORT = 323,
     PROTO = 324,
     AF = 325,
     MYSELF = 326,
     MSGLEN = 327,
     UDP = 328,
     TCP = 329,
     TLS = 330,
     SCTP = 331,
     NULLV = 332,
     CACHE_STORE = 333,
     CACHE_FETCH = 334,
     CACHE_REMOVE = 335,
     DEBUG = 336,
     FORK = 337,
     LOGSTDERROR = 338,
     LOGFACILITY = 339,
     LOGNAME = 340,
     AVP_ALIASES = 341,
     LISTEN = 342,
     ALIAS = 343,
     AUTO_ALIASES = 344,
     DNS = 345,
     REV_DNS = 346,
     DNS_TRY_IPV6 = 347,
     DNS_RETR_TIME = 348,
     DNS_RETR_NO = 349,
     DNS_SERVERS_NO = 350,
     DNS_USE_SEARCH = 351,
     MAX_WHILE_LOOPS = 352,
     PORT = 353,
     CHILDREN = 354,
     CHECK_VIA = 355,
     MEMLOG = 356,
     MEMDUMP = 357,
     SIP_WARNING = 358,
     SOCK_MODE = 359,
     SOCK_USER = 360,
     SOCK_GROUP = 361,
     UNIX_SOCK = 362,
     UNIX_SOCK_CHILDREN = 363,
     UNIX_TX_TIMEOUT = 364,
     SERVER_SIGNATURE = 365,
     SERVER_HEADER = 366,
     USER_AGENT_HEADER = 367,
     LOADMODULE = 368,
     MPATH = 369,
     MODPARAM = 370,
     MAXBUFFER = 371,
     USER = 372,
     GROUP = 373,
     CHROOT = 374,
     WDIR = 375,
     MHOMED = 376,
     DISABLE_TCP = 377,
     TCP_ACCEPT_ALIASES = 378,
     TCP_CHILDREN = 379,
     TCP_CONNECT_TIMEOUT = 380,
     TCP_SEND_TIMEOUT = 381,
     TCP_CON_LIFETIME = 382,
     TCP_POLL_METHOD = 383,
     TCP_MAX_CONNECTIONS = 384,
     TCP_OPT_CRLF_PINGPONG = 385,
     DISABLE_TLS = 386,
     TLSLOG = 387,
     TLS_PORT_NO = 388,
     TLS_METHOD = 389,
     TLS_HANDSHAKE_TIMEOUT = 390,
     TLS_SEND_TIMEOUT = 391,
     TLS_SERVER_DOMAIN = 392,
     TLS_CLIENT_DOMAIN = 393,
     TLS_CLIENT_DOMAIN_AVP = 394,
     SSLv23 = 395,
     SSLv2 = 396,
     SSLv3 = 397,
     TLSv1 = 398,
     TLS_VERIFY_CLIENT = 399,
     TLS_VERIFY_SERVER = 400,
     TLS_REQUIRE_CLIENT_CERTIFICATE = 401,
     TLS_CERTIFICATE = 402,
     TLS_PRIVATE_KEY = 403,
     TLS_CA_LIST = 404,
     TLS_CIPHERS_LIST = 405,
     ADVERTISED_ADDRESS = 406,
     ADVERTISED_PORT = 407,
     DISABLE_CORE = 408,
     OPEN_FD_LIMIT = 409,
     MCAST_LOOPBACK = 410,
     MCAST_TTL = 411,
     TOS = 412,
     DISABLE_DNS_FAILOVER = 413,
     DISABLE_DNS_BLACKLIST = 414,
     DST_BLACKLIST = 415,
     DISABLE_STATELESS_FWD = 416,
     DB_VERSION_TABLE = 417,
     EQUAL = 418,
     EQUAL_T = 419,
     GT = 420,
     LT = 421,
     GTE = 422,
     LTE = 423,
     DIFF = 424,
     MATCH = 425,
     NOTMATCH = 426,
     COLONEQ = 427,
     PLUSEQ = 428,
     MINUSEQ = 429,
     SLASHEQ = 430,
     MULTEQ = 431,
     MODULOEQ = 432,
     BANDEQ = 433,
     BOREQ = 434,
     BXOREQ = 435,
     AND = 436,
     OR = 437,
     BRSHIFT = 438,
     BLSHIFT = 439,
     BXOR = 440,
     BAND = 441,
     BOR = 442,
     MODULO = 443,
     MULT = 444,
     SLASH = 445,
     MINUS = 446,
     PLUS = 447,
     BNOT = 448,
     NOT = 449,
     NUMBER = 450,
     ZERO = 451,
     ID = 452,
     STRING = 453,
     SCRIPTVAR = 454,
     IPV6ADDR = 455,
     COMMA = 456,
     SEMICOLON = 457,
     RPAREN = 458,
     LPAREN = 459,
     LBRACE = 460,
     RBRACE = 461,
     LBRACK = 462,
     RBRACK = 463,
     AS = 464,
     DOT = 465,
     CR = 466,
     COLON = 467,
     ANY = 468,
     SCRIPTVARERR = 469
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 183 "cfg.y"

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct _pv_spec *specval;



/* Line 214 of yacc.c  */
#line 446 "cfg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 458 "cfg.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  172
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  555
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1095

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   469

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    18,
      21,    22,    25,    26,    29,    30,    33,    34,    37,    38,
      41,    42,    45,    46,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    76,    79,    81,
      85,    89,    95,    99,   105,   109,   111,   114,   124,   135,
     139,   141,   144,   148,   152,   156,   160,   164,   168,   172,
     176,   180,   184,   188,   192,   196,   200,   204,   208,   212,
     215,   219,   222,   226,   229,   233,   236,   240,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   307,   311,   315,   319,   323,   327,
     331,   335,   339,   343,   347,   351,   355,   359,   363,   367,
     371,   375,   379,   383,   387,   391,   395,   399,   403,   407,
     411,   415,   419,   423,   427,   431,   435,   439,   443,   447,
     451,   455,   459,   463,   467,   471,   475,   479,   483,   487,
     491,   495,   499,   503,   507,   511,   515,   519,   523,   527,
     531,   535,   539,   543,   547,   551,   555,   559,   563,   565,
     567,   571,   575,   579,   583,   587,   591,   595,   599,   603,
     607,   611,   615,   619,   623,   627,   631,   635,   639,   643,
     647,   651,   655,   659,   663,   667,   671,   675,   679,   683,
     687,   690,   694,   697,   705,   709,   713,   717,   720,   723,
     726,   735,   744,   747,   749,   751,   759,   761,   763,   767,
     768,   779,   780,   791,   792,   801,   803,   806,   808,   811,
     815,   819,   823,   827,   831,   835,   839,   843,   847,   851,
     855,   859,   863,   867,   871,   875,   879,   883,   887,   891,
     895,   899,   903,   907,   911,   915,   919,   923,   927,   931,
     935,   939,   941,   943,   945,   950,   958,   961,   969,   972,
     977,   985,   988,   996,   999,  1004,  1007,  1012,  1015,  1020,
    1023,  1033,  1036,  1040,  1044,  1047,  1051,  1055,  1057,  1059,
    1061,  1063,  1065,  1067,  1069,  1071,  1073,  1075,  1077,  1079,
    1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,
    1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,  1133,  1136,
    1140,  1144,  1148,  1152,  1156,  1160,  1164,  1168,  1172,  1175,
    1179,  1183,  1186,  1190,  1194,  1197,  1201,  1205,  1208,  1212,
    1216,  1219,  1223,  1227,  1231,  1234,  1238,  1242,  1246,  1249,
    1253,  1257,  1261,  1264,  1268,  1272,  1276,  1280,  1283,  1287,
    1291,  1293,  1297,  1299,  1301,  1303,  1307,  1311,  1313,  1315,
    1317,  1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335,
    1337,  1339,  1341,  1343,  1347,  1351,  1355,  1359,  1363,  1367,
    1371,  1375,  1379,  1383,  1386,  1390,  1394,  1398,  1402,  1404,
    1406,  1408,  1412,  1415,  1417,  1421,  1424,  1427,  1429,  1432,
    1435,  1437,  1439,  1441,  1444,  1446,  1449,  1453,  1459,  1463,
    1471,  1474,  1476,  1479,  1481,  1488,  1494,  1499,  1503,  1510,
    1516,  1521,  1525,  1529,  1532,  1534,  1538,  1540,  1544,  1549,
    1553,  1556,  1561,  1566,  1569,  1574,  1578,  1580,  1584,  1586,
    1591,  1596,  1600,  1602,  1607,  1614,  1617,  1622,  1627,  1631,
    1634,  1639,  1642,  1647,  1650,  1655,  1658,  1663,  1666,  1671,
    1674,  1679,  1682,  1689,  1694,  1697,  1704,  1709,  1712,  1719,
    1724,  1727,  1734,  1737,  1742,  1747,  1750,  1755,  1760,  1763,
    1768,  1773,  1776,  1781,  1786,  1789,  1794,  1799,  1802,  1807,
    1814,  1819,  1823,  1825,  1832,  1839,  1844,  1847,  1852,  1857,
    1860,  1865,  1870,  1873,  1878,  1883,  1886,  1891,  1896,  1899,
    1904,  1908,  1910,  1915,  1918,  1923,  1927,  1929,  1933,  1935,
    1939,  1941,  1945,  1947,  1952,  1956,  1958,  1963,  1968,  1973,
    1976,  1981,  1986,  1989,  1994,  1999,  2002,  2007,  2012,  2015,
    2019,  2024,  2027,  2032,  2037,  2040,  2045,  2050,  2053,  2062,
    2073,  2080,  2089,  2093,  2098,  2103
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     216,     0,    -1,   217,    -1,   217,   218,    -1,   218,    -1,
     217,     1,    -1,   235,    -1,   236,    -1,    -1,   219,   251,
      -1,    -1,   220,   252,    -1,    -1,   221,   253,    -1,    -1,
     222,   254,    -1,    -1,   223,   255,    -1,    -1,   224,   256,
      -1,    -1,   225,   257,    -1,    -1,   226,   258,    -1,   211,
      -1,   237,    -1,   198,    -1,   271,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,   213,    -1,   195,    -1,   213,
      -1,   195,    -1,   192,   195,    -1,   191,   195,    -1,   227,
      -1,   227,   212,   229,    -1,   228,   212,   227,    -1,   228,
     212,   227,   212,   229,    -1,   231,   209,   227,    -1,   231,
     209,   227,   212,   229,    -1,   227,   212,     1,    -1,   231,
      -1,   231,   232,    -1,   204,   228,   201,   269,   201,   229,
     201,   198,   203,    -1,   194,   204,   228,   201,   269,   201,
     229,   201,   198,   203,    -1,   234,   201,   233,    -1,   233,
      -1,   234,     1,    -1,    81,   163,   230,    -1,    81,   163,
       1,    -1,    82,   163,   195,    -1,    82,   163,     1,    -1,
      83,   163,   195,    -1,    83,   163,     1,    -1,    84,   163,
     197,    -1,    84,   163,     1,    -1,    85,   163,   198,    -1,
      85,   163,     1,    -1,    86,   163,   198,    -1,    86,   163,
       1,    -1,    90,   163,   195,    -1,    90,   163,     1,    -1,
      91,   163,   195,    -1,    91,   163,     1,    -1,    92,   163,
     195,    -1,    92,     1,    -1,    93,   163,   195,    -1,    93,
       1,    -1,    94,   163,   195,    -1,    94,     1,    -1,    95,
     163,   195,    -1,    95,     1,    -1,    96,   163,   195,    -1,
      96,     1,    -1,    98,   163,   195,    -1,    98,   163,     1,
      -1,    97,   163,   195,    -1,    97,   163,     1,    -1,   116,
     163,   195,    -1,   116,   163,     1,    -1,    99,   163,   195,
      -1,    99,   163,     1,    -1,   100,   163,   195,    -1,   100,
     163,     1,    -1,   101,   163,   195,    -1,   101,   163,     1,
      -1,   102,   163,   195,    -1,   102,   163,     1,    -1,   103,
     163,   195,    -1,   103,   163,     1,    -1,   117,   163,   198,
      -1,   117,   163,   197,    -1,   117,   163,     1,    -1,   118,
     163,   198,    -1,   118,   163,   197,    -1,   118,   163,     1,
      -1,   119,   163,   198,    -1,   119,   163,   197,    -1,   119,
     163,     1,    -1,   120,   163,   198,    -1,   120,   163,   197,
      -1,   120,   163,     1,    -1,   121,   163,   195,    -1,   121,
     163,     1,    -1,   122,   163,   195,    -1,   122,   163,     1,
      -1,   123,   163,   195,    -1,   123,   163,     1,    -1,   124,
     163,   195,    -1,   124,   163,     1,    -1,   125,   163,   195,
      -1,   125,   163,     1,    -1,   126,   163,   195,    -1,   126,
     163,     1,    -1,   127,   163,   195,    -1,   127,   163,     1,
      -1,   128,   163,   197,    -1,   128,   163,   198,    -1,   128,
     163,     1,    -1,   129,   163,   195,    -1,   129,   163,     1,
      -1,   130,   163,   195,    -1,   130,   163,     1,    -1,   131,
     163,   195,    -1,   131,   163,     1,    -1,   132,   163,   195,
      -1,   132,   163,     1,    -1,   133,   163,   195,    -1,   133,
     163,     1,    -1,   134,   163,   140,    -1,   134,   163,   141,
      -1,   134,   163,   142,    -1,   134,   163,   143,    -1,   134,
     163,     1,    -1,   144,   163,   195,    -1,   144,   163,     1,
      -1,   145,   163,   195,    -1,   145,   163,     1,    -1,   146,
     163,   195,    -1,   146,   163,     1,    -1,   147,   163,   198,
      -1,   147,   163,     1,    -1,   148,   163,   198,    -1,   148,
     163,     1,    -1,   149,   163,   198,    -1,   149,   163,     1,
      -1,   150,   163,   198,    -1,   150,   163,     1,    -1,   135,
     163,   195,    -1,   135,   163,     1,    -1,   136,   163,   195,
      -1,   136,   163,     1,    -1,   139,   163,   195,    -1,   139,
     163,     1,    -1,   241,    -1,   243,    -1,   110,   163,   195,
      -1,   110,   163,     1,    -1,   111,   163,   198,    -1,   111,
     163,     1,    -1,   112,   163,   198,    -1,   112,   163,     1,
      -1,    87,   163,   232,    -1,    87,   163,     1,    -1,    88,
     163,   232,    -1,    88,   163,     1,    -1,    89,   163,   195,
      -1,    89,   163,     1,    -1,   151,   163,   227,    -1,   151,
     163,     1,    -1,   152,   163,   195,    -1,   152,   163,     1,
      -1,   153,   163,   195,    -1,   153,   163,     1,    -1,   154,
     163,   195,    -1,   154,   163,     1,    -1,   155,   163,   195,
      -1,   155,   163,     1,    -1,   156,   163,   195,    -1,   156,
     163,     1,    -1,   157,   163,   195,    -1,   157,   163,   197,
      -1,   157,   163,     1,    -1,   114,   163,   198,    -1,   114,
     163,     1,    -1,   158,   163,   195,    -1,   158,     1,    -1,
     159,   163,   195,    -1,   159,     1,    -1,   160,   163,   197,
     212,   205,   234,   206,    -1,   161,   163,   195,    -1,   162,
     163,   198,    -1,   162,   163,     1,    -1,     1,   163,    -1,
     113,   198,    -1,   113,     1,    -1,   115,   204,   198,   201,
     198,   201,   198,   203,    -1,   115,   204,   198,   201,   198,
     201,   230,   203,    -1,   115,     1,    -1,   238,    -1,   240,
      -1,   195,   210,   195,   210,   195,   210,   195,    -1,   200,
      -1,   239,    -1,   207,   239,   208,    -1,    -1,   137,   207,
     237,   212,   229,   208,   242,   205,   246,   206,    -1,    -1,
     138,   207,   237,   212,   229,   208,   244,   205,   247,   206,
      -1,    -1,   138,   207,   198,   208,   245,   205,   247,   206,
      -1,   248,    -1,   246,   248,    -1,   249,    -1,   247,   249,
      -1,   134,   163,   140,    -1,   134,   163,   141,    -1,   134,
     163,   142,    -1,   134,   163,   143,    -1,   134,   163,     1,
      -1,   147,   163,   198,    -1,   147,   163,     1,    -1,   148,
     163,   198,    -1,   148,   163,     1,    -1,   149,   163,   198,
      -1,   149,   163,     1,    -1,   150,   163,   198,    -1,   150,
     163,     1,    -1,   144,   163,   195,    -1,   144,   163,     1,
      -1,   146,   163,   195,    -1,   146,   163,     1,    -1,   134,
     163,   140,    -1,   134,   163,   141,    -1,   134,   163,   142,
      -1,   134,   163,   143,    -1,   134,   163,     1,    -1,   147,
     163,   198,    -1,   147,   163,     1,    -1,   148,   163,   198,
      -1,   148,   163,     1,    -1,   149,   163,   198,    -1,   149,
     163,     1,    -1,   150,   163,   198,    -1,   150,   163,     1,
      -1,   145,   163,   195,    -1,   145,   163,     1,    -1,   197,
      -1,   195,    -1,   198,    -1,    10,   205,   277,   206,    -1,
      10,   207,   250,   208,   205,   277,   206,    -1,    10,     1,
      -1,    11,   207,   250,   208,   205,   277,   206,    -1,    11,
       1,    -1,    12,   205,   277,   206,    -1,    12,   207,   250,
     208,   205,   277,   206,    -1,    12,     1,    -1,    13,   207,
     250,   208,   205,   277,   206,    -1,    13,     1,    -1,    14,
     205,   277,   206,    -1,    14,     1,    -1,    15,   205,   277,
     206,    -1,    15,     1,    -1,    16,   205,   277,   206,    -1,
      16,     1,    -1,    17,   207,   250,   201,   195,   208,   205,
     277,   206,    -1,    17,     1,    -1,   259,   181,   259,    -1,
     259,   182,   259,    -1,   194,   259,    -1,   204,   259,   203,
      -1,   207,   273,   208,    -1,   267,    -1,   164,    -1,   169,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,   170,
      -1,   171,    -1,   260,    -1,   261,    -1,   260,    -1,   261,
      -1,   262,    -1,    62,    -1,    63,    -1,    64,    -1,   199,
      -1,   214,    -1,   268,    -1,   275,    -1,   230,    -1,   266,
      -1,   265,   264,   271,    -1,    67,   260,   269,    -1,    67,
     264,   271,    -1,    65,   260,   269,    -1,    65,   264,   271,
      -1,    61,   264,   198,    -1,    61,   264,   197,    -1,    61,
     264,     1,    -1,    61,     1,    -1,   266,   264,   266,    -1,
     266,   264,   198,    -1,   266,   264,   197,    -1,   266,   263,
     230,    -1,   266,   260,    71,    -1,   266,   260,    77,    -1,
     265,   264,   198,    -1,   265,   260,    71,    -1,   265,   264,
       1,    -1,   265,     1,    -1,    66,   263,   195,    -1,    66,
     263,     1,    -1,    66,     1,    -1,    68,   263,   195,    -1,
      68,   263,     1,    -1,    68,     1,    -1,    69,   263,   228,
      -1,    69,   263,     1,    -1,    69,     1,    -1,    70,   263,
     195,    -1,    70,   263,     1,    -1,    70,     1,    -1,    72,
     263,   195,    -1,    72,   263,    50,    -1,    72,   263,     1,
      -1,    72,     1,    -1,    65,   264,   198,    -1,    65,   260,
      71,    -1,    65,   264,     1,    -1,    65,     1,    -1,    67,
     264,   198,    -1,    67,   260,    71,    -1,    67,   264,     1,
      -1,    67,     1,    -1,    71,   260,   265,    -1,    71,   260,
      65,    -1,    71,   260,    67,    -1,    71,   260,     1,    -1,
      71,     1,    -1,   237,   190,   237,    -1,   237,   190,   195,
      -1,   237,    -1,   237,   190,     1,    -1,   210,    -1,   191,
      -1,   197,    -1,   271,   270,   197,    -1,   271,   210,     1,
      -1,   163,    -1,   172,    -1,   173,    -1,   174,    -1,   175,
      -1,   176,    -1,   177,    -1,   178,    -1,   179,    -1,   180,
      -1,   230,    -1,   198,    -1,   197,    -1,   266,    -1,   268,
      -1,   287,    -1,   273,   192,   273,    -1,   273,   191,   273,
      -1,   273,   189,   273,    -1,   273,   190,   273,    -1,   273,
     188,   273,    -1,   273,   186,   273,    -1,   273,   187,   273,
      -1,   273,   185,   273,    -1,   273,   184,   273,    -1,   273,
     183,   273,    -1,   193,   273,    -1,   204,   273,   203,    -1,
     266,   272,   273,    -1,   266,   163,    77,    -1,   266,   172,
      77,    -1,   287,    -1,   279,    -1,   274,    -1,   205,   277,
     206,    -1,   205,   206,    -1,   278,    -1,   205,   277,   206,
      -1,   205,   206,    -1,   277,   278,    -1,   278,    -1,   277,
       1,    -1,   287,   202,    -1,   279,    -1,   280,    -1,   281,
      -1,   274,   202,    -1,   202,    -1,   287,     1,    -1,    36,
     259,   276,    -1,    36,   259,   276,    37,   276,    -1,    42,
     259,   276,    -1,    38,   204,   266,   203,   205,   282,   206,
      -1,   283,   285,    -1,   283,    -1,   283,   284,    -1,   284,
      -1,    39,   230,   212,   277,    41,   202,    -1,    39,   230,
     212,    41,   202,    -1,    39,   230,   212,   277,    -1,    39,
     230,   212,    -1,    39,   198,   212,   277,    41,   202,    -1,
      39,   198,   212,    41,   202,    -1,    39,   198,   212,   277,
      -1,    39,   198,   212,    -1,    40,   212,   277,    -1,    40,
     212,    -1,   198,    -1,   286,   201,   198,    -1,   195,    -1,
     286,   201,   195,    -1,     3,   204,   198,   203,    -1,     3,
     204,   203,    -1,     3,     1,    -1,     3,   204,     1,   203,
      -1,     4,   204,   198,   203,    -1,     4,     1,    -1,     4,
     204,     1,   203,    -1,     5,   204,   203,    -1,     5,    -1,
       6,   204,   203,    -1,     6,    -1,     7,   204,   230,   203,
      -1,     7,   204,   266,   203,    -1,     7,   204,   203,    -1,
       7,    -1,     8,   204,   198,   203,    -1,     8,   204,   230,
     201,   198,   203,    -1,     8,     1,    -1,     8,   204,     1,
     203,    -1,    51,   204,   195,   203,    -1,    51,   204,   203,
      -1,    51,     1,    -1,    52,   204,   195,   203,    -1,    52,
       1,    -1,    53,   204,   195,   203,    -1,    53,     1,    -1,
      54,   204,   195,   203,    -1,    54,     1,    -1,    58,   204,
     195,   203,    -1,    58,     1,    -1,    59,   204,   195,   203,
      -1,    59,     1,    -1,    60,   204,   195,   203,    -1,    60,
       1,    -1,    55,   204,   195,   201,   195,   203,    -1,    55,
     204,   195,   203,    -1,    55,     1,    -1,    56,   204,   195,
     201,   195,   203,    -1,    56,   204,   195,   203,    -1,    56,
       1,    -1,    57,   204,   195,   201,   195,   203,    -1,    57,
     204,   195,   203,    -1,    57,     1,    -1,     9,   204,   198,
     201,   198,   203,    -1,     9,     1,    -1,     9,   204,     1,
     203,    -1,    10,   204,   250,   203,    -1,    10,     1,    -1,
      10,   204,     1,   203,    -1,    18,   204,   198,   203,    -1,
      18,     1,    -1,    18,   204,     1,   203,    -1,    20,   204,
     198,   203,    -1,    20,     1,    -1,    20,   204,     1,   203,
      -1,    22,   204,   195,   203,    -1,    22,     1,    -1,    22,
     204,     1,   203,    -1,    21,   204,   195,   203,    -1,    21,
       1,    -1,    21,   204,     1,   203,    -1,    23,   204,   198,
     201,   198,   203,    -1,    23,   204,   198,   203,    -1,    23,
     204,   203,    -1,    23,    -1,    24,   204,   198,   201,   198,
     203,    -1,    24,   204,   266,   201,   198,   203,    -1,    19,
     204,   198,   203,    -1,    19,     1,    -1,    19,   204,     1,
     203,    -1,    27,   204,   198,   203,    -1,    27,     1,    -1,
      27,   204,     1,   203,    -1,    25,   204,   198,   203,    -1,
      25,     1,    -1,    25,   204,     1,   203,    -1,    26,   204,
     198,   203,    -1,    26,     1,    -1,    26,   204,     1,   203,
      -1,    28,   204,   198,   203,    -1,    28,     1,    -1,    28,
     204,     1,   203,    -1,    29,   204,   203,    -1,    29,    -1,
      30,   204,   198,   203,    -1,    30,     1,    -1,    30,   204,
       1,   203,    -1,    31,   204,   203,    -1,    31,    -1,    32,
     204,   203,    -1,    32,    -1,    33,   204,   203,    -1,    33,
      -1,    34,   204,   203,    -1,    34,    -1,    35,   204,   195,
     203,    -1,    35,   204,   203,    -1,    35,    -1,    35,   204,
       1,   203,    -1,    43,   204,   227,   203,    -1,    43,   204,
       1,   203,    -1,    43,     1,    -1,    44,   204,   195,   203,
      -1,    44,   204,     1,   203,    -1,    44,     1,    -1,    45,
     204,   231,   203,    -1,    45,   204,     1,   203,    -1,    45,
       1,    -1,    46,   204,   195,   203,    -1,    46,   204,     1,
     203,    -1,    46,     1,    -1,    47,   204,   203,    -1,    47,
     204,     1,   203,    -1,    47,     1,    -1,    48,   204,   198,
     203,    -1,    48,   204,     1,   203,    -1,    48,     1,    -1,
      49,   204,   198,   203,    -1,    49,   204,     1,   203,    -1,
      49,     1,    -1,    78,   204,   198,   201,   198,   201,   198,
     203,    -1,    78,   204,   198,   201,   198,   201,   198,   201,
     195,   203,    -1,    80,   204,   198,   201,   198,   203,    -1,
      79,   204,   198,   201,   198,   201,   266,   203,    -1,   197,
     204,   203,    -1,   197,   204,   286,   203,    -1,   197,   204,
       1,   203,    -1,   197,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   441,   441,   444,   445,   446,   449,   450,   451,   451,
     452,   452,   453,   453,   454,   454,   455,   455,   456,   456,
     457,   457,   458,   458,   460,   463,   476,   483,   496,   497,
     498,   506,   513,   516,   517,   520,   521,   522,   526,   527,
     528,   529,   530,   531,   532,   535,   536,   540,   547,   557,
     558,   559,   563,   570,   571,   572,   573,   574,   575,   581,
     582,   583,   584,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   641,
     642,   649,   650,   657,   658,   665,   666,   673,   674,   681,
     682,   696,   710,   711,   718,   719,   726,   727,   734,   735,
     742,   743,   750,   751,   761,   771,   781,   791,   800,   808,
     809,   817,   818,   825,   826,   836,   837,   847,   848,   858,
     859,   869,   870,   877,   878,   885,   886,   893,   894,   895,
     896,   897,   898,   901,   902,   905,   906,   921,   924,   929,
     931,   932,   933,   939,   941,   953,   955,   958,   959,   962,
     963,   970,   971,   978,   979,   983,  1010,  1011,  1019,  1020,
    1023,  1024,  1027,  1028,  1038,  1041,  1042,  1043,  1046,  1085,
    1086,  1092,  1098,  1102,  1103,  1106,  1140,  1160,  1161,  1164,
    1164,  1175,  1175,  1186,  1186,  1197,  1198,  1201,  1202,  1205,
    1212,  1219,  1226,  1233,  1234,  1241,  1243,  1250,  1252,  1259,
    1260,  1267,  1268,  1275,  1276,  1283,  1287,  1294,  1301,  1308,
    1315,  1317,  1324,  1326,  1333,  1335,  1342,  1343,  1350,  1351,
    1358,  1361,  1364,  1371,  1376,  1384,  1399,  1402,  1408,  1411,
    1419,  1425,  1428,  1434,  1437,  1445,  1448,  1456,  1459,  1467,
    1470,  1482,  1485,  1486,  1487,  1488,  1489,  1490,  1493,  1494,
    1497,  1498,  1499,  1500,  1502,  1503,  1506,  1507,  1510,  1511,
    1512,  1515,  1516,  1517,  1520,  1534,  1539,  1540,  1541,  1543,
    1546,  1548,  1550,  1552,  1554,  1558,  1560,  1562,  1563,  1566,
    1569,  1572,  1575,  1578,  1581,  1584,  1586,  1588,  1589,  1592,
    1594,  1595,  1596,  1598,  1599,  1600,  1602,  1605,  1606,  1608,
    1609,  1610,  1612,  1614,  1615,  1616,  1630,  1632,  1634,  1636,
    1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,  1669,  1670,
    1681,  1682,  1689,  1690,  1693,  1694,  1706,  1710,  1711,  1712,
    1713,  1714,  1715,  1716,  1717,  1718,  1719,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1732,  1735,  1738,  1741,  1744,  1747,
    1750,  1753,  1756,  1759,  1762,  1765,  1778,  1791,  1813,  1814,
    1815,  1816,  1817,  1820,  1821,  1822,  1825,  1826,  1827,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1839,  1847,  1857,  1865,
    1874,  1875,  1877,  1878,  1881,  1890,  1899,  1907,  1915,  1924,
    1933,  1941,  1952,  1958,  1966,  1971,  1980,  1984,  1991,  1997,
    2004,  2005,  2008,  2014,  2015,  2017,  2018,  2019,  2020,  2021,
    2027,  2033,  2039,  2045,  2048,  2054,  2055,  2057,  2059,  2060,
    2061,  2063,  2064,  2066,  2067,  2069,  2070,  2072,  2073,  2075,
    2076,  2078,  2079,  2083,  2086,  2087,  2091,  2095,  2096,  2100,
    2104,  2105,  2111,  2112,  2114,  2120,  2121,  2123,  2125,  2126,
    2129,  2131,  2132,  2134,  2136,  2137,  2140,  2142,  2143,  2145,
    2153,  2155,  2157,  2160,  2183,  2198,  2200,  2201,  2203,  2205,
    2206,  2208,  2210,  2211,  2213,  2215,  2216,  2218,  2220,  2221,
    2223,  2224,  2225,  2227,  2228,  2230,  2232,  2233,  2234,  2235,
    2237,  2238,  2240,  2242,  2250,  2257,  2264,  2267,  2278,  2280,
    2281,  2297,  2299,  2300,  2304,  2307,  2308,  2312,  2315,  2316,
    2319,  2322,  2323,  2327,  2330,  2331,  2335,  2338,  2339,  2348,
    2361,  2368,  2377,  2394,  2411,  2413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "SEND", "DROP", "EXIT",
  "RETURN", "LOG_TOK", "ERROR", "ROUTE", "ROUTE_FAILURE", "ROUTE_ONREPLY",
  "ROUTE_BRANCH", "ROUTE_ERROR", "ROUTE_LOCAL", "ROUTE_STARTUP",
  "ROUTE_TIMER", "SET_HOST", "SET_HOSTPORT", "PREFIX", "STRIP",
  "STRIP_TAIL", "APPEND_BRANCH", "PV_PRINTF", "SET_USER", "SET_USERPASS",
  "SET_PORT", "SET_URI", "REVERT_URI", "SET_DSTURI", "RESET_DSTURI",
  "ISDSTURISET", "FORCE_RPORT", "FORCE_LOCAL_RPORT", "FORCE_TCP_ALIAS",
  "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "SBREAK", "WHILE",
  "SET_ADV_ADDRESS", "SET_ADV_PORT", "FORCE_SEND_SOCKET",
  "SERIALIZE_BRANCHES", "NEXT_BRANCHES", "USE_BLACKLIST",
  "UNUSE_BLACKLIST", "MAX_LEN", "SETDEBUG", "SETFLAG", "RESETFLAG",
  "ISFLAGSET", "SETBFLAG", "RESETBFLAG", "ISBFLAGSET", "SETSFLAG",
  "RESETSFLAG", "ISSFLAGSET", "METHOD", "URI", "FROM_URI", "TO_URI",
  "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "PROTO", "AF", "MYSELF",
  "MSGLEN", "UDP", "TCP", "TLS", "SCTP", "NULLV", "CACHE_STORE",
  "CACHE_FETCH", "CACHE_REMOVE", "DEBUG", "FORK", "LOGSTDERROR",
  "LOGFACILITY", "LOGNAME", "AVP_ALIASES", "LISTEN", "ALIAS",
  "AUTO_ALIASES", "DNS", "REV_DNS", "DNS_TRY_IPV6", "DNS_RETR_TIME",
  "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH", "MAX_WHILE_LOOPS",
  "PORT", "CHILDREN", "CHECK_VIA", "MEMLOG", "MEMDUMP", "SIP_WARNING",
  "SOCK_MODE", "SOCK_USER", "SOCK_GROUP", "UNIX_SOCK",
  "UNIX_SOCK_CHILDREN", "UNIX_TX_TIMEOUT", "SERVER_SIGNATURE",
  "SERVER_HEADER", "USER_AGENT_HEADER", "LOADMODULE", "MPATH", "MODPARAM",
  "MAXBUFFER", "USER", "GROUP", "CHROOT", "WDIR", "MHOMED", "DISABLE_TCP",
  "TCP_ACCEPT_ALIASES", "TCP_CHILDREN", "TCP_CONNECT_TIMEOUT",
  "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME", "TCP_POLL_METHOD",
  "TCP_MAX_CONNECTIONS", "TCP_OPT_CRLF_PINGPONG", "DISABLE_TLS", "TLSLOG",
  "TLS_PORT_NO", "TLS_METHOD", "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT",
  "TLS_SERVER_DOMAIN", "TLS_CLIENT_DOMAIN", "TLS_CLIENT_DOMAIN_AVP",
  "SSLv23", "SSLv2", "SSLv3", "TLSv1", "TLS_VERIFY_CLIENT",
  "TLS_VERIFY_SERVER", "TLS_REQUIRE_CLIENT_CERTIFICATE", "TLS_CERTIFICATE",
  "TLS_PRIVATE_KEY", "TLS_CA_LIST", "TLS_CIPHERS_LIST",
  "ADVERTISED_ADDRESS", "ADVERTISED_PORT", "DISABLE_CORE", "OPEN_FD_LIMIT",
  "MCAST_LOOPBACK", "MCAST_TTL", "TOS", "DISABLE_DNS_FAILOVER",
  "DISABLE_DNS_BLACKLIST", "DST_BLACKLIST", "DISABLE_STATELESS_FWD",
  "DB_VERSION_TABLE", "EQUAL", "EQUAL_T", "GT", "LT", "GTE", "LTE", "DIFF",
  "MATCH", "NOTMATCH", "COLONEQ", "PLUSEQ", "MINUSEQ", "SLASHEQ", "MULTEQ",
  "MODULOEQ", "BANDEQ", "BOREQ", "BXOREQ", "AND", "OR", "BRSHIFT",
  "BLSHIFT", "BXOR", "BAND", "BOR", "MODULO", "MULT", "SLASH", "MINUS",
  "PLUS", "BNOT", "NOT", "NUMBER", "ZERO", "ID", "STRING", "SCRIPTVAR",
  "IPV6ADDR", "COMMA", "SEMICOLON", "RPAREN", "LPAREN", "LBRACE", "RBRACE",
  "LBRACK", "RBRACK", "AS", "DOT", "CR", "COLON", "ANY", "SCRIPTVARERR",
  "$accept", "cfg", "statements", "statement", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "listen_id", "proto", "port", "snumber",
  "phostport", "id_lst", "blst_elem", "blst_elem_list", "assign_stm",
  "module_stm", "ip", "ipv4", "ipv6addr", "ipv6", "tls_server_domain_stm",
  "$@9", "tls_client_domain_stm", "$@10", "$@11", "tls_server_decls",
  "tls_client_decls", "tls_server_var", "tls_client_var", "route_name",
  "route_stm", "failure_route_stm", "onreply_route_stm",
  "branch_route_stm", "error_route_stm", "local_route_stm",
  "startup_route_stm", "timer_route_stm", "exp", "equalop", "compop",
  "matchop", "intop", "strop", "uri_type", "script_var", "exp_elem",
  "exp_cond", "ipnet", "host_sep", "host", "assignop", "assignexp",
  "assign_cmd", "exp_stm", "stm", "actions", "action", "if_cmd",
  "while_cmd", "switch_cmd", "switch_stm", "case_stms", "case_stm",
  "default_stm", "module_func_param", "cmd", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   215,   216,   217,   217,   217,   218,   218,   219,   218,
     220,   218,   221,   218,   222,   218,   223,   218,   224,   218,
     225,   218,   226,   218,   218,   227,   227,   227,   228,   228,
     228,   228,   228,   229,   229,   230,   230,   230,   231,   231,
     231,   231,   231,   231,   231,   232,   232,   233,   233,   234,
     234,   234,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     236,   236,   236,   237,   237,   238,   239,   240,   240,   242,
     241,   244,   243,   245,   243,   246,   246,   247,   247,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   250,   250,   250,   251,   251,   251,   252,   252,   253,
     253,   253,   254,   254,   255,   255,   256,   256,   257,   257,
     258,   258,   259,   259,   259,   259,   259,   259,   260,   260,
     261,   261,   261,   261,   262,   262,   263,   263,   264,   264,
     264,   265,   265,   265,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   269,   269,
     269,   269,   270,   270,   271,   271,   271,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   274,   274,   274,   275,   275,
     275,   275,   275,   276,   276,   276,   277,   277,   277,   278,
     278,   278,   278,   278,   278,   278,   279,   279,   280,   281,
     282,   282,   283,   283,   284,   284,   284,   284,   284,   284,
     284,   284,   285,   285,   286,   286,   286,   286,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     3,
       3,     5,     3,     5,     3,     1,     2,     9,    10,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     2,     7,     3,     3,     3,     2,     2,     2,
       8,     8,     2,     1,     1,     7,     1,     1,     3,     0,
      10,     0,    10,     0,     8,     1,     2,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     4,     7,     2,     7,     2,     4,
       7,     2,     7,     2,     4,     2,     4,     2,     4,     2,
       9,     2,     3,     3,     2,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     2,     3,     3,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     3,     2,     3,     3,
       1,     3,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     1,     1,
       1,     3,     2,     1,     3,     2,     2,     1,     2,     2,
       1,     1,     1,     2,     1,     2,     3,     5,     3,     7,
       2,     1,     2,     1,     6,     5,     4,     3,     6,     5,
       4,     3,     3,     2,     1,     3,     1,     3,     4,     3,
       2,     4,     4,     2,     4,     3,     1,     3,     1,     4,
       4,     3,     1,     4,     6,     2,     4,     4,     3,     2,
       4,     2,     4,     2,     4,     2,     4,     2,     4,     2,
       4,     2,     6,     4,     2,     6,     4,     2,     6,     4,
       2,     6,     2,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     6,
       4,     3,     1,     6,     6,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       3,     1,     4,     2,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     4,     3,     1,     4,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     3,
       4,     2,     4,     4,     2,     4,     4,     2,     8,    10,
       6,     8,     3,     4,     4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,   158,   159,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    71,     0,    73,     0,    75,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   198,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,   192,     0,     0,
       0,     0,     1,     5,     3,     0,     9,     0,    11,     0,
      13,     0,    15,     0,    17,     0,    19,     0,    21,     0,
      23,    53,     0,     0,    35,    52,    55,    54,    57,    56,
      59,    58,    61,    60,    63,    62,   167,    28,    29,    30,
      31,     0,   354,    26,   206,     0,    32,    38,     0,    45,
     166,    25,   203,   207,   204,    27,   169,   168,   171,   170,
      65,    64,    67,    66,    68,    70,    72,    74,    76,    81,
      80,    79,    78,    85,    84,    87,    86,    89,    88,    91,
      90,    93,    92,   161,   160,   163,   162,   165,   164,   188,
     187,     0,    83,    82,    96,    95,    94,    99,    98,    97,
     102,   101,   100,   105,   104,   103,   107,   106,   109,   108,
     111,   110,   113,   112,   115,   114,   117,   116,   119,   118,
     122,   120,   121,   124,   123,   126,   125,   128,   127,   130,
     129,   132,   131,   137,   133,   134,   135,   136,   153,   152,
     155,   154,     0,     0,     0,   157,   156,   139,   138,   141,
     140,   143,   142,   145,   144,   147,   146,   149,   148,   151,
     150,   173,   172,   175,   174,   177,   176,   179,   178,   181,
     180,   183,   182,   186,   184,   185,   189,   191,     0,   194,
     196,   195,   256,     0,     0,   258,     0,   261,     0,     0,
     263,     0,   265,     0,   267,     0,   269,     0,   271,     0,
      37,    36,     0,     0,     0,     0,     0,    46,   353,     0,
       0,     0,     0,   213,     0,     0,     0,     0,   436,   438,
     442,     0,     0,     0,     0,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,   511,     0,   516,   518,   520,
     522,   525,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   404,   295,     0,
       0,     0,   397,   400,   401,   402,     0,   252,   251,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,    44,    33,    34,    39,    40,    42,   356,   355,     0,
       0,     0,     0,     0,   430,     0,   433,     0,     0,     0,
       0,   445,     0,   472,     0,   475,     0,   478,     0,   496,
       0,   481,     0,   487,     0,   484,     0,     0,     0,   502,
       0,   505,     0,   499,     0,   508,     0,     0,   513,     0,
       0,     0,     0,     0,     0,     0,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,   299,   277,   296,   390,   297,   389,
     388,     0,     0,   529,     0,   532,     0,   535,     0,   538,
       0,   541,     0,   544,     0,   547,     0,   449,     0,   451,
       0,   453,     0,   455,     0,   464,     0,   467,     0,   470,
       0,   457,     0,   459,     0,   461,     0,     0,     0,     0,
     555,     0,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,   403,   398,   254,   396,   405,   399,     0,
       0,   259,     0,     0,   264,   266,   268,     0,     0,     0,
       0,     0,   209,     0,   211,     0,     0,    50,     0,     0,
       0,   429,     0,     0,   435,   437,   441,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,     0,
       0,   515,   517,   519,   521,     0,     0,   524,   308,   278,
     280,   281,   282,   283,   279,   284,   285,   288,   289,   290,
       0,   338,   288,     0,   321,   286,   287,     0,   342,   288,
       0,   324,     0,   327,     0,   330,     0,   347,     0,   334,
       0,   274,     0,   392,     0,     0,     0,     0,     0,   368,
       0,   367,     0,   370,   371,     0,   372,     0,     0,     0,
     406,   393,   318,   288,     0,   288,   289,     0,     0,     0,
     408,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     426,   424,   552,     0,   386,   387,   385,     0,     0,     0,
       0,     0,     0,    41,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,     0,     0,     0,    51,
       0,   193,   431,   428,   434,   432,   439,   440,   446,   443,
       0,   473,     0,   476,   474,   479,   477,   497,   495,   482,
     480,   488,   486,   485,   483,     0,   490,     0,     0,   503,
     501,   506,   504,   500,   498,   509,   507,   514,   512,   526,
     523,   307,   306,   305,   336,   350,   303,   337,   335,   304,
     320,   319,   340,   301,   341,   339,   302,   323,   322,   326,
     325,   329,   328,   346,   344,   345,   343,   333,   332,   331,
     275,   391,   288,     0,   288,     0,   383,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     272,   273,   395,     0,     0,   316,   317,   315,   300,   313,
     314,   312,   311,   310,   309,     0,   528,   527,   531,   530,
     534,   533,   537,   536,   540,   543,   542,   546,   545,   447,
     450,   452,   454,     0,   463,     0,   466,     0,   469,   456,
     458,   460,     0,     0,     0,   554,     0,   553,     0,     0,
       0,     0,     0,     0,   200,   201,     0,     0,     0,     0,
       0,     0,     0,   214,   218,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,   384,   382,   381,   380,   378,
     379,   377,   375,   376,   374,   373,   394,   407,     0,     0,
       0,     0,     0,     0,     0,   427,   425,   255,   257,   260,
     262,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,   215,   240,   236,   237,   238,   239,   250,   249,   242,
     241,   244,   243,   246,   245,   248,   247,     0,     0,     0,
     444,   471,   489,   493,   494,   351,   349,   348,     0,     0,
     411,   413,   462,   465,   468,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   216,   212,     0,
       0,     0,     0,   409,     0,   412,   410,     0,     0,   270,
     223,   219,   220,   221,   222,   233,   232,   235,   234,   225,
     224,   227,   226,   229,   228,   231,   230,     0,     0,   421,
     417,   423,     0,   548,   551,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   419,     0,   415,     0,   549,
       0,    47,   418,   414,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   217,   218,   464,   711,   219,   220,   617,   618,
      86,    87,   221,   222,   223,   224,    88,   777,    89,   786,
     471,   990,   784,   991,   785,   450,   176,   178,   180,   182,
     184,   186,   188,   190,   532,   685,   678,   679,   727,   728,
     712,   439,   535,   714,   836,   380,   225,   592,   715,   440,
     538,   720,   441,   442,   443,   444,   445,  1019,  1020,  1021,
    1046,   763,   446
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -769
static const yytype_int16 yypact[] =
{
    3695,   -95,   -67,   -45,   -31,   -20,   -19,    -2,     2,     8,
      12,    37,   245,    55,   429,   440,   452,   521,   268,   277,
     289,   375,   389,   392,   480,   539,   552,   562,   135,   564,
      18,   565,   566,   569,   588,   590,   591,   597,   599,   602,
     607,   626,   636,   685,   710,   716,   731,   751,   776,   777,
     779,   789,   -26,    13,   790,   791,   814,   816,   817,   818,
     827,   839,   840,   846,   848,   849,   852,   861,   864,   531,
     533,   866,   868,   869,  -769,   410,  2445,  -769,   611,   650,
     670,   678,   778,   807,   775,  1016,  -769,  -769,  -769,  -769,
    -769,   443,   193,   444,   425,   158,   163,    16,    38,   445,
     446,   447,  -769,   865,  -769,   872,  -769,   873,  -769,   874,
    -769,   875,   450,   453,   454,   455,   456,   457,   458,   459,
     169,   184,  -769,  -769,   187,  -769,   845,   460,   181,   183,
     186,   189,   461,   462,   463,   464,   475,   477,   478,   195,
     479,   490,   492,   497,   498,   535,   500,   502,   606,  1155,
     503,   504,   505,   506,   192,   205,   206,   207,    57,   508,
     509,   510,   511,   512,   216,  -769,   876,  -769,   880,   881,
     882,   208,  -769,   -95,  -769,    43,  -769,    51,  -769,    62,
    -769,    59,  -769,    19,  -769,    44,  -769,    69,  -769,    66,
    -769,  -769,   885,   890,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,   856,  -769,  -769,  -769,   893,  -769,   860,   870,   931,
    -769,  -769,  -769,  -769,  -769,  -162,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,   889,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,   886,   891,   888,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   897,  -769,
    -769,  -769,  -769,  3553,   349,  -769,   349,  -769,  3553,   349,
    -769,   349,  -769,  3553,  -769,  3553,  -769,  3553,  -769,   349,
    -769,  -769,   916,   902,    24,   925,   925,  -769,  -769,   432,
     927,   914,  -158,  -769,  -158,   922,    26,    30,   926,   929,
     930,    71,    72,    73,    74,    75,    77,    78,    79,   932,
     943,    80,    81,    82,    83,   944,    84,   945,   946,   948,
     959,   985,  2606,   987,  2606,    85,    86,    87,    98,   104,
     105,   106,   108,   109,   114,   116,   122,   127,   130,   133,
     136,   146,   988,   989,   998,   149,  -769,  -769,  -769,  1285,
     933,   940,  -769,  -769,  -769,  -769,   115,  -769,  -769,  -769,
     935,  1005,  1152,  1006,  1007,  1215,  1281,  1493,  1025,   941,
    -769,  -769,  -769,  -769,  -769,  1015,  1017,  -769,  -769,  1027,
    1009,   936,  1044,  -143,  -769,   157,  -769,   209,  1051,  1052,
     831,  -769,   177,  -769,   211,  -769,   179,  -769,   214,  -769,
     220,  -769,   226,  -769,   513,  -769,   514,  -139,  -145,  -769,
     227,  -769,   279,  -769,   302,  -769,   304,  1053,  -769,   310,
    1062,  1080,  1089,  1093,   159,   613,  -769,  -769,  -769,   871,
     629,   887,   659,   950,  1000,    33,  1112,  2606,  2606,  2949,
    2684,  -769,  2886,   937,  1267,  -769,  -769,  -769,  -769,  -769,
    -769,   -73,  2886,  -769,    65,  -769,   515,  -769,    46,  -769,
     516,  -769,   103,  -769,   323,  -769,   326,  -769,  -138,  -769,
    1102,  -769,  1103,  -769,  1123,  -769,  1125,  -769,  1126,  -769,
    1127,  -769,  1148,  -769,  1153,  -769,  1157,  1158,  1159,  1165,
    -769,   154,  1287,  1288,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  2684,  -769,  -769,  -769,  -769,  -769,  -769,  1182,
    1183,  -769,  1185,  1186,  -769,  -769,  -769,  1198,  1199,  -158,
    -158,   -29,  -769,   947,  -769,  1191,   801,  -769,    41,  1193,
    1195,  -769,  1196,  1210,  -769,  -769,  -769,  1212,  1213,  1216,
    1217,  1188,  1219,  1200,  1220,  1221,  1222,  1223,  1224,  1225,
    1246,  1247,  1248,  1249,  1250,  1251,   231,  -769,  1201,  1254,
    1253,  1273,  1274,  1276,  1278,  1279,  1282,  1286,  -769,  1289,
    1290,  -769,  -769,  -769,  -769,  1301,  1302,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
     198,  -769,   519,   200,  -769,  -769,  -769,   517,  -769,   821,
     202,  -769,   518,  -769,    27,  -769,   525,  -769,   723,  -769,
     442,  -769,  -132,  -769,  1556,   871,   887,  2684,   553,  -769,
    2684,  -769,   937,  1240,  -769,  1184,  -769,  2606,  2606,  3161,
    1363,  -769,  -769,  1347,   204,   358,   -98,   247,   467,  1303,
    -769,  1304,  1305,  1306,  1307,  1327,   -74,  1329,  1330,  1331,
    -769,  1340,  1351,  1352,  1353,  1355,  -769,  1364,  1365,  1366,
     330,   487,   530,  1367,  1390,  1392,  1395,  1396,  1405,  1414,
    -769,  -769,  -769,   545,  -769,  -769,  1283,  3553,  3553,  3553,
    3553,  1280,  1408,  -769,  -769,  1416,  1417,  1419,  1321,  1323,
    1328,  1458,  1459,  1470,   939,  -769,  1432,   801,  1437,  -769,
    -143,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    1292,  -769,  1441,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  1461,  -769,  1463,  1464,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  1473,  -769,  -769,  -769,  -162,
    -769,  -769,  -769,  -769,  -769,  -769,  -162,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  1601,   327,  1612,   347,  -769,  1194,   350,  2684,
    2684,  2684,  2684,  2684,  2684,  2684,  2684,  2684,  2684,  -769,
    -769,  -769,  -769,  1622,  3224,  -769,  -769,  -769,  -162,  -769,
    -769,  -769,  -769,  -769,  -769,  1479,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  1490,  -769,  1491,  -769,  1492,  -769,  -769,
    -769,  -769,  1495,  1496,  1498,  -769,     0,  -769,  1834,  1897,
    1963,  2175,  1483,  1494,  -769,  -769,   625,   662,   526,   372,
     418,   419,   420,  -769,  -769,   947,  1497,   606,  -769,  1488,
    1500,  1501,  1502,  1503,    61,  -769,   377,   377,   377,   377,
     377,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  1658,  1505,
    1506,  1507,  1510,  1511,  1512,  -769,  -769,  -769,  -769,  -769,
    -769,  3553,  -769,  1550,  1551,  1553,  1554,  1555,  1557,  1558,
     915,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  1197,   606,  1518,
    -769,  -769,  -769,  -769,  -769,  -769,   856,  -769,   488,  1516,
     628,  -769,  -769,  -769,  -769,  1525,   -73,  -769,  2238,   668,
     527,   528,   421,   422,   426,   427,  -769,  -769,  -769,  1523,
    -158,  1513,  1514,  -769,  1515,  -769,  -769,   546,  1526,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -158,  1527,  3290,
    3490,  3553,  1535,  -769,  -769,  1530,  1534,  1531,   811,  1532,
     877,  2304,  1533,  1537,  1536,  -769,  1538,  -769,  1539,  -769,
    1540,  -769,  -769,  -769,  -769
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -769,  -769,  -769,  1661,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -150,   -23,  -378,   -91,  1190,   -52,   952,  -769,
    -769,  -769,  -147,  -769,  1529,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,   800,   756,  -768,   407,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -374,  -342,    17,  -769,   524,  -347,
    -382,  -403,  -769,  -379,  -676,  -769,  -160,  -769,  -577,  -376,
    -769,  -539,  -353,  -434,  -371,  -769,  -769,  -769,  -769,   727,
    -769,  -769,  -388
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -423
static const yytype_int16 yytable[] =
{
     195,   312,   314,   730,   470,   452,   472,   596,   332,   534,
     455,   534,   456,   843,   457,   766,   944,   206,   596,   125,
     362,   596,   596,   596,   540,   461,   540,   474,   849,   378,
     533,   476,   533,   536,   697,   536,   537,   462,   537,   226,
     542,   539,   789,   539,   352,   364,   227,   735,   379,   717,
     718,   615,   355,   648,   436,   463,   102,   745,   331,   646,
     360,   616,  1015,   357,   647,   746,   731,   368,    90,   438,
     366,   860,   481,   483,   485,   487,   489,   628,   491,   493,
     495,   499,   501,   503,   505,   508,   543,   545,   547,   207,
     208,   209,   210,  -287,  -287,   649,    91,  -287,   721,   549,
     207,   208,   209,   210,   739,   551,   553,   555,   721,   557,
     559,   207,   208,   209,   210,   561,   597,   563,    92,   207,
     208,   209,   210,   565,   534,   534,   436,   713,   567,   901,
     866,   569,    93,   867,   571,   376,   122,   573,   729,   540,
     540,   438,   716,    94,    95,   533,   533,   575,   536,   536,
     580,   537,   537,   701,   702,   759,   539,   539,   619,   202,
     665,    96,   192,   193,   204,    97,   194,   377,   680,   775,
     255,    98,   683,   677,   690,    99,   704,   682,   629,   689,
     634,   148,   264,   698,   267,   257,   724,   270,   259,   713,
     273,   723,   725,   323,   196,   975,   290,   669,   976,   831,
     100,   837,   674,   844,   716,   886,   325,   327,   329,   350,
     622,   211,   632,   212,   213,   636,   214,   343,   103,   462,
     149,   638,   126,   215,   363,   465,   466,   640,   650,   216,
     475,   773,   774,   211,   477,   212,   213,   463,   214,   944,
     216,   211,   790,   212,   213,   215,   214,   791,   353,   365,
     354,   216,   211,   215,   212,   213,  1016,   214,   356,   216,
     211,   214,   212,   213,   215,   214,   361,   358,   215,   359,
     596,  1009,   215,   369,   367,   482,   484,   486,   488,   490,
     652,   492,   494,   496,   500,   502,   504,   506,   509,   544,
     546,   548,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   550,   654,   713,   656,   740,   713,   552,   554,
     556,   659,   558,   560,   534,   534,   856,   598,   562,   716,
     564,   531,   716,   531,   741,   894,   566,   743,   837,   540,
     540,   568,  1039,   123,   570,   533,   533,   572,   536,   536,
     574,   537,   537,   880,   881,   967,   539,   539,   844,   760,
     576,   886,   761,   581,   666,   620,   203,   762,   863,   865,
     621,   205,   667,   862,   864,   868,   883,   256,   192,   193,
     723,   725,   194,   999,   447,   630,   448,   449,   265,   266,
     268,   269,   258,   271,   272,   260,   274,   275,   197,   627,
     324,   631,   291,   292,   732,   832,   833,   212,   838,   212,
     845,   212,   887,   326,   328,   330,   351,   623,   101,   633,
     172,   344,   637,   345,   928,   929,   930,   931,   639,  1001,
    1003,  1005,  1059,  1061,   641,   651,   200,  1063,  1065,   889,
     104,   112,   815,   467,   816,   890,   531,   531,   192,   193,
     113,   106,   194,   857,   191,   198,   228,   230,   232,   596,
     721,   239,   114,   108,   241,   243,   245,   247,   249,   251,
     253,   262,   276,   278,   280,   282,   713,   713,   713,   713,
     713,   713,   713,   713,   713,   713,   284,   653,   286,   288,
     293,   716,   716,   716,   716,   716,   716,   716,   716,   716,
     716,   295,   858,   297,   596,   596,   596,   596,   299,   301,
     655,   308,   657,   310,   315,   317,   319,   321,   660,   333,
     335,   337,   339,   341,   642,   644,   733,   737,   840,   847,
     776,   742,   110,   839,   744,   838,   851,   997,  1055,  1057,
     846,   913,   165,   914,   167,   835,   303,   686,   115,   686,
     686,   686,   835,   686,   447,   845,   448,   449,   887,  -286,
    -286,   726,   116,  -286,   580,   117,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,   888,   874,   875,   876,   877,   878,
    1000,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
     834,  -369,   105,   788,   596,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,   107,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,   668,   109,  1002,  1004,  1006,  1060,
    1062,   175,   201,  1048,  1064,  1066,   531,   531,  1028,  -352,
     684,  -369,  -369,  -369,   192,   193,   891,   859,   194,   199,
     229,   231,   233,   118,   596,   240,   596,   596,   242,   244,
     246,   248,   250,   252,   254,   263,   277,   279,   281,   283,
     691,   177,  1068,   992,   892,   893,   436,  1018,  1044,  1050,
     285,   850,   287,   289,   294,   304,   305,   306,   307,   192,
     193,   438,   179,   194,   111,   296,  1041,   298,   915,  1075,
     916,   181,   300,   302,   166,   309,   168,   311,   316,   318,
     320,   322,   119,   334,   336,   338,   340,   342,   643,   645,
     734,   738,   841,   848,   211,   120,  1078,  1080,  1081,   214,
     852,   998,  1056,  1058,   853,   121,   215,   124,   127,   128,
     726,   917,   129,   918,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,   926,  1072,   927,  1073,
    -369,   130,  -369,   131,   132,  -369,  -369,   581,  -369,   983,
     133,  -369,   134,   451,   946,   135,   453,  -369,   454,   984,
     136,   985,   986,   987,   988,   989,   458,   669,   670,   671,
     672,   673,   674,   675,   676,   516,   517,   518,   854,   137,
     855,   187,   183,   669,   670,   671,   672,   673,   674,   138,
     835,   211,   993,   994,   995,   996,   214,  1017,  1051,  1052,
    1053,  1054,   594,   215,   386,   387,   388,   389,   390,   391,
     392,   393,   185,   669,   670,   671,   672,   673,   674,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   139,   413,
    -420,  -420,  1086,   414,   415,   416,   417,   418,   419,   420,
     421,   835,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   681,   140,   207,   208,   209,   210,   594,   141,
     386,   387,   388,   389,   390,   391,   392,   393,   688,   432,
     433,   434,   842,   635,   142,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   143,   413,  -416,  -416,  1088,   414,
     415,   416,   417,   418,   419,   420,   421,  1042,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   722,   144,
     145,   594,   146,   386,   387,   388,   389,   390,   391,   392,
     393,   693,   147,   150,   151,   432,   433,   434,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   152,   413,   153,
     154,   155,   414,   415,   416,   417,   418,   419,   420,   421,
     156,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   695,   157,   158,   207,   208,   209,   210,   435,   159,
     436,   160,   161,   437,   216,   162,   211,  -420,   432,   433,
     434,   214,   192,   193,   163,   438,   194,   164,   215,   169,
     436,   170,   171,   189,   626,   669,   670,   671,   672,   673,
     674,   675,   676,   261,   687,   438,   692,   694,   696,   983,
     700,   669,   670,   671,   672,   673,   674,   675,   676,   984,
     234,   985,   986,   987,   988,   989,   372,   235,   236,   237,
     238,   346,   374,   778,   435,   347,   436,   349,   348,   437,
     370,   778,   375,  -416,   779,   371,   780,   781,   782,   783,
     381,   438,   779,   214,   780,   781,   782,   783,   382,   383,
     384,   669,   670,   671,   672,   673,   674,   675,   676,   385,
     460,   459,   469,   699,   669,   670,   671,   672,   673,   674,
     211,  1036,   212,   213,   468,   214,   211,   473,   212,   213,
     478,   214,   215,   479,   480,   593,   497,   435,   215,   436,
     376,   613,   437,   599,   216,   943,   595,   498,   507,   510,
     511,   608,   512,   594,   438,   386,   387,   388,   389,   390,
     391,   392,   393,   513,   669,   670,   671,   672,   673,   674,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   514,
     413,   541,   577,   578,   414,   415,   416,   417,   418,   419,
     420,   421,   579,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   600,   602,   603,   594,   612,   386,   387,
     388,   389,   390,   391,   392,   393,   607,   609,   611,   610,
     432,   433,   434,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   614,   413,   624,   625,   658,   414,   415,   416,
     417,   418,   419,   420,   421,   661,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   669,   670,   671,   672,
     673,   674,   594,   662,   386,   387,   388,   389,   390,   391,
     392,   393,   663,   432,   433,   434,   664,   747,   748,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   749,   413,
     750,   751,   752,   414,   415,   416,   417,   418,   419,   420,
     421,   778,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   779,   753,   780,   781,   782,   783,   754,   435,
     211,   436,   755,   313,   437,   214,   756,   757,   601,   432,
     433,   434,   215,   758,   764,   765,   438,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   767,   768,   800,
     769,   770,   879,   771,   772,   787,   792,   955,   793,   794,
     884,   802,   817,  1038,   669,   670,   671,   672,   673,   674,
     675,   676,   435,   795,   436,   796,   797,   437,   885,   798,
     799,   604,   801,   803,   804,   805,   806,   807,   808,   438,
     582,   669,   670,   671,   672,   673,   674,   675,   676,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   582,   809,
     810,   811,   812,   813,   814,   818,   819,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   869,   870,   871,   872,
     873,   874,   875,   876,   877,   878,   820,   821,   435,   822,
     436,   823,   824,   437,   937,   825,   938,   605,   932,   826,
     949,   939,   827,   828,   594,   438,   386,   387,   388,   389,
     390,   391,   392,   393,   829,   830,   895,   896,   897,   898,
     899,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     900,   413,   902,   903,   904,   414,   415,   416,   417,   418,
     419,   420,   421,   905,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   906,   907,   908,   594,   909,   386,
     387,   388,   389,   390,   391,   392,   393,   910,   911,   912,
     919,   432,   433,   434,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   920,   413,   921,   922,   923,   414,   415,
     416,   417,   418,   419,   420,   421,   924,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   925,   933,   934,
     935,   940,   941,   594,   936,   386,   387,   388,   389,   390,
     391,   392,   393,   942,   432,   433,   434,   945,   947,   950,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   951,
     413,   952,   953,   954,   414,   415,   416,   417,   418,   419,
     420,   421,   834,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   842,   968,   969,   970,   971,   981,   982,
     435,  1010,   436,   972,   973,   437,   974,  1018,  1008,   606,
     432,   433,   434,  1011,  1012,  1013,  1014,   438,  1022,  1023,
    1024,  1025,  1026,  1029,  1030,  1027,  1031,  1032,  1033,  1040,
    1034,  1035,  1043,  1047,  1067,  1069,  1070,  1071,  1076,  1074,
    1082,  1083,  1084,  1085,  1087,  1090,  1089,   174,   736,  1091,
    1092,  1093,   948,  1094,   373,  1007,  1037,  1045,     0,     0,
       0,     0,     0,   435,     0,   436,     0,     0,   437,     0,
       0,     0,   861,     0,     0,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   435,
       0,   436,     0,     0,   437,     0,     0,     0,   966,     0,
       0,     0,     0,     0,     0,   594,   438,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,     0,   413,     0,     0,     0,   414,   415,   416,   417,
     418,   419,   420,   421,     0,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,   594,     0,
     386,   387,   388,   389,   390,   391,   392,   393,     0,     0,
       0,     0,   432,   433,   434,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,     0,   413,     0,     0,     0,   414,
     415,   416,   417,   418,   419,   420,   421,     0,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,     0,     0,   594,     0,   386,   387,   388,   389,
     390,   391,   392,   393,     0,   432,   433,   434,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,   413,     0,     0,     0,   414,   415,   416,   417,   418,
     419,   420,   421,     0,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,     0,     0,
       0,   435,     0,   436,     0,     0,   437,     0,     0,     0,
     977,   432,   433,   434,     0,     0,     0,     0,   438,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,     0,   436,     0,     0,   437,
       0,     0,     0,   978,     0,     0,     0,     0,     0,     0,
       0,   438,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,     0,   436,     0,     0,   437,     0,     0,     0,   979,
       0,     0,     0,     0,     0,     0,   594,   438,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
       0,     0,     0,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,     0,   413,     0,     0,     0,   414,   415,   416,
     417,   418,   419,   420,   421,     0,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,   594,
       0,   386,   387,   388,   389,   390,   391,   392,   393,     0,
       0,     0,     0,   432,   433,   434,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,     0,   413,     0,     0,     0,
     414,   415,   416,   417,   418,   419,   420,   421,     0,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,     0,     0,   594,     0,   386,   387,   388,
     389,   390,   391,   392,   393,     0,   432,   433,   434,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,     0,   413,     0,     0,     0,   414,   415,   416,   417,
     418,   419,   420,   421,     0,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,     0,
       0,     0,   435,     0,   436,     0,     0,   437,     0,     0,
       0,   980,   432,   433,   434,     0,     0,     0,     0,   438,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,     0,   436,     0,     0,
     437,     0,     0,     0,  1049,    -2,   173,     0,     0,     0,
       0,     0,   438,     0,     0,    -8,   -10,   -12,   -14,   -16,
     -18,   -20,   -22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,     0,   436,     0,     0,   437,     0,     0,     0,
    -422,     0,     0,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,     0,     0,     0,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,     0,     0,     0,     0,     0,     0,   415,
     416,   417,   418,   419,   420,   421,    74,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,     0,
       0,     0,     0,     0,   432,   433,   434,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
       0,     0,     0,     0,     0,     0,     0,   415,   416,   417,
     418,   419,   420,   421,     0,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   515,   516,   517,   518,   705,
     520,   706,   522,   523,   524,   525,   526,     0,     0,     0,
       0,     0,   432,   433,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   193,     0,
     527,   194,     0,   435,     0,   436,     0,     0,     0,     0,
     528,   529,     0,   530,     0,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   193,   707,     0,   194,
       0,   708,   709,   436,     0,     0,     0,     0,   710,   386,
     387,   388,   389,   390,   391,   392,   393,     0,   438,     0,
       0,     0,     0,     0,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,     0,   413,     0,     0,     0,   414,   415,
     416,   417,   418,   419,   420,   421,     0,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
       0,     0,     0,     0,   432,   433,   434,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,     0,   413,     0,     0,
       0,   414,   415,   416,   417,   418,   419,   420,   421,     0,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   432,   433,   434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   717,   718,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,     0,   436,     0,     0,   437,     0,
       0,   719,     0,     0,     0,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,     0,   436,     0,
       0,   437,     0,     0,     0,   703,     0,     0,     0,     0,
       0,     0,     0,   438,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,     0,     0,     0,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,     0,   413,
       0,     0,     0,   414,   415,   416,   417,   418,   419,   420,
     421,     0,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   432,
     433,   434,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,     0,   413,     0,     0,     0,   414,   415,   416,   417,
     418,   419,   420,   421,     0,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,     0,   432,   433,   434,     0,     0,     0,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,     0,   413,     0,
       0,  1077,   414,   415,   416,   417,   418,   419,   420,   421,
       0,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,     0,     0,     0,   435,     0,
     436,     0,     0,   437,     0,     0,     0,   882,   432,   433,
     434,     0,     0,     0,     0,   438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,     0,   436,     0,     0,   437,     0,     0,   719,
       0,     0,     0,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,     0,   436,
       0,     0,   437,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,   438,     0,     0,     0,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,     0,   413,     0,
       0,  1079,   414,   415,   416,   417,   418,   419,   420,   421,
       0,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   393,     0,     0,     0,     0,   432,   433,
     434,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,   413,     0,     0,     0,   414,   415,   416,   417,   418,
     419,   420,   421,     0,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   433,   434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,     0,   436,
       0,     0,   437,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,   438,    -8,   -10,   -12,   -14,   -16,
     -18,   -20,   -22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,     0,   436,     0,     0,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
      91,   148,   149,   542,   382,   358,   384,   441,   158,   412,
     363,   414,   365,   689,   367,   592,   784,     1,   452,     1,
       1,   455,   456,   457,   412,     1,   414,     1,     1,   191,
     412,     1,   414,   412,     1,   414,   412,   195,   414,     1,
     414,   412,     1,   414,     1,     1,    98,     1,   210,   181,
     182,   194,     1,   198,   199,   213,     1,   195,     1,   198,
       1,   204,     1,     1,   203,   203,     1,     1,   163,   214,
       1,   203,     1,     1,     1,     1,     1,   480,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,    73,
      74,    75,    76,   191,   192,   498,   163,   195,   532,     1,
      73,    74,    75,    76,     1,     1,     1,     1,   542,     1,
       1,    73,    74,    75,    76,     1,     1,     1,   163,    73,
      74,    75,    76,     1,   527,   528,   199,   530,     1,   203,
     707,     1,   163,   710,     1,   209,     1,     1,   541,   527,
     528,   214,   530,   163,   163,   527,   528,     1,   527,   528,
       1,   527,   528,   527,   528,     1,   527,   528,     1,     1,
       1,   163,   191,   192,     1,   163,   195,   219,   515,   198,
       1,   163,   519,   515,   521,   163,   529,   519,     1,   521,
       1,   207,     1,   525,     1,     1,   533,     1,     1,   592,
       1,   533,   534,     1,     1,   195,     1,   164,   198,     1,
     163,     1,   169,     1,   592,     1,     1,     1,     1,     1,
       1,   195,     1,   197,   198,     1,   200,     1,   163,   195,
     207,     1,   204,   207,   205,   375,   376,     1,     1,   213,
     204,   609,   610,   195,   204,   197,   198,   213,   200,  1007,
     213,   195,   201,   197,   198,   207,   200,   206,   205,   205,
     207,   213,   195,   207,   197,   198,   195,   200,   207,   213,
     195,   200,   197,   198,   207,   200,   207,   205,   207,   207,
     704,   947,   207,   207,   205,   204,   204,   204,   204,   204,
       1,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   869,   870,   871,   872,   873,   874,   875,   876,
     877,   878,   204,     1,   707,     1,   203,   710,   204,   204,
     204,     1,   204,   204,   717,   718,   698,   202,   204,   707,
     204,   412,   710,   414,     1,   728,   204,     1,     1,   717,
     718,   204,  1008,   198,   204,   717,   718,   204,   717,   718,
     204,   717,   718,   717,   718,   884,   717,   718,     1,   195,
     204,     1,   198,   204,   195,   198,   198,   203,   705,   706,
     203,   198,   203,   705,   706,   712,   719,   198,   191,   192,
     712,   713,   195,     1,   195,   198,   197,   198,   197,   198,
     197,   198,   198,   197,   198,   198,   197,   198,   195,   480,
     198,   482,   197,   198,   544,   197,   198,   197,   198,   197,
     198,   197,   198,   198,   198,   198,   198,   198,   163,   198,
       0,   195,   198,   197,   767,   768,   769,   770,   198,     1,
       1,     1,     1,     1,   198,   198,     1,     1,     1,    71,
       1,   163,   201,     1,   203,    77,   527,   528,   191,   192,
     163,     1,   195,     1,     1,     1,     1,     1,     1,   883,
     884,     1,   163,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,   869,   870,   871,   872,
     873,   874,   875,   876,   877,   878,     1,   198,     1,     1,
       1,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     878,     1,    50,     1,   928,   929,   930,   931,     1,     1,
     198,     1,   198,     1,     1,     1,     1,     1,   198,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     611,   198,     1,   683,   198,   198,     1,     1,     1,     1,
     690,   201,     1,   203,     1,   682,     1,   520,   163,   522,
     523,   524,   689,   526,   195,   198,   197,   198,   198,   191,
     192,   534,   163,   195,     1,   163,     3,     4,     5,     6,
       7,     8,     9,    10,   724,   188,   189,   190,   191,   192,
     198,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      71,    38,   163,   616,  1028,    42,    43,    44,    45,    46,
      47,    48,    49,   163,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     1,   163,   198,   198,   198,   198,
     198,    10,   197,  1026,   198,   198,   717,   718,   981,   197,
       1,    78,    79,    80,   191,   192,   727,   195,   195,   195,
     195,   195,   195,   163,  1078,   195,  1080,  1081,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
       1,    11,  1040,     1,   197,   198,   199,    39,    40,     1,
     195,   694,   195,   195,   195,   140,   141,   142,   143,   191,
     192,   214,    12,   195,   163,   195,   198,   195,   201,  1067,
     203,    13,   195,   195,   163,   195,   163,   195,   195,   195,
     195,   195,   163,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   163,  1069,  1070,  1071,   200,
     195,   195,   195,   195,     1,   163,   207,   163,   163,   163,
     713,   201,   163,   203,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   201,   201,   203,   203,
     197,   163,   199,   163,   163,   202,   203,   204,   205,   134,
     163,   208,   163,   356,   787,   163,   359,   214,   361,   144,
     163,   146,   147,   148,   149,   150,   369,   164,   165,   166,
     167,   168,   169,   170,   171,    62,    63,    64,    65,   163,
      67,    16,    14,   164,   165,   166,   167,   168,   169,   163,
     947,   195,   140,   141,   142,   143,   200,   954,   140,   141,
     142,   143,     1,   207,     3,     4,     5,     6,     7,     8,
       9,    10,    15,   164,   165,   166,   167,   168,   169,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   163,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,  1008,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     1,   163,    73,    74,    75,    76,     1,   163,
       3,     4,     5,     6,     7,     8,     9,    10,     1,    78,
      79,    80,    71,   486,   163,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,   163,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,  1018,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     1,   163,
     163,     1,   163,     3,     4,     5,     6,     7,     8,     9,
      10,     1,   163,   163,   163,    78,    79,    80,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,   163,    38,   163,
     163,   163,    42,    43,    44,    45,    46,    47,    48,    49,
     163,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     1,   163,   163,    73,    74,    75,    76,   197,   163,
     199,   163,   163,   202,   213,   163,   195,   206,    78,    79,
      80,   200,   191,   192,   163,   214,   195,   163,   207,   163,
     199,   163,   163,    17,   203,   164,   165,   166,   167,   168,
     169,   170,   171,   198,   520,   214,   522,   523,   524,   134,
     526,   164,   165,   166,   167,   168,   169,   170,   171,   144,
     195,   146,   147,   148,   149,   150,   210,   195,   195,   195,
     195,   195,   212,   134,   197,   195,   199,   195,   197,   202,
     195,   134,   212,   206,   145,   195,   147,   148,   149,   150,
     201,   214,   145,   200,   147,   148,   149,   150,   212,   208,
     212,   164,   165,   166,   167,   168,   169,   170,   171,   212,
     208,   195,   198,     1,   164,   165,   166,   167,   168,   169,
     195,   206,   197,   198,   197,   200,   195,   205,   197,   198,
     204,   200,   207,   204,   204,   202,   204,   197,   207,   199,
     209,   205,   202,   208,   213,   206,   206,   204,   204,   204,
     204,   210,   204,     1,   214,     3,     4,     5,     6,     7,
       8,     9,    10,   204,   164,   165,   166,   167,   168,   169,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,   204,
      38,   204,   204,   204,    42,    43,    44,    45,    46,    47,
      48,    49,   204,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,   208,   208,   208,     1,   208,     3,     4,
       5,     6,     7,     8,     9,    10,   201,   212,   201,   212,
      78,    79,    80,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,   208,    38,   203,   203,   203,    42,    43,    44,
      45,    46,    47,    48,    49,   203,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   164,   165,   166,   167,
     168,   169,     1,   203,     3,     4,     5,     6,     7,     8,
       9,    10,   203,    78,    79,    80,   203,   195,   195,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   195,    38,
     195,   195,   195,    42,    43,    44,    45,    46,    47,    48,
      49,   134,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,   145,   195,   147,   148,   149,   150,   195,   197,
     195,   199,   195,   198,   202,   200,   198,   198,   206,    78,
      79,    80,   207,   198,    77,    77,   214,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   205,   205,   201,
     205,   205,   208,   195,   195,   204,   203,   203,   203,   203,
      37,   201,   201,   206,   164,   165,   166,   167,   168,   169,
     170,   171,   197,   203,   199,   203,   203,   202,    71,   203,
     203,   206,   203,   203,   203,   203,   203,   203,   203,   214,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   163,   203,
     203,   203,   203,   203,   203,   201,   203,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   203,   203,   197,   203,
     199,   203,   203,   202,   163,   203,   163,   206,   208,   203,
     198,   163,   203,   203,     1,   214,     3,     4,     5,     6,
       7,     8,     9,    10,   203,   203,   203,   203,   203,   203,
     203,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     203,    38,   203,   203,   203,    42,    43,    44,    45,    46,
      47,    48,    49,   203,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   203,   203,   203,     1,   203,     3,
       4,     5,     6,     7,     8,     9,    10,   203,   203,   203,
     203,    78,    79,    80,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,   203,    38,   203,   201,   201,    42,    43,
      44,    45,    46,    47,    48,    49,   201,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   203,   210,   203,
     203,   163,   163,     1,   205,     3,     4,     5,     6,     7,
       8,     9,    10,   163,    78,    79,    80,   205,   201,   198,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,   198,
      38,   198,   198,   190,    42,    43,    44,    45,    46,    47,
      48,    49,    71,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    71,   205,   195,   195,   195,   205,   195,
     197,   203,   199,   198,   198,   202,   198,    39,   201,   206,
      78,    79,    80,   203,   203,   203,   203,   214,   203,   203,
     203,   201,   201,   163,   163,   203,   163,   163,   163,   201,
     163,   163,   206,   198,   201,   212,   212,   212,   201,   203,
     195,   201,   198,   202,   202,   198,   203,    76,   548,   203,
     202,   202,   790,   203,   215,   945,   990,  1020,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,    -1,    -1,   202,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,    -1,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,     1,   214,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    78,    79,    80,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    78,    79,    80,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,    -1,   202,    -1,    -1,    -1,
     206,    78,    79,    80,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,    -1,    -1,   202,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,    -1,    -1,   202,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,     1,   214,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    78,    79,    80,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    78,    79,    80,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,   199,    -1,    -1,   202,    -1,    -1,
      -1,   206,    78,    79,    80,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,    -1,
     202,    -1,    -1,    -1,   206,     0,     1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,    -1,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,   211,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,    -1,
     194,   195,    -1,   197,    -1,   199,    -1,    -1,    -1,    -1,
     204,   205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,    -1,    -1,    -1,    -1,   204,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    78,    79,    80,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,    -1,    -1,   202,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
      -1,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    78,
      79,    80,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    78,    79,    80,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
     199,    -1,    -1,   202,    -1,    -1,    -1,   206,    78,    79,
      80,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,    -1,   202,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
      -1,    -1,   202,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,   214,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    78,    79,
      80,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
      -1,    -1,   202,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   211,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   235,   236,   241,   243,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,     1,   163,     1,   163,     1,   163,     1,   163,
       1,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,     1,   198,   163,     1,   204,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   207,   207,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,     1,   163,     1,   163,   163,
     163,   163,     0,     1,   218,    10,   251,    11,   252,    12,
     253,    13,   254,    14,   255,    15,   256,    16,   257,    17,
     258,     1,   191,   192,   195,   230,     1,   195,     1,   195,
       1,   197,     1,   198,     1,   198,     1,    73,    74,    75,
      76,   195,   197,   198,   200,   207,   213,   227,   228,   231,
     232,   237,   238,   239,   240,   271,     1,   232,     1,   195,
       1,   195,     1,   195,   195,   195,   195,   195,   195,     1,
     195,     1,   195,     1,   195,     1,   195,     1,   195,     1,
     195,     1,   195,     1,   195,     1,   198,     1,   198,     1,
     198,   198,     1,   195,     1,   197,   198,     1,   197,   198,
       1,   197,   198,     1,   197,   198,     1,   195,     1,   195,
       1,   195,     1,   195,     1,   195,     1,   195,     1,   195,
       1,   197,   198,     1,   195,     1,   195,     1,   195,     1,
     195,     1,   195,     1,   140,   141,   142,   143,     1,   195,
       1,   195,   237,   198,   237,     1,   195,     1,   195,     1,
     195,     1,   195,     1,   198,     1,   198,     1,   198,     1,
     198,     1,   227,     1,   195,     1,   195,     1,   195,     1,
     195,     1,   195,     1,   195,   197,   195,   195,   197,   195,
       1,   198,     1,   205,   207,     1,   207,     1,   205,   207,
       1,   207,     1,   205,     1,   205,     1,   205,     1,   207,
     195,   195,   210,   239,   212,   212,   209,   232,   191,   210,
     270,   201,   212,   208,   212,   212,     3,     4,     5,     6,
       7,     8,     9,    10,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    38,    42,    43,    44,    45,    46,    47,
      48,    49,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    78,    79,    80,   197,   199,   202,   214,   266,
     274,   277,   278,   279,   280,   281,   287,   195,   197,   198,
     250,   250,   277,   250,   250,   277,   277,   277,   250,   195,
     208,     1,   195,   213,   229,   227,   227,     1,   197,   198,
     229,   245,   229,   205,     1,   204,     1,   204,   204,   204,
     204,     1,   204,     1,   204,     1,   204,     1,   204,     1,
     204,     1,   204,     1,   204,     1,   204,   204,   204,     1,
     204,     1,   204,     1,   204,     1,   204,   204,     1,   204,
     204,   204,   204,   204,   204,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   194,   204,   205,
     207,   230,   259,   265,   266,   267,   268,   274,   275,   279,
     287,   204,   259,     1,   204,     1,   204,     1,   204,     1,
     204,     1,   204,     1,   204,     1,   204,     1,   204,     1,
     204,     1,   204,     1,   204,     1,   204,     1,   204,     1,
     204,     1,   204,     1,   204,     1,   204,   204,   204,   204,
       1,   204,   163,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   272,   202,     1,   206,   278,     1,   202,   208,
     208,   206,   208,   208,   206,   206,   206,   201,   210,   212,
     212,   201,   208,   205,   208,   194,   204,   233,   234,     1,
     198,   203,     1,   198,   203,   203,   203,   230,   266,     1,
     198,   230,     1,   198,     1,   250,     1,   198,     1,   198,
       1,   198,     1,   195,     1,   195,   198,   203,   198,   266,
       1,   198,     1,   198,     1,   198,     1,   198,   203,     1,
     198,   203,   203,   203,   203,     1,   195,   203,     1,   164,
     165,   166,   167,   168,   169,   170,   171,   260,   261,   262,
     264,     1,   260,   264,     1,   260,   261,   263,     1,   260,
     264,     1,   263,     1,   263,     1,   263,     1,   260,     1,
     263,   259,   259,   206,   277,    65,    67,   193,   197,   198,
     204,   230,   265,   266,   268,   273,   287,   181,   182,   205,
     276,   278,     1,   260,   264,   260,   261,   263,   264,   266,
     276,     1,   227,     1,   195,     1,   231,     1,   195,     1,
     203,     1,   198,     1,   198,   195,   203,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   198,   198,   198,     1,
     195,   198,   203,   286,    77,    77,   273,   205,   205,   205,
     205,   195,   195,   229,   229,   198,   230,   242,   134,   145,
     147,   148,   149,   150,   247,   249,   244,   204,   228,     1,
     201,   206,   203,   203,   203,   203,   203,   203,   203,   203,
     201,   203,   201,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   201,   203,   201,   201,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,     1,   197,   198,    71,   237,   269,     1,   198,   271,
       1,   195,    71,   269,     1,   198,   271,     1,   195,     1,
     228,     1,   195,     1,    65,    67,   265,     1,    50,   195,
     203,   206,   260,   264,   260,   264,   273,   273,   264,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   208,
     259,   259,   206,   277,    37,    71,     1,   198,   271,    71,
      77,   230,   197,   198,   266,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   201,   203,   201,   203,   201,   203,   203,
     203,   203,   201,   201,   201,   203,   201,   203,   277,   277,
     277,   277,   208,   210,   203,   203,   205,   163,   163,   163,
     163,   163,   163,   206,   249,   205,   228,   201,   233,   198,
     198,   198,   198,   198,   190,   203,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   206,   276,   205,   195,
     195,   195,   198,   198,   198,   195,   198,   206,   206,   206,
     206,   205,   195,   134,   144,   146,   147,   148,   149,   150,
     246,   248,     1,   140,   141,   142,   143,     1,   195,     1,
     198,     1,   198,     1,   198,     1,   198,   247,   201,   269,
     203,   203,   203,   203,   203,     1,   195,   237,    39,   282,
     283,   284,   203,   203,   203,   201,   201,   203,   277,   163,
     163,   163,   163,   163,   163,   163,   206,   248,   206,   269,
     201,   198,   230,   206,    40,   284,   285,   198,   266,   206,
       1,   140,   141,   142,   143,     1,   195,     1,   195,     1,
     198,     1,   198,     1,   198,     1,   198,   201,   229,   212,
     212,   212,   201,   203,   203,   229,   201,    41,   277,    41,
     277,   277,   195,   201,   198,   202,    41,   202,    41,   203,
     198,   203,   202,   202,   203
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 444 "cfg.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 445 "cfg.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 446 "cfg.y"
    { yyerror(""); YYABORT;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 451 "cfg.y"
    {rt=REQUEST_ROUTE;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 452 "cfg.y"
    {rt=FAILURE_ROUTE;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 453 "cfg.y"
    {rt=ONREPLY_ROUTE;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 454 "cfg.y"
    {rt=BRANCH_ROUTE;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 455 "cfg.y"
    {rt=ERROR_ROUTE;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 456 "cfg.y"
    {rt=LOCAL_ROUTE;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 457 "cfg.y"
    {rt=STARTUP_ROUTE;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 458 "cfg.y"
    {rt=TIMER_ROUTE;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 463 "cfg.y"
    {	tmp=ip_addr2a((yyvsp[(1) - (1)].ipaddr));
							if(tmp==0){
								LM_CRIT("cfg. parser: bad ip address.\n");
								(yyval.strval)=0;
							}else{
								(yyval.strval)=pkg_malloc(strlen(tmp)+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									strncpy((yyval.strval), tmp, strlen(tmp)+1);
								}
							}
						;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 476 "cfg.y"
    {	(yyval.strval)=pkg_malloc(strlen((yyvsp[(1) - (1)].strval))+1);
							if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
							}else{
									strncpy((yyval.strval), (yyvsp[(1) - (1)].strval), strlen((yyvsp[(1) - (1)].strval))+1);
							}
						;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 483 "cfg.y"
    {	if ((yyvsp[(1) - (1)].strval)==0) {
								(yyval.strval) = 0;
							} else {
								(yyval.strval)=pkg_malloc(strlen((yyvsp[(1) - (1)].strval))+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									strncpy((yyval.strval), (yyvsp[(1) - (1)].strval), strlen((yyvsp[(1) - (1)].strval))+1);
								}
							}
						;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 496 "cfg.y"
    { (yyval.intval)=PROTO_UDP; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 497 "cfg.y"
    { (yyval.intval)=PROTO_TCP; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 498 "cfg.y"
    {
			#ifdef USE_TLS
				(yyval.intval)=PROTO_TLS;
			#else
				(yyval.intval)=PROTO_TCP;
				warn("tls support not compiled in");
			#endif
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 506 "cfg.y"
    { 
			#ifdef USE_SCTP
				(yyval.intval)=PROTO_SCTP;
			#else
				yyerror("sctp support not compiled in\n");YYABORT;
			#endif
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 513 "cfg.y"
    { (yyval.intval)=0; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 516 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 517 "cfg.y"
    { (yyval.intval)=0; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 520 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 521 "cfg.y"
    { (yyval.intval)=(yyvsp[(2) - (2)].intval); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 522 "cfg.y"
    { (yyval.intval)=-(yyvsp[(2) - (2)].intval); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 526 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (1)].strval), 0, 0); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 527 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (3)].strval), 0, (yyvsp[(3) - (3)].intval)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 528 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (3)].strval), (yyvsp[(1) - (3)].intval), 0); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 529 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (5)].strval), (yyvsp[(1) - (5)].intval), (yyvsp[(5) - (5)].intval));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 530 "cfg.y"
    { set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (3)].sockid), (yyvsp[(3) - (3)].strval), 5060); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 531 "cfg.y"
    { set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (5)].sockid), (yyvsp[(3) - (5)].strval), (yyvsp[(5) - (5)].intval)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 532 "cfg.y"
    { (yyval.sockid)=0; yyerror(" port number expected"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 535 "cfg.y"
    {  (yyval.sockid)=(yyvsp[(1) - (1)].sockid) ; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 536 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (2)].sockid); (yyval.sockid)->next=(yyvsp[(2) - (2)].sockid); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 540 "cfg.y"
    {
				s_tmp.s=(yyvsp[(8) - (9)].strval);
				s_tmp.len=strlen((yyvsp[(8) - (9)].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[(4) - (9)].ipnet),&s_tmp,(yyvsp[(6) - (9)].intval),(yyvsp[(2) - (9)].intval),0)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 547 "cfg.y"
    {
				s_tmp.s=(yyvsp[(9) - (10)].strval);
				s_tmp.len=strlen((yyvsp[(9) - (10)].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[(5) - (10)].ipnet),&s_tmp,
				(yyvsp[(7) - (10)].intval),(yyvsp[(3) - (10)].intval),BLR_APPLY_CONTRARY)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 557 "cfg.y"
    {;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 558 "cfg.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 559 "cfg.y"
    { yyerror("bad black list element");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 563 "cfg.y"
    { 
#ifdef CHANGEABLE_DEBUG_LEVEL
					*debug=(yyvsp[(3) - (3)].intval);
#else
					debug=(yyvsp[(3) - (3)].intval);
#endif
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 570 "cfg.y"
    { yyerror("number  expected"); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 571 "cfg.y"
    { dont_fork= ! (yyvsp[(3) - (3)].intval); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 572 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 573 "cfg.y"
    { if (!config_check) log_stderr=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 574 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 575 "cfg.y"
    {
					if ( (i_tmp=str2facility((yyvsp[(3) - (3)].strval)))==-1)
						yyerror("bad facility (see syslog(3) man page)");
					if (!config_check)
						log_facility=i_tmp;
									;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 581 "cfg.y"
    { yyerror("ID expected"); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 582 "cfg.y"
    { log_name=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 583 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 584 "cfg.y"
    { 
				if ((yyvsp[(3) - (3)].strval)!=0 && (yyvsp[(3) - (3)].strval)[0]!=0)
					if ( add_avp_galias_str((yyvsp[(3) - (3)].strval))!=0 )
						yyerror("invalid AVP aliases");;
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 589 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 590 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_DNS:0; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 591 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 592 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_REV_DNS:0; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 593 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 594 "cfg.y"
    { dns_try_ipv6=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 595 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 596 "cfg.y"
    { dns_retr_time=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 597 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 598 "cfg.y"
    { dns_retr_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 599 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 600 "cfg.y"
    { dns_servers_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 601 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 602 "cfg.y"
    { dns_search_list=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 603 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 604 "cfg.y"
    { port_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 605 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 606 "cfg.y"
    { max_while_loops=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 607 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 608 "cfg.y"
    { maxbuffer=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 609 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 610 "cfg.y"
    { children_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 611 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 612 "cfg.y"
    { check_via=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 613 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 614 "cfg.y"
    { memlog=(yyvsp[(3) - (3)].intval); memdump=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 615 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 616 "cfg.y"
    { memdump=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 617 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 618 "cfg.y"
    { sip_warning=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 619 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 620 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 621 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 622 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 623 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 624 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 625 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 626 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 627 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 628 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 629 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 630 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 631 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 632 "cfg.y"
    { mhomed=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 633 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 634 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 641 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 642 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_accept_aliases=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 649 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 650 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_children_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 657 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 658 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_connect_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 665 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 666 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 673 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 674 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_con_lifetime=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 681 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 682 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_poll_method=get_poll_type((yyvsp[(3) - (3)].strval));
										if (tcp_poll_method==POLL_NONE){
											LM_CRIT("bad poll method name:"
												" %s\n, try one of %s.\n",
												(yyvsp[(3) - (3)].strval), poll_support);
											yyerror("bad tcp_poll_method "
												"value");
										}
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 696 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_poll_method=get_poll_type((yyvsp[(3) - (3)].strval));
										if (tcp_poll_method==POLL_NONE){
											LM_CRIT("bad poll method name:"
												" %s\n, try one of %s.\n",
												(yyvsp[(3) - (3)].strval), poll_support);
											yyerror("bad tcp_poll_method "
												"value");
										}
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 710 "cfg.y"
    { yyerror("poll method name expected"); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 711 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_max_connections=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 718 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 719 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_crlf_pingpong=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 726 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 727 "cfg.y"
    {
									#ifdef USE_TLS
										tls_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 734 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 735 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_log=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 742 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 743 "cfg.y"
    {
									#ifdef USE_TLS
										tls_port_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 750 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 751 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv23;
										tls_default_client_domain->method =
											TLS_USE_SSLv23;
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 761 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv2;
										tls_default_client_domain->method =
											TLS_USE_SSLv2;
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 771 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv3;
										tls_default_client_domain->method =
											TLS_USE_SSLv3;
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 781 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_TLSv1;
										tls_default_client_domain->method =
											TLS_USE_TLSv1;
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 791 "cfg.y"
    {
									#ifdef USE_TLS
										yyerror("SSLv23, SSLv2, SSLv3 or TLSv1"
													" expected");
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 800 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->verify_cert
											= (yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 808 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 809 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_client_domain->verify_cert
											=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 817 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 818 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->require_client_cert=(yyvsp[(3) - (3)].intval);
									#else
										warn( "tls support not compiled in");
									#endif
									;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 825 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 826 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->cert_file=
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->cert_file=
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 836 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 837 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->pkey_file=
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->pkey_file=
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 847 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 848 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->ca_file =
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->ca_file =
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 858 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 859 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->ciphers_list
											= (yyvsp[(3) - (3)].strval);
										tls_default_client_domain->ciphers_list
											= (yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 869 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 870 "cfg.y"
    {
									#ifdef USE_TLS
										tls_handshake_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 877 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 878 "cfg.y"
    {
									#ifdef USE_TLS
										tls_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 885 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 886 "cfg.y"
    {
									#ifdef USE_TLS
										tls_client_domain_avp=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 893 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 896 "cfg.y"
    { server_signature=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 897 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 898 "cfg.y"
    { server_header.s=(yyvsp[(3) - (3)].strval);
									server_header.len=strlen((yyvsp[(3) - (3)].strval));
									;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 901 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 902 "cfg.y"
    { user_agent_header.s=(yyvsp[(3) - (3)].strval);
									user_agent_header.len=strlen((yyvsp[(3) - (3)].strval));
									;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 905 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 906 "cfg.y"
    {
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next){
								if (add_listen_iface(	lst_tmp->name,
														lst_tmp->port,
														lst_tmp->proto,
														lst_tmp->adv_name,
														lst_tmp->adv_port,
														0
													)!=0){
									LM_CRIT("cfg. parser: failed"
											" to add listen address\n");
									break;
								}
							}
							 ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 921 "cfg.y"
    { yyerror("ip address or hostname "
						"expected (use quotes if the hostname includes"
						" config keywords)"); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 924 "cfg.y"
    { 
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next)
								add_alias(lst_tmp->name, strlen(lst_tmp->name),
											lst_tmp->port, lst_tmp->proto);
							  ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 929 "cfg.y"
    { yyerror("hostname expected (use quotes"
							" if the hostname includes config keywords)"); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 931 "cfg.y"
    { auto_aliases=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 932 "cfg.y"
    { yyerror("number  expected"); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 933 "cfg.y"
    {
								if ((yyvsp[(3) - (3)].strval)) {
									default_global_address.s=(yyvsp[(3) - (3)].strval);
									default_global_address.len=strlen((yyvsp[(3) - (3)].strval));
								}
								;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 939 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 941 "cfg.y"
    {
								tmp=int2str((yyvsp[(3) - (3)].intval), &i_tmp);
								if ((default_global_port.s=pkg_malloc(i_tmp))
										==0){
										LM_CRIT("cfg. parser: out of memory.\n");
										default_global_port.len=0;
								}else{
									default_global_port.len=i_tmp;
									memcpy(default_global_port.s, tmp,
											default_global_port.len);
								};
								;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 953 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 955 "cfg.y"
    {
										disable_core_dump=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 958 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 959 "cfg.y"
    {
										open_files_limit=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 962 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 963 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_loopback=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 970 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 971 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_ttl=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 978 "cfg.y"
    { yyerror("number expected as tos"); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 979 "cfg.y"
    { tos = (yyvsp[(3) - (3)].intval);
							if (tos<=0)
								yyerror("invalid tos value");
		 ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 983 "cfg.y"
    { if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_LOWDELAY")) {
								tos=IPTOS_LOWDELAY;
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_THROUGHPUT")) {
								tos=IPTOS_THROUGHPUT;
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_RELIABILITY")) {
								tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_MINCOST")) {
								tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_LOWCOST")) {
								tos=IPTOS_LOWCOST;
#endif
							} else {
								yyerror("invalid tos value - allowed: "
									"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
									"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
									",IPTOS_LOWCOST"
#endif
#if defined(IPTOS_MINCOST)
									",IPTOS_MINCOST"
#endif
									"\n");
							}
		 ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1010 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1011 "cfg.y"
    { mpath=(yyvsp[(3) - (3)].strval); strcpy(mpath_buf, (yyvsp[(3) - (3)].strval));
								mpath_len=strlen((yyvsp[(3) - (3)].strval)); 
								if(mpath_buf[mpath_len-1]!='/') {
									mpath_buf[mpath_len]='/';
									mpath_len++;
									mpath_buf[mpath_len]='\0';
								}
							;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1019 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1020 "cfg.y"
    {
										disable_dns_failover=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1023 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1024 "cfg.y"
    {
										disable_dns_blacklist=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1027 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1028 "cfg.y"
    {
				s_tmp.s = (yyvsp[(3) - (7)].strval);
				s_tmp.len = strlen((yyvsp[(3) - (7)].strval));
				if ( create_bl_head( BL_CORE_ID, BL_READONLY_LIST,
				bl_head, bl_tail, &s_tmp)==0) {
					yyerror("failed to create blacklist\n");
					YYABORT;
				}
				bl_head = bl_tail = 0;
				;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1038 "cfg.y"
    {
				sl_fwd_disabled=(yyvsp[(3) - (3)].intval);
				;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1041 "cfg.y"
    { db_version_table=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1042 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1043 "cfg.y"
    { yyerror("unknown config variable"); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1046 "cfg.y"
    {
			if(*(yyvsp[(2) - (2)].strval)!='/' && mpath!=NULL
					&& strlen((yyvsp[(2) - (2)].strval))+mpath_len<255)
			{
				strcpy(mpath_buf+mpath_len, (yyvsp[(2) - (2)].strval));
				if (stat(mpath_buf, &statf) == -1) {
					i_tmp = strlen(mpath_buf);
					if(strchr((yyvsp[(2) - (2)].strval), '/')==NULL &&
							strncmp(mpath_buf+i_tmp-3, ".so", 3)==0)
					{
						if(i_tmp+strlen((yyvsp[(2) - (2)].strval))<255)
						{
							strcpy(mpath_buf+i_tmp-3, "/");
							strcpy(mpath_buf+i_tmp-2, (yyvsp[(2) - (2)].strval));
							if (stat(mpath_buf, &statf) == -1) {
								mpath_buf[mpath_len]='\0';
								LM_ERR("module '%s' not found in '%s'\n",
									(yyvsp[(2) - (2)].strval), mpath_buf);
								yyerror("failed to load module");
							}
						} else {
							yyerror("failed to load module - path too long");
						}
					} else {
						yyerror("failed to load module - not found");
					}
				}
				LM_DBG("loading module %s\n", mpath_buf);
				if (sr_load_module(mpath_buf)!=0){
					yyerror("failed to load module");
				}
				mpath_buf[mpath_len]='\0';
			} else {
				LM_DBG("loading module %s\n", (yyvsp[(2) - (2)].strval));
				if (sr_load_module((yyvsp[(2) - (2)].strval))!=0){
					yyerror("failed to load module");
				}
			}
		;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1085 "cfg.y"
    { yyerror("string expected");  ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1086 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), STR_PARAM, (yyvsp[(7) - (8)].strval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1092 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), INT_PARAM, (void*)(yyvsp[(7) - (8)].intval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1098 "cfg.y"
    { yyerror("Invalid arguments"); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1102 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1103 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1106 "cfg.y"
    { 
											(yyval.ipaddr)=pkg_malloc(
													sizeof(struct ip_addr));
											if ((yyval.ipaddr)==0){
												LM_CRIT("cfg. "
													"parser: out of memory.\n"
													);
											}else{
												memset((yyval.ipaddr), 0, 
													sizeof(struct ip_addr));
												(yyval.ipaddr)->af=AF_INET;
												(yyval.ipaddr)->len=4;
												if (((yyvsp[(1) - (7)].intval)>255) || ((yyvsp[(1) - (7)].intval)<0) ||
													((yyvsp[(3) - (7)].intval)>255) || ((yyvsp[(3) - (7)].intval)<0) ||
													((yyvsp[(5) - (7)].intval)>255) || ((yyvsp[(5) - (7)].intval)<0) ||
													((yyvsp[(7) - (7)].intval)>255) || ((yyvsp[(7) - (7)].intval)<0)){
													yyerror("invalid ipv4"
															"address");
													(yyval.ipaddr)->u.addr32[0]=0;
													/* $$=0; */
												}else{
													(yyval.ipaddr)->u.addr[0]=(yyvsp[(1) - (7)].intval);
													(yyval.ipaddr)->u.addr[1]=(yyvsp[(3) - (7)].intval);
													(yyval.ipaddr)->u.addr[2]=(yyvsp[(5) - (7)].intval);
													(yyval.ipaddr)->u.addr[3]=(yyvsp[(7) - (7)].intval);
													/*
													$$=htonl( ($1<<24)|
													($3<<16)| ($5<<8)|$7 );
													*/
												}
											}
												;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1140 "cfg.y"
    {
					(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
					if ((yyval.ipaddr)==0){
						LM_CRIT("ERROR: cfg. parser: out of memory.\n");
					}else{
						memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
						(yyval.ipaddr)->af=AF_INET6;
						(yyval.ipaddr)->len=16;
					#ifdef USE_IPV6
						if (inet_pton(AF_INET6, (yyvsp[(1) - (1)].strval), (yyval.ipaddr)->u.addr)<=0){
							yyerror("bad ipv6 address");
						}
					#else
						yyerror("ipv6 address & no ipv6 support compiled in");
						YYABORT;
					#endif
					}
				;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1160 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1161 "cfg.y"
    {(yyval.ipaddr)=(yyvsp[(2) - (3)].ipaddr); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1164 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_server_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval))) 
								yyerror("tls_new_server_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1175 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval)))
								yyerror("tls_new_client_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1186 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain_name((yyvsp[(3) - (4)].strval), strlen((yyvsp[(3) - (4)].strval))))
								yyerror("tls_new_client_domain_name failed");
						#else	
							warn("tls support not compiled in");
						#endif
							;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1205 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1212 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1219 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1226 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1233 "cfg.y"
    { yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1234 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1241 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1243 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1250 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1252 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1259 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1260 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1267 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1268 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1275 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1276 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->require_client_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn( "tls support not compiled in");
						#endif
								;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1283 "cfg.y"
    { 
						yyerror("boolean value expected"); ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1287 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1294 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1301 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1308 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1315 "cfg.y"
    {
						yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1317 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1324 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1326 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1333 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1335 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1342 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1343 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1350 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1351 "cfg.y"
    {
						#ifdef USE_TLS
									tls_client_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1358 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1361 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
				;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1364 "cfg.y"
    {
				tmp=int2str((yyvsp[(1) - (1)].intval), &i_tmp);
				if (((yyval.strval)=pkg_malloc(i_tmp+1))==0)
					yyerror("cfg. parser: out of memory.\n");
				memcpy( (yyval.strval), tmp, i_tmp);
				(yyval.strval)[i_tmp] = 0;
				;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1371 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
		;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1376 "cfg.y"
    {
						if (rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"request routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &rlist[DEFAULT_RT].a);
					;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1384 "cfg.y"
    { 
						if ( strtol((yyvsp[(3) - (7)].strval),&tmp,10)==0 && *tmp==0) {
							/* route[0] detected */
							if (rlist[DEFAULT_RT].a!=0) {
								yyerror("overwritting(2) default "
									"request routing table");
								YYABORT;
							}
							push((yyvsp[(6) - (7)].action), &rlist[DEFAULT_RT].a);
						} else {
							i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),rlist,RT_NO,1);
							if (i_tmp==-1) YYABORT;
							push((yyvsp[(6) - (7)].action), &rlist[i_tmp].a);
						}
					;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1399 "cfg.y"
    { yyerror("invalid  route  statement"); ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1402 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),failure_rlist,
								FAILURE_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &failure_rlist[i_tmp].a);
					;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1408 "cfg.y"
    { yyerror("invalid failure_route statement"); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1411 "cfg.y"
    {
						if (onreply_rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"onreply routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &onreply_rlist[DEFAULT_RT].a);
					;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1419 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),onreply_rlist,
								ONREPLY_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &onreply_rlist[i_tmp].a);
					;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1425 "cfg.y"
    { yyerror("invalid onreply_route statement"); ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1428 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),branch_rlist,
								BRANCH_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &branch_rlist[i_tmp].a);
					;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1434 "cfg.y"
    { yyerror("invalid branch_route statement"); ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1437 "cfg.y"
    {
						if (error_rlist.a!=0) {
							yyerror("overwritting default "
								"error routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &error_rlist.a);
					;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1445 "cfg.y"
    { yyerror("invalid error_route statement"); ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1448 "cfg.y"
    {
						if (local_rlist.a!=0) {
							yyerror("re-definition of local "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &local_rlist.a);
					;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1456 "cfg.y"
    { yyerror("invalid local_route statement"); ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1459 "cfg.y"
    {
						if (startup_rlist.a!=0) {
							yyerror("re-definition of startup "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &startup_rlist.a);
					;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1467 "cfg.y"
    { yyerror("invalid startup_route statement"); ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1470 "cfg.y"
    {
						i_tmp = 0;
						while (timer_rlist[i_tmp].a!=0 && i_tmp < TIMER_RT_NO) {
							i_tmp++;
						}
						if(i_tmp == TIMER_RT_NO) {
							yyerror("Too many timer routes defined\n");
							YYABORT;
						}
						timer_rlist[i_tmp].interval = (yyvsp[(5) - (9)].intval);
						push((yyvsp[(8) - (9)].action), &timer_rlist[i_tmp].a);
					;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1482 "cfg.y"
    { yyerror("invalid timer_route statement"); ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1485 "cfg.y"
    { (yyval.expr)=mk_exp(AND_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1486 "cfg.y"
    { (yyval.expr)=mk_exp(OR_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1487 "cfg.y"
    { (yyval.expr)=mk_exp(NOT_OP, (yyvsp[(2) - (2)].expr), 0);  ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1488 "cfg.y"
    { (yyval.expr)=mk_exp(EVAL_OP, (yyvsp[(2) - (3)].expr), 0); ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1489 "cfg.y"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1490 "cfg.y"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1493 "cfg.y"
    {(yyval.intval)=EQUAL_OP; ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1494 "cfg.y"
    {(yyval.intval)=DIFF_OP; ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1497 "cfg.y"
    {(yyval.intval)=GT_OP; ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1498 "cfg.y"
    {(yyval.intval)=LT_OP; ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1499 "cfg.y"
    {(yyval.intval)=GTE_OP; ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1500 "cfg.y"
    {(yyval.intval)=LTE_OP; ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1502 "cfg.y"
    {(yyval.intval)=MATCH_OP; ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1503 "cfg.y"
    {(yyval.intval)=NOTMATCH_OP; ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1506 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1507 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1510 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1511 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1512 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1515 "cfg.y"
    {(yyval.intval)=URI_O;;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1516 "cfg.y"
    {(yyval.intval)=FROM_URI_O;;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1517 "cfg.y"
    {(yyval.intval)=TO_URI_O;;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1520 "cfg.y"
    { 
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				if (spec==NULL){
					yyerror("no more pkg memory\n");
				}
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[(1) - (1)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable");
				}
				(yyval.specval) = spec;
			;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1534 "cfg.y"
    {
			(yyval.specval)=0; yyerror("invalid script variable name");
		;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1539 "cfg.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1540 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1541 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, NUMBER_O, 0, NUMBER_ST, 
											(void*)(yyvsp[(1) - (1)].intval) ); ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1543 "cfg.y"
    {
				(yyval.expr)=mk_elem(NO_OP, SCRIPTVAR_O,0,SCRIPTVAR_ST,(void*)(yyvsp[(1) - (1)].specval));
			;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1546 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1548 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1550 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1552 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1554 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1558 "cfg.y"
    {(yyval.expr)= mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
									;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1560 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1562 "cfg.y"
    { (yyval.expr)=0; yyerror("string expected"); ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1563 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
										"== , !=, or =~ expected");
						;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1566 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),SCRIPTVAR_ST,(void*)(yyvsp[(3) - (3)].specval));
			;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1569 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1572 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1575 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),NUMBER_ST,(void *)(yyvsp[(3) - (3)].intval));
			;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1578 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), MYSELF_ST, 0);
			;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1581 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), NULLV_ST, 0);
			;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1584 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 				;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1586 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, MYSELF_ST, 0);
								;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1588 "cfg.y"
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1589 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
									" == , != or =~ expected");
					;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1592 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1594 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1595 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1596 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1598 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1599 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1600 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), PROTO_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1602 "cfg.y"
    { (yyval.expr)=0;
								yyerror("protocol expected (udp, tcp or tls)");
							;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1605 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1606 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), AF_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1608 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1609 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1610 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1612 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) BUF_SIZE); ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1614 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1615 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1616 "cfg.y"
    {	s_tmp.s=(yyvsp[(3) - (3)].strval);
									s_tmp.len=strlen((yyvsp[(3) - (3)].strval));
									ip_tmp=str2ip(&s_tmp);
									if (ip_tmp==0)
										ip_tmp=str2ip6(&s_tmp);
									if (ip_tmp){
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST,
												mk_net_bitlen(ip_tmp, 
														ip_tmp->len*8) );
									}else{
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST,
												(yyvsp[(3) - (3)].strval));
									}
								;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1630 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1632 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 "expected" ); ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1634 "cfg.y"
    { (yyval.expr)=0; 
						 yyerror("invalid operator, ==, != or =~ expected");;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1636 "cfg.y"
    {	s_tmp.s=(yyvsp[(3) - (3)].strval);
									s_tmp.len=strlen((yyvsp[(3) - (3)].strval));
									ip_tmp=str2ip(&s_tmp);
									if (ip_tmp==0)
										ip_tmp=str2ip6(&s_tmp);
									if (ip_tmp){
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST,
												mk_net_bitlen(ip_tmp, 
														ip_tmp->len*8) );
									}else{
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST,
												(yyvsp[(3) - (3)].strval));
									}
								;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1650 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1652 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 			"expected" ); ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1654 "cfg.y"
    { (yyval.expr)=0; 
						yyerror("invalid operator, ==, != or =~ expected");;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1656 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval), 0, MYSELF_ST, 0);
								;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1658 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1660 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1662 "cfg.y"
    {	(yyval.expr)=0; 
									yyerror(" URI, SRCIP or DSTIP expected"); ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1664 "cfg.y"
    { (yyval.expr)=0; 
							yyerror ("invalid operator, == or != expected");
						;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1669 "cfg.y"
    { (yyval.ipnet)=mk_net((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].ipaddr)); ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1670 "cfg.y"
    {	if (((yyvsp[(3) - (3)].intval)<0) || ((yyvsp[(3) - (3)].intval)>(long)(yyvsp[(1) - (3)].ipaddr)->len*8)){
								yyerror("invalid bit number in netmask");
								(yyval.ipnet)=0;
							}else{
								(yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].intval));
							/*
								$$=mk_net($1, 
										htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
							*/
							}
						;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1681 "cfg.y"
    { (yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (1)].ipaddr), (yyvsp[(1) - (1)].ipaddr)->len*8); ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1682 "cfg.y"
    { (yyval.ipnet)=0;
						 yyerror("netmask (eg:255.0.0.0 or 8) expected");
						;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1689 "cfg.y"
    {(yyval.strval)=".";;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1690 "cfg.y"
    {(yyval.strval)="-"; ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1693 "cfg.y"
    { (yyval.strval)=(yyvsp[(1) - (1)].strval); ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1694 "cfg.y"
    { (yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[(1) - (3)].strval))+1+strlen((yyvsp[(3) - (3)].strval))+1);
						  if ((yyval.strval)==0){
							LM_CRIT("cfg. parser: memory allocation"
										" failure while parsing host\n");
						  }else{
							memcpy((yyval.strval), (yyvsp[(1) - (3)].strval), strlen((yyvsp[(1) - (3)].strval)));
							(yyval.strval)[strlen((yyvsp[(1) - (3)].strval))]=*(yyvsp[(2) - (3)].strval);
							memcpy((yyval.strval)+strlen((yyvsp[(1) - (3)].strval))+1, (yyvsp[(3) - (3)].strval), strlen((yyvsp[(3) - (3)].strval)));
							(yyval.strval)[strlen((yyvsp[(1) - (3)].strval))+1+strlen((yyvsp[(3) - (3)].strval))]=0;
						  }
						  pkg_free((yyvsp[(1) - (3)].strval)); pkg_free((yyvsp[(3) - (3)].strval));
						;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1706 "cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[(1) - (3)].strval)); yyerror("invalid hostname (use quotes if hostname has config keywords)"); ;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1710 "cfg.y"
    { (yyval.intval) = EQ_T; ;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1711 "cfg.y"
    { (yyval.intval) = COLONEQ_T; ;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1712 "cfg.y"
    { (yyval.intval) = PLUSEQ_T; ;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1713 "cfg.y"
    { (yyval.intval) = MINUSEQ_T;;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1714 "cfg.y"
    { (yyval.intval) = DIVEQ_T; ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1715 "cfg.y"
    { (yyval.intval) = MULTEQ_T; ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1716 "cfg.y"
    { (yyval.intval) = MODULOEQ_T; ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1717 "cfg.y"
    { (yyval.intval) = BANDEQ_T; ;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1718 "cfg.y"
    { (yyval.intval) = BOREQ_T; ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1719 "cfg.y"
    { (yyval.intval) = BXOREQ_T; ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1723 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, NUMBERV_O, (void*)(yyvsp[(1) - (1)].intval), 0, 0); ;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1724 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1725 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); ;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1726 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, SCRIPTVAR_O, (yyvsp[(1) - (1)].specval), 0, 0); ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1727 "cfg.y"
    { (yyval.expr)= (yyvsp[(1) - (1)].expr); ;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1728 "cfg.y"
    { (yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); ;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1729 "cfg.y"
    { 
				(yyval.expr) = mk_elem(PLUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1732 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MINUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr)); 
			;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1735 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MULT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1738 "cfg.y"
    { 
				(yyval.expr) = mk_elem(DIV_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1741 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MODULO_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1744 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BAND_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1747 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1750 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BXOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1753 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BLSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1756 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BRSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1759 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BNOT_OP, EXPR_O, (yyvsp[(2) - (2)].expr), 0, 0);
			;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1762 "cfg.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1765 "cfg.y"
    {	
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), (yyvsp[(2) - (3)].intval),
					SCRIPTVAR_ST,
					EXPR_ST,
					(yyvsp[(1) - (3)].specval),
					(yyvsp[(3) - (3)].expr));
		;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1778 "cfg.y"
    {
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), EQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[(1) - (3)].specval),
					0);
		;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1791 "cfg.y"
    {
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			/* not all can get NULL with := */
			switch((yyvsp[(1) - (3)].specval)->type) {
				case PVT_AVP:
				break;
				default:
					yyerror("invalid left operand in NULL assignment");
			}
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), COLONEQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[(1) - (3)].specval),
					0);
		;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1813 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1814 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1815 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1816 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); ;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1817 "cfg.y"
    { (yyval.action)=0; ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1820 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1821 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1822 "cfg.y"
    { (yyval.action)=0; ;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1825 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1826 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1827 "cfg.y"
    { (yyval.action)=0; yyerror("bad command!)"); ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1830 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1831 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1832 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1833 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1834 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1835 "cfg.y"
    {(yyval.action)=0;;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1836 "cfg.y"
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); ;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1839 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 NOSUBTYPE,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action),
													 0);
									;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1847 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (5)].expr),
													 (yyvsp[(3) - (5)].action),
													 (yyvsp[(5) - (5)].action));
									;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1857 "cfg.y"
    { mk_action2( (yyval.action), WHILE_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action));
									;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1865 "cfg.y"
    {
											mk_action2( (yyval.action), SWITCH_T,
														SCRIPTVAR_ST,
														ACTIONS_ST,
														(yyvsp[(3) - (7)].specval),
														(yyvsp[(6) - (7)].action));
									;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1874 "cfg.y"
    { (yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1875 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1877 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1878 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1882 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].intval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1891 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].intval),
													0,
													(void*)1);
											;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1899 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].intval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1907 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].intval),
													0,
													(void*)0);
							;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1916 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].strval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1925 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].strval),
													0,
													(void*)1);
											;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1933 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].strval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1941 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].strval),
													0,
													(void*)0);
							;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1952 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													(yyvsp[(3) - (3)].action),
													0);
									;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1958 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													0,
													0);
									;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1966 "cfg.y"
    {
										elems[1].type = STRING_ST;
										elems[1].u.data = (yyvsp[(1) - (1)].strval);
										(yyval.intval)=1;
										;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1971 "cfg.y"
    {
										if ((yyvsp[(1) - (3)].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[(1) - (3)].intval)+1].type = STRING_ST;
										elems[(yyvsp[(1) - (3)].intval)+1].u.data = (yyvsp[(3) - (3)].strval);
										(yyval.intval)=(yyvsp[(1) - (3)].intval)+1;
										;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1980 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1984 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1991 "cfg.y"
    { mk_action2( (yyval.action), FORWARD_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1997 "cfg.y"
    {
										mk_action2( (yyval.action), FORWARD_T,
											0,
											0,
											0,
											0);
										;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2004 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2005 "cfg.y"
    { (yyval.action)=0; yyerror("bad forward"
										"argument"); ;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2008 "cfg.y"
    { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2014 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2015 "cfg.y"
    { (yyval.action)=0; yyerror("bad send"
													"argument"); ;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2017 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2018 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); ;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2019 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); ;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2020 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); ;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2021 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].intval),
																0);
												;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2027 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																SCRIPTVAR_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].specval),
																0);
												;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2033 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2039 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2045 "cfg.y"
    {mk_action2( (yyval.action), LOG_T, NUMBER_ST, 
													STRING_ST,(void*)4,(yyvsp[(3) - (4)].strval));
									;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2048 "cfg.y"
    {mk_action2( (yyval.action), LOG_T,
																NUMBER_ST, 
																STRING_ST,
																(void*)(yyvsp[(3) - (6)].intval),
																(yyvsp[(5) - (6)].strval));
												;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2054 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2055 "cfg.y"
    { (yyval.action)=0; yyerror("bad log"
									"argument"); ;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2057 "cfg.y"
    {mk_action2((yyval.action), SET_DEBUG_T, NUMBER_ST,
									0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2059 "cfg.y"
    {mk_action2( (yyval.action), SET_DEBUG_T, 0, 0, 0, 0 ); ;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2060 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2061 "cfg.y"
    {mk_action2((yyval.action), SETFLAG_T, NUMBER_ST, 0,
													(void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2063 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2064 "cfg.y"
    {mk_action2( (yyval.action), RESETFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2066 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2067 "cfg.y"
    {mk_action2( (yyval.action), ISFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2069 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2070 "cfg.y"
    {mk_action2( (yyval.action), SETSFLAG_T, NUMBER_ST,
										0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2072 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2073 "cfg.y"
    {mk_action2( (yyval.action), RESETSFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2075 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2076 "cfg.y"
    {mk_action2( (yyval.action), ISSFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2078 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2079 "cfg.y"
    {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2083 "cfg.y"
    {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2086 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2087 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2091 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2095 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2096 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2100 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2104 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2105 "cfg.y"
    {mk_action2( (yyval.action), ERROR_T,
																STRING_ST, 
																STRING_ST,
																(yyvsp[(3) - (6)].strval),
																(yyvsp[(5) - (6)].strval));
												  ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2111 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2112 "cfg.y"
    { (yyval.action)=0; yyerror("bad error"
														"argument"); ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2114 "cfg.y"
    { 
						i_tmp = get_script_route_idx( (yyvsp[(3) - (4)].strval), rlist, RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						mk_action2( (yyval.action), ROUTE_T, NUMBER_ST,
							0, (void*)(long)i_tmp, 0);
					;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2120 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2121 "cfg.y"
    { (yyval.action)=0; yyerror("bad route"
						"argument"); ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2123 "cfg.y"
    { mk_action2( (yyval.action), SET_HOST_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2125 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2126 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2129 "cfg.y"
    { mk_action2( (yyval.action), PREFIX_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2131 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2132 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2134 "cfg.y"
    { mk_action2( (yyval.action), STRIP_TAIL_T, 
									NUMBER_ST, 0, (void *) (yyvsp[(3) - (4)].intval), 0); ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2136 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2137 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2140 "cfg.y"
    { mk_action2( (yyval.action), STRIP_T, NUMBER_ST,
														0, (void *) (yyvsp[(3) - (4)].intval), 0); ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2142 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2143 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); ;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2145 "cfg.y"
    { 
				{   qvalue_t q;
				if (str2q(&q, (yyvsp[(5) - (6)].strval), strlen((yyvsp[(5) - (6)].strval))) < 0) {
					yyerror("bad argument, q value expected");
				}
				mk_action2( (yyval.action), APPEND_BRANCH_T, STR_ST, NUMBER_ST, (yyvsp[(3) - (6)].strval),
						(void *)(long)q); } 
		;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2153 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, (yyvsp[(3) - (4)].strval), (void *)Q_UNSPECIFIED) ; ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2155 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED) ; ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2157 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED ) ; ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2160 "cfg.y"
    {
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[(3) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable in first parameter");
				}
				if(!pv_is_w(spec))
					yyerror("read-only script variable in first parameter");

				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, spec, pvmodel) ;
			;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2183 "cfg.y"
    {
				if(!pv_is_w((yyvsp[(3) - (6)].specval)))
					yyerror("read-only script variable in first parameter");
				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, (yyvsp[(3) - (6)].specval), pvmodel) ;
			;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2198 "cfg.y"
    { mk_action2( (yyval.action), SET_HOSTPORT_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2200 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2201 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
												" string expected"); ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2203 "cfg.y"
    { mk_action2( (yyval.action), SET_PORT_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2205 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2206 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2208 "cfg.y"
    { mk_action2( (yyval.action), SET_USER_T,
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2210 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2211 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2213 "cfg.y"
    { mk_action2( (yyval.action), SET_USERPASS_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2215 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2216 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2218 "cfg.y"
    { mk_action2( (yyval.action), SET_URI_T, STR_ST, 
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2220 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2221 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); ;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2223 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); ;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2224 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); ;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2225 "cfg.y"
    { mk_action2( (yyval.action), SET_DSTURI_T,
													STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2227 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2228 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); ;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2230 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T,
															0,0,0,0); ;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2232 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T, 0,0,0,0); ;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2233 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); ;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2234 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); ;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2235 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,
															0, 0, 0, 0); ;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2237 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,0, 0, 0, 0); ;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2238 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); ;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2240 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); ;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2242 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,NUMBER_ST, 0,
										(void*)(yyvsp[(3) - (4)].intval), 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
												;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2250 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0); 
					#else
						yyerror("tcp support not compiled in");
					#endif
										;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2257 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
										;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2264 "cfg.y"
    {(yyval.action)=0; 
					yyerror("bad argument, number expected");
					;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2267 "cfg.y"
    {
								(yyval.action)=0;
								if ((str_tmp=pkg_malloc(sizeof(str)))==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else if ((yyvsp[(3) - (4)].strval)!=0){
										str_tmp->s=(yyvsp[(3) - (4)].strval);
										str_tmp->len=strlen((yyvsp[(3) - (4)].strval));
										mk_action2( (yyval.action), SET_ADV_ADDR_T, STR_ST,
											0, str_tmp, 0);
								}
												  ;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2278 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 2280 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 2281 "cfg.y"
    {
								(yyval.action)=0;
								tmp=int2str((yyvsp[(3) - (4)].intval), &i_tmp);
								if ((str_tmp=pkg_malloc(sizeof(str)))==0){
										LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									if ((str_tmp->s=pkg_malloc(i_tmp))==0){
										LM_CRIT("cfg. parser: out of memory.\n");
									}else{
										memcpy(str_tmp->s, tmp, i_tmp);
										str_tmp->len=i_tmp;
										mk_action2( (yyval.action), SET_ADV_PORT_T, STR_ST,
													0, str_tmp, 0);
									}
								}
								            ;}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 2297 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
								"string expected"); ;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 2299 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 2300 "cfg.y"
    {
								mk_action2( (yyval.action), FORCE_SEND_SOCKET_T,
									SOCKID_ST, 0, (yyvsp[(3) - (4)].sockid), 0);
								;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 2304 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
								" [proto:]host[:port] expected");
								;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 2307 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 2308 "cfg.y"
    {
								mk_action2( (yyval.action), SERIALIZE_BRANCHES_T,
									NUMBER_ST, 0, (void*)(long)(yyvsp[(3) - (4)].intval), 0);
								;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 2312 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" number expected");
								;}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 2315 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 2316 "cfg.y"
    {
								mk_action2( (yyval.action), NEXT_BRANCHES_T, 0, 0, 0, 0);
								;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 2319 "cfg.y"
    {(yyval.action)=0; yyerror("no argument is"
								" expected");
								;}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 2322 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 2323 "cfg.y"
    {
								mk_action2( (yyval.action), USE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								;}
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 2327 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 2330 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 2331 "cfg.y"
    {
								mk_action2( (yyval.action), UNUSE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								;}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 2335 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 2338 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 2339 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_STORE_T,
													STR_ST,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].strval));
							;}
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 2349 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].strval); 
								elems[3].type = NUMBER_ST; 
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_STORE_T, 4, elems, line); 

							;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 2361 "cfg.y"
    { 
									mk_action2( (yyval.action), CACHE_REMOVE_T,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (6)].strval),
													(yyvsp[(5) - (6)].strval));
							;}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 2368 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_FETCH_T,
													STR_ST,
													STR_ST,
													SCRIPTVAR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].specval));
							;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 2377 "cfg.y"
    {
						 			cmd_tmp=(void*)find_cmd_export_t((yyvsp[(1) - (3)].strval), 0, rt);
									if (cmd_tmp==0){
										if (find_cmd_export_t((yyvsp[(1) - (3)].strval), 0, 0)) {
											yyerror("Command cannot be "
												"used in the block\n");
										} else {
											yyerrorf("unknown command <%s>, "
												"missing loadmodule?", (yyvsp[(1) - (3)].strval));
										}
										(yyval.action)=0;
									}else{
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										(yyval.action) = mk_action(MODULE_T, 1, elems, line);
									}
								;}
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 2394 "cfg.y"
    {
									cmd_tmp=(void*)find_cmd_export_t((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].intval), rt);
									if (cmd_tmp==0){
										if (find_cmd_export_t((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].intval), 0)) {
											yyerror("Command cannot be "
												"used in the block\n");
										} else {
											yyerrorf("unknown command <%s>, "
												"missing loadmodule?", (yyvsp[(1) - (4)].strval));
										}
										(yyval.action)=0;
									}else{
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										(yyval.action) = mk_action(MODULE_T, (yyvsp[(3) - (4)].intval)+1, elems, line);
									}
								;}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 2411 "cfg.y"
    { (yyval.action)=0; yyerrorf("bad arguments for "
												"command <%s>", (yyvsp[(1) - (4)].strval)); ;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 2413 "cfg.y"
    { (yyval.action)=0; yyerrorf("bare word <%s> found, command calls need '()'", (yyvsp[(1) - (2)].strval)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 8294 "cfg.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2423 "cfg.y"


extern int column;
extern int startcolumn;
#if !defined(USE_TLS) || !defined(USE_TCP) \
		||  !defined(USE_MCAST)
static void warn(char* s)
{
	LM_WARN("warning in config file, line %d, column %d-%d: %s\n", line, startcolumn, 
			column, s);
}
#endif

static void yyerror(char* s)
{
	LM_CRIT("parse error in config file, line %d, column %d-%d: %s\n", line, startcolumn, 
			column, s);
	cfg_errors++;
}

#define ERROR_MAXLEN 1024
static void yyerrorf(char *fmt, ...)
{
	char *tmp = pkg_malloc(ERROR_MAXLEN);
	va_list ap;
	va_start(ap, fmt);

	vsnprintf(tmp, ERROR_MAXLEN, fmt, ap);
	yyerror(tmp);

	pkg_free(tmp);
	va_end(ap);
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0){
		LM_CRIT("cfg. parser: out of memory.\n");
	}else{
		l->name=host;
		l->port=port;
		l->proto=proto;
		l->adv_name=NULL;
		l->adv_port=0;
		l->next=0;
	}
	return l;
}

static struct socket_id* set_listen_id_adv(struct socket_id* sock,
											char *adv_name,
											int adv_port)
{
	sock->adv_name=adv_name;
	sock->adv_port=adv_port;
	return sock;
}

