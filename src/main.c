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
const int CELL_NUM = 5;
Uint32 colorc = 0xf0000000;
//#include "shooting.h"

struct state{
    int statetype; //1=home , 2=empty , 3=others
    int soliders;
    Uint32 color;
};

int handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return 0;
        if (event.type == SDL_KEYDOWN){
            const Uint8* keys = SDL_GetKeyboardState(NULL);
        }
        if( event.type == SDL_MOUSEMOTION){
            //event.motion.x and event.motion.y
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                printf("pressed on (%d,%d)\n", event.button.x, event.button.y);
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                printf("finished on (%d,%d)\n", event.button.x, event.button.y);
            }
        }

    }
    return 0;
}

void drawBox( int x, int y , Uint32 color) {
    Sint16 width1 = SCREEN_WIDTH * y / CELL_NUM;
    Sint16 height1 = SCREEN_HEIGHT * x / CELL_NUM;
    roundedBoxColor(sdlRenderer, width1, height1, width1 + SCREEN_WIDTH / CELL_NUM, height1 + SCREEN_HEIGHT / CELL_NUM, 10 ,  color);
    filledCircleColor(sdlRenderer, (width1+(width1 + SCREEN_WIDTH / CELL_NUM))/2, (height1+(height1 + SCREEN_HEIGHT / CELL_NUM))/2, 5 , colorc);
    stringRGBA(sdlRenderer , (width1+(width1 + SCREEN_WIDTH / CELL_NUM))/2, (height1+(height1 + SCREEN_HEIGHT / CELL_NUM))/2 +6 , "20" , 0xff , 0xff , 0xff , 0xff);
}

int main() {
    srand(time(0));
    int ime = rand()%4+1 ;
    int ienemy = rand()%4+1;
    if (ime==ienemy &&ienemy!=4)
        ime=ienemy+1;
    int jme = rand()%4+1;
    int jenemy = rand()%4+1;
    if (jme==jenemy &&jenemy!=4)
        jme=jenemy+1;
    int emp1i=rand()%4+1 , emp2i=rand()%4+1 ;
    int emp1j=rand()%4+1 , emp2j=rand()%4+1 ;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    sdlWindow = SDL_CreateWindow("Test_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_Surface *icon;
    icon = SDL_LoadBMP("D:\\uni\\untitled1\\media\\1.bmp");
    SDL_SetWindowTitle(sdlWindow , "state.io");
    SDL_SetWindowIcon(sdlWindow , icon);
//    SDL_Surface *image;
//    SDL_Texture *text;
    Uint32 colorme = 0x8060B371;
    Uint32 colorenemy = 0x80894D96;
    Uint32 gray = 0x80808080;
    SDL_bool shallExit = SDL_FALSE;
    //char text[30] = {" "};
    Sint16 tool = 233;
    int i = 0;
    while (shallExit == SDL_FALSE) {
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
            }

        }
        //دریافت نام کاربری
//        while (SDL_PollEvent(&sdlEvent)) {
//            switch (sdlEvent.type) {
//                case SDL_QUIT:
//                    shallExit = SDL_TRUE;
//                    break;
//                case SDL_KEYDOWN:
//                    //while(text[i]!=NULL)
//                    //{
//                    characterRGBA(sdlRenderer, tool, 342, text[i], 0x00, 0xbb, 0xaa, 0xee);
//                    tool += 6;
//                    i++;
//                    //}
//                    break;
//                case SDL_TEXTINPUT:
//                    strcat(text, sdlEvent.text.text);
//                    break;
//            }
//        }
        //ورود
//            image = SDL_LoadBMP("D:\\uni\\untitled1\\media\\starterArtboard-1.bmp");
//            if(!image){
//                printf("%s\n" ,SDL_GetError());
//                return 3;
//            }
//            text=SDL_CreateTextureFromSurface(sdlRenderer,image);
//            SDL_RenderPresent(sdlRenderer);
//            SDL_RenderCopy(sdlRenderer,text,NULL,NULL);

        //نقشه
        SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlRenderer);
        handleEvents();
        for (int i = 0; i < CELL_NUM; i++) {
            for (int j =0 ; j < CELL_NUM; j++){
                if (i==ime && j==jme) {
                    drawBox( i, j , colorme);
                }else if (i==ienemy && j== jenemy) {
                    drawBox( i, j , colorenemy);
                }else if ((i!=emp1i && j!=emp1j)&&(i!=emp2i && j!=emp2j)){
                    drawBox( i, j , gray);

                }

            }
        }


//        if (flag){
//            Sint16 ratio=(500)/(300);
//            shooting( 600 , 400 , 100 , 100 , ratio);
//        }
//       flag=0;
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(100 / FPS);
    }


//    SDL_FreeSurface(image);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    return 0;
}


/*
#include <SDL2_gfxPrimitives.h>
#include <SDL_surface.h>
#ifdef main
#undef main
#endif
#include <stdio.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

void InitVideo();
void Redraw();

char *text;
char *composition;
Sint32 cursor;
Sint32 selection_len;

//Starts up SDL and creates window
bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

//Loads media
bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "D:\\uni\\untitled1\\starter.bmp");
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}
//Frees media and shuts down SDL
void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main() {

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            //Update the surface
            SDL_UpdateWindowSurface( gWindow );

            //Wait two seconds
            SDL_Delay( 20000 );
        }
    }





    SDL_Quit();
    //Free resources and close SDL
    close();

    return 0;
}
*/
