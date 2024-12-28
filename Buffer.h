#include <string>
#include <iostream>
#include <sstream>


#ifndef BUFFER_H
#define BUFFER_H

using namespace std;

class Buffer {
public:
    Buffer(int linhas, int colunas);
    ~Buffer();

    void clear();
    void moveCursor(int linha, int coluna);
    void escreveChar(char c);
    void escreveInt(int x);
    void print()const;
    string getConteudoBuffer()const;

private:
    int cursorLinha, cursorColuna, linhas, colunas;
    char **grelha;


    bool validaPosicao(int linha, int coluna)const;
};

ostream& operator<<(ostream& os, Buffer b);

#endif //BUFFER_H
