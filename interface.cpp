/*
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
            realizar_login(aluno, professor, administrador, alunos, professores);
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
            menu_principal(aluno, professor, administrador, alunos, professores);
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
                cadastrar_professor(professores);
                menu_administrador(alunos , professores);
                break;

            case 2:
                // Chamar a função para cadastrar aluno
                cadastrar_aluno(alunos);
                menu_administrador(alunos , professores);
                break;

            case 3:
                excluir_professor(professores);
                menu_administrador(alunos , professores);
                break;
            case 4:
                excluir_aluno(alunos);
                menu_administrador(alunos , professores);
                break;
            case 5:
                // Opção para voltar
                std::cout << "Voltando ao menu principal do administrador." << std::endl;
                menu_administrador(alunos , professores);
                break;

            default:
                // Mensagem de erro para opções inválidas
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                menu_administrador(alunos , professores);
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
        menu_professor(professor);
        break;
      case 2:
        // Editar evento
        professor_editar_evento(professor);
        menu_professor(professor);
        break;
      case 3:
        // Excluir evento
        professor_excluir_evento(professor);
        menu_professor(professor);
        break;
      case 4:
        // Pesquisar evento
        professor_pesquisar_evento(professor);
        menu_professor(professor);
        break;
      case 5:
        // Listar eventos
        professor_listar_eventos(professor);
        menu_professor(professor);
        break;
      case 6:
        menu_professor(professor);// Voltar
      default:
        // Opção inválida
        std::cout << "Opção inválida, voce voltara ao menu do professor." << std::endl;
        menu_professor(professor);
    }
  }

void Interface::menu_aluno( Aluno& aluno){
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
        aluno_criar_evento(aluno);
        menu_aluno(aluno);
        break;
      case 2:
        // Editar evento
        aluno_editar_evento(aluno);
        menu_aluno(aluno);
        break;
      case 3:
        // Excluir evento
        aluno_excluir_evento(aluno);
        menu_aluno(aluno);
        break;
      case 4:
        // Pesquisar evento
        aluno_pesquisar_evento(aluno);
        menu_aluno(aluno);
        break;
      case 5:
        // Listar eventos
        aluno_listar_eventos(aluno);
        menu_aluno(aluno);
        break;
      case 6:
        menu_aluno(aluno);// Voltar
      default:
        // Opção inválida
        std::cout << "Opção inválida." << std::endl;
        menu_aluno(aluno);
    }
  }

void Interface::solicitar_e_recuperar_senha(std::vector<Aluno>& alunos, std::vector<Professor>& professores, Administrador& administrador) {
    std::string id;
    std::cout << "Digite o id: ";
    std::cin >> id;

    // Try to find the user with the given ID
    Aluno* aluno = encontrar_usuario_pelo_ID(alunos, id);
    Professor* professor = encontrar_usuario_pelo_ID(professores, id);

    // Check if the ID belongs to an Aluno
    if (aluno != nullptr) {
        recuperar_senha(*aluno);
        return;
    }

    // Check if the ID belongs to a Professor
    if (professor != nullptr) {
        recuperar_senha(*professor);
        return;
    }

    // Check if the ID belongs to the Administrador
    if (administrador.get_id() == id) {
        recuperar_senha(administrador);
        return;
    }

    std::cout << "Usuario nao encontrado operacao cancelada." << std::endl;
}

// Function to find a user by ID in a vector
template<typename UserType>
UserType* Interface::encontrar_usuario_pelo_ID(const std::vector<UserType>& users, const std::string& id) {
    for (auto& user : users) {
        if (user.get_id() == id) {
            return const_cast<UserType*>(&user);
        }
    }
    return nullptr;
}

// Function to recover password for a user
template<typename UserType>
void Interface::recuperar_senha(UserType& user) {
    std::string new_password;
    std::cout << "Digite a nova senha " << user.get_id() << ": ";
    std::cin >> new_password;

    // Set the new password for the user
    user.alterar_senha(new_password);

    std::cout << "Senha modificada com sucesso " << user.get_id() << std::endl;
}
void Interface::realizar_login(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores) {
    std::string id, senha;

    std::cout << "Informe o ID para realizar o login: ";
    std::cin >> id;

    std::cout << "Informe a senha: ";
    std::cin >> senha;

    // Verifique o login para Aluno
    if (aluno.fazer_login(id, senha)) {
        std::cout << "Login bem-sucedido para o aluno " << aluno.get_id() << std::endl;
        menu_aluno(aluno);
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

    char resposta;
    std::cout << "Esqueceu sua senha ?" << std::endl;
    std::cout << "Digite (s) para sim, caso contrário, será direcionado ao menu principal: ";
    std::cin >> resposta;
    if (resposta == 's' || resposta == 'S') {
        solicitar_e_recuperar_senha(alunos, professores, administrador);
        realizar_login(aluno, professor , administrador , alunos , professores);
    } else {
        menu_principal(aluno, professor, administrador, alunos, professores);
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
            cadastrar_professor(professores);
            break;
        case 3:
            cadastrar_aluno(alunos);
            break;
        case 4:
            menu_principal(aluno, professor, administrador, alunos, professores);
            break;
        default:
            std::cout << "Opção inválida." << std::endl;
            menu_principal(aluno, professor, administrador, alunos, professores);
            break;
    }
}

template<typename UserType>
void Interface::adicionar_usuario(std::vector<UserType>& users, const UserType& user) {
    users.push_back(user);
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

Professor Interface::cadastrar_professor(std::vector<Professor>& professores) {
    std::string id, senha, nome;
    std::cout << "Informe o ID do professor: ";
    std::cin >> id;

    std::cout << "Informe a senha do professor: ";
    std::cin >> senha;

    std::cout << "Informe o nome do professor: ";
    std::cin >> nome;

    // Criar uma nova instância de Professor
    Professor novo_professor(nome, id, senha);

    // Adicionar o novo professor ao vetor de professores
    adicionar_usuario(professores, novo_professor);

    // Retornar o novo objeto Professor
    return novo_professor;
}

Aluno Interface::cadastrar_aluno(std::vector<Aluno>& alunos) {
    std::string id, senha, matricula, nome;
    std::cout << "Informe o ID do aluno: ";
    std::cin >> id;

    std::cout << "Informe a senha do aluno: ";
    std::cin >> senha;

    std::cout << "Informe a matrícula do aluno: ";
    std::cin >> matricula;

    std::cout << "Informe o nome do aluno: ";
    std::cin >> nome;

    // Criar uma nova instância de Aluno
    Aluno novo_aluno(nome, id, senha, matricula);

    // Adicionar o novo aluno ao vetor de alunos
    adicionar_usuario(alunos, novo_aluno);

    // Retornar o novo objeto Aluno
    return novo_aluno;
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

    auto it = std::remove_if(alunos.begin(), alunos.end(), [id_aluno](const Aluno& aluno) { return aluno.get_id() == id_aluno; });

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
                menu_professor(professor);
                break;
            }
            default: {
                std::cout << "Opção inválida.\n";
                menu_professor(professor);
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
            menu_professor(professor);
            break;
        }
        default: {
            // Opção inválida
            std::cout << "Opção inválida." << std::endl;
            menu_professor(professor);
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
            menu_professor(professor);
            break;
        }
        default: {
            // Opção inválida
            std::cout << "Opção inválida." << std::endl;
            menu_professor(professor);
            break;
        }
    }
}

void Interface::aluno_criar_evento(Aluno& aluno){
    std::string tipo, titulo, descricao, data, hora, local, criador;

    // Pedir ao usuário para inserir informações
    std::cout << "Digite o tipo: "; std::cin >> tipo;
    std::cout << "Digite o titulo: "; std::cin >> titulo;
    std::cout << "Digite a descricao: "; std::cin >> descricao;
    std::cout << "Digite a data: "; std::cin >> data;
    std::cout << "Digite a hora: "; std::cin >> hora;
    std::cout << "Digite o local: "; std::cin >> local;

    // Criar uma instância de Evento com as informações inseridas
    Evento novoEvento(tipo, titulo, descricao, data, hora, local, aluno.get_nome());

    aluno.criarEvento(novoEvento);

}

void Interface::aluno_editar_evento(Aluno& aluno) {
    // Listar os eventos existentes
    aluno.listarEventosTodos();

    // Pedir ao usuário para escolher um evento
    std::cout << "Digite o título do evento que deseja editar: ";
    std::string tituloEscolhido;
    std::cin >> tituloEscolhido;

    // Criar uma instância temporária do evento com o título escolhido
    Evento eventoEscolhido(tituloEscolhido, "", "", "", "", "", "");

    // Encontrar o evento pelo título
    auto it = std::find_if(aluno.getEventos().begin(), aluno.getEventos().end(),[tituloEscolhido](const Evento& evento) {return evento.getTitulo() == tituloEscolhido;});

    if (it != aluno.getEventos().end()) {
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
                menu_aluno(aluno);
                break;
            }
            default: {
                std::cout << "Opção inválida.\n";
                menu_aluno(aluno);
                break;
            }
        }
    } else {
        std::cout << "Evento não encontrado.\n";
    }
}

void Interface::aluno_excluir_evento(Aluno& aluno) {
    // Listar os eventos existentes
    aluno.listarEventosTodos();

    // Pedir ao usuário para escolher um evento para excluir
    std::cout << "Digite o título do evento que deseja excluir: ";
    std::string tituloEscolhido;
    std::cin >> tituloEscolhido;

    // Criar um evento temporário apenas para realizar a comparação
    Evento eventoTemporario(tituloEscolhido, "", "", "", "", "", "");

    // Excluir o evento
    aluno.excluirEvento(eventoTemporario);
}

void Interface::aluno_pesquisar_evento(Aluno& aluno) {
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
            aluno.listarEventosTipo(tipo);
            break;
        }
        case 2: {
            // Pesquisar por Data
            std::string data;
            std::cout << "Digite a data: ";
            std::cin >> data;
            aluno.pesquisarEventoPorData(data);
            break;
        }
        case 3: {
            // Pesquisar por Título
            std::string titulo;
            std::cout << "Digite o título: ";
            std::cin >> titulo;
            aluno.pesquisarEventoPorTitulo(titulo);
            break;
        }
        case 0: {
            // Cancelar
            std::cout << "Operação cancelada." << std::endl;
            menu_aluno(aluno);
            break;
        }
        default: {
            // Opção inválida
            std::cout << "Opção inválida." << std::endl;
            menu_aluno(aluno);
            break;
        }
    }
}

void Interface::aluno_listar_eventos(Aluno& aluno) {
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
            aluno.listarEventosTodos();
            break;
        }
        case 2: {
            // Listar Eventos por Dia
            std::string data;
            std::cout << "Digite a data: ";
            std::cin >> data;
            aluno.listarEventosDia(data);
            break;
        }
        case 3: {
            // Listar Meus Eventos
            aluno.listarMeusEventos();
            break;
        }
        case 0: {
            // Cancelar
            std::cout << "Operação cancelada." << std::endl;
            menu_aluno(aluno);
            break;
        }
        default: {
            // Opção inválida
            std::cout << "Opção inválida." << std::endl;
            menu_aluno(aluno);
            break;
        }
    }
}
*/