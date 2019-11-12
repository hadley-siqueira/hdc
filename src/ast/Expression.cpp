#include "ast/Expression.h"

using namespace hdc;

Expression::~Expression() {

}

/* Visitors */
void Expression::accept(Visitor* visitor) {
    visitor->visit(this);
}
