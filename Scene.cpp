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

void Scene::setActive(bool pause)
{
	sceneActive = pause;
}

bool Scene::activated()
{
	return sceneActive;
}