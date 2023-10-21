#include <Windows.h>
#include <cstdint>
#include "memory.h"
#include "offsets.h"
#include "citos.h"
#include "settings.h"












void init_citos() {
    while (true)
    {
        if (glow)
        {
            for (int i = 1; i < 64; i++)
            {
                auto entitylist = read<uintptr_t>(module_client + entity_list);
                auto listentry = read<uintptr_t>(entitylist + (8 * (i & 0x7FFF) >> 9) + 16);
                auto player = read<uintptr_t>(listentry + 120 * (i & 0x1FF));
                auto playerpawn = read<uint32_t>(player + 0x7BC);
                auto list_entry2 = read<uintptr_t>(entitylist + 0x8 * ((playerpawn & 0x7FFF) >> 9) + 16);
                auto p_cs_player_pawn = read<uintptr_t>(list_entry2 + 120 * (playerpawn & 0x1FF));
                write<float>(p_cs_player_pawn + 0x13C4, 100000.f); // on
               
            }

        }
        else if (!glow) {
            for (int i = 1; i < 64; i++)
            {
                auto entitylist = read<uintptr_t>(module_client + entity_list);
                auto listentry = read<uintptr_t>(entitylist + (8 * (i & 0x7FFF) >> 9) + 16);
                auto player = read<uintptr_t>(listentry + 120 * (i & 0x1FF));
                auto playerpawn = read<uint32_t>(player + 0x7BC);
                auto list_entry2 = read<uintptr_t>(entitylist + 0x8 * ((playerpawn & 0x7FFF) >> 9) + 16);
                auto p_cs_player_pawn = read<uintptr_t>(list_entry2 + 120 * (playerpawn & 0x1FF));
                write<float>(p_cs_player_pawn + 0x13C4, 0.f); // on

            }
        }
        Sleep(5);
    }
}