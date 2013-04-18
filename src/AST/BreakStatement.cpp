#include "AST/BreakStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(BreakStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(BreakStatement)

void BreakStatement::Print(TreePrinter &printer) const
{
    printer.AddLeafNode(String("BreakStatement"));
}

