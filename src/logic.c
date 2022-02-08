#include <stdio.h>

struct state
{
    int statetype;//0=me , 1=empty , 2=enemy
    int soliders;
};

void attack(Sint16 x1 , Sint16 y1 , Sint16 x2 , Sint16 y2){
//attack need x1 , y1 , x2 , y2 , from mouse event
    struct state s1;//x1 , y1 is in this area
    struct state s2;//x2, y2 is in this area
    int flag=0;
    switch (s1.statetype)
    {
    case 0:
        if(s2.statetype==0){
            while (s1.soliders>0)
            {
                s1.soliders--;
                s2.soliders++;
                //color s2 from gray switch to s1 color
                //alpha s2++ and alpha s1--
                //send a solider from first Coordinates to second one
            }
            
        }else if (s2.statetype==2||s2.statetype==1)
        {   while (s1.soliders>0)
            {
                s1.soliders--;
                //alpha s1--
                //send a solider from first Coordinates to second one
                while (s2.soliders>0)
                {
                    s2.soliders--;
                    //alpha s2--
                }
                if (s2.soliders==0)
                {
                    flag=1;
                    //color s2 switch to color s1
                }
                if (flag)
                {
                    s2.soliders++;
                    //alpha s2++
                }
                
            }
        }
        break;
    default:
        break;
    }

}

int main(){
Sint16 x1 , y1 , x2 ,  y2;
    if (//mouse event)
    {
        //first click give us x1 , y1
        //second click give us x2 , y2
        attack(x1 , y1 , x2 , y2);
    }
    

    
}