#include "Calendario.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Evento.hpp"

Calendario::Calendario() {}     // Construtor

Calendario::~Calendario() {}        // Destrutor


// Métodos para excluir eventos
void Calendario::excluirEvento() {
    std::cout << "==============EXCLUINDO EVENTO==============\n\n";
    std::string id, titulo;    // Variaveis para armazenar o tipo de usuario, o id e o titulo do evento
    std::cout << "Digite o titulo do evento a ser excluido: ";
    std::getline(std::cin, titulo);    // Recebe o titulo do evento
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);   // Recebe o id do usuario

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado
    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    std::string linha;
    std::vector<std::string> eventosAtualizados;

    while (std::getline(arquivoEventos, linha)) {   //percorre o arquivo de eventos
        std::stringstream ss(linha);    //variavel para armazenar a linha do arquivo
        std::string tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento;  //variaveis para armazenar os dados do evento
        std::getline(ss, tipoEvento, '|');  //le o tipo do evento
        std::getline(ss, tituloEvento, '|');    //le o titulo do evento
        std::getline(ss, descricao, '|');   //le a descricao do evento
        std::getline(ss, data, '|');    //le a data do evento
        std::getline(ss, hora, '|');    //le a hora do evento
        std::getline(ss, local, '|');   //le o local do evento
        std::getline(ss, criador, '|'); //le o criador do evento
        std::getline(ss, idEvento, '|');    //le o id do evento

        if (id == idEvento && titulo == tituloEvento) {   // Verifica se o id e o titulo do evento existem
            idEncontrado = true;    // Caso existam, a variavel recebe true
            eventoEncontrado = true;    // Caso existam, a variavel recebe true
        } else {
            Evento evento(tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
            eventosAtualizados.push_back(linha); //adiciona o evento ao vetor
        }
    }

    arquivoEventos.close(); //fecha o arquivo

    if(!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario ou ID nao existe!" << std::endl;
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Evento nao encontrado!" << std::endl;
    }

    std::ofstream novoArquivoEventos("eventos.txt"); //abre o arquivo para escrita
    for(const std::string& evento : eventosAtualizados) {
        novoArquivoEventos << evento << std::endl; //escreve o evento no arquivo
    }
    novoArquivoEventos.close(); //fecha o arquivo

    if(idEncontrado && eventoEncontrado){
        std::cout << "Evento excluido com sucesso!" << std::endl;
    } 
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para listar eventos criar sommente por um usuario especifico
void Calendario::listarMeusEventosFuturos() {
    std::cout << "==============LISTANDO MEUS EVENTOS FUTUROS==============\n\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    bool eventoIdEncontrado = false;  // Variavel para verificar se o id foi encontrado
    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha, tipoUsuario, idUsuario, senhaUsuario;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');
        Usuario usuario(tipoUsuario, idUsuario, senhaUsuario); //cria um objeto do tipo usuario com os dados do arquivo
        if (id == idUsuario) {  // Verifica se o id existe
            eventoIdEncontrado = true;    // Caso exista, a variavel recebe true
        }
    }

    if(!eventoIdEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "ID nao existe!" << std::endl;
        return; // sai da funcao
    }

    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n" << std::endl;
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;
        std::getline(ss, tipoEvento, '|');
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');


        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual
            if(id == idEvento) {  //verifica se o id do usuario e o id do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if(!eventoEncontrado) { // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado!" << std::endl;
    }

    arquivoUsuarios.close(); //fecha o arquivo
    arquivoEventos.close(); //fecha o arquivo
}

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para listar eventos passados criar sommente por um usuario especifico
void Calendario::listarMeusEventosPassados() {
    std::cout << "==============LISTANDO MEUS EVENTOS PASSADOS==============\n\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    bool eventoIdEncontrado = false;  // Variavel para verificar se o id foi encontrado
    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha, tipoUsuario, idUsuario, senhaUsuario;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');
        Usuario usuario(tipoUsuario, idUsuario, senhaUsuario); //cria um objeto do tipo usuario com os dados do arquivo
        if (id == idUsuario) {  // Verifica se o id existe
            eventoIdEncontrado = true;    // Caso exista, a variavel recebe true
        }
    }

    if(!eventoIdEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "ID nao existe!" << std::endl;
        return; // sai da funcao
    }

    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n" << std::endl;
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;
        std::getline(ss, tipoEvento, '|');
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');


        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual < 0) {   //verifica se a data do evento é maior que a data atual
            if(id == idEvento) {  //verifica se o id do usuario e o id do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if(!eventoEncontrado) { // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado!" << std::endl;
    }

    arquivoUsuarios.close(); //fecha o arquivo
    arquivoEventos.close(); //fecha o arquivo
}



/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Método para imprimir eventos
void Calendario::imprimirEvento(const Evento& evento) {
    std::cout << "=========DETALHES DO EVENTO=========\n\n";
    // Imprime os detalhes do evento
    std::cout << "Tipo: " << evento.getTipo() << std::endl;
    std::cout << "Titulo: " << evento.getTitulo() << std::endl;
    std::cout << "Descricao: " << evento.getDescricao() << std::endl;
    std::cout << "Data: " << evento.getData() << std::endl;
    std::cout << "Hora: " << evento.getHora() << std::endl;
    std::cout << "Local: " << evento.getLocal() << std::endl;
    std::cout << std::endl; // Pula uma linha
}

// Método get para retornar os eventos
std::vector<Evento>  Calendario::getEventos() const {
    return eventos;
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Método para imprimir eventos ordenados
void Calendario::imprimirEventoOrdenado(const std::vector<Evento> &eventos){
    std::vector<Evento> eventosOrdenados = eventos;

    std::sort(eventosOrdenados.begin(), eventosOrdenados.end(), compararPorData);

    for (const auto& evento : eventosOrdenados) {
        imprimirEvento(evento);
        std::cout << "------------------------------\n";
    }
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


bool Calendario::compararPorData(const Evento& a, const Evento& b) {
    return a.getData() < b.getData(); // Retorna true se a data do evento a for menor que a data do evento b
}