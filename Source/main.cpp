#include <iostream>
#include <thread>
#include <utility>

#include "Game/character.h"
#include "Utils/Math.h"

int main()
{
    Character hero1("Durden");
    Character hero2("Angel Face");
    Character* attacker = &hero1;
    Character* defender = &hero2;
    int round{1};
    bool lastFireStatus = true;

    while (true)
    {
        std::cout << "====hello, ladies and jentllemans!!!\n";

        std::cout << "============== Round " << round++ << " ==================" << std::endl;
        bool fired = attacker->attack(*defender);
        /*if (!lastFireStatus && !fire d)*/
        if (!lastFireStatus && !fired)
        {
            std::cout << "============== GAME OVER ==================" << std::endl;
            std::cout << attacker->name() << " friendship wins !!!" << std::endl;

            break;
        }

        lastFireStatus = fired;

        if (defender->dead())
        {
            std::cout << std::endl;
            std::cout << "============== GAME OVER ==================" << std::endl;
            std::cout << defender->name() << " is dead =(" << std::endl;
            std::cout << attacker->name() << " wins !!!" << std::endl;
            break;
        }

        std::swap(attacker, defender);
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cin.get();
    return 0;
}
