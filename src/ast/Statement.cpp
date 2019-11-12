#include "ast/Statement.h"

using namespace hdc;

Statement::~Statement() {

}

void Statement::accept(Visitor* visitor) {
    visitor->visit(this);
}
