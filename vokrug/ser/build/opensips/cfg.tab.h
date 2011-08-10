
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 280 "cfg.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


