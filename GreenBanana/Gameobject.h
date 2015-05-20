#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <sstream>
#include "Animator.h"
#include "BoxCollider.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
//#include "Scene.h"

class Scene;

class Gameobject
{
public:
	//Gameobject();
	//Gameobject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	//~Gameobject();
	
	// Methods
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	sf::Vector2f GetPosition() { return position; };
	void SetPosition(sf::Vector2f newPos) { position = newPos; };
	
	bool GetIsStatic() { return isStatic; };
	void SetIsStatic(bool value) { isStatic = value; };

	bool GetworldSpace() { return worldSpace; };
	void SetworldSpace(bool value) { worldSpace = value; };

	std::string GetName() { return name; };
	void SetName(std::string newName) { name = newName; };

	std::string GetType() { return type; }
	void SetType(std::string newType) { type = newType; }

	Animator GetAnimator() { return animations; }

	BoxCollider* GetCollider(){ return collider; }

	Scene* GetCurrentScene(){ return curScene; }
	void SetCurrentScene(Scene* sc){ curScene = sc; }

	std::string Serialize();
	//Animator SetAnimator(Animator newAnimator) { animations = newAnimator; };
protected:	
	// Variables
	Scene* curScene;
	std::string name;
	std::string type;
	sf::Vector2f position;
	Animator animations;
	BoxCollider* collider;
	bool isStatic;
	bool worldSpace;
};

#endif