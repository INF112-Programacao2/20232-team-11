#include "Interface.hpp"
#include <iostream>

void Interface::executar_opcao(int opcao){
    menu_principal();
    std::cout << std::endl;
    switch(opcao){
        case 1:
            std::cout << "Cadastrar" << std::endl;
            menu_cadastro();
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Login" << std::endl;
            break;
        case 3:
            std::cout << "Sair" << std::endl;
            break;
        default:
            std::cout << "Opcao invalida" << std::endl;
            break;
    }
}



void Interface::menu_principal()
{
    std::cout << "Bem vindo ao Calendario Academico!" << std::endl;
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Cadastrar" << std::endl;
    std::cout << "2 - Login" << std::endl;
    std::cout << "3 - Sair" << std::endl;
}

void Interface::menu_cadastro(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Administrador" << std::endl;
    std::cout << "2 - Professor" << std::endl;
    std::cout << "3 - Aluno" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
}

void Interface::menu_login(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Administrador" << std::endl;
    std::cout << "2 - Professor" << std::endl;
    std::cout << "3 - Aluno" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
}

void Interface::menu_administrador(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Cadastrar Professor" << std::endl;
    std::cout << "2 - Cadastrar Aluno" << std::endl;
    std::cout << "3 - Excluir Professor" << std::endl;
    std::cout << "4 - Excluir Aluno" << std::endl;
    std::cout << "5 - Voltar" << std::endl;
}

void Interface::menu_professor(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Cadastrar Evento" << std::endl;
    std::cout << "2 - Editar Evento" << std::endl;
    std::cout << "3 - Excluir Evento" << std::endl;
    std::cout << "4 - Pesquisar Evento" << std::endl;
    std::cout << "5 - Listar Eventos" << std::endl;
    std::cout << "6 - Voltar" << std::endl;
}

void Interface::menu_aluno(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Cadastrar Evento" << std::endl;
    std::cout << "2 - Pesquisar Evento" << std::endl;
    std::cout << "3 - Listar Eventos" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
}

void Interface::menu_evento(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Titulo" << std::endl;
    std::cout << "2 - Data" << std::endl;
    std::cout << "3 - Voltar" << std::endl;
}

void Interface::menu_pesquisa(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Titulo" << std::endl;
    std::cout << "2 - Data" << std::endl;
    std::cout << "3 - Voltar" << std::endl;
}

void Interface::menu_edicao(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Titulo" << std::endl;
    std::cout << "2 - Data" << std::endl;
    std::cout << "3 - Voltar" << std::endl;
}

void Interface::menu_exclusao(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Titulo" << std::endl;
    std::cout << "2 - Data" << std::endl;
    std::cout << "3 - Voltar" << std::endl;
}

void Interface::menu_listagem(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Listar Todos" << std::endl;
    std::cout << "2 - Listar por Data" << std::endl;
    std::cout << "3 - Listar por Titulo" << std::endl;
    std::cout << "4 - Voltar" << std::endl;
}

void Interface::menu_listagem_data(){
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Listar por Data" << std::endl;
    std::cout << "2 - Voltar" << std::endl;
}

