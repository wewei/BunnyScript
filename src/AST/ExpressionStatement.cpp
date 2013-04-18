#include "AST/ExpressionStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(ExpressionStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(ExpressionStatement)

void ExpressionStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("ExpressionStatement"));
    {
        m_expr->Print(printer);
    }
    printer.EndNode();
}

