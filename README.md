![Imgur](https://imgur.com/oXGegKe.png)

# Tasty-Stats

**Tasty Stats** is a low-level header only hybrid functional object oriented RPG entity and stats system which was developed to be simple and intuitive while not assuming any design choices. 

## Usage
1. Simply #include "StatComponent.h"

2. Create an Entity (example player entity included in EntityLib.h)

If using EntityLib.h you can create a new player entity, enemy entity, and have one attack the other in three lines of code.

	std::shared_ptr<Player> newPlayer = std::make_shared<Player>();
	std::shared_ptr<Player> newEnemy = std::make_shared<Player>();

	newPlayer->Act(newEnemy);

## Notes

  Entity class is fully self contained and should not need to be modified for any reason.



## Future plans
Detailed documentation of the design idiom.

Serialization through cereal is on the roadmap

UE5 integration
