#include "AST/VariableDefineStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(VariableDefineStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(VariableDefineStatement)

#ifdef DEBUG
void VariableDefineStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("VariableDefineStatement:"));
    m_type->Print(printer);
    m_varName->Print(printer);
    if (m_initValue)
        m_initValue->Print(printer);
    printer.EndNode();
}
#endif // DEBUG

