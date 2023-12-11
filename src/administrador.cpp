#include "Administrador.hpp"

Administrador::Administrador() {} // Construtor

Administrador::~Administrador() {}  // Destrutor

// Métodos

// Métodos para pesquisar eventos por tipo
void Administrador::pesquisarEventoPorTipo() {
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual
            if (((tipo == tipoEvento && criador == "ADMIN") || (tipo == tipoEvento && criador == "PROF")) && tipo != "PESSOAL") {   // Verifica se o tipo de evento e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento futuro" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
            }else if(tipo == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento futuro" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;  //eventoEncontrado recebe true
                }
            }
        }else{
            if(((tipo == tipoEvento && criador == "ADMIN") || (tipo == tipoEvento && criador == "PROF")) && tipo != "PESSOAL") {   // Verifica se o tipo de evento e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento passado" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
            }else if(tipo == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento passado" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;  //eventoEncontrado recebe true
                }
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
void Administrador::pesquisarEventoPorTitulo() {
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

    //percorre o arquivo de usuários para encontrar o id do usuário

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;  //variavel para verificar se o evento foi encontrado
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual
            if(((titulo == tituloEvento && criador == "ADMIN") || (titulo == tituloEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento futuro" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(titulo == tituloEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento futuro" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
            }
        }else{
            if(((titulo == tituloEvento && criador == "ADMIN") || (titulo == tituloEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento passado" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(titulo == tituloEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento passado" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
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
void Administrador::pesquisarEventoPorData() { 
    std::cout << "==============PESQUISANDO EVENTO POR DATA==============\n\n"; 
    std::string data, id;   // Variaveis para armazenar a data e o tipo de usuario
    std::cout << "Digite a data do evento a ser pesquisado (DD-MM-AAAA): ";
    std::getline(std::cin, data);   // Recebe a data do evento
    if(!Usuario::dataValida(data)) { // Verifica se a data possui o tamanho correto
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

    bool eventoEncontrado = false;  //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado
    std::string linha;

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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual
            if (((data == dataEvento && criador == "ADMIN") || (data == dataEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento futuro" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(data == dataEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento futuro" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
            }
        }else{
            if(((data == dataEvento && criador == "ADMIN") || (data == dataEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento passado" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(data == dataEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento passado" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
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


// Métodos para listar todos os eventos futuros
void Administrador::listarTodosEventosFuturos() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS FUTUROS==============\n\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario
   
    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0 ){
            if (id == idEvento || (criador == "PROF" && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
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


// Métodos para listar todos os eventos passados
void Administrador::listarTodosEventosPassados() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS PASSADOS==============\n\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario
   
    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual < 0 ){
            if (id == idEvento || (criador == "PROF" && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
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



// Métodos para exibir notificações
void Administrador::exibirNotificacoes(){
    std::cout << "=======CALENDARIO ACADEMICO=======\n\n";
    std::cout << "---------Você tem notificação!---------\n\n";
    bool notificacao = false; // variável para verificar se a notificação foi encontrada
    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
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
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ADMIN") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual && (((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400) || ((dataHoraEvento - dataHoraAtual) <= 3600))) { 
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    imprimirEvento(evento); // Imprime o evento
                    std::cout << "**********************************" << std::endl;
                    std::cout << std::endl;
                    notificacao = true;
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


//metodo para exibir o numero de notificacoes
int Administrador::getNumeroNotificacao(){
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
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ADMIN") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual) { 
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    eventos.push_back(evento);
                    if(tipoEvento == "ACADEMICO"){
                        contEventoAcademico++;
                    }else if(tipoEvento == "PESSOAL"){
                        contEventoPessoal++;
                    }else if(tipoEvento == "APRESENTACAO"){
                        contEventoApresentacao++;
                    }else if(tipoEvento == "PROVA"){
                        contEventoProva++;
                    }else if(tipoEvento == "TRABALHO"){
                        contEventoTrabalho++;
                    }
                }
            }
        }
    }

    return eventos.size();
}





/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

//metodo para contar o numero de eventos por tipo
void Administrador::contTipoEvento() const {
    std::cout << "- " << contEventoAcademico << " eventos academicos" << std::endl;
    std::cout << "- " << contEventoPessoal << " eventos pessoal" << std::endl;
    std::cout << "- " << contEventoApresentacao << " eventos de apresentacao" << std::endl;
    std::cout << "- " << contEventoProva << " eventos de prova" << std::endl;
}

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

//metodo para imprimir calendario com os eventos
void Administrador::calendarioComEventos(){

    std::set<int> diasEventos;  //variável para armazenar os dias dos eventos
    std::ifstream arquivoEventos("eventos.txt");

    if (!arquivoEventos.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string linha, tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;
        std::string palavra;

        // Ler os dados do arquivo
        std::getline(ss, tipoEvento, '|');  
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ADMIN") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA"){
            std::istringstream dataStream(dataEvento); // Criar um fluxo de string para a data
            std::string token;
            while (std::getline(dataStream, token, '-')) { // Percorrer a string separando por '-'
                try {
                    int diaEvento = std::stoi(token); // Converter a parte da data para inteiro
                    diasEventos.insert(diaEvento); // Inserir o dia do evento no conjunto
                } catch (const std::invalid_argument& e) {
                    std::cout << "Erreur sistema" << e.what() << std::endl;
                }
            }
        }
    }
    arquivoEventos.close();

    time_t agora = time(0); //variável para armazenar a data e hora atual
    tm *tempo = localtime(&agora);  //variável para armazenar a data e hora atual
    int mesAtual = tempo->tm_mon;   //variável para armazenar o mês atual
    int anoAtual = tempo->tm_year + 1900;   //variável para armazenar o ano atual

    //logica para imprimir o calendario
    int diasPorMes[] = {31, ((anoAtual % 4 == 0 && anoAtual % 100 != 0) || anoAtual % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string nomesMeses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    std::cout << "Calendário para os eventos de " << nomesMeses[mesAtual] << " de " << anoAtual << ":" << std::endl;
    std::cout << "______________________" << std::endl;
    std::cout << "|      " << nomesMeses[mesAtual] << "       |" << std::endl;
    std::cout << "|____________________|" << std::endl;
    std::cout << "| Seg Ter Qua Qui Sex Sáb Dom |" << std::endl;
    std::cout << "|____________________|" << std::endl;

    int dia = 1;
    tm primeiroDia = { 0, 0, 0, 1, mesAtual, anoAtual - 1900 }; //variável para armazenar o primeiro dia do mês
    mktime(&primeiroDia);
    int primeiroDiaSemana = primeiroDia.tm_wday;    //variável para armazenar o primeiro dia da semana

    for (int i = 0; i < primeiroDiaSemana; i++) {       // Imprime os espaços para o primeiro dia da semana
        std::cout << "    ";
    }

    while (dia <= diasPorMes[mesAtual]) {   // Imprime os dias do mês enquanto o dia for menor ou igual ao último dia do mês
        for (int i = primeiroDiaSemana; i < 7 && dia <= diasPorMes[mesAtual]; i++) {    
            if (diasEventos.find(dia) != diasEventos.end()) {   // Verifica se o dia possui evento
                std::cout << std::setw(2) << dia << "* ";
            } else {
                std::cout << std::setw(3) << dia << " ";
            }
            dia++;
        }
        std::cout << std::endl;
        primeiroDiaSemana = 0;  // Reseta o primeiro dia da semana
    }
    std::cout << std::endl;
}