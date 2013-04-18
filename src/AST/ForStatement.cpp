#include "AST/ForStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(ForStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(ForStatement)

void ForStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("ForStatement"));
    {
        m_element->Print(printer);
        m_exprCollection->Print(printer);
        m_loopBody->Print(printer);
    }
    printer.EndNode();
}

