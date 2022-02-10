#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_surface.h>
#ifdef main
#undef main
#endif
#include <stdio.h>
#include <stdbool.h>
#include<time.h>
SDL_Renderer *sdlRenderer=NULL;
SDL_Window *sdlWindow=NULL;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 60;
const int CELL_NUM = 7;
Uint32 colorc = 0xf0000000;
struct state
{
    int x;//state x center coordinate
    int y;//state y center coordinate
    int statetype; //1=home , 0=empty , 2=others
    int soliders;
    Uint32 color;
    int maxsoliders;
    int startamount;
    char num[3];
};
#include "shooting.h"
#include "eventhandeling.h"
#include "amount.h"
#include "attack.h"



void drawBox( int x, int y , Uint32 color , char num[]) {
    roundedBoxColor(sdlRenderer, x-40, y-40, x + 40 , y + 40, 10 ,  color);
    filledCircleColor(sdlRenderer, x , y, 5 , colorc);

}


int main() {
    struct state st[CELL_NUM+1];
    int x1 , y1 , x2 , y2;
    bool war=0;
    const Uint8* keys;
    int flag=1 , go=0;
    char name[30]={"\0"};
    name[3]="\n";
    srand(time(0));
    int ime = rand()%CELL_NUM+1 ;
    int x=rand()%100;
    int ienemy = rand()%CELL_NUM+1;
    if (ime==ienemy && ienemy!=CELL_NUM)
        ime=ienemy+1;
    Uint32 colorme = 0x8060B371;
    Uint32 colorenemy = 0x80894D96;
    Uint32 gray = 0x80808080;
    for (int i = 1 ; i <=CELL_NUM; ++i) {
        x=rand()%100;
        if (i==ime) {
            st[i].color=colorme;
            st[i].y=SCREEN_HEIGHT * i / CELL_NUM+x;
            st[i].x=SCREEN_WIDTH * i / CELL_NUM-x;
            st[i].statetype=1;
        }else if (i==ienemy) {
            st[i].color=colorenemy;
            st[i].y=SCREEN_HEIGHT * i / CELL_NUM+x;
            st[i].x=SCREEN_WIDTH * i / CELL_NUM-x;
            st[i].statetype=2;
        }else{
            st[i].color=gray;
            st[i].y=SCREEN_HEIGHT * i / CELL_NUM+x;
            st[i].x=SCREEN_WIDTH * i / CELL_NUM-x;
            st[i].statetype=0;
        }
        st[i].num[0]='\0';
        st[i].num[1]='\0';
        st[i].num[2]='\0';
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    sdlWindow = SDL_CreateWindow("Test_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_Surface *icon;
    icon = SDL_LoadBMP("D:\\uni\\untitled1\\media\\11.bmp");
    SDL_SetWindowTitle(sdlWindow , "state.io");
    SDL_SetWindowIcon(sdlWindow , icon);
    SDL_RenderPresent(sdlRenderer);
    SDL_Surface *image;
    SDL_Texture *text;
    SDL_bool shallExit = SDL_FALSE;
    while (shallExit == SDL_FALSE) {
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent) && !go) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
                case SDL_KEYDOWN:
                    if (sdlEvent.key.keysym.sym==SDLK_RETURN||sdlEvent.key.keysym.sym==SDLK_KP_ENTER)
                        go=1;
                    break;
                case SDL_TEXTINPUT:
                    strcat(name, sdlEvent.text.text);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                        if(sdlEvent.button.button == SDL_BUTTON_LEFT ){
                            x1=sdlEvent.button.x;
                            y1=sdlEvent.button.y;
                        }

                case SDL_MOUSEBUTTONUP:
                        if(sdlEvent.button.button == SDL_BUTTON_LEFT ){
                            x2=sdlEvent.button.x;
                            y2=sdlEvent.button.y;
                            war=1;
                        }
            }
        }
        if (!go){
            image = SDL_LoadBMP("D:\\uni\\untitled1\\media\\starter.bmp");
            if(!image){
                printf("%s\n" ,SDL_GetError());
                return 3;
            }
            text=SDL_CreateTextureFromSurface(sdlRenderer,image);
            SDL_RenderPresent(sdlRenderer);
            SDL_RenderCopy(sdlRenderer,text,NULL,NULL);
        }
        stringRGBA(sdlRenderer,SCREEN_WIDTH/2-70, SCREEN_HEIGHT/2-175 , "enter your name" , 0xff, 0xff, 0xff, 0xff );
        stringRGBA(sdlRenderer,SCREEN_WIDTH/2-40 , SCREEN_HEIGHT/2-100 , name , 0xff, 0xff, 0xff, 0xff );
        //نقشه
        if (go){
            SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(sdlRenderer);
            for (int j = 1; j <=CELL_NUM; ++j){
                drawBox(st[j].x , st[j].y , st[j].color , st[j].num);
            }
            for (int i = 0; i <=CELL_NUM ; ++i) {
                start(&st[i]);
                SDL_RenderPresent(sdlRenderer);
            }
        }
        if (war){
            attack(x1 , y1 , x2 , y2 , st);
        }
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1 / FPS);


    }
    SDL_FreeSurface(image);
    SDL_FreeSurface(text);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    return 0;
}

