#include "StatComponent.h"
#include <algorithm>

class Player : public Entity {

	void Attack(std::shared_ptr<Entity> Target) {
		//FF7 Damage Formula, use different formulas for different weapons/characters/etc. 
		Target->GetStats().HP-=(GetStats().Attack / 16.0f) * (GetStats().Attack + ((GetStats().Level + GetStats().Attack) / 32.0f) * ((GetStats().Level * GetStats().Attack) / 32.0f));
	}

	void Hit(std::shared_ptr<Entity> Source) {
		float dDamage=GetOldStats().HP-GetStats().HP;
		if (dDamage>0.0f) GetStats().HP=std::clamp(GetOldStats().HP-dDamage*(100.0f/(100.0f+GetStats().Defense)), 0.0f, GetStats().maxHP);
	}

public:
	Player() {
		GetStats().name = "player";
		GetStats().maxHP=100.0f; GetStats().HP=GetStats().maxHP;
		GetStats().maxMP=100.0f; GetStats().MP=GetStats().maxMP;
		GetStats().Attack=5.0f;
		GetStats().Defense=2.0f;
		GetStats().Level=1.0f;
		GetOldStats()=GetStats();

		Effect = std::bind( &Player::Attack, this, std::placeholders::_1 );
		ReEffect = std::bind( &Player::Hit, this, std::placeholders::_1 );

	}
};