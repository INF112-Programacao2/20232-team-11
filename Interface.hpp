#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

// Declaração avançada para evitar dependências cíclicas
class Aluno;
class Professor;
class Administrador;

class Interface{
private:
    bool administradorCadastrado = false;
    void executar_opcao(int opcao);
    void recuperar_senha(Aluno& aluno, Professor& professor, Administrador& administrador);
    void realizar_login(Aluno& aluno, Professor& professor , Administrador& administrador);
    Administrador cadastrar_administrador();
    Professor cadastrar_professor();
    Aluno cadastrar_aluno();
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
    void cadastrar_usuario();
    

};

#endif