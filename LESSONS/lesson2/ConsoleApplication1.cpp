// передача параметров функции
// передача по значению

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

void TakeDamage(int hp, int damage)
{
    hp = hp - damage;
}
// здесь hp копируется
// если ывзвать 

// int playerHp = 100;
// TakeDamage(playerHp, 30);
// то hp отнимится но playerHp останется 100

// передача по ссылке
// void TakeDamage(int& hp, int damage)
// {
//     hp = hp - damage;
// }
// int& hp означает:
// hp - это ссылка на ориг переменную

struct  CharacterStats
{
    string name;
    int hp;
    int maxHp;
    int damage;
};

// передача по const-ссылке
// подходит когда объекты передаются большими, но функция не должна их менять
void PrintPlayer(const CharacterStats& stats)
{
    cout << stats.name << endl;
    cout << stats.hp << "/" << stats.maxHp << endl;
    cout << stats.damage << endl;
}
// const - запрещает менять объект
// & - позволяет не копировать объект

// передача через указатель
// указатель похож на ссылку но он может быть пкстым
// null ptr - nul Pointer (указатель)
void Heal(int* hp, int* amount);
// функция принимате адрес переменной hp

void HealByPointer(int* hp, int amount, int maxHp)
{
    if (hp == nullptr)
    {
        return;
    }
    
    *hp = *hp + amount; // разыменование указателя ( изменение ориг значения)
    
    if (*hp > maxHp)
    {
        *hp = maxHp;
    }
}

int CalculateDamage(int baseDamage, float multiplier, int armor)
{
    float damage = baseDamage * multiplier;
    float afterArmor = damage - armor;
    if (afterArmor < 0)
        afterArmor = 0;
    return static_cast<int>(round(afterArmor));
}

int main()
{
    CharacterStats oleg{"Oleg", 80, 100, 20};
    PrintPlayer(oleg);
    
    int playerHP = 50;
    int maxHP = 100;
    
    HealByPointer(&playerHP, 50, maxHP); // передаем адрес playerHp через оператор &
    
    cout << "player HP: " << playerHP << endl;
    
    int baseDamage = 50;
    float multiplier = 2.5;
    int armor = 70;
    cout << CalculateDamage(baseDamage, multiplier, armor);
    
    // &playerHp - это адрес переменной
    // *hp  - это указатель на значение по этому адресу
    
    return 0;
}