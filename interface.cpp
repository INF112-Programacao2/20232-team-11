#include "Interface.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Adminitrador.hpp"
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
            realizar_login;
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

void Interface::menu_administrador(std::vector<Aluno>& alunos, std::vector<Professor>& professores) {
    int escolha;
    do {
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1 - Cadastrar Professor" << std::endl;
        std::cout << "2 - Cadastrar Aluno" << std::endl;
        std::cout << "3 - Excluir Professor" << std::endl;
        std::cout << "4 - Excluir Aluno" << std::endl;
        std::cout << "5 - Voltar" << std::endl;

        std::cout << "Opcao: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                // Chamar a função para cadastrar professor
                cadastrar_professor();
                break;

            case 2:
                // Chamar a função para cadastrar aluno
                cadastrar_aluno();
                break;

            case 3:
                excluir_professor(professores);
                break;
            case 4:
                excluir_aluno(alunos);
                break;
            case 5:
                // Opção para voltar
                std::cout << "Voltando ao menu principal." << std::endl;
                break;

            default:
                // Mensagem de erro para opções inválidas
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                break;
        }

    } while (escolha != 5); // Continue o loop até que a opção 5 (Voltar) seja escolhida
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

void Interface::realizar_login(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores) {
    std::string id, senha;

    std::cout << "Informe o ID: ";
    std::cin >> id;

    std::cout << "Informe a senha: ";
    std::cin >> senha;

    // Verifique o login para Aluno
    if (aluno.fazer_login(id, senha)) {
        std::cout << "Login bem-sucedido para o aluno " << aluno.get_id() << std::endl;
        menu_aluno();
        return;
    }

    // Verifique o login para Professor
    if (professor.fazer_login(id, senha)) {
        std::cout << "Login bem-sucedido para o professor " << professor.get_id() << std::endl;
        menu_professor();
        return;
    }

    // Verifique o login para Administrador
    if (administrador.fazer_login(id, senha)) {
        std::cout << "Login bem-sucedido para o adminstrador " << professor.get_id() << std::endl;
        menu_administrador(alunos , professores);
        return;
    }

    // Se chegou aqui, o login falhou
    std::cout << "Credenciais de login inválidas." << std::endl;
    char resposta;
    std::cout << "Esqueceu sua senha ?" << std::endl;
    std::cout << "Digite (s) para sim , caso contrario sera direcionado ao menu principal ?" << std::endl;
    if(resposta == 's' || resposta == 'S'){
        recuperar_senha(aluno, professor ,administrador);
    }
    else {
        menu_principal();
    }

}

void recuperar_senha(Aluno& aluno, Professor& professor, Administrador& administrador) {
    // Implemente a lógica para recuperar a senha
    std::string novo_id, nova_senha;

    std::cout << "Informe o ID novamente: ";
    std::cin >> novo_id;

    // Modifique para solicitar a nova senha de uma maneira segura, como via e-mail ou outro meio seguro
    std::cout << "Informe a nova senha: ";
    std::cin >> nova_senha;

    // Encontre o usuário correspondente e altere a senha
    if (aluno.get_id() == novo_id) {
        aluno.alterar_senha(nova_senha);
        std::cout << "Senha alterada com sucesso para o aluno " << aluno.get_id() << std::endl;
    } else if (professor.get_id() == novo_id) {
        professor.alterar_senha(nova_senha);
        std::cout << "Senha alterada com sucesso para o professor " << professor.get_id() << std::endl;
    } else if (administrador.get_id() == novo_id) {
        administrador.alterar_senha(nova_senha);
        std::cout << "Senha alterada com sucesso para o administrador " << administrador.get_id() << std::endl;
    } else {
        std::cout << "Usuário não encontrado. Operação de recuperação de senha cancelada." << std::endl;
    }
}


void Interface::cadastrar_usuario() {
    int opcao;
    std::cout << "Escolha uma opção de cadastro:" << std::endl;
    std::cout << "1 - Administrador" << std::endl;
    std::cout << "2 - Professor" << std::endl;
    std::cout << "3 - Aluno" << std::endl;
    std::cout << "4 - Voltar" << std::endl;

    std::cout << "Opção: ";
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            if (administradorCadastrado) {
                cadastrar_administrador();
            } else {
                std::cout << "Já existe um administrador cadastrado." << std::endl;
            }
            break;
        case 2:
            cadastrar_professor();
            break;
        case 3:
            cadastrar_aluno();
            break;
        case 4:
            menu_principal();
            break;
        default:
            std::cout << "Opção inválida." << std::endl;
            break;
    }
}

Administrador Interface::cadastrar_administrador() {
    std::string id, senha , nome ;

    std::cout << "Informe o ID do administrador: ";
    std::cin >> id;

    std::cout << "Informe a senha do administrador: ";
    std::cin >> senha;

    std::cout << "Informe o nome do administrador: ";
    std::cin >> nome;

    // Criar uma nova instância de Administrador
    Administrador novo_administrador(nome, id, senha);

    // Retornar o novo objeto Administrador
    return novo_administrador;
}

Professor Interface::cadastrar_professor() {
    std::string id, senha , nome;

    std::cout << "Informe o ID do professor: ";
    std::cin >> id;

    std::cout << "Informe a senha do professor: ";
    std::cin >> senha;

    std::cout << "Informe o nome do professor: ";
    std::cin >> nome;

    // Criar uma nova instância de Professor
    Professor novo_professor(nome , id, senha);

    // Definir a flag como true
    administradorCadastrado = true;

    // Retornar o novo objeto Professor
    return novo_professor;
}

Aluno Interface::cadastrar_aluno() {
    std::string id, senha, matricula , nome;

    std::cout << "Informe o ID do aluno: ";
    std::cin >> id;

    std::cout << "Informe a senha do aluno: ";
    std::cin >> senha;

    std::cout << "Informe a matrícula do aluno: ";
    std::cin >> matricula;
    
    std::cout << "Informe o nome do aluno: ";
    std::cin >> nome;

    // Criar uma nova instância de Aluno
    Aluno novoAluno(nome, id, senha, matricula);

    // Retornar o novo objeto Aluno
    return novoAluno;
}

void Interface::excluir_professor(std::vector<Professor>& professores) {
    std::string id_prof;
    std::cout << "Digite o ID do professor a ser excluído: ";
    std::cin >> id_prof;

    auto it = std::remove_if(professores.begin(), professores.end(),
                             [id_prof](const Professor& professor) { return professor.get_id() == id_prof; });

    if (it != professores.end()) {
        professores.erase(it, professores.end());
        std::cout << "Professor excluído com sucesso." << std::endl;
    } else {
        std::cout << "Professor não encontrado." << std::endl;
    }
}

void Interface::excluir_aluno(std::vector<Aluno>& alunos) {
    std::string id_aluno;
    std::cout << "Digite o ID do aluno a ser excluído: ";
    std::cin >> id_aluno;

    auto it = std::remove_if(alunos.begin(), alunos.end(),
                             [id_aluno](const Aluno& aluno) { return aluno.get_id() == id_aluno; });

    if (it != alunos.end()) {
        alunos.erase(it, alunos.end());
        std::cout << "Aluno excluído com sucesso." << std::endl;
    } else {
        std::cout << "Aluno não encontrado." << std::endl;
    }
}