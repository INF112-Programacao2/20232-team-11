#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

class Interface{
private:
    void executar_opcao(int opcao);
public:
    void menu_principal();
    void menu_cadastro();
    void menu_login();
    void menu_administrador();
    void menu_professor();
    void menu_aluno();
    void menu_evento();
    void menu_pesquisa();
    void menu_edicao();
    void menu_exclusao();
    void menu_listagem();
    void menu_listagem_data();

};

#endif