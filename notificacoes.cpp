#include "Notificacoes.hpp"

Notificacao::Notificacao() {}

Notificacao::~Notificacao() {}

std::string Notificacao::getMensagem() const {
    return _mensagem;
}

std::string Notificacao::getData() const {
    return _data;
}

std::string Notificacao::getHora() const {
    return _hora;
}

void Notificacao::setMensagem(const std::string& mensagem) {
    _mensagem = mensagem;
}

void Notificacao::setData(const std::string& data) {
    _data = data;
}

void Notificacao::setHora(const std::string& hora) {
    _hora = hora;
}

//método para verificar se a data e hora do evento é valida
bool Notificacao::verificarDataHora(const std::vector<Evento>& eventos) {
    for(int i = 0; i < eventos.size(); i++) {       // Percorre o vetor de eventos
        std::string dataHora = eventos[i].getData() + " " + eventos[i].getHora();       // Concatena a data e hora do evento
        std::tm tempo = {};     // Cria uma variável do tipo tm
        std::istringstream dado(dataHora);      // Cria uma variável do tipo istringstream
        dado >> std::get_time(&tempo, "%d/%m/%Y %H:%M");        // Lê a data e hora do evento

        if (dado.fail()) {      // Verifica se a leitura falhou
            std::cout << "Data ou hora invalida!" << std::endl;     // Caso a leitura falhe
            return false;       
        }

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());     // Pega a data e hora atual
        std::time_t dataHoraEvento = std::mktime(&tempo);       // Pega a data e hora do evento

        if(dataHoraEvento - dataHoraAtual == 0) {       // Verifica se a data e hora do evento é igual a data e hora atual
            return true;        // Caso a data e hora do evento seja igual a data e hora atual
        }
    }

    // Se nenhum evento corresponder à data e hora atual, retorna falso
    return false;
}

//métodos para verificar se o evento é uma semana antes
bool Notificacao::umaSemanaAntes(const std::vector<Evento>& eventos) {
    for(int i = 0; i < eventos.size(); i++) {       // Percorre o vetor de eventos
        std::string dataHora = eventos[i].getData() + " " + eventos[i].getHora();
        std::tm tempo = {}; // Cria uma variável do tipo tm para armazenar a data e hora do evento
        std::istringstream dado(dataHora);    // Cria uma variável do tipo istringstream para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d/%m/%Y %H:%M");    // Lê a data e hora do evento de acordo com o formato especificado 

        if (dado.fail()) {      // Verifica se a leitura falhou
            std::cout << "Data ou hora invalida!" << std::endl;
            return false;
        }
        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());     // Pega a data e hora atual
        std::time_t dataHoraEvento = std::mktime(&tempo);       // Pega a data e hora do evento e armazena na variável dataHoraEvento, usando a função mktime para converter a data e hora do evento para o formato time_t

        if(dataHoraEvento - dataHoraAtual == 604800) {      // Verifica se a data e hora do evento é igual a data e hora atual conversando para segundos (604800 segundos = 1 semana =  (7 dias * 24 horas * 60 minutos * 60 segundos)))
            return true;
        }        
    }

    return false;
}

//métodos para verificar se o evento é três dias antes
bool Notificacao::tresDiasAntes(const std::vector<Evento>& eventos) {       
    for(int i = 0; i < eventos.size(); i++) {
        std::string dataHora = eventos[i].getData() + " " + eventos[i].getHora();
        std::tm tempo = {};
        std::istringstream dado(dataHora);
        dado >> std::get_time(&tempo, "%d/%m/%Y %H:%M");

        if (dado.fail()) {
            std::cout << "Data ou hora invalida!" << std::endl;
            return false;
        }
        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::time_t dataHoraEvento = std::mktime(&tempo);

        if(dataHoraEvento - dataHoraAtual == 259200) {
            return true;
        }
    }
    
    return false;
}

//métodos para verificar se o evento é um dia antes
bool Notificacao::umDiaAntes(const std::vector<Evento>& eventos) {
    for(int i = 0; i < eventos.size(); i++) {
        std::string dataHora = eventos[i].getData() + " " + eventos[i].getHora();
        std::tm tempo = {};
        std::istringstream dado(dataHora);
        dado >> std::get_time(&tempo, "%d/%m/%Y %H:%M");

        if (dado.fail()) {
            std::cout << "Data ou hora invalida!" << std::endl;
            return false;
        }
        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::time_t dataHoraEvento = std::mktime(&tempo);

        if(dataHoraEvento - dataHoraAtual == 86400) {
            return true;
        }
    }

    return false;
}

//métodos para verificar se o evento é uma hora antes
bool Notificacao::umaHoraAntes(const std::vector<Evento>& eventos) {
    for(int i = 0; i < eventos.size(); i++) {
        std::string dataHora = eventos[i].getData() + " " + eventos[i].getHora();
        std::tm tempo = {};
        std::istringstream dado(dataHora);
        dado >> std::get_time(&tempo, "%d/%m/%Y %H:%M");

        if (dado.fail()) {
            std::cout << "Data ou hora invalida!" << std::endl;
            return false;
        }
        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::time_t dataHoraEvento = std::mktime(&tempo);

        if(dataHoraEvento - dataHoraAtual == 3600) {
            return true;
        }
    }
    
    return false;
}

//métodos para verificar se o evento é quinze minutos antes
bool Notificacao::quinzeMinutosAntes(const std::vector<Evento>& eventos) {
    for(int i = 0; i < eventos.size(); i++) {
        std::string dataHora = eventos[i].getData() + " " + eventos[i].getHora();
        std::tm tempo = {};
        std::istringstream dado(dataHora);
        dado >> std::get_time(&tempo, "%d/%m/%Y %H:%M");

        if (dado.fail()) {
            std::cout << "Data ou hora invalida!" << std::endl;
            return false;
        }
        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::time_t dataHoraEvento = std::mktime(&tempo);

        if(dataHoraEvento - dataHoraAtual == 900) {
            return true;
        }
    }

    return false;
}

//método para exibir a notificação
void Notificacao::exibirNotificacao(const std::vector<Evento>& eventos){

    bool semana = umaSemanaAntes(eventos);      //boolenas para verificar se o evento é uma semana antes
    bool tresDias = tresDiasAntes(eventos);     //boolenas para verificar se o evento é três dias antes
    bool umDia = umDiaAntes(eventos);       //boolenas para verificar se o evento é um dia antes
    bool umaHora = umaHoraAntes(eventos);       //boolenas para verificar se o evento é uma hora antes
    bool quinzeMinutos = quinzeMinutosAntes(eventos);       //boolenas para verificar se o evento é quinze minutos antes
    bool notifProva = semana || tresDias || umDia || umaHora || quinzeMinutos;      //boolenas para verificar se o evento é uma prova
    bool notifTrabalho = tresDias || umDia || umaHora || quinzeMinutos;     //boolenas para verificar se o evento é um trabalho
    bool notifApresentacao = umDia || umaHora || quinzeMinutos;     //boolenas para verificar se o evento é uma apresentação
    bool notifOutro = tresDias || umaHora;      //boolenas para verificar se o evento é outro
    
    //verifica se o evento é uma prova
    if(notifProva){     
        for(int i = 0; i < eventos.size(); i++){        //percorre o vetor de eventos
            std::string tipo = eventos[i].getTipo();     
            if(tipo == "PROVA"){      //verifica se o evento é uma prova
                //imprime o evento
                std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
                std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
                std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
                std::cout << "Data: " << eventos[i].getData() << std::endl;
                std::cout << "Hora: " << eventos[i].getHora() << std::endl;
                std::cout << "Local: " << eventos[i].getLocal() << std::endl;
                std::cout << std::endl;
            }
        }
    }

    //verifica se o evento é um trabalho
    if(notifTrabalho){      
        for(int i = 0; i < eventos.size(); i++){        //percorre o vetor de eventos
            std::string tipo = eventos[i].getTipo();     //verifica se o evento é um trabalho
            if(tipo == "TRABALHO"){       //verifica se o evento é um trabalho
                //imprime o evento
                std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
                std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
                std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
                std::cout << "Data: " << eventos[i].getData() << std::endl;
                std::cout << "Hora: " << eventos[i].getHora() << std::endl;
                std::cout << "Local: " << eventos[i].getLocal() << std::endl;
                std::cout << std::endl;
            }
        }
    }

    //verifica se o evento é uma apresentação
    if(notifApresentacao){      
        for(int i = 0; i < eventos.size(); i++){        //percorre o vetor de eventos
            std::string tipo = eventos[i].getTipo();     //verifica se o evento é uma apresentação   
            if(tipo == "APRESENTACAO"){       //verifica se o evento é uma apresentação
                //imprime o evento
                std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
                std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
                std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
                std::cout << "Data: " << eventos[i].getData() << std::endl;
                std::cout << "Hora: " << eventos[i].getHora() << std::endl;
                std::cout << "Local: " << eventos[i].getLocal() << std::endl;
                std::cout << std::endl;
            }
        }
    }

    //verifica se o evento é outro
    if(notifOutro){
        for(int i = 0; i < eventos.size(); i++){        //percorre o vetor de eventos
            std::string tipo = eventos[i].getTipo();         //verifica se o evento é outro   
            if(tipo == "OUTRO"){              //verifica se o evento é outro
                //imprime o evento
                std::cout << "Tipo: " << eventos[i].getTipo() << std::endl;
                std::cout << "Titulo: " << eventos[i].getTitulo() << std::endl;
                std::cout << "Descricao: " << eventos[i].getDescricao() << std::endl;
                std::cout << "Data: " << eventos[i].getData() << std::endl;
                std::cout << "Hora: " << eventos[i].getHora() << std::endl;
                std::cout << "Local: " << eventos[i].getLocal() << std::endl;
                std::cout << std::endl;
            }
        }
    }
}