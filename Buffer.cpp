#include <iostream>
#include <sstream>
#include "Buffer.h"

using namespace std;

Buffer::Buffer(int linhas, int colunas) : linhas(linhas), colunas(colunas), cursorColuna(0), cursorLinha(0){
    grelha = new char*[linhas];
    for (int i = 0; i < linhas; ++i) {
        grelha[i] = new char[colunas];
    }
    for (int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            grelha[i][j] = ' ';
        }
    }
}

bool Buffer::validaPosicao(int linha, int coluna)const{
    if(linha < 0 || coluna < 0|| linha >= linhas || coluna >= colunas){
        cout << "Posicao invalida" << endl;
        return false;
    }
    return true;
}

void Buffer::clear() {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            grelha[i][j] = ' ';
        }
    }
}

void Buffer::moveCursor(int linha, int coluna) {
    if(validaPosicao(linha, coluna)) {
        cursorColuna = coluna;
        cursorLinha = linha;
    }
}

void Buffer::escreveChar(char c) {
    if(validaPosicao(cursorLinha, cursorColuna)) {
        grelha[cursorLinha][cursorColuna] = c;
        cursorColuna++;
        if (cursorColuna >= colunas) {
            cursorColuna = 0;
            cursorLinha++;
            if (cursorLinha >= linhas) {
                cursorLinha = 0;
            }
        }
    }
}

void Buffer::escreveInt(int x) {
    char aux = x;
    escreveChar(aux);
}

void Buffer::print() const {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            cout << grelha[i][j];
        }
        cout << "\n";
    }
}

string Buffer::getConteudoBuffer() const{
    string aux;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            aux += grelha[i][j];
            aux += "\t";
        }
        aux += "\n";
    }
    return aux;
}

ostream& operator<<(ostream& os, const Buffer b) {
    os << b.getConteudoBuffer();
    return os;
}

Buffer::~Buffer() {
    for(int i = 0; i < linhas; i++) {
        delete[] grelha[i];
    }
    delete[] grelha;
}