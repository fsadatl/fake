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

void shooting(Sint16 x1 , Sint16 y1 , Sint16 x2 , Sint16 y2 , Sint16 ratio){
    switch (motion_guess(x1 , y1 , x2 , y2)) {
        case 1:
            if (ratio>1)
            {
                while (y1>y2)
                {
                    filledCircleColor()
                    x1--;
                    y1--;
                }
                while (x1<x2)
                {
                    filledCircleColor()
                    x1--;
                }
            }else{
                while (x1>x2)
                {
                    filledCircleColor()
                    y1--;
                    x1--;
                }
                while (y1>y2)
                {
                    filledCircleColor()
                    y1--;
                }
            }
            break;
        case 2:
            if (ratio<-1)
            {
                while (y1>y2)
                {
                    filledCircleColor()
                    x1++;
                    y1--;
                }
            }else{
                while (x1<x2)
                {
                    filledCircleColor()
                    x1++;
                }
            }
            break;
        case 3:
            if (ratio<-1)
            {
                while (y1<y2)
                {
                    filledCircleColor()
                    x1--;
                    y1++;
                }
            }else{
                while (x1<x2)
                {
                    filledCircleColor()
                    x1--;
                }
            }
            break;
        case 4:
            if (ratio>1)
            {
                while (y1<y2)
                {
                    filledCircleColor()
                    x1++;
                    y1++;
                }
                while (x1<x2)
                {
                    filledCircleColor()
                    x1++;
                }
            }else{
                while (x1<x2)
                {
                    filledCircleColor()
                    y1++;
                    x1++;
                }
                while (y1<y2)
                {
                    filledCircleColor()
                    y1++;
                }
            }
            break;
        default 
            break;
    }

}

