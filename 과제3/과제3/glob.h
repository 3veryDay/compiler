enum errorType { noerror, digit_ident, long_ident, ill_symbol, over_st, missing_semi, missing_paren, missing_curly, missing_square, missing_comma, missing_funcheader, declaring_err, missing_condition, wrong_assign, missing_operand
};
typedef enum errorType ErrorType;
ErrorType err;

int lineno;
