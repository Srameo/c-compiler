#include "./VarNode.h"
#include "./OperatorNode.h"

AST::DefineVarNode::DefineVarNode() : BaseNode(AST::def_var) {
    this->symbol_type = SMB::SymbolType::none;
}

// AST::DefineVarNode::DefineVarNode(std::string content, BaseNode *child)
// : BaseNode(content, AST::def_var) {
//     this->symbol_type = SMB::SymbolType::none;
//     this->addChildNode(child);
// }

AST::DefineVarNode::DefineVarNode(std::string content, std::string struct_name)
: BaseNode(content, AST::def_var) {
    this->symbol_type = SMB::SymbolType::struct_type;
    this->struct_name = struct_name;
}

AST::DefineVarNode::DefineVarNode(std::string content) : BaseNode(content, AST::def_var) {
    this->symbol_type = SMB::SymbolType::none;
}

void AST::DefineVarNode::printInfo(int) {
    if (this->symbol_type == SMB::SymbolType::array) {
        std::cout << "array defination: " << this-> content << "length: " << this->array_length;
    } else {
        std::cout << "variable defination: " << this->content;
    }
}

void AST::DefineVarNode::setAllSymbolType(std::string symbol_type) {
    SMB::SymbolType var_type;
    if (symbol_type == "int") {
        var_type = SMB::SymbolType::integer;
    } else if (symbol_type == "void") {
        var_type = SMB::SymbolType::void_type;
    } else if (symbol_type == "int ptr") {
        var_type = SMB::SymbolType::pointer;
    } else if (symbol_type == "struct") {
        var_type = SMB::SymbolType::struct_type;
    } else if (symbol_type == "array") {
        var_type = SMB::SymbolType::array;
    }
    if (this->symbol_type == SMB::SymbolType::none) {
        // std::cout<<var_type<<std::endl;
        this->symbol_type = var_type;
    }
    BaseNode *cousin = this->getCousinNode();
    if (!cousin) return;
    if (cousin->getASTNodeType() == AST::op) {
        OperatorNode* tmp = (OperatorNode*) cousin;
        tmp->setAllSymbolType(symbol_type);
    } else if (cousin->getASTNodeType() == AST::def_var) {
        DefineVarNode* tmp = (DefineVarNode*) cousin;
        tmp->setAllSymbolType(symbol_type);
    }
    // while (cousin != NULL) {
    //     if (cousin->symbol_type == SMB::SymbolType::none) {
    //         cousin->symbol_type = var_type;
    //     }
    //     cousin = (DefineVarNode *)cousin->getCousinNode();
    // }
}

void AST::DefineVarNode::setArrayLength(std::string length) {
    this->array_length = atoi(length.c_str());
}

AST::AssignVarNode::AssignVarNode() : BaseNode(AST::assign_var) {}

AST::AssignVarNode::AssignVarNode(std::string content) : BaseNode(content, AST::assign_var) {}

void AST::AssignVarNode::printInfo(int) {
    std::cout << "variable: " << this->content;
}
