#include "AST/ReturnStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(ReturnStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(ReturnStatement)

#ifdef DEBUG
void ReturnStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("ReturnStatement:"));
    if (m_exprReturn)
        m_exprReturn->Print(printer);
    printer.EndNode();
}
#endif // DEBUG

