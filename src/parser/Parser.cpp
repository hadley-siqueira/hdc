#include <iostream>

#include "parser/Parser.h"

using namespace hdc;

void Parser::advance() {
    if ((*current_token).getKind() != TK_EOF) {
        ++current_token;
    } 
}

bool Parser::lookahead(TokenKind kind) {
    return (*current_token).getKind() == kind;
}

bool Parser::match(TokenKind kind) {
    if (lookahead(kind)) {
        matched = current_token;
        advance();
        return true;
    }

    return false;
}


void Parser::expect(TokenKind kind) {
    Token expected;

    if (match(kind)) return;

    expected.setKind(kind);

    std::cout << (*current_token).getLine() << ": ";
    std::cout << "expected a " << expected.getKindAsString()
        << " but got a " << (*current_token).getKindAsString() << " instead\n";

    exit(0);
}


Import* Parser::parse_import() {
    Import* import = new Import();

    expect(TK_IMPORT);
    expect(TK_ID);

    import->add(*matched);

    while (match(TK_DOT)) {
        expect(TK_ID);
        import->add(*matched);
    }

    if (match(TK_AS)) {
        expect(TK_ID);
        import->set_alias(*matched);
    }

    expect(TK_NEWLINE);
    return import;
}


Type* Parser::parse_type() {
    Type* type = NULL;

    if (match(TK_INT)) {
        type = new IntType(*matched);
    } else if (match(TK_UINT)) {
        type = new UIntType(*matched);
    } else if (match(TK_FLOAT)) {
        type = new FloatType(*matched);
    } else if (match(TK_DOUBLE)) {
        type = new DoubleType(*matched);
    } else if (match(TK_SHORT)) {
        type = new ShortType(*matched);
    } else if (match(TK_USHORT)) {
        type = new UShortType(*matched);
    } else if (match(TK_LONG)) {
        type = new LongType(*matched);
    } else if (match(TK_ULONG)) {
        type = new ULongType(*matched);
    } else if (match(TK_CHAR)) {
        type = new CharType(*matched);
    } else if (match(TK_UCHAR)) {
        type = new UCharType(*matched);
    } else if (match(TK_SYMBOL)) {
        type = new SymbolType(*matched);
    } else if (match(TK_VOID)) {
        type = new VoidType(*matched);
    } else if (match(TK_BOOL)) {
        type = new BoolType(*matched);
    } else if (match(TK_I8)) {
        type = new Int8Type(*matched);
    } else if (match(TK_I16)) {
        type = new Int16Type(*matched);
    } else if (match(TK_I32)) {
        type = new Int32Type(*matched);
    } else if (match(TK_I64)) {
        type = new Int64Type(*matched);
    } else if (match(TK_U8)) {
        type = new UInt8Type(*matched);
    } else if (match(TK_U16)) {
        type = new UInt16Type(*matched);
    } else if (match(TK_U32)) {
        type = new UInt32Type(*matched);
    } else if (match(TK_U64)) {
        type = new UInt64Type(*matched);
    } else if (lookahead(TK_ID)) {
        type = parse_named_type();
    }

    while (type != NULL) {
        if (match(TK_TIMES)) {
            type = new PointerType(type, *matched);
        } else if (match(TK_POWER)) {
            type = new PointerType(new PointerType(type, *matched), *matched);
        } else {
            break;
        }
    }

    return type;
}

IdentifierExpression* Parser::parse_identifier_expression() {
    IdentifierExpression* id;
    Token name;
    Token alias;

    expect(TK_ID);
    name = *matched;

    if (match(TK_SCOPE)) {
        expect(TK_ID);
        alias = name;
        name = *matched;
        id = new IdentifierExpression(alias, name);
    } else {
        id = new IdentifierExpression(name);
    }

    return id;
}

Expression* Parser::parse_primary_expression() {
    Expression* expression = NULL;
    Token oper;

    if (match(TK_LEFT_PARENTHESIS)) {
        oper = *matched;
        expression = new ParenthesisExpression(oper, parse_expression());
        expect(TK_RIGHT_PARENTHESIS);
    } else if (match(TK_DOLAR)) {
        oper = *matched;
        expression = new DolarExpression(oper, parse_identifier_expression());
    } else if (match(TK_LITERAL_INTEGER)) {
        expression = new LiteralIntegerExpression(*matched);
    } else if (match(TK_LITERAL_CHAR)) {
        expression = new LiteralCharExpression(*matched);
    } else if (match(TK_LITERAL_FLOAT)) {
        expression = new LiteralFloatExpression(*matched);
    } else if (match(TK_LITERAL_DOUBLE)) {
        expression = new LiteralDoubleExpression(*matched);
    } else if (match(TK_LITERAL_STRING)) {
        expression = new LiteralStringExpression(*matched);
    } else if (match(TK_LITERAL_SYMBOL)) {
        expression = new LiteralSymbolExpression(*matched);
    } else if (match(TK_TRUE)) {
        expression = new LiteralBoolExpression(*matched);
    } else if (match(TK_FALSE)) {
        expression = new LiteralBoolExpression(*matched);
    } else {
        expression = parse_identifier_expression();
    }

    return expression; 
}

std::vector<Expression*> Parser::parse_argument_list() {
    std::vector<Expression*> arguments;

    if (!lookahead(TK_RIGHT_PARENTHESIS)) {
        arguments.push_back(parse_expression());

        while (match(TK_COMMA)) {
            arguments.push_back(parse_expression());
        }
    }

    return arguments;
}

Expression* Parser::parse_postfix_expression() {
    Expression* expression = parse_primary_expression();
    Token oper;

    while (true) {
        if (match(TK_DOT)) {
            oper = *matched;
            expression = new DotExpression(oper, expression, parse_identifier_expression());
        } else if (match(TK_ARROW)) {
            oper = *matched;
            expression = new ArrowExpression(oper, expression, parse_identifier_expression());
        } else if (match(TK_LEFT_SQUARE_BRACKET)) {
            oper = *matched;
            expression = new IndexExpression(oper, expression, parse_expression());
            expect(TK_RIGHT_SQUARE_BRACKET);
        } else if (match(TK_LEFT_PARENTHESIS)) {
            oper = *matched;
            expression = new CallExpression(oper, expression, parse_argument_list());
            expect(TK_RIGHT_PARENTHESIS);
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_unary_expression() {
    Expression* expression = NULL;
    Token oper;

    if (match(TK_LOGICAL_NOT)) {
        oper = *matched;
        expression = new LogicalNotExpression(oper, parse_unary_expression());
    } else if (match(TK_BITWISE_AND)) {
        oper = *matched;
        expression = new AddressOfExpression(oper, parse_unary_expression());
    } else if (match(TK_TIMES)) {
        oper = *matched;
        expression = new DereferenceExpression(oper, parse_unary_expression());
    } else if (match(TK_POWER)) {
        oper = *matched;
        expression = new DereferenceExpression(oper, parse_unary_expression());
        expression = new DereferenceExpression(oper, expression);
    } else if (match(TK_BITWISE_NOT)) {
        oper = *matched;
        expression = new BitwiseNotExpression(oper, parse_unary_expression());
    } else if (match(TK_MINUS)) {
        oper = *matched;
        expression = new UnaryMinusExpression(oper, parse_unary_expression());
    } else if (match(TK_PLUS)) {
        oper = *matched;
        expression = new UnaryPlusExpression(oper, parse_unary_expression());
    } else if (match(TK_INC)) {
        oper = *matched;
        expression = new PreIncrementExpression(oper, parse_unary_expression());
    } else if (match(TK_DEC)) {
        oper = *matched;
        expression = new PreDecrementExpression(oper, parse_unary_expression());
    } else if (match(TK_SIZEOF)) {
        oper = *matched;
        expect(TK_LEFT_PARENTHESIS);
        expression = new SizeOfExpression(oper, parse_unary_expression());
        expect(TK_RIGHT_PARENTHESIS);
    } else {
        expression = parse_postfix_expression();
    }

    return expression;
}

Expression* Parser::parse_shift_expression() {
    Token oper;
    Expression* expression = parse_unary_expression();

    while (true) {
        if (match(TK_SLL)) {
            oper = *matched;
            expression = new ShiftLeftLogicalExpression(oper, expression, parse_unary_expression());
        } else if (match(TK_SRL)) {
            oper = *matched;
            expression = new ShiftRightLogicalExpression(oper, expression, parse_unary_expression());
        } else if (match(TK_SRA)) {
            oper = *matched;
            expression = new ShiftRightArithmeticExpression(oper, expression, parse_unary_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_bitwise_and_expression() {
    Token oper;
    Expression* expression = parse_shift_expression();

    while (true) {
        if (match(TK_BITWISE_AND)) {
            oper = *matched;
            expression = new BitwiseAndExpression(oper, expression, parse_shift_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_bitwise_xor_expression() {
    Token oper;
    Expression* expression = parse_bitwise_and_expression();

    while (true) {
        if (match(TK_BITWISE_XOR)) {
            oper = *matched;
            expression = new BitwiseXorExpression(oper, expression, parse_bitwise_and_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_bitwise_or_expression() {
    Token oper;
    Expression* expression = parse_bitwise_xor_expression();

    while (true) {
        if (match(TK_BITWISE_OR)) {
            oper = *matched;
            expression = new BitwiseOrExpression(oper, expression, parse_bitwise_xor_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_term_expression() {
    Token oper;
    Expression* expression = parse_bitwise_or_expression();

    while (true) {
        if (match(TK_TIMES)) {
            oper = *matched;
            expression = new TimesExpression(oper, expression, parse_bitwise_or_expression());
        } else if (match(TK_DIVISION)) {
            oper = *matched;
            expression = new DivisionExpression(oper, expression, parse_bitwise_or_expression());
        } else if (match(TK_INTEGER_DIVISION)) {
            oper = *matched;
            expression = new IntegerDivisionExpression(oper, expression, parse_bitwise_or_expression());
        } else if (match(TK_MODULO)) {
            oper = *matched;
            expression = new ModuloExpression(oper, expression, parse_bitwise_or_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_arith_expression() {
    Token oper;
    Expression* expression = parse_term_expression();

    while (true) {
        if (match(TK_PLUS)) {
            oper = *matched;
            expression = new PlusExpression(oper, expression, parse_term_expression());
        } else if (match(TK_MINUS)) {
            oper = *matched;
            expression = new MinusExpression(oper, expression, parse_term_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_relational_expression() {
    Token oper;
    Expression* expression = parse_arith_expression();

    while (true) {
        if (match(TK_LT)) {
            oper = *matched;
            expression = new LessThanExpression(oper, expression, parse_arith_expression());
        } else if (match(TK_GT)) {
            oper = *matched;
            expression = new GreaterThanExpression(oper, expression, parse_arith_expression());
        } else if (match(TK_LE)) {
            oper = *matched;
            expression = new LessThanOrEqualExpression(oper, expression, parse_arith_expression());
        } else if (match(TK_GE)) {
            oper = *matched;
            expression = new GreaterThanOrEqualExpression(oper, expression, parse_arith_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression*Parser::parse_equality_expression() {
    Token oper;
    Expression* expression = parse_relational_expression();

    while (true) {
        if (match(TK_EQ)) {
            oper = *matched;
            expression = new EqualExpression(oper, expression, parse_relational_expression());
        } else if (match(TK_NE)) {
            oper = *matched;
            expression = new NotEqualExpression(oper, expression, parse_relational_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_assignment_expression() {
    Token oper;
    Expression* expression = parse_equality_expression();

    while (true) {
        if (match(TK_ASSIGNMENT)) {
            expression = new AssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_BITWISE_AND_ASSIGNMENT)) {
            expression = new BitwiseAndAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_BITWISE_XOR_ASSIGNMENT)) {
            expression = new BitwiseXorAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_BITWISE_OR_ASSIGNMENT)) {
            expression = new BitwiseOrAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_BITWISE_NOT_ASSIGNMENT)) {
            expression = new BitwiseNotAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_DIVISION_ASSIGNMENT)) {
            expression = new DivisionAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_INTEGER_DIVISION_ASSIGNMENT)) {
            expression = new IntegerDivisionAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_MINUS_ASSIGNMENT)) {
            expression = new MinusAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_MODULO_ASSIGNMENT)) {
            expression = new ModuloAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_PLUS_ASSIGNMENT)) {
            expression = new PlusAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_TIMES_ASSIGNMENT)) {
            expression = new TimesAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_SLL_ASSIGNMENT)) {
            expression = new SllAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_SRA_ASSIGNMENT)) {
            expression = new SraAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_SRL_ASSIGNMENT)) {
            expression = new SrlAssignmentExpression(oper, expression, parse_equality_expression());
        } else if (match(TK_SPECIAL_ASSIGNMENT)) {
            expression = new SpecialAssignmentExpression(oper, expression, parse_equality_expression());
        } else {
            break;
        }
    }

    return expression;
}

Expression* Parser::parse_expression() {
    return parse_assignment_expression();
}

ReturnStatement* Parser::parse_return_statement() {
    Token token;
    ReturnStatement* ret;

    expect(TK_RETURN);
    token = *matched;

    if (lookahead(TK_NEWLINE)) {
        ret = new ReturnStatement(token);
    } else {
        ret = new ReturnStatement(token, parse_expression());
    }

    expect(TK_NEWLINE);
    return ret;
}


WhileStatement* Parser::parse_while_statement() {
    Expression* expression;
    CompoundStatement* statements;

    expect(TK_WHILE);
    expression = parse_expression();

    expect(TK_COLON);
    expect(TK_NEWLINE);
    expect(TK_BEGIN);
    statements = parse_statements();
    expect(TK_END);

    return new WhileStatement(expression, statements);
}

IfStatement* Parser::parse_if_statement() {
    Expression* expression;
    CompoundStatement* statements;

    expect(TK_IF);
    expression = parse_expression();

    expect(TK_COLON);
    expect(TK_NEWLINE);
    expect(TK_BEGIN);
    statements = parse_statements();
    expect(TK_END);

    if (lookahead(TK_ELIF)) {
        return new IfStatement(expression, statements, parse_elif_statement());
    } else if (lookahead(TK_ELSE)) {
        return new IfStatement(expression, statements, parse_else_statement());
    }

    return new IfStatement(expression, statements);
}

ElifStatement* Parser::parse_elif_statement() {
    Expression* expression;
    CompoundStatement* statements;

    expect(TK_ELIF);
    expression = parse_expression();

    expect(TK_COLON);
    expect(TK_NEWLINE);
    expect(TK_BEGIN);
    statements = parse_statements();
    expect(TK_END);

    if (lookahead(TK_ELIF)) {
        return new ElifStatement(expression, statements, parse_elif_statement());
    } else if (lookahead(TK_ELSE)) {
        return new ElifStatement(expression, statements, parse_else_statement());
    }

    return new ElifStatement(expression, statements);
}

ElseStatement* Parser::parse_else_statement() {
    CompoundStatement* statements;

    expect(TK_ELSE);
    expect(TK_COLON);
    expect(TK_NEWLINE);
    expect(TK_BEGIN);
    statements = parse_statements();
    expect(TK_END);

    return new ElseStatement(statements);
}

Statement* Parser::parse_statement() {
    Statement* statement;

    if (lookahead(TK_WHILE)) {
        statement = parse_while_statement();
    } else if (lookahead(TK_IF)) {
        statement = parse_if_statement();
    } else if (lookahead(TK_RETURN)) {
        statement = parse_return_statement();
    } else {
        statement = parse_expression();
        expect(TK_NEWLINE);
    }

    return statement;
}

Type* Parser::parse_named_type() {
    IdentifierExpression* name;

    name = parse_identifier_expression();

    return new NamedType(name);
}


CompoundStatement* Parser::parse_statements() {
    CompoundStatement* statements = new CompoundStatement();

    if (match(TK_PASS)) {
        expect(TK_NEWLINE);
    } else {
        while (!lookahead(TK_END)) {
            statements->addStatement(parse_statement());
        }
    }

    return statements;
}

Def* Parser::parse_def() {
    Def* def = new Def();

    expect(TK_DEF);
    expect(TK_ID);

    def->setName(*matched);

    expect(TK_COLON);
    def->setReturnType(parse_type());

    expect(TK_NEWLINE);
    expect(TK_BEGIN);

    while (match(TK_AT)) {
        Token name;
        Type* ptype;

        expect(TK_ID);
        name = *matched;

        expect(TK_COLON);
        ptype = parse_type();
        expect(TK_NEWLINE);

        def->addParameter(name, ptype);
    }

    def->setStatements(parse_statements());
    expect(TK_END);

    return def;
}

Class* Parser::parse_class() {
    Token name;
    Class* klass = new Class();

    expect(TK_CLASS);
    expect(TK_ID);
    klass->setName(*matched);
    name = *matched;

    if (match(TK_LEFT_PARENTHESIS)) {
        klass->setParent(parse_identifier_expression());
        expect(TK_RIGHT_PARENTHESIS);
    }

    expect(TK_COLON);
    expect(TK_NEWLINE);
    expect(TK_BEGIN);

    while (true) {
        if (lookahead(TK_DEF)) {
            klass->addMethod(parse_def());
        } else if (lookahead(TK_ID)){
            klass->addVariable(parse_class_variable());
        } else {
            break;
        }
    }

    expect(TK_END);

    return klass;
}

ClassVariable* Parser::parse_class_variable() {
    Token token;
    Type* type;

    expect(TK_ID);
    token = *matched;

    expect(TK_COLON);
    type = parse_type();
    expect(TK_NEWLINE);

    return new ClassVariable(token, type);
}


SourceFile* Parser::read(std::string path) {
    Lex lex;

    tokens = lex.getTokens(path);
    file = new SourceFile(path);
    current_token = tokens.begin();

    while (true) { 
        if (lookahead(TK_IMPORT)) {
            file->addImport(parse_import());
        } else if (lookahead(TK_DEF)) {
            file->addDef(parse_def());
        } else if (lookahead(TK_CLASS)) {
            file->addClass(parse_class());
        } else {
            break;
        }
    }

    return file;
}
