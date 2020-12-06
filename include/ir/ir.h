#include "ir/IR.h"

#include "ir/IRProgram.h"
#include "ir/IRSourceFile.h"
#include "ir/IRFunction.h"

// instructions
#include "ir/instructions/IRInstruction.h"
#include "ir/instructions/IRLabelDef.h"
#include "ir/instructions/IRGoto.h"
#include "ir/instructions/IRIFz.h"

#include "ir/instructions/IRUnaryInstruction.h"
#include "ir/instructions/IRLoadConstant.h"

#include "ir/instructions/IRBinaryInstruction.h"
#include "ir/instructions/IRAdd.h"
#include "ir/instructions/IRMinus.h"

// values
#include "ir/values/IRValue.h"
#include "ir/values/IRTemporary.h"
#include "ir/values/IRLabel.h"
#include "ir/values/IRConstant.h"
