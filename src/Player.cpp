#include "Player.h"

Player::Player(int x, int y)
{
    //Initialize movement variables
    health = 100;
    xOffset = x;
    yOffset = y;
    xVel = 0;
    yVel = 0;
    speed = 8;

    //Initialize animation variables
    frame = 0;
    direction = PLAYER_RIGHT;

    set_clips();

    //Load the sprite sheet
    player_sprite_up = Utility::loadImage("resources\\sprite_RedUp.png"); // move up
    player_sprite_right = Utility::loadImage("resources\\sprite_RedRight.png"); // move right
    player_sprite_down = Utility::loadImage("resources\\sprite_RedDown.png"); // move down
    player_sprite_left = Utility::loadImage("resources\\sprite_RedLeft.png"); // move left
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

void Player::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, mainScreenSurface, &offset);
}

void Player::input(SDL_Event event)
{
    switch (event.type)
    {
        case (SDL_KEYDOWN):
            switch (event.key.keysym.sym)
            {
                case SDLK_w:
                    yVel -= speed;
                    break;
                case SDLK_s:
                    yVel += speed;
                    break;
                case SDLK_a:
                    xVel -= speed;
                    break;
                case SDLK_d:
                    xVel += speed;
                    break;
                    //shoot
                case SDLK_j:
                    break;
            }
            break;
        case (SDL_KEYUP):
            switch (event.key.keysym.sym)
            {
                case SDLK_w:
                    yVel += speed;
                    break;
                case SDLK_s:
                    yVel -= speed;
                    break;
                case SDLK_a:
                    xVel += speed;
                    break;
                case SDLK_d:
                    xVel -= speed;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
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
        if (yOffset >= 0 && yOffset <= 640)
            yOffset += yVel;
        else
            yOffset = 0;
        direction = PLAYER_UP;
    }
    if (yVel > 0) {
        if (yOffset >= 0 && yOffset <= 640)
            yOffset += yVel;
        else
            yOffset = 0;
        direction = PLAYER_DOWN;
    }
}

void Player::draw(int frame)
{
    if (xVel == 0 && yVel == 0)
        frame = 0;
    else if (frame == 15 || frame == 30)
        frame++;
    
    if (frame > 3)
        frame = 0;

    switch (direction)
    {
        case PLAYER_UP:
            apply_surface(xOffset, yOffset, player_sprite_up, &spriteClips[frame]);
            break;
        case PLAYER_RIGHT:
            apply_surface(xOffset, yOffset, player_sprite_right, &spriteClips[frame]);
            break;
        case PLAYER_DOWN:
            apply_surface(xOffset, yOffset, player_sprite_down, &spriteClips[frame]);
            break;
        case PLAYER_LEFT:
            apply_surface(xOffset, yOffset, player_sprite_left, &spriteClips[frame]);
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
    spriteClips[ 0 ].x = PLAYER_WIDTH;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = PLAYER_WIDTH;
    spriteClips[ 0 ].h = PLAYER_HEIGHT;

    spriteClips[ 1 ].x = 0;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = PLAYER_WIDTH;
    spriteClips[ 1 ].h = PLAYER_HEIGHT;

    spriteClips[ 2 ].x = PLAYER_WIDTH;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = PLAYER_WIDTH;
    spriteClips[ 2 ].h = PLAYER_HEIGHT;

    spriteClips[ 3 ].x = PLAYER_WIDTH * 2;
    spriteClips[ 3 ].y = 0;
    spriteClips[ 3 ].w = PLAYER_WIDTH;
    spriteClips[ 3 ].h = PLAYER_HEIGHT;
}