#ifndef HDC_AST_H
#define HDC_AST_H

#include "ast/ASTNode.h"
#include "ast/SourceFile.h"
#include "ast/Def.h"
#include "ast/Class.h"

/* Variables */
#include "ast/Variable.h"
#include "ast/Parameter.h"
#include "ast/LocalVariable.h"

/* Statements */
#include "ast/Statement.h"
#include "ast/CompoundStatement.h"
#include "ast/WhileStatement.h"
#include "ast/IfStatement.h"
#include "ast/ElifStatement.h"
#include "ast/ElseStatement.h"
#include "ast/ReturnStatement.h"

/* Expressions */
#include "ast/Expression.h"
#include "ast/IdentifierExpression.h"

#include "ast/UnaryOperator.h"
#include "ast/LogicalNotExpression.h"
#include "ast/AddressOfExpression.h"
#include "ast/DereferenceExpression.h"
#include "ast/BitwiseNotExpression.h"
#include "ast/UnaryMinusExpression.h"
#include "ast/UnaryPlusExpression.h"
#include "ast/PreIncrementExpression.h"
#include "ast/PreDecrementExpression.h"
#include "ast/SizeOfExpression.h"
#include "ast/DolarExpression.h"
#include "ast/ParenthesisExpression.h"

#include "ast/BinaryOperator.h"

#include "ast/CallExpression.h"
#include "ast/DotExpression.h"
#include "ast/ArrowExpression.h"
#include "ast/IndexExpression.h"

#include "ast/ShiftLeftLogicalExpression.h"
#include "ast/ShiftRightLogicalExpression.h"
#include "ast/ShiftRightArithmeticExpression.h"

#include "ast/BitwiseAndExpression.h"
#include "ast/BitwiseXorExpression.h"
#include "ast/BitwiseOrExpression.h"

#include "ast/TimesExpression.h"
#include "ast/DivisionExpression.h"
#include "ast/IntegerDivisionExpression.h"
#include "ast/ModuloExpression.h"

#include "ast/PlusExpression.h"
#include "ast/MinusExpression.h"

#include "ast/LessThanExpression.h"
#include "ast/GreaterThanExpression.h"
#include "ast/LessThanOrEqualExpression.h"
#include "ast/GreaterThanOrEqualExpression.h"
#include "ast/EqualExpression.h"
#include "ast/NotEqualExpression.h"

#include "ast/AssignmentExpression.h"
#include "ast/BitwiseAndAssignmentExpression.h"
#include "ast/BitwiseXorAssignmentExpression.h"
#include "ast/BitwiseOrAssignmentExpression.h"
#include "ast/BitwiseNotAssignmentExpression.h"
#include "ast/DivisionAssignmentExpression.h"
#include "ast/IntegerDivisionAssignmentExpression.h"
#include "ast/MinusAssignmentExpression.h"
#include "ast/ModuloAssignmentExpression.h"
#include "ast/PlusAssignmentExpression.h"
#include "ast/TimesAssignmentExpression.h"
#include "ast/SllAssignmentExpression.h"
#include "ast/SraAssignmentExpression.h"
#include "ast/SrlAssignmentExpression.h"
#include "ast/SpecialAssignmentExpression.h"

#include "ast/LiteralExpression.h"
#include "ast/LiteralIntegerExpression.h"
#include "ast/LiteralFloatExpression.h"
#include "ast/LiteralDoubleExpression.h"
#include "ast/LiteralBoolExpression.h"
#include "ast/LiteralCharExpression.h"
#include "ast/LiteralSymbolExpression.h"
#include "ast/LiteralStringExpression.h"

/* Types */
#include "ast/Type.h"
#include "ast/PrimitiveType.h"
#include "ast/PointerType.h"
#include "ast/IntType.h"

#include "ast/UIntType.h"
#include "ast/ShortType.h"
#include "ast/UShortType.h"
#include "ast/LongType.h"
#include "ast/ULongType.h"
#include "ast/CharType.h"
#include "ast/UCharType.h"
#include "ast/FloatType.h"
#include "ast/DoubleType.h"
#include "ast/VoidType.h"
#include "ast/SymbolType.h"
#include "ast/BoolType.h"
#include "ast/Int8Type.h"
#include "ast/Int16Type.h"
#include "ast/Int32Type.h"
#include "ast/Int64Type.h"
#include "ast/UInt8Type.h"
#include "ast/UInt16Type.h"
#include "ast/UInt32Type.h"
#include "ast/UInt64Type.h"

#endif
