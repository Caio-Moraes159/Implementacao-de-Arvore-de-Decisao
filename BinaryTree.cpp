//SALA: 4°A
/*ALUNOS:
Caio Caminitti de Moraes - 2146079
Leonardo Ferreira Colmanetti de Almeida Lima - 2131526*/

#include "BinaryTree.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Função Construtora
BinaryTree::BinaryTree(){
//Pós-condição: a árvore é criada e iniciada como vazia.
    root = NULL;
}

void BinaryTree::Insert(string chave_pai, string chave_filhoEsquerdo, string chave_filhoDireito){
// Pré-condição: A árvore deve ser inicializada corretamente.
// Pós-condição: A árvore é modificada para incluir os novos nós conforme as chaves fornecidas.

    if (root == NULL) {
        root = new TreeNode;
        if (root == NULL)
        {
            cout << "Memoria cheia!" << endl;
            return;
        }
        root->Entry = chave_pai;
        root->LeftNode = root->RightNode = NULL;
    }

    if(chave_pai == "X") return;

    Insert(root, chave_pai, chave_filhoEsquerdo, chave_filhoDireito);
}

void BinaryTree::Insert(TreePointer &p ,string chave_pai, string chave_filhoEsquerdo,string chave_filhoDireito){
// Pré-condição: A árvore deve estar inicializada.
// Pós-condição: Os nós filho são inseridos no nó pai conforme as chaves fornecidas.

    if(p == NULL) return;
    
    if (p->Entry == chave_pai) {
        // Inserimos os filhos no nó pai encontrado
        p->LeftNode = new TreeNode;
        p->LeftNode->Entry = chave_filhoEsquerdo;
        p->LeftNode->LeftNode = NULL;
        p->LeftNode->RightNode = NULL;

        p->RightNode = new TreeNode;
        p->RightNode->Entry = chave_filhoDireito;
        p->RightNode->LeftNode = NULL;
        p->RightNode->RightNode = NULL;
    } else {
        // Continuamos a busca na subárvore esquerda e direita
        Insert(p->LeftNode, chave_pai, chave_filhoEsquerdo, chave_filhoDireito);
        Insert(p->RightNode, chave_pai, chave_filhoEsquerdo, chave_filhoDireito);
    }
}

int BinaryTree::Nodes(){
// Pré-condição: A árvore deve estar inicializada.
// Pós-condição: Retorna o número de nós na árvore.

    return Nodes(root);
}

int BinaryTree::Nodes(TreePointer r){
    if(r->Entry == "X") return 0;

    return 1 + Nodes(r->LeftNode) + Nodes(r->RightNode);
}

//Função que imprime a árvore na tela
void BinaryTree::Print(){
// Pré-condição: A árvore deve estar inicializada.
// Pós-condição: A árvore é impressa em ordem.

    Print(root, 0);
}

void BinaryTree::Print(TreePointer &r, int s){ 

    if (r != NULL)
    {
        Print(r->RightNode, s+3);
        for (int i = 1 ; i <= s ; i++)
            cout << " ";
        cout << setw(6) << r->Entry << endl;
        Print(r->LeftNode, s+3);
    }
}

int BinaryTree::Leaves()
{ 
// Pré-condição: A árvore deve estar inicializada.
// Pós-condição: Retorna o número de folhas na árvore.
    return Leaves(root);
}

int BinaryTree::Leaves(TreePointer &t)
{   
    if(t->Entry == "X"){
        return 0;
    } else if(t->LeftNode->Entry == "X" && t->RightNode->Entry == "X"){
        return 1;
    } else {
    return Leaves(t->LeftNode) + Leaves(t->RightNode);
    }
}

void BinaryTree::ExibeInf(){
// Pré-condição: A árvore deve estar inicializada.
// Pós-condição: Exibe informações sobre cada nó na árvore.
    ExibeInf(root);
}

void BinaryTree::ExibeInf(TreePointer p){
    if(p->Entry == "X") return;

    cout << p->Entry <<" ";
    if (p->LeftNode->Entry != "X" && p->RightNode->Entry != "X")
    {
        cout << "2" << " " << "ED";
    } else if(p->LeftNode->Entry != "X" || p->RightNode->Entry != "X") {
        cout << "1" << " ";
        if (p->LeftNode->Entry != "X")
        {
            cout << "E";
        } else {
            cout << "D";
        }
        
    } else {
        cout << "0" << " " << "F";
    }

    cout << endl;
    ExibeInf(p->LeftNode);
    ExibeInf(p->RightNode);
}