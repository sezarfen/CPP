#include "Character.hpp"

Character::Character( void )
{
    std::cout << "Character constructor called" << std::endl;
    this->name = "Unknown Character";
    for(int i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

Character::Character( const Character& other )
{
    this->name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] != NULL)
        {
            if (other.materias[i] != NULL)
            {
                delete this->materias[i];
                if (other.materias[i]->getType() == "ice")
                    this->materias[i] = new Ice();
                else
                    this->materias[i] = new Cure();    
            }
            else
            {
                delete this->materias[i];
                this->materias[i] = NULL;
            }
        }
        else
        {
            if (other.materias[i]->getType() == "ice")
                this->materias[i] = new Ice();
            else
                this->materias[i] = new Cure(); 
        }
    }
}

Character::Character( std::string const& name )
{
    this->name = name;
    for(int i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

Character::~Character( void )
{
    std::cout << "Character class destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] != NULL)
            delete this->materias[i];
    }
}

Character& Character::operator=( const Character& other )
{
    if (this == &other) // if they do c1 = c1, this statement expect to happen;
        return (*this);
    
    this->name = other.name;

    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] != NULL)
        {
            if (other.materias[i] != NULL)
            {
                delete this->materias[i];
                if (other.materias[i]->getType() == "ice")
                    this->materias[i] = new Ice();
                else
                    this->materias[i] = new Cure(); 
            }
            else
            {
                delete this->materias[i];
                this->materias[i] = NULL;
            }
        }
        else
        {
            if (other.materias[i]->getType() == "ice")
                this->materias[i] = new Ice();
            else
                this->materias[i] = new Cure(); 
        }
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->name);
}

// They can not equip new Materia, if the inventory is full
void Character::equip( AMateria* m )
{
    for (int i = 0; i < 4; i++) // because they might fulfill the indexed 1 2 [] 4 // 3 is empty, subject says, first empty slot they find
    {
        if (this->materias[i] == NULL)
            this->materias[i] = m;
    }
}

void Character::unequip( int idx )
{
    if (idx < 0 || idx > 3)
        return ;
    if (this->materias[idx] != NULL)
    {
        delete this->materias[idx];
        this->materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        return ;
    if (this->materias[idx] != NULL)
        this->materias[idx]->use(target);
}
