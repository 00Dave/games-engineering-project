#include "HudManager.h"
#include "Game.h"
#include "MessageHandler.h"
#include <iostream>
#include "Player.h"
#include "EntityManager.h"
#include <list>
#include "Collectable.h"
#include <sstream>
#include <string>

using namespace irr::gui;
using namespace irr::core;
using namespace irr::video;


HudManager::HudManager() : Entity(-1, 0, "Hudman"){
	_hintTimer = 0;
	///*setup Hints*/

	_hints["Movement"] = "Use W, A, S & D to move around";
	_hints["Camera"] = "Look around with the mouse";
	_hints["Throw"] = "Press 'E' again to drop, or left click the mouse to throw";
	_hints["Object"] = "Press 'E' to pick up certain objects";
	_hints["Door"] = "Press 'F' to move through doors";


	//init hints shown check map
	std::unordered_map<std::string, std::string>::iterator si = _hints.begin();
	for (; si != _hints.end();si++){
		_hintsShown[si->first] == false;
	}

	//set guiEnvironment
	_env = game.getDevice()->getGUIEnvironment();

	//initilise texture map
	std::list<Entity*>* allColls = EntityManager::getNamedEntities("Collectable");
	auto iter = allColls->begin();
	while (iter != allColls->end()){
		Collectable* collTemp = (Collectable*)(*iter);
		std::wstringstream pathToTexture;
		pathToTexture << "textures/hud/" << collTemp->getItemName().c_str() << ".png";
		ITexture* tempTexture = game.getDevice()->getVideoDriver()->getTexture(pathToTexture.str().c_str());
		_collTextures[collTemp->getItemName()] = tempTexture;
		iter++;
	}	
}



void HudManager::initialise(){

}

void HudManager::loadContent(){

}

void HudManager::update(float deltaTime){
	if (_hintTimer > 5) _hintTimer = 0;
	//clear everything
	_env->clear();

	Player* player = (Player*)EntityManager::getNamedEntities("Player")->front();
	
	//ofset for images
	int offset = 60;
	int count = 0.0f;

	//dimension
	dimension2d<u32> dims = game.getDimensions();



	//Draw collectables. use of alpha channel depends on if the object has been picked up or not
	std::unordered_map<std::string, bool> collectableList = player->getCollectedItems();
	std::unordered_map<std::string, bool>::iterator i = collectableList.begin();
	for (; i != collectableList.end(); i++){
		IGUIImage* img = _env->addImage(_collTextures[i->first], core::position2d<s32>(dims.Width - 100 - (offset*count), 20), false);
		img->setUseAlphaChannel(!i->second); 
		count++;
	}
	
	//draw noise meter





	//control hints
	if (_hintTimer == 0 && !hasHintBeenShownFor("Movement")){
		drawHintFor("Movement");
	}
	if (!hasHintBeenShownFor("Camera") && _hintTimer == 0 && player->getNode()->getPosition().X != 0.0f){
		drawHintFor("Camera");
	}

	if (_hintTimer >= 1 && _hintTimer < 5){
		std::wstringstream sstream;
		sstream << _hintText.c_str();
		IGUIStaticText* text = _env->addStaticText(sstream.str().c_str(), irr::core::rect<irr::s32>(dims.Width / 2 - 200, dims.Height / 2 - 200, dims.Width / 2 + 200, dims.Height / 2 + 200), false);
		irr::gui::IGUIFont* font = _env->getFont("bigfont.png");
		text->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
		text->setOverrideFont(font);
	}
	if (_hintTimer >= 1)
		_hintTimer += deltaTime;
	
	
	
	
	
	
	
	
	
	
	
	/*DEBUG STUFF*/
	/*IGUIStaticText* text = _env->addStaticText(L"", irr::core::rect<irr::s32>(250, 10, 500, 200), false);
	irr::gui::IGUIFont* font = _env->getFont("bigfont.png");
	text->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
	text->setOverrideFont(font);
	vector3df pos = player->getNode()->getPosition();
	std::wstringstream sstream;*/
	/*sstream << "x:" << pos.X << " y: " << pos.Y << " z: " << pos.Z << "\nNM: " << player->getNoiseMade() << "\n";
	std::unordered_map<std::string, bool> colLs = player->getCollectedItems();
	std::unordered_map<std::string, bool>::iterator z = colLs.begin();
	for (; z != colLs.end(); z++){
		sstream << z->first.c_str() << " = " <<z->second;
	}*/

}

void HudManager::render(){


}

void HudManager::unloadContent(){
	
}

void HudManager::shutdown(){
		
}

void HudManager::drawHintFor(std::string hintFor){
	std::string tempHint;
	auto found = _hints.find(hintFor);
	if (found != _hints.end()){
		_hintText = found->second;
		_hintTimer = 1;
		_hintsShown[found->first] = true;
	}
}

void HudManager::handleMessage(const Message& message){

}

//does the player need a hint?
//HudManager* hud = (HudManager*)EntityManager::getNamedEntities("Hudman")->front();
//if (!hud->hasHintBeenShownFor("Object")){
//	vector3df playerPos = ((Entity*)player)->getNode()->getPosition();
//	vector3df objectPos = _node->getPosition();
//	vector3df d = playerPos - objectPos;
//	auto dist = d.getLength();
//	if (d.getLength()<5){
//		hud->drawHintFor("Object");
//	}
//}