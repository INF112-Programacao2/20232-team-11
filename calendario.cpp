#include "Calendario.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Evento.hpp"

Calendario::Calendario() {}     // Construtor

Calendario::~Calendario() {}        // Destrutor

// Métodos para adicinar eventos
void Calendario::adicionarEvento(const Evento& evento) {
    eventos.push_back(evento);      // Adiciona o evento no final do vetor
}

// Métodos para excluir eventos
void Calendario::excluirEvento(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {
    std::string tipoUsuario, id, titulo;    // Variaveis para armazenar o tipo de usuario, o id e o titulo do evento
    std::cout << "Digite o seu tipo de usuario: ";
    std::getline(std::cin, tipoUsuario);    // Recebe o tipo de usuario
    std::cout << "Digite o titulo do evento: ";
    std::getline(std::cin, titulo);    // Recebe o titulo do evento
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);   // Recebe o id do usuario

    bool encontradoId = false;    // Variavel para verificar se o id foi encontrado
  
    for(const Usuario& usuario : usuarios) {    // Percorre o vetor de usuarios
        if(usuario.getId() == id && usuario.getTipo() == tipoUsuario) {    // Verifica se o id e o tipo de usuario existem
            encontradoId = true;    // Caso existam, a variavel recebe true
            break;    // Sai do loop
        }
    }

    if(!encontradoId) {    // Caso o id nao seja encontrado
        std::cout << "Usuario ou ID nao encontrado!" << std::endl;
        return;  // sai da funcao
    }

    for(auto i = eventos.begin(); i != eventos.end(); i++) {      // Percorre o vetor de eventos
        if (titulo == i->getTitulo() && i->getId() == id && i->getCriador() == tipoUsuario) {     // Verifica se o evento existe
            i = eventos.erase(i);       // Apaga o evento
            std::cout << "Evento excluido com sucesso!" << std::endl;
            return;    // sai da funcao
        }
    }
    std::cout << "Evento nao encontrado!" << std::endl;     // Caso o evento nao exista
}

// Métodos para editar eventos
void Calendario::editarEvento(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {        // Edita o evento
    std::string id, titulo, tipo, descricao, data, hora, local;    // Variaveis para armazenar o id, o titulo, o tipo, a descricao, a data, a hora e o local do evento
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);  // Recebe o id do usuario
    std::cout << "Digite o titulo do evento: ";
    std::getline(std::cin, titulo); // Recebe o titulo do evento

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    for (const Usuario& usuario : usuarios) {   // Percorre o vetor de usuarios
        if (usuario.getId() == id) {    // Verifica se o id existe
            idEncontrado = true;    // Caso exista, a variavel recebe true
            break;  // Sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    for (Evento& evento : eventos) {      // Percorre o vetor de eventos
        if (evento.getTitulo() == titulo && evento.getId() == id) {     // Verifica se o evento existe
            eventoEncontrado = true;    // Caso exista, a variavel recebe true
            std::cout << "Digite o novo tipo do evento: ";
            std::getline(std::cin, tipo);   // Recebe o novo tipo do evento
            std::cout << "Digite o novo titulo do evento: ";
            std::getline(std::cin, titulo); // Recebe o novo titulo do evento
            std::cout << "Digite a nova descricao do evento: ";
            std::getline(std::cin, descricao);  // Recebe a nova descricao do evento
            std::cout << "Digite a nova data do evento (DD-MM-AAAA): ";
            std::getline(std::cin, data);   // Recebe a nova data do evento
            std::cout << "Digite a nova hora do evento (HH:MM): ";
            std::getline(std::cin, hora);   // Recebe a nova hora do evento
            std::cout << "Digite o novo local do evento: ";
            std::getline(std::cin, local);  // Recebe o novo local do evento

            evento.setTipo(tipo);   // Altera o tipo do evento
            evento.setTitulo(titulo);   // Altera o titulo do evento
            evento.setDescricao(descricao); // Altera a descricao do evento
            evento.setData(data);   // Altera a data do evento
            evento.setHora(hora);   // Altera a hora do evento
            evento.setLocal(local); // Altera o local do evento

            std::cout << "Evento editado com sucesso!" << std::endl;
            return; // sai da funcao
        }
    }
}

// Métodos para pesquisar eventos por tipo
void Calendario::pesquisarEventoPorTipo(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {
    std::string tipoEvento, tipoUsuario, id;    // Variaveis para armazenar o tipo de evento, o tipo de usuario e o id do usuario
    std::cout << "Digite o tipo de evento a ser pesquisado (PROVA - TRABALHO - APRESENTACAO - OUTRO): ";
    std::getline(std::cin, tipoEvento);   // Recebe o tipo de evento
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    std::getline(std::cin, tipoUsuario);    // Recebe o tipo de usuario
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);  // Recebe o id do usuario

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    for (const Usuario& usuario : usuarios) {   // Percorre o vetor de usuarios
        if (usuario.getId() == id && usuario.getTipo() == tipoUsuario) {    // Verifica se o id e o tipo de usuario existem
            idEncontrado = true;    // Caso existam, a variavel recebe true
            break;  // Sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario ou ID nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    for (const Evento& evento : eventos) {      // Percorre o vetor de eventos
        if (evento.getTipo() == tipoEvento && evento.getId() == id) {     // Verifica se o evento existe
            if (tipoUsuario == "ADMIN" && evento.getCriador() == "ADMIN") { // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);     // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipoUsuario == "PROF" && (evento.getCriador() == "PROF" || evento.getCriador() == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);    // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipoUsuario == "ALUNO") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);   // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }
}


// Métodos para pesquisar eventos por título
void Calendario::pesquisarEventoPorTitulo(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {
    std::string titulo, tipo, id;   // Variaveis para armazenar o titulo, o tipo e o id do usuario
    std::cout << "Digite o titulo do evento a ser pesquisado: ";
    std::getline(std::cin, titulo); // Recebe o titulo do evento
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    std::getline(std::cin, tipo);   // Recebe o tipo de usuario
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    for (const Usuario& usuario : usuarios) {   // Percorre o vetor de usuarios
        if (usuario.getId() == id && usuario.getTipo() == tipo) {   // Verifica se o id e o tipo de usuario existem
            idEncontrado = true;    // Caso existam, a variavel recebe true
            break;  // Sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario ou ID nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    for (const Evento& evento : eventos) {      // Percorre o vetor de eventos
        if (evento.getTitulo() == titulo && evento.getId() == id && evento.getCriador() == tipo) {     // Verifica se o evento existe
            if (tipo == "ADMIN" && evento.getCriador() == "ADMIN") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);    // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "PROF" && (evento.getCriador() == "PROF" || evento.getCriador() == "ADMIN")) {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);   // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "ALUNO") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);  // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse usuario." << std::endl;
    }
}

// Métodos para listar eventos por tipo
void Calendario::listarEventosTipo(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {      
    std::string tipoUsuario, tipoEvento, id;    // Variaveis para armazenar o tipo de usuario, o tipo de evento e o id do usuario
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    std::getline(std::cin, tipoUsuario);    // Recebe o tipo de usuario
    std::cout << "Digite o tipo de evento a ser listado (PROVA - TRABALHO - APRESENTACAO - OUTRO): ";
    std::getline(std::cin, tipoEvento); 
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    for (const Usuario& usuario : usuarios) {   // Percorre o vetor de usuarios
        if (id == usuario.getId() && usuario.getTipo() == tipoUsuario) {    // Verifica se o id e o tipo de usuario existem
            idEncontrado = true;    // Caso existam, a variavel recebe true
            break;  // Sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    for (const Evento& evento : eventos) {      // Percorre o vetor de eventos
        if (evento.getTipo() == tipoEvento && evento.getId() == id) {     // Verifica se o evento existe
            if (tipoUsuario == "ADMIN" && evento.getCriador() == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento);
                eventoEncontrado = true;
            } else if (tipoUsuario == "PROF" && (evento.getCriador() == "PROF" || evento.getCriador() == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipoUsuario == "ALUNO") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse usuario." << std::endl;
    }
}

// Métodos para pesquisar eventos por data
void Calendario::pesquisarEventoPorData(std::vector<Evento>& eventos) {  
    std::string data, tipo;   // Variaveis para armazenar a data e o tipo de usuario
    std::cout << "Digite a data do evento a ser pesquisado: ";
    std::getline(std::cin, data);   // Recebe a data do evento
    std::cout << "Digite o seu tipo de usuario: ";
    std::getline(std::cin, tipo);   // Recebe o tipo de usuario


    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    for (const Evento& evento : eventos) {      // Percorre o vetor de eventos
        if (evento.getData() == data) {     // Verifica se o evento existe
            if (tipo == "ADMIN" && evento.getCriador() == "ADMIN") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
               imprimirEvento(evento);  // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "PROF" && (evento.getCriador() == "PROF" || evento.getCriador() == "ADMIN")) {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "ALUNO") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse usuario." << std::endl;
    }
}

// Métodos para listar todos os eventos
void Calendario::listarEventosTodos(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {

    std::string id, criador;    // Variaveis para armazenar o id e o tipo de usuario
    std::cout << "Digite o seu tipo de usuario: ";
    std::getline(std::cin, criador);    // Recebe o tipo de usuario
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    for (const Usuario& usuario : usuarios) {   // Percorre o vetor de usuarios
        if (id == usuario.getId()) {    // Verifica se o id existe
            idEncontrado = true;    // Caso exista, a variavel recebe true
            break;  // Sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado 
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    for (const Evento& evento : eventos) {    // Percorre o vetor de eventos
        if (evento.getId() == id) {    // Verifica se o evento existe
            if (evento.getCriador() == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento); // Imprime o evento
            } else if ((evento.getCriador() == "PROF") || evento.getCriador() == "ADMIN") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                imprimirEvento(evento); // Imprime o evento
            }
        }
        //se o usuario for aluno, ele so pode ver os eventos que ele criou ou os eventos criados por professores ou administradores
        if ((criador == "ALUNO" && evento.getId() == id) || (evento.getCriador() == "PROF" || evento.getCriador() == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
            imprimirEvento(evento); // Imprime o evento
        }
    }
}

// Métodos para listar eventos por criador
void Calendario::listarMeusEventos(std::vector<Evento>& eventos, std::vector<Usuario>& usuarios) {
    std::string id;   // Variavel para armazenar o id do usuario
    std::cout << "Digite o seu ID de usuário: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    for (const Usuario& usuario : usuarios) {   // Percorre o vetor de usuarios
        if (id == usuario.getId()) {    // Verifica se o id existe
            idEncontrado = true;    // Caso exista, a variavel recebe true
            break;  // Sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    for (const Evento& evento : eventos) {    // Percorre o vetor de eventos
        if (evento.getId() == id) {  // Verifica se o evento existe
            imprimirEvento(evento); // Imprime o evento
            eventoEncontrado = true;    // Caso existam, a variavel recebe true
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse usuario." << std::endl;
    }
}

// Método get para retornar os eventos
std::vector<Evento>  Calendario::getEventos() const {
    return eventos;
}

// Métodos para imprimir eventos
void Calendario::imprimirEvento(const Evento& evento) {
    std::cout << "Tipo: " << evento.getTipo() << std::endl;   // Imprime o tipo do evento
    std::cout << "Titulo: " << evento.getTitulo() << std::endl;  // Imprime o titulo do evento
    std::cout << "Descricao: " << evento.getDescricao() << std::endl;   // Imprime a descricao do evento
    std::cout << "Data: " << evento.getData() << std::endl;  // Imprime a data do evento
    std::cout << "Hora: " << evento.getHora() << std::endl; // Imprime a hora do evento
    std::cout << "Local: " << evento.getLocal() << std::endl;   // Imprime o local do evento
    std::cout << std::endl; // Pula uma linha
}
