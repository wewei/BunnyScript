#include "AST/TypeDefineStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(TypeDefineStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(TypeDefineStatement)

#ifdef DEBUG
void TypeDefineStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("TypeDefineStatement:"));
    {
        m_type->Print(printer);
        m_typeName->Print(printer);
    }
    printer.EndNode();
}
#endif // DEBUG

