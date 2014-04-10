#pragma once

#include "Scene.h"

#include <vector>
#include <iostream>
using namespace std;

class SceneSystem
{
public:
	static Scene getScene(int SceneNum);
	static void openScene(Scene *newScene);
	static void closeScene();
	static void pauseScene();
	static void changeScene(Scene *scene);
	static void MainMenu();

	static void update(float dt);
	static void draw(RenderWindow* window);

private:

	static vector<Scene*> SceneList;
	static vector <Scene*>::iterator it;
	static bool sceneChanged;
};

