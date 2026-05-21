#define V2 ImVec2
#define R d->AddRectFilled

#define RED_COLOR 0xFF0000FF
#define WHITE_COLOR 0xFFFFFFFF
#define PATH_COLOR 0xFF3F3F3F
#define BACKGROUND_COLOR 0xFF600030

#define SCALE (FRAME_WIDTH/50)

void FX(ImDrawList* d, V2 a, V2 b, V2 sz, ImVec4 m, float t)
{
    static float mx = a.x + sz.x/2;
    const float dy = SCALE*4, dt = 2;
    int i = fmodf(dt * t, 2) < 1 ? 1 : 0;
    auto v = fmodf(dt * t, 1);
    auto y = a.y - dy + v * dy;
    float dy_inv = 1./dy;

    int c = sinf(t + v *dy_inv) * SCALE*5;
    for (int s = 1 + sz.y * dy_inv; s > 0; --s, y += dy) {
        R({ sz.x / 2 - SCALE*13, y }, { sz.x / 2 + SCALE*13, y+dy }, BACKGROUND_COLOR);
        V2 tl = { c + a.x + sz.x / 2 - SCALE*8, y };
        V2 br = { c + a.x + sz.x / 2 + SCALE*8, y + dy };
        tl.x += SCALE;
        br.x -= SCALE;
        R(tl, br, PATH_COLOR); //gray
        R({tl.x-SCALE, tl.y}, {tl.x, br.y}, (i & 1) ? WHITE_COLOR : RED_COLOR);
        R({br.x, tl.y}, {br.x+SCALE, br.y}, (i & 1) ? WHITE_COLOR : RED_COLOR);
        ++i;
        
        //break;
    }
    if (m.z >= 0) mx--;
    if (m.w >= 0) mx++;
    
    //draw car
    R({ mx - 8*SCALE/16, b.y - sz.y / 4 - 15*SCALE/16 }, { mx + 8*SCALE/16, b.y - sz.y / 4 + 15*SCALE/16 }, 0xff00ff00, 4);
    R({ mx - 7*SCALE/16, b.y - sz.y / 4 - 8*SCALE/16 }, { mx + 7*SCALE/16, b.y - sz.y / 4 + 12*SCALE/16 }, 0xff007f00, 4);
    R({ mx - 6*SCALE/16, b.y - sz.y / 4 + 13*SCALE/16 }, { mx - 2*SCALE/16, b.y - sz.y / 4 + 14*SCALE/16 }, RED_COLOR);
    R({ mx + 2*SCALE/16, b.y - sz.y / 4 + 13*SCALE/16 }, { mx + 6*SCALE/16, b.y - sz.y / 4 + 14*SCALE/16 }, RED_COLOR);
}

