#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.PushBack({ 848, 256, 40, 40 });
	flag.speed = 0.08f;

	// girl animation
	girl.PushBack({ 624, 16, 32, 56 });
	girl.PushBack({ 624, 80, 32, 56 });
	girl.PushBack({ 624, 144, 32, 56 });
	girl.PushBack({ 624, 80, 32, 56 });
	girl.speed = 0.08f;

	// graymans animation
	graymans.PushBack({ 552, 8, 64, 64 });
	graymans.PushBack({ 552, 72, 64, 64 });
	graymans.PushBack({ 552, 136, 64, 64 });
	graymans.PushBack({ 552, 72, 64, 64 });
	graymans.speed = 0.08f;

	// pman animation
	pman.PushBack({ 808, 24, 48, 32 });
	pman.PushBack({ 808, 72, 48, 32 });
	pman.PushBack({ 808, 120, 48, 32 });
	pman.PushBack({ 808, 72, 48, 32 });
	pman.speed = 0.08f;

	// bluehat animation
	bluehat.PushBack({ 704, 16, 48, 56 });
	bluehat.PushBack({ 704, 80, 48, 56 });
	bluehat.PushBack({ 704, 144, 48, 56 });
	bluehat.PushBack({ 704, 80, 48, 56 });
	bluehat.speed = 0.08f;

	// brownhat animation
	brownhat.PushBack({ 760, 16, 40, 40 });
	brownhat.PushBack({ 760, 64, 40, 40 });
	brownhat.PushBack({ 760, 112, 40, 40 });
	brownhat.PushBack({ 760, 64, 40, 40 });
	brownhat.speed = 0.08f;

	// coffeman animation
	coffeman.PushBack({ 664, 16, 32, 56 });
	coffeman.PushBack({ 664, 80, 32, 56 });
	coffeman.speed = 0.08f;

	// ship
	ship.x = 8;
	ship.y = 24;
	ship.w = 520;
	ship.h = 181;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{

	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect

	updown();

	App->render->Blit(graphics, 0, -5 + ud, &ship, 0.9f);//Ship


	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	App->render->Blit(graphics, 192, 99 + ud, &(girl.GetCurrentFrame()), 0.9f); // Girl animation
	App->render->Blit(graphics, 128, 91 + ud, &(graymans.GetCurrentFrame()), 0.9f); // graymans animation
	App->render->Blit(graphics, 224, 99 + ud, &(coffeman.GetCurrentFrame()), 0.9f); // coffeman animation
	App->render->Blit(graphics, 288, 91 + ud, &(bluehat.GetCurrentFrame()), 0.9f); // bluehat animation
	App->render->Blit(graphics, 88, 19 + ud, &(brownhat.GetCurrentFrame()), 0.9f); // brownhat animation
	App->render->Blit(graphics, 128, 19 + ud, &(pman.GetCurrentFrame()), 0.9f); // pman animation


	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}