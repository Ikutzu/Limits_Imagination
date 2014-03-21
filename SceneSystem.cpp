#include "SceneSystem.h"

vector<Scene> SceneSystem::SceneList;

void SceneSystem::openScene(Scene scene)
{
	SceneList.push_back(scene);

}

void SceneSystem::closeScene(Scene scene)
{

}

void SceneSystem::pauseScene()
{
	cout << "vittuuu" << endl;
}

void SceneSystem::changeScene(Scene scene)
{

}