#include "Aluno.hpp"

Aluno::Aluno() {}    // Construtor
Aluno::~Aluno() {}      // Destrutor

//Metodos

// Métodos para pesquisar eventos por tipo
void Aluno::pesquisarEventoPorTipo() {
    std::cout << "==============PESQUISANDO EVENTO POR TIPO==============\n";
    std::string tipo, id;    // Variaveis para armazenar o tipo de evento, o tipo de usuario e o id do usuario
    std::cout << "Digite o tipo de evento a ser pesquisado (ACADEMICO, PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
    std::getline(std::cin, tipo);   // Recebe o tipo de evento
    if(tipo != "ACADEMICO" && tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "PESSOAL") {    // Verifica se o tipo de evento e valido
        std::cout << "Tipo de evento invalido!" << std::endl;
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
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
            if (tipo != "PESSOAL" && ((tipo == tipoEvento) && (criador == "PROF" || criador == "ADMIN"))) {   // Verifica se o tipo de evento e o id do usuario existem
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
            if(tipo != "PESSOAL" && ((tipo == tipoEvento) && (criador == "PROF" || criador == "ADMIN"))) {   // Verifica se o tipo de evento e o id do usuario existem
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
void Aluno::pesquisarEventoPorTitulo() {
    std::cout << "==============PESQUISANDO EVENTO POR TITULO==============\n";
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
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
void Aluno::pesquisarEventoPorData() { 
    std::cout << "==============PESQUISANDO EVENTO POR DATA==============\n"; 
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
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
            if ((data == dataEvento && criador == "ADMIN") || ((data == dataEvento && criador == "PROF") && tipoEvento != "PESSOAL")) {   // Verifica se o titulo e o id do usuario existem
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
            if((data == dataEvento && criador == "ADMIN") || ((data == dataEvento && criador == "PROF") && tipoEvento != "PESSOAL")) {   // Verifica se o titulo e o id do usuario existem
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
void Aluno::listarTodosEventosFuturos() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS==============\n";
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
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
        
        if(dataHoraEvento - dataHoraAtual > 0 ){ // Verifica se a data do evento e posterior a data atual
            if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }
        }else{
            eventoEncontrado = false;
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
void Aluno::listarTodosEventosPassados() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS==============\n";
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
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
        
        if(dataHoraEvento - dataHoraAtual < 0 ){ // Verifica se a data do evento e posterior a data atual
            if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }
        }else{
            eventoEncontrado = false;
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
void Aluno::exibirNotificacoes(){
    std::cout << "=======CALENDARIO ACADEMICO=======" << std::endl;
    std::cout << std::endl;
    std::cout << "---------Você tem notificação!---------" << std::endl;
    std::cout << std::endl;
    bool notificacao = false; // variável para verificar se a notificação foi encontrada
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
        if(dataHoraEvento - dataHoraAtual > 0 ){ // Verifica se a data do evento e posterior a data atual
            notificacao = true;
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ALUNO") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if(tipoEvento == "PROVA"){                                          // 1 semana em segundos (1 semaine * 7 jours * 24 heures * 60 minutes * 60 secondes = 604800)
                    if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 604800) || ((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400)) || ((dataHoraEvento - dataHoraAtual) <= 3600)))  {    
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }                                                                // 15 minutos em segundos (15 minutes * 60 secondes = 900)
                }else if(tipoEvento == "TRABALHO"){                                 // 3 dias em segundos (3 jours * 24 heures * 60 minutes * 60 secondes = 259200)
                    if (dataHoraEvento >= dataHoraAtual && (((((dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) ||((dataHoraEvento - dataHoraAtual) <= 3600)) || ((dataHoraEvento - dataHoraAtual) <= 900))) {    
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }                                                                                               //uma hora em segundos (1 heure * 60 minutes * 60 secondes = 3600)
                }else if(tipoEvento == "APRESENTACAO" || tipoEvento == "ACADEMICO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                    if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400)) || ((dataHoraEvento - dataHoraAtual) <= 3600))) { 
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }
                }else if(tipoEvento == "PESSOAL" && criador == "ALUNO"){
                    if (dataHoraEvento >= dataHoraAtual && (((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400) || ((dataHoraEvento - dataHoraAtual) <= 3600))) { 
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }
                
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


// Métodos para retornar o número de notificações
int Aluno::getNumeroNotificacao(){

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
       
        if(dataHoraEvento - dataHoraAtual > 0 ){ //
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ALUNO") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual) { //
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


// Métodos para contar o número de eventos por tipo
void Aluno::contTipoEvento() const {
    std::cout << "- " << contEventoAcademico << " eventos academicos" << std::endl;
    std::cout << "- " << contEventoPessoal << " eventos pessoal" << std::endl;
    std::cout << "- " << contEventoApresentacao << " eventos de apresentacao" << std::endl;
    std::cout << "- " << contEventoProva << " eventos de prova" << std::endl;
}