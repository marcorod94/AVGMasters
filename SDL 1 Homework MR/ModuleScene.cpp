#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "SDL/include/SDL.h"

ModuleScene::ModuleScene() {
}

ModuleScene::~ModuleScene() {
}

bool ModuleScene::Init() {
	return true;
}

update_status ModuleScene::Update() {
	
	if (texture == NULL) {
		texture = App->textures->Load("sprites.png");
		if (texture == NULL) {
			return UPDATE_ERROR;
		}
	}
	SDL_RenderCopy(App->renderer->renderer, texture, NULL, NULL);
	return UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp() {
	return false;
}
