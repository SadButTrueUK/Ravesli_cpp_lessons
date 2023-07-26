#include <string>
#include <iostream>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


class Creature
{
    protected:
        std::string m_name;
        char m_symbol;
        int m_health;
        int m_damage;
        int m_gold;
    public:
        Creature(std::string name, char symbol, int health, int damage, int gold)
                : m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
        {
        }
        const std::string getName() const { return m_name; }
        char getSymbol() const { return m_symbol; }
        int getHealth() const { return m_health; }
        char getDamage() const { return m_damage; }
        int getGold() const { return m_gold; }
        void reduceHealth(int health) { m_health -= health; }
        bool isDead() const { return m_health <= 0; }
        void addGold(int gold) { m_gold += gold; }
};


class Player : public Creature
{
    private:
        int m_level{1}; 
    public:    
        Player(std::string name) : Creature(name, '@', 10, 1, 0)
        {        
        }
        void levelUp()
        {
            ++m_level;
            ++m_damage;
        }
        int getLevel() const { return m_level; }
        bool hasWon() const { return m_level >= 20; }
};


class Monster : public Creature
{
    public:
        enum Type
        {
            DRAGON,
            ORC,
            SLIME,
            MAX_TYPES
        };
        struct MonsterData
        {
            std::string m_name;
            char m_symbol;
            int m_health;
            int m_damage;
            int m_gold;
        };
        static MonsterData monsterData[MAX_TYPES];
        
        static Monster getRandomMonster()
        {
            int num = getRandomNumber(0, MAX_TYPES - 1);
            return Monster(static_cast<Type>(num));
        }
        
        Monster(Type type) 
        : Creature(monsterData[type].m_name, monsterData[type].m_symbol, 
          monsterData[type].m_health, monsterData[type].m_damage, monsterData[type].m_gold)
        {
        }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

// Этот метод обрабатывает атаку монстра игроком
void attackMonster(Player &p, Monster &m)
{
	// Checking if player is dead
	if (p.isDead())
		return;
 
	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
 
	// Здоровье монстра уменьшается от урона игрока
	m.reduceHealth(p.getDamage());
 
	// Если монстр мертв, то увеличиваем level игрока
	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}
 
// Этот метод обрабатывает атаку игрока монстром
void attackPlayer(Monster &m, Player &p)
{
	// Если монстр мертв, то он не может атаковать игрока
	if (m.isDead())
		return;
 
	// Здоровье игрока уменьшается от урона монстра
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}
 
// Play process handling
void fightMonster(Player &p)
{
	// Сначала генерируем рандомного монстра
	Monster m = Monster::getRandomMonster();
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
	
	// Пока монстр или игрок не мертв, то бой продолжается
	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input;
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50/50 шанс удачного побега
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // встречу с монстром удалось избежать
			}
			else
			{
				// Неудачная попытка побега дает монстру право атаковать
				std::cout << "You failed to flee.\n";
				attackPlayer(m, p);
				continue;
			}
		}
 
		if (input == 'F' || input == 'f')
		{
			// Сначала атакует игрок, затем монстр
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

int main()
{
	/* Creature o("orc", 'o', 4, 2, 10);
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.";
    std::cout << '\n';
    
    std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;
 
	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << ".\n";
 
	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.";
    std::cout << '\n';
    
    Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат
 
	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	} */

    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат
 
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;
 
	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << '\n';
 
	// Если игрок не мертв и еще не победил, то игра продолжается
	while (!p.isDead() && !p.hasWon())
		fightMonster(p);
 
	// К этому моменту игрок либо мертв, либо победил
	if (p.isDead())
	{
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << p.getGold() << " gold!\n";
	}

	return 0;
}