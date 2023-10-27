#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

class Professor : public Usuario{
private:
public:
    Professor(const std::string id, const std::string senha);
    ~Professor();
    std::string get_senha() const override;
    std::string get_id() const override;
};


#endif