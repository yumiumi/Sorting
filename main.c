#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

struct Sort_State {
    int id;
};

void selection_sort(struct Sort_State* st, int size, int* nums, int max) {
    if(st->id < size) {
        int min = max + 1;
        int min_id = -1;

        for(int i = st->id; i < size; i++) {
            if(nums[i] < min) {
                min = nums[i];
                min_id = i;
            }
        }
        int temp = nums[st->id];
        nums[st->id] = min;
        nums[min_id] = temp;

        st->id += 1;
    }
}

int main() {
    struct Sort_State state;
    state.id = 0;

    const int scr_width = 1200;
    const int scr_height = 800;

    InitWindow(scr_width, scr_height, "sorted_circle");
    Vector2 start_pos = { (float)scr_width/2, (float)scr_height/2 };

    int max_num = 100;
    int num_amount = 800;
    int nums[num_amount];
    float radius = 360.f;
    float angle_deg = 360.f / (float)num_amount;

    for(int i = 0; i < num_amount; i++) {
        nums[i] = GetRandomValue(0, max_num);
    }

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        selection_sort(&state, num_amount, nums, max_num);
        BeginDrawing();
            ClearBackground(BLACK);
            float cur_angle = 0.f;
            for(int i = 0; i < num_amount; i++) {
                float start_angle = cur_angle;
                float end_angle = cur_angle + angle_deg;
                DrawCircleSector(start_pos, radius, start_angle, end_angle, 1, ColorFromHSV( nums[i] * (360.f / max_num), 1, 1));
                cur_angle += angle_deg;
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
