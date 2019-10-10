#ifndef ModuleAudio_h
#define ModuleAudio_h
#include "Module.h"
#include "Globals.h"
class ModuleAudio : public Module
{
public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	update_status Update();
	bool CleanUp();
private:
	SDL_Texture* texture = NULL;
};
#endif