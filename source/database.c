#include "database.h"

static char unknown_name[32];

const char* pokemon_get_name(u16 species) {
    switch(species) {
        case 1: return "Bulbasaur";
        case 4: return "Charmander";
        case 7: return "Squirtle";
        case 25: return "Pikachu";
        case 197: return "Umbreon";
        case 198: return "Murkrow";
        case 229: return "Houndoom";
        case 248: return "Tyranitar";
        case 262: return "Mightyena";
        case 302: return "Sableye";
        case 359: return "Absol";
        case 551: return "Krookodile";
        case 658: return "Greninja";
        case 659: return "Bunnelby";
        case 660: return "Diggersby";
        case 717: return "Yveltal";
        default:
            snprintf(unknown_name, sizeof(unknown_name), "Pokemon #%d", species);
            return unknown_name;
    }
}

const char* move_get_name(u16 move) {
    switch(move) {
        case 1: return "Pound";
        case 33: return "Tackle";
        case 242: return "Crunch";
        case 304: return "Dark Pulse";
        case 364: return "Feint Attack";
        case 399: return "Night Slash";
        case 400: return "Sucker Punch";
        default: return "Move";
    }
}

const char* nature_get_name(u8 nature) {
    static const char* names[] = {
        "Hardy","Lonely","Brave","Adamant","Naughty",
        "Bold","Docile","Relaxed","Impish","Lax",
        "Timid","Hasty","Serious","Jolly","Naive",
        "Modest","Mild","Quiet","Bashful","Rash",
        "Calm","Gentle","Sassy","Careful","Quirky"
    };
    if (nature < 25) return names[nature];
    return "Hardy";
}

u8 pokemon_is_dark_type(u16 species) {
    switch(species) {
        case 197: case 198: case 229: case 248:
        case 262: case 302: case 359: case 551:
        case 658: case 717:
            return 1;
        default: return 0;
    }
}

int save_load(SaveData* save, const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return 0;
    fread(save, sizeof(SaveData), 1, f);
    fclose(f);
    return 1;
}

int save_write(SaveData* save, const char* path) {
    FILE* f = fopen(path, "wb");
    if (!f) return 0;
    fwrite(save, sizeof(SaveData), 1, f);
    fclose(f);
    return 1;
}
