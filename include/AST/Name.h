#pragma once

#include "ShortCut.h"
#include "Node.h"

namespace Bunny {
    namespace AST {
        class Name;
        DEFINE_PTRS(Name)

        class Name : public Node {
        public:
            AST_CONCRETE_NODE_HEADER(Name)

            Name(const SPStringC &strValue)
                : m_strValue(strValue)
                { }

            const SPStringC &StringValue() const { return m_strValue; }

        private:
            SPStringC m_strValue; 
        };
    }
}

