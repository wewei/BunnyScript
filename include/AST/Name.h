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

            Name(const SPStringC &strValue, const SPNameC &subname)
                : m_strValue(strValue)
                , m_subname(subname)
            { }


            const SPStringC &StringValue() const { return m_strValue; }
            const SPNameC &Subname() const { return m_subname; }

        private:
            SPNameC m_subname;
            SPStringC m_strValue; 
        };
    }
}

