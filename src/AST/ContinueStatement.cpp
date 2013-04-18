#include "AST/ContinueStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(ContinueStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(ContinueStatement)

void ContinueStatement::Print(TreePrinter &printer) const
{
    printer.AddLeafNode(String("ContinueStatement"));
}

