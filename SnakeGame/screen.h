#pragma once
#include "theme.h"
#include <iostream>

using namespace std;

struct Screen {
    void clear() {
        system("cls");
    }

    struct Draw {
        #define x first
        #define y second

        #define width first
        #define height second

        void retangle(const pair<int, int> topLeft, const pair<int, int> dimension, int color, int thickness) {
            textColor(color);
            for (int i = topLeft.x; i <= topLeft.x + (dimension.width * 2); ++i) {
                if (thickness == 2) {
                    gotoXY(i, topLeft.y);
                    printf("%c", 219);

                    gotoXY(i, topLeft.y + dimension.height);
                    printf("%c", 219);
                }
                else if (thickness == 1) {
                    gotoXY(i, topLeft.y);
                    printf("%c", 220);

                    gotoXY(i, topLeft.y + dimension.height);
                    printf("%c", 223);
                }
            }

            for (int i = topLeft.y; i <= topLeft.y + dimension.height; ++i) {
                if (thickness == 2) {
                    gotoXY(topLeft.x, i);
                    printf("%c%c", 219, 219);

                    gotoXY(topLeft.x + (dimension.width * 2), i);
                    printf("%c%c", 219, 219);
                }
                else if (thickness == 1) {
                    if (i != topLeft.y && i != topLeft.y + dimension.height) {
                        gotoXY(topLeft.x, i);
                        printf("%c", 219);

                        gotoXY(topLeft.x + (dimension.width * 2), i);
                        printf("%c", 219);
                    }
                }
            }
        }

    } draw;
};