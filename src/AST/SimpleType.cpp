#include <sstream>
#include "AST/SimpleType.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(SimpleType)

AST_NODE_DEFINE_DUMMY_GenerateCode(SimpleType)

#ifdef DEBUG

void SimpleType::Print(TreePrinter &printer) const
{
    printer.StartNode(String("SimpleType:"));
    if (m_nmspace)
        m_nmspace->Print(printer);
    if (m_name)
        m_name->Print(printer);
    printer.EndNode();
}
#endif // DEBUG

