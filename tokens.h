/* tokens.h */
enum e_tag {
    html = 1,
    body = 2,
    b = 3,
    br = 4
};
typedef enum e_tag Tag;

struct s_tagstart {
    Tag type;
    /* Attributes attrs; */
    int8 value[];   // similar to char value[]
};
typedef struct s_tagstart Tagstart;

struct s_tagend {
    Tag type;
    int8 value[];
};
typedef struct s_tagend Tagend;

struct s_selfclosed {
    Tag type;
    int8 value[];
};
typedef struct s_selfclose Selfclosed;

enum e_tokentype {
    text = 1,
    tagstart = 2,
    tagend = 3,
    selfclosed = 4
};
typedef enum e_tokentype Tokentype;

struct s_text {

};
typedef struct s_text Text;

struct s_token {
    Tokentype type;
    union {
        Text texttoken;
        Tagstart start;
        Tagend end;
        Selfclosed self;
    } contents;
};
typedef struct s_token Token;

struct s_tokens {
    int16 length;
    Token ts[];
}