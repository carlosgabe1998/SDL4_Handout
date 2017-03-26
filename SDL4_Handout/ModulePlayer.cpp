#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({7, 14, 60, 90});
	idle.PushBack({95, 15, 60, 89});
	idle.PushBack({184, 14, 60, 90});
	idle.PushBack({276, 11, 60, 93});
	idle.PushBack({366, 12, 60, 92});
	idle.speed = 0.2f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	forward.PushBack({78, 131, 60, 88});
	forward.PushBack({162, 128, 64, 92});
	forward.PushBack({259, 128, 63, 90});
	forward.PushBack({352, 128, 54, 91});
	forward.PushBack({432, 131, 50, 89});
	forward.speed = 0.1f;

	// TODO 4: Make ryu walk backwards with the correct animations
	backward.PushBack({ 542, 127, 61, 92 });
	backward.PushBack({ 628, 128, 61, 92 });
	backward.PushBack({ 713, 126, 61, 92 });
	backward.PushBack({ 797, 125, 61, 92 });
	backward.PushBack({ 883, 127, 61, 92 });
	backward.PushBack({ 974, 126, 61, 92 });
	backward.speed = 0.1f;


	//punch animation
	punch.PushBack({ 20, 272, 63, 91 });
	punch.PushBack({ 108, 272, 92, 91 });
	punch.speed = 0.1f;

	//kick animation
	kick.PushBack({ 607, 265, 59, 98 });
	kick.PushBack({ 689, 267, 66, 92 });
	kick.PushBack({ 777, 265, 114, 94 });
	kick.PushBack({ 689, 267, 66, 92 });
	kick.speed = 0.1f;


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ryu.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_LSHIFT] == 1)
	{

		current_animation = &punch;

	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{

		current_animation = &kick;

	}

	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}