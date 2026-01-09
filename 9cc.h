#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// トークナイズ
typedef enum
{
    TK_RESERVED, // 予約語
    TK_NUM,      // 整数トークン
    TK_EOF,      // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

struct Token
{
    TokenKind kind; // トークンの型
    Token *next;    // 次のトークンのポインタ
    int val;        // 値
    char *str;      // 文字列
    int len;        // トークンの長さ
};

extern Token *token;
extern char *user_input;

Token *tokenize(char *p);
bool consume(char *op);
void expect(char *op);
int expect_number();

// パーサーの処理
typedef enum
{
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_NUM,
    ND_EQ, // ==
    ND_NE, // !=
    ND_LT, // <
    ND_LE, // <=
} NodeKind;

typedef struct Node Node;

struct Node
{
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
};

Node *expr();

// codegenの処理
void gen(Node *node);
