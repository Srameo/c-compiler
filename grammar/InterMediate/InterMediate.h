#if !defined(_INTERMEDIATE_H_)
#define _INTERMEDIATE_H_

#include "../Nodes.h"
#include "./Quaternion.h"
#include <stack>
#include <list>

namespace IM {

class InterMediate
{
private:
    AST::BaseNode *root;
    std::vector<Quaternion> quads;
    std::vector<SMB::Symbol*> temp_vars;
    // FuncTable funcTable;
    SMB::SymbolTable *root_symbol_table;

    std::stack< std::list<int> > true_list;
    std::stack< std::list<int> > false_list;
    std::stack<int> signal;
    std::stack<SMB::Symbol*> child_value;
    // Function for backPatch.
    std::list<int> *makeList(int index);
    std::list<int> *merge(std::list<int> *list1, std::list<int> *list2);
    void backPatch(std::list<int> *backList, int target);

public:
    inline AST::BaseNode *getRoot() { return this->root; }
    inline SMB::SymbolTable *getTable() { return this->root_symbol_table; }
    // inline FuncTable &getFuncTable() { return this->funcTable; }
    inline std::vector<Quaternion> &getQuads() { return this->quads; }
    inline std::vector<SMB::Symbol*> &getTempVars() { return this->temp_vars; }
    InterMediate(AST::BaseNode *rootNode, SMB::StructTable*);
    void generate(AST::BaseNode *node, SMB::SymbolTable*);
    // Create a child symbol table to generate follow code.
    SMB::SymbolTable *generateStatement(AST::StatementNode*, SMB::SymbolTable*);
    SMB::SymbolTable *generateReturn(AST::StatementNode*, SMB::SymbolTable*);
    SMB::Symbol *generateOperator(AST::OperatorNode*, SMB::SymbolTable*);
    Quaternion *caculateOperator(OperatorCode, AST::BaseNode*, AST::BaseNode*, SMB::Symbol*, SMB::SymbolTable*);
    void relopOperator(Quaternion*, Quaternion*, OperatorCode, AST::BaseNode*, AST::BaseNode*, SMB::SymbolTable*);
    void print();
};

} // namespace IM


#endif