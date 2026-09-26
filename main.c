#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

struct Sort_State {
    int id;
};

void selection_sort(struct Sort_State* st, int size, int *nums, int max) {
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

    int max_num = 99;
    int num_amount = 500;
    int nums[num_amount];
    float length = 360.f;
    float angle_deg = 360.f / (float)num_amount;

    for(int i = 0; i < num_amount; i++) {
        nums[i] = GetRandomValue(0, max_num);
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        selection_sort(&state, num_amount, nums, max_num);
        BeginDrawing();
            ClearBackground(BLACK);
            float cur_angle = 0.f;
            for(int i = 0; i < num_amount; i++) {
                Vector2 end_pos = {start_pos.x + length * cosf(DEG2RAD * cur_angle), start_pos.y + length * sinf(DEG2RAD * cur_angle)};
                cur_angle += angle_deg;
                DrawLineV(start_pos, end_pos, ColorFromHSV( nums[i] * (300.f / max_num), 1, 1));
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
