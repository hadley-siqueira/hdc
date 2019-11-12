cmake_minimum_required(VERSION 2.8)
project(hdc)

include_directories(include)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

set(TOKEN_SRC src/token/Token.cpp)
set(LEX_SRC src/lex/Lex.cpp)
set(PARSER_SRC src/parser/Parser.cpp)
set(AST_SRC src/ast/SourceFile.cpp src/ast/Import.cpp src/ast/Def.cpp src/ast/Class.cpp src/ast/Parameter.cpp

    src/ast/AddressOfExpression.cpp
    src/ast/BitwiseXorAssignmentExpression.cpp
    src/ast/GreaterThanOrEqualExpression.cpp
    src/ast/LiteralExpression.cpp
    src/ast/ModuloExpression.cpp
    src/ast/SizeOfExpression.cpp
    src/ast/ArrowExpression.cpp
    src/ast/BitwiseXorExpression.cpp
    src/ast/IdentifierExpression.cpp
    src/ast/LiteralFloatExpression.cpp
    src/ast/ParenthesisExpression.cpp
    src/ast/SllAssignmentExpression.cpp
    src/ast/AssignmentExpression.cpp
    src/ast/CallExpression.cpp
    src/ast/IndexExpression.cpp
    src/ast/LiteralIntegerExpression.cpp
    src/ast/PlusAssignmentExpression.cpp
    src/ast/SpecialAssignmentExpression.cpp
    src/ast/BinaryOperator.cpp
    src/ast/DereferenceExpression.cpp
    src/ast/IntegerDivisionAssignmentExpression.cpp
    src/ast/LiteralOPERExpression.cpp
    src/ast/PlusExpression.cpp
    src/ast/SraAssignmentExpression.cpp
    src/ast/BitwiseAndAssignmentExpression.cpp
    src/ast/DivisionAssignmentExpression.cpp
    src/ast/IntegerDivisionExpression.cpp
    src/ast/LiteralStringExpression.cpp
    src/ast/PreDecrementExpression.cpp
    src/ast/SrlAssignmentExpression.cpp
    src/ast/BitwiseAndExpression.cpp
    src/ast/DivisionExpression.cpp
    src/ast/LessThanExpression.cpp
    src/ast/LiteralSymbolExpression.cpp
    src/ast/PreIncrementExpression.cpp
    src/ast/TimesAssignmentExpression.cpp
    src/ast/BitwiseNotAssignmentExpression.cpp
    src/ast/DolarExpression.cpp
    src/ast/LessThanOrEqualExpression.cpp
    src/ast/LogicalNotExpression.cpp
    src/ast/ShiftLeftLogicalExpression.cpp
    src/ast/TimesExpression.cpp
    src/ast/BitwiseNotExpression.cpp
    src/ast/DotExpression.cpp
    src/ast/LiteralBoolExpression.cpp
    src/ast/MinusAssignmentExpression.cpp
    src/ast/ShiftRightArithmeticExpression.cpp
    src/ast/UnaryMinusExpression.cpp
    src/ast/BitwiseOrAssignmentExpression.cpp
    src/ast/Expression.cpp
    src/ast/LiteralCharExpression.cpp
    src/ast/MinusExpression.cpp
    src/ast/ShiftRightLogicalExpression.cpp
    src/ast/UnaryOperator.cpp
    src/ast/BitwiseOrExpression.cpp
    src/ast/GreaterThanExpression.cpp
    src/ast/LiteralDoubleExpression.cpp
    src/ast/ModuloAssignmentExpression.cpp
    src/ast/SizeofExpression.cpp
    src/ast/UnaryPlusExpression.cpp
    src/ast/BoolType.cpp
    src/ast/SymbolType.cpp
    src/ast/UIntType.cpp
    src/ast/CharType.cpp
    src/ast/Int8Type.cpp
    src/ast/Type.cpp
    src/ast/DoubleType.cpp
    src/ast/IntType.cpp
    src/ast/UCharType.cpp
    src/ast/ULongType.cpp
    src/ast/FloatType.cpp
    src/ast/LongType.cpp
    src/ast/UInt16Type.cpp
    src/ast/UShortType.cpp
    src/ast/Int16Type.cpp
    src/ast/PointerType.cpp
    src/ast/UInt32Type.cpp
    src/ast/VoidType.cpp
    src/ast/Int32Type.cpp
    src/ast/PrimitiveType.cpp
    src/ast/UInt64Type.cpp
    src/ast/Int64Type.cpp
    src/ast/ShortType.cpp
    src/ast/UInt8Type.cpp
    src/ast/Statement.cpp
    src/ast/CompoundStatement.cpp
    src/ast/WhileStatement.cpp
)

set(SOURCES ${TOKEN_SRC} ${LEX_SRC} ${PARSER_SRC} ${AST_SRC} src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
