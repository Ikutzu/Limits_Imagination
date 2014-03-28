#include "SceneSystem.h"

vector<Scene*> SceneSystem::SceneList;
vector<Scene*>::iterator SceneSystem::it;
bool SceneSystem::sceneChanged = false;

void SceneSystem::openScene(Scene* newScene)
{
	SceneList.push_back(newScene);
	newScene->pause(true);
	sceneChanged = true;
}

void SceneSystem::closeScene(Scene newScene)
{
	it = SceneList.end() -1;
	(*it)->~Scene();
	SceneList.shrink_to_fit();
	sceneChanged = true;
}

void SceneSystem::pauseScene()
{
	it = SceneList.end() -1;
	(*it)->pause(false);
}

void SceneSystem::changeScene(Scene* newScene)
{
	SceneList.clear();
	openScene(newScene);
}

void SceneSystem::update(float dt)
{
	for(it = SceneList.begin(); it != SceneList.end(); it++)
	{
		if((*it)->activated())
		{
			(*it)->update(dt);
		
			if(sceneChanged)
			{
				sceneChanged = false;
				break;
			}
		}
	}
}

void SceneSystem::draw(RenderWindow* window)
{
	for(it = SceneList.begin(); it != SceneList.end(); it++)
	{
		(*it)->draw(window);
	}
}