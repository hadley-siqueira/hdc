#include "ast/operators/binary/ExclusiveRangeExpression.h"

using namespace hdc;

/* Constructors */
ExclusiveRangeExpression::ExclusiveRangeExpression() {
    setKind(AST_EXCLUSIVE_RANGE);
}

ExclusiveRangeExpression::ExclusiveRangeExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_EXCLUSIVE_RANGE);
}

ExclusiveRangeExpression::ExclusiveRangeExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_EXCLUSIVE_RANGE);
}

/* Destructors */
ExclusiveRangeExpression::~ExclusiveRangeExpression() {
    /* Empty */
}

/* Visitors */
void ExclusiveRangeExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
