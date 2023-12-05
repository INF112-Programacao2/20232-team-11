#include "Notificacao.hpp"

Notificacao::Notificacao() {}   // Construtor

Notificacao::~Notificacao() {}  // Destrutor

//métodos get 
std::string Notificacao::getMensagem() const {
    return _mensagem;
}

std::string Notificacao::getData() const {
    return _data;
}

std::string Notificacao::getHora() const {
    return _hora;
}

//métodos set
void Notificacao::setMensagem(const std::string& mensagem) {
    _mensagem = mensagem;
}

void Notificacao::setData(const std::string& data) {
    _data = data;
}

void Notificacao::setHora(const std::string& hora) {
    _hora = hora;
}

//método para exibir a notificação
void Notificacao::exibirNotificacao(){
    std::cout << "=======CALENDARIO ACADEMICO=======" << std::endl;
    std::cout << "Você tem uma notificação!" << std::endl;
    bool encontrado = false; // variável para verificar se o evento foi encontrado
    bool notificacao = false; // variável para verificar se a notificação foi encontrada
    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    std::ifstream arquivoEventos("eventos.txt");    //abre o arquivo de eventos
    if (!arquivoEventos.is_open()) {    //verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo de eventos!" << std::endl;
        return;
    }

    std::string linha;  //variável para armazenar a linha do arquivo

    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);    //cria um fluxo de string
        std::string tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;  //variáveis para armazenar os dados do evento

        //ler os dados do arquivo
        std::getline(ss, tipoEvento, '|');  
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t

        if (dado.fail()) {
            std::cout << "Data ou hora invalida!" << std::endl;
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
        if(dataHoraEvento - dataHoraAtual > 0 ){
            notificacao = true;
            if(tipoEvento == "PROVA"){                                          // 1 semana em segundos (1 semaine * 7 jours * 24 heures * 60 minutes * 60 secondes)
                if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 604800) || (dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) || (dataHoraEvento - dataHoraAtual) <= 3600) {    
                    //exibe os dados do evento
                    std::cout << "Tipo: " << tipoEvento << std::endl;
                    std::cout << "Titulo: " << tituloEvento << std::endl;
                    std::cout << "Descricao: " << descricaoEvento << std::endl;
                    std::cout << "Data: " << dataEvento << std::endl;
                    std::cout << "Hora: " << horaEvento << std::endl;
                    std::cout << "Local: " << localEvento << std::endl;
                    std::cout << std::endl;
                    encontrado = true;
                }
            }else if(tipoEvento == "TRABALHO"){                                 // 3 dias em segundos (3 jours * 24 heures * 60 minutes * 60 secondes)
                if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) || (dataHoraEvento - dataHoraAtual) <= 3600) || (dataHoraEvento - dataHoraAtual) <= 900) {    // 3 dias em segundos (3 jours * 24 heures * 60 minutes * 60 secondes)
                    std::cout << "Tipo: " << tipoEvento << std::endl;
                    std::cout << "Titulo: " << tituloEvento << std::endl;
                    std::cout << "Descricao: " << descricaoEvento << std::endl;
                    std::cout << "Data: " << dataEvento << std::endl;
                    std::cout << "Hora: " << horaEvento << std::endl;
                    std::cout << "Local: " << localEvento << std::endl;
                    std::cout << std::endl;
                    encontrado = true;
                }
            }else if(tipoEvento == "APRESENTACAO" || tipoEvento == "OUTRO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes)***// 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes)
                if (dataHoraEvento >= dataHoraAtual && (((dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) || (dataHoraEvento - dataHoraAtual) <= 3600) {    // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes)
                    std::cout << "Tipo: " << tipoEvento << std::endl;
                    std::cout << "Titulo: " << tituloEvento << std::endl;
                    std::cout << "Descricao: " << descricaoEvento << std::endl;
                    std::cout << "Data: " << dataEvento << std::endl;
                    std::cout << "Hora: " << horaEvento << std::endl;
                    std::cout << "Local: " << localEvento << std::endl;
                    std::cout << std::endl;
                    encontrado = true;
                }
            }
        }

        if(!notificacao){
            std::cout << "Nenhuma notificação!" << std::endl;
        }
    }
}