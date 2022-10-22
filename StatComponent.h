#include <memory>
#include <vector>
#include <string>
#include <functional>


class StatComponent {
public:
	std::string name;
	float Level;
	float maxHP;
	float HP;
	float maxMP;
	float MP;
	float Attack;
	float Defense;
	float Exp;
	
	template<class Archive>
		  void serialize(Archive & archive)
		  {
		    archive( Level, maxHP, HP, maxMP, MP, Attack, Defense, Exp); // serialize things by passing them to the archive
		  }
};

class Entity : public std::enable_shared_from_this<Entity> {
	std::shared_ptr<Entity> Parent;

	std::vector<std::shared_ptr<Entity>> Inventory;

	StatComponent oldStats;

	StatComponent Stats;

public:

	std::function<void(std::shared_ptr<Entity>)> Effect;

	std::function<void(std::shared_ptr<Entity>)> ReEffect;

	void AddItem(std::shared_ptr<Entity> newItem) {Inventory.push_back(newItem); newItem->Parent=shared_from_this();}

	void RemoveItem(std::shared_ptr<Entity> oldItem) {Inventory.erase(std::remove(Inventory.begin(), Inventory.end(), oldItem), Inventory.end()); oldItem->Parent=nullptr;}

	void Act(std::shared_ptr<Entity> Target) {
		Effect(Target);
		Target->ReAct(shared_from_this());
	}

	void ReAct(std::shared_ptr<Entity> Source) {ReEffect(Source);oldStats=Stats;}

	StatComponent& GetStats() {return Stats;}

	StatComponent& GetOldStats() {return oldStats;}
};