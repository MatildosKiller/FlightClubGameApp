#include "Character.h"

#include <iostream>

#include "Utils/Math.h"
#include "Weapon.h"

Character::Character(const char* name) : m_name{name}
{
    const int bulletsCount = LifeExe::randomInt(1, 10);
    m_weapon = new Weapon(bulletsCount);
}

Character::~Character() {}

bool Character::attack(Character& target)
{
    const bool fired = m_weapon->fire();
 
    if (fired)
    {
        const int damage = m_weapon->damage();
        target.takeDamage(damage);
        std::cout << m_name << " is attacked with damage: " << damage << std::endl;
    }
    else
    {
        std::cout << m_name << " has no more bullets, shit... bad day...: " << m_health
                  << std::endl;
        m_empty = true;
    }

    return fired;
}

void Character::takeDamage(int damage)
{
    m_health -= damage;
    if (m_health < 0)
        m_health = 0;

    std::cout << m_name << " was attacked, current health: " << m_health << std::endl;
}

int Character::health() const { return m_health; }

int Character::dead() const { return m_health == 0; }

bool Character::isEmpty() const { return m_empty; }

const char* Character::name() { return m_name; }
