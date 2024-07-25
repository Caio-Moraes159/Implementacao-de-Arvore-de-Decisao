//SALA: 4°A
/*ALUNOS:
Caio Caminitti de Moraes - 2146079
Leonardo Ferreira Colmanetti de Almeida Lima - 2131526*/

#ifndef BINARY_TREE
#define BINARY_TREE
#include <string>
using namespace std;

class BinaryTree{
    public:
    BinaryTree();
    //~BinaryTree();
    void Insert(string chave_pai, string chave_filhoEsquerdo, string chave_filhoDireito);
    int Nodes();
    int Leaves();
    void Print();
    void ExibeInf();


    private:
    struct TreeNode{
        string Entry;
        TreeNode* LeftNode;
        TreeNode* RightNode;
    };
    typedef TreeNode* TreePointer;
    TreePointer root;
    void Insert(TreePointer &r, string chave_pai, string chave_filhoEsquerdo, string chave_filhoDireito);
    int Nodes(TreePointer r);
    int Leaves(TreePointer &t);
    void Print(TreePointer &r, int s);
    void Search(TreePointer &r, string chave_pai, TreePointer &resultado);
    void ExibeInf(TreePointer p);
};
#endif