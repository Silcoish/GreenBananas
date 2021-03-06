#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <sstream>
#include "Animator.h"
#include "BoxCollider.h"
#include "SpritesheetLoader.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
//#include "Scene.h"

class Scene;

class Gameobject
{
public:
	//Gameobject();
	//Gameobject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	virtual ~Gameobject();
	
	// Methods
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow* rw);
	virtual void ResetObject();

	sf::Vector2f GetPosition() { return position; };
	void SetPosition(sf::Vector2f newPos) { position = newPos; };

	sf::Vector2f GetStartPosition() { return startPosition; };
	void SetStartPosition(sf::Vector2f newPos) { startPosition = newPos; };
	
	bool GetIsStatic() { return isStatic; };
	void SetIsStatic(bool value) { isStatic = value; };

	bool GetworldSpace() { return worldSpace; };
	void SetworldSpace(bool value) { worldSpace = value; };

	std::string GetName() { return name; };
	void SetName(std::string newName) { name = newName; };

	std::string GetType() { return type; }
	void SetType(std::string newType) { type = newType; }

	int GetDepth() { return depth; };
	void SetDepth(int newDepth) { depth = newDepth; };

	Animator& GetAnimator() { return animations; }

	BoxCollider* GetCollider(){ return collider; }

	Scene* GetCurrentScene(){ return curScene; }
	void SetCurrentScene(Scene* sc){ curScene = sc; }



	void ScaleSprites(std::map<std::string, Animation>& anims, float scale);
	void ScaleSprites(std::map<std::string, Animation>& anims, sf::Vector2f newSize);

	std::string Serialize();
	sf::Vector2f GetSize();
	//Animator SetAnimator(Animator newAnimator) { animations = newAnimator; };
protected:	
	// Variables
	Scene* curScene;
	std::string name;
	std::string type;
	sf::Vector2f position;
	sf::Vector2f startPosition;
	Animator animations;
	BoxCollider* collider;
	bool isStatic;
	bool worldSpace;
	int depth;
};

#endif