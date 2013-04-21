#include "AST/DeclarationStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(DeclarationStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(DeclarationStatement)

#ifdef DEBUG
void DeclarationStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("DeclarationStatement:"));
    m_type->Print(printer);
    m_varName->Print(printer);
    if (m_initValue)
        m_initValue->Print(printer);
    printer.EndNode();
}
#endif // DEBUG

