#pragma once

#include "ShortCut.h"
#include "Node.h"

namespace Bunny {
    namespace AST {
        class Name;
        DEFINE_PTRS(Name)

        class Name : public Node {

        const SPNameC &Subname() { return m_subname; }
        const SPStringC &StringValue() { return m_strValue; }
        private:
            SPNameC m_subname;
            SPStringC m_strValue; 
        };
    }
}
