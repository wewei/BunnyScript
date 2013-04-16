#include <sstream>

#include "AST/Name.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(Name)

AST_NODE_DEFINE_DUMMY_GenerateCode(Name)

#ifdef DEBUG

void Name::Print(TreePrinter &printer) const
{
    std::ostringstream sstm;
    sstm << "Name(" << *m_strValue << ")";
    printer.StartNode(sstm.str());
    if (m_subname) {
        m_subname->Print(printer);
    }
    printer.EndNode();
}

#endif // DEBUG

