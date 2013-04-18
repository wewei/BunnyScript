#include "AST/WhileStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(WhileStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(WhileStatement)

void WhileStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("WhileStatement"));
    {
        m_exprCondition->Print(printer);
        m_loopBody->Print(printer);
    }
    printer.EndNode();
}

