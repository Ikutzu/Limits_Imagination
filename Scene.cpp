#include "Scene.h"


Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}

void Scene::update(float dt)
{
}

void Scene::draw(RenderWindow* window)
{
}

void Scene::activate()
{
	if(sceneActive)
		sceneActive = false;
	else
		sceneActive = true;
}