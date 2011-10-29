
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
#include "xlog.h"
#include "tcp_server.h"
#include "db/db_insertq.h"


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
#define mk_action1(_res, _type, _p1_type, _p1) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		_res = mk_action(_type, 1, elems, line); \
	} while(0)
#define	mk_action2(_res, _type, _p1_type, _p2_type, _p1, _p2) \
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
#line 185 "cfg.tab.c"

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
     REMOVE_BRANCH = 279,
     PV_PRINTF = 280,
     SET_USER = 281,
     SET_USERPASS = 282,
     SET_PORT = 283,
     SET_URI = 284,
     REVERT_URI = 285,
     SET_DSTURI = 286,
     RESET_DSTURI = 287,
     ISDSTURISET = 288,
     FORCE_RPORT = 289,
     FORCE_LOCAL_RPORT = 290,
     FORCE_TCP_ALIAS = 291,
     IF = 292,
     ELSE = 293,
     SWITCH = 294,
     CASE = 295,
     DEFAULT = 296,
     SBREAK = 297,
     WHILE = 298,
     SET_ADV_ADDRESS = 299,
     SET_ADV_PORT = 300,
     FORCE_SEND_SOCKET = 301,
     SERIALIZE_BRANCHES = 302,
     NEXT_BRANCHES = 303,
     USE_BLACKLIST = 304,
     UNUSE_BLACKLIST = 305,
     MAX_LEN = 306,
     SETDEBUG = 307,
     SETFLAG = 308,
     RESETFLAG = 309,
     ISFLAGSET = 310,
     SETBFLAG = 311,
     RESETBFLAG = 312,
     ISBFLAGSET = 313,
     SETSFLAG = 314,
     RESETSFLAG = 315,
     ISSFLAGSET = 316,
     METHOD = 317,
     URI = 318,
     FROM_URI = 319,
     TO_URI = 320,
     SRCIP = 321,
     SRCPORT = 322,
     DSTIP = 323,
     DSTPORT = 324,
     PROTO = 325,
     AF = 326,
     MYSELF = 327,
     MSGLEN = 328,
     UDP = 329,
     TCP = 330,
     TLS = 331,
     SCTP = 332,
     NULLV = 333,
     CACHE_STORE = 334,
     CACHE_FETCH = 335,
     CACHE_REMOVE = 336,
     XDBG = 337,
     XLOG = 338,
     XLOG_BUF_SIZE = 339,
     XLOG_FORCE_COLOR = 340,
     RAISE_EVENT = 341,
     CONSTRUCT_URI = 342,
     GET_TIMESTAMP = 343,
     DEBUG = 344,
     FORK = 345,
     LOGSTDERROR = 346,
     LOGFACILITY = 347,
     LOGNAME = 348,
     AVP_ALIASES = 349,
     LISTEN = 350,
     ALIAS = 351,
     AUTO_ALIASES = 352,
     DNS = 353,
     REV_DNS = 354,
     DNS_TRY_IPV6 = 355,
     DNS_RETR_TIME = 356,
     DNS_RETR_NO = 357,
     DNS_SERVERS_NO = 358,
     DNS_USE_SEARCH = 359,
     MAX_WHILE_LOOPS = 360,
     PORT = 361,
     CHILDREN = 362,
     CHECK_VIA = 363,
     MEMLOG = 364,
     MEMDUMP = 365,
     EXECMSGTHRESHOLD = 366,
     EXECDNSTHRESHOLD = 367,
     TCPTHRESHOLD = 368,
     QUERYBUFFERSIZE = 369,
     QUERYFLUSHTIME = 370,
     SIP_WARNING = 371,
     SOCK_MODE = 372,
     SOCK_USER = 373,
     SOCK_GROUP = 374,
     UNIX_SOCK = 375,
     UNIX_SOCK_CHILDREN = 376,
     UNIX_TX_TIMEOUT = 377,
     SERVER_SIGNATURE = 378,
     SERVER_HEADER = 379,
     USER_AGENT_HEADER = 380,
     LOADMODULE = 381,
     MPATH = 382,
     MODPARAM = 383,
     MAXBUFFER = 384,
     USER = 385,
     GROUP = 386,
     CHROOT = 387,
     WDIR = 388,
     MHOMED = 389,
     DISABLE_TCP = 390,
     TCP_ACCEPT_ALIASES = 391,
     TCP_CHILDREN = 392,
     TCP_CONNECT_TIMEOUT = 393,
     TCP_SEND_TIMEOUT = 394,
     TCP_CON_LIFETIME = 395,
     TCP_POLL_METHOD = 396,
     TCP_MAX_CONNECTIONS = 397,
     TCP_OPT_CRLF_PINGPONG = 398,
     TCP_NO_NEW_CONN_BFLAG = 399,
     DISABLE_TLS = 400,
     TLSLOG = 401,
     TLS_PORT_NO = 402,
     TLS_METHOD = 403,
     TLS_HANDSHAKE_TIMEOUT = 404,
     TLS_SEND_TIMEOUT = 405,
     TLS_SERVER_DOMAIN = 406,
     TLS_CLIENT_DOMAIN = 407,
     TLS_CLIENT_DOMAIN_AVP = 408,
     SSLv23 = 409,
     SSLv2 = 410,
     SSLv3 = 411,
     TLSv1 = 412,
     TLS_VERIFY_CLIENT = 413,
     TLS_VERIFY_SERVER = 414,
     TLS_REQUIRE_CLIENT_CERTIFICATE = 415,
     TLS_CERTIFICATE = 416,
     TLS_PRIVATE_KEY = 417,
     TLS_CA_LIST = 418,
     TLS_CIPHERS_LIST = 419,
     ADVERTISED_ADDRESS = 420,
     ADVERTISED_PORT = 421,
     DISABLE_CORE = 422,
     OPEN_FD_LIMIT = 423,
     MCAST_LOOPBACK = 424,
     MCAST_TTL = 425,
     TOS = 426,
     DISABLE_DNS_FAILOVER = 427,
     DISABLE_DNS_BLACKLIST = 428,
     DST_BLACKLIST = 429,
     DISABLE_STATELESS_FWD = 430,
     DB_VERSION_TABLE = 431,
     DB_DEFAULT_URL = 432,
     DISABLE_503_TRANSLATION = 433,
     EQUAL = 434,
     EQUAL_T = 435,
     GT = 436,
     LT = 437,
     GTE = 438,
     LTE = 439,
     DIFF = 440,
     MATCH = 441,
     NOTMATCH = 442,
     COLONEQ = 443,
     PLUSEQ = 444,
     MINUSEQ = 445,
     SLASHEQ = 446,
     MULTEQ = 447,
     MODULOEQ = 448,
     BANDEQ = 449,
     BOREQ = 450,
     BXOREQ = 451,
     AND = 452,
     OR = 453,
     BRSHIFT = 454,
     BLSHIFT = 455,
     BXOR = 456,
     BAND = 457,
     BOR = 458,
     MODULO = 459,
     MULT = 460,
     SLASH = 461,
     MINUS = 462,
     PLUS = 463,
     BNOT = 464,
     NOT = 465,
     NUMBER = 466,
     ZERO = 467,
     ID = 468,
     STRING = 469,
     SCRIPTVAR = 470,
     IPV6ADDR = 471,
     COMMA = 472,
     SEMICOLON = 473,
     RPAREN = 474,
     LPAREN = 475,
     LBRACE = 476,
     RBRACE = 477,
     LBRACK = 478,
     RBRACK = 479,
     AS = 480,
     DOT = 481,
     CR = 482,
     COLON = 483,
     ANY = 484,
     SCRIPTVARERR = 485
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 186 "cfg.y"

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
#line 465 "cfg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 477 "cfg.tab.c"

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
#define YYFINAL  192
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  586
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   485

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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230
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
     531,   535,   539,   543,   547,   551,   555,   559,   563,   567,
     571,   575,   579,   583,   587,   591,   595,   599,   603,   607,
     611,   613,   615,   619,   623,   627,   631,   635,   639,   643,
     647,   651,   655,   659,   663,   667,   671,   675,   679,   683,
     687,   691,   695,   699,   703,   707,   711,   715,   719,   723,
     727,   731,   735,   739,   743,   747,   751,   754,   758,   761,
     769,   773,   777,   781,   785,   789,   793,   797,   800,   803,
     806,   815,   824,   827,   829,   831,   839,   841,   843,   847,
     848,   859,   860,   871,   872,   881,   883,   886,   888,   891,
     895,   899,   903,   907,   911,   915,   919,   923,   927,   931,
     935,   939,   943,   947,   951,   955,   959,   963,   967,   971,
     975,   979,   983,   987,   991,   995,   999,  1003,  1007,  1011,
    1015,  1019,  1021,  1023,  1025,  1030,  1038,  1041,  1049,  1052,
    1057,  1065,  1068,  1076,  1079,  1084,  1087,  1092,  1095,  1100,
    1103,  1113,  1116,  1120,  1124,  1127,  1131,  1135,  1137,  1139,
    1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,
    1161,  1163,  1165,  1167,  1169,  1171,  1173,  1175,  1177,  1179,
    1181,  1185,  1189,  1193,  1197,  1201,  1205,  1209,  1213,  1216,
    1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,  1252,  1255,
    1259,  1263,  1266,  1270,  1274,  1277,  1281,  1285,  1288,  1292,
    1296,  1299,  1303,  1307,  1311,  1314,  1318,  1322,  1326,  1329,
    1333,  1337,  1341,  1344,  1348,  1352,  1356,  1360,  1363,  1367,
    1371,  1373,  1377,  1379,  1381,  1383,  1387,  1391,  1393,  1395,
    1397,  1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,
    1417,  1419,  1421,  1423,  1427,  1431,  1435,  1439,  1443,  1447,
    1451,  1455,  1459,  1463,  1466,  1470,  1474,  1478,  1482,  1484,
    1486,  1488,  1492,  1495,  1497,  1501,  1504,  1507,  1509,  1512,
    1515,  1517,  1519,  1521,  1524,  1526,  1529,  1533,  1539,  1543,
    1551,  1554,  1556,  1559,  1561,  1568,  1574,  1579,  1583,  1590,
    1596,  1601,  1605,  1609,  1612,  1614,  1618,  1620,  1624,  1629,
    1633,  1636,  1641,  1646,  1649,  1654,  1658,  1660,  1664,  1666,
    1671,  1676,  1680,  1682,  1687,  1694,  1697,  1702,  1707,  1711,
    1714,  1719,  1722,  1727,  1730,  1735,  1738,  1743,  1746,  1751,
    1754,  1759,  1762,  1769,  1774,  1777,  1784,  1789,  1792,  1799,
    1804,  1807,  1814,  1817,  1822,  1827,  1830,  1835,  1840,  1843,
    1848,  1853,  1856,  1861,  1866,  1869,  1874,  1879,  1882,  1887,
    1894,  1899,  1903,  1905,  1910,  1915,  1922,  1929,  1934,  1937,
    1942,  1947,  1950,  1955,  1960,  1963,  1968,  1973,  1976,  1981,
    1986,  1989,  1994,  1998,  2000,  2005,  2008,  2013,  2017,  2019,
    2023,  2025,  2029,  2031,  2035,  2037,  2042,  2046,  2048,  2053,
    2058,  2063,  2066,  2071,  2076,  2079,  2084,  2089,  2092,  2097,
    2102,  2105,  2109,  2114,  2117,  2122,  2127,  2130,  2135,  2140,
    2143,  2152,  2163,  2174,  2181,  2190,  2194,  2199,  2204,  2207,
    2212,  2217,  2224,  2229,  2236,  2245,  2260
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     232,     0,    -1,   233,    -1,   233,   234,    -1,   234,    -1,
     233,     1,    -1,   251,    -1,   252,    -1,    -1,   235,   267,
      -1,    -1,   236,   268,    -1,    -1,   237,   269,    -1,    -1,
     238,   270,    -1,    -1,   239,   271,    -1,    -1,   240,   272,
      -1,    -1,   241,   273,    -1,    -1,   242,   274,    -1,   227,
      -1,   253,    -1,   214,    -1,   287,    -1,    74,    -1,    75,
      -1,    76,    -1,    77,    -1,   229,    -1,   211,    -1,   229,
      -1,   211,    -1,   208,   211,    -1,   207,   211,    -1,   243,
      -1,   243,   228,   245,    -1,   244,   228,   243,    -1,   244,
     228,   243,   228,   245,    -1,   247,   225,   243,    -1,   247,
     225,   243,   228,   245,    -1,   243,   228,     1,    -1,   247,
      -1,   247,   248,    -1,   220,   244,   217,   285,   217,   245,
     217,   214,   219,    -1,   210,   220,   244,   217,   285,   217,
     245,   217,   214,   219,    -1,   250,   217,   249,    -1,   249,
      -1,   250,     1,    -1,    89,   179,   246,    -1,    89,   179,
       1,    -1,    90,   179,   211,    -1,    90,   179,     1,    -1,
      91,   179,   211,    -1,    91,   179,     1,    -1,    92,   179,
     213,    -1,    92,   179,     1,    -1,    93,   179,   214,    -1,
      93,   179,     1,    -1,    94,   179,   214,    -1,    94,   179,
       1,    -1,    98,   179,   211,    -1,    98,   179,     1,    -1,
      99,   179,   211,    -1,    99,   179,     1,    -1,   100,   179,
     211,    -1,   100,     1,    -1,   101,   179,   211,    -1,   101,
       1,    -1,   102,   179,   211,    -1,   102,     1,    -1,   103,
     179,   211,    -1,   103,     1,    -1,   104,   179,   211,    -1,
     104,     1,    -1,   106,   179,   211,    -1,   106,   179,     1,
      -1,   105,   179,   211,    -1,   105,   179,     1,    -1,   129,
     179,   211,    -1,   129,   179,     1,    -1,   107,   179,   211,
      -1,   107,   179,     1,    -1,   108,   179,   211,    -1,   108,
     179,     1,    -1,   109,   179,   211,    -1,   109,   179,     1,
      -1,   110,   179,   211,    -1,   110,   179,     1,    -1,   111,
     179,   211,    -1,   111,   179,     1,    -1,   112,   179,   211,
      -1,   112,   179,     1,    -1,   113,   179,   211,    -1,   113,
     179,     1,    -1,   114,   179,   211,    -1,   114,   179,     1,
      -1,   115,   179,   211,    -1,   115,   179,     1,    -1,   116,
     179,   211,    -1,   116,   179,     1,    -1,   130,   179,   214,
      -1,   130,   179,   213,    -1,   130,   179,     1,    -1,   131,
     179,   214,    -1,   131,   179,   213,    -1,   131,   179,     1,
      -1,   132,   179,   214,    -1,   132,   179,   213,    -1,   132,
     179,     1,    -1,   133,   179,   214,    -1,   133,   179,   213,
      -1,   133,   179,     1,    -1,   134,   179,   211,    -1,   134,
     179,     1,    -1,   135,   179,   211,    -1,   135,   179,     1,
      -1,   136,   179,   211,    -1,   136,   179,     1,    -1,   137,
     179,   211,    -1,   137,   179,     1,    -1,   138,   179,   211,
      -1,   138,   179,     1,    -1,   139,   179,   211,    -1,   139,
     179,     1,    -1,   140,   179,   211,    -1,   140,   179,     1,
      -1,   141,   179,   213,    -1,   141,   179,   214,    -1,   141,
     179,     1,    -1,   142,   179,   211,    -1,   142,   179,     1,
      -1,   143,   179,   211,    -1,   143,   179,     1,    -1,   144,
     179,   211,    -1,   144,   179,     1,    -1,   145,   179,   211,
      -1,   145,   179,     1,    -1,   146,   179,   211,    -1,   146,
     179,     1,    -1,   147,   179,   211,    -1,   147,   179,     1,
      -1,   148,   179,   154,    -1,   148,   179,   155,    -1,   148,
     179,   156,    -1,   148,   179,   157,    -1,   148,   179,     1,
      -1,   158,   179,   211,    -1,   158,   179,     1,    -1,   159,
     179,   211,    -1,   159,   179,     1,    -1,   160,   179,   211,
      -1,   160,   179,     1,    -1,   161,   179,   214,    -1,   161,
     179,     1,    -1,   162,   179,   214,    -1,   162,   179,     1,
      -1,   163,   179,   214,    -1,   163,   179,     1,    -1,   164,
     179,   214,    -1,   164,   179,     1,    -1,   149,   179,   211,
      -1,   149,   179,     1,    -1,   150,   179,   211,    -1,   150,
     179,     1,    -1,   153,   179,   214,    -1,   153,   179,     1,
      -1,   257,    -1,   259,    -1,   123,   179,   211,    -1,   123,
     179,     1,    -1,   124,   179,   214,    -1,   124,   179,     1,
      -1,   125,   179,   214,    -1,   125,   179,     1,    -1,    84,
     179,   211,    -1,    85,   179,   211,    -1,    84,   179,     1,
      -1,    85,   179,     1,    -1,    95,   179,   248,    -1,    95,
     179,     1,    -1,    96,   179,   248,    -1,    96,   179,     1,
      -1,    97,   179,   211,    -1,    97,   179,     1,    -1,   165,
     179,   243,    -1,   165,   179,     1,    -1,   166,   179,   211,
      -1,   166,   179,     1,    -1,   167,   179,   211,    -1,   167,
     179,     1,    -1,   168,   179,   211,    -1,   168,   179,     1,
      -1,   169,   179,   211,    -1,   169,   179,     1,    -1,   170,
     179,   211,    -1,   170,   179,     1,    -1,   171,   179,   211,
      -1,   171,   179,   213,    -1,   171,   179,     1,    -1,   127,
     179,   214,    -1,   127,   179,     1,    -1,   172,   179,   211,
      -1,   172,     1,    -1,   173,   179,   211,    -1,   173,     1,
      -1,   174,   179,   213,   228,   221,   250,   222,    -1,   175,
     179,   211,    -1,   176,   179,   214,    -1,   176,   179,     1,
      -1,   177,   179,   214,    -1,   177,   179,     1,    -1,   178,
     179,   211,    -1,   178,   179,     1,    -1,     1,   179,    -1,
     126,   214,    -1,   126,     1,    -1,   128,   220,   214,   217,
     214,   217,   214,   219,    -1,   128,   220,   214,   217,   214,
     217,   246,   219,    -1,   128,     1,    -1,   254,    -1,   256,
      -1,   211,   226,   211,   226,   211,   226,   211,    -1,   216,
      -1,   255,    -1,   223,   255,   224,    -1,    -1,   151,   223,
     253,   228,   245,   224,   258,   221,   262,   222,    -1,    -1,
     152,   223,   253,   228,   245,   224,   260,   221,   263,   222,
      -1,    -1,   152,   223,   214,   224,   261,   221,   263,   222,
      -1,   264,    -1,   262,   264,    -1,   265,    -1,   263,   265,
      -1,   148,   179,   154,    -1,   148,   179,   155,    -1,   148,
     179,   156,    -1,   148,   179,   157,    -1,   148,   179,     1,
      -1,   161,   179,   214,    -1,   161,   179,     1,    -1,   162,
     179,   214,    -1,   162,   179,     1,    -1,   163,   179,   214,
      -1,   163,   179,     1,    -1,   164,   179,   214,    -1,   164,
     179,     1,    -1,   158,   179,   211,    -1,   158,   179,     1,
      -1,   160,   179,   211,    -1,   160,   179,     1,    -1,   148,
     179,   154,    -1,   148,   179,   155,    -1,   148,   179,   156,
      -1,   148,   179,   157,    -1,   148,   179,     1,    -1,   161,
     179,   214,    -1,   161,   179,     1,    -1,   162,   179,   214,
      -1,   162,   179,     1,    -1,   163,   179,   214,    -1,   163,
     179,     1,    -1,   164,   179,   214,    -1,   164,   179,     1,
      -1,   159,   179,   211,    -1,   159,   179,     1,    -1,   213,
      -1,   211,    -1,   214,    -1,    10,   221,   293,   222,    -1,
      10,   223,   266,   224,   221,   293,   222,    -1,    10,     1,
      -1,    11,   223,   266,   224,   221,   293,   222,    -1,    11,
       1,    -1,    12,   221,   293,   222,    -1,    12,   223,   266,
     224,   221,   293,   222,    -1,    12,     1,    -1,    13,   223,
     266,   224,   221,   293,   222,    -1,    13,     1,    -1,    14,
     221,   293,   222,    -1,    14,     1,    -1,    15,   221,   293,
     222,    -1,    15,     1,    -1,    16,   221,   293,   222,    -1,
      16,     1,    -1,    17,   223,   266,   217,   211,   224,   221,
     293,   222,    -1,    17,     1,    -1,   275,   197,   275,    -1,
     275,   198,   275,    -1,   210,   275,    -1,   220,   275,   219,
      -1,   223,   289,   224,    -1,   283,    -1,   180,    -1,   185,
      -1,   181,    -1,   182,    -1,   183,    -1,   184,    -1,   186,
      -1,   187,    -1,   276,    -1,   277,    -1,   276,    -1,   277,
      -1,   278,    -1,    63,    -1,    64,    -1,    65,    -1,   215,
      -1,   230,    -1,   284,    -1,   291,    -1,   246,    -1,   282,
      -1,   281,   280,   287,    -1,    68,   276,   285,    -1,    68,
     280,   287,    -1,    66,   276,   285,    -1,    66,   280,   287,
      -1,    62,   280,   214,    -1,    62,   280,   213,    -1,    62,
     280,     1,    -1,    62,     1,    -1,   282,   280,   282,    -1,
     282,   280,   214,    -1,   282,   280,   213,    -1,   282,   279,
     246,    -1,   282,   276,    72,    -1,   282,   276,    78,    -1,
     281,   280,   214,    -1,   281,   276,    72,    -1,   281,   280,
       1,    -1,   281,     1,    -1,    67,   279,   211,    -1,    67,
     279,     1,    -1,    67,     1,    -1,    69,   279,   211,    -1,
      69,   279,     1,    -1,    69,     1,    -1,    70,   279,   244,
      -1,    70,   279,     1,    -1,    70,     1,    -1,    71,   279,
     211,    -1,    71,   279,     1,    -1,    71,     1,    -1,    73,
     279,   211,    -1,    73,   279,    51,    -1,    73,   279,     1,
      -1,    73,     1,    -1,    66,   280,   214,    -1,    66,   276,
      72,    -1,    66,   280,     1,    -1,    66,     1,    -1,    68,
     280,   214,    -1,    68,   276,    72,    -1,    68,   280,     1,
      -1,    68,     1,    -1,    72,   276,   281,    -1,    72,   276,
      66,    -1,    72,   276,    68,    -1,    72,   276,     1,    -1,
      72,     1,    -1,   253,   206,   253,    -1,   253,   206,   211,
      -1,   253,    -1,   253,   206,     1,    -1,   226,    -1,   207,
      -1,   213,    -1,   287,   286,   213,    -1,   287,   226,     1,
      -1,   179,    -1,   188,    -1,   189,    -1,   190,    -1,   191,
      -1,   192,    -1,   193,    -1,   194,    -1,   195,    -1,   196,
      -1,   246,    -1,   214,    -1,   213,    -1,   282,    -1,   284,
      -1,   303,    -1,   289,   208,   289,    -1,   289,   207,   289,
      -1,   289,   205,   289,    -1,   289,   206,   289,    -1,   289,
     204,   289,    -1,   289,   202,   289,    -1,   289,   203,   289,
      -1,   289,   201,   289,    -1,   289,   200,   289,    -1,   289,
     199,   289,    -1,   209,   289,    -1,   220,   289,   219,    -1,
     282,   288,   289,    -1,   282,   179,    78,    -1,   282,   188,
      78,    -1,   303,    -1,   295,    -1,   290,    -1,   221,   293,
     222,    -1,   221,   222,    -1,   294,    -1,   221,   293,   222,
      -1,   221,   222,    -1,   293,   294,    -1,   294,    -1,   293,
       1,    -1,   303,   218,    -1,   295,    -1,   296,    -1,   297,
      -1,   290,   218,    -1,   218,    -1,   303,     1,    -1,    37,
     275,   292,    -1,    37,   275,   292,    38,   292,    -1,    43,
     275,   292,    -1,    39,   220,   282,   219,   221,   298,   222,
      -1,   299,   301,    -1,   299,    -1,   299,   300,    -1,   300,
      -1,    40,   246,   228,   293,    42,   218,    -1,    40,   246,
     228,    42,   218,    -1,    40,   246,   228,   293,    -1,    40,
     246,   228,    -1,    40,   214,   228,   293,    42,   218,    -1,
      40,   214,   228,    42,   218,    -1,    40,   214,   228,   293,
      -1,    40,   214,   228,    -1,    41,   228,   293,    -1,    41,
     228,    -1,   214,    -1,   302,   217,   214,    -1,   211,    -1,
     302,   217,   211,    -1,     3,   220,   214,   219,    -1,     3,
     220,   219,    -1,     3,     1,    -1,     3,   220,     1,   219,
      -1,     4,   220,   214,   219,    -1,     4,     1,    -1,     4,
     220,     1,   219,    -1,     5,   220,   219,    -1,     5,    -1,
       6,   220,   219,    -1,     6,    -1,     7,   220,   246,   219,
      -1,     7,   220,   282,   219,    -1,     7,   220,   219,    -1,
       7,    -1,     8,   220,   214,   219,    -1,     8,   220,   246,
     217,   214,   219,    -1,     8,     1,    -1,     8,   220,     1,
     219,    -1,    52,   220,   211,   219,    -1,    52,   220,   219,
      -1,    52,     1,    -1,    53,   220,   211,   219,    -1,    53,
       1,    -1,    54,   220,   211,   219,    -1,    54,     1,    -1,
      55,   220,   211,   219,    -1,    55,     1,    -1,    59,   220,
     211,   219,    -1,    59,     1,    -1,    60,   220,   211,   219,
      -1,    60,     1,    -1,    61,   220,   211,   219,    -1,    61,
       1,    -1,    56,   220,   211,   217,   211,   219,    -1,    56,
     220,   211,   219,    -1,    56,     1,    -1,    57,   220,   211,
     217,   211,   219,    -1,    57,   220,   211,   219,    -1,    57,
       1,    -1,    58,   220,   211,   217,   211,   219,    -1,    58,
     220,   211,   219,    -1,    58,     1,    -1,     9,   220,   214,
     217,   214,   219,    -1,     9,     1,    -1,     9,   220,     1,
     219,    -1,    10,   220,   266,   219,    -1,    10,     1,    -1,
      10,   220,     1,   219,    -1,    18,   220,   214,   219,    -1,
      18,     1,    -1,    18,   220,     1,   219,    -1,    20,   220,
     214,   219,    -1,    20,     1,    -1,    20,   220,     1,   219,
      -1,    22,   220,   211,   219,    -1,    22,     1,    -1,    22,
     220,     1,   219,    -1,    21,   220,   211,   219,    -1,    21,
       1,    -1,    21,   220,     1,   219,    -1,    23,   220,   214,
     217,   214,   219,    -1,    23,   220,   214,   219,    -1,    23,
     220,   219,    -1,    23,    -1,    24,   220,   211,   219,    -1,
      24,   220,   282,   219,    -1,    25,   220,   214,   217,   214,
     219,    -1,    25,   220,   282,   217,   214,   219,    -1,    19,
     220,   214,   219,    -1,    19,     1,    -1,    19,   220,     1,
     219,    -1,    28,   220,   214,   219,    -1,    28,     1,    -1,
      28,   220,     1,   219,    -1,    26,   220,   214,   219,    -1,
      26,     1,    -1,    26,   220,     1,   219,    -1,    27,   220,
     214,   219,    -1,    27,     1,    -1,    27,   220,     1,   219,
      -1,    29,   220,   214,   219,    -1,    29,     1,    -1,    29,
     220,     1,   219,    -1,    30,   220,   219,    -1,    30,    -1,
      31,   220,   214,   219,    -1,    31,     1,    -1,    31,   220,
       1,   219,    -1,    32,   220,   219,    -1,    32,    -1,    33,
     220,   219,    -1,    33,    -1,    34,   220,   219,    -1,    34,
      -1,    35,   220,   219,    -1,    35,    -1,    36,   220,   211,
     219,    -1,    36,   220,   219,    -1,    36,    -1,    36,   220,
       1,   219,    -1,    44,   220,   243,   219,    -1,    44,   220,
       1,   219,    -1,    44,     1,    -1,    45,   220,   211,   219,
      -1,    45,   220,     1,   219,    -1,    45,     1,    -1,    46,
     220,   247,   219,    -1,    46,   220,     1,   219,    -1,    46,
       1,    -1,    47,   220,   211,   219,    -1,    47,   220,     1,
     219,    -1,    47,     1,    -1,    48,   220,   219,    -1,    48,
     220,     1,   219,    -1,    48,     1,    -1,    49,   220,   214,
     219,    -1,    49,   220,     1,   219,    -1,    49,     1,    -1,
      50,   220,   214,   219,    -1,    50,   220,     1,   219,    -1,
      50,     1,    -1,    79,   220,   214,   217,   214,   217,   214,
     219,    -1,    79,   220,   214,   217,   214,   217,   214,   217,
     211,   219,    -1,    79,   220,   214,   217,   214,   217,   214,
     217,   282,   219,    -1,    81,   220,   214,   217,   214,   219,
      -1,    80,   220,   214,   217,   214,   217,   282,   219,    -1,
     213,   220,   219,    -1,   213,   220,   302,   219,    -1,   213,
     220,     1,   219,    -1,   213,     1,    -1,    82,   220,   214,
     219,    -1,    83,   220,   214,   219,    -1,    83,   220,   214,
     217,   214,   219,    -1,    86,   220,   214,   219,    -1,    86,
     220,   214,   217,   282,   219,    -1,    86,   220,   214,   217,
     282,   217,   282,   219,    -1,    87,   220,   214,   217,   214,
     217,   214,   217,   214,   217,   214,   217,   282,   219,    -1,
      88,   220,   282,   217,   282,   219,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   460,   460,   463,   464,   465,   468,   469,   470,   470,
     471,   471,   472,   472,   473,   473,   474,   474,   475,   475,
     476,   476,   477,   477,   479,   482,   495,   502,   515,   516,
     517,   525,   532,   535,   536,   539,   540,   541,   545,   546,
     547,   548,   549,   550,   551,   554,   555,   559,   566,   576,
     577,   578,   582,   589,   590,   591,   592,   593,   594,   600,
     601,   602,   603,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   671,
     672,   679,   680,   687,   688,   695,   696,   703,   704,   711,
     712,   726,   740,   741,   748,   749,   756,   757,   767,   768,
     775,   776,   783,   784,   791,   792,   802,   812,   822,   832,
     841,   849,   850,   858,   859,   866,   867,   877,   878,   888,
     889,   899,   900,   910,   911,   918,   919,   926,   927,   938,
     939,   940,   941,   942,   943,   946,   947,   950,   951,   952,
     953,   954,   956,   971,   974,   979,   981,   982,   983,   989,
     991,  1003,  1005,  1008,  1009,  1012,  1013,  1020,  1021,  1028,
    1029,  1033,  1060,  1061,  1069,  1070,  1073,  1074,  1077,  1078,
    1088,  1091,  1092,  1093,  1094,  1095,  1096,  1099,  1102,  1141,
    1142,  1148,  1154,  1158,  1159,  1162,  1196,  1216,  1217,  1220,
    1220,  1231,  1231,  1242,  1242,  1253,  1254,  1257,  1258,  1261,
    1268,  1275,  1282,  1289,  1290,  1297,  1299,  1306,  1308,  1315,
    1316,  1323,  1324,  1331,  1332,  1339,  1343,  1350,  1357,  1364,
    1371,  1373,  1380,  1382,  1389,  1391,  1398,  1399,  1406,  1407,
    1414,  1417,  1420,  1427,  1432,  1440,  1455,  1458,  1464,  1467,
    1475,  1481,  1484,  1490,  1493,  1501,  1504,  1512,  1515,  1523,
    1526,  1538,  1541,  1542,  1543,  1544,  1545,  1546,  1549,  1550,
    1553,  1554,  1555,  1556,  1558,  1559,  1562,  1563,  1566,  1567,
    1568,  1571,  1572,  1573,  1576,  1590,  1595,  1596,  1597,  1599,
    1602,  1604,  1606,  1608,  1610,  1614,  1616,  1618,  1619,  1622,
    1625,  1628,  1631,  1634,  1637,  1640,  1642,  1644,  1645,  1648,
    1650,  1651,  1652,  1654,  1655,  1656,  1658,  1661,  1662,  1664,
    1665,  1666,  1668,  1670,  1671,  1672,  1686,  1688,  1690,  1692,
    1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1725,  1726,
    1737,  1738,  1745,  1746,  1749,  1750,  1762,  1766,  1767,  1768,
    1769,  1770,  1771,  1772,  1773,  1774,  1775,  1779,  1780,  1781,
    1782,  1783,  1784,  1785,  1788,  1791,  1794,  1797,  1800,  1803,
    1806,  1809,  1812,  1815,  1818,  1821,  1834,  1847,  1869,  1870,
    1871,  1872,  1873,  1876,  1877,  1878,  1881,  1882,  1883,  1886,
    1887,  1888,  1889,  1890,  1891,  1892,  1895,  1903,  1913,  1921,
    1930,  1931,  1933,  1934,  1937,  1946,  1955,  1963,  1971,  1980,
    1989,  1997,  2008,  2014,  2022,  2027,  2036,  2040,  2047,  2053,
    2060,  2061,  2064,  2070,  2071,  2073,  2074,  2075,  2076,  2077,
    2083,  2089,  2095,  2101,  2104,  2110,  2111,  2113,  2115,  2116,
    2117,  2119,  2120,  2122,  2123,  2125,  2126,  2128,  2129,  2131,
    2132,  2134,  2135,  2139,  2142,  2143,  2147,  2151,  2152,  2156,
    2160,  2161,  2167,  2168,  2170,  2176,  2177,  2179,  2181,  2182,
    2185,  2187,  2188,  2190,  2192,  2193,  2196,  2198,  2199,  2201,
    2209,  2211,  2213,  2215,  2217,  2220,  2243,  2258,  2260,  2261,
    2263,  2265,  2266,  2268,  2270,  2271,  2273,  2275,  2276,  2278,
    2280,  2281,  2283,  2284,  2285,  2287,  2288,  2290,  2292,  2293,
    2294,  2295,  2297,  2298,  2300,  2302,  2310,  2317,  2324,  2327,
    2338,  2340,  2341,  2357,  2359,  2360,  2364,  2367,  2368,  2372,
    2375,  2376,  2379,  2382,  2383,  2387,  2390,  2391,  2395,  2398,
    2399,  2408,  2420,  2433,  2440,  2449,  2466,  2483,  2485,  2487,
    2489,  2491,  2493,  2495,  2497,  2499,  2513
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
  "STRIP_TAIL", "APPEND_BRANCH", "REMOVE_BRANCH", "PV_PRINTF", "SET_USER",
  "SET_USERPASS", "SET_PORT", "SET_URI", "REVERT_URI", "SET_DSTURI",
  "RESET_DSTURI", "ISDSTURISET", "FORCE_RPORT", "FORCE_LOCAL_RPORT",
  "FORCE_TCP_ALIAS", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "SBREAK",
  "WHILE", "SET_ADV_ADDRESS", "SET_ADV_PORT", "FORCE_SEND_SOCKET",
  "SERIALIZE_BRANCHES", "NEXT_BRANCHES", "USE_BLACKLIST",
  "UNUSE_BLACKLIST", "MAX_LEN", "SETDEBUG", "SETFLAG", "RESETFLAG",
  "ISFLAGSET", "SETBFLAG", "RESETBFLAG", "ISBFLAGSET", "SETSFLAG",
  "RESETSFLAG", "ISSFLAGSET", "METHOD", "URI", "FROM_URI", "TO_URI",
  "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "PROTO", "AF", "MYSELF",
  "MSGLEN", "UDP", "TCP", "TLS", "SCTP", "NULLV", "CACHE_STORE",
  "CACHE_FETCH", "CACHE_REMOVE", "XDBG", "XLOG", "XLOG_BUF_SIZE",
  "XLOG_FORCE_COLOR", "RAISE_EVENT", "CONSTRUCT_URI", "GET_TIMESTAMP",
  "DEBUG", "FORK", "LOGSTDERROR", "LOGFACILITY", "LOGNAME", "AVP_ALIASES",
  "LISTEN", "ALIAS", "AUTO_ALIASES", "DNS", "REV_DNS", "DNS_TRY_IPV6",
  "DNS_RETR_TIME", "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH",
  "MAX_WHILE_LOOPS", "PORT", "CHILDREN", "CHECK_VIA", "MEMLOG", "MEMDUMP",
  "EXECMSGTHRESHOLD", "EXECDNSTHRESHOLD", "TCPTHRESHOLD",
  "QUERYBUFFERSIZE", "QUERYFLUSHTIME", "SIP_WARNING", "SOCK_MODE",
  "SOCK_USER", "SOCK_GROUP", "UNIX_SOCK", "UNIX_SOCK_CHILDREN",
  "UNIX_TX_TIMEOUT", "SERVER_SIGNATURE", "SERVER_HEADER",
  "USER_AGENT_HEADER", "LOADMODULE", "MPATH", "MODPARAM", "MAXBUFFER",
  "USER", "GROUP", "CHROOT", "WDIR", "MHOMED", "DISABLE_TCP",
  "TCP_ACCEPT_ALIASES", "TCP_CHILDREN", "TCP_CONNECT_TIMEOUT",
  "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME", "TCP_POLL_METHOD",
  "TCP_MAX_CONNECTIONS", "TCP_OPT_CRLF_PINGPONG", "TCP_NO_NEW_CONN_BFLAG",
  "DISABLE_TLS", "TLSLOG", "TLS_PORT_NO", "TLS_METHOD",
  "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT", "TLS_SERVER_DOMAIN",
  "TLS_CLIENT_DOMAIN", "TLS_CLIENT_DOMAIN_AVP", "SSLv23", "SSLv2", "SSLv3",
  "TLSv1", "TLS_VERIFY_CLIENT", "TLS_VERIFY_SERVER",
  "TLS_REQUIRE_CLIENT_CERTIFICATE", "TLS_CERTIFICATE", "TLS_PRIVATE_KEY",
  "TLS_CA_LIST", "TLS_CIPHERS_LIST", "ADVERTISED_ADDRESS",
  "ADVERTISED_PORT", "DISABLE_CORE", "OPEN_FD_LIMIT", "MCAST_LOOPBACK",
  "MCAST_TTL", "TOS", "DISABLE_DNS_FAILOVER", "DISABLE_DNS_BLACKLIST",
  "DST_BLACKLIST", "DISABLE_STATELESS_FWD", "DB_VERSION_TABLE",
  "DB_DEFAULT_URL", "DISABLE_503_TRANSLATION", "EQUAL", "EQUAL_T", "GT",
  "LT", "GTE", "LTE", "DIFF", "MATCH", "NOTMATCH", "COLONEQ", "PLUSEQ",
  "MINUSEQ", "SLASHEQ", "MULTEQ", "MODULOEQ", "BANDEQ", "BOREQ", "BXOREQ",
  "AND", "OR", "BRSHIFT", "BLSHIFT", "BXOR", "BAND", "BOR", "MODULO",
  "MULT", "SLASH", "MINUS", "PLUS", "BNOT", "NOT", "NUMBER", "ZERO", "ID",
  "STRING", "SCRIPTVAR", "IPV6ADDR", "COMMA", "SEMICOLON", "RPAREN",
  "LPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "AS", "DOT", "CR",
  "COLON", "ANY", "SCRIPTVARERR", "$accept", "cfg", "statements",
  "statement", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "listen_id", "proto", "port", "snumber", "phostport", "id_lst",
  "blst_elem", "blst_elem_list", "assign_stm", "module_stm", "ip", "ipv4",
  "ipv6addr", "ipv6", "tls_server_domain_stm", "$@9",
  "tls_client_domain_stm", "$@10", "$@11", "tls_server_decls",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   231,   232,   233,   233,   233,   234,   234,   235,   234,
     236,   234,   237,   234,   238,   234,   239,   234,   240,   234,
     241,   234,   242,   234,   234,   243,   243,   243,   244,   244,
     244,   244,   244,   245,   245,   246,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   248,   248,   249,   249,   250,
     250,   250,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   252,   252,
     252,   252,   252,   253,   253,   254,   255,   256,   256,   258,
     257,   260,   259,   261,   259,   262,   262,   263,   263,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   266,   266,   266,   267,   267,   267,   268,   268,   269,
     269,   269,   270,   270,   271,   271,   272,   272,   273,   273,
     274,   274,   275,   275,   275,   275,   275,   275,   276,   276,
     277,   277,   277,   277,   278,   278,   279,   279,   280,   280,
     280,   281,   281,   281,   282,   282,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   285,   285,
     285,   285,   286,   286,   287,   287,   287,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   290,   290,   290,   291,   291,
     291,   291,   291,   292,   292,   292,   293,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   295,   295,   296,   297,
     298,   298,   299,   299,   300,   300,   300,   300,   300,   300,
     300,   300,   301,   301,   302,   302,   302,   302,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     7,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
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
       4,     3,     1,     4,     4,     6,     6,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     4,
       2,     4,     3,     1,     4,     2,     4,     3,     1,     3,
       1,     3,     1,     3,     1,     4,     3,     1,     4,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     4,
       2,     3,     4,     2,     4,     4,     2,     4,     4,     2,
       8,    10,    10,     6,     8,     3,     4,     4,     2,     4,
       4,     6,     4,     6,     8,    14,     6
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,   170,   171,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,    71,     0,    73,     0,
      75,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     218,     0,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,     0,   208,     0,     0,     0,     0,
       0,     0,     1,     5,     3,     0,     9,     0,    11,     0,
      13,     0,    15,     0,    17,     0,    19,     0,    21,     0,
      23,   180,   178,   181,   179,    53,     0,     0,    35,    52,
      55,    54,    57,    56,    59,    58,    61,    60,    63,    62,
     183,    28,    29,    30,    31,     0,   374,    26,   226,     0,
      32,    38,     0,    45,   182,    25,   223,   227,   224,    27,
     185,   184,   187,   186,    65,    64,    67,    66,    68,    70,
      72,    74,    76,    81,    80,    79,    78,    85,    84,    87,
      86,    89,    88,    91,    90,    93,    92,    95,    94,    97,
      96,    99,    98,   101,   100,   103,   102,   173,   172,   175,
     174,   177,   176,   204,   203,     0,    83,    82,   106,   105,
     104,   109,   108,   107,   112,   111,   110,   115,   114,   113,
     117,   116,   119,   118,   121,   120,   123,   122,   125,   124,
     127,   126,   129,   128,   132,   130,   131,   134,   133,   136,
     135,   138,   137,   140,   139,   142,   141,   144,   143,   149,
     145,   146,   147,   148,   165,   164,   167,   166,     0,     0,
       0,   169,   168,   151,   150,   153,   152,   155,   154,   157,
     156,   159,   158,   161,   160,   163,   162,   189,   188,   191,
     190,   193,   192,   195,   194,   197,   196,   199,   198,   202,
     200,   201,   205,   207,     0,   210,   212,   211,   214,   213,
     216,   215,   276,     0,     0,   278,     0,   281,     0,     0,
     283,     0,   285,     0,   287,     0,   289,     0,   291,     0,
      37,    36,     0,     0,     0,     0,     0,    46,   373,     0,
       0,     0,     0,   233,     0,     0,     0,     0,   456,   458,
     462,     0,     0,     0,     0,     0,     0,     0,     0,   512,
       0,     0,     0,     0,     0,     0,   533,     0,   538,   540,
     542,   544,   547,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   314,   424,   315,     0,     0,     0,   417,   420,
     421,   422,     0,   272,   271,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,    44,    33,    34,
      39,    40,    42,   376,   375,     0,     0,     0,     0,     0,
     450,     0,   453,     0,     0,     0,     0,   465,     0,   492,
       0,   495,     0,   498,     0,   518,     0,   501,     0,   507,
       0,   504,     0,     0,     0,     0,   524,     0,   527,     0,
     521,     0,   530,     0,     0,   535,     0,     0,     0,     0,
       0,     0,     0,   311,   312,   313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,   319,   297,   316,   410,   317,   409,   408,     0,     0,
     551,     0,   554,     0,   557,     0,   560,     0,   563,     0,
     566,     0,   569,     0,   469,     0,   471,     0,   473,     0,
     475,     0,   484,     0,   487,     0,   490,     0,   477,     0,
     479,     0,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,     0,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,     0,   423,   418,   274,   416,   425,
     419,     0,     0,   279,     0,     0,   284,   286,   288,     0,
       0,     0,     0,     0,   229,     0,   231,     0,     0,    50,
       0,     0,     0,   449,     0,     0,   455,   457,   461,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,     0,     0,   537,   539,   541,   543,     0,
       0,   546,   328,   298,   300,   301,   302,   303,   299,   304,
     305,   308,   309,   310,     0,   358,   308,     0,   341,   306,
     307,     0,   362,   308,     0,   344,     0,   347,     0,   350,
       0,   367,     0,   354,     0,   294,     0,   412,     0,     0,
       0,     0,     0,   388,     0,   387,     0,   390,   391,     0,
     392,     0,     0,     0,   426,   413,   338,   308,     0,   308,
     309,     0,     0,     0,   428,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   561,     0,     0,     0,     0,     0,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     444,   575,     0,   406,   407,   405,     0,     0,     0,     0,
       0,     0,    41,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,     0,     0,     0,    51,     0,
     209,   451,   448,   454,   452,   459,   460,   466,   463,     0,
     493,     0,   496,   494,   499,   497,   519,   517,   502,   500,
     508,   506,   505,   503,     0,   510,   513,   514,     0,     0,
     525,   523,   528,   526,   522,   520,   531,   529,   536,   534,
     548,   545,   327,   326,   325,   356,   370,   323,   357,   355,
     324,   340,   339,   360,   321,   361,   359,   322,   343,   342,
     346,   345,   349,   348,   366,   364,   365,   363,   353,   352,
     351,   295,   411,   308,     0,   308,     0,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,   292,   293,   415,     0,     0,   336,   337,   335,   320,
     333,   334,   332,   331,   330,   329,     0,   550,   549,   553,
     552,   556,   555,   559,   558,   562,   565,   564,   568,   567,
     467,   470,   472,   474,     0,   483,     0,   486,     0,   489,
     476,   478,   480,     0,     0,     0,   579,     0,   580,     0,
     582,     0,     0,   577,     0,   576,     0,     0,     0,     0,
       0,     0,   220,   221,     0,     0,     0,     0,     0,     0,
       0,   234,   238,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,   404,   402,   401,   400,   398,   399,   397,
     395,   396,   394,   393,   414,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,   445,   275,
     277,   280,   282,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   260,   256,   257,   258,   259,   270,
     269,   262,   261,   264,   263,   266,   265,   268,   267,     0,
       0,     0,   464,   491,   509,   515,   516,   371,   369,   368,
       0,     0,   431,   433,   482,   485,   488,     0,     0,   573,
     581,     0,   583,     0,   586,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   236,   232,     0,     0,     0,     0,
     429,     0,   432,   430,     0,     0,     0,     0,   290,   243,
     239,   240,   241,   242,   253,   252,   255,   254,   245,   244,
     247,   246,   249,   248,   251,   250,     0,     0,   441,   437,
     443,     0,   570,   574,   584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   439,     0,
     435,     0,   571,   572,     0,     0,    47,   438,   434,     0,
      48,     0,     0,   585
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   241,   242,   510,   765,   243,   244,   669,   670,
      96,    97,   245,   246,   247,   248,    98,   836,    99,   845,
     517,  1062,   843,  1063,   844,   496,   196,   198,   200,   202,
     204,   206,   208,   210,   579,   739,   732,   733,   781,   782,
     766,   485,   582,   768,   897,   420,   249,   644,   769,   486,
     585,   774,   487,   488,   489,   490,   491,  1091,  1092,  1093,
    1123,   822,   492
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -825
static const yytype_int16 yypact[] =
{
    3985,  -129,   -75,   -64,   -46,   -12,     0,     9,    13,    39,
     295,   350,   373,   385,   397,    40,    42,   457,   467,   472,
     398,   430,   445,   449,   453,   465,   486,   492,   497,   498,
     517,   529,   533,   549,   551,    32,   552,    31,   558,   600,
     625,   628,   634,   643,   644,   654,   670,   713,   719,   734,
     747,   768,   771,   775,   781,   782,   786,   787,   790,   793,
     269,   395,   829,   842,   853,   861,   862,   863,   866,   868,
     869,   875,   876,   881,   895,   896,   917,   530,   532,   930,
     942,   953,   954,   955,  -825,   623,  2743,  -825,   647,   848,
     691,   856,   886,   902,  1104,  1118,  -825,  -825,  -825,  -825,
    -825,   209,   335,   337,   336,   338,   130,   152,   174,    43,
      47,   339,   357,   358,  -825,   925,  -825,   931,  -825,   932,
    -825,   939,  -825,   940,   362,   414,   439,   442,   443,   444,
     450,   451,   455,   456,   459,   462,   463,   176,   179,  -825,
    -825,   193,  -825,   943,   464,   128,   148,   183,   186,   468,
     469,   474,   475,   476,   477,   478,   188,   479,   490,   502,
     503,   504,   505,   646,   506,   507,  -149,   823,   199,   508,
     509,   510,   200,   202,   203,   204,    16,   512,   513,   514,
     515,   516,   319,  -825,   944,  -825,   947,   946,   969,   205,
     207,   522,  -825,  -129,  -825,    44,  -825,    41,  -825,    48,
    -825,    45,  -825,    26,  -825,    29,  -825,    54,  -825,    51,
    -825,  -825,  -825,  -825,  -825,  -825,   971,   973,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,   927,  -825,  -825,  -825,   938,
    -825,   958,   959,   481,  -825,  -825,  -825,  -825,  -825,  -153,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,   972,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,   963,   966,
     965,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,   967,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  3843,   380,  -825,   380,  -825,  3843,   380,
    -825,   380,  -825,  3843,  -825,  3843,  -825,  3843,  -825,   380,
    -825,  -825,   983,   974,    20,   369,   369,  -825,  -825,   151,
     984,   982,   -97,  -825,   -97,   978,    57,    63,   981,   985,
     994,    67,    69,    74,    78,    80,    83,    84,    85,   995,
     996,   997,    86,    87,    88,    89,   998,    90,   999,  1000,
    1021,  1023,  1024,  2919,  1025,  2919,    91,    93,    96,    97,
      98,    99,   101,   126,   129,   135,   140,   145,   160,   161,
     162,   163,   164,  1034,  1045,  1046,  1047,  1048,  1049,  1050,
    1052,   165,  -825,  -825,  -825,  1219,  1056,  1203,  -825,  -825,
    -825,  -825,    70,  -825,  -825,  -825,   979,  1051,  1291,  1053,
    1054,  1436,  1524,  1669,  1062,   976,  -825,  -825,  -825,  -825,
    -825,  1059,  1065,  -825,  -825,  1064,  1078,  1082,  1080,  -117,
    -825,    82,  -825,   208,  1086,  1087,   941,  -825,   184,  -825,
     210,  -825,   115,  -825,   212,  -825,   213,  -825,   215,  -825,
     523,  -825,   524,   353,  -164,   321,  -825,   216,  -825,   221,
    -825,   222,  -825,   223,  1088,  -825,   224,  1089,  1110,  1112,
    1113,   168,   655,  -825,  -825,  -825,   681,   458,   690,   663,
     671,   706,    35,   721,  2919,  2919,  3236,  3005,  -825,  3150,
     698,  1201,  -825,  -825,  -825,  -825,  -825,  -825,   -18,  3150,
    -825,    79,  -825,   525,  -825,    68,  -825,   527,  -825,   111,
    -825,   225,  -825,   227,  -825,  -106,  -825,  1122,  -825,  1131,
    -825,  1152,  -825,  1153,  -825,  1155,  -825,  1156,  -825,  1157,
    -825,  1158,  -825,  1164,  1151,  1162,  1185,  1186,  1187,  1188,
    1189,   -18,  -825,   175,  1326,  1327,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  3005,  -825,  -825,  -825,  -825,  -825,
    -825,  1196,  1198,  -825,  1199,  1202,  -825,  -825,  -825,  1195,
    1211,   -97,   -97,   399,  -825,   766,  -825,  1204,   521,  -825,
      21,  1207,  1208,  -825,  1209,  1210,  -825,  -825,  -825,  1212,
    1213,  1215,  1216,  1221,  1217,  1230,  1229,  1231,  1232,  1233,
    1234,  1255,  1257,  1258,  1259,  1268,  1279,  1280,   386,  -825,
    1281,  1282,  1285,  1286,  1288,  1289,  1292,  1293,  1295,  1301,
    1307,  1316,  -825,  1317,  1318,  -825,  -825,  -825,  -825,  1319,
    1320,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,   190,  -825,   -33,   192,  -825,  -825,
    -825,   538,  -825,   482,   195,  -825,   540,  -825,    33,  -825,
     541,  -825,   536,  -825,   411,  -825,  -141,  -825,  1757,   681,
     690,  3005,   738,  -825,  3005,  -825,   698,   992,  -825,   923,
    -825,  2919,  2919,  3381,  1392,  -825,  -825,  1377,   197,   756,
     452,   603,  -154,  1321,  -825,  1322,  1343,  1345,  1346,  1347,
     356,  1356,  1367,  1368,  -825,  1369,  1370,  1371,  1372,  1373,
    -825,  1374,  1375,  1376,   610,   613,   641,  1378,  1379,  1380,
    1383,  1384,  1385,  1389,   680,   692,  1396,  1397,  1390,  -825,
    -825,  -825,   699,  -825,  -825,  1154,  3843,  3843,  3843,  3843,
    1391,  1284,  -825,  -825,  1398,  1399,  1395,  1417,  1440,  1441,
    1442,  1443,  1444,   760,  -825,  1403,   521,  1408,  -825,  -117,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  1412,
    -825,  1413,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  1414,  -825,  -825,  -825,  1415,  1416,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  1299,  -825,  -825,  -825,
    -153,  -825,  -825,  -825,  -825,  -825,  -825,  -153,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  1559,   232,  1560,   233,  -825,   962,   234,
    3005,  3005,  3005,  3005,  3005,  3005,  3005,  3005,  3005,  3005,
    -825,  -825,  -825,  -825,  1902,  3467,  -825,  -825,  -825,  -153,
    -825,  -825,  -825,  -825,  -825,  -825,  1418,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  1422,  -825,  1423,  -825,  1424,  -825,
    -825,  -825,  -825,  1426,  1427,  1428,  -825,  1429,  -825,   -18,
    -825,  1430,   -18,  -825,   405,  -825,  1990,  2135,  2223,  2368,
    1425,  1434,  -825,  -825,    10,   739,   565,   235,   236,   239,
     240,  -825,  -825,   766,  1419,  -149,  -825,  1431,  1433,  1437,
    1438,  1445,    62,  -825,   865,   865,   865,   865,   865,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  1597,  1446,  1448,  1449,
    1421,  1452,  1461,  1462,   816,  1454,  1463,  -825,  -825,  -825,
    -825,  -825,  -825,  3843,  -825,  1468,  1469,  1474,  1476,  1480,
    1481,  1482,   426,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,   822,
    -149,  1466,  -825,  -825,  -825,  -825,  -825,  -825,   927,  -825,
     741,  1464,   114,  -825,  -825,  -825,  -825,  1470,   -18,  -825,
    -825,   -18,  -825,  1471,  -825,  2456,   777,   569,   578,   241,
     247,   298,   313,  -825,  -825,  -825,  1490,   -97,  1435,  1483,
    -825,  1492,  -825,  -825,   819,  1491,  1512,  1515,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,   -97,  1516,  3612,  3698,
    3843,   323,  -825,  -825,  -825,  1495,  1517,  1521,  1518,   970,
    1520,  1058,  2601,  1522,  1525,  1523,  1529,  1526,  -825,  1535,
    -825,  1541,  -825,  -825,  1533,  1549,  -825,  -825,  -825,  1552,
    -825,   -18,  1551,  -825
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -825,  -825,  -825,  1576,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -163,  -226,  -417,  -103,  1176,   -57,   924,  -825,
    -825,  -825,  -165,  -825,  1556,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,   759,   712,  -824,   511,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -440,    49,    64,  -825,    -8,    46,
    -427,  -449,  -825,  -424,  -729,  -825,  -672,  -825,  -562,  -418,
    -825,  -578,  -395,  -478,  -415,  -825,  -825,  -825,  -825,   705,
    -825,  -825,  -437
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -443
static const yytype_int16 yytable[] =
{
     219,   348,   350,   498,   581,   516,   581,   518,   501,   648,
     502,   784,   503,   368,   904,   589,   587,   367,   587,  1012,
     648,   507,   848,   648,   648,   648,   580,   402,   580,   583,
     404,   583,   142,   139,   910,   584,   751,   584,   586,   895,
     586,   114,   395,   116,   230,   392,   400,   700,   250,   397,
     100,   482,   408,   251,   418,   406,   771,   772,   520,   953,
     954,   482,   235,  1087,   522,   900,   484,   238,   527,   789,
     529,   649,   907,   419,   239,   531,   484,   680,   921,   533,
     785,   535,   825,   671,   537,   539,   541,   546,   548,   550,
     552,   555,   590,   667,   592,   701,   703,   594,   596,   598,
     600,   775,   602,   668,   101,   799,   949,   231,   232,   233,
     234,   775,   793,   800,   508,   102,   686,   231,   232,   233,
     234,   231,   232,   233,   234,   581,   581,   604,   767,   298,
     606,   224,   509,   103,   755,   756,   608,   587,   587,   783,
     770,   610,   231,   232,   233,   234,   612,   580,   580,   301,
     583,   583,   513,   226,  1090,  1121,   584,   584,  1055,   586,
     586,   614,   616,   618,   620,   622,   632,   104,  1056,   719,
    1057,  1058,  1059,  1060,  1061,   228,   818,   289,   235,   105,
     291,   758,   817,   238,   304,   681,   417,   307,   106,   324,
     239,   892,   107,   898,   293,   767,   905,   482,   947,   927,
     351,   359,   928,   361,   363,   365,   386,   770,   388,   674,
     211,   684,   484,   688,   690,   723,   692,   704,   108,   115,
     728,   117,   706,   708,   710,   713,   795,   235,   797,   236,
     237,   508,   238,   898,   905,   947,  1071,  1073,   849,   239,
    1075,  1077,  1138,   850,   832,   833,   140,   403,  1140,   509,
     405,   143,   511,   512,   235,  1012,   236,   237,   235,   238,
     236,   237,   240,   238,   396,   393,   239,   394,   401,   398,
     239,   399,   240,  1088,   409,   407,   240,   521,   238,   235,
     648,   236,   237,   523,   238,   239,  1081,   528,   650,   530,
     235,   239,   236,   237,   532,   238,   672,   240,   534,  1142,
     536,   673,   239,   538,   540,   542,   547,   549,   551,   553,
     556,   591,   767,   593,  1144,   767,   595,   597,   599,   601,
     379,   603,   581,   581,   770,   917,   493,   770,   494,   495,
     794,   941,   942,   955,   587,   587,   213,   220,   215,   222,
     252,   299,   300,   225,   580,   580,   605,   583,   583,   607,
     578,  1116,   578,   584,   584,   609,   586,   586,   254,   256,
     611,   302,   303,   263,  -372,   613,   227,  1035,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,   944,   720,
     615,   617,   619,   621,   623,   633,   819,   721,   229,   820,
     290,   216,   217,   292,   821,   218,   305,   306,   682,   308,
     309,   325,   326,   893,   894,   236,   899,   294,   236,   906,
     236,   948,   918,   352,   360,   265,   362,   364,   366,   387,
     212,   389,   675,   679,   685,   683,   689,   691,   786,   693,
     705,   996,   997,   998,   999,   707,   709,   711,   714,   796,
     267,   798,   847,   269,   271,   273,   899,   906,   948,  1072,
    1074,   275,   277,  1076,  1078,  1139,   279,   281,   118,   738,
     283,  1141,   919,   285,   287,   296,   648,   775,   120,   310,
     312,   578,   578,   122,   109,   314,   316,   318,   320,   322,
     327,   767,   767,   767,   767,   767,   767,   767,   767,   767,
     767,   329,   166,   770,   770,   770,   770,   770,   770,   770,
     770,   770,   770,   331,   333,   335,   337,   344,   346,   353,
     355,   357,  1143,   369,   371,   373,   375,   377,   648,   648,
     648,   648,   911,   390,   694,   696,   787,  1145,   791,   110,
     380,   183,   381,   185,  1163,   702,   482,   914,   482,   901,
    1044,   908,   912,  1046,   216,   217,   214,   221,   218,   223,
     253,   484,   111,   484,   903,   231,   232,   233,   234,   741,
     835,   746,   748,   750,   112,   754,  1069,   698,   255,   257,
    1134,   896,   699,   264,  1055,   962,   113,   124,   896,  1136,
     235,   416,   236,   237,  1056,   238,  1057,  1058,  1059,  1060,
    1061,   493,   239,   494,   495,   231,   232,   233,   234,   563,
     564,   565,   915,   874,   916,   875,   216,   217,   734,   125,
     218,   731,   737,   834,   744,   736,  1047,   743,   167,  1048,
    1014,   752,   920,   192,   126,   266,   778,   648,   127,   777,
     779,   740,   128,   740,   740,   740,   119,   740,   723,   724,
     725,   726,   727,   728,   129,   780,   121,   339,  1113,  1125,
     268,   123,  1126,   270,   272,   274,   722,   195,  1105,  -307,
    -307,   276,   278,  -307,   745,   130,   280,   282,   578,   578,
     284,   131,   747,   286,   288,   297,   132,   133,   952,   311,
     313,   648,   735,   648,   648,   315,   317,   319,   321,   323,
     328,   742,   235,   235,   236,   237,   134,   238,   238,   776,
    1147,   330,  1164,   199,   239,   239,   416,   749,   135,   184,
     240,   186,   136,   332,   334,   336,   338,   345,   347,   354,
     356,   358,   753,   370,   372,   374,   376,   378,   137,  1156,
     138,   141,  1182,   391,   695,   697,   788,   144,   792,   632,
    1064,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,   902,
     240,   909,   913,  1159,  1161,  1162,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  1070,  -389,  1129,   145,
    1135,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  1137,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
     340,   341,   342,   343,   146,   924,   926,   147,   923,   925,
     216,   217,   929,   148,   218,   777,   779,  -389,  -389,  -389,
    -389,  -389,   149,   150,  -389,  -389,  -389,   974,   950,   975,
     976,   780,   977,   151,   951,   723,   724,   725,   726,   727,
     728,   729,   730,   723,   724,   725,   726,   727,   728,   152,
     896,   723,   724,   725,   726,   727,   728,  1089,   978,   197,
     979,   723,   724,   725,   726,   727,   728,   729,   730,   201,
     723,   724,   725,   726,   727,   728,   729,   730,   723,   724,
     725,   726,   727,   728,   729,   730,   723,   724,   725,   726,
     727,   728,   153,  1065,  1066,  1067,  1068,   987,   154,   988,
     203,   723,   724,   725,   726,   727,   728,   497,   837,   989,
     499,   990,   500,   155,   837,   896,   994,   205,   995,   838,
     504,   839,   840,   841,   842,   838,   156,   839,   840,   841,
     842,  1130,  1131,  1132,  1133,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,   157,   216,   217,
     158,  -389,   218,  -389,   159,  1118,  -389,  -389,   633,  -389,
     160,   161,  -389,  -306,  -306,   162,   163,  -306,  -389,   164,
     837,   646,   165,   426,   427,   428,   429,   430,   431,   432,
     433,   838,  1011,   839,   840,   841,   842,  1119,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   168,   454,
    -440,  -440,  1169,   455,   456,   457,   458,   459,   460,   461,
     462,   169,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   170,  1101,   235,  1102,  1151,   349,  1152,   238,
     171,   172,   173,   687,  1115,   174,   239,   175,   176,   473,
     474,   475,   476,   477,   177,   178,   478,   479,   480,   646,
     179,   426,   427,   428,   429,   430,   431,   432,   433,   935,
     936,   937,   938,   939,   180,   181,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   182,   454,  -436,  -436,
    1171,   455,   456,   457,   458,   459,   460,   461,   462,   187,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     207,   188,   930,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   189,   190,   191,   209,   258,   473,   474,   475,
     476,   477,   259,   260,   478,   479,   480,   940,   216,   217,
     261,   262,   218,   412,   238,   382,   482,   295,   383,   384,
     678,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   484,   723,   724,   725,   726,   727,   728,   729,   730,
     385,  1023,   410,   481,   411,   482,   414,   415,   483,   421,
     423,   422,  -440,   424,   505,   425,   515,   514,   506,   519,
     484,   524,   660,   651,   646,   525,   426,   427,   428,   429,
     430,   431,   432,   433,   526,   543,   544,   545,   554,   557,
     558,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   559,   454,   560,   561,   588,   455,   456,   457,   458,
     459,   460,   461,   462,   624,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   625,   626,   627,   628,   629,
     630,   481,   631,   482,   645,   652,   483,   654,   655,   659,
    -436,   663,   473,   474,   475,   476,   477,   661,   484,   478,
     479,   480,   646,   662,   426,   427,   428,   429,   430,   431,
     432,   433,   664,   665,   666,   676,   677,   712,   715,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   716,
     454,   717,   718,   801,   455,   456,   457,   458,   459,   460,
     461,   462,   802,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   930,   931,   932,   933,   934,   935,   936,
     937,   938,   939,   803,   804,   810,   805,   806,   807,   808,
     473,   474,   475,   476,   477,   809,   811,   478,   479,   480,
     634,   723,   724,   725,   726,   727,   728,   729,   730,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   634,   812,
     813,   814,   815,   816,   823,   824,   830,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   481,   826,   482,   827,
     828,   483,   831,   829,   846,   647,   851,   852,   853,   854,
     945,   855,   856,   484,   857,   858,   860,   646,   859,   426,
     427,   428,   429,   430,   431,   432,   433,   861,   862,   946,
     863,   864,   865,   866,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   867,   454,   868,   869,   870,   455,
     456,   457,   458,   459,   460,   461,   462,   871,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   872,   873,
     876,   877,   878,   879,   481,  1022,   482,   880,   881,   483,
    1001,   882,   883,   653,   884,   473,   474,   475,   476,   477,
     885,   484,   478,   479,   480,   646,   886,   426,   427,   428,
     429,   430,   431,   432,   433,   887,   888,   889,   890,   891,
     956,   957,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   958,   454,   959,   960,   961,   455,   456,   457,
     458,   459,   460,   461,   462,   963,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   964,   965,   966,   967,
     968,   969,   970,   971,   972,   973,  1005,   980,   981,   982,
     983,   984,   985,   473,   474,   475,   476,   477,   986,   993,
     478,   479,   480,   991,   992,  1000,  1004,  1002,  1003,  1006,
    1007,  1008,  1009,  1010,  1013,  1015,  1017,  1018,  1019,  1020,
    1021,   895,   903,  1037,  1038,  1039,  1080,  1090,  1097,  1036,
    1040,  1041,  1042,  1043,  1045,  1054,  1053,  1106,  1107,   481,
    1082,   482,  1083,  1108,   483,  1109,  1084,  1085,   656,  1110,
    1111,  1112,   194,  1148,  1086,  1094,   484,  1095,  1096,  1098,
     646,  1103,   426,   427,   428,   429,   430,   431,   432,   433,
    1099,  1100,  1104,  1117,  1124,  1127,  1120,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,  1146,   454,  1165,
    1153,  1149,   455,   456,   457,   458,   459,   460,   461,   462,
    1150,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,  1154,  1155,  1157,  1166,  1167,  1168,   481,  1170,   482,
    1174,  1172,   483,  1175,  1173,  1176,   657,  1179,   473,   474,
     475,   476,   477,  1177,   484,   478,   479,   480,   646,  1178,
     426,   427,   428,   429,   430,   431,   432,   433,  1180,  1181,
    1183,   790,  1079,  1016,  1114,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   413,   454,  1122,     0,     0,
     455,   456,   457,   458,   459,   460,   461,   462,     0,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   473,   474,   475,   476,
     477,     0,     0,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   481,     0,   482,     0,     0,   483,     0,     0,
       0,   658,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,     0,   646,     0,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,     0,     0,     0,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
       0,   454,     0,     0,     0,   455,   456,   457,   458,   459,
     460,   461,   462,     0,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,     0,     0,     0,     0,     0,     0,
     481,     0,   482,     0,     0,   483,     0,     0,     0,   922,
       0,   473,   474,   475,   476,   477,     0,   484,   478,   479,
     480,   646,     0,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,     0,     0,     0,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,     0,   454,
       0,     0,     0,   455,   456,   457,   458,   459,   460,   461,
     462,     0,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   475,   476,   477,     0,     0,   478,   479,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,   482,     0,     0,
     483,     0,     0,     0,  1034,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,   646,     0,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
       0,     0,     0,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,     0,   454,     0,     0,     0,   455,   456,
     457,   458,   459,   460,   461,   462,     0,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,     0,     0,     0,
       0,     0,     0,   481,     0,   482,     0,     0,   483,     0,
       0,     0,  1049,     0,   473,   474,   475,   476,   477,     0,
     484,   478,   479,   480,   646,     0,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,     0,     0,
       0,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,     0,   454,     0,     0,     0,   455,   456,   457,   458,
     459,   460,   461,   462,     0,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,   474,   475,   476,   477,     0,     0,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   481,     0,
     482,     0,     0,   483,     0,     0,     0,  1050,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,   646,
       0,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,     0,     0,     0,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,     0,   454,     0,     0,
       0,   455,   456,   457,   458,   459,   460,   461,   462,     0,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
       0,     0,     0,     0,     0,     0,   481,     0,   482,     0,
       0,   483,     0,     0,     0,  1051,     0,   473,   474,   475,
     476,   477,     0,   484,   478,   479,   480,   646,     0,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,     0,     0,     0,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,     0,   454,     0,     0,     0,   455,
     456,   457,   458,   459,   460,   461,   462,     0,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,   474,   475,   476,   477,
       0,     0,   478,   479,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   481,     0,   482,     0,     0,   483,     0,     0,     0,
    1052,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,   646,     0,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,     0,     0,     0,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,     0,
     454,     0,     0,     0,   455,   456,   457,   458,   459,   460,
     461,   462,     0,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,     0,     0,     0,     0,     0,     0,   481,
       0,   482,     0,     0,   483,     0,     0,     0,  1128,     0,
     473,   474,   475,   476,   477,     0,   484,   478,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -2,   193,     0,     0,     0,     0,     0,
       0,     0,     0,    -8,   -10,   -12,   -14,   -16,   -18,   -20,
     -22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   481,     0,   482,     0,     0,   483,
       0,     0,     0,  -442,     0,     0,     0,     2,     3,     0,
       0,   484,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,     0,     0,     0,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,     0,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
      84,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,   473,   474,
     475,   476,   477,     0,     0,   478,   479,   480,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
       0,     0,     0,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,     0,     0,     0,     0,     0,     0,     0,   456,
     457,   458,   459,   460,   461,   462,     0,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   562,   563,   564,
     565,   759,   567,   760,   569,   570,   571,   572,   573,     0,
       0,     0,     0,     0,   473,   474,   475,   476,   477,     0,
       0,   478,   479,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   217,     0,   574,
     218,     0,   481,     0,   482,     0,     0,     0,     0,   575,
     576,     0,   577,     0,     0,     0,     0,     0,     0,   484,
       0,     0,     0,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,     0,     0,     0,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,     0,   454,
       0,     0,     0,   455,   456,   457,   458,   459,   460,   461,
     462,     0,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   216,   217,   761,     0,   218,     0,   762,   763,
     482,     0,     0,     0,     0,   764,     0,     0,     0,   473,
     474,   475,   476,   477,     0,   484,   478,   479,   480,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,     0,     0,     0,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,     0,   454,     0,     0,     0,   455,
     456,   457,   458,   459,   460,   461,   462,     0,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,   474,   475,   476,   477,
       0,     0,   478,   479,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   771,   772,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,     0,   482,     0,     0,   483,     0,
       0,   773,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,     0,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,     0,     0,     0,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,     0,
     454,     0,     0,     0,   455,   456,   457,   458,   459,   460,
     461,   462,     0,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,     0,     0,     0,     0,     0,     0,   481,
       0,   482,     0,     0,   483,     0,     0,     0,   757,     0,
     473,   474,   475,   476,   477,     0,   484,   478,   479,   480,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,     0,     0,     0,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,     0,   454,     0,     0,     0,
     455,   456,   457,   458,   459,   460,   461,   462,     0,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   473,   474,   475,   476,
     477,     0,     0,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   481,     0,   482,     0,     0,   483,
       0,     0,     0,   943,     0,     0,     0,     0,     0,     0,
       0,   484,     0,     0,     0,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,     0,     0,     0,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
       0,   454,     0,     0,  1158,   455,   456,   457,   458,   459,
     460,   461,   462,     0,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,     0,     0,     0,     0,     0,     0,
     481,     0,   482,     0,     0,   483,     0,     0,   773,     0,
       0,   473,   474,   475,   476,   477,     0,   484,   478,   479,
     480,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,     0,     0,     0,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,     0,   454,     0,     0,
    1160,   455,   456,   457,   458,   459,   460,   461,   462,     0,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   473,   474,   475,
     476,   477,     0,     0,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,   482,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,     0,     0,
       0,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,     0,   454,     0,     0,     0,   455,   456,   457,   458,
     459,   460,   461,   462,     0,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,     0,     0,     0,     0,     0,
       0,   481,     0,   482,     0,     0,   483,     0,     0,     0,
       0,     0,   473,   474,   475,   476,   477,     0,   484,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,    -8,   -10,   -12,   -14,   -16,
     -18,   -20,   -22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,     0,   482,     0,
       0,   483,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,   484,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84
};

static const yytype_int16 yycheck[] =
{
     103,   166,   167,   398,   453,   422,   455,   424,   403,   487,
     405,   589,   407,   176,   743,   455,   453,     1,   455,   843,
     498,     1,     1,   501,   502,   503,   453,     1,   455,   453,
       1,   455,     1,     1,     1,   453,     1,   455,   453,    72,
     455,     1,     1,     1,     1,     1,     1,   211,     1,     1,
     179,   215,     1,   110,   207,     1,   197,   198,     1,   213,
     214,   215,   211,     1,     1,   737,   230,   216,     1,     1,
       1,     1,   744,   226,   223,     1,   230,   526,   219,     1,
       1,     1,   644,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,   210,     1,   544,   545,     1,     1,     1,
       1,   579,     1,   220,   179,   211,   778,    74,    75,    76,
      77,   589,     1,   219,   211,   179,     1,    74,    75,    76,
      77,    74,    75,    76,    77,   574,   575,     1,   577,     1,
       1,     1,   229,   179,   574,   575,     1,   574,   575,   588,
     577,     1,    74,    75,    76,    77,     1,   574,   575,     1,
     574,   575,     1,     1,    40,    41,   574,   575,   148,   574,
     575,     1,     1,     1,     1,     1,     1,   179,   158,     1,
     160,   161,   162,   163,   164,     1,     1,     1,   211,   179,
       1,   576,   631,   216,     1,     1,   243,     1,   179,     1,
     223,     1,   179,     1,     1,   644,     1,   215,     1,   761,
       1,     1,   764,     1,     1,     1,     1,   644,     1,     1,
       1,     1,   230,     1,     1,   180,     1,     1,   179,   179,
     185,   179,     1,     1,     1,     1,     1,   211,     1,   213,
     214,   211,   216,     1,     1,     1,     1,     1,   217,   223,
       1,     1,     1,   222,   661,   662,   214,   221,     1,   229,
     221,   220,   415,   416,   211,  1079,   213,   214,   211,   216,
     213,   214,   229,   216,   223,   221,   223,   223,   223,   221,
     223,   223,   229,   211,   223,   221,   229,   220,   216,   211,
     758,   213,   214,   220,   216,   223,  1015,   220,   218,   220,
     211,   223,   213,   214,   220,   216,   214,   229,   220,     1,
     220,   219,   223,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   761,   220,     1,   764,   220,   220,   220,   220,
       1,   220,   771,   772,   761,   752,   211,   764,   213,   214,
     219,   771,   772,   782,   771,   772,     1,     1,     1,     1,
       1,   213,   214,   213,   771,   772,   220,   771,   772,   220,
     453,  1080,   455,   771,   772,   220,   771,   772,     1,     1,
     220,   213,   214,     1,   213,   220,   214,   945,   930,   931,
     932,   933,   934,   935,   936,   937,   938,   939,   773,   211,
     220,   220,   220,   220,   220,   220,   211,   219,   214,   214,
     214,   207,   208,   214,   219,   211,   213,   214,   214,   213,
     214,   213,   214,   213,   214,   213,   214,   214,   213,   214,
     213,   214,     1,   214,   214,     1,   214,   214,   214,   214,
     211,   214,   214,   526,   214,   528,   214,   214,   591,   214,
     214,   826,   827,   828,   829,   214,   214,   214,   214,   214,
       1,   214,   668,     1,     1,     1,   214,   214,   214,   214,
     214,     1,     1,   214,   214,   214,     1,     1,     1,     1,
       1,   214,    51,     1,     1,     1,   944,   945,     1,     1,
       1,   574,   575,     1,   179,     1,     1,     1,     1,     1,
       1,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,     1,   223,   930,   931,   932,   933,   934,   935,   936,
     937,   938,   939,     1,     1,     1,     1,     1,     1,     1,
       1,     1,   214,     1,     1,     1,     1,     1,   996,   997,
     998,   999,   748,     1,     1,     1,     1,   214,     1,   179,
     211,     1,   213,     1,   211,   214,   215,     1,   215,     1,
     989,     1,     1,   992,   207,   208,   211,   211,   211,   211,
     211,   230,   179,   230,    72,    74,    75,    76,    77,   567,
     663,   569,   570,   571,   179,   573,     1,   214,   211,   211,
       1,   736,   219,   211,   148,   219,   179,   179,   743,     1,
     211,   225,   213,   214,   158,   216,   160,   161,   162,   163,
     164,   211,   223,   213,   214,    74,    75,    76,    77,    63,
      64,    65,    66,   217,    68,   219,   207,   208,   562,   179,
     211,   562,   566,   214,   568,   566,   211,   568,   223,   214,
     846,   572,   211,     0,   179,   211,   580,  1105,   179,   580,
     581,   567,   179,   569,   570,   571,   179,   573,   180,   181,
     182,   183,   184,   185,   179,   581,   179,     1,   222,  1098,
     211,   179,  1101,   211,   211,   211,     1,    10,  1053,   207,
     208,   211,   211,   211,     1,   179,   211,   211,   771,   772,
     211,   179,     1,   211,   211,   211,   179,   179,   781,   211,
     211,  1159,     1,  1161,  1162,   211,   211,   211,   211,   211,
     211,     1,   211,   211,   213,   214,   179,   216,   216,     1,
    1117,   211,  1151,    12,   223,   223,   225,     1,   179,   179,
     229,   179,   179,   211,   211,   211,   211,   211,   211,   211,
     211,   211,     1,   211,   211,   211,   211,   211,   179,  1146,
     179,   179,  1181,   211,   211,   211,   211,   179,   211,     1,
       1,     3,     4,     5,     6,     7,     8,     9,    10,   211,
     229,   211,   211,  1148,  1149,  1150,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   211,    39,     1,   179,
     211,    43,    44,    45,    46,    47,    48,    49,    50,   211,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     154,   155,   156,   157,   179,   759,   760,   179,   759,   760,
     207,   208,   766,   179,   211,   766,   767,    79,    80,    81,
      82,    83,   179,   179,    86,    87,    88,   217,    72,   219,
     217,   767,   219,   179,    78,   180,   181,   182,   183,   184,
     185,   186,   187,   180,   181,   182,   183,   184,   185,   179,
    1015,   180,   181,   182,   183,   184,   185,  1022,   217,    11,
     219,   180,   181,   182,   183,   184,   185,   186,   187,    13,
     180,   181,   182,   183,   184,   185,   186,   187,   180,   181,
     182,   183,   184,   185,   186,   187,   180,   181,   182,   183,
     184,   185,   179,   154,   155,   156,   157,   217,   179,   219,
      14,   180,   181,   182,   183,   184,   185,   396,   148,   217,
     399,   219,   401,   179,   148,  1080,   217,    15,   219,   159,
     409,   161,   162,   163,   164,   159,   179,   161,   162,   163,
     164,   154,   155,   156,   157,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   179,   207,   208,
     179,   213,   211,   215,   179,   214,   218,   219,   220,   221,
     179,   179,   224,   207,   208,   179,   179,   211,   230,   179,
     148,     1,   179,     3,     4,     5,     6,     7,     8,     9,
      10,   159,   222,   161,   162,   163,   164,  1090,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   179,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   179,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   179,   217,   211,   219,   217,   214,   219,   216,
     179,   179,   179,   532,   222,   179,   223,   179,   179,    79,
      80,    81,    82,    83,   179,   179,    86,    87,    88,     1,
     179,     3,     4,     5,     6,     7,     8,     9,    10,   204,
     205,   206,   207,   208,   179,   179,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   179,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   179,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      16,   179,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   179,   179,   179,    17,   211,    79,    80,    81,
      82,    83,   211,   211,    86,    87,    88,   224,   207,   208,
     211,   211,   211,   226,   216,   211,   215,   214,   211,   213,
     219,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   230,   180,   181,   182,   183,   184,   185,   186,   187,
     211,   219,   211,   213,   211,   215,   228,   228,   218,   217,
     224,   228,   222,   228,   211,   228,   214,   213,   224,   221,
     230,   220,   226,   224,     1,   220,     3,     4,     5,     6,
       7,     8,     9,    10,   220,   220,   220,   220,   220,   220,
     220,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   220,    39,   220,   220,   220,    43,    44,    45,    46,
      47,    48,    49,    50,   220,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   220,   220,   220,   220,   220,
     220,   213,   220,   215,   218,   224,   218,   224,   224,   217,
     222,   217,    79,    80,    81,    82,    83,   228,   230,    86,
      87,    88,     1,   228,     3,     4,     5,     6,     7,     8,
       9,    10,   224,   221,   224,   219,   219,   219,   219,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   219,
      39,   219,   219,   211,    43,    44,    45,    46,    47,    48,
      49,    50,   211,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   211,   211,   214,   211,   211,   211,   211,
      79,    80,    81,    82,    83,   211,   214,    86,    87,    88,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   179,   214,
     214,   214,   214,   214,    78,    78,   211,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   213,   221,   215,   221,
     221,   218,   211,   221,   220,   222,   219,   219,   219,   219,
      38,   219,   219,   230,   219,   219,   219,     1,   217,     3,
       4,     5,     6,     7,     8,     9,    10,   217,   219,    72,
     219,   219,   219,   219,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,   219,    39,   219,   219,   219,    43,
      44,    45,    46,    47,    48,    49,    50,   219,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   219,   219,
     219,   219,   217,   217,   213,   206,   215,   219,   219,   218,
     226,   219,   219,   222,   219,    79,    80,    81,    82,    83,
     219,   230,    86,    87,    88,     1,   219,     3,     4,     5,
       6,     7,     8,     9,    10,   219,   219,   219,   219,   219,
     219,   219,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   219,    39,   219,   219,   219,    43,    44,    45,
      46,    47,    48,    49,    50,   219,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   179,   219,   219,   219,
     217,   217,   217,    79,    80,    81,    82,    83,   219,   219,
      86,    87,    88,   217,   217,   224,   221,   219,   219,   179,
     179,   179,   179,   179,   221,   217,   214,   214,   214,   214,
     214,    72,    72,   211,   211,   211,   217,    40,   217,   221,
     214,   214,   214,   214,   214,   211,   221,   179,   179,   213,
     219,   215,   219,   179,   218,   179,   219,   219,   222,   179,
     179,   179,    86,   228,   219,   219,   230,   219,   219,   217,
       1,   217,     3,     4,     5,     6,     7,     8,     9,    10,
     219,   219,   219,   217,   214,   214,   222,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,   217,    39,   214,
     219,   228,    43,    44,    45,    46,    47,    48,    49,    50,
     228,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   219,   217,   217,   217,   214,   218,   213,   218,   215,
     217,   219,   218,   214,   219,   219,   222,   214,    79,    80,
      81,    82,    83,   218,   230,    86,    87,    88,     1,   218,
       3,     4,     5,     6,     7,     8,     9,    10,   219,   217,
     219,   595,  1013,   849,  1062,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,   239,    39,  1092,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,   215,    -1,    -1,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,   215,    -1,    -1,   218,    -1,    -1,    -1,   222,
      -1,    79,    80,    81,    82,    83,    -1,   230,    86,    87,
      88,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,   215,    -1,    -1,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,   215,    -1,    -1,   218,    -1,
      -1,    -1,   222,    -1,    79,    80,    81,    82,    83,    -1,
     230,    86,    87,    88,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
     215,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,   215,    -1,
      -1,   218,    -1,    -1,    -1,   222,    -1,    79,    80,    81,
      82,    83,    -1,   230,    86,    87,    88,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,   215,    -1,    -1,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,   215,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,
      79,    80,    81,    82,    83,    -1,   230,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,   215,    -1,    -1,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    84,    85,    -1,
      -1,   230,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
     227,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   208,    -1,   210,
     211,    -1,   213,    -1,   215,    -1,    -1,    -1,    -1,   220,
     221,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   207,   208,   209,    -1,   211,    -1,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    79,
      80,    81,    82,    83,    -1,   230,    86,    87,    88,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,   215,    -1,    -1,   218,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,   215,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,
      79,    80,    81,    82,    83,    -1,   230,    86,    87,    88,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,   215,    -1,    -1,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,   215,    -1,    -1,   218,    -1,    -1,   221,    -1,
      -1,    79,    80,    81,    82,    83,    -1,   230,    86,    87,
      88,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      82,    83,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,   215,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,   215,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    79,    80,    81,    82,    83,    -1,   230,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,   215,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,   230,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    84,    85,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   227,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   251,   252,   257,   259,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,     1,   179,     1,   179,     1,   179,
       1,   179,     1,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,     1,
     214,   179,     1,   220,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   223,   223,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,     1,   179,     1,   179,   179,   179,   179,
     179,   179,     0,     1,   234,    10,   267,    11,   268,    12,
     269,    13,   270,    14,   271,    15,   272,    16,   273,    17,
     274,     1,   211,     1,   211,     1,   207,   208,   211,   246,
       1,   211,     1,   211,     1,   213,     1,   214,     1,   214,
       1,    74,    75,    76,    77,   211,   213,   214,   216,   223,
     229,   243,   244,   247,   248,   253,   254,   255,   256,   287,
       1,   248,     1,   211,     1,   211,     1,   211,   211,   211,
     211,   211,   211,     1,   211,     1,   211,     1,   211,     1,
     211,     1,   211,     1,   211,     1,   211,     1,   211,     1,
     211,     1,   211,     1,   211,     1,   211,     1,   211,     1,
     214,     1,   214,     1,   214,   214,     1,   211,     1,   213,
     214,     1,   213,   214,     1,   213,   214,     1,   213,   214,
       1,   211,     1,   211,     1,   211,     1,   211,     1,   211,
       1,   211,     1,   211,     1,   213,   214,     1,   211,     1,
     211,     1,   211,     1,   211,     1,   211,     1,   211,     1,
     154,   155,   156,   157,     1,   211,     1,   211,   253,   214,
     253,     1,   214,     1,   211,     1,   211,     1,   211,     1,
     214,     1,   214,     1,   214,     1,   214,     1,   243,     1,
     211,     1,   211,     1,   211,     1,   211,     1,   211,     1,
     211,   213,   211,   211,   213,   211,     1,   214,     1,   214,
       1,   211,     1,   221,   223,     1,   223,     1,   221,   223,
       1,   223,     1,   221,     1,   221,     1,   221,     1,   223,
     211,   211,   226,   255,   228,   228,   225,   248,   207,   226,
     286,   217,   228,   224,   228,   228,     3,     4,     5,     6,
       7,     8,     9,    10,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    39,    43,    44,    45,    46,    47,
      48,    49,    50,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    79,    80,    81,    82,    83,    86,    87,
      88,   213,   215,   218,   230,   282,   290,   293,   294,   295,
     296,   297,   303,   211,   213,   214,   266,   266,   293,   266,
     266,   293,   293,   293,   266,   211,   224,     1,   211,   229,
     245,   243,   243,     1,   213,   214,   245,   261,   245,   221,
       1,   220,     1,   220,   220,   220,   220,     1,   220,     1,
     220,     1,   220,     1,   220,     1,   220,     1,   220,     1,
     220,     1,   220,   220,   220,   220,     1,   220,     1,   220,
       1,   220,     1,   220,   220,     1,   220,   220,   220,   220,
     220,   220,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   210,   220,   221,   223,   246,   275,
     281,   282,   283,   284,   290,   291,   295,   303,   220,   275,
       1,   220,     1,   220,     1,   220,     1,   220,     1,   220,
       1,   220,     1,   220,     1,   220,     1,   220,     1,   220,
       1,   220,     1,   220,     1,   220,     1,   220,     1,   220,
       1,   220,     1,   220,   220,   220,   220,   220,   220,   220,
     220,   220,     1,   220,   179,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   288,   218,     1,   222,   294,     1,
     218,   224,   224,   222,   224,   224,   222,   222,   222,   217,
     226,   228,   228,   217,   224,   221,   224,   210,   220,   249,
     250,     1,   214,   219,     1,   214,   219,   219,   219,   246,
     282,     1,   214,   246,     1,   214,     1,   266,     1,   214,
       1,   214,     1,   214,     1,   211,     1,   211,   214,   219,
     211,   282,   214,   282,     1,   214,     1,   214,     1,   214,
       1,   214,   219,     1,   214,   219,   219,   219,   219,     1,
     211,   219,     1,   180,   181,   182,   183,   184,   185,   186,
     187,   276,   277,   278,   280,     1,   276,   280,     1,   276,
     277,   279,     1,   276,   280,     1,   279,     1,   279,     1,
     279,     1,   276,     1,   279,   275,   275,   222,   293,    66,
      68,   209,   213,   214,   220,   246,   281,   282,   284,   289,
     303,   197,   198,   221,   292,   294,     1,   276,   280,   276,
     277,   279,   280,   282,   292,     1,   243,     1,   211,     1,
     247,     1,   211,     1,   219,     1,   214,     1,   214,   211,
     219,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     214,   214,   214,   214,   214,   214,   214,   282,     1,   211,
     214,   219,   302,    78,    78,   289,   221,   221,   221,   221,
     211,   211,   245,   245,   214,   246,   258,   148,   159,   161,
     162,   163,   164,   263,   265,   260,   220,   244,     1,   217,
     222,   219,   219,   219,   219,   219,   219,   219,   219,   217,
     219,   217,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   217,   219,   219,   219,   217,   217,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,     1,   213,   214,    72,   253,   285,     1,   214,
     287,     1,   211,    72,   285,     1,   214,   287,     1,   211,
       1,   244,     1,   211,     1,    66,    68,   281,     1,    51,
     211,   219,   222,   276,   280,   276,   280,   289,   289,   280,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     224,   275,   275,   222,   293,    38,    72,     1,   214,   287,
      72,    78,   246,   213,   214,   282,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   217,   219,   217,   219,   217,   219,
     219,   219,   219,   217,   217,   217,   219,   217,   219,   217,
     219,   217,   217,   219,   217,   219,   293,   293,   293,   293,
     224,   226,   219,   219,   221,   179,   179,   179,   179,   179,
     179,   222,   265,   221,   244,   217,   249,   214,   214,   214,
     214,   214,   206,   219,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   222,   292,   221,   211,   211,   211,
     214,   214,   214,   214,   282,   214,   282,   211,   214,   222,
     222,   222,   222,   221,   211,   148,   158,   160,   161,   162,
     163,   164,   262,   264,     1,   154,   155,   156,   157,     1,
     211,     1,   214,     1,   214,     1,   214,     1,   214,   263,
     217,   285,   219,   219,   219,   219,   219,     1,   211,   253,
      40,   298,   299,   300,   219,   219,   219,   217,   217,   219,
     219,   217,   219,   217,   219,   293,   179,   179,   179,   179,
     179,   179,   179,   222,   264,   222,   285,   217,   214,   246,
     222,    41,   300,   301,   214,   282,   282,   214,   222,     1,
     154,   155,   156,   157,     1,   211,     1,   211,     1,   214,
       1,   214,     1,   214,     1,   214,   217,   245,   228,   228,
     228,   217,   219,   219,   219,   217,   245,   217,    42,   293,
      42,   293,   293,   211,   282,   214,   217,   214,   218,    42,
     218,    42,   219,   219,   217,   214,   219,   218,   218,   214,
     219,   217,   282,   219
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
#line 463 "cfg.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 464 "cfg.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 465 "cfg.y"
    { yyerror(""); YYABORT;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 470 "cfg.y"
    {rt=REQUEST_ROUTE;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 471 "cfg.y"
    {rt=FAILURE_ROUTE;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 472 "cfg.y"
    {rt=ONREPLY_ROUTE;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 473 "cfg.y"
    {rt=BRANCH_ROUTE;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 474 "cfg.y"
    {rt=ERROR_ROUTE;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 475 "cfg.y"
    {rt=LOCAL_ROUTE;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 476 "cfg.y"
    {rt=STARTUP_ROUTE;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 477 "cfg.y"
    {rt=TIMER_ROUTE;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 482 "cfg.y"
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
#line 495 "cfg.y"
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
#line 502 "cfg.y"
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
#line 515 "cfg.y"
    { (yyval.intval)=PROTO_UDP; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 516 "cfg.y"
    { (yyval.intval)=PROTO_TCP; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 517 "cfg.y"
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
#line 525 "cfg.y"
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
#line 532 "cfg.y"
    { (yyval.intval)=0; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 535 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 536 "cfg.y"
    { (yyval.intval)=0; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 539 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 540 "cfg.y"
    { (yyval.intval)=(yyvsp[(2) - (2)].intval); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 541 "cfg.y"
    { (yyval.intval)=-(yyvsp[(2) - (2)].intval); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 545 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (1)].strval), 0, 0); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 546 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (3)].strval), 0, (yyvsp[(3) - (3)].intval)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 547 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (3)].strval), (yyvsp[(1) - (3)].intval), 0); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 548 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (5)].strval), (yyvsp[(1) - (5)].intval), (yyvsp[(5) - (5)].intval));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 549 "cfg.y"
    { set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (3)].sockid), (yyvsp[(3) - (3)].strval), 5060); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 550 "cfg.y"
    { set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (5)].sockid), (yyvsp[(3) - (5)].strval), (yyvsp[(5) - (5)].intval)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 551 "cfg.y"
    { (yyval.sockid)=0; yyerror(" port number expected"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 554 "cfg.y"
    {  (yyval.sockid)=(yyvsp[(1) - (1)].sockid) ; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 555 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (2)].sockid); (yyval.sockid)->next=(yyvsp[(2) - (2)].sockid); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 559 "cfg.y"
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
#line 566 "cfg.y"
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
#line 576 "cfg.y"
    {;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 577 "cfg.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 578 "cfg.y"
    { yyerror("bad black list element");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 582 "cfg.y"
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
#line 589 "cfg.y"
    { yyerror("number  expected"); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 590 "cfg.y"
    { dont_fork= ! (yyvsp[(3) - (3)].intval); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 591 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 592 "cfg.y"
    { if (!config_check) log_stderr=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 593 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 594 "cfg.y"
    {
					if ( (i_tmp=str2facility((yyvsp[(3) - (3)].strval)))==-1)
						yyerror("bad facility (see syslog(3) man page)");
					if (!config_check)
						log_facility=i_tmp;
									;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 600 "cfg.y"
    { yyerror("ID expected"); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 601 "cfg.y"
    { log_name=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 602 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 603 "cfg.y"
    { 
/*				if ($3!=0 && $3[0]!=0)
					if ( add_avp_galias_str($3)!=0 )
						yyerror("invalid AVP aliases");;*/
				yyerror("AVP_ALIASES shouldn't be used anymore\n");
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 609 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 610 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_DNS:0; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 611 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 612 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_REV_DNS:0; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 613 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 614 "cfg.y"
    { dns_try_ipv6=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 615 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 616 "cfg.y"
    { dns_retr_time=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 617 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 618 "cfg.y"
    { dns_retr_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 619 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 620 "cfg.y"
    { dns_servers_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 621 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 622 "cfg.y"
    { dns_search_list=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 623 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 624 "cfg.y"
    { port_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 625 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 626 "cfg.y"
    { max_while_loops=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 627 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 628 "cfg.y"
    { maxbuffer=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 629 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 630 "cfg.y"
    { children_no=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 631 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 632 "cfg.y"
    { check_via=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 633 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 634 "cfg.y"
    { memlog=(yyvsp[(3) - (3)].intval); memdump=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 635 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 636 "cfg.y"
    { memdump=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 637 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 638 "cfg.y"
    { execmsgthreshold=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 639 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 640 "cfg.y"
    { execdnsthreshold=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 641 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 642 "cfg.y"
    { tcpthreshold=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 643 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 644 "cfg.y"
    { query_buffer_size=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 645 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 646 "cfg.y"
    { query_flush_time=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 647 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 648 "cfg.y"
    { sip_warning=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 649 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 650 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 651 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 652 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 653 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 654 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 655 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 656 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 657 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 658 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 659 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 660 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 661 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 662 "cfg.y"
    { mhomed=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 663 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 664 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 671 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 672 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_accept_aliases=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 679 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 680 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_children_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 687 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 688 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_connect_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 695 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 696 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 703 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 704 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_con_lifetime=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 711 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 712 "cfg.y"
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

  case 131:

/* Line 1455 of yacc.c  */
#line 726 "cfg.y"
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

  case 132:

/* Line 1455 of yacc.c  */
#line 740 "cfg.y"
    { yyerror("poll method name expected"); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 741 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_max_connections=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 748 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 749 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_crlf_pingpong=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 756 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 757 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_no_new_conn_bflag=(yyvsp[(3) - (3)].intval);
				if (!flag_in_range( (flag_t)tcp_no_new_conn_bflag ) )
					yyerror("invalid TCP no_new_conn Branch Flag");
				flag_idx2mask( &tcp_no_new_conn_bflag );
			#else
				warn("tcp support not compiled in");
			#endif
		;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 767 "cfg.y"
    { yyerror("number value expected"); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 768 "cfg.y"
    {
									#ifdef USE_TLS
										tls_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 775 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 776 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_log=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 783 "cfg.y"
    { yyerror("int value expected"); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 784 "cfg.y"
    {
									#ifdef USE_TLS
										tls_port_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 791 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 792 "cfg.y"
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

  case 146:

/* Line 1455 of yacc.c  */
#line 802 "cfg.y"
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

  case 147:

/* Line 1455 of yacc.c  */
#line 812 "cfg.y"
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

  case 148:

/* Line 1455 of yacc.c  */
#line 822 "cfg.y"
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

  case 149:

/* Line 1455 of yacc.c  */
#line 832 "cfg.y"
    {
									#ifdef USE_TLS
										yyerror("SSLv23, SSLv2, SSLv3 or TLSv1"
													" expected");
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 841 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->verify_cert
											= (yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 849 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 850 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_client_domain->verify_cert
											=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 858 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 859 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->require_client_cert=(yyvsp[(3) - (3)].intval);
									#else
										warn( "tls support not compiled in");
									#endif
									;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 866 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 867 "cfg.y"
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

  case 157:

/* Line 1455 of yacc.c  */
#line 877 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 878 "cfg.y"
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

  case 159:

/* Line 1455 of yacc.c  */
#line 888 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 889 "cfg.y"
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

  case 161:

/* Line 1455 of yacc.c  */
#line 899 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 900 "cfg.y"
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

  case 163:

/* Line 1455 of yacc.c  */
#line 910 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 911 "cfg.y"
    {
									#ifdef USE_TLS
										tls_handshake_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 918 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 919 "cfg.y"
    {
									#ifdef USE_TLS
										tls_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 926 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 927 "cfg.y"
    {
									#ifdef USE_TLS
										tstr.s = (yyvsp[(3) - (3)].strval);
										tstr.len = strlen(tstr.s);
										if (parse_avp_spec(&tstr, &tls_client_domain_avp)) {
											yyerror("cannot parse tls_client_avp");
										}
									#else
										warn("tls support not compiled in");
									#endif
									;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 938 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 941 "cfg.y"
    { server_signature=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 942 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 943 "cfg.y"
    { server_header.s=(yyvsp[(3) - (3)].strval);
									server_header.len=strlen((yyvsp[(3) - (3)].strval));
									;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 946 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 947 "cfg.y"
    { user_agent_header.s=(yyvsp[(3) - (3)].strval);
									user_agent_header.len=strlen((yyvsp[(3) - (3)].strval));
									;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 950 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 951 "cfg.y"
    { xlog_buf_size = (yyvsp[(3) - (3)].intval); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 952 "cfg.y"
    { xlog_force_color = (yyvsp[(3) - (3)].intval); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 953 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 954 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 956 "cfg.y"
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

  case 183:

/* Line 1455 of yacc.c  */
#line 971 "cfg.y"
    { yyerror("ip address or hostname "
						"expected (use quotes if the hostname includes"
						" config keywords)"); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 974 "cfg.y"
    { 
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next)
								add_alias(lst_tmp->name, strlen(lst_tmp->name),
											lst_tmp->port, lst_tmp->proto);
							  ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 979 "cfg.y"
    { yyerror("hostname expected (use quotes"
							" if the hostname includes config keywords)"); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 981 "cfg.y"
    { auto_aliases=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 982 "cfg.y"
    { yyerror("number  expected"); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 983 "cfg.y"
    {
								if ((yyvsp[(3) - (3)].strval)) {
									default_global_address.s=(yyvsp[(3) - (3)].strval);
									default_global_address.len=strlen((yyvsp[(3) - (3)].strval));
								}
								;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 989 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 991 "cfg.y"
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

  case 191:

/* Line 1455 of yacc.c  */
#line 1003 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1005 "cfg.y"
    {
										disable_core_dump=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1008 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1009 "cfg.y"
    {
										open_files_limit=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1012 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1013 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_loopback=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1020 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1021 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_ttl=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1028 "cfg.y"
    { yyerror("number expected as tos"); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1029 "cfg.y"
    { tos = (yyvsp[(3) - (3)].intval);
							if (tos<=0)
								yyerror("invalid tos value");
		 ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1033 "cfg.y"
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

  case 202:

/* Line 1455 of yacc.c  */
#line 1060 "cfg.y"
    { yyerror("number expected"); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1061 "cfg.y"
    { mpath=(yyvsp[(3) - (3)].strval); strcpy(mpath_buf, (yyvsp[(3) - (3)].strval));
								mpath_len=strlen((yyvsp[(3) - (3)].strval)); 
								if(mpath_buf[mpath_len-1]!='/') {
									mpath_buf[mpath_len]='/';
									mpath_len++;
									mpath_buf[mpath_len]='\0';
								}
							;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1069 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1070 "cfg.y"
    {
										disable_dns_failover=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1073 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1074 "cfg.y"
    {
										disable_dns_blacklist=(yyvsp[(3) - (3)].intval);
									;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1077 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1078 "cfg.y"
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

  case 210:

/* Line 1455 of yacc.c  */
#line 1088 "cfg.y"
    {
				sl_fwd_disabled=(yyvsp[(3) - (3)].intval);
				;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1091 "cfg.y"
    { db_version_table=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1092 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1093 "cfg.y"
    { db_default_url=(yyvsp[(3) - (3)].strval); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1094 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1095 "cfg.y"
    { disable_503_translation=(yyvsp[(3) - (3)].intval); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1096 "cfg.y"
    {
				yyerror("string value expected");
				;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1099 "cfg.y"
    { yyerror("unknown config variable"); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1102 "cfg.y"
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

  case 219:

/* Line 1455 of yacc.c  */
#line 1141 "cfg.y"
    { yyerror("string expected");  ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1142 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), STR_PARAM, (yyvsp[(7) - (8)].strval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1148 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), INT_PARAM, (void*)(yyvsp[(7) - (8)].intval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1154 "cfg.y"
    { yyerror("Invalid arguments"); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1158 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1159 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1162 "cfg.y"
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

  case 226:

/* Line 1455 of yacc.c  */
#line 1196 "cfg.y"
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

  case 227:

/* Line 1455 of yacc.c  */
#line 1216 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1217 "cfg.y"
    {(yyval.ipaddr)=(yyvsp[(2) - (3)].ipaddr); ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1220 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_server_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval))) 
								yyerror("tls_new_server_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1231 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval)))
								yyerror("tls_new_client_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1242 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain_name((yyvsp[(3) - (4)].strval), strlen((yyvsp[(3) - (4)].strval))))
								yyerror("tls_new_client_domain_name failed");
						#else	
							warn("tls support not compiled in");
						#endif
							;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1261 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1268 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1275 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1282 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1289 "cfg.y"
    { yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1290 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1297 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1299 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1306 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1308 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1315 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1316 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1323 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1324 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1331 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1332 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->require_client_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn( "tls support not compiled in");
						#endif
								;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1339 "cfg.y"
    { 
						yyerror("boolean value expected"); ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1343 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1350 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1357 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1364 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1371 "cfg.y"
    {
						yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1373 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1380 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1382 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1389 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1391 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1398 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1399 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1406 "cfg.y"
    { yyerror("string value expected"); ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1407 "cfg.y"
    {
						#ifdef USE_TLS
									tls_client_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1414 "cfg.y"
    { yyerror("boolean value expected"); ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1417 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
				;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1420 "cfg.y"
    {
				tmp=int2str((yyvsp[(1) - (1)].intval), &i_tmp);
				if (((yyval.strval)=pkg_malloc(i_tmp+1))==0)
					yyerror("cfg. parser: out of memory.\n");
				memcpy( (yyval.strval), tmp, i_tmp);
				(yyval.strval)[i_tmp] = 0;
				;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1427 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
		;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1432 "cfg.y"
    {
						if (rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"request routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &rlist[DEFAULT_RT].a);
					;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1440 "cfg.y"
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

  case 276:

/* Line 1455 of yacc.c  */
#line 1455 "cfg.y"
    { yyerror("invalid  route  statement"); ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1458 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),failure_rlist,
								FAILURE_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &failure_rlist[i_tmp].a);
					;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1464 "cfg.y"
    { yyerror("invalid failure_route statement"); ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1467 "cfg.y"
    {
						if (onreply_rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"onreply routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &onreply_rlist[DEFAULT_RT].a);
					;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1475 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),onreply_rlist,
								ONREPLY_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &onreply_rlist[i_tmp].a);
					;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1481 "cfg.y"
    { yyerror("invalid onreply_route statement"); ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1484 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),branch_rlist,
								BRANCH_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &branch_rlist[i_tmp].a);
					;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1490 "cfg.y"
    { yyerror("invalid branch_route statement"); ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1493 "cfg.y"
    {
						if (error_rlist.a!=0) {
							yyerror("overwritting default "
								"error routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &error_rlist.a);
					;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1501 "cfg.y"
    { yyerror("invalid error_route statement"); ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1504 "cfg.y"
    {
						if (local_rlist.a!=0) {
							yyerror("re-definition of local "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &local_rlist.a);
					;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1512 "cfg.y"
    { yyerror("invalid local_route statement"); ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1515 "cfg.y"
    {
						if (startup_rlist.a!=0) {
							yyerror("re-definition of startup "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &startup_rlist.a);
					;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1523 "cfg.y"
    { yyerror("invalid startup_route statement"); ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1526 "cfg.y"
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

  case 291:

/* Line 1455 of yacc.c  */
#line 1538 "cfg.y"
    { yyerror("invalid timer_route statement"); ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1541 "cfg.y"
    { (yyval.expr)=mk_exp(AND_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1542 "cfg.y"
    { (yyval.expr)=mk_exp(OR_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1543 "cfg.y"
    { (yyval.expr)=mk_exp(NOT_OP, (yyvsp[(2) - (2)].expr), 0);  ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1544 "cfg.y"
    { (yyval.expr)=mk_exp(EVAL_OP, (yyvsp[(2) - (3)].expr), 0); ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1545 "cfg.y"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1546 "cfg.y"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1549 "cfg.y"
    {(yyval.intval)=EQUAL_OP; ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1550 "cfg.y"
    {(yyval.intval)=DIFF_OP; ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1553 "cfg.y"
    {(yyval.intval)=GT_OP; ;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1554 "cfg.y"
    {(yyval.intval)=LT_OP; ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1555 "cfg.y"
    {(yyval.intval)=GTE_OP; ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1556 "cfg.y"
    {(yyval.intval)=LTE_OP; ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1558 "cfg.y"
    {(yyval.intval)=MATCH_OP; ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1559 "cfg.y"
    {(yyval.intval)=NOTMATCH_OP; ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1562 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1563 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1566 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1567 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1568 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1571 "cfg.y"
    {(yyval.intval)=URI_O;;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1572 "cfg.y"
    {(yyval.intval)=FROM_URI_O;;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1573 "cfg.y"
    {(yyval.intval)=TO_URI_O;;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1576 "cfg.y"
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

  case 315:

/* Line 1455 of yacc.c  */
#line 1590 "cfg.y"
    {
			(yyval.specval)=0; yyerror("invalid script variable name");
		;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1595 "cfg.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1596 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1597 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, NUMBER_O, 0, NUMBER_ST, 
											(void*)(yyvsp[(1) - (1)].intval) ); ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1599 "cfg.y"
    {
				(yyval.expr)=mk_elem(NO_OP, SCRIPTVAR_O,0,SCRIPTVAR_ST,(void*)(yyvsp[(1) - (1)].specval));
			;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1602 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1604 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1606 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1608 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1610 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1614 "cfg.y"
    {(yyval.expr)= mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
									;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1616 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1618 "cfg.y"
    { (yyval.expr)=0; yyerror("string expected"); ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1619 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
										"== , !=, or =~ expected");
						;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1622 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),SCRIPTVAR_ST,(void*)(yyvsp[(3) - (3)].specval));
			;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1625 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1628 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1631 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),NUMBER_ST,(void *)(yyvsp[(3) - (3)].intval));
			;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1634 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), MYSELF_ST, 0);
			;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1637 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), NULLV_ST, 0);
			;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1640 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 				;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1642 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, MYSELF_ST, 0);
								;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1644 "cfg.y"
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1645 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
									" == , != or =~ expected");
					;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1648 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1650 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1651 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1652 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1654 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1655 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1656 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), PROTO_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1658 "cfg.y"
    { (yyval.expr)=0;
								yyerror("protocol expected (udp, tcp or tls)");
							;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1661 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1662 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), AF_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1664 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1665 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1666 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1668 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) BUF_SIZE); ;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1670 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1671 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1672 "cfg.y"
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

  case 356:

/* Line 1455 of yacc.c  */
#line 1686 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1688 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 "expected" ); ;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1690 "cfg.y"
    { (yyval.expr)=0; 
						 yyerror("invalid operator, ==, != or =~ expected");;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1692 "cfg.y"
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

  case 360:

/* Line 1455 of yacc.c  */
#line 1706 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1708 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 			"expected" ); ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1710 "cfg.y"
    { (yyval.expr)=0; 
						yyerror("invalid operator, ==, != or =~ expected");;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1712 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval), 0, MYSELF_ST, 0);
								;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1714 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1716 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1718 "cfg.y"
    {	(yyval.expr)=0; 
									yyerror(" URI, SRCIP or DSTIP expected"); ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1720 "cfg.y"
    { (yyval.expr)=0; 
							yyerror ("invalid operator, == or != expected");
						;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1725 "cfg.y"
    { (yyval.ipnet)=mk_net((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].ipaddr)); ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1726 "cfg.y"
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

  case 370:

/* Line 1455 of yacc.c  */
#line 1737 "cfg.y"
    { (yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (1)].ipaddr), (yyvsp[(1) - (1)].ipaddr)->len*8); ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1738 "cfg.y"
    { (yyval.ipnet)=0;
						 yyerror("netmask (eg:255.0.0.0 or 8) expected");
						;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1745 "cfg.y"
    {(yyval.strval)=".";;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1746 "cfg.y"
    {(yyval.strval)="-"; ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1749 "cfg.y"
    { (yyval.strval)=(yyvsp[(1) - (1)].strval); ;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1750 "cfg.y"
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

  case 376:

/* Line 1455 of yacc.c  */
#line 1762 "cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[(1) - (3)].strval)); yyerror("invalid hostname (use quotes if hostname has config keywords)"); ;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1766 "cfg.y"
    { (yyval.intval) = EQ_T; ;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1767 "cfg.y"
    { (yyval.intval) = COLONEQ_T; ;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1768 "cfg.y"
    { (yyval.intval) = PLUSEQ_T; ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1769 "cfg.y"
    { (yyval.intval) = MINUSEQ_T;;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1770 "cfg.y"
    { (yyval.intval) = DIVEQ_T; ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1771 "cfg.y"
    { (yyval.intval) = MULTEQ_T; ;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1772 "cfg.y"
    { (yyval.intval) = MODULOEQ_T; ;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1773 "cfg.y"
    { (yyval.intval) = BANDEQ_T; ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1774 "cfg.y"
    { (yyval.intval) = BOREQ_T; ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1775 "cfg.y"
    { (yyval.intval) = BXOREQ_T; ;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1779 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, NUMBERV_O, (void*)(yyvsp[(1) - (1)].intval), 0, 0); ;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1780 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1781 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); ;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1782 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, SCRIPTVAR_O, (yyvsp[(1) - (1)].specval), 0, 0); ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1783 "cfg.y"
    { (yyval.expr)= (yyvsp[(1) - (1)].expr); ;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1784 "cfg.y"
    { (yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1785 "cfg.y"
    { 
				(yyval.expr) = mk_elem(PLUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1788 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MINUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr)); 
			;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1791 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MULT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1794 "cfg.y"
    { 
				(yyval.expr) = mk_elem(DIV_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1797 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MODULO_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1800 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BAND_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1803 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1806 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BXOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1809 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BLSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1812 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BRSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1815 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BNOT_OP, EXPR_O, (yyvsp[(2) - (2)].expr), 0, 0);
			;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1818 "cfg.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1821 "cfg.y"
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

  case 406:

/* Line 1455 of yacc.c  */
#line 1834 "cfg.y"
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

  case 407:

/* Line 1455 of yacc.c  */
#line 1847 "cfg.y"
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

  case 408:

/* Line 1455 of yacc.c  */
#line 1869 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1870 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1871 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1872 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1873 "cfg.y"
    { (yyval.action)=0; ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1876 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1877 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); ;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1878 "cfg.y"
    { (yyval.action)=0; ;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1881 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); ;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1882 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1883 "cfg.y"
    { (yyval.action)=0; yyerror("bad command!)"); ;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1886 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1887 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1888 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1889 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1890 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1891 "cfg.y"
    {(yyval.action)=0;;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1892 "cfg.y"
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); ;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1895 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 NOSUBTYPE,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action),
													 0);
									;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1903 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (5)].expr),
													 (yyvsp[(3) - (5)].action),
													 (yyvsp[(5) - (5)].action));
									;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1913 "cfg.y"
    { mk_action2( (yyval.action), WHILE_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action));
									;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1921 "cfg.y"
    {
											mk_action2( (yyval.action), SWITCH_T,
														SCRIPTVAR_ST,
														ACTIONS_ST,
														(yyvsp[(3) - (7)].specval),
														(yyvsp[(6) - (7)].action));
									;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1930 "cfg.y"
    { (yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); ;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1931 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); ;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1933 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); ;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1934 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1938 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].intval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1947 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].intval),
													0,
													(void*)1);
											;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1955 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].intval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1963 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].intval),
													0,
													(void*)0);
							;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1972 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].strval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1981 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].strval),
													0,
													(void*)1);
											;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1989 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].strval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1997 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].strval),
													0,
													(void*)0);
							;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2008 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													(yyvsp[(3) - (3)].action),
													0);
									;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2014 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													0,
													0);
									;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2022 "cfg.y"
    {
										elems[1].type = STRING_ST;
										elems[1].u.data = (yyvsp[(1) - (1)].strval);
										(yyval.intval)=1;
										;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2027 "cfg.y"
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

  case 446:

/* Line 1455 of yacc.c  */
#line 2036 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2040 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2047 "cfg.y"
    { mk_action2( (yyval.action), FORWARD_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2053 "cfg.y"
    {
										mk_action2( (yyval.action), FORWARD_T,
											0,
											0,
											0,
											0);
										;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2060 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2061 "cfg.y"
    { (yyval.action)=0; yyerror("bad forward "
										"argument"); ;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2064 "cfg.y"
    { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2070 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2071 "cfg.y"
    { (yyval.action)=0; yyerror("bad send"
													"argument"); ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2073 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2074 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2075 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2076 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2077 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].intval),
																0);
												;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2083 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																SCRIPTVAR_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].specval),
																0);
												;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2089 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2095 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2101 "cfg.y"
    {mk_action2( (yyval.action), LOG_T, NUMBER_ST, 
													STRING_ST,(void*)4,(yyvsp[(3) - (4)].strval));
									;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2104 "cfg.y"
    {mk_action2( (yyval.action), LOG_T,
																NUMBER_ST, 
																STRING_ST,
																(void*)(yyvsp[(3) - (6)].intval),
																(yyvsp[(5) - (6)].strval));
												;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2110 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2111 "cfg.y"
    { (yyval.action)=0; yyerror("bad log"
									"argument"); ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2113 "cfg.y"
    {mk_action2((yyval.action), SET_DEBUG_T, NUMBER_ST,
									0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2115 "cfg.y"
    {mk_action2( (yyval.action), SET_DEBUG_T, 0, 0, 0, 0 ); ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2116 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2117 "cfg.y"
    {mk_action2((yyval.action), SETFLAG_T, NUMBER_ST, 0,
													(void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2119 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2120 "cfg.y"
    {mk_action2( (yyval.action), RESETFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2122 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2123 "cfg.y"
    {mk_action2( (yyval.action), ISFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2125 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2126 "cfg.y"
    {mk_action2( (yyval.action), SETSFLAG_T, NUMBER_ST,
										0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2128 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2129 "cfg.y"
    {mk_action2( (yyval.action), RESETSFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2131 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2132 "cfg.y"
    {mk_action2( (yyval.action), ISSFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2134 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2135 "cfg.y"
    {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2139 "cfg.y"
    {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2142 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2143 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2147 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2151 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2152 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); ;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2156 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); ;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2160 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2161 "cfg.y"
    {mk_action2( (yyval.action), ERROR_T,
																STRING_ST, 
																STRING_ST,
																(yyvsp[(3) - (6)].strval),
																(yyvsp[(5) - (6)].strval));
												  ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2167 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2168 "cfg.y"
    { (yyval.action)=0; yyerror("bad error"
														"argument"); ;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2170 "cfg.y"
    { 
						i_tmp = get_script_route_idx( (yyvsp[(3) - (4)].strval), rlist, RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						mk_action2( (yyval.action), ROUTE_T, NUMBER_ST,
							0, (void*)(long)i_tmp, 0);
					;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2176 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2177 "cfg.y"
    { (yyval.action)=0; yyerror("bad route"
						"argument"); ;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2179 "cfg.y"
    { mk_action2( (yyval.action), SET_HOST_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2181 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2182 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2185 "cfg.y"
    { mk_action2( (yyval.action), PREFIX_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2187 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2188 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2190 "cfg.y"
    { mk_action2( (yyval.action), STRIP_TAIL_T, 
									NUMBER_ST, 0, (void *) (yyvsp[(3) - (4)].intval), 0); ;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2192 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2193 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2196 "cfg.y"
    { mk_action2( (yyval.action), STRIP_T, NUMBER_ST,
														0, (void *) (yyvsp[(3) - (4)].intval), 0); ;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2198 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2199 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); ;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2201 "cfg.y"
    { 
				{   qvalue_t q;
				if (str2q(&q, (yyvsp[(5) - (6)].strval), strlen((yyvsp[(5) - (6)].strval))) < 0) {
					yyerror("bad argument, q value expected");
				}
				mk_action2( (yyval.action), APPEND_BRANCH_T, STR_ST, NUMBER_ST, (yyvsp[(3) - (6)].strval),
						(void *)(long)q); } 
		;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2209 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, (yyvsp[(3) - (4)].strval), (void *)Q_UNSPECIFIED) ; ;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2211 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED) ; ;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2213 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED ) ; ;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2215 "cfg.y"
    {
						mk_action1((yyval.action), REMOVE_BRANCH_T, NUMBER_ST, (void*)(yyvsp[(3) - (4)].intval));;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2217 "cfg.y"
    {
						mk_action1( (yyval.action), REMOVE_BRANCH_T, SCRIPTVAR_ST, (yyvsp[(3) - (4)].specval));;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2220 "cfg.y"
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

  case 516:

/* Line 1455 of yacc.c  */
#line 2243 "cfg.y"
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

  case 517:

/* Line 1455 of yacc.c  */
#line 2258 "cfg.y"
    { mk_action2( (yyval.action), SET_HOSTPORT_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2260 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2261 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
												" string expected"); ;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2263 "cfg.y"
    { mk_action2( (yyval.action), SET_PORT_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2265 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2266 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2268 "cfg.y"
    { mk_action2( (yyval.action), SET_USER_T,
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2270 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2271 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2273 "cfg.y"
    { mk_action2( (yyval.action), SET_USERPASS_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2275 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2276 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 2278 "cfg.y"
    { mk_action2( (yyval.action), SET_URI_T, STR_ST, 
														0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 2280 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 2281 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); ;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 2283 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); ;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 2284 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); ;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 2285 "cfg.y"
    { mk_action2( (yyval.action), SET_DSTURI_T,
													STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); ;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 2287 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 2288 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); ;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 2290 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T,
															0,0,0,0); ;}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 2292 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T, 0,0,0,0); ;}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 2293 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); ;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 2294 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); ;}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 2295 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,
															0, 0, 0, 0); ;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 2297 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,0, 0, 0, 0); ;}
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 2298 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); ;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 2300 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); ;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 2302 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,NUMBER_ST, 0,
										(void*)(yyvsp[(3) - (4)].intval), 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
												;}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 2310 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0); 
					#else
						yyerror("tcp support not compiled in");
					#endif
										;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 2317 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
										;}
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 2324 "cfg.y"
    {(yyval.action)=0; 
					yyerror("bad argument, number expected");
					;}
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 2327 "cfg.y"
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

  case 550:

/* Line 1455 of yacc.c  */
#line 2338 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); ;}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 2340 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 2341 "cfg.y"
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

  case 553:

/* Line 1455 of yacc.c  */
#line 2357 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
								"string expected"); ;}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 2359 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 2360 "cfg.y"
    {
								mk_action2( (yyval.action), FORCE_SEND_SOCKET_T,
									SOCKID_ST, 0, (yyvsp[(3) - (4)].sockid), 0);
								;}
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 2364 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
								" [proto:]host[:port] expected");
								;}
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 2367 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 2368 "cfg.y"
    {
								mk_action2( (yyval.action), SERIALIZE_BRANCHES_T,
									NUMBER_ST, 0, (void*)(long)(yyvsp[(3) - (4)].intval), 0);
								;}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 2372 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" number expected");
								;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 2375 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 2376 "cfg.y"
    {
								mk_action2( (yyval.action), NEXT_BRANCHES_T, 0, 0, 0, 0);
								;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 2379 "cfg.y"
    {(yyval.action)=0; yyerror("no argument is"
								" expected");
								;}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 2382 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 2383 "cfg.y"
    {
								mk_action2( (yyval.action), USE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								;}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 2387 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								;}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 2390 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 2391 "cfg.y"
    {
								mk_action2( (yyval.action), UNUSE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								;}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 2395 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								;}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 2398 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); ;}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 2399 "cfg.y"
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

  case 571:

/* Line 1455 of yacc.c  */
#line 2409 "cfg.y"
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

  case 572:

/* Line 1455 of yacc.c  */
#line 2421 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].strval); 
								elems[3].type = SCRIPTVAR_ST; 
								elems[3].u.data = (yyvsp[(9) - (10)].specval);
								(yyval.action) = mk_action(CACHE_STORE_T, 4, elems, line); 
							;}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 2433 "cfg.y"
    { 
									mk_action2( (yyval.action), CACHE_REMOVE_T,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (6)].strval),
													(yyvsp[(5) - (6)].strval));
							;}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 2440 "cfg.y"
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

  case 575:

/* Line 1455 of yacc.c  */
#line 2449 "cfg.y"
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

  case 576:

/* Line 1455 of yacc.c  */
#line 2466 "cfg.y"
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

  case 577:

/* Line 1455 of yacc.c  */
#line 2483 "cfg.y"
    { (yyval.action)=0; yyerrorf("bad arguments for "
												"command <%s>", (yyvsp[(1) - (4)].strval)); ;}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 2485 "cfg.y"
    { (yyval.action)=0; yyerrorf("bare word <%s> found, command calls need '()'", (yyvsp[(1) - (2)].strval)); ;}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 2487 "cfg.y"
    {
				mk_action1((yyval.action), XDBG_T, STR_ST, (yyvsp[(3) - (4)].strval));	;}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 2489 "cfg.y"
    {
				mk_action1((yyval.action), XLOG_T, STR_ST, (yyvsp[(3) - (4)].strval)); ;}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 2491 "cfg.y"
    {
				mk_action2((yyval.action), XLOG_T, STR_ST, STR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].strval)); ;}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 2493 "cfg.y"
    {
				mk_action1((yyval.action), RAISE_EVENT_T, STR_ST, (yyvsp[(3) - (4)].strval)); ;}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 2495 "cfg.y"
    {
				mk_action2((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].specval)); ;}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 2497 "cfg.y"
    {
				mk_action3((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, SCRIPTVAR_ST, (yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].specval), (yyvsp[(7) - (8)].specval)); ;}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 2499 "cfg.y"
    {
				elems[0].type = STR_ST; 
				elems[0].u.data = (yyvsp[(3) - (14)].strval); 
				elems[1].type = STR_ST; 
				elems[1].u.data = (yyvsp[(5) - (14)].strval); 
				elems[2].type = STR_ST; 
				elems[2].u.data = (yyvsp[(7) - (14)].strval); 
				elems[3].type = STR_ST; 
				elems[3].u.data = (yyvsp[(9) - (14)].strval);
				elems[4].type = STR_ST; 
				elems[4].u.data = (yyvsp[(11) - (14)].strval);
				elems[5].type = SCRIPTVAR_ST; 
				elems[5].u.data = (yyvsp[(13) - (14)].specval);
				(yyval.action) = mk_action(CONSTRUCT_URI_T,6,elems,line); ;}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 2513 "cfg.y"
    {
				elems[0].type = SCRIPTVAR_ST;
				elems[0].u.data = (yyvsp[(3) - (6)].specval);
				elems[1].type = SCRIPTVAR_ST;
				elems[1].u.data = (yyvsp[(5) - (6)].specval); 
				(yyval.action) = mk_action(GET_TIMESTAMP_T,2,elems,line); ;}
    break;



/* Line 1455 of yacc.c  */
#line 8707 "cfg.tab.c"
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
#line 2528 "cfg.y"


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

