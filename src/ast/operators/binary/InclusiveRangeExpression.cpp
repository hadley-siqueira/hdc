#include "ast/operators/binary/InclusiveRangeExpression.h"

using namespace hdc;

/* Constructors */
InclusiveRangeExpression::InclusiveRangeExpression() {
    setKind(AST_INCLUSIVE_RANGE);
}

InclusiveRangeExpression::InclusiveRangeExpression(Expression* left, Expression* right) : BinaryOperator(left, right) {
    setKind(AST_INCLUSIVE_RANGE);
}

InclusiveRangeExpression::InclusiveRangeExpression(Token& oper, Expression* left, Expression* right) : BinaryOperator(oper, left, right) {
    setKind(AST_INCLUSIVE_RANGE);
}

/* Destructors */
InclusiveRangeExpression::~InclusiveRangeExpression() {
    /* Empty */
}

/* Visitors */
void InclusiveRangeExpression::accept(Visitor* visitor) {
    visitor->visit(this);
}
