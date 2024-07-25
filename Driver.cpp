//SALA: 4°A
/*ALUNOS:
Caio Caminitti de Moraes - 2146079
Leonardo Ferreira Colmanetti de Almeida Lima - 2131526*/

#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
BinaryTree tree;
//Lê o arquivo e insere as variáveis na árvore binária 
ifstream saidaArq("exemplo1.tree" , ios::in);
string chave1_pai, chave2_filhoEsq, chave3_FilhoDir;

    while (saidaArq >> chave1_pai >> chave2_filhoEsq >> chave3_FilhoDir)
    {
        tree.Insert(chave1_pai, chave2_filhoEsq, chave3_FilhoDir);
    }

//tree.Print();

cout << endl << "|---------------------------------------|" << endl;

tree.ExibeInf();
cout << tree.Nodes() << " " << tree.Leaves();
}