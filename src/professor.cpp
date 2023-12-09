#include "Professor.hpp"

Professor::Professor() {}  // Construtor

Professor::~Professor() {}  // Destrutor

// Métodos

// Métodos para pesquisar eventos por tipo
void Professor::pesquisarEventoPorTipo() {
    std::cout << "==============PESQUISANDO EVENTO POR TIPO==============\n\n";
    std::string tipo, id;    // Variaveis para armazenar o tipo de evento, o tipo de usuario e o id do usuario
    std::cout << "Digite o tipo de evento a ser pesquisado (ACADEMICO, PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
    std::getline(std::cin, tipo);   // Recebe o tipo de evento
    while(tipo != "ACADEMICO" && tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "PESSOAL") {    // Verifica se o tipo de evento e valido
        std::cout << "Tipo de evento invalido!" << std::endl;
        std::cout << "Digite o tipo de evento a ser pesquisado (ACADEMICO, PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
        std::getline(std::cin, tipo);   // Recebe o tipo de evento
    }

    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }

    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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

        if (tipo != "PESSOAL" && ((tipo == tipoEvento) && (criador == "PROF" || criador == "ADMIN"))) {   // Verifica se o tipo de evento e o id do usuario existem
            Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
            imprimirEvento(evento); // Imprime o evento
            eventoEncontrado = true;  //eventoEncontrado recebe true
        }else if(tipo == "PESSOAL"){
            if(id == idEvento){
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
            }
        }
    }

    if(!eventoEncontrado) {   // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/



// Métodos para pesquisar eventos por título
void Professor::pesquisarEventoPorTitulo() {
    std::cout << "==============PESQUISANDO EVENTO POR TITULO==============\n\n";
    std::string titulo, id;   // Variaveis para armazenar o titulo, o tipo e o id do usuario
    std::cout << "Digite o titulo do evento a ser pesquisado: ";
    std::getline(std::cin, titulo); // Recebe o titulo do evento

    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

   std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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

        if(((titulo == tituloEvento && criador == "ADMIN") || (titulo == tituloEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
            Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
            imprimirEvento(evento); // Imprime o evento
            eventoEncontrado = true;    //eventoEncontrado recebe true
        }else if(titulo == tituloEvento && tipoEvento == "PESSOAL"){
            if(id == idEvento){
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para pesquisar eventos por data
void Professor::pesquisarEventoPorData() { 
    std::cout << "==============PESQUISANDO EVENTO POR DATA==============\n\n"; 
    std::string data, id;   // Variaveis para armazenar a data e o tipo de usuario
    std::cout << "Digite a data do evento a ser pesquisado (DD-MM-AAAA): ";
    std::getline(std::cin, data);   // Recebe a data do evento
    if(data.size() != 10 || data[2] != '-' || data[5] != '-') { // Verifica se a data possui o tamanho correto
        std::cout << "Data invalida!" << std::endl;
        return; // sai da funcao
    }

    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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

        if((data == dataEvento && criador == "ADMIN") || (data == dataEvento && criador == "PROF") && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
            Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
            imprimirEvento(evento); // Imprime o evento
            eventoEncontrado = true;    //eventoEncontrado recebe true
        }else if(data == dataEvento && tipoEvento == "PESSOAL"){
            if(id == idEvento){
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para listar todos os eventos
void Professor::listarEventosTodos() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS==============\n\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario
   
    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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

        if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
            Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
            imprimirEvento(evento); // Imprime o evento
            eventoEncontrado = true;  //eventoEncontrado recebe true
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

void Professor::exibirNotificacoes(){
    std::cout << "=======CALENDARIO ACADEMICO=======\n\n";
    std::cout << "---------Você tem notificação!---------\n\n";
    bool encontrado = false; // variável para verificar se o evento foi encontrado
    bool notificacao = false; // variável para verificar se a notificação foi encontrada
    int cont = 0; // variável para contar o número de notificações
    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;

    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);    //cria um fluxo de string
        std::string linha, tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;  //variáveis para armazenar os dados do evento

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
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
        if(dataHoraEvento - dataHoraAtual > 0 ){
            notificacao = true;
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "PROF") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual && (((dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) || (dataHoraEvento - dataHoraAtual) <= 3600) { 
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    imprimirEvento(evento); // Imprime o evento
                    std::cout << "**********************************" << std::endl;
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

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

int Professor::getNumeroNotificacao(){
    bool encontrado = false; // variável para verificar se o evento foi encontrado
    bool notificacao = false; // variável para verificar se a notificação foi encontrada
    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        return 0; // sai da funcao
    }

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;

    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);    //cria um fluxo de string
        std::string linha, tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;  //variáveis para armazenar os dados do evento

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
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
       
        if(dataHoraEvento - dataHoraAtual > 0 ){
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && idEvento == getId()) || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual && (((dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) || (dataHoraEvento - dataHoraAtual) <= 3600) { 
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    eventos.push_back(evento);
                }
            }
        }
    }

    for(const auto& evento : eventos){
        if(evento.getTipo() == "ACADEMICO"){
            contEventoAcademico++;
        }else if(evento.getTipo() == "PESSOAL"){
            contEventoPessoal++;
        }else if(evento.getTipo() == "APRESENTACAO"){
            contEventoApresentacao++;
        }else if(evento.getTipo() == "PROVA"){
            contEventoProva++;
        }else if(evento.getTipo() == "TRABALHO"){
            contEventoTrabalho++;
        }
    }

    return eventos.size();
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


void Professor::contTipoEvento() const {
    std::cout << "- " << contEventoAcademico << " eventos academicos" << std::endl;
    std::cout << "- " << contEventoPessoal << " eventos pessoal" << std::endl;
    std::cout << "- " << contEventoApresentacao << " eventos de apresentacao" << std::endl;
    std::cout << "- " << contEventoProva << " eventos de prova" << std::endl;
    std::cout << "- " << contEventoTrabalho << " eventos de trabalho" << std::endl;
}