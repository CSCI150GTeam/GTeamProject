#include "Editor.h"

Editor::Editor()
{
    grid = new Grid("resources\\data_c1.txt");
    fileOpen = true;
    updateGrid = false;
    needsDraw = true;
    selectedTile = 4;

    oneSpawn.x = 0;
    oneSpawn.y = 0;
    twoSpawn.x = 0;
    twoSpawn.y = 0;
    endzone.x = 0;
    endzone.y = 0;
    endzone.w = 0;
    endzone.h = 0;

    editorBackground = Utility::loadImage("resources\\ui_editorBackground.png");
    horizontalLine = Utility::loadImage("resources\\ui_horizontalLine.png");
    verticalLine = Utility::loadImage("resources\\ui_verticalLine.png");

    IMG_BRICK = Utility::loadImage("resources\\tile_brick32.jpg");
    IMG_DIRT = Utility::loadImage("resources\\tile_dirt32.jpg");
    IMG_DIRTYBRICK = Utility::loadImage("resources\\tile_dirtybrick32.jpg");
    IMG_GRASS = Utility::loadImage("resources\\tile_grass32.jpg");
    IMG_LAVA = Utility::loadImage("resources\\tile_lava32.jpg");
    IMG_REDCARPET = Utility::loadImage("resources\\tile_redcarpet32.jpg");
    IMG_STONE = Utility::loadImage("resources\\tile_stone32.jpg");
    IMG_WATER = Utility::loadImage("resources\\tile_water32.jpg");
    IMG_WOOD = Utility::loadImage("resources\\tile_wood32.jpg");

    IMG_BRICK64 = Utility::loadImage("resources\\tile_brick64.jpg");
    IMG_DIRT64 = Utility::loadImage("resources\\tile_dirt64.jpg");
    IMG_DIRTYBRICK64 = Utility::loadImage("resources\\tile_dirtybrick64.jpg");
    IMG_GRASS64 = Utility::loadImage("resources\\tile_grass64.jpg");
    IMG_LAVA64 = Utility::loadImage("resources\\tile_lava64.jpg");
    IMG_REDCARPET64 = Utility::loadImage("resources\\tile_redcarpet64.jpg");
    IMG_STONE64 = Utility::loadImage("resources\\tile_stone64.jpg");
    IMG_WATER64 = Utility::loadImage("resources\\tile_water64.jpg");
    IMG_WOOD64 = Utility::loadImage("resources\\tile_wood64.jpg");

    IMG_MENU1 = Utility::loadImage("resources\\ui_menu1.png");

    IMG_BUTTON_HIGHLIGHT = Utility::loadImage("resources\\ui_menuHighlight.jpg");
    IMG_SELECT_HIGHLIGHT = Utility::loadImage("resources\\ui_editorHighlight.png");
    IMG_INFOBAR = Utility::loadImage("resources\\ui_infoBar.png");
}

Editor::~Editor()
{
    SDL_FreeSurface(editorBackground);
    SDL_FreeSurface(horizontalLine);
    SDL_FreeSurface(verticalLine);

    SDL_FreeSurface(IMG_BRICK);
    SDL_FreeSurface(IMG_DIRT);
    SDL_FreeSurface(IMG_DIRTYBRICK);
    SDL_FreeSurface(IMG_GRASS);
    SDL_FreeSurface(IMG_LAVA);
    SDL_FreeSurface(IMG_REDCARPET);
    SDL_FreeSurface(IMG_STONE);
    SDL_FreeSurface(IMG_WATER);
    SDL_FreeSurface(IMG_WOOD);

    SDL_FreeSurface(IMG_MENU1);

    SDL_FreeSurface(IMG_BUTTON_HIGHLIGHT);
    SDL_FreeSurface(IMG_INFOBAR);
}

int Editor::runEditor()
{
    bool quit = false;
    while ( !quit )
    {
	switch ( input() )
	{
	    case -1:
		return GS_MENU;
	    case 0:
		break;
	}

	switch ( update() )
	{
	    case 0:
		break;
	}

	switch ( draw() )
	{
	    case 0:
		break;
	}
    }
}

int Editor::input()
{
    SDL_Event event;
    if ( SDL_PollEvent(&event) )
    {
	switch ( event.type )
	{
	    case SDL_MOUSEBUTTONDOWN:
		if ( event.button.button == SDL_BUTTON_LEFT )
		{
		    if ( event.button.y <= 640 )
		    {
			cout << "Input- button down in grid" << endl;
			mouseDown.x = event.button.x;
			mouseDown.y = event.button.y;
		    }
		    else
		    {
			//bottom bar code
		    }
		}
		break;
	    case SDL_MOUSEBUTTONUP:
		if ( event.button.button == SDL_BUTTON_LEFT )
		{
		    if ( event.button.y <= 640 )
		    {
			cout << "Input- button up in grid" << endl;
			mouseUp.x = event.button.x;
			mouseUp.y = event.button.y;
			updateGrid = true;
			needsDraw = true;
			break;
		    }
		    else
		    {
			needsDraw = true;
		    }
		}
		break;
	    case SDL_KEYUP:
		if ( event.key.keysym.sym == SDLK_ESCAPE )
		{
		    save();
		    return -1;
		}
	    default:
		break;
	}
    }
    return 0;
}

int Editor::update()
{
    if ( updateGrid )
    {
	cout << "Updating grid" << endl;
	int x, y, w, h;
	w = ( mouseUp.x / 32 ) - ( mouseDown.x / 32 );
	x = mouseDown.x;
	if ( mouseUp.x < mouseDown.x )
	{
	    w *= -1;
	    x = mouseUp.x;
	}

	h = ( mouseUp.y / 32 ) - ( mouseDown.y / 32 );
	y = mouseDown.y;
	if ( mouseUp.y < mouseDown.y )
	{
	    h *= -1;
	    y = mouseUp.y;
	}
	
	cout<<"Updating area from x = "<<x<<" to x = "<<x+w<<" and from y = "<<y<<" to y = "<<y+h<<endl;

	for ( int i = x; i < x+w; i++ )
	    for ( int j = y; j < y+h; j++ )
		grid->setTileAt(i, j, selectedTile);
	updateGrid = false;
    }
    return 0;
}

int Editor::draw()
{
    if ( needsDraw )
    {
	cout << "Editor::draw()" << endl;
	if ( fileOpen )
	    grid->drawGrid();
	else
	{
	    Utility::applySurface(0, 0, editorBackground);
	    for ( int i = 0; i <= GRID_WIDTH; i++ )
		Utility::applySurface(i * 32, 0, verticalLine);
	    Utility::applySurface(1279, 0, verticalLine);
	    for ( int j = 0; j <= GRID_HEIGHT; j++ )
		Utility::applySurface(0, j * 32, horizontalLine);
	}

	//Draw bar
	Utility::applySurface(0, 640, IMG_INFOBAR);
	Utility::applySurface(0, 640, horizontalLine);
	Utility::applySurface(0, 767, horizontalLine);

	//Draw tile selection
	Utility::applySurface(12 + ( 48 * ( selectedTile - 1 ) ), 700, IMG_SELECT_HIGHLIGHT);
	Utility::applySurface(16, 704, IMG_BRICK);
	Utility::applySurface(64, 704, IMG_DIRT);
	Utility::applySurface(112, 704, IMG_DIRTYBRICK);
	Utility::applySurface(160, 704, IMG_GRASS);
	Utility::applySurface(208, 704, IMG_LAVA);
	Utility::applySurface(256, 704, IMG_REDCARPET);
	Utility::applySurface(304, 704, IMG_STONE);
	Utility::applySurface(352, 704, IMG_WATER);
	Utility::applySurface(400, 704, IMG_WOOD);
	SDL_Rect offset;
	offset.x = 0;
	offset.y = 640;
	offset.w = 432;
	offset.h = 64;
	text->displayTextCentered(offset, "Tile Selection", 36);

	//Draw selection display
	switch ( selectedTile )
	{
	    case 1:
		Utility::applySurface(496, 700, IMG_BRICK64);
		text->displayText(496, 644, "Brick", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    case 2:
		Utility::applySurface(496, 700, IMG_DIRT64);
		text->displayText(496, 644, "Dirt", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    case 3:
		Utility::applySurface(496, 700, IMG_DIRTYBRICK64);
		text->displayText(496, 644, "Dirty Brick", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    case 4:
		Utility::applySurface(496, 700, IMG_GRASS64);
		text->displayText(496, 644, "Grass", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    case 5:
		Utility::applySurface(496, 700, IMG_LAVA64);
		text->displayText(496, 644, "Lava", 24);
		text->displayText(496, 672, "Unpassable", 24);
		break;
	    case 6:
		Utility::applySurface(496, 700, IMG_REDCARPET64);
		text->displayText(496, 644, "Red Carpet", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    case 7:
		Utility::applySurface(496, 700, IMG_STONE64);
		text->displayText(496, 644, "Stone", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    case 8:
		Utility::applySurface(496, 700, IMG_WATER64);
		text->displayText(496, 644, "Water", 24);
		text->displayText(496, 672, "Unpassable", 24);
		break;
	    case 9:
		Utility::applySurface(496, 700, IMG_WOOD64);
		text->displayText(496, 644, "Wood", 24);
		text->displayText(496, 672, "Background", 24);
		break;
	    default:
		break;
	}

	//Spawns/Endzones

	//Buttons
	SDL_Rect size;
	size.x = 390;
	size.y = 134;
	size.w = 256;
	size.h = 42;

	offset.x = 1024;
	offset.y = 641;
	offset.w = 256;
	offset.h = 42;
	SDL_BlitSurface(IMG_MENU1, &size, mainScreenSurface, &offset);
	text->displayTextCentered(offset, "New", 36);
	offset.y = 683;
	SDL_BlitSurface(IMG_MENU1, &size, mainScreenSurface, &offset);
	text->displayTextCentered(offset, "Load", 36);
	offset.y = 725;
	SDL_BlitSurface(IMG_MENU1, &size, mainScreenSurface, &offset);
	text->displayTextCentered(offset, "Exit", 36);

	needsDraw = false;
	SDL_Flip(mainScreenSurface);
    }
    return 0;
}

void Editor::save()
{
    grid->editorSave("resources\\data_c1.txt", oneSpawn, twoSpawn, endzone);
}