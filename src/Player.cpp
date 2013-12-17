#include "Player.h"

Player::Player(int x, int y)
{
    //Initialize movement variables
    health = 100;
    xOffset = x;
    yOffset = y;
    xVel = 0;
    yVel = 0;

    //Initialize animation variables
    frame = 0;
    direction = PLAYER_RIGHT;

    set_clips();

    //Load the sprite sheet
    player_sprite_up = load_image("Resources\\foo-red-1.png"); // move up
    player_sprite_right = load_image("Resources\\foo-red-2.png"); // move right
    player_sprite_down = load_image("Resources\\foo-red-3.png"); // move down
    player_sprite_left = load_image("Resources\\foo-red-4.png"); // move left
    if (player_sprite_up == NULL || player_sprite_right == NULL || player_sprite_down == NULL || player_sprite_left == NULL)
        cout << "Plyaer sprite didn't load" << endl;
}

Player::~Player()
{
    //Free the surface
    SDL_FreeSurface(player_sprite_up);
    SDL_FreeSurface(player_sprite_right);
    SDL_FreeSurface(player_sprite_down);
    SDL_FreeSurface(player_sprite_left);

}

SDL_Surface* Player::load_image(string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load(filename.c_str());
    if (loadedImage != NULL) {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
        if (optimizedImage != NULL)
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
    }
    return optimizedImage;
}

void Player::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip = NULL)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, mainScreenSurface, &offset);
}

void Player::update()
{
    if (xVel < 0) {
        if (xOffset >= 0 && xOffset <= 1280)
            xOffset += xVel;
        else
            xOffset = 0;
        direction = PLAYER_LEFT;
    }
    if (xVel > 0) {
        if (xOffset >= 0 && xOffset <= 1280)
            xOffset += xVel;
        else
            xOffset = 0;
        direction = PLAYER_RIGHT;
    }
    if (yVel < 0) {
        if (yOffset >= 0 && yOffset <= 768)
            yOffset += yVel;
        else
            yOffset = 0;
        direction = PLAYER_UP;
    }
    if (yVel > 0) {
        if (yOffset >= 0 && yOffset <= 768)
            yOffset += yVel;
        else
            yOffset = 0;
        direction = PLAYER_DOWN;
    }
}

void Player::draw()
{
    if (xVel == 0 && yVel == 0)
        frame = 1;
    else frame++;

    if (frame > 2)
        frame = 0;

    else switch (direction)
        {
            case PLAYER_UP:
                apply_surface(xOffset, yOffset, player_sprite_up, clipsUp);
                break;
            case PLAYER_RIGHT:
                apply_surface(xOffset, yOffset, player_sprite_right, clipsRight);
                break;
            case PLAYER_DOWN:
                apply_surface(xOffset, yOffset, player_sprite_down, clipsDown);
                break;
            case PLAYER_LEFT:
                apply_surface(xOffset, yOffset, player_sprite_left, clipsLeft);
                break;

        }
}

int Player::getX()
{
    return xOffset;
}

int Player::getY()
{
    return yOffset;
}

void Player::set_clips()
{
    //Clip the sprites Right move
    clipsRight[ 0 ].x = 0;
    clipsRight[ 0 ].y = 0;
    clipsRight[ 0 ].w = PLAYER_WIDTH;
    clipsRight[ 0 ].h = PLAYER_HEIGHT;

    clipsRight[ 1 ].x = PLAYER_WIDTH;
    clipsRight[ 1 ].y = 0;
    clipsRight[ 1 ].w = PLAYER_WIDTH;
    clipsRight[ 1 ].h = PLAYER_HEIGHT;

    clipsRight[ 2 ].x = PLAYER_WIDTH * 2;
    clipsRight[ 2 ].y = 0;
    clipsRight[ 2 ].w = PLAYER_WIDTH;
    clipsRight[ 2 ].h = PLAYER_HEIGHT;

    //Clip the sprites Left move

    clipsLeft[ 0 ].x = 0;
    clipsLeft[ 0 ].y = 0;
    clipsLeft[ 0 ].w = PLAYER_WIDTH;
    clipsLeft[ 0 ].h = PLAYER_HEIGHT;

    clipsLeft[ 1 ].x = PLAYER_WIDTH;
    clipsLeft[ 1 ].y = 0;
    clipsLeft[ 1 ].w = PLAYER_WIDTH;
    clipsLeft[ 1 ].h = PLAYER_HEIGHT;

    clipsLeft[ 2 ].x = PLAYER_WIDTH * 2;
    clipsLeft[ 2 ].y = 0;
    clipsLeft[ 2 ].w = PLAYER_WIDTH;
    clipsLeft[ 2 ].h = PLAYER_HEIGHT;

    //Clip the sprites Down move

    clipsDown[ 0 ].x = 0;
    clipsDown[ 0 ].y = 0;
    clipsDown[ 0 ].w = PLAYER_WIDTH;
    clipsDown[ 0 ].h = PLAYER_HEIGHT;

    clipsDown[ 1 ].x = PLAYER_WIDTH;
    clipsDown[ 1 ].y = 0;
    clipsDown[ 1 ].w = PLAYER_WIDTH;
    clipsDown[ 1 ].h = PLAYER_HEIGHT;

    clipsDown[ 2 ].x = PLAYER_WIDTH * 2;
    clipsDown[ 2 ].y = 0;
    clipsDown[ 2 ].w = PLAYER_WIDTH;
    clipsDown[ 2 ].h = PLAYER_HEIGHT;
    //Clip the sprites Up move

    clipsUp[ 0 ].x = 0;
    clipsUp[ 0 ].y = 0;
    clipsUp[ 0 ].w = PLAYER_WIDTH;
    clipsUp[ 0 ].h = PLAYER_HEIGHT;

    clipsUp[ 1 ].x = PLAYER_WIDTH;
    clipsUp[ 1 ].y = 0;
    clipsUp[ 1 ].w = PLAYER_WIDTH;
    clipsUp[ 1 ].h = PLAYER_HEIGHT;

    clipsUp[ 2 ].x = PLAYER_WIDTH * 2;
    clipsUp[ 2 ].y = 0;
    clipsUp[ 2 ].w = PLAYER_WIDTH;
    clipsUp[ 2 ].h = PLAYER_HEIGHT;
}