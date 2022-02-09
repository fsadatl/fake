
int makestate(struct state *s ){
    SDL_RenderPresent(sdlRenderer);
    stringRGBA(sdlRenderer , s->x, s->y , s->soliders , 0xff , 0xff , 0xff , 0xff);
    s->soliders++;
    if (s->soliders>s->maxsoliders)
    {
        s->soliders=s->maxsoliders;
        return 0;
    } else return 1;
    
}

void produce(struct state *s ){
    while (true)
    {
        //sdldelay
        if (!makestate(s))return;
    }

}

void start(struct state *s ){
    s->soliders=s->startamount;
    switch (s->statetype)
    {   //ordinary
        case 0:
            s->maxsoliders=20;
            s->startamount=20;
            break;
            //home
        case 1:
            s->maxsoliders=50;
            break;
        case 2:
            s->maxsoliders=50;
            break;
        default:
            break;
    }
    produce(&s);

}
