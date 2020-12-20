cmake_minimum_required(VERSION 2.8)
project(hdc)

include_directories(include)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(TOKEN_SRC src/token/Token.cpp)
set(LEX_SRC src/lex/Lex.cpp)
set(PARSER_SRC src/parser/Parser.cpp)

set(AST_TYPES_SRC
    src/ast/types/Type.cpp
    src/ast/types/Int64Type.cpp
    src/ast/types/ShortType.cpp
    src/ast/types/UInt8Type.cpp
    src/ast/types/BoolType.cpp
    src/ast/types/SymbolType.cpp
    src/ast/types/UIntType.cpp
    src/ast/types/CharType.cpp
    src/ast/types/Int8Type.cpp
    src/ast/types/DoubleType.cpp
    src/ast/types/IntType.cpp
    src/ast/types/UCharType.cpp
    src/ast/types/ULongType.cpp
    src/ast/types/FloatType.cpp
    src/ast/types/LongType.cpp
    src/ast/types/UInt16Type.cpp
    src/ast/types/UShortType.cpp
    src/ast/types/Int16Type.cpp
    src/ast/types/PointerType.cpp
    src/ast/types/UInt32Type.cpp
    src/ast/types/VoidType.cpp
    src/ast/types/Int32Type.cpp
    src/ast/types/PrimitiveType.cpp
    src/ast/types/UInt64Type.cpp
    src/ast/types/NamedType.cpp
    src/ast/types/FunctionType.cpp
)

set(AST_SRC
    ${AST_TYPES_SRC}
    src/ast/ASTNode.cpp
    src/ast/Program.cpp
    src/ast/SourceFile.cpp
    src/ast/Import.cpp
    src/ast/Def.cpp
    src/ast/Class.cpp
    src/ast/Parameter.cpp
    src/ast/ListExpression.cpp
    src/ast/ArrayExpression.cpp
    src/ast/ForEachStatement.cpp
    src/ast/ForStatement.cpp
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
    src/ast/LiteralNullExpression.cpp
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
    src/ast/EqualExpression.cpp
    src/ast/NotEqualExpression.cpp
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
    src/ast/UnaryPlusExpression.cpp
    src/ast/Statement.cpp
    src/ast/CompoundStatement.cpp
    src/ast/Variable.cpp
    src/ast/LocalVariable.cpp
    src/ast/WhileStatement.cpp
    src/ast/IfStatement.cpp
    src/ast/ElifStatement.cpp
    src/ast/ElseStatement.cpp
    src/ast/ReturnStatement.cpp
    src/ast/ClassVariable.cpp
    src/ast/AtExpression.cpp
    src/ast/GlobalVariable.cpp
    src/ast/Struct.cpp
    src/ast/StructField.cpp
    src/ast/Constant.cpp
    src/ast/GlobalConstant.cpp
)

set(IR_SRC
    src/ir/IRProgram.cpp
    src/ir/IRSourceFile.cpp
    src/ir/IRFunction.cpp
    src/ir/instructions/IRLabelDef.cpp
    src/ir/instructions/IRGoto.cpp
    src/ir/instructions/IRIFz.cpp
    src/ir/instructions/IRLocalVar.cpp
    src/ir/instructions/IRUnaryInstruction.cpp
    src/ir/instructions/IRLoadConstant.cpp
    src/ir/instructions/IRStore.cpp
    src/ir/instructions/IRBinaryInstruction.cpp
    src/ir/instructions/IRAdd.cpp
    src/ir/instructions/IRMinus.cpp
    src/ir/values/IRValue.cpp
    src/ir/values/IRTemporary.cpp
    src/ir/values/IRLabel.cpp
    src/ir/values/IRConstant.cpp
)

set(TAC_SRC
    src/tac/TAC.cpp
    src/tac/TACAdd.cpp
)

set(GEN_SRC src/gen/x86_64/gen_x86_64.cpp)

set(VISITORS_SRC
    src/visitors/PrettyPrinter.cpp
    src/visitors/SymbolTableBuilderVisitor.cpp
    src/visitors/TypeCheckerVisitor.cpp
    src/visitors/CppPrinter.cpp
    src/visitors/TACBuilderVisitor.cpp
    src/visitors/TACPrettyPrinter.cpp
    src/visitors/ast/IRBuilderVisitor.cpp
    src/visitors/ir/IRPrettyPrinter.cpp
)

set(SYMTAB_SRC src/symtab/Symbol.cpp src/symtab/SymbolTable.cpp)
set(LOGGER_SRC src/logger/Log.cpp src/logger/Logger.cpp)
set(DRIVER_SRC src/driver/Driver.cpp)

set(SOURCES
    ${TOKEN_SRC}
    ${LEX_SRC}
    ${PARSER_SRC}
    ${AST_SRC}
    ${TAC_SRC}
    ${IR_SRC}
    ${GEN_SRC}
    ${SYMTAB_SRC}
    ${VISITORS_SRC}
    ${LOGGER_SRC}
    ${DRIVER_SRC}
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
