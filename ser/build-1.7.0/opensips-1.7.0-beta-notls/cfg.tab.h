
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 296 "cfg.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


