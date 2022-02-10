
void  realize(Sint16 x1 , Sint16 y1 , Sint16 x2 , Sint16 y2 , struct state s[CELL_NUM] , struct state *s1, struct state *s2){
    for (int i = 0; i < CELL_NUM; ++i) {
        if (x1<s[i].x+40 && x1>s[i].x-40 && y1<s[i].y+40 && y1>s[i].y-40 )
              *s1= s[i];
        if (x2<s[i].x+40 && x2>s[i].x-40 && y2<s[i].y+40 && y2>s[i].y-40 )
              *s2= s[i];
    }
}
void attack(Sint16 x1 , Sint16 y1 , Sint16 x2 , Sint16 y2 ,  struct state s[CELL_NUM]){
//attack need x1 , y1 , x2 , y2 , from mouse event
    struct state s1;//x1 , y1 is in this area
    struct state s2;//x2, y2 is in this area
    realize(x1 , y1 , x2 , y2 ,  s , &s1 , &s2);
    int flag=0;
    switch (s1.statetype)
    {
    case 1:
        if(s2.statetype==0){
            while (s1.soliders>0)
            {
                s1.soliders--;
                s2.soliders++;
                //color s2 from gray switch to s1 color
                s2.color = s1.color;
                //alpha s2++ and alpha s1--
                s2.color+= 0x01000000;
                s1.color-=0x01000000;
                //send a solider from first Coordinates to second one
                shoot(s1.x , s1.y , s2.x , s2.y);
            }
            
        }else if (s2.statetype==2||s2.statetype==1)
        {   while (s1.soliders>0)
            {
                s1.soliders--;
                //alpha s1--
                s1.color-=0x01000000;
                //send a solider from first Coordinates to second one
                shoot(s1.x, s1.y, s2.x , s2.y);
                while (s2.soliders>0)
                {
                    s2.soliders--;
                    //alpha s2--
                    s2.color-=0x01000000;
                }
                if (s2.soliders==0)
                {
                    flag=1;
                    //color s2 switch to color s1
                    s2.color = s1.color;

                }
                if (flag)
                {
                    s2.soliders++;
                    //alpha s2++
                    s2.color+= 0x01000000;
                }
                
            }
        }
        break;
    default:
        break;
    }

}
