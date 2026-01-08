#pragma once

#ifdef WIN32 || _WINDOWS

    #ifdef _EXPORTING
        #define GAME_API __declspec(dllexport)
    #elif _IMPOTING
        #define GAME_API __declspec(dllimport)
    #else
        #define GAME_API
    #endif
#else
    #define GAMEAPI __attribute__((visibility("default")))
#endif 
class Weapon;

class GAME_API Character
{
   public:
    Character(const char* name);
    ~Character();
    bool attack(Character& target);
    void takeDamage(int damage);
    int health() const;
    int dead() const;
    bool isEmpty() const;
    const char* name();

   private:
    const char* m_name;
    Weapon* m_weapon;
    int m_health{100};
    bool m_empty{false};
};