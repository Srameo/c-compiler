#if !defined(_FUNCNODE_H_)
#define _FUNCNODE_H_

#include "./BaseNode.h"
#include "../symbol/SymbolType.h"
#include <string>

namespace AST {
    
    class DefineFuncNode: public BaseNode {
    private:
        BaseNode* arg_list; // 参数列表
        SMB::SymbolType return_symbol_type; // 返回值symbol类型
    public:
        DefineFuncNode();
        DefineFuncNode(std::string);
        DefineFuncNode(std::string, BaseNode*);
        inline BaseNode* getArgList() { return this->arg_list; }
        inline SMB::SymbolType getReturnSymbolType(){ return this->return_symbol_type; }
        void setReturnSymbolType(std::string);
        void printInfo(int);
        ~DefineFuncNode();
    };

    class CallFuncNode: public BaseNode {
    private:
        BaseNode *var_list; // 参数列表
    public:
        CallFuncNode();
        CallFuncNode(std::string);
        inline void setVarList(BaseNode *v) {this->var_list = v; v->setParentNode(this);}
        inline BaseNode* getVarList() {return this->var_list;}
        void printInfo(int);
        ~CallFuncNode();
    };

} // namespace AST


#endif // _FUNCNODE_H_
