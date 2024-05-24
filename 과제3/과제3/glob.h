enum errorType { noerror, digit_ident, long_ident, ill_symbol, over_st, miss_semi, miss_paren, miss_curly, miss_square, miss_comma, miss_funcheader, declaring_err, miss_condition, wrong_assign, miss_operand
};
typedef enum errorType ErrorType;
ErrorType err;
