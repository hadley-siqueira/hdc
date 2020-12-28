#ifndef HDC_PARSER_H
#define HDC_PARSER_H

#include <string>

#include "lex/Lex.h"
#include "ast/AST.h"
#include "logger/Logger.h"

namespace hdc {
    class Parser {
        public:
            SourceFile* read(std::string path);

            Logger* getLogger() const;
            void setLogger(Logger* value);

    private:
            void advance();
            bool lookahead(TokenKind kind);
            bool match(TokenKind kind);
            void expect(TokenKind kind);
            bool hasParameters();

        private:
            Import* parse_import();
            Def* parse_def();
            Class* parse_class();
            Struct* parse_struct();
            ClassVariable* parse_class_variable();
            GlobalVariable* parse_global_variable();
            VariableDeclarationStatement *parse_local_variable();
            GlobalConstant* parse_global_constant();

            std::vector<Expression*> parse_argument_list();
            IdentifierExpression* parse_identifier_expression();

            Expression* parse_array_expression();
            Expression* parse_list_expression();
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
            Expression* parse_equality_expression();
            Expression* parse_logical_and_expression();
            Expression* parse_logical_or_expression();
            Expression* parse_range_expression();

            Expression* parse_assignment_expression();

            Expression* parse_expression();

            ReturnStatement* parse_return_statement();
            WhileStatement* parse_while_statement();
            Statement* parse_for_statement();
            IfStatement* parse_if_statement();
            ElifStatement* parse_elif_statement();
            ElseStatement* parse_else_statement();
            CompoundStatement* parse_statements();
            Statement* parse_statement();

            NamedType *parse_named_type();
            Type* parse_type();

        private:
            SourceFile* file;
            std::vector<Token> tokens;

        private:
             std::vector<Token>::iterator current_token;
             std::vector<Token>::iterator matched;
             Logger* logger;
             std::string filePath;


    };
}

#endif
