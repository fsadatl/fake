
void produce(struct state *s ){

    while (true)
    {
        SDL_RenderPresent(sdlRenderer);
        sprintf(s->num, "%d" , s->soliders);
        stringRGBA(sdlRenderer,s->x-2 , s->y+10, s->num, 0x00, 0x00 , 0x00 , 0xff);
        s->soliders++;
        if (s->soliders>s->maxsoliders)
        {
            s->soliders=s->maxsoliders;
            return;
        }
    }

}

void start(struct state *s ){
    switch (s->statetype)
    {   //ordinary
        case 0:
            s->maxsoliders=20;
            s->startamount=20;
            break;
            //home
        case 1:
            s->maxsoliders=50;
            s->startamount=10;
            break;
        case 2:
            s->maxsoliders=50;
            s->startamount=10;
            break;
        default:
            break;
    }
    s->soliders=s->startamount;
    produce(s);
}

