#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled) {
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	hotTub.x = 0;
	hotTub.y = 0;
	hotTub.w = 0;
	hotTub.h = 0;

	mountain.frames.push_back({ 848, 208, 40, 40 });
	mountain.frames.push_back({ 848, 256, 40, 40 });
	mountain.frames.push_back({ 848, 304, 40, 40 });
	mountain.speed = 0.08f;

	samurai.frames.push_back({ 624, 15, 32, 56 });
	samurai.frames.push_back({ 624, 80, 32, 56 });
	samurai.frames.push_back({ 624, 144, 32, 56 });
	samurai.speed = 0.03f;
}

ModuleSceneHonda::~ModuleSceneHonda() {}

bool ModuleSceneHonda::Init() {
	LOG("Loading honda scene");

	graphics = App->textures->Load("honda_stage.png");
	App->player->Start();
	App->audio->PlayMusic("honda.ogg");

	return true;
}

bool ModuleSceneHonda::CleanUp() {
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

update_status ModuleSceneHonda::Update() {
	App->renderer->Blit(graphics, 0, 0, &background, 2.0f);
	App->renderer->Blit(graphics, 560, 8, &(mountain.GetCurrentFrame()), 2.0f);
	App->renderer->Blit(graphics, 560, 8, &(samurai.GetCurrentFrame()), 2.0f);
	
	App->renderer->Blit(graphics, 0, 0, &hotTub, 2.0f);
	App->renderer->Blit(graphics, 0, 170, &ground, 2.0f);

	App->player->Update();

	if (App->input->GetKey(SDL_SCANCODE_SPACE)) {
		App->fade->FadeToBlack(App->scene_ken, App->scene_honda);
	}
	return UPDATE_CONTINUE;
}
