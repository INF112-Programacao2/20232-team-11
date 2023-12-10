#include "Evento.hpp"

Evento::Evento(){}  // Construtor

Evento::Evento(const std::string &tipo, const std::string &titulo, const std::string &descricao, const std::string &data, const std::string &hora, const std::string &local, const std::string &criador, const std::string id) : _tipo(tipo), _titulo(titulo), _descricao(descricao), _data(data), _hora(hora), _local(local), _criador(criador), _id(id) {}    // Construtor

Evento::~Evento() {}    // Destrutor

//metodos get
std::string Evento::getTipo() const {
    return _tipo;
}

std::string Evento::getTitulo() const {
    return _titulo;
}

std::string Evento::getDescricao() const {
    return _descricao;
}

std::string Evento::getData() const {
    return _data;
}

std::string Evento::getHora() const {
    return _hora;
}

std::string Evento::getLocal() const {
    return _local;
}

std::string Evento::getCriador() const {
    return _criador;
}

std::string Evento::getId() const {
    return _id;
}

// Métodos set
void Evento::setTipo(const std::string& tipo) {
    _tipo = tipo;
}

void Evento::setTitulo(const std::string& titulo) {
    _titulo = titulo;
}

void Evento::setDescricao(const std::string& descricao) {
    _descricao = descricao;
}

void Evento::setData(const std::string& data) {
    _data = data;
}

void Evento::setHora(const std::string& hora) {
    _hora = hora;
}

void Evento::setLocal(const std::string& local) {
    _local = local;
}

void Evento::setCriador(const std::string& criador) {
    _criador = criador;
}
