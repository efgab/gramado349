
// demos.h

#ifndef __DEMOS_H
#define __DEMOS_H  1

extern int gUseDemos;
extern struct gws_window_d *__demo_window;

extern unsigned long beginTick;

//
// == Prototypes ===============
//

void demoLines(void);
void demoTriangle(void);
void demoPolygon(void);
void demoPolygon2(void);
// curve+string
void demoCurve(void);

// Cat
void demoCat(int draw_desktop);

// flying cube
void FlyingCubeMove(int number, int direction, float value);
void demoFlyingCubeSetup(void);
void demoFlyingCubeDrawScene(int draw_desktop, unsigned int bg_color, int flush);
void demos_refresh_demo_window(void);

int demoUpdateDemoWindow(
    unsigned long left,
    unsigned long top,
    unsigned long width,
    unsigned long height );

#endif    



