#pragma once
#include <3ds.h>
#include <stdio.h>
#include <string.h>

// Pokemon Save Editor for 3DS by Darkness Metal
// Banco de dados basico - X / Y / ORAS / Sun / Moon

#define MAX_POKEMON 721
#define MAX_MOVES 621
#define PARTY_SIZE 6

typedef struct {
    u16 species;
    u8 level;
    u16 hp;
    u16 max_hp;
    u8 shiny;
    u8 nature;
    u16 moves[4];
} PokemonSlot;

typedef struct {
    char trainer_name[16];
    u32 money;
    u32 play_time;
    PokemonSlot party[PARTY_SIZE];
} SaveData;

// Funcoes do banco de dados
const char* pokemon_get_name(u16 species);
const char* move_get_name(u16 move);
const char* nature_get_name(u8 nature);
u8 pokemon_is_dark_type(u16 species);

// Funcoes de save
int save_load(SaveData* save, const char* path);
int save_write(SaveData* save, const char* path);
