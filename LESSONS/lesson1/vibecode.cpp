// типы данных
// bool
// float
// int
// string
// char
// long long
// double
// size_t - размер контейнера (индекс памяти)
// int32_t - точный 32 битный int
// uint32_t - unsigned 
// int64_t - точный 64 битный int

// отличие float от double
// float - занимает 4 байта
// double - 8 байт
// занимает и выделяет больше памяти
// int: hp, кол-во предметов, уровней, очеов опыта, индексов
// float: коорды, скорости, дельта времени, множитель уровня, плавная анимация
// double: используем там же где и float, но для более точного значения или обработки real-time 
// беззнаковый тип:
// кажется удобным что переменная не может быть отрицательной, но:
// unsigned int gold = 0;
// gold = gold - 1;
// если unsigned тип уходит в минус, то он перекрутится в огромное число
// int: 0 -> 2 147 483 647
// так же мы не можем класть int число в uint - даже если оно положительное 
// gold = max(0, gold - cost)

// static_cast -> конвертация типа данных, что и .toInt()
// int damage = static_cast<int>(baseDamage * multiplier)
// явная смена типа даных 

#include <iostream>

// i -> in
// o -> out
// stream - поток

#include <limits>
// для просмотра границ типов данных
 
#include <cstdint>
// подключаем фикс типа данных (int32_t, int64_t)

using namespace std;

#include <string>
#include <vector>

enum class ItemType
{
    Weapon,
    Armor,
    Potion
};

// data class -> struct

struct Item
{
    string id;
    string name;
    ItemType type;
    int maxStack;
};

struct ItemStack
{
    Item item;
    int count;
};

struct Enemy
{
    string name;
    int hp;
    int armor;
};

int CalculateDamage(int baseDamage, float critMultiplier, int armor)
{
    float damage = baseDamage * critMultiplier;
    damage -= armor;
    if (damage < 0)
        damage = 0;
    return static_cast<int>(damage);
}

void ApplyDamage(Enemy& enemy, int damage)
{
    enemy.hp -= damage;
    if (enemy.hp < 0)
        enemy.hp = 0;
}

string ItemTypeToText(ItemType type)
{
    switch(type)
    {
        case ItemType::Weapon: return "Weapon";
        case ItemType::Armor: return "Armor";
        case ItemType::Potion: return "Potion";
    }
}

void PrintStack(const ItemStack& stack)
{
    cout << stack.item.name;
    cout << " x" << stack.count;
    cout << " [" << ItemTypeToText(stack.item.type) << "]";
    cout << endl;
}

int main()
{
    // setlocale(LC_ALL, "Russian");
    // cout << "bool: " << sizeof(bool) << " байт" << endl;
    // cout << "char: " << sizeof(char) << " байт" << endl;
    // cout << "int: " << sizeof(int) << " байт" << endl;
    // cout << "float: " << sizeof(float) << " байт" << endl;
    // cout << "double: " << sizeof(double) << " байт" << endl;
    // cout << "int: " << sizeof(int) << " байт" << endl;
    // cout << "int32_t: " << sizeof(int32_t) << " байт" << endl;
    // cout << "int64_t: " << sizeof(int64_t) << " байт" << endl;
    // cout << endl;
    // cout << "Лимиты тд" << endl;
    //
    // cout << "int min: " << numeric_limits<int>::min() << endl;
    // cout << "int max: " << numeric_limits<int>::max() << endl;
    // cout << "float min: " << numeric_limits<float>::min() << endl;
    // cout << "float max: " << numeric_limits<float>::max() << endl;
    // cout << "double min: " << numeric_limits<double>::min() << endl;
    // cout << "double max: " << numeric_limits<double>::max() << endl;
    
    Item potion { "potion_heal", "Healing", ItemType::Potion, 10};
    Item sword { "sword", "Sword", ItemType::Weapon, 1};
    
    // Списки -> это vector
    vector<ItemStack> inventory;
    
    inventory.push_back(ItemStack{potion, 6});
    inventory.push_back(ItemStack{sword, 1});
    
    cout << "inventory: "<< endl;
    for (const ItemStack& stack : inventory)
    {
        PrintStack(stack);
    }

    Enemy goblin { "Goblin", 50, 5 };
    int damage = CalculateDamage(20, 1.5f, goblin.armor);
    ApplyDamage(goblin, damage);
    cout << goblin.name << " HP: " << goblin.hp << endl;
    
    return 0;
}



























