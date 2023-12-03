#include "Interface.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Adminitrador.hpp"
#include "Calendario.hpp"
#include <iostream>

void Interface::menu_principal(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores) {
    std::cout << "Bem vindo ao Calendario Academico!" << std::endl;
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1 - Cadastrar" << std::endl;
    std::cout << "2 - Login" << std::endl;
    std::cout << "3 - Sair" << std::endl;
    std::cout << std::endl;

    int opcao;
    std::cout << "Digite sua opcao: ";
    std::cin >> opcao;

    switch(opcao) {
        case 1:
            std::cout << "Cadastrar" << std::endl;
            cadastrar_usuario(aluno, professor, administrador, alunos, professores);
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Login" << std::endl;
            realizar_login(aluno, professor, administrador, alunos, professores);
            break;
        case 3:
            std::cout << "Sair" << std::endl;
            break;
        default:
            std::cout << "Opcao invalida" << std::endl;
            break;
    }
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

void Interface::menu_professor( Professor& professor){
// Exiba as opções do menu
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "1 - Cadastrar Evento" << std::endl;
    std::cout << "2 - Editar Evento" << std::endl;
    std::cout << "3 - Excluir Evento" << std::endl;
    std::cout << "4 - Pesquisar Evento" << std::endl;
    std::cout << "5 - Listar Eventos" << std::endl;
    std::cout << "6 - Voltar" << std::endl;

    // Leia a opção do usuário
    int opcao;
    std::cin >> opcao;

    // Execute a ação correspondente à opção selecionada
    switch (opcao) {
      case 1:
        // Cadastrar evento
        professor_criar_evento(professor);
        break;
      case 2:
        // Editar evento
        professor_editar_evento(professor);
        break;
      case 3:
        // Excluir evento
        professor_excluir_evento(professor);
        break;
      case 4:
        // Pesquisar evento
        professor_pesquisar_evento(professor);
        break;
      case 5:
        // Listar eventos
        professor_listar_eventos(professor);
        break;
      case 6:
        menu_professor(professor);// Voltar
      default:
        // Opção inválida
        std::cout << "Opção inválida." << std::endl;
    }
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
        menu_professor(professor);
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
    std::cout << "Digite (s) para sim , caso contrario sera direcionado ao menu principal !" << std::endl;
    if(resposta == 's' || resposta == 'S'){
        recuperar_senha(aluno, professor ,administrador);
    }
    else {
        menu_principal(aluno, professor, administrador, alunos, professores);
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


void Interface::cadastrar_usuario(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores) {
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
            menu_principal(aluno, professor, administrador, alunos, professores);
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

    
void Interface::professor_criar_evento(Professor& professor){
    std::string tipo, titulo, descricao, data, hora, local, criador;

    // Pedir ao usuário para inserir informações
    std::cout << "Digite o tipo: "; std::cin >> tipo;
    std::cout << "Digite o titulo: "; std::cin >> titulo;
    std::cout << "Digite a descricao: "; std::cin >> descricao;
    std::cout << "Digite a data: "; std::cin >> data;
    std::cout << "Digite a hora: "; std::cin >> hora;
    std::cout << "Digite o local: "; std::cin >> local;

    // Criar uma instância de Evento com as informações inseridas
    Evento novoEvento(tipo, titulo, descricao, data, hora, local, professor.get_nome());

    professor.criarEvento(novoEvento);

}

void Interface::professor_editar_evento(Professor& professor) {
    // Listar os eventos existentes
    professor.listarEventosTodos();

    // Pedir ao usuário para escolher um evento
    std::cout << "Digite o título do evento que deseja editar: ";
    std::string tituloEscolhido;
    std::cin >> tituloEscolhido;

    // Criar uma instância temporária do evento com o título escolhido
    Evento eventoEscolhido(tituloEscolhido, "", "", "", "", "", "");

    // Encontrar o evento pelo título
    auto it = std::find_if(professor.getEventos().begin(), professor.getEventos().end(),[tituloEscolhido](const Evento& evento) {return evento.getTitulo() == tituloEscolhido;});

    if (it != professor.getEventos().end()) {
        // Evento encontrado, permitir ao usuário escolher o que editar
        std::cout << "Escolha o que deseja editar:\n";
        std::cout << "1 - Título\n";
        std::cout << "2 - Descrição\n";
        std::cout << "3 - Data\n";
        std::cout << "4 - Hora\n";
        std::cout << "5 - Local\n";
        std::cout << "0 - Cancelar\n";

        int opcao;
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string novoTitulo;
                std::cout << "Novo título: ";
                std::cin >> novoTitulo;
                it->setTitulo(novoTitulo);
                break;
            }
            case 2: {
                std::string novaDescricao;
                std::cout << "Nova descrição: ";
                std::cin >> novaDescricao;
                it->setDescricao(novaDescricao);
                break;
            }
            case 3: {
                std::string novaData;
                std::cout << "Nova data: ";
                std::cin >> novaData;
                it->setData(novaData);
                break;
            }
            case 4: {
                std::string novaHora;
                std::cout << "Nova hora: ";
                std::cin >> novaHora;
                it->setHora(novaHora);
                break;
            }
            case 5: {
                std::string novoLocal;
                std::cout << "Novo local: ";
                std::cin >> novoLocal;
                it->setLocal(novoLocal);
                break;
            }
            case 0: {
                std::cout << "Edição cancelada.\n";
                break;
            }
            default: {
                std::cout << "Opção inválida.\n";
                break;
            }
        }
    } else {
        std::cout << "Evento não encontrado.\n";
    }
}

void Interface::professor_excluir_evento(Professor& professor) {
    // Listar os eventos existentes
    professor.listarEventosTodos();

    // Pedir ao usuário para escolher um evento para excluir
    std::cout << "Digite o título do evento que deseja excluir: ";
    std::string tituloEscolhido;
    std::cin >> tituloEscolhido;

    // Criar um evento temporário apenas para realizar a comparação
    Evento eventoTemporario(tituloEscolhido, "", "", "", "", "", "");

    // Excluir o evento
    professor.excluirEvento(eventoTemporario);
}

void Interface::professor_pesquisar_evento(Professor& professor) {
    // Exiba as opções para o tipo de pesquisa
    std::cout << "Escolha o tipo de pesquisa:" << std::endl;
    std::cout << "1 - Pesquisar por Tipo" << std::endl;
    std::cout << "2 - Pesquisar por Data" << std::endl;
    std::cout << "3 - Pesquisar por Título" << std::endl;
    std::cout << "0 - Cancelar" << std::endl;

    // Leia a opção do usuário
    int opcao;
    std::cin >> opcao;

    switch (opcao) {
        case 1: {
            // Pesquisar por Tipo
            std::string tipo;
            std::cout << "Digite o tipo: ";
            std::cin >> tipo;
            professor.listarEventosTipo(tipo);
            break;
        }
        case 2: {
            // Pesquisar por Data
            std::string data;
            std::cout << "Digite a data: ";
            std::cin >> data;
            professor.pesquisarEventoPorData(data);
            break;
        }
        case 3: {
            // Pesquisar por Título
            std::string titulo;
            std::cout << "Digite o título: ";
            std::cin >> titulo;
            professor.pesquisarEventoPorTitulo(titulo);
            break;
        }
        case 0: {
            // Cancelar
            std::cout << "Operação cancelada." << std::endl;
            break;
        }
        default: {
            // Opção inválida
            std::cout << "Opção inválida." << std::endl;
            break;
        }
    }
}

void Interface::professor_listar_eventos(Professor& professor) {
    // Exiba as opções para o tipo de listagem
    std::cout << "Escolha o tipo de listagem:" << std::endl;
    std::cout << "1 - Listar Todos os Eventos" << std::endl;
    std::cout << "2 - Listar Eventos por Dia" << std::endl;
    std::cout << "3 - Listar Meus Eventos" << std::endl;
    std::cout << "0 - Cancelar" << std::endl;

    // Leia a opção do usuário
    int opcao;
    std::cin >> opcao;

    switch (opcao) {
        case 1: {
            // Listar Todos os Eventos
            professor.listarEventosTodos();
            break;
        }
        case 2: {
            // Listar Eventos por Dia
            std::string data;
            std::cout << "Digite a data: ";
            std::cin >> data;
            professor.listarEventosDia(data);
            break;
        }
        case 3: {
            // Listar Meus Eventos
            professor.listarMeusEventos();
            break;
        }
        case 0: {
            // Cancelar
            std::cout << "Operação cancelada." << std::endl;
            break;
        }
        default: {
            // Opção inválida
            std::cout << "Opção inválida." << std::endl;
            break;
        }
    }
}