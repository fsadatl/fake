int motion_guess(Sint16 x1 , Sint16 y1 , Sint16 x2 , Sint16 y2 ){
    if (x1>x2 && y1>y2)
        return 1;
    if (x1<x2 && y1>y2)
        return 2;
    if (x1>x2 && y1<y2)
        return 3;
    if (x1<x2 && y1<y2)
        return 4;
}

void shoot(Sint16 x1 , Sint16 y1 , Sint16 x2 , Sint16 y2){
    float ratio=(float)(x2 - x1)/(y2-y1);
    switch (motion_guess(x1 , y1 , x2 , y2)) {
        case 1:
            if (ratio>1)
            {
                while (y1>y2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1-=5;
                    y1-=5;
                }
                while (x1<x2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1-=5;
                }
            }else{
                while (x1>x2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    y1-=5;
                    x1-=5;
                }
                while (y1>y2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    y1-=5;
                }
            }
            break;
        case 2:
            if (ratio<-1)
            {
                while (y1>y2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1+=5;
                    y1-=5;
                }
            }else{
                while (x1<x2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1+=5;
                }
            }
            break;
        case 3:
            if (ratio<-1)
            {
                while (y1<y2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1-=5;
                    y1+=5;
                }
            }else{
                while (x1<x2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1-=5;
                }
            }
            break;
        case 4:
            if (ratio>1)
            {
                while (y1<y2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1+=5;
                    y1+=5;
                }
                while (x1<x2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    x1+=5;
                }
            }else{
                while (x1<x2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    y1+=5;
                    x1+=5;
                }
                while (y1<y2)
                {   SDL_RenderPresent(sdlRenderer);
                    filledCircleColor(sdlRenderer, x1 , y1 , 3 , colorc);
                    y1+=5;
                }
            }
            break;
        default :
            break;
    }

}
