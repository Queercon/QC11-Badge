/*
 * anim.c
 *
 *  Created on: Jul 21, 2014
 *      Author: glouthan
 */
#include "qcxi.h"
#if BADGE_TARGET
#include "anim.h"

// Bus:

#pragma DATA_SECTION (anim_full_prop_wand_use, ".infoC");
#pragma DATA_SECTION (anim_sprite_prop_dynamite_use, ".infoD");

// prop use:
const fullframe anim_full_prop_ball_use[] = {{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10100000000000, 0b01111000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10100000000000, 0b01110000000000, 0b00101000000000, 0},{0b01010000000000, 0b01010000000000, 0b10100000000000, 0b01110000000000, 0b00110000000000, 0},{0b01010000000000, 0b01010000000000, 0b10100000000000, 0b01110000000000, 0b00101000000000, 0},{0b01010000000000, 0b01010000000000, 0b10100000000000, 0b01111000000000, 0b00100100000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100010000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100001000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000100000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000010000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000001000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000000100, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000010, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000001, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000000000, 128},};
const fullframe anim_full_prop_wand_use[] = {{0b01010000000000, 0b01010000000000, 0b10110000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10110000000000, 0b01111000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01111000000000, 0b00101000000000, 0},{0b01010000000000, 0b01010000000000, 0b10110000000000, 0b01111000000000, 0b00100100000000, 0},{0b01010000000000, 0b01010000000000, 0b10110000000000, 0b01111000000000, 0b00100101000000, 0},{0b01010000000000, 0b01010000000000, 0b10110000100000, 0b01111001000000, 0b00100100010000, 0},{0b01010000000000, 0b01010000000000, 0b10110000100010, 0b01111000001000, 0b00100100001000, 0},{0b01010000000000, 0b01010000000000, 0b10110000000100, 0b01111000010001, 0b00100000001010, 0},{0b01010000000000, 0b01010000000000, 0b10110000000000, 0b01110000000100, 0b00100000000001, 128},};
const spriteframe anim_sprite_prop_earthquake_use[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01000000, 0b01010000, 0b10111000, 0b01110000, 0b00100000, 1},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01111000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010100, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b11010010, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010001, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
const spriteframe anim_sprite_prop_stick_use[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10110000, 0b01110000, 0b00100000, 1},{0b01011000, 0b01011000, 0b10101000, 0b01111000, 0b00101000, 0},{0b01010000, 0b01011000, 0b10101000, 0b01111000, 0b00101000, 1},{0b01011000, 0b01011000, 0b10101000, 0b01111000, 0b00101000, 2},{0b01010000, 0b01010000, 0b10110000, 0b01110000, 0b00110000, 0},{0b01010000, 0b01010000, 0b10110000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
const spriteframe anim_sprite_prop_dynamite_use[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010111, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010010, 0b01010111, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010010, 0b01010010, 0b10101111, 0b01110000, 0b00100000, 0},{0b01010111, 0b01010010, 0b10101010, 0b01110111, 0b00100000, 0},{0b01010111, 0b01010111, 0b10101010, 0b01110010, 0b00100111, 0},{0b01010111, 0b01010111, 0b10100010, 0b01111010, 0b00100111, 0},{0b01010111, 0b01010111, 0b10100010, 0b01110010, 0b00101111, 1},{0b01010111, 0b01010111, 0b10100010, 0b01111111, 0b00100000, 1},{0b01010111, 0b01010111, 0b10101111, 0b01110000, 0b00100000, 4},{0b01010111, 0b01010111, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010111, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
const spriteframe anim_sprite_prop_sword_use[] = {{0b01010000, 0b01010000, 0b10110000, 0b01110000, 0b00100000, 0},{0b01011000, 0b01011000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101110, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110100, 0b00100010, 1},{0b01010000, 0b01010000, 0b10100000, 0b01111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00110000, 1},{0b01010000, 0b01010000, 0b10100000, 0b01111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110100, 0b00100010, 1},{0b01010000, 0b01010000, 0b10101110, 0b01110000, 0b00100000, 0},{0b01011000, 0b01011000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10110000, 0b01110000, 0b00100000, 128},};

// prop effects:
const fullframe anim_full_prop_ball_effect[] = {{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000001, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000010, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000100, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000001000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000010000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000100000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101001000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101010000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101100000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10111000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b01110000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b00100000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01110000000000, 0b01110000000000, 0b00100000000000, 0b00000000000000, 4},{0b01010000000000, 0b01010000000000, 0b01110000000000, 0b01110000000000, 0b00100000000000, 0},{0b01010000000000, 0b01010000000000, 0b10101000000000, 0b01110000000000, 0b00100000000000, 128},};
const fullframe anim_full_prop_rain_effect[] = {{0b00000000000000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0},{0b00000000000000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0b01000000000000, 0},{0b00000000000000, 0b00000000000000, 0b00000000000000, 0b01000000000000, 0b01000001000000, 0},{0b00000000000000, 0b00000000000000, 0b01000000000000, 0b01000001000000, 0b00000001000010, 0},{0b00000000000000, 0b01000000000000, 0b01000001000000, 0b00000001000010, 0b00001000000010, 0},{0b01000000000000, 0b01000001000000, 0b00000001000010, 0b00001000000010, 0b00001000010000, 0},{0b01000001000000, 0b00000001000010, 0b00001000000010, 0b00001000010000, 0b00100000010100, 0},{0b00000001000010, 0b00001000000010, 0b00001000010000, 0b00100000010100, 0b00100010000100, 0},{0b00001000000010, 0b00001000010000, 0b00100000010100, 0b00100010000100, 0b10000010000001, 0},{0b00001000010000, 0b00100000010100, 0b00100010000100, 0b10000010000001, 0b10000000100001, 0},{0b00100000010100, 0b00100010000100, 0b10000010000001, 0b10000000100001, 0b00001000101000, 0},{0b00100010000100, 0b10000010000001, 0b10000000100001, 0b00001000101000, 0b00001000001000, 0},{0b10000010000001, 0b00000000100001, 0b00001000101000, 0b00001000001000, 0b01000000000000, 0},{0b00000000100001, 0b00001000101000, 0b00001000001000, 0b01000000000000, 0b01000000000010, 0},{0b00001000101000, 0b00001000001000, 0b01000000000000, 0b01000000000010, 0b00000010000010, 0},{0b00001000001000, 0b01000000000000, 0b01000000000010, 0b00000010000010, 0b00000010000000, 0},{0b01000000000000, 0b01000000000010, 0b00000010000010, 0b00000010000000, 0b00100000010000, 0},{0b01000000000010, 0b00000010000010, 0b00000010000000, 0b00100000010000, 0b00100000010000, 0},{0b00000010000010, 0b00000010000000, 0b00100000010000, 0b00100000010000, 0b00000000000000, 0},{0b00000010000000, 0b00100000010000, 0b00100000010000, 0b00000000000000, 0b00000000000000, 0},{0b00100000010000, 0b00100000010000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0},{0b00100000010000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0},{0b00000000000000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 0b00000000000000, 128},};
const spriteframe anim_sprite_prop_dynamite_effect[] = {{0b00001010, 0b00001010, 0b00010001, 0b00001110, 0b00000100, 0},{0b00001010, 0b00010001, 0b00010000, 0b00000110, 0b00010100, 0},{0b00101001, 0b00000000, 0b00000000, 0b00000000, 0b00000101, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 3},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000100, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000100, 0b00000000, 0},{0b00000000, 0b00000000, 0b00000100, 0b00000000, 0b00000000, 0},{0b00000000, 0b00000100, 0b00000000, 0b00000000, 0b00001000, 0},{0b00000100, 0b00000000, 0b00000000, 0b00001000, 0b00000010, 0},{0b00000100, 0b00000000, 0b00001000, 0b00000010, 0b00000100, 0},{0b00001100, 0b00000000, 0b00000010, 0b00000100, 0b00000000, 0},{0b00001100, 0b00000010, 0b00000100, 0b00000000, 0b00000000, 0},{0b00001110, 0b00000100, 0b00000000, 0b00000000, 0b00001000, 0},{0b00001110, 0b00000100, 0b00000000, 0b00001000, 0b00000000, 0},{0b00001110, 0b00000100, 0b00001000, 0b00000000, 0b00000000, 0},{0b00001110, 0b00001100, 0b00000000, 0b00000000, 0b00000000, 2},{0b00001010, 0b00001100, 0b00000100, 0b00000000, 0b00000000, 0},{0b00001010, 0b00001110, 0b00000100, 0b00000100, 0b00000000, 0},{0b00001010, 0b00001010, 0b00000100, 0b00000100, 0b00000100, 0},{0b00001010, 0b00001010, 0b00001110, 0b00001110, 0b00000100, 128},};
const spriteframe anim_sprite_prop_earthquake_effect[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b00101000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b00010100, 0b00010100, 0b00101010, 0b00011100, 0b00001000, 0},{0b00101000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b00101000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b00101000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b00010100, 0b00010100, 0b00101010, 0b00011100, 0b00001000, 0},{0b00101000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b00010100, 0b00010100, 0b00101010, 0b00011100, 0b00001000, 0},{0b00101000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
const spriteframe anim_sprite_prop_wand_effect[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b01100000, 0b01110000, 0b00110000, 1},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b00100000, 1},{0b01010000, 0b01010000, 0b00110000, 0b01110000, 0b01100000, 1},{0b01010000, 0b01010000, 0b00100000, 0b01111000, 0b01100000, 2},{0b01001000, 0b01010000, 0b00100000, 0b01111000, 0b01100000, 0},{0b01001000, 0b00101000, 0b00010000, 0b00111100, 0b00110000, 1},{0b01001000, 0b01010000, 0b00100000, 0b01111000, 0b01100000, 1},{0b01001000, 0b00101000, 0b00010000, 0b00111100, 0b00110000, 2},{0b00101000, 0b00101000, 0b00010000, 0b00111100, 0b00110000, 1},{0b00101000, 0b00101000, 0b00010000, 0b00111000, 0b00111000, 1},{0b00101000, 0b00101000, 0b00010000, 0b01111000, 0b00011000, 0},{0b01001000, 0b00101000, 0b00010000, 0b01111000, 0b00011000, 0},{0b01001000, 0b01010000, 0b00100000, 0b11110000, 0b00110000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11110000, 0b00110000, 2},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
const spriteframe anim_sprite_prop_sword_effect[] = {{0b01010000, 0b00100000, 0b11111000, 0b00100000, 0b00000000, 0},{0b00100000, 0b01110000, 0b10101000, 0b00000000, 0b00000000, 0},{0b01110000, 0b10101000, 0b00000000, 0b00000000, 0b00000000, 0},{0b10101000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 5},{0b10001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b10101000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b11111000, 0b00100000, 0b00000000, 0b00000000, 0b00000000, 0},{0b10101000, 0b01110000, 0b00100000, 0b00000000, 0b00000000, 0},{0b10111000, 0b01110000, 0b00100000, 0b00000000, 0b00000000, 0},{0b11111000, 0b01111000, 0b00100000, 0b00000000, 0b00000000, 0},{0b11011000, 0b11111000, 0b01110000, 0b00100000, 0b00000000, 0},{0b10001000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b10010000, 0b01010000, 0b01101000, 0b01110000, 0b00100000, 128},};

// sleep mode:
const spriteframe anim_sprite_sleep_laydown[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b00010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b00010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01110000, 0b11111000, 0b01110000, 0b00100000, 0b00000000, 0},{0b01110000, 0b11111000, 0b01110000, 0b00100000, 0b00000000, 0},{0b01110100, 0b01111000, 0b00110000, 0b00001000, 0b00000000, 0},{0b01110100, 0b01111000, 0b00110000, 0b00001000, 0b00000000, 0},{0b01111100, 0b01111000, 0b00110100, 0b00000000, 0b00000000, 0},{0b01111100, 0b01111000, 0b00110100, 0b00000000, 0b00000000, 0},{0b11111100, 0b01111100, 0b00110000, 0b00000000, 0b00000000, 0},{0b11111100, 0b01111100, 0b00110000, 0b00000000, 0b00000000, 0},{0b11111100, 0b01111100, 0b00110000, 0b00000000, 0b00000000, 8},};
const spriteframe anim_sprite_sleep_wakeup[] = {{0b11111000, 0b01111000, 0b00110000, 0b00000000, 0b00000000, 0},{0b11101000, 0b01111000, 0b00110000, 0b00100000, 0b00000000, 0},{0b01001000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 8},};

// Tricks:
spriteframe anim_sprite_trick_armdance[] = {{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b11111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00101000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10100000, 0b11111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b10100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b11111000, 0b00100000, 128},};
spriteframe anim_sprite_trick_ballet[] = {{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b10010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 0},{0b00010000, 0b01010000, 0b00110000, 0b00111100, 0b01010000, 1},{0b00010000, 0b00010000, 0b00110000, 0b00111000, 0b00010000, 0},{0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0},{0b00010000, 0b00010000, 0b00011000, 0b00111000, 0b00010000, 0},{0b00010000, 0b00010100, 0b00011000, 0b01111100, 0b00010000, 0},{0b00010000, 0b00010000, 0b00011000, 0b00111000, 0b00010000, 0},{0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0},{0b00010000, 0b00010000, 0b00110000, 0b00111000, 0b00010000, 0},{0b00010000, 0b01010000, 0b00110000, 0b01111100, 0b00010000, 1},{0b10010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 128},};
spriteframe anim_sprite_trick_companion[] = {{0b01010000, 0b01010000, 0b01100000, 0b01111000, 0b00100000, 0},{0b01000000, 0b01011000, 0b01100000, 0b01111000, 0b00100000, 0},{0b00000000, 0b01111000, 0b01100000, 0b01111000, 0b00000000, 0},{0b00000000, 0b01111000, 0b01101000, 0b00111000, 0b00000000, 0},{0b00000000, 0b00111000, 0b00101000, 0b00111000, 0b00000000, 1},{0b01111100, 0b01101100, 0b01101100, 0b01010100, 0b01111100, 1},{0b11101110, 0b11000110, 0b10000010, 0b10000010, 0b11010110, 1},{0b11000011, 0b10000001, 0b10000001, 0b10000001, 0b11000011, 0},{0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 2},{0b10000000, 0b00000000, 0b10000000, 0b00000000, 0b00000000, 0},{0b01000000, 0b10000000, 0b01000000, 0b10000000, 0b00000000, 0},{0b11000000, 0b11000000, 0b10000000, 0b10000000, 0b10000000, 0},{0b10010000, 0b10100000, 0b01000000, 0b01000000, 0b01000000, 0},{0b01010000, 0b01010000, 0b01110000, 0b00100000, 0b00100000, 128},};
spriteframe anim_sprite_trick_handwave[] = {{0b01010000, 0b01010000, 0b00101000, 0b11110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01111000, 0b10100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b01101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10110000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01111000, 0b10100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b01101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10110000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01111000, 0b10100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b01101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10110000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b01101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10110000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b01101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 128},};
spriteframe anim_sprite_trick_headroll[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00010000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01111000, 0b00000000, 0},{0b01010000, 0b01010000, 0b10101100, 0b01110000, 0b00000000, 0},{0b01010000, 0b01010100, 0b10101000, 0b01110000, 0b00000000, 0},{0b01010100, 0b01010000, 0b10101000, 0b01110000, 0b00000000, 0},{0b01010010, 0b01010000, 0b10101000, 0b01110000, 0b00000000, 0},{0b01010001, 0b01010000, 0b10101000, 0b01110000, 0b00000000, 1},{0b01010001, 0b01010000, 0b00100000, 0b11111000, 0b00000000, 0},{0b01010001, 0b01010000, 0b00100000, 0b01110000, 0b10001000, 0},{0b01010001, 0b01010000, 0b00100000, 0b01110000, 0b01010000, 0},{0b01010001, 0b01010000, 0b00100000, 0b01110000, 0b10001000, 0},{0b01010001, 0b01010000, 0b00100000, 0b01110000, 0b01010000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10001000, 0},{0b01010000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 1},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 128},};
spriteframe anim_sprite_trick_headstand[] = {{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00000000, 0},{0b01010000, 0b01010000, 0b11111000, 0b00000000, 0b00000000, 0},{0b01010000, 0b11111000, 0b01110000, 0b00000000, 0b00000000, 0},{0b10101000, 0b01110000, 0b01110000, 0b01000000, 0b00000000, 0},{0b10101000, 0b01110000, 0b00100000, 0b01110000, 0b01000000, 0},{0b10101000, 0b01110000, 0b00100000, 0b01010000, 0b01010000, 3},{0b10101000, 0b01110000, 0b00100000, 0b01010000, 0b00000000, 0},{0b10101000, 0b01110000, 0b01110000, 0b00000000, 0b00000000, 0},{0b11111000, 0b01110000, 0b00100000, 0b00000000, 0b00000000, 0},{0b01010000, 0b11111000, 0b01110000, 0b00100000, 0b00000000, 128},};
spriteframe anim_sprite_trick_jump[] = {{0b01010000, 0b01110000, 0b11111000, 0b00100000, 0b00000000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b00000000, 0b10001000, 0b01010000, 0b00100000, 0b11111000, 0},{0b00000000, 0b00000000, 0b10001000, 0b01010000, 0b00100000, 0},{0b00000000, 0b00000000, 0b00000000, 0b10001000, 0b01010000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10001000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 2},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01010000, 0},{0b00000000, 0b00000000, 0b00000000, 0b01010000, 0b01010000, 0},{0b00000000, 0b00000000, 0b01010000, 0b01010000, 0b00100000, 0},{0b00000000, 0b01010000, 0b01010000, 0b00100000, 0b11111000, 0},{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 128},};
spriteframe anim_sprite_trick_legstand[] = {{0b01000000, 0b01011000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01000000, 0b01000000, 0b10111000, 0b01111000, 0b00100000, 0},{0b01000000, 0b01000000, 0b10110000, 0b01111000, 0b00101100, 3},{0b01000000, 0b00100000, 0b01011000, 0b00111100, 0b00010110, 0},{0b01000000, 0b01111000, 0b00111100, 0b00010110, 0b00000000, 0},{0b01111000, 0b00111111, 0b00001011, 0b00000000, 0b00000000, 0},{0b01111111, 0b00111110, 0b00001000, 0b00000000, 0b00000000, 1},{0b01111110, 0b00111100, 0b00001000, 0b00000000, 0b00000000, 0},{0b01110110, 0b00111100, 0b00001000, 0b00000000, 0b00000000, 0},{0b01110010, 0b00111100, 0b00001000, 0b00000000, 0b00000000, 0},{0b01000100, 0b00101000, 0b00111000, 0b00111000, 0b00010000, 0},{0b01001000, 0b00101000, 0b01010100, 0b00111000, 0b00010000, 0},{0b01001000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
spriteframe anim_sprite_trick_poof[] = {{0b01010000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b00000000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b00000000, 0b01010000, 0b01110000, 0b00100000, 0b00000000, 0},{0b00000000, 0b00000000, 0b01110000, 0b00100000, 0b00000000, 0},{0b00000000, 0b00000000, 0b00100000, 0b00000000, 0b00000000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b00100000, 0b00100000, 0b11011000, 0b00100000, 0b00100000, 0},{0b10101000, 0b00000000, 0b10001000, 0b00000000, 0b10101000, 0},{0b10001000, 0b00000000, 0b00000000, 0b00000000, 0b10001000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 4},{0b00100000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b01110000, 0b00100000, 0b00000000, 0b00000000, 0b00000000, 0},{0b10101000, 0b01110000, 0b00100000, 0b00000000, 0b00000000, 0},{0b01010000, 0b10101000, 0b01110000, 0b00100000, 0b00000000, 128},};
spriteframe anim_sprite_trick_rocket[] = {{0b01010000, 0b00100000, 0b10101000, 0b01110000, 0b00100000, 0},{0b00100000, 0b00100000, 0b10101000, 0b01110000, 0b00100000, 3},{0b11111000, 0b00100000, 0b10101000, 0b01110000, 0b00100000, 0},{0b11111000, 0b01100000, 0b10101000, 0b01110000, 0b00100000, 0},{0b11110000, 0b01110000, 0b10101000, 0b01110000, 0b00100000, 0},{0b11111000, 0b10110000, 0b00100000, 0b10101000, 0b01110000, 0},{0b01111000, 0b11011000, 0b00100000, 0b00100000, 0b10101000, 0},{0b11111000, 0b10110000, 0b00000000, 0b00100000, 0b00100000, 0},{0b11111100, 0b01101000, 0b00100000, 0b00000000, 0b00100000, 0},{0b11111100, 0b10110000, 0b00100000, 0b00000000, 0b00000000, 0},{0b11111100, 0b01101000, 0b00000000, 0b00000000, 0b00000000, 0},{0b01111000, 0b01110000, 0b00000000, 0b00000000, 0b00000000, 0},{0b01011000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 2},{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00100000, 0},{0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b00000000, 0},{0b00000000, 0b00000000, 0b00100000, 0b10001000, 0b01110000, 0},{0b00000000, 0b00100000, 0b10001000, 0b01110000, 0b00000000, 0},{0b00100000, 0b10001000, 0b01110000, 0b00000000, 0b00000000, 0},{0b10101000, 0b01110000, 0b00000000, 0b00000000, 0b00000000, 0},{0b11111000, 0b00100000, 0b00000000, 0b00000000, 0b00000000, 0},{0b00100000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0},{0b00100000, 0b00100000, 0b00000000, 0b00000000, 0b00000000, 0},{0b01010000, 0b00100000, 0b01110000, 0b00100000, 0b00000000, 128},};
spriteframe anim_sprite_trick_russian[] = {{0b01010000, 0b01010000, 0b00100000, 0b11111000, 0b00100000, 0},{0b01010000, 0b01110000, 0b01110000, 0b00100000, 0b00000000, 0},{0b10001000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 1},{0b01010000, 0b01110000, 0b01110000, 0b00100000, 0b00000000, 1},{0b10001000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 1},{0b01010000, 0b01110000, 0b01110000, 0b00100000, 0b00000000, 1},{0b10001000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 1},{0b01010000, 0b01110000, 0b01110000, 0b00100000, 0b00000000, 1},{0b10001000, 0b01010000, 0b00100000, 0b01110000, 0b10101000, 1},{0b01010000, 0b01110000, 0b01110000, 0b00100000, 0b00000000, 1},{0b01010000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 128},};
spriteframe anim_sprite_trick_spin_slow[] = {{0b01000000, 0b10101000, 0b01101000, 0b00010000, 0b01101000, 0},{0b00100000, 0b11010000, 0b00111000, 0b11010000, 0b00100000, 0},{0b01101000, 0b00010000, 0b01101000, 0b10101000, 0b01000000, 0},{0b00100000, 0b01110000, 0b10101000, 0b01010000, 0b01010000, 1},{0b10110000, 0b01000000, 0b10110000, 0b10101000, 0b00010000, 0},{0b00100000, 0b01011000, 0b11100000, 0b01011000, 0b00100000, 0},{0b00010000, 0b10101000, 0b10110000, 0b01000000, 0b10110000, 128},};
spriteframe anim_sprite_trick_studio[] = {{0b01010000, 0b01010000, 0b01100000, 0b01111000, 0b00100000, 0},{0b10010000, 0b01010000, 0b01100000, 0b01110000, 0b00101000, 1},{0b01010000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b10010000, 0b01010000, 0b01100000, 0b01110000, 0b00101000, 1},{0b01010000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b01001000, 0b01010000, 0b00110000, 0b01110000, 0b10100000, 1},{0b01010000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 0},{0b01001000, 0b01010000, 0b00110000, 0b01110000, 0b10100000, 1},{0b01010000, 0b01010000, 0b01110000, 0b01110000, 0b00100000, 128},};

spriteframe anim_sprite_halfheight_intro[] = {{0b00000000, 0b00000000, 0b00000001, 0b00000000, 0b00000000, 0},{0b00000010, 0b00000001, 0b00000011, 0b00000001, 0b00000000, 0},{0b00000110, 0b00000010, 0b00000111, 0b00000010, 0b00000000, 0},{0b00001010, 0b00000100, 0b00001110, 0b00000100, 0b00000000, 0},{0b00001100, 0b00001000, 0b00011100, 0b00001000, 0b00000000, 0},{0b00010100, 0b00001000, 0b00011100, 0b00001000, 0b00000000, 128},};
spriteframe anim_sprite_crowd_1_to_2[] = {{0b00010100, 0b00001000, 0b00011100, 0b00001000, 0b00000000, 0},{0b00110000, 0b00010000, 0b00111001, 0b00010000, 0b00000000, 0},{0b00110010, 0b00100001, 0b01110011, 0b00100001, 0b00000000, 0},{0b01010101, 0b00100010, 0b01110111, 0b00100010, 0b00000000, 128},};
spriteframe anim_sprite_crowd_2_to_3[] = {{0b01010101, 0b00100010, 0b01110111, 0b00100010, 0b00000000, 0},{0b01100110, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0},{0b01001001, 0b01001001, 0b01001001, 0b00000000, 0b00000000, 128},};
spriteframe anim_sprite_crowd_3_to_4[] = {{0b01001001, 0b01001001, 0b01001001, 0b00000000, 0b00000000, 0},{0b01010010, 0b01010010, 0b01010010, 0b00000000, 0b00000000, 0},{0b01010101, 0b01010101, 0b01010101, 0b00000000, 0b00000000, 128},};

spriteframe anim_sprite_walkin[] = {{0b10000000, 0b00000000, 0b10000000, 0b00000000, 0b00000000, 0},{0b01000000, 0b10000000, 0b01000000, 0b10000000, 0b00000000, 0},{0b11000000, 0b11000000, 0b10000000, 0b10000000, 0b10000000, 0},{0b10010000, 0b10100000, 0b01000000, 0b01000000, 0b01000000, 0},{0b01010000, 0b01010000, 0b01110000, 0b00100000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
spriteframe anim_sprite_wave[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00110000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00110000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00110000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01110000, 0b00101000, 0},{0b01010000, 0b01010000, 0b10100000, 0b01111000, 0b00100000, 0},{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128},};
spriteframe stand[] = {{0b01010000, 0b01010000, 0b10101000, 0b01110000, 0b00100000, 128}};

spriteframe * gaydar[] = {
		anim_sprite_halfheight_intro,
		anim_sprite_crowd_1_to_2,
		anim_sprite_crowd_2_to_3,
		anim_sprite_crowd_3_to_4
};
spriteframe * tricks[] = {
		anim_sprite_trick_armdance,
		anim_sprite_trick_ballet,
		anim_sprite_trick_companion,
		anim_sprite_trick_handwave,
		anim_sprite_trick_headroll,
		anim_sprite_trick_headstand,
		anim_sprite_trick_jump,
		anim_sprite_trick_legstand,
		anim_sprite_trick_poof,
		anim_sprite_trick_rocket,
		anim_sprite_trick_russian,
		anim_sprite_trick_spin_slow,
		anim_sprite_trick_studio,
		anim_sprite_wave
};
fullframe * prop_uses[] = {
		anim_full_prop_ball_use,
		anim_full_prop_wand_use,
};
spriteframe * prop_uses_sprites[] = {
		anim_sprite_prop_earthquake_use,
		anim_sprite_prop_stick_use,
		anim_sprite_prop_dynamite_use,
		anim_sprite_prop_sword_use,
};
fullframe * prop_effects[] = {
		anim_full_prop_ball_effect,
		anim_full_prop_rain_effect,
};

spriteframe * prop_effects_sprites[] = {
		anim_sprite_prop_dynamite_effect,
		anim_sprite_prop_earthquake_effect,
		anim_sprite_prop_wand_effect,
		anim_sprite_prop_sword_effect,
};

#endif
