#include<stdio.h>

#include<windows.h>



main()



{

    int i[10000] = {784,880,587,523,587,523,



                    784,880,587,523,587,523,



                    784,880,587,523,587,523,



                    698,659,698,659,587,523,



                    784,880,587,523,587,523,



                    784,880,587,523,587,523,



                    784,880,1060,1500,1330,1500,1330,1185,1060,880,



                    784,880,587,523,587,523,



                    784,880,587,523,587,523,



                    784,880,587,523,587,523,



                    698,659,698,659,587,523,



                    587,523,587,698,587,698,784,698,784,1060,1500,880,1060,1500,1330,1500,1330,1185,1060,1185,



                    587,587,523,523,587,698,784,



                    587,587,523,587,523,400,523,



                    587,587,523,523,587,698,784,880,784,880,784,698,587,



                    587,587,587,523,523,587,698,784,



                    587,587,523,587,523,523,400,



                    587,587,523,523,587,698,784,880,784,880,784,698,587,



                    698,659,587,523,523,523,587,400,330,400,



                    400,523,587,784,659,698,659,523,587,



                    698,659,587,523,523,523,587,400,330,400,



                    400,523,587,587,587,698,784,659,



                    587,698,784,784,880,880,



                    880,523,587,784,698,880,



                    587,698,784,784,880,880,



                    880,450,880,784,698,698,



                    587,698,784,784,880,880,



                    880,523,587,784,698,880,



                    587,698,450,880,784,698,784,880,698,1060,1185,

                   };



    int j[10000] =  {2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,2,2,1,2,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,1,1,1,1,



                     2,2,2,1,1,1,



                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,



                     2,2,2,1,2,1,2,



                     2,2,2,1,2,1,2,



                     2,2,2,1,2,1,2,1,2,2,2,1,1,



                     2,2,2,1,2,1,2,



                     2,2,2,1,2,1,2,



                     2,2,2,1,2,1,2,1,2,2,2,1,1,



                     2,2,2,2,1,2,2,1,1,1,



                     2,2,2,2,2,2,2,1,1,



                     2,2,2,2,1,2,1,1,1,2,



                     2,1,1,1,2,2,1,1,



                     2,2,2,2,2,1,



                     2,2,2,2,1,1,



                     2,2,2,2,2,1,



                     2,2,2,2,1,1,



                     2,2,2,2,2,1,



                     2,2,2,2,1,1,



                     2,3,2,2,2,2,2,2,2,1,1,4



                    };

                    

    int k;

    

    for(k = 0 ; k < 10000 ; k++)



    {

        Beep(i[k], j[k] * 300);

    }

}