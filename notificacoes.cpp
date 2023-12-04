#include "Notificacoes.hpp"

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


//métodos para verificar se o evento é uma semana antes
bool Notificacao::umaSemanaAntes(const std::vector<Evento>& eventos) {
    
    std::string dataHora = eventos[0].getData() + " " + eventos[0].getHora();   //pega a data e hora do evento que estão na primeira posição do vetor
    std::tm tempo = {}; //variável para armazenar a data e hora do evento
    std::istringstream dado(dataHora);  //variável para armazenar a data e hora do evento
    dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //variável para armazenar a data e hora do evento

    if (dado.fail()) {  //verifica se a data ou hora são válidas
        std::cout << "Data ou hora invalida!" << std::endl;
        return false;   //retorna falso se a data ou hora forem inválidas
    }

    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
    std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

    if (dataHoraEvento < dataHoraAtual) {   //verifica se a data e hora do evento são menores que a data e hora atual
        return false;   //retorna falso se a data e hora do evento forem menores que a data e hora atual
    }

    return (dataHoraEvento - dataHoraAtual <= 604800); // 7 dias em segundos (7 jours * 24 heures * 60 minutes * 60 secondes)
}

//métodos para verificar se o evento é três dias antes
bool Notificacao::tresDiasAntes(const Evento& evento) { 

    std::string dataHora = evento.getData() + " " + evento.getHora();   //pega a data e hora do evento que estão na primeira posição do vetor
    std::tm tempo = {}; //variável para armazenar a data e hora do evento
    std::istringstream dado(dataHora);  //variável para armazenar a data e hora do evento
    dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //variável para armazenar a data e hora do evento

    if (dado.fail()) {  //verifica se a data ou hora são válidas
        std::cout << "Data ou hora invalida!" << std::endl;
        return false;   //retorna falso se a data ou hora forem inválidas
    }

    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
    std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

    if (dataHoraEvento < dataHoraAtual) {   //verifica se a data e hora do evento são menores que a data e hora atual
        return false;   //retorna falso se a data e hora do evento forem menores que a data e hora atual
    }

    return (dataHoraEvento - dataHoraAtual <= 259200); // 3 dias em segundos (3 jours * 24 heures * 60 minutes * 60 secondes)
}

//métodos para verificar se o evento é um dia antes
bool Notificacao::umDiaAntes(const std::vector<Evento>& eventos) {

    std::string dataHora = eventos[0].getData() + " " + eventos[0].getHora();   //pega a data e hora do evento que estão na primeira posição do vetor
    std::tm tempo = {}; //variável para armazenar a data e hora do evento
    std::istringstream dado(dataHora);  //variável para armazenar a data e hora do evento
    dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    

    if (dado.fail()) {  //verifica se a data ou hora são válidas
        std::cout << "Data ou hora invalida!" << std::endl; 
        return false;   //retorna falso se a data ou hora forem inválidas
    }

    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
    std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

    if (dataHoraEvento < dataHoraAtual) {   //verifica se a data e hora do evento são menores que a data e hora atual
        return false;   //retorna falso se a data e hora do evento forem menores que a data e hora atual
    }

    return (dataHoraEvento - dataHoraAtual <= 86400); // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes)
}

//métodos para verificar se o evento é uma hora antes
bool Notificacao::umaHoraAntes(const std::vector<Evento>& eventos) { 

    std::string dataHora = eventos[0].getData() + " " + eventos[0].getHora();   //pega a data e hora do evento que estão na primeira posição do vetor
    std::tm tempo = {}; //variável para armazenar a data e hora do evento
    std::istringstream dado(dataHora);  
    dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");   //variável para armazenar a data e hora do evento

    if (dado.fail()) {  //verifica se a data ou hora são válidas
        std::cout << "Data ou hora invalida!" << std::endl;
        return false;   //retorna falso se a data ou hora forem inválidas
    }

    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
    std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

    if (dataHoraEvento < dataHoraAtual) {   //verifica se a data e hora do evento são menores que a data e hora atual
        return false;   //retorna falso se a data e hora do evento forem menores que a data e hora atual
    }

    return (dataHoraEvento - dataHoraAtual <= 3600); // 1 hora em segundos (1 heure * 60 minutes * 60 secondes)
}

//métodos para verificar se o evento é quinze minutos antes
bool Notificacao::quinzeMinutosAntes(const std::vector<Evento>& eventos) {

    std::string dataHora = eventos[0].getData() + " " + eventos[0].getHora();   //pega a data e hora do evento que estão na primeira posição do vetor
    std::tm tempo = {}; //variável para armazenar a data e hora do evento
    std::istringstream dado(dataHora);  //variável para armazenar a data e hora do evento
    dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //variável para armazenar a data e hora do evento

    if (dado.fail()) {  //verifica se a data ou hora são válidas
        std::cout << "Data ou hora invalida!" << std::endl;
        return false;   //retorna falso se a data ou hora forem inválidas
    }

    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
    std::time_t dataHoraEvento = std::mktime(&tempo); //variável para armazenar a data e hora do evento  

    if (dataHoraEvento < dataHoraAtual) {   //verifica se a data e hora do evento são menores que a data e hora atual
        return false;   //retorna falso se a data e hora do evento forem menores que a data e hora atual
    }

    return (dataHoraEvento - dataHoraAtual <= 900); // 15 minutos em segundos (15 minutes * 60 secondes)
}

//método para exibir a notificação
void Notificacao::exibirNotificacao(const std::vector<Evento>& eventos){

    bool encontrado = false; // variável para verificar se o evento foi encontrado
    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    for (const Evento& evento : eventos) {  //percorre o vetor de eventos
        std::string tipo = evento.getTipo();    //pega o tipo do evento
        std::string dataHora = evento.getData() + " " + evento.getHora();   //pega a data e hora do evento
        std::tm tempo = {}; //variável para armazenar a data e hora do evento
        std::istringstream dado(dataHora);  //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //variável para armazenar a data e hora do evento

        if (dado.fail()) {  //verifica se a data ou hora são válidas
            std::cout << "Data ou hora invalida!" << std::endl;
            continue;   //passar para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if (dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data e hora do evento são maiores que a data e hora atual

            if (tipo == "TRABALHO" && (tresDiasAntes(evento) || umDiaAntes(eventos) || umaHoraAntes(eventos) || quinzeMinutosAntes(eventos))) { //verifica se o tipo do evento é trabalho e se o evento é três dias antes, um dia antes, uma hora antes ou quinze minutos antes
                encontrado = true; // pelo menos um evento foi encontrado
                //imprime os dados do evento
                std::cout << "Tipo: " << evento.getTipo() << std::endl;
                std::cout << "Título: " << evento.getTitulo() << std::endl;
                std::cout << "Descrição: " << evento.getDescricao() << std::endl;
                std::cout << "Data: " << evento.getData() << std::endl;
                std::cout << "Hora: " << evento.getHora() << std::endl;
                std::cout << "Local: " << evento.getLocal() << std::endl;
                std::cout << std::endl;
            }else if (tipo == "PROVA" && (umaSemanaAntes(eventos) || tresDiasAntes(evento) || umDiaAntes(eventos))) {   //verifica se o tipo do evento é prova e se o evento é uma semana antes, três dias antes ou um dia antes
                encontrado = true; // pelo menos um evento foi encontrado
                //imprime os dados do evento
                std::cout << "Tipo: " << evento.getTipo() << std::endl;
                std::cout << "Título: " << evento.getTitulo() << std::endl;
                std::cout << "Descrição: " << evento.getDescricao() << std::endl;
                std::cout << "Data: " << evento.getData() << std::endl;
                std::cout << "Hora: " << evento.getHora() << std::endl;
                std::cout << "Local: " << evento.getLocal() << std::endl;
                std::cout << std::endl;
            }else if (tipo == "APRESENTACAO" && (tresDiasAntes(evento) || umDiaAntes(eventos) || umaHoraAntes(eventos))) {  //verifica se o tipo do evento é apresentação e se o evento é três dias antes, um dia antes ou uma hora antes
                encontrado = true; // pelo menos um evento foi encontrado
                //imprime os dados do evento
                std::cout << "Tipo: " << evento.getTipo() << std::endl;
                std::cout << "Título: " << evento.getTitulo() << std::endl;
                std::cout << "Descrição: " << evento.getDescricao() << std::endl;
                std::cout << "Data: " << evento.getData() << std::endl;
                std::cout << "Hora: " << evento.getHora() << std::endl;
                std::cout << "Local: " << evento.getLocal() << std::endl;
                std::cout << std::endl;
            }else if (tipo == "OUTRO" && tresDiasAntes(evento)) {   //verifica se o tipo do evento é outro e se o evento é três dias antes
                encontrado = true; // pelo menos um evento foi encontrado
                //imprime os dados do evento
                std::cout << "Tipo: " << evento.getTipo() << std::endl;
                std::cout << "Título: " << evento.getTitulo() << std::endl;
                std::cout << "Descrição: " << evento.getDescricao() << std::endl;
                std::cout << "Data: " << evento.getData() << std::endl;
                std::cout << "Hora: " << evento.getHora() << std::endl;
                std::cout << "Local: " << evento.getLocal() << std::endl;
                std::cout << std::endl;
            }
        }
    
    }

    if (!encontrado) {  //verifica se o evento não foi encontrado
        std::cout << "Nenhum evento encontrado!" << std::endl;
    }
}