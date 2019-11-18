#ifndef HDC_PARSER_H
#define HDC_PARSER_H

#include <string>

#include "lex/Lex.h"
#include "ast/AST.h"

namespace hdc {
    class Parser {
        public:
            SourceFile* read(std::string path);

        private:
            void advance();
            bool lookahead(TokenKind kind);
            bool match(TokenKind kind);
            void expect(TokenKind kind);

        private:
            Import* parse_import();
            Def* parse_def();
            Class* parse_class();

            std::vector<Expression*> parse_argument_list();
            IdentifierExpression* parse_identifier_expression();

            Expression* parse_primary_expression();
            Expression* parse_postfix_expression();
            Expression* parse_unary_expression();

            Expression* parse_shift_expression();

            Expression* parse_bitwise_and_expression();
            Expression* parse_bitwise_xor_expression();
            Expression* parse_bitwise_or_expression();

            Expression* parse_term_expression();
            Expression* parse_arith_expression();
            Expression* parse_relational_expression();

            Expression* parse_assignment_expression();

            Expression* parse_expression();

            WhileStatement* parse_while_statement();
            CompoundStatement* parse_statements();
            Statement* parse_statement();

            Type* parse_type();

        private:
            SourceFile* file;
            std::vector<Token> tokens;

        private:
             std::vector<Token>::iterator current_token;
             std::vector<Token>::iterator matched;


    };
}

#endif