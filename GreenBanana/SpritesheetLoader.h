#include <vector>
#include <SFML/Graphics/Rect.hpp>

#include "Sprite.h"
class SpritesheetLoader
{
	public:
		std::vector<Sprite*> Load(std::string filePath, int spriteWidth, int spriteHeight);
};