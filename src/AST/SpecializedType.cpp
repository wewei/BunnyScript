#include "AST/SpecializedType.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(SpecializedType)

AST_NODE_DEFINE_DUMMY_GenerateCode(SpecializedType)

#ifdef DEBUG

void SpecializedType::Print(TreePrinter &printer) const
{
    printer.StartNode(String("SpecializedType:"));
    m_genericType->Print(printer);
    if (m_typeList)
        m_typeList->Print(printer);
    printer.EndNode();
}

#endif // DEBUG

