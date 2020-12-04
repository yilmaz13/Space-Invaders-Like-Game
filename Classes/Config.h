#pragma once
#include <string>

// define various constant value

// width, height constants
#define HEAVY_ENEMY_WIDTH		48.f
#define HEAVY_ENEMY_HEIGHT		48.f
#define LIGHT_ENEMY_WIDTH		48.f
#define LIGHT_ENEMY_HEIGHT		48.f

#define SPACE_SHIP_WIDTH		48.f
#define SPACE_SHIP_HEIGHT		48.f

#define PLAYER_SPACE_SHIP_HEALTH 25.f

#define BULLET_WIDTH	12.f
#define BULLET_HEIGHT	24.f

#define COLUMN	10
#define ROW		4


// image resource names
#define SPACE_SHIP_PATH "self.png"

#define LIGHT_ENEMY_PATH "enemy1.png"
#define HEAVY_ENEMY_PATH "enemy2.png"
#define HEAVY_ENEMY_HIT_PATH "enemy2_hit.png"
#define HEALTH_BAR_PATH "health_bar.png"

#define BULLET_PATH "rocket.png"


// rocket power & enemy HP(Health Point)
#define DEFAULT_BULLET_POWER 25.0f
#define POWERUP_BULLET_POWER 100.0f

#define LIGHT_ENEMY_HEALTH 50.0f
#define HEAVY_ENEMY_HEALTH 100.0f


// rocket direction
#define ENEMY_BULLET_DIRECTION -1
#define PLAYER_BULLET_DIRECTION 1

//

//rocket speed multiplier
#define ENEMY_BULLET_SPEED_MULTIPLIER 0.2
#define PLAYER_BULLET_SPEED_MULTIPLIER 1


// sprite kind
#define TAG_GENERAL		  0
#define TAG_ENEMY_SHIP	  1
#define TAG_BULLET_PLAYER 2
#define TAG_PLAYERSHIP	  3
#define TAG_BULLET_ENEMY  4

#define ENEMY_SHIP_HEAVY 0
#define ENEMY_SHIP_LIGHT 1


// Motion displacement
#define SHIP_DELTA_X			20.f
#define SHIP_DELTA_Y			1.f
#define BULLET_DELTA_Y			8.f

// Scene ids
#define SCENE_GAME_PLAY 0
#define SCENE_GAME_OVER 1
#define SCENE_GAME_START 2


// shoot speed
#define BULLET_RELOAD_RATE		.4f

// emeny Moveable Timer 
#define ENENY_MOVE_RATE		.4f

// paths
#define BACKGROUND_PATH "background.png"
#define ENEMY_PATH "enemy125.png"
#define ENEMY1_PATH "enemy1.png"
#define ENEMY2_PATH "enemy2.png"
#define ENEMY_MYSTERY_PATH "mystery.png"
#define BUTTON_START_NORMAL_PATH "btn_start_normal.png"
#define BUTTON_START_DOWN_PATH "btn_start_down.png"
#define BUTTON_RETRY_NORMAL_PATH "btn_retry_normal.png"
#define BUTTON_RETRY_DOWN_PATH "btn_retry_down.png"
#define BUTTON_EXIT_NORMAL_PATH "btn_exit_normal.png"
#define BUTTON_EXIT_DOWN_PATH "btn_exit_down.png"


#define HURT_NAME "hurt"
#define HEALTH_BAR "health_bar"


// collision case
#define HERO_ENEMY_COLLISION 0
#define ROCKET_ENEMY_COLLISION 1
#define ROCKET_PLAYER_COLLISION 2
#define ROCKET_ROCKET_COLLISION 3

// scores
#define HEAVY_ENEMY_SCORE 20
#define LIGHT_ENEMY_SCORE 10