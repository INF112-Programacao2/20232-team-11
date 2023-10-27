#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

class Professor : public Usuario{
private:
    const std::string _id;
    const std::string _senha;
public:
    std::string get_senha() const;
    std::string get_id() const override;
};


#endif